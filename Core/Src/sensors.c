/**
  ******************************************************************************
  * @file           : sensors.c
  * @author         : malahov
  * @version        : 0.1.0
  * @brief          : Файл содержит основные опрделения и функции получения
  *                   данных с датчиков.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "sensors.h"
/* Private define ------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private constants and variables -------------------------------------------*/
//Переменная в которую считывается температура и давление
BME280_sensor_t BME280_sensor;

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/
void sensors_Init(void)
{
	//Инициализация датчика BME280
	BME280_sensor.temperature = 0.0f;
	BME280_sensor.pressure = 0.0f;
	BME280_sensor.humidity = 0.0f;

	BME280_Init();
}

void sensors_Handle(void)
{
	//Задача получения температуры и давления с датчика
	BME280_sensor.temperature = BME280_ReadTemperature();
	BME280_sensor.pressure = BME280_ReadPressure();
}


/************************ (C) COPYRIGHT malahov ****************END OF FILE****/
