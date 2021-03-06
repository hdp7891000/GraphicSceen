/*
 * systemStatus.h
 *
 *  Created on: Jan 9, 2016
 *      Author: pavelgamov
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stdbool.h>

typedef enum {
	INFORM_INIT,
	INFORM_PREHEAT,
	INFORM_IDLE,
	INFORM_SLEEP,
	INFORM_CONNECTION_LOST,
	INFORM_ERROR,
	INFORM_LAST
} systemStatus_t;

typedef void (*ledOutputControl_t)(const _Bool);

void System_setLedControl(ledOutputControl_t);
void System_setStatus(systemStatus_t);

uint32_t System_getUptime(void);
uint32_t System_getUptimeMs(void);

void System_delayMsDummy(uint32_t delay);

int System_Lock(void);
void System_Unlock(int primask);
void System_Poll(void);

#ifdef __cplusplus
}
#endif


#endif /* SYSTEM_H_ */
