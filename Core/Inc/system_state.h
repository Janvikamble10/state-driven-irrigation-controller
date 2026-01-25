/*
 * system_state.h
 *
 *  Created on: Jan 26, 2026
 *      Author: janvi
 */

#ifndef INC_SYSTEM_STATE_H_
#define INC_SYSTEM_STATE_H_

typedef enum
{
	STATE_INIT=0,
	STATE_IDLE,
	STATE_MEASURING,
	STATE_WATERING,
	STATE_COOLDOWN,
	STATE_ERROR
}system_state_t;

void system_state_set(system_state_t new_state);
system_state_t system_state_get(void);

#endif /* INC_SYSTEM_STATE_H_ */
