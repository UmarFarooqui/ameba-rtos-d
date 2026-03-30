#pragma once
#include <stdint.h>
#include "lwip/sockets.h"

struct ifaddrs {
    struct ifaddrs  *ifa_next;
    char            *ifa_name;
    unsigned int     ifa_flags;
    struct sockaddr *ifa_addr;
    struct sockaddr *ifa_netmask;
    struct sockaddr *ifa_broadaddr;
    void            *ifa_data;
};

static inline int getifaddrs(struct ifaddrs **ifap) { *ifap = NULL; return -1; }
static inline void freeifaddrs(struct ifaddrs *ifa) { (void)ifa; }
