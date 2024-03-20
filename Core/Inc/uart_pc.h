/**
  ******************************************************************************
  * @file           : uart_pc.h
  * @author         : Malahov
  * @version        : 0.1.0
  * @brief          : Заголовочный файл для uart_pc.c
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __UART_PC_H
#define __UART_PC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* Exported defines ----------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants and variables ------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void uart_pc_init 	(void);
void uart_pc_handle	(void);

#ifdef __cplusplus
}
#endif

#endif /* __UART_PC_H */

/************************ (C) COPYRIGHT malahov ****************END OF FILE****/
