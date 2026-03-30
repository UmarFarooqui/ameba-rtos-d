include $(MAKE_INCLUDE_GEN)

.PHONY: all clean

LIBPEER_SRC = $(BASEDIR)/../libpeer/src
COREMQTT_DIR = $(BASEDIR)/../libpeer/third_party/coreMQTT/source
CJSON_DIR = $(BASEDIR)/../libpeer/third_party/cJSON
COREHTTP_DIR = /home/uafarooq/esp/libpeer/third_party/coreHTTP/source
LLHTTP_DIR = /home/uafarooq/esp/libpeer/third_party/coreHTTP/source/dependency/3rdparty/llhttp/src
LIBSRTP_DIR = $(BASEDIR)/../libpeer/third_party/libsrtp
LIBPEER_DIR = $(BASEDIR)/component/common/example/libpeer

MODULE_IFLAGS += -I$(CJSON_DIR)
MODULE_IFLAGS += -DMBEDTLS_TIMING_C
MODULE_IFLAGS += -DMBEDTLS_SSL_COOKIE_C
MODULE_IFLAGS += -DMBEDTLS_SSL_DTLS_HELLO_VERIFY
MODULE_IFLAGS += -DMBEDTLS_SSL_SRV_C
MODULE_IFLAGS += -DMBEDTLS_SSL_PROTO_TLS1_2
MODULE_IFLAGS += -DCONFIG_USE_LWIP=1
MODULE_IFLAGS += -DCONFIG_MBEDTLS_2_X=0
MODULE_IFLAGS += -DCONFIG_USE_USRSCTP=1
MODULE_IFLAGS += -D__Userspace__
MODULE_IFLAGS += -D__Userspace_os_FreeRTOS
MODULE_IFLAGS += -DSCTP_SIMPLE_ALLOCATOR
MODULE_IFLAGS += -DSCTP_PROCESS_LEVEL_LOCKS
MODULE_IFLAGS += -DSCTP_DEBUG
MODULE_IFLAGS += -DINET
MODULE_IFLAGS += -Wno-address-of-packed-member
MODULE_IFLAGS += -Wno-unused-parameter
MODULE_IFLAGS += -DHTTP_DO_NOT_USE_CUSTOM_CONFIG
MODULE_IFLAGS += -DMQTT_DO_NOT_USE_CUSTOM_CONFIG
MODULE_IFLAGS += -D__BYTE_ORDER=__LITTLE_ENDIAN
MODULE_IFLAGS += -DCONFIG_EXAMPLE_LIBPEER=1
MODULE_IFLAGS += -DCONFIG_DATA_BUFFER_SIZE=512
MODULE_IFLAGS += -DCONFIG_AUDIO_BUFFER_SIZE=512
MODULE_IFLAGS += -DCONFIG_HTTP_BUFFER_SIZE=512
MODULE_IFLAGS += -DCONFIG_SDP_BUFFER_SIZE=2048
MODULE_IFLAGS += -DHAVE_CONFIG_H
MODULE_IFLAGS += -DHAVE_NETINET_IN_H=1
MODULE_IFLAGS += -DHAVE_STDLIB_H=1
MODULE_IFLAGS += -DHAVE_STDINT_H=1
MODULE_IFLAGS += -DHAVE_INTTYPES_H=1
MODULE_IFLAGS += -DHAVE_UINT8_T=1
MODULE_IFLAGS += -DHAVE_UINT16_T=1
MODULE_IFLAGS += -DHAVE_UINT32_T=1
MODULE_IFLAGS += -DHAVE_INT32_T=1
MODULE_IFLAGS += -DHAVE_UINT64_T=1
MODULE_IFLAGS += -DCPU_CISC=1
MODULE_IFLAGS += -DPRIx64=PRIx32
MODULE_IFLAGS += -DPACKAGE_STRING=\"libsrtp\"
MODULE_IFLAGS += -DPACKAGE_VERSION=\"2.4\"
MODULE_IFLAGS += -DSIZEOF_UNSIGNED_LONG=4
MODULE_IFLAGS += -DSIZEOF_UNSIGNED_LONG_LONG=8
MODULE_IFLAGS += -I$(LIBPEER_DIR)/compat
MODULE_IFLAGS += -I$(LIBPEER_DIR)/compat/net
MODULE_IFLAGS += -I$(LIBPEER_SRC)
MODULE_IFLAGS += -I$(COREMQTT_DIR)/include
MODULE_IFLAGS += -I$(COREMQTT_DIR)/interface
MODULE_IFLAGS += -I$(COREHTTP_DIR)/include
MODULE_IFLAGS += -I$(COREHTTP_DIR)/interface
MODULE_IFLAGS += -I/home/uafarooq/esp/libpeer/third_party/coreHTTP/source/dependency/3rdparty/llhttp/include
MODULE_IFLAGS += -I$(LIBSRTP_DIR)/include
MODULE_IFLAGS += -I$(LIBSRTP_DIR)/crypto/include
MODULE_IFLAGS += -I$(LIBSRTP_DIR)/crypto/cipher
MODULE_IFLAGS += -I$(LIBSRTP_DIR)/crypto/hash
MODULE_IFLAGS += -I$(LIBSRTP_DIR)/test
MODULE_IFLAGS += -I$(BASEDIR)/../libpeer/third_party/usrsctp/usrsctplib
MODULE_IFLAGS += -I$(BASEDIR)/../libpeer/third_party/usrsctp/usrsctplib/netinet
MODULE_IFLAGS += -I$(BASEDIR)/../libpeer/third_party/usrsctp/usrsctplib/netinet6

