/*
 * encoder.h
 *
 *  Created on: 9 мар. 2024 г.
 *      Author: Dima
 */

#ifndef __ENCODER_H_
#define __ENCODER_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
typedef enum {
  BUTTON_YES        = 0x00U,
  BUTTON_NO         = 0x01U
} button_status_t;

typedef enum {
	BUTTON_PULL_UP    = 0x00U,
	BUTTON_PULL_DOWN  = 0x01U
} button_pulling_t;

typedef enum {
  BUTTON_NORM_OPEN  = 0x00U,
  BUTTON_NORM_CLOSE = 0x01U
} button_type_t;

typedef enum
{
	GPIO_LOW = 0U,
	GPIO_HIGH,
}
gpio_state_t;

typedef struct {
	button_type_t     _type;
	button_pulling_t  _pulling_mode;
	uint8_t           _state;
	uint8_t           _previous_state;
	uint16_t          _status;
	uint8_t           _clicks_counter;
	uint8_t           _debounce_timeout;
	uint16_t          _click_timeout;
	uint16_t          _hold_timeout;
	uint16_t          _step_timeout;
	uint16_t          _idle_timeout;
	uint32_t          _timer;
} button_t;

/* Exported constants and variables ------------------------------------------*/
extern GPIO_PinState test;

extern button_t  button;
extern uint8_t Enc_Counter;
extern __IO uint32_t global_tick;

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void encoder_init	(void);
void encoder_handle	(void);

void button_timer_tick (void);

void keyboard_handling (void);


#ifdef __cplusplus
}
#endif


#endif /* __ENCODER_H_ */
