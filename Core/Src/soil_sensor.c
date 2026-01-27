#include "soil_sensor.h"

/* fake soil moisture value */
static uint16_t fake_moisture = 300;

uint16_t soil_sensor_read(void)
{
	return fake_moisture;
}
