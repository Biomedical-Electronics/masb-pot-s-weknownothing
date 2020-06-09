#include "components/stm32main.h"
#include "components/masb_comm_s.h"
#include "components/chronoamperometry.h"
#include "components/cyclic_voltammetry.h"

struct CV_Configuration_S cvConfiguration; // save cv config
struct CA_Configuration_S caConfiguration; //save ca config


// executed function before while loop (just once)

void setup(void){
	MASB_COMM_S_controlPMU();
	MASB_COMM_S_waitForMessage(); //waiting for message


}

//executed function in the while loop

void loop(void){

	struct Data_S data;

	if (MASB_COMM_S_dataReceived()){

		switch (MASB_COMM_S_command()){

		case START_CV_MEAS: // if a CV is wanted
			cvConfiguration = MASB_COMM_S_getCvConfiguration();//save CV configuration
			CyclicVoltammetry();
			break;

		case START_CA_MEAS:
			caConfiguration = MASB_COMM_S_getCaConfiguration(); //save CA configuration
			ChronoAmperometry();
			break;

		case STOP_MEAS:

			break;

		default:
			break;
		}
		MASB_COMM_S_waitForMessage();
	}else{

	}

}
/*
 * stm32main.c
 *
 *  Created on: 5 jun. 2020
 *      Author: omile
 */


