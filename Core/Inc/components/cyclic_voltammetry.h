/**
  ******************************************************************************
  * @file		cyclic_voltammetry.h
  * @brief		Archivo de encabezado del componente encargado de la gestión de
  *             la voltammetría cíclica.
  * @author		Albert Álvarez Carulla
  * @copyright	Copyright 2020 Albert Álvarez Carulla. All rights reserved.
  ******************************************************************************
  */

#ifndef INC_COMPONENTS_CYCLIC_VOLTAMMETRY_H_
#define INC_COMPONENTS_CYCLIC_VOLTAMMETRY_H_

#include "stm32f4xx_hal.h"

#ifndef TRUE
    #define TRUE				1
#endif

#ifndef FALSE
    #define FALSE				0
#endif

#define RELAY_Pin GPIO_PIN_5
#define RELAY_GPIO_Port GPIOB

struct CV_Configuration_S {

	double eBegin;
	double eVertex1;
	double eVertex2;
	uint8_t cycles;
	double scanRate;
	double eStep;

};

//Prototypes
void CyclicVoltammetry(void);
void CV_Measures(void);


#endif /* INC_COMPONENTS_CYCLIC_VOLTAMMETRY_H_ */
