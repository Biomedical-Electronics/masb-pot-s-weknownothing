/*
 * dac.h
 *
 *  Created on: 8 jun. 2020
 *      Author: omile
 */

#ifndef INC_COMPONENTS_DAC_H_
#define INC_COMPONENTS_DAC_H_

#define DAC_ADDR 0x60 //I2C addres is 1100000 in hexagecimal 0x60
#define DAC_BUFFER_SIZE	3
#define CONTROL_BYTE	0b01000000

// Prototypes
void SendVoltageToDAC(double Voltage);

#endif /* INC_COMPONENTS_DAC_H_ */
