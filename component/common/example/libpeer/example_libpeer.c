#include "FreeRTOS.h"
#include "task.h"
#include "wifi_conf.h"
#include "lwip/sockets.h"
#include "lwip/netdb.h"
#include "peer.h"

/* Define in6addr_any for usrsctp */
const struct in6_addr in6addr_any = {{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}};

#define WIFI_SSID      "resideo-singh"
#define WIFI_PASSWORD  "12345678"
#define SIGNALING_URL  "mqtts://broker.emqx.io:8883/public/spotted-smart-eagle"

static PeerConnection *g_pc = NULL;
static PeerConnectionState eState = PEER_CONNECTION_CLOSED;

static void oniceconnectionstatechange(PeerConnectionState state, void *user_data) {
    eState = state;
    printf("[libpeer] PeerConnectionState: %d\n", state);
}

static void onmessage(char *msg, size_t len, void *userdata, uint16_t sid) {
    printf("[libpeer] Got message: %.*s\n", (int)len, msg);
    if (strncmp(msg, "ping", 4) == 0) {
        printf("[libpeer] Got ping, send pong\n");
        peer_connection_datachannel_send(g_pc, "pong", 4);
    }
}

static void onopen(void *userdata) {
    printf("[libpeer] Datachannel opened\n");
}

static void onclose(void *userdata) {
    printf("[libpeer] Datachannel closed\n");
}

static void peer_connection_task(void *param) {
    while (1) {
        peer_connection_loop(g_pc);
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

static void peer_signaling_task(void *param) {
    while (1) {
        peer_signaling_loop();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

static void libpeer_task(void *param) {
    // Wait for WiFi
    printf("[libpeer] Connecting to WiFi: %s\n", WIFI_SSID);
    while (wifi_connect(WIFI_SSID, RTW_SECURITY_WPA2_AES_PSK,
                        WIFI_PASSWORD, strlen(WIFI_SSID),
                        strlen(WIFI_PASSWORD), -1, NULL) != RTW_SUCCESS) {
        printf("[libpeer] WiFi connect failed, retrying...\n");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
    printf("[libpeer] WiFi connected!\n");

    // Wait for IP
    vTaskDelay(pdMS_TO_TICKS(2000));

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

    peer_signaling_connect(SIGNALING_URL, "", g_pc);

    xTaskCreate(peer_connection_task, "pc_task", 4096, NULL, tskIDLE_PRIORITY + 2, NULL);
    xTaskCreate(peer_signaling_task, "ps_task", 4096, NULL, tskIDLE_PRIORITY + 2, NULL);

    printf("[libpeer] Open https://sepfy.github.io/libpeer/?id=spotted-smart-eagle\n");
    vTaskDelete(NULL);
}

void example_libpeer(void) {
    wifi_on(RTW_MODE_STA);
    xTaskCreate(libpeer_task, "libpeer", 8192, NULL, tskIDLE_PRIORITY + 1, NULL);
}
