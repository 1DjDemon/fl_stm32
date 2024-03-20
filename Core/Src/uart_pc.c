/**
  ******************************************************************************
  * @file           : uart_pc.c
  * @author         : Malahov
  * @version        : 0.1.0
  * @brief          : Описание отправки данных на ПК
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "uart_pc.h"
#include "stdio.h"
#include "sensors.h"

/* Private define ------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private constants and variables -------------------------------------------*/
uint8_t data[64];

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/
void uart_pc_init 	(void)
{}
void uart_pc_handle	(void)
{

	sprintf((char*)data,	"%02d:%02d:%02d %02d.%02d.%02d %.2f %.2f   \n\r", 	timedata.hour,
																				timedata.min,
																				timedata.sec,
																				timedata.date,
																				timedata.month,
																				timedata.year,
																				BME280_sensor.temperature,
																				BME280_sensor.pressure
																				);
//
//	data[0] = timedata.hour;
//	data[1] = timedata.min;
//	data[2] = timedata.sec;
//	data[3] = timedata.date;
//	data[4] = timedata.month;
//	data[5] = timedata.year;

	HAL_UART_Transmit_IT(&huart2, data, sizeof(data));
}

/************************ (C) COPYRIGHT malahov ****************END OF FILE****/
