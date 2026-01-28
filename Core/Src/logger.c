/*
 * logger.c
 *
 *  Created on: Jan 28, 2026
 *      Author: janvi
 */
#include "logger.h"
#include "main.h"
#include <string.h>

void logger_log(const char *msg)
{
	HAL_UART_Transmit(
			&huart1,
			(uint8_t *)msg,
			strlen(msg),
			HAL_MAX_DELAY


	);

}

