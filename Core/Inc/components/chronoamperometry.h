/**
  ******************************************************************************
  * @file		chronoamperometry.h
  * @brief		Archivo de encabezado del componente encargado de la gestión de
  *             la cronoamperometría.
  * @author		Albert Álvarez Carulla
  * @copyright	Copyright 2020 Albert Álvarez Carulla. All rights reserved.
  ******************************************************************************
  */

#ifndef INC_COMPONENTS_CHRONOAMPEROMETRY_H_
#define INC_COMPONENTS_CHRONOAMPEROMETRY_H_

#include "stm32f4xx_hal.h"

#ifndef TRUE
    #define TRUE				1
#endif

#ifndef FALSE
    #define FALSE				0
#endif


#define relayClosed GPIO_PIN_SET
#define relayOpened GPIO_PIN_RESET

struct CA_Configuration_S {

	double eDC;
	uint32_t samplingPeriodMs;
	uint32_t measurementTime;

};


//prototype
void ChronoAmperometry(void);

#endif /* INC_COMPONENTS_CHRONOAMPEROMETRY_H_ */
