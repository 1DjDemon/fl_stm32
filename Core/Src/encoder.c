/*
 * encoder.c
 *
 *  Created on: 9 мар. 2024 г.
 *      Author: Dima
 */

/* Includes ------------------------------------------------------------------*/
#include "encoder.h"
/* Private define ------------------------------------------------------------*/
#define DEBOUNCE_PROCESS      0x0001U
#define CLICK_PROCESS         0x0002U
#define MANY_CLICKS_PROCESS   0x0004U
#define HOLDING_PROCESS       0x0008U
#define PRESSED               0x0010U
#define RELEASED              0x0020U
#define CLICK                 0x0040U
#define MANY_CLICKS           0x0080U
#define CLICKS_COUNTER_RESET  0x0100U
#define HELD                  0x0200U
#define INCREMENTING_HOLD     0x0400U

/* Private macro -------------------------------------------------------------*/
#define get_state(state)     (button._status & state)
#define set_state(state)     (button._status |= state)
#define reset_state(state)   (button._status &= ~state)
#define timeout_passed(time) (global_tick - button._timer) >= button.time

/* Private includes ----------------------------------------------------------*/


/* Private typedef -----------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private constants and variables -------------------------------------------*/
HAL_TIM_StateTypeDef t;
__IO uint32_t global_tick;

button_t  button;
uint8_t Enc_Counter = 0;

/* Private function prototypes -----------------------------------------------*/
button_status_t button_has_clicks (button_t *_button);
button_status_t button_is_held (button_t *_button);
uint8_t button_get_clicks_count (button_t *_button);

/* Private user code ---------------------------------------------------------*/

button_status_t button_has_clicks (button_t *_button)
{
  button_status_t status = BUTTON_NO;

  if (get_state(MANY_CLICKS) != 0)
  {
    status = BUTTON_YES;
  }

  return status;
}

uint8_t button_get_clicks_count (button_t *_button)
{
//  reset_state(MANY_CLICKS);
//  set_state(CLICKS_COUNTER_RESET);
  return _button->_clicks_counter;
}

button_status_t button_is_held (button_t *_button)
{
  button_status_t status = BUTTON_NO;

  if (get_state(HELD) != 0)
  {
    reset_state(HELD);
    status = BUTTON_YES;
  }

  return status;
}

void encoder_init	(void)
{
	HAL_TIM_Encoder_MspInit(&htim3);
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
	osDelay(100);

	button._type             = BUTTON_NORM_OPEN;
	button._pulling_mode     = BUTTON_PULL_UP;

	button._debounce_timeout = 30;
	button._click_timeout    = 400;
	button._hold_timeout     = 500;
	button._step_timeout     = 350;
	button._idle_timeout     = 1000;
	button._timer            = global_tick;

	button._state            = 0;
	button._previous_state   = 0;

	button._status           = 0;

	button._clicks_counter   = 0;

}


void button_timer_tick (void)
{
	global_tick += 1U;
}

void encoder_handling (void)
{
	//Обработка энкодера
	Enc_Counter = (TIM3->CNT)/2;;
	//Обработка кнопки
	if ((GPIOA->IDR & 0x20) != (uint32_t)GPIO_PIN_RESET)
	{
		button._state = button._type ^ button._pulling_mode ^ 0x00U;
	}
	else
	{
		button._state = button._type ^ button._pulling_mode ^ 0x01U;
	}


	// Обработка нажатия
	if ((button._state) && !(button._previous_state))
	{
		if (get_state(DEBOUNCE_PROCESS) == 0U)
		{
		  set_state(DEBOUNCE_PROCESS);
		  button._timer = global_tick;
		}
		else
		{
		  if (timeout_passed(_debounce_timeout))
		  {
			button._previous_state = 0x01U;
			set_state(PRESSED);
			set_state(CLICK_PROCESS);
		  }
		}
	}
	else
	{
		reset_state(DEBOUNCE_PROCESS);
	}

	// Обработка отпускания
	  if (!(button._state) && (button._previous_state))
	  {
	    button._previous_state = 0x00U;

	    if (get_state(CLICK_PROCESS) != 0U)
	    {
	      set_state(CLICK);
	      reset_state(CLICK_PROCESS);
	      button._clicks_counter++;
	    }

	    set_state(RELEASED);
	    reset_state(PRESSED);
	    reset_state(HOLDING_PROCESS);

	    button._timer = global_tick;
	  }

	  // Удержание
	  if ((button._previous_state) && (button._state))
	  {
	    if (timeout_passed(_hold_timeout))
	    {
	      if (get_state(HOLDING_PROCESS) == 0U)
	      {
	        set_state(HOLDING_PROCESS);
	        set_state(HELD);
	        reset_state(CLICK_PROCESS);
	        button._timer = global_tick;
	      }
	    }
	  }

	  // Удержание "с инкрементацией" (для пошагового изменения величин)
	  if (get_state(HOLDING_PROCESS) != 0U)
	  {
	    if (timeout_passed(_step_timeout))
	    {
	      set_state(INCREMENTING_HOLD);
	      button._timer = global_tick;
	    }
	  }

	  // Многократное нажатие
	  if (timeout_passed(_click_timeout))
	  {
	    if ((button._clicks_counter > 0U) && (button._state == 0U))
	    {
	      set_state(MANY_CLICKS);
	    }
	  }

	  // Сброс многократного нажатия
	  if (get_state(CLICKS_COUNTER_RESET) != 0U)
	  {
	    reset_state(CLICKS_COUNTER_RESET);
	    reset_state(MANY_CLICKS);
	    button._clicks_counter = 0U;
	  }

	  // Сброс необработанных состояний
	  if (timeout_passed(_idle_timeout))
	  {
	    button._status = 0;
	    button._clicks_counter = 0U;
	  }

}

void keyboard_handling(void)
{
	if (button_has_clicks (&button) == BUTTON_YES)
	  {
	    switch (button_get_clicks_count (&button))
	    {
	      //case 1:   agregat_reset_alarm (); break;
	      case 5:   NVIC_SystemReset ();    break;
	      default:                          break;
	    }
	  }


}
