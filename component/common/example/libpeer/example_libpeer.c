#include "FreeRTOS.h"
#include "task.h"
#include "wifi_conf.h"
#include "lwip/sockets.h"
#include "lwip/netdb.h"
#include "peer.h"
#include "lwip/netif.h"
#include "lwip/ip_addr.h"
#include "lwip/dns.h"
#include "lwip/err.h"
#include "lwip/inet.h"
#include "lwip_netconf.h"
#include <errno.h>
#include <string.h>

/* AmebaD hardware entropy source for mbedTLS */
extern u32 Gen_RandomSeed(void);

int mbedtls_hardware_poll(void *data, unsigned char *output, size_t len, size_t *olen) {
    (void)data;
    size_t i = 0;
    while (i < len) {
        u32 rnd = Gen_RandomSeed();
        size_t copy = (len - i < 4) ? (len - i) : 4;
        memcpy(output + i, &rnd, copy);
        i += copy;
    }
    *olen = len;
    return 0;
}

/* Define in6addr_any for usrsctp */
const struct in6_addr in6addr_any = {{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}};

#define WIFI_SSID      "resideo-singh"
#define WIFI_PASSWORD  "12345678"
#define SIGNALING_URL  "mqtts://broker.emqx.io:8883/public/spotted-smart-eagle"

static PeerConnection *g_pc = NULL;
static PeerConnectionState eState = PEER_CONNECTION_CLOSED;
static int g_signaling_active = 0;

static void oniceconnectionstatechange(PeerConnectionState state, void *user_data) {
    eState = state;
    printf("[T+%dms] PeerConnectionState: %d\n", (int)(xTaskGetTickCount() * portTICK_PERIOD_MS), state);
}

static void onmessage(char *msg, size_t len, void *userdata, uint16_t sid) {
    printf("[libpeer] Got message: %.*s\n", (int)len, msg);
    if (strncmp(msg, "ping", 4) == 0) {
        printf("[libpeer] Got ping, send pong\n");
        peer_connection_datachannel_send(g_pc, "pong", 4);
    }
}

static void onopen(void *userdata) {
    printf("[T+%dms] Datachannel opened\n", (int)(xTaskGetTickCount() * portTICK_PERIOD_MS));
}

static void onclose(void *userdata) {
    printf("[libpeer] Datachannel closed\n");
}

