#ifndef SOIL_SENSOR_H
#define SOIL_SENSOR_H

#include <stdint.h>
/* read current soil moisture value*/
uint16_t soil_sensor_read(void);

void soil_sensor_on_watering(void);
/* call periodically to simulate drying */
void soil_sensor_decay(void);

#endif

