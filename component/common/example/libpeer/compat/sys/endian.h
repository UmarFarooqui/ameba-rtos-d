#pragma once
/* Endian stub for usrsctp on AmebaD */
#include <machine/endian.h>
#ifndef BYTE_ORDER
#define LITTLE_ENDIAN 1234
#define BIG_ENDIAN    4321
#define BYTE_ORDER    LITTLE_ENDIAN
#endif
#ifndef htobe16
#include <lwip/def.h>
#define htobe16(x) lwip_htons(x)
#define htobe32(x) lwip_htonl(x)
#define be16toh(x) lwip_ntohs(x)
#define be32toh(x) lwip_ntohl(x)
#define htole16(x) (x)
#define htole32(x) (x)
#define le16toh(x) (x)
#define le32toh(x) (x)
#endif
