#pragma once
#ifndef IP_PKTINFO
#define IP_PKTINFO      8
#endif
#ifndef IP_RECVDSTADDR
#define IP_RECVDSTADDR  7
#endif
#ifndef IP_HDRINCL
#define IP_HDRINCL      3
#endif
#ifndef _STRUCT_IN_PKTINFO
#define _STRUCT_IN_PKTINFO
struct in_pktinfo {
    int             ipi_ifindex;
    uint32_t        ipi_spec_dst;
    uint32_t        ipi_addr;
};
#endif
#ifndef IPPORT_RESERVED
#define IPPORT_RESERVED 1024
#endif
#include "lwip/sockets.h"
#include "lwip/inet.h"
#ifndef _SOCKADDR_IN6_DEFINED
#define _SOCKADDR_IN6_DEFINED
#ifndef INET6_ADDRSTRLEN
#define INET6_ADDRSTRLEN 46
#endif
struct sockaddr_in6 {
  uint8_t          sin6_len;
  uint8_t          sin6_family;
  uint16_t         sin6_port;
  uint32_t         sin6_flowinfo;
  struct in6_addr  sin6_addr;
  uint32_t         sin6_scope_id;
};
#endif
#ifndef IN6ADDR_ANY_INIT
#define IN6ADDR_ANY_INIT {{{0}}}
#endif
extern const struct in6_addr in6addr_any;
