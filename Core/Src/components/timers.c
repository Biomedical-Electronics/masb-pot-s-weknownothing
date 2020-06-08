
#include "main.h"
#include "components/timers.h"
#include "components/chronoamperometry.h"
#include "components/cyclic_voltammetry.h"

TIM_HandleTypeDef htim3;
struct CV_Configuration_S cvConfiguration; //save CV data
struct CA_Configuration_S caConfiguration; //save CA data

_Bool wait;

void SamplingPeriodTimerCA(void){
	//CA timer

	HAL_TIM_Base_DeInit(&htim3); //deinitialize timer

	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	htim3.Instance = TIM3;
	htim3.Init.Prescaler = 8399;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = caConfiguration.samplingPeriodMs*10; //period in Ms
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
	{
		Error_Handler();
		}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
	{
		Error_Handler();
	  }
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
}
	HAL_TIM_Base_Init(&htim3); //initialize timer

	HAL_TIM_Base_Start_IT(&htim3); //start timer

}

void SamplingPeriodTimerCV(void){
	//CA timer

	HAL_TIM_Base_DeInit(&htim3); //deinitialize timer

	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	htim3.Instance = TIM3;
	htim3.Init.Prescaler = 8399;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = cvConfiguration.eStep/cvConfiguration.scanRate; //period in s
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
	{
		Error_Handler();
		}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
	{
		Error_Handler();
	  }
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
}
	HAL_TIM_Base_Init(&htim3); //initialize timer

	HAL_TIM_Base_Start_IT(&htim3); //start timer

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

	wait = FALSE;

}