static void main_loop_task(void *param) {
    // Single task running both peer_connection_loop and peer_signaling_loop.
    // This prevents concurrent mbedTLS/hardware-crypto access which caused
    // a Security Fault when pc_task and ps_loop were separate tasks.
    printf("[libpeer] Main loop started (free heap: %d)\n", xPortGetFreeHeapSize());
    while (1) {
        // Disconnect MQTT/TLS signaling once ICE connectivity succeeds.
        // At that point SDP and ICE candidates have been exchanged; MQTT
        // is no longer needed. Freeing the TLS session recovers ~15 KB
        // of heap that the DTLS-SRTP handshake needs.
        if (g_signaling_active && eState >= PEER_CONNECTION_CONNECTED) {
            printf("[T+%dms] ICE connected — disconnecting signaling (free heap: %d)\n",
                   (int)(xTaskGetTickCount() * portTICK_PERIOD_MS), xPortGetFreeHeapSize());
            peer_signaling_disconnect();
            g_signaling_active = 0;
            printf("[T+%dms] Signaling disconnected (free heap: %d)\n",
                   (int)(xTaskGetTickCount() * portTICK_PERIOD_MS), xPortGetFreeHeapSize());
        }

        peer_connection_loop(g_pc);

        if (g_signaling_active) {
            peer_signaling_loop();
        }

        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

static void peer_signaling_task(void *param) {
    // Connect here (deferred from libpeer_task) so that libpeer_task's
    // stack is freed before the TLS handshake needs heap memory.
    // This task uses a large stack for the TLS handshake, then spawns
    // a smaller loop task and deletes itself to reclaim ~10KB heap.
    printf("[T+%dms] Free heap before signaling connect: %d\n", (int)(xTaskGetTickCount() * portTICK_PERIOD_MS), xPortGetFreeHeapSize());
    peer_signaling_connect(SIGNALING_URL, "", g_pc);
    g_signaling_active = 1;

    // TLS handshake + MQTT connect + subscribe done.
    // Spawn a single loop task for BOTH peer_connection and signaling,
    // then delete this task to free the large stack (3072 words = 12KB).
    // The merged loop needs enough stack for the deeper path:
    // STUN connectivity check → HMAC-SHA1 → mbedTLS → secure crypto.
    xTaskCreate(main_loop_task, "main_loop", 2048, NULL, tskIDLE_PRIORITY + 2, NULL);
    vTaskDelete(NULL);
}

static void libpeer_task(void *param) {
    printf("\n=== LIBPEER BUILD 20260403-U ===\n\n");
    // Wait for WiFi
    printf("[libpeer] Connecting to WiFi: %s\n", WIFI_SSID);
    while (wifi_connect(WIFI_SSID, RTW_SECURITY_WPA2_AES_PSK,
                        WIFI_PASSWORD, strlen(WIFI_SSID),
                        strlen(WIFI_PASSWORD), -1, NULL) != RTW_SUCCESS) {
        printf("[libpeer] WiFi connect failed, retrying...\n");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
    printf("[T+%dms] WiFi connected!\n", (int)(xTaskGetTickCount() * portTICK_PERIOD_MS));

    // Run DHCP to get IP address
    printf("[libpeer] Starting DHCP...\n");
    uint8_t dhcp_ret = LwIP_DHCP(0, DHCP_START);
    if (dhcp_ret == DHCP_ADDRESS_ASSIGNED) {
        printf("[libpeer] DHCP OK\n");
    } else {
        printf("[libpeer] DHCP failed (ret=%d), retrying...\n", dhcp_ret);
        vTaskDelay(pdMS_TO_TICKS(1000));
        dhcp_ret = LwIP_DHCP(0, DHCP_START);
        printf("[libpeer] DHCP retry ret=%d\n", dhcp_ret);
    }

    // Print network info
    extern struct netif xnetif[];
    printf("[libpeer] IP: %s\n", ipaddr_ntoa(&xnetif[0].ip_addr));
    printf("[libpeer] GW: %s\n", ipaddr_ntoa(&xnetif[0].gw));
    printf("[libpeer] Netmask: %s\n", ipaddr_ntoa(&xnetif[0].netmask));

    // Set STA interface as default so libpeer advertises the correct IP
    // (netif_list starts with the AP interface on AmebaD)
    netif_set_default(&xnetif[0]);

    // Check DNS servers from DHCP
    {
        const ip_addr_t *dns0 = dns_getserver(0);
        const ip_addr_t *dns1 = dns_getserver(1);
        // Always set a public DNS as secondary — the local router DNS
        // may not resolve all hosts (e.g. stun.l.google.com fails on
        // some home routers). If DHCP provided no primary, set that too.
        if (dns0 && ip_addr_isany(dns0)) {
            ip_addr_t dns_primary;
            IP_ADDR4(&dns_primary, 8, 8, 8, 8);
            dns_setserver(0, &dns_primary);
        }
        {
            ip_addr_t dns_secondary;
            IP_ADDR4(&dns_secondary, 8, 8, 8, 8);
            dns_setserver(1, &dns_secondary);
        }
    }

    // Verify wifi_is_ready_to_transceive
    if (wifi_is_ready_to_transceive(RTW_STA_INTERFACE) == RTW_SUCCESS) {
        printf("[libpeer] WiFi ready to transceive!\n");
    } else {
        printf("[libpeer] WARNING: WiFi NOT ready to transceive\n");
    }

    PeerConfiguration config = {
        .ice_servers = {
            {.urls = "stun:stun.l.google.com:19302"}
        },
        .datachannel = DATA_CHANNEL_STRING,
    };

    peer_init();
    g_pc = peer_connection_create(&config);
    peer_connection_oniceconnectionstatechange(g_pc, oniceconnectionstatechange);
    peer_connection_ondatachannel(g_pc, onmessage, onopen, onclose);

    // NOTE: Do NOT call peer_signaling_connect() here — it triggers TLS handshake
    // which needs ~12KB heap. This task's stack is still allocated, starving heap.
    // Instead, defer it to the ps_task after this task is deleted.
    // ps_task does TLS+MQTT connect, then spawns a single merged loop task
    // (peer_connection_loop + peer_signaling_loop) to avoid concurrent
    // mbedTLS/hardware-crypto access between separate tasks.

    xTaskCreate(peer_signaling_task, "ps_task", 3072, NULL, tskIDLE_PRIORITY + 2, NULL);

    printf("[libpeer] Open https://sepfy.github.io/libpeer/?id=spotted-smart-eagle\n");
    vTaskDelete(NULL);
}

void example_libpeer(void) {
    // Do NOT call wifi_on() here — it is already called by the system's
    // wlan_network()/init_thread after the FreeRTOS scheduler starts.
    // Calling it from main() context (before scheduler) causes a Hard Fault
    // because wifi_on() uses RTOS primitives that require the scheduler.
    xTaskCreate(libpeer_task, "libpeer", 1536, NULL, tskIDLE_PRIORITY + 1, NULL);
}