lp_address.c:
	cp $(LIBPEER_SRC)/address.c lp_address.c

lp_agent.c:
	cp $(LIBPEER_SRC)/agent.c lp_agent.c

lp_base64.c:
	cp $(LIBPEER_SRC)/base64.c lp_base64.c

lp_dtls_srtp.c:
	cp $(LIBPEER_SRC)/dtls_srtp.c lp_dtls_srtp.c

lp_ice.c:
	cp $(LIBPEER_SRC)/ice.c lp_ice.c

lp_mdns.c:
	cp $(LIBPEER_SRC)/mdns.c lp_mdns.c

lp_peer.c:
	cp $(LIBPEER_SRC)/peer.c lp_peer.c

lp_peer_connection.c:
	cp $(LIBPEER_SRC)/peer_connection.c lp_peer_connection.c

lp_peer_signaling.c:
	cp $(LIBPEER_SRC)/peer_signaling.c lp_peer_signaling.c

lp_ports.c:
	cp $(LIBPEER_SRC)/ports.c lp_ports.c

lp_rtcp.c:
	cp $(LIBPEER_SRC)/rtcp.c lp_rtcp.c

lp_rtp.c:
	cp $(LIBPEER_SRC)/rtp.c lp_rtp.c

lp_sctp.c:
	cp $(LIBPEER_SRC)/sctp.c lp_sctp.c

lp_sdp.c:
	cp $(LIBPEER_SRC)/sdp.c lp_sdp.c

lp_socket.c:
	cp $(LIBPEER_SRC)/socket.c lp_socket.c

lp_ssl_transport.c:
	cp $(LIBPEER_SRC)/ssl_transport.c lp_ssl_transport.c

lp_stun.c:
	cp $(LIBPEER_SRC)/stun.c lp_stun.c

lp_utils.c:
	cp $(LIBPEER_SRC)/utils.c lp_utils.c

lp_core_mqtt.c:
	cp $(COREMQTT_DIR)/core_mqtt.c lp_core_mqtt.c

lp_core_mqtt_state.c:
	cp $(COREMQTT_DIR)/core_mqtt_state.c lp_core_mqtt_state.c

lp_core_mqtt_serializer.c:
	cp $(COREMQTT_DIR)/core_mqtt_serializer.c lp_core_mqtt_serializer.c

lp_cJSON.c:
	cp $(CJSON_DIR)/cJSON.c lp_cJSON.c

lp_core_http_client.c:
	cp $(COREHTTP_DIR)/core_http_client.c lp_core_http_client.c

lp_llhttp.c:
	cp /home/uafarooq/esp/libpeer/third_party/coreHTTP/source/dependency/3rdparty/llhttp/src/llhttp.c lp_llhttp.c

