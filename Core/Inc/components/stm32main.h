/*
 * stm32main.h
 *
 *  Created on: 5 jun. 2020
 *      Author: omile
 */

#ifndef INC_COMPONENTS_STM32MAIN_H_
#define INC_COMPONENTS_STM32MAIN_H_

#include "stm32f4xx_hal.h"
#include "cobs.h"

#define CV 01
#define CA 02
#define IDLE 03


//function prototypes
void setup(void);
void loop(void);
void obtainState (uint8_t Estado);

#endif /* INC_COMPONENTS_STM32MAIN_H_ */
