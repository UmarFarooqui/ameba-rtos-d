#pragma once
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
typedef SemaphoreHandle_t pthread_mutex_t;
typedef TaskHandle_t pthread_t;
typedef int pthread_mutexattr_t;
typedef int pthread_attr_t;
#define pthread_mutex_init(m,a)    ((*(m) = xSemaphoreCreateMutex()) ? 0 : -1)
#define pthread_mutex_lock(m)      (xSemaphoreTake(*(m), portMAX_DELAY) ? 0 : -1)
#define pthread_mutex_unlock(m)    (xSemaphoreGive(*(m)) ? 0 : -1)
#define pthread_mutex_destroy(m)   vSemaphoreDelete(*(m))