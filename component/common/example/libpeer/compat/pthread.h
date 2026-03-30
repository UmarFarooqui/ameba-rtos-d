#pragma once
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

typedef SemaphoreHandle_t pthread_mutex_t;
typedef SemaphoreHandle_t pthread_rwlock_t;
typedef SemaphoreHandle_t pthread_cond_t;
typedef TaskHandle_t      pthread_t;
typedef int pthread_mutexattr_t;
typedef int pthread_rwlockattr_t;
typedef int pthread_condattr_t;
typedef int pthread_attr_t;

#define PTHREAD_MUTEX_INITIALIZER   NULL
#define PTHREAD_RWLOCK_INITIALIZER  NULL

#define pthread_mutex_init(m,a)     ((*(m)=xSemaphoreCreateMutex())?0:-1)
#define pthread_mutex_lock(m)       (xSemaphoreTake(*(m),portMAX_DELAY)?0:-1)
#define pthread_mutex_unlock(m)     (xSemaphoreGive(*(m))?0:-1)
#define pthread_mutex_destroy(m)    vSemaphoreDelete(*(m))
#define pthread_mutex_trylock(m)    (xSemaphoreTake(*(m),0)?0:-1)

#define pthread_rwlock_init(m,a)    ((*(m)=xSemaphoreCreateMutex())?0:-1)
#define pthread_rwlock_rdlock(m)    (xSemaphoreTake(*(m),portMAX_DELAY)?0:-1)
#define pthread_rwlock_wrlock(m)    (xSemaphoreTake(*(m),portMAX_DELAY)?0:-1)
#define pthread_rwlock_unlock(m)    (xSemaphoreGive(*(m))?0:-1)
#define pthread_rwlock_destroy(m)   vSemaphoreDelete(*(m))

#define pthread_cond_init(c,a)      ((*(c)=xSemaphoreCreateBinary())?0:-1)
#define pthread_cond_signal(c)      (xSemaphoreGive(*(c))?0:-1)
#define pthread_cond_broadcast(c)   (xSemaphoreGive(*(c))?0:-1)
#define pthread_cond_wait(c,m)      (xSemaphoreTake(*(c),portMAX_DELAY)?0:-1)
#define pthread_cond_destroy(c)     vSemaphoreDelete(*(c))
#define pthread_mutexattr_init(a)   0
#define pthread_mutexattr_destroy(a) 0
#define pthread_mutexattr_settype(a,t) 0
#define pthread_rwlockattr_init(a)  0
#define pthread_rwlockattr_destroy(a) 0

#define pthread_create(t,a,f,arg)   (xTaskCreate(f,"sctp",4096,arg,2,(TaskHandle_t*)(t))?0:-1)
#define pthread_join(t,r)           0
#define pthread_self()              xTaskGetCurrentTaskHandle()
#define pthread_equal(a,b)          ((a)==(b))
