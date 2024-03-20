/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "gps_neo6.h"
#include "usart.h"
#include "stdio.h"
#include "ds1307_for_stm32_hal.h"
#include "tim.h"
#include "i2c.h"
//#include "_bme280.h"
//#include "BME280.h"

#include "sensors.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
//uint8_t Message[64];
//uint8_t Message2[64];
//uint8_t Message3[64];




//uint32_t Timer1 = HAL_GetTick();

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId displeyTaskHandle;
osThreadId encodetTaskHandle;
osThreadId gpsTaskHandle;
osThreadId rtcTaskHandle;
osThreadId UARTTaskHandle;
osThreadId sensorsTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartdispleyTask(void const * argument);
void StartencodetTask(void const * argument);
void StartGPSTask(void const * argument);
void StartRTCTask(void const * argument);
void StartUARTTask(void const * argument);
void StartSensorTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of displeyTask */
  osThreadDef(displeyTask, StartdispleyTask, osPriorityLow, 0, 512);
  displeyTaskHandle = osThreadCreate(osThread(displeyTask), NULL);

  /* definition and creation of encodetTask */
  osThreadDef(encodetTask, StartencodetTask, osPriorityLow, 0, 128);
  encodetTaskHandle = osThreadCreate(osThread(encodetTask), NULL);

  /* definition and creation of gpsTask */
  osThreadDef(gpsTask, StartGPSTask, osPriorityLow, 0, 128);
  gpsTaskHandle = osThreadCreate(osThread(gpsTask), NULL);

  /* definition and creation of rtcTask */
  osThreadDef(rtcTask, StartRTCTask, osPriorityLow, 0, 128);
  rtcTaskHandle = osThreadCreate(osThread(rtcTask), NULL);

  /* definition and creation of UARTTask */
  osThreadDef(UARTTask, StartUARTTask, osPriorityIdle, 0, 256);
  UARTTaskHandle = osThreadCreate(osThread(UARTTask), NULL);

  /* definition and creation of sensorsTask */
  osThreadDef(sensorsTask, StartSensorTask, osPriorityIdle, 0, 128);
  sensorsTaskHandle = osThreadCreate(osThread(sensorsTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartdispleyTask */
/**
* @brief Function implementing the displeyTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartdispleyTask */
void StartdispleyTask(void const * argument)
{
  /* USER CODE BEGIN StartdispleyTask */
	display_Init();
  /* Infinite loop */
	for(;;)
	{
//		ssd1306_SetCursor(2,0);
//		ssd1306_WriteString((char*)Message, Font_11x18, White);
//		ssd1306_Line(2, 17, 24, 17, White);
//
//		ssd1306_SetCursor(2, 20);
//		sprintf((char*)Message2,	"T= %.2fC", BME280_sensor.temperature);
//		ssd1306_WriteString((char*)Message2, Font_11x18, White);
//		ssd1306_SetCursor(2, 38);
//
//		sprintf((char*)Message3,	"P= %.2fkPa", BME280_sensor.pressure/1000);
//		ssd1306_WriteString((char*)Message3, Font_11x18, White);

		display_handle();

		osDelay(500);
	}
  /* USER CODE END StartdispleyTask */
}

/* USER CODE BEGIN Header_StartencodetTask */
/**
* @brief Function implementing the encodetTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartencodetTask */
void StartencodetTask(void const * argument)
{
  /* USER CODE BEGIN StartencodetTask */
	encoder_init();
  /* Infinite loop */
	for(;;)
	  {
//		  encoder_handle();
//		if(&htim3.Instance->CR1==0x01)// по часовой стрелке
//		{
//					Rotary++;
//		}
		encoder_handling();
		keyboard_handling();


		//sprintf((char*)Message2, "E %02d      ", test);


//		Enc_Counter = (TIM3->CNT)/2;
		  //sprintf((char*)Message3, "E %02d      ", Enc_Counter);
		  osDelay(1);
	  }
  /* USER CODE END StartencodetTask */
}

/* USER CODE BEGIN Header_StartGPSTask */
/**
* @brief Function implementing the gpsTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartGPSTask */
void StartGPSTask(void const * argument)
{
  /* USER CODE BEGIN StartGPSTask */
	sprintf((char*)Message, "T %02d:%02d:%02d", 12, 12, 12);
//	NEO6_Init(&GpsState, &huart1);
	osDelay(1000);
	sprintf((char*)Message, "T %02d:%02d:%02d", GpsState.Hour, GpsState.Minute, GpsState.Second);
  /* Infinite loop */
  for(;;)
  {
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
	  NEO6_Task(&GpsState);
	  osDelay(1000);

	  if(NEO6_IsFix(&GpsState))
	  {
		 sprintf((char*)Message, "T %02d:%02d:%02d", GpsState.Hour, GpsState.Minute, GpsState.Second);
	  }
	  else
	  {
		  sprintf((char*)Message, "No Fix\n\r");

	  }


	  osDelay(1000);
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
	  osDelay(1000);
  }
  /* USER CODE END StartGPSTask */
}

/* USER CODE BEGIN Header_StartRTCTask */
/**
* @brief Function implementing the rtcTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartRTCTask */
void StartRTCTask(void const * argument)
{
  /* USER CODE BEGIN StartRTCTask */
  /* Infinite loop */

//	uint8_t second	= 0;
//	uint8_t minute	= 0;
//	uint8_t hour	= 0;
//
//
//	DS1307_Init(&hi2c2);
	rtc_Init();


//	DS1307_SetTimeZone(+3, 00);
//	DS1307_SetDate(14);
//	DS1307_SetMonth(3);
//	DS1307_SetYear(2024);
//	DS1307_SetDayOfWeek(4);
//	DS1307_SetHour(18);
//	DS1307_SetMinute(01);
//	DS1307_SetSecond(00);

  for(;;)
  {
//	  second = DS1307_GetSecond();
//	  minute = DS1307_GetMinute();
//	  hour = DS1307_GetHour();
//
//	  sprintf((char*)Message,	"%02d:%02d:%02d     ", hour, minute, second);
//	  sprintf((char*)Message2,	"SEC %d%d     ",((data/10)%10), (data%10));
//	  sprintf((char*)Message2,	"SEC %02d      ", second);

//	  sprintf((char*)Message3,	"MIN %d%d     ",((data/10)%10), (data%10));
	  //sprintf((char*)Message3,	"MIN %02d      ", minute);
	  rtc_handle();
    osDelay(100);
  }
  /* USER CODE END StartRTCTask */
}

/* USER CODE BEGIN Header_StartUARTTask */
/**
* @brief Function implementing the UARTTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartUARTTask */
void StartUARTTask(void const * argument)
{
  /* USER CODE BEGIN StartUARTTask */
  /* Infinite loop */
  for(;;)
  {
	  uart_pc_handle();
	  osDelay(100);
  }
  /* USER CODE END StartUARTTask */
}

/* USER CODE BEGIN Header_StartSensorTask */
/**
* @brief Function implementing the sensorsTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartSensorTask */
void StartSensorTask(void const * argument)
{
  /* USER CODE BEGIN StartSensorTask */
  /* Infinite loop */

	sensors_Init();

  for(;;)
  {
	  sensors_Handle();
	  osDelay(1000);
  }
  /* USER CODE END StartSensorTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

