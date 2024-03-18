/**
  ******************************************************************************
  * @file           : rtc.c
  * @author         : malahov
  * @version        : 0.1.0
  * @brief          :
  ******************************************************************************
  */


/* Private includes ----------------------------------------------------------*/
//#include "main.h"
#include "rtc.h"
#include "ds1307_for_stm32_hal.h"

/* Private define ------------------------------------------------------------*/


/* Private typedef -----------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private constants and variables -------------------------------------------*/
rtc_t timedata;

/* Private function prototypes -----------------------------------------------*/


/* Private user code ---------------------------------------------------------*/
void rtc_Init(void)
{
	timedata.sec	= 0;
	timedata.min	= 0;
	timedata.hour	= 0;

	timedata.date	= 0;
	timedata.month	= 0;
	timedata.year	= 0;

	DS1307_Init(&hi2c2);

//		DS1307_SetTimeZone(+3, 00);
//		DS1307_SetDate(17);
//		DS1307_SetMonth(3);
//		DS1307_SetYear(2024);
////		DS1307_SetDayOfWeek(4);
//		DS1307_SetHour(17);
//		DS1307_SetMinute(6);
//		DS1307_SetSecond(00);
}

void rtc_handle (void)
{
	timedata.sec	= DS1307_GetSecond();
	timedata.min	= DS1307_GetMinute();
	timedata.hour	= DS1307_GetHour();

	timedata.date	= DS1307_GetDate();
	timedata.month	= DS1307_GetMonth();
	timedata.year	= DS1307_GetYear();
}

/************************ (C) COPYRIGHT malahov ****************END OF FILE****/
