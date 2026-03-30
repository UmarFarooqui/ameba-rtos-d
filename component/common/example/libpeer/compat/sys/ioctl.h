#pragma once
#ifndef SIOCGIFCONF
#define SIOCGIFCONF  0x8912
#define SIOCGIFADDR  0x8915
#define SIOCGIFFLAGS 0x8913
#endif
#ifndef IFNAMSIZ
#define IFNAMSIZ 16
#endif

#ifndef _NANOSLEEP_DEFINED
#define _NANOSLEEP_DEFINED
#include "FreeRTOS.h"
#include "task.h"
static inline int nanosleep(const struct timespec *req, struct timespec *rem) {
    vTaskDelay(pdMS_TO_TICKS(req->tv_sec * 1000 + req->tv_nsec / 1000000));
    return 0;
}
#endif
