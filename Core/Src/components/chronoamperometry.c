/**
  ******************************************************************************
  * @file		chronoamperometry.c
  * @brief		Gestión de la cronoamperometría.
  * @author		Albert Álvarez Carulla
  * @copyright	Copyright 2020 Albert Álvarez Carulla. All rights reserved.
  ******************************************************************************
  */

#include "components/chronoamperometry.h"
#include "components/timers.h"
#include "components/masb_comm_s.h"
#include "components/adc.h"

relayClosed= GPIO_PIN_SET;
relayOpened= GPIO_PIN_RESET;

struct CA_Configuration_S caConfiguration;

void ChronoAmperometry(void){

	Vcell= caConfiguration.eDC;
	wait = TRUE;
	SamplingPeriodTimerCA();
	while (wait){} //if the period has not passed, wait

	Vcell= Cell_Measures(); // measure Vcell through ADC
	MASB_COMM_S_sendData();
	//While (measurementTime){}
		HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin,relayOpened);

}
