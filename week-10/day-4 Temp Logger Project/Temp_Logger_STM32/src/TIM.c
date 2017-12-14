#include "main.h"
#include "I2C.h"

extern TIM_HandleTypeDef TimHandle;
extern RTC_HandleTypeDef RtcHandle;
extern I2C_HandleTypeDef I2cHandle;
extern uint8_t cmd;

void TimerITInit() {

	__HAL_RCC_TIM1_CLK_ENABLE();

	TimHandle.Instance               = TIM1;
	TimHandle.Init.Period            = 4000;
	TimHandle.Init.Prescaler         = 54000;
	TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&TimHandle);
	HAL_TIM_Base_Start_IT(&TimHandle);

	HAL_NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
}

void TIM1_UP_TIM10_IRQHandler() {
	HAL_TIM_IRQHandler(&TimHandle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	RTC_DateTypeDef dDate;
	RTC_TimeTypeDef dTime;

	HAL_RTC_GetTime(&RtcHandle, &dTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&RtcHandle, &dDate, RTC_FORMAT_BIN);

	//Print out date&time with leading zeros! Useful for string tokenization on PC side
	printf("%d.%02d.%02d %02d:%02d:%02d ",
	(dDate.Year + 2000), dDate.Month, dDate.Date, dTime.Hours, dTime.Minutes, dTime.Seconds);

	HAL_I2C_Master_Transmit_IT(&I2cHandle, I2C_ADDRESS << 1, (uint8_t*) &cmd, 1);
}
