/*
 * sensors.h
 *
 *  Created on: Mar 17, 2024
 *      Author: Dima
 */

#ifndef __SENSORS_H_
#define __SENSORS_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "BME280.h"
/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
typedef struct
{
	float temperature;
	float pressure;
	float humidity;

}BME280_sensor_t;

/* Exported constants and variables ------------------------------------------*/

extern BME280_sensor_t BME280_sensor;

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void sensors_Init(void);

void sensors_Handle(void);


#ifdef __cplusplus
}
#endif


#endif /* INC_SENSORS_H_ */
