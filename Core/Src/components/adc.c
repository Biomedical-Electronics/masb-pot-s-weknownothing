

#include "components/adc.h"
#include "main.h"

ADC_HandleTypeDef hadc1;

double Vcell = 0;
double Icell = 0;
double Vadc = 0;

double Cell_measures(void){
	//to read the cell voltage and current
	HAL_ADC_Start(&hadc1); // initialize conversion
	HAL_ADC_PollForConversion(&hadc1, 200); // wait until conversion

	Vadc = HAL_ADC_GetValue(&hadc1);
	return Vadc;
}

double Obtain_Icell(void){
	Vadc = Cell_measures();

	Icell= ((Vadc-1.65)*2)/R_TIA;
	return Icell;
}

double Obtain_Vcell(double Vadc){
	Vadc= Cell_measures();

	Vcell= (1.65-Vadc)*2;
	return Vcell;
}
