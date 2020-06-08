#include "components/dac.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c1;


uint8_t dacBuffer[DAC_BUFFER_SIZE]= {0}; //buffer to save the transmitted values



void SendVoltageToDAC(double Voltage){

	uint16_t DAC_Voltage= Voltage*4096/4; //conversion
	dacBuffer[0]= CONTROL_BYTE;
	dacBuffer[1]= DAC_Voltage >> 4; //11-4 shift right 4 places
	dacBuffer[2]= DAC_Voltage <<4; //3-0 shift left 4 places

	//Transmision of data
	HAL_I2C_Master_Transmit(&hi2c1, DAC_ADDR <<1, dacBuffer, DAC_BUFFER_SIZE, HAL_MAX_DELAY);
}


/*
 * dac.c
 *
 *  Created on: 8 jun. 2020
 *      Author: omile
 */


