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
#include "components/dac.h"

double Vcell;
double vObjetivo;
_Bool wait;

struct CV_Configuration_S cvConfiguration;
struct Data_S data;


void CyclicVoltammetry(void){
	for (double i =0; i < cvConfiguration.cycles; i++){
		SendVoltageToDAC(cvConfiguration.eBegin); //set Vcell as eBegin

		vObjetivo = cvConfiguration.eVertex1;

		HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, relayClosed); //closing relay
		wait = TRUE;
		SamplingPeriodTimerCV();
		while (wait){}; //while the period has not passed, wait

		data.point= i ;
		data.current = Obtain_Icell();
		data.voltage= Obtain_Vcell() ;

		MASB_COMM_S_sendData(data);

		if (Vcell == vObjetivo){
			if (vObjetivo == cvConfiguration.eVertex1){
				vObjetivo = cvConfiguration.eVertex2;
			}else{
				if (vObjetivo == cvConfiguration.eVertex2){
					vObjetivo = cvConfiguration.eBegin;
				}else{
					if (i==cvConfiguration.cycles){
						HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, relayOpened);
					}else{
						vObjetivo= cvConfiguration.eVertex1;
					}
				}
			}
		}else{
			if (Vcell + cvConfiguration.eStep > vObjetivo){
				//fix Vcell to vObjectivo
				Vcell = vObjetivo;
			}else{
				//apply increment or decrement of eStep to Vcell until equal to eVertex1
				if (Vcell > vObjetivo){
				Vcell -= cvConfiguration.eStep;
				}else{
					Vcell += cvConfiguration.eStep;
				}

			}
		}

	}
}


