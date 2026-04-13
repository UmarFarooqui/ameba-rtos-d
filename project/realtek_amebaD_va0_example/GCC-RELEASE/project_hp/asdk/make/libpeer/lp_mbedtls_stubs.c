#include "mbedtls/ssl.h"

void mbedtls_ssl_conf_dtls_cookies(
    mbedtls_ssl_config *conf,
    mbedtls_ssl_cookie_write_t *f_cookie_write,
    mbedtls_ssl_cookie_check_t *f_cookie_check,
    void *p_cookie) {
    (void)conf; (void)f_cookie_write;
    (void)f_cookie_check; (void)p_cookie;
}

int mbedtls_ssl_set_client_transport_id(
    mbedtls_ssl_context *ssl,
    const unsigned char *info,
    size_t ilen) {
    (void)ssl; (void)info; (void)ilen;
    return 0;
}