lp_llhttp_api.c:
	cp /home/uafarooq/esp/libpeer/third_party/coreHTTP/source/dependency/3rdparty/llhttp/src/api.c lp_llhttp_api.c

lp_llhttp_http.c:
	cp /home/uafarooq/esp/libpeer/third_party/coreHTTP/source/dependency/3rdparty/llhttp/src/http.c lp_llhttp_http.c

lp_usrsctp_sctp_asconf.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_asconf.c lp_usrsctp_sctp_asconf.c

lp_usrsctp_sctp_auth.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_auth.c lp_usrsctp_sctp_auth.c

lp_usrsctp_sctp_bsd_addr.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_bsd_addr.c lp_usrsctp_sctp_bsd_addr.c

lp_usrsctp_sctp_callout.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_callout.c lp_usrsctp_sctp_callout.c

lp_usrsctp_sctp_cc_functions.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_cc_functions.c lp_usrsctp_sctp_cc_functions.c

lp_usrsctp_sctp_crc32.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_crc32.c lp_usrsctp_sctp_crc32.c

lp_usrsctp_sctp_indata.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_indata.c lp_usrsctp_sctp_indata.c

lp_usrsctp_sctp_input.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_input.c lp_usrsctp_sctp_input.c

lp_usrsctp_sctp_output.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_output.c lp_usrsctp_sctp_output.c

lp_usrsctp_sctp_pcb.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_pcb.c lp_usrsctp_sctp_pcb.c

lp_usrsctp_sctp_peeloff.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_peeloff.c lp_usrsctp_sctp_peeloff.c

lp_usrsctp_sctp_sha1.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_sha1.c lp_usrsctp_sctp_sha1.c

lp_usrsctp_sctp_ss_functions.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_ss_functions.c lp_usrsctp_sctp_ss_functions.c

lp_usrsctp_sctp_sysctl.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_sysctl.c lp_usrsctp_sctp_sysctl.c

lp_usrsctp_sctp_timer.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_timer.c lp_usrsctp_sctp_timer.c

lp_usrsctp_sctp_userspace.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_userspace.c lp_usrsctp_sctp_userspace.c

lp_usrsctp_sctp_usrreq.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctp_usrreq.c lp_usrsctp_sctp_usrreq.c

lp_usrsctp_sctputil.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet/sctputil.c lp_usrsctp_sctputil.c

lp_usrsctp_sctp6_usrreq.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/netinet6/sctp6_usrreq.c lp_usrsctp_sctp6_usrreq.c

lp_usrsctp_user_environment.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/user_environment.c lp_usrsctp_user_environment.c

lp_usrsctp_user_mbuf.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/user_mbuf.c lp_usrsctp_user_mbuf.c

lp_usrsctp_user_recv_thread.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/user_recv_thread.c lp_usrsctp_user_recv_thread.c

lp_usrsctp_user_socket.c:
	cp /home/uafarooq/esp/libpeer/third_party/usrsctp/usrsctplib/user_socket.c lp_usrsctp_user_socket.c

lp_srtp_srtp.c:
	cp $(LIBSRTP_DIR)/srtp/srtp.c lp_srtp_srtp.c

lp_srtp_cipher.c:
	cp $(LIBSRTP_DIR)/crypto/cipher/cipher.c lp_srtp_cipher.c

lp_srtp_null_cipher.c:
	cp $(LIBSRTP_DIR)/crypto/cipher/null_cipher.c lp_srtp_null_cipher.c

lp_srtp_aes.c:
	cp $(LIBSRTP_DIR)/crypto/cipher/aes.c lp_srtp_aes.c

lp_srtp_aes_icm.c:
	cp $(LIBSRTP_DIR)/crypto/cipher/aes_icm.c lp_srtp_aes_icm.c

lp_srtp_cipher_test_cases.c:
	cp $(LIBSRTP_DIR)/crypto/cipher/cipher_test_cases.c lp_srtp_cipher_test_cases.c

lp_srtp_auth.c:
	cp $(LIBSRTP_DIR)/crypto/hash/auth.c lp_srtp_auth.c

