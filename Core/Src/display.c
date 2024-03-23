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
#include "gps_neo6.h"
/* Private typedef -----------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private constants and variables -------------------------------------------*/
uint8_t Message[64];
uint8_t cursor;
page_properties_t page_properties;
uint8_t bufttttt[64];

/* Private function prototypes -----------------------------------------------*/

void display_menu_screen (void);
void display_setings_screen (void);
void display_seting_data_screen (void);
void display_seting_time_screen (void);
void display_seting_GPS_screen (void);
void display_seting_timezone_GPS_screen (void);
void display_seting_synch_GPS_screen (void);

/* Private user code ---------------------------------------------------------*/
void display_Init(void)
{
	ssd1306_Init();
	page_properties.page_list = page_start;
	page_properties.line = line_0;
	osDelay(1000);

}

void display_handle (void)
{
	switch (page_properties.page_list)
	{
	  case page_start			: display_start_screen(); 	break;
	  case page_menu			: display_menu_screen();		break;
	  case page_settings		: display_setings_screen();	break;
	  case page_setting_date	: display_seting_data_screen();	break;
	  case page_setting_time	: display_seting_time_screen();	break;
	  case page_setting_GPS		: display_seting_GPS_screen();	break;
	  default:              	display_start_screen(); 	break;
	}


	ssd1306_UpdateScreen();

}

void display_start_screen (void)
{
	ssd1306_Fill(Black);
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
	sprintf((char*)Message,	"K= %02d %02d %02d     ", GpsState.Hour, GpsState.Minute, GpsState.Second);
	ssd1306_WriteString((char*)Message, Font_7x10, White);
	ssd1306_SetCursor(2, 48);
	sprintf((char*)Message,	"E= %02d    ", bufttttt);
	ssd1306_WriteString((char*)bufttttt, Font_7x10, White);
	//page_list = page_start;

}

void display_menu_screen (void)
{
	ssd1306_Fill(Black);

	ssd1306_SetCursor(2, 0);
	sprintf((char*)Message,	"Menu");
	ssd1306_WriteString((char*)Message, Font_7x10, White);

//if(Enc_Counter%2 == 0)
	ssd1306_SetCursor(10, 24);
	sprintf((char*)Message,	"Setings");
	ssd1306_WriteString((char*)Message, Font_7x10, White);
//	ssd1306_SetCursor(10, 36);
//	sprintf((char*)Message,	"Test ");
//	ssd1306_WriteString((char*)Message, Font_7x10, White);
	 ssd1306_SetCursor(2, 24);
	 page_properties.line=line_0;

//	switch(Enc_Counter%2)
//	{
//		case 0: ssd1306_SetCursor(2, 24); page_properties.line=line_0; break;
//		case 1: ssd1306_SetCursor(2, 36); page_properties.line=line_1;break;
//
//		default: break;
//	}
	sprintf((char*)Message,	"*");
	ssd1306_WriteString((char*)Message, Font_7x10, White);


}


void display_setings_screen (void)
{
	ssd1306_Fill(Black);

	ssd1306_SetCursor(2, 0);
	sprintf((char*)Message,	"Setings");
	ssd1306_WriteString((char*)Message, Font_7x10, White);

//if(Enc_Counter%2 == 0)
	ssd1306_SetCursor(10, 14);
	sprintf((char*)Message,	"Date");
	ssd1306_WriteString((char*)Message, Font_7x10, White);
	ssd1306_SetCursor(10, 26);
	sprintf((char*)Message,	"Time");
	ssd1306_WriteString((char*)Message, Font_7x10, White);
	ssd1306_SetCursor(10, 38);
	sprintf((char*)Message,	"Seting GPS");
	ssd1306_WriteString((char*)Message, Font_7x10, White);

	switch(Enc_Counter%3)
	{
		case 0: ssd1306_SetCursor(2, 14); page_properties.line=line_0; break;
		case 1: ssd1306_SetCursor(2, 26); page_properties.line=line_1;break;
		case 2: ssd1306_SetCursor(2, 38); page_properties.line=line_2;break;

		default: break;
	}
	sprintf((char*)Message,	"*");
	ssd1306_WriteString((char*)Message, Font_7x10, White);

}

void display_seting_data_screen (void)
{
	ssd1306_Fill(Black);

	ssd1306_SetCursor(2, 0);
	sprintf((char*)Message,	"Seting Date");
	ssd1306_WriteString((char*)Message, Font_7x10, White);

	ssd1306_SetCursor(10, 26);
	sprintf((char*)Message,	"%02d.%02d.%04d", temptimedata.date, temptimedata.month, temptimedata.year);
	ssd1306_WriteString((char*)Message, Font_7x10, White);

	switch(page_properties.line)
	{
		case line_0: ssd1306_Line(10, 36, 24, 36, White); break;
		case line_1: ssd1306_Line(31, 36, 45, 36, White); break;
		case line_2: ssd1306_Line(52, 36, 80, 36, White); break;
		default: break;
	}


}
void display_seting_time_screen (void)
{
	ssd1306_Fill(Black);

	ssd1306_SetCursor(2, 0);
	sprintf((char*)Message,	"Seting Time");
	ssd1306_WriteString((char*)Message, Font_7x10, White);

	ssd1306_SetCursor(10, 26);
	sprintf((char*)Message,	"%02d:%02d:%02d", temptimedata.hour, temptimedata.min, temptimedata.sec);
	ssd1306_WriteString((char*)Message, Font_7x10, White);

	switch(page_properties.line)
	{
		case line_0: ssd1306_Line(10, 36, 24, 36, White); break;
		case line_1: ssd1306_Line(31, 36, 45, 36, White); break;
		case line_2: ssd1306_Line(52, 36, 66, 36, White); break;
		default: break;
	}

}
void display_seting_GPS_screen (void)
{
	ssd1306_Fill(Black);

	ssd1306_SetCursor(2, 0);
	sprintf((char*)Message,	"Seting GPS");
	ssd1306_WriteString((char*)Message, Font_7x10, White);
	ssd1306_SetCursor(10, 14);
	sprintf((char*)Message,	"Seting timezone");
	ssd1306_WriteString((char*)Message, Font_7x10, White);
	ssd1306_SetCursor(10, 26);
	sprintf((char*)Message,	"Synch GPS");
	ssd1306_WriteString((char*)Message, Font_7x10, White);

	switch(Enc_Counter%2)
	{
		case 0: ssd1306_SetCursor(2, 14); page_properties.line=line_0; break;
		case 1: ssd1306_SetCursor(2, 26); page_properties.line=line_1;break;

		default: break;
	}
	sprintf((char*)Message,	"*");
	ssd1306_WriteString((char*)Message, Font_7x10, White);


}


void display_seting_timezone_GPS_screen (void)
{
	ssd1306_Fill(Black);

	ssd1306_SetCursor(2, 0);
	sprintf((char*)Message,	"Seting Timezone");
	ssd1306_WriteString((char*)Message, Font_7x10, White);

	ssd1306_SetCursor(10, 26);
	sprintf((char*)Message,	"%02d", temptimedata.timezone);
	ssd1306_WriteString((char*)Message, Font_7x10, White);
	ssd1306_Line(10, 36, 24, 36, White);


}
void display_seting_synch_GPS_screen (void)
{

}




