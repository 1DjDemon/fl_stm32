/**
  ******************************************************************************
  * @file           : rtc.h
  * @author	        : malahov
  * @version        : 0.1.0
  * @brief          : Заголовочный файл для rtc.c
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RTC_H
#define __RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "display.h"

/* Exported defines ----------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
typedef struct {

	uint8_t		sec;
	uint8_t		min;
	uint8_t 	hour;

	uint8_t 	date;
	uint8_t 	month;
	uint16_t	year;

	int8_t		timezone;

}rtc_t;


/* Exported constants and variables ------------------------------------------*/
extern rtc_t timedata;
extern rtc_t temptimedata;

/* Exported functions prototypes ---------------------------------------------*/
void rtc_Init(void);

void rtc_handle (void);

#ifdef __cplusplus
}
#endif

#endif /* __RTC_H */

/************************ (C) COPYRIGHT malahov ****************END OF FILE****/
