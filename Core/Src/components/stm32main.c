#include "components/stm32main.h"
#include "components/masb_comm_s.h"

struct CV_Configuration_S cvConfiguration; // save cv config
struct CA_Configuration_S caConfiguration; //save ca config
uint8_t State = 03;

uint8_t obtainState(uint8_t Estado){
	State= Estado;
			return State;
}

// executed function before while loop (just once)

void setup(void){
	MASB_COMM_S_waitForMessage(); //waiting fir message
}

//executed function in the while loop

void loop(void){

	struct Data_S data;

	if (MASB_COMM_S_dataReceived()){

		switch (MASB_COMM_S_command()){

		case START_CV_MEAS: // if a CV is wanted
			cvConfiguration = MASB_COMM_S_getCvConfiguration();//save CV configuration
			obtainState(CV);
			break;

		case START_CA_MEAS:
			caConfiguration = MASB_COMM_S_getCaConfiguration(); //save CA configuration
			obtainState(CA);
			break;

		case STOP_MEAS:
			obtainState(IDLE);
			break;

		default:
			break;
		}
		MASB_COMM_S_waitForMessage();
	}else{

		switch (obtainSate()){ //check state

		case CV:
			//obtain next point
			//send point to host
		//is point =last
			obtainState(IDLE);
			break;
		case CA:
			//obtain next point
			//send point to host
			//if point =last
			obtainState(IDLE);
			break;
		case IDLE:
			break;
		}
	}

}
/*
 * stm32main.c
 *
 *  Created on: 5 jun. 2020
 *      Author: omile
 */


