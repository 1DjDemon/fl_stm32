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

/* Exported constants and variables ------------------------------------------*/
extern uint8_t Message[64];
/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void display_Init(void);
void display_handle (void);

void display_start_screen (void);

#ifdef __cplusplus
}
#endif

#endif /* INC_DISPLAY_H_ */
