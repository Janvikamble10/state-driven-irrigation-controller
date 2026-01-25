/*
 * system_state.c
 *
 *  Created on: Jan 26, 2026
 *      Author: janvi
 */


#include "system_state.h"
/* current system state */
static system_state_t current_state=STATE_INIT;
/* Set system state*/
void system_state_set(system_state_t new_state)
{
	current_state = new_state;

}
/* get current system state */
system_state_t system_state_get(void)
{
	return current_state;
}
