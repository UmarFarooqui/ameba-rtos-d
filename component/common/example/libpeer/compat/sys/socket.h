#pragma once
#ifndef SOCK_SEQPACKET
#define SOCK_SEQPACKET 5
#endif
#ifndef SOMAXCONN
#define SOMAXCONN 128
#endif
#ifndef UIO_MAXIOV
#define UIO_MAXIOV 1024
#endif
#ifndef CMSG_ALIGN
#define CMSG_ALIGN(len) (((len)+sizeof(long)-1) & ~(sizeof(long)-1))
#endif
#ifndef MSG_EOR
#define MSG_EOR     0x08
#endif
#ifndef MSG_TRUNC
#define MSG_TRUNC   0x20
#endif
#ifndef MSG_CTRUNC
#define MSG_CTRUNC  0x08
#endif
#ifndef MSG_NOTIFICATION
#define MSG_NOTIFICATION 0x8000
#endif
#include "lwip/sockets.h"

#ifndef _CMSGHDR_DEFINED
#define _CMSGHDR_DEFINED
struct cmsghdr {
    socklen_t cmsg_len;
    int       cmsg_level;
    int       cmsg_type;
};
#ifndef CMSG_DATA
#define CMSG_DATA(cmsg) ((unsigned char *)((cmsg) + 1))
#define CMSG_NXTHDR(mhdr, cmsg) \
    ((cmsg)->cmsg_len < sizeof(struct cmsghdr) ? NULL : \
    (struct cmsghdr *)((char *)(cmsg) + \
    (((cmsg)->cmsg_len + sizeof(int) - 1) & ~(sizeof(int) - 1))))
#define CMSG_FIRSTHDR(mhdr) \
    ((mhdr)->msg_controllen >= sizeof(struct cmsghdr) ? \
    (struct cmsghdr *)(mhdr)->msg_control : NULL)
#define CMSG_SPACE(len) (sizeof(struct cmsghdr) + (len))
#define CMSG_LEN(len)   (sizeof(struct cmsghdr) + (len))
#endif
#endif

#ifndef recvmsg
static inline int recvmsg(int s, struct msghdr *msg, int flags) {
    int ret = lwip_recv(s, msg->msg_iov[0].iov_base, msg->msg_iov[0].iov_len, flags);
    if (ret > 0) msg->msg_iov[0].iov_len = ret;
    return ret;
}
#endif
