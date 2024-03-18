/**
  ******************************************************************************
  * @file           : display.c
  * @author         : malahov
  * @version        : 0.1.0
  * @brief          : Файл содержит основные опрделения и функции отображений
  *                   на OLED экране.
  ******************************************************************************
  */

/* Private define ------------------------------------------------------------*/


/* Private includes ----------------------------------------------------------*/
//#include "main.h"
#include "sensors.h"
#include "display.h"
#include "ssd1306.h"
#include "encoder.h"
/* Private typedef -----------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private constants and variables -------------------------------------------*/
uint8_t Message[64];

/* Private function prototypes -----------------------------------------------*/


/* Private user code ---------------------------------------------------------*/
void display_Init(void)
{
	ssd1306_Init();
	osDelay(1000);

}

void display_handle (void)
{
	display_start_screen();
	ssd1306_UpdateScreen();

}

void display_start_screen (void)
{
	ssd1306_SetCursor(2,0);
	sprintf((char*)Message,	"%02d:%02d:%02d %02d.%02d.%02d   ", timedata.hour,
																timedata.min,
																timedata.sec,
																timedata.date,
																timedata.month,
																timedata.year - 2000);
	ssd1306_WriteString((char*)Message, Font_7x10, White);
	//ssd1306_Line(2, 17, 24, 17, White);

	ssd1306_SetCursor(2, 12);
	sprintf((char*)Message,	"T= %.2fC      ", BME280_sensor.temperature);
	ssd1306_WriteString((char*)Message, Font_7x10, White);
	ssd1306_SetCursor(2, 24);

	sprintf((char*)Message,	"P= %.2fkPa      ", BME280_sensor.pressure/1000);
	ssd1306_WriteString((char*)Message, Font_7x10, White);
	ssd1306_SetCursor(2, 36);
	sprintf((char*)Message,	"K= %02d %02d %02d     ", button_get_clicks_count (&button), (GPIOA->IDR & 0x20)>>5, global_tick);
	ssd1306_WriteString((char*)Message, Font_7x10, White);
	ssd1306_SetCursor(2, 48);
	sprintf((char*)Message,	"E= %02d    ", Enc_Counter);
	ssd1306_WriteString((char*)Message, Font_7x10, White);

}

