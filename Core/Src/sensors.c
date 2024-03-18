/*
 * sensors.c
 *
 *  Created on: 9 мар. 2024 г.
 *      Author: Dima
 */

/* Includes ------------------------------------------------------------------*/
#include "sensors.h"
/* Private define ------------------------------------------------------------*/


/* Private includes ----------------------------------------------------------*/


/* Private typedef -----------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private constants and variables -------------------------------------------*/
BME280_sensor_t BME280_sensor;

/* Private function prototypes -----------------------------------------------*/


/* Private user code ---------------------------------------------------------*/
void sensors_Init(void)
{
	BME280_sensor.temperature = 0.0f;
	BME280_sensor.pressure = 0.0f;
	BME280_sensor.humidity = 0.0f;
	BME280_Init();
}

void sensors_Handle(void)
{
	BME280_sensor.temperature = BME280_ReadTemperature();
	BME280_sensor.pressure = BME280_ReadPressure();

}
