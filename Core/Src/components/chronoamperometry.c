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
#include "components/dac.h"
#include "main.h"


_Bool wait;
double Vcell;
uint32_t currentMillis;  // actual ms
uint32_t measureMillis;  // ms that have passed


struct CA_Configuration_S caConfiguration;
struct Data_S data;

void ChronoAmperometry(void){
	currentMillis =HAL_GetTick();
	for (int i= 0;i < caConfiguration.measurementTime/caConfiguration.samplingPeriodMs;i++){
	SendVoltageToDAC(caConfiguration.eDC);

	HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, relayClosed); //close the relay
	wait = TRUE;
	SamplingPeriodTimerCA();

	while (wait){} //if the period has not passed, wait

	// measure Vcell through ADC
	measureMillis = HAL_GetTick();

	data.point=i;
	data.current=Obtain_Icell();
	data.voltage=Obtain_Vcell() ;
	data.timeMs= (measureMillis - currentMillis)*data.point;

	MASB_COMM_S_sendData(data);
	if (i== caConfiguration.measurementTime/caConfiguration.samplingPeriodMs){
		HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, relayOpened);
	}
	}
}

