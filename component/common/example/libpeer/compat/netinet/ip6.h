#pragma once
#include <stdint.h>
#include "lwip/sockets.h"
struct ip6_hdr {
    uint32_t ip6_flow;
    uint16_t ip6_plen;
    uint8_t  ip6_nxt;
    uint8_t  ip6_hlim;
    struct in6_addr ip6_src, ip6_dst;
};
