#pragma once
#include <stdint.h>
#include "lwip/sockets.h"

#define IPVERSION  4
#define IP_DF      0x4000
#define IP_MF      0x2000
#define IP_OFFMASK 0x1fff

struct ip {
    uint8_t  ip_hl:4, ip_v:4;
    uint8_t  ip_tos;
    uint16_t ip_len;
    uint16_t ip_id;
    uint16_t ip_off;
    uint8_t  ip_ttl;
    uint8_t  ip_p;
    uint16_t ip_sum;
    struct in_addr ip_src, ip_dst;
};