lp_srtp_null_auth.c:
	cp $(LIBSRTP_DIR)/crypto/hash/null_auth.c lp_srtp_null_auth.c

lp_srtp_hmac.c:
	cp $(LIBSRTP_DIR)/crypto/hash/hmac.c lp_srtp_hmac.c

lp_srtp_sha1.c:
	cp $(LIBSRTP_DIR)/crypto/hash/sha1.c lp_srtp_sha1.c

lp_srtp_auth_test_cases.c:
	cp $(LIBSRTP_DIR)/crypto/hash/auth_test_cases.c lp_srtp_auth_test_cases.c

lp_srtp_alloc.c:
	cp $(LIBSRTP_DIR)/crypto/kernel/alloc.c lp_srtp_alloc.c

lp_srtp_crypto_kernel.c:
	cp $(LIBSRTP_DIR)/crypto/kernel/crypto_kernel.c lp_srtp_crypto_kernel.c

lp_srtp_err.c:
	cp $(LIBSRTP_DIR)/crypto/kernel/err.c lp_srtp_err.c

lp_srtp_key.c:
	cp $(LIBSRTP_DIR)/crypto/kernel/key.c lp_srtp_key.c

lp_srtp_datatypes.c:
	cp $(LIBSRTP_DIR)/crypto/math/datatypes.c lp_srtp_datatypes.c

lp_srtp_rdb.c:
	cp $(LIBSRTP_DIR)/crypto/replay/rdb.c lp_srtp_rdb.c

lp_srtp_rdbx.c:
	cp $(LIBSRTP_DIR)/crypto/replay/rdbx.c lp_srtp_rdbx.c


lp_mbedtls_timing.c:
	cp /home/uafarooq/esp/ameba-rtos-d/component/common/network/ssl/mbedtls-3.4.0/library/timing.c lp_mbedtls_timing.c


lp_example_libpeer.c:
	cp $(LIBPEER_DIR)/example_libpeer.c lp_example_libpeer.c

lp_mbedtls_stubs.c:
	cp /home/uafarooq/esp/ameba-rtos-d/component/common/example/libpeer/compat/mbedtls_stubs.c lp_mbedtls_stubs.c

CSRC += lp_usrsctp_sctp_asconf.c
CSRC += lp_usrsctp_sctp_auth.c
CSRC += lp_usrsctp_sctp_bsd_addr.c
CSRC += lp_usrsctp_sctp_callout.c
CSRC += lp_usrsctp_sctp_cc_functions.c
CSRC += lp_usrsctp_sctp_crc32.c
CSRC += lp_usrsctp_sctp_indata.c
CSRC += lp_usrsctp_sctp_input.c
CSRC += lp_usrsctp_sctp_output.c
CSRC += lp_usrsctp_sctp_pcb.c
CSRC += lp_usrsctp_sctp_peeloff.c
CSRC += lp_usrsctp_sctp_sha1.c
CSRC += lp_usrsctp_sctp_ss_functions.c
CSRC += lp_usrsctp_sctp_sysctl.c
CSRC += lp_usrsctp_sctp_timer.c
CSRC += lp_usrsctp_sctp_userspace.c
CSRC += lp_usrsctp_sctp_usrreq.c
CSRC += lp_usrsctp_sctputil.c
CSRC += lp_usrsctp_sctp6_usrreq.c
CSRC += lp_usrsctp_user_environment.c
CSRC += lp_usrsctp_user_mbuf.c
CSRC += lp_usrsctp_user_recv_thread.c
CSRC += lp_usrsctp_user_socket.c
CSRC += lp_address.c
CSRC += lp_agent.c
CSRC += lp_base64.c
CSRC += lp_dtls_srtp.c
CSRC += lp_ice.c
CSRC += lp_mdns.c
CSRC += lp_peer.c
CSRC += lp_peer_connection.c
CSRC += lp_peer_signaling.c
CSRC += lp_ports.c
CSRC += lp_rtcp.c
CSRC += lp_rtp.c
CSRC += lp_sctp.c
CSRC += lp_sdp.c
CSRC += lp_socket.c
CSRC += lp_ssl_transport.c
CSRC += lp_stun.c
CSRC += lp_utils.c
CSRC += lp_core_mqtt.c
CSRC += lp_core_mqtt_state.c
CSRC += lp_core_mqtt_serializer.c
CSRC += lp_cJSON.c
CSRC += lp_core_http_client.c
CSRC += lp_llhttp.c
CSRC += lp_llhttp_api.c
CSRC += lp_llhttp_http.c
CSRC += lp_srtp_srtp.c
CSRC += lp_srtp_cipher.c
CSRC += lp_srtp_null_cipher.c
CSRC += lp_srtp_aes.c
CSRC += lp_srtp_aes_icm.c
CSRC += lp_srtp_cipher_test_cases.c
CSRC += lp_srtp_auth.c
CSRC += lp_srtp_null_auth.c
CSRC += lp_srtp_hmac.c
CSRC += lp_srtp_sha1.c
CSRC += lp_srtp_auth_test_cases.c
CSRC += lp_srtp_alloc.c
CSRC += lp_srtp_crypto_kernel.c
CSRC += lp_srtp_err.c
CSRC += lp_srtp_key.c
CSRC += lp_srtp_datatypes.c
CSRC += lp_srtp_rdb.c
CSRC += lp_srtp_rdbx.c
CSRC += lp_mbedtls_timing.c
CSRC += lp_example_libpeer.c
CSRC += lp_mbedtls_stubs.c

