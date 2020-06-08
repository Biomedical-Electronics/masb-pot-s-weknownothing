/**
  ******************************************************************************
  * @file		cyclic_voltammetry.c
  * @brief		Gestión de la voltammetría cíclica.
  * @author		Albert Álvarez Carulla
  * @copyright	Copyright 2020 Albert Álvarez Carulla. All rights reserved.
  ******************************************************************************
  */

#include "components/cyclic_voltammetry.h"
#include "components/timers.h"
#include "components/masb_comm_s.h"
#include "components/adc.h"

relayClosed = GPIO_PIN_SET;
relayOpened = GPIO_PIN_RESET;

struct CV_Configuration_S cvConfiguration;

void CyclicVoltammetry(void){
	for (uint8_t i =0; i < cvConfigutation.cycles; i++){
		Vcell = eBegin; //set Vcell as eBegin
		vObjetivo = eVertex1;
		HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, relayClosed); //closing relay
		wait = TRUE;
		SamplingPeriodTimerCV();
		while (wait){}; //while the period has not passed, wait
		Vcell = Cell_Measures(); //adc function to measure Vcell
		MASB_COMM_S_sendData();
		if (Vcell == vObjetivo){
			if (vObjetivo == eVertex1){
				vObjetivo = eVertex2;
			}else{
				if (vObjetivo == eVertex2){
					vObjetivo = eBegin;
				}else{
					if (i==cvConfiguration.cycles){
						HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, relayOpened);
					}else{
						vObjetivo=eVertex1;
					}
				}
			}
		}else{
			if (Vcell + eStep > Vobjetivo){
				//fix Vcell to vObjectivo
				Vcell = vObjetivo;
			}else{
				//apply increment or decrement of eStep to Vcell until equal to eVertex1
				if (Vcell > Vobjetivo){
				Vcell -= eStep;
				}else{
					Vcell += eStep;
				}

			}
		}

	}
}


