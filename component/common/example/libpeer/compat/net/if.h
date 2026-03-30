#pragma once
#include <stdint.h>
#include "lwip/sockets.h"

#ifndef IFNAMSIZ
#define IFNAMSIZ 16
#endif
#ifndef IF_NAMESIZE
#define IF_NAMESIZE 16
#endif

#ifndef SIOCGIFMTU
#define SIOCGIFMTU   0x8921
#define SIOCGIFCONF  0x8912
#define SIOCGIFADDR  0x8915
#define SIOCGIFFLAGS 0x8913
#endif

struct ifreq {
    char ifr_name[IFNAMSIZ];
    union {
        struct sockaddr ifr_addr;
        struct sockaddr ifr_dstaddr;
        struct sockaddr ifr_broadaddr;
        struct sockaddr ifr_netmask;
        struct sockaddr ifr_hwaddr;
        short           ifr_flags;
        int             ifr_ifindex;
        int             ifr_metric;
        int             ifr_mtu;
        char            ifr_slave[IFNAMSIZ];
        char            ifr_newname[IFNAMSIZ];
        char           *ifr_data;
    };
};

struct if_nameindex {
    unsigned int if_index;
    char *if_name;
};

static inline unsigned int if_nametoindex(const char *ifname) { return 0; }
static inline char *if_indextoname(unsigned int i, char *n) { return NULL; }