OBJS = lp_usrsctp_sctp_asconf.o lp_usrsctp_sctp_auth.o lp_usrsctp_sctp_bsd_addr.o lp_usrsctp_sctp_callout.o lp_usrsctp_sctp_cc_functions.o lp_usrsctp_sctp_crc32.o lp_usrsctp_sctp_indata.o lp_usrsctp_sctp_input.o lp_usrsctp_sctp_output.o lp_usrsctp_sctp_pcb.o lp_usrsctp_sctp_peeloff.o lp_usrsctp_sctp_sha1.o lp_usrsctp_sctp_ss_functions.o lp_usrsctp_sctp_sysctl.o lp_usrsctp_sctp_timer.o lp_usrsctp_sctp_userspace.o lp_usrsctp_sctp_usrreq.o lp_usrsctp_sctputil.o lp_usrsctp_sctp6_usrreq.o lp_usrsctp_user_environment.o lp_usrsctp_user_mbuf.o lp_usrsctp_user_recv_thread.o lp_usrsctp_user_socket.o lp_address.o lp_agent.o lp_base64.o lp_dtls_srtp.o lp_ice.o lp_mdns.o lp_peer.o lp_peer_connection.o lp_peer_signaling.o lp_ports.o lp_rtcp.o lp_rtp.o lp_sctp.o lp_sdp.o lp_socket.o lp_ssl_transport.o lp_stun.o lp_utils.o lp_core_mqtt.o lp_core_mqtt_state.o lp_core_mqtt_serializer.o lp_cJSON.o lp_core_http_client.o lp_llhttp.o lp_llhttp_api.o lp_llhttp_http.o lp_srtp_srtp.o lp_srtp_cipher.o lp_srtp_null_cipher.o lp_srtp_aes.o lp_srtp_aes_icm.o lp_srtp_cipher_test_cases.o lp_srtp_auth.o lp_srtp_null_auth.o lp_srtp_hmac.o lp_srtp_sha1.o lp_srtp_auth_test_cases.o lp_srtp_alloc.o lp_srtp_crypto_kernel.o lp_srtp_err.o lp_srtp_key.o lp_srtp_datatypes.o lp_srtp_rdb.o lp_srtp_rdbx.o lp_mbedtls_timing.o lp_example_libpeer.o lp_mbedtls_stubs.o

%.o: %.c
	$(CC) $(GLOBAL_CFLAGS) $(MODULE_IFLAGS) $< -o $@

all: $(CSRC) CORE_TARGETS COPY_RAM_OBJS

CORE_TARGETS: $(OBJS)

clean: CLEAN_OBJS
	$(REMOVE) *.o *.i *.s *.d *.c

-include $(DEPS)
