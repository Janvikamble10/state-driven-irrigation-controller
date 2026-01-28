#include "soil_sensor.h"

/* Simulated soil moisture value */
static uint16_t fake_moisture = 300;

/* Limits to keep values realistic */
#define MOISTURE_MAX  800
#define MOISTURE_MIN  200

uint16_t soil_sensor_read(void)
{
    return fake_moisture;
}

/* Called when watering finishes */
void soil_sensor_on_watering(void)
{
    if (fake_moisture < MOISTURE_MAX)
    {
        fake_moisture += 80;

        if (fake_moisture > MOISTURE_MAX)
        {
            fake_moisture = MOISTURE_MAX;
        }
    }
}

/* Called periodically to simulate drying */
void soil_sensor_decay(void)
{
    if (fake_moisture > MOISTURE_MIN)
    {
        fake_moisture -= 5;
    }
}
