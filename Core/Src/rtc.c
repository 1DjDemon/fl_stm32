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
//Структура с флагами для настройки дыты и время
typedef struct
{
	uint8_t flag_readtemptimedata;

	uint8_t flag_sec;
	uint8_t flag_min;
	uint8_t flag_hour;

	uint8_t flag_data;
	uint8_t flag_month;
	uint8_t flag_year;

}flag_line_timedata_t;

/* Private macro -------------------------------------------------------------*/


/* Private constants and variables -------------------------------------------*/
rtc_t timedata;
rtc_t temptimedata;

flag_line_timedata_t flag_line_timedata;


/* Private function prototypes -----------------------------------------------*/
void rtc_SetTimeData (void);
void rtc_InstalDataEncoder (void);
void rtc_InstalTimeEncoder (void);


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
}

void rtc_handle (void)
{
	timedata.sec	= DS1307_GetSecond();
	timedata.min	= DS1307_GetMinute();
	timedata.hour	= DS1307_GetHour();

	timedata.date	= DS1307_GetDate();
	timedata.month	= DS1307_GetMonth();
	timedata.year	= DS1307_GetYear();

	if(page_properties.page_list == page_setting_date)
	{
		rtc_InstalDataEncoder();
	}
	if(page_properties.page_list == page_setting_time)
	{
		rtc_InstalTimeEncoder();
	}
}

void rtc_SetTimeData (void)
{
	if(flag_line_timedata.flag_data)
	{
		DS1307_SetDate(temptimedata.date);
		flag_line_timedata.flag_data = 0;
	}
	if(flag_line_timedata.flag_month)
	{
		DS1307_SetMonth(temptimedata.month);
		flag_line_timedata.flag_month = 0;
	}
	if(flag_line_timedata.flag_year)
	{
		DS1307_SetYear(temptimedata.year);
		flag_line_timedata.flag_year = 0;
	}
	if(flag_line_timedata.flag_hour)
	{
		DS1307_SetHour(temptimedata.hour);
		flag_line_timedata.flag_hour = 0;
	}
	if(flag_line_timedata.flag_min)
	{
		DS1307_SetMinute(temptimedata.min);
		flag_line_timedata.flag_min = 0;
	}
	if(flag_line_timedata.flag_sec)
	{
		DS1307_SetSecond(temptimedata.sec);
		flag_line_timedata.flag_sec = 0;
	}

	flag_line_timedata.flag_readtemptimedata = 0;
}

void rtc_InstalDataEncoder (void)
{
	if(flag_line_timedata.flag_readtemptimedata == 0)
	{
		flag_line_timedata.flag_readtemptimedata = 1;

		temptimedata.date	= DS1307_GetDate();
		temptimedata.month	= DS1307_GetMonth();
		temptimedata.year	= DS1307_GetYear();
	}

	if(page_properties.line == line_0)
	{
		if(flag_line_timedata.flag_data == 0)
		{
			flag_line_timedata.flag_data = 1;
			(TIM3->CNT) = temptimedata.date * 2;
		}
		else
		{
			if(Enc_Counter > 31)
			{
				(TIM3->CNT) = 0;
			}
			else if((Enc_Counter <1) || (Enc_Counter >100))
			{
				(TIM3->CNT) = 31 * 2;
			}
			temptimedata.date = Enc_Counter;
		}
	}
	if(page_properties.line == line_1)
		{
			if(flag_line_timedata.flag_month == 0)
			{
				flag_line_timedata.flag_month = 1;
				(TIM3->CNT) = temptimedata.month * 2;
			}
			else
			{
				if(Enc_Counter > 12)
				{
					(TIM3->CNT) = 0;
				}
				else if((Enc_Counter <1) || (Enc_Counter >100))
				{
					(TIM3->CNT) = 12 * 2;
				}
				temptimedata.month = Enc_Counter;
			}
		}
	if(page_properties.line == line_2)
		{
			if(flag_line_timedata.flag_year == 0)
			{
				flag_line_timedata.flag_year = 1;
				(TIM3->CNT) = temptimedata.year * 2;
			}
			else
			{
				if(Enc_Counter > 2100)
				{
					(TIM3->CNT) = 2000;
				}
				else if((Enc_Counter <2000) || (Enc_Counter >2500))
				{
					(TIM3->CNT) = 2100 * 2;
				}
				temptimedata.year = Enc_Counter;
			}
		}
	if(page_properties.line == line_3)
	{
		rtc_SetTimeData();
		page_properties.page_list = page_start;
		page_properties.line = line_0;
	}
}

void rtc_InstalTimeEncoder (void)
{
	if(flag_line_timedata.flag_readtemptimedata == 0)
	{
		flag_line_timedata.flag_readtemptimedata = 1;
		temptimedata.sec	= DS1307_GetSecond();
		temptimedata.min	= DS1307_GetMinute();
		temptimedata.hour	= DS1307_GetHour();
	}

	if(page_properties.line == line_0)
	{
		if(flag_line_timedata.flag_hour == 0)
		{
			flag_line_timedata.flag_hour = 1;
			(TIM3->CNT) = temptimedata.hour * 2;
		}
		else
		{
			if(Enc_Counter > 23)
			{
				(TIM3->CNT) = 0;
			}
			else if((Enc_Counter >100))
			{
				(TIM3->CNT) = 23 * 2;
			}
			temptimedata.hour = Enc_Counter;
		}
	}
	if(page_properties.line == line_1)
		{
			if(flag_line_timedata.flag_min == 0)
			{
				flag_line_timedata.flag_min = 1;
				(TIM3->CNT) = temptimedata.min * 2;
			}
			else
			{
				if(Enc_Counter > 59)
				{
					(TIM3->CNT) = 0;
				}
				else if((Enc_Counter >100))
				{
					(TIM3->CNT) = 59 * 2;
				}
				temptimedata.min = Enc_Counter;
			}
		}
	if(page_properties.line == line_2)
		{
			if(flag_line_timedata.flag_sec == 0)
			{
				flag_line_timedata.flag_sec = 1;
				(TIM3->CNT) = temptimedata.sec * 2;
			}
			else
			{
				if(Enc_Counter > 59)
				{
					(TIM3->CNT) = 0;
				}
				else if(Enc_Counter >100)
				{
					(TIM3->CNT) = 59 * 2;
				}
				temptimedata.sec = Enc_Counter;
			}
		}
	if(page_properties.line == line_3)
	{
		rtc_SetTimeData();
		page_properties.page_list = page_start;
		page_properties.line = line_0;
	}
}

/************************ (C) COPYRIGHT malahov ****************END OF FILE****/
