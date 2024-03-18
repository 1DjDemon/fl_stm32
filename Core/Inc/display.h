/*
 * display.h
 *
 *  Created on: 9 мар. 2024 г.
 *      Author: Dima
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "rtc.h"

/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
typedef enum
{
	page_start = 0,
	page_menu,
	page_settings

}page_list_t;

typedef enum
{
	line_0 = 0,
	line_1,
	line_2

}line_num_t;

typedef struct
{
	page_list_t page_list;
	line_num_t	line;

}page_properties_t;

/* Exported constants and variables ------------------------------------------*/
extern uint8_t Message[64];
extern page_properties_t page_properties;
/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void display_Init(void);
void display_handle (void);

void display_start_screen (void);

#ifdef __cplusplus
}
#endif

#endif /* INC_DISPLAY_H_ */
