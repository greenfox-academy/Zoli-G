#include "stm32f7xx_hal.h"

void HAL_MspInit(void)
{
}

void HAL_MspDeInit(void)
{
}

void HAL_RTC_MspInit(RTC_HandleTypeDef* hrtc) {
    RCC_OscInitTypeDef RtcOscInit;

    RtcOscInit.OscillatorType = RCC_OSCILLATORTYPE_LSI;
    RtcOscInit.PLL.PLLState = RCC_PLL_NONE;
    RtcOscInit.LSIState = RCC_LSI_ON;
    RtcOscInit.LSEState = RCC_LSE_OFF;
    if (HAL_RCC_OscConfig(&RtcOscInit) != HAL_OK) {
        printf("Error while configuring LSI\r\n");
    }

    RCC_PeriphCLKInitTypeDef RtcPeriphClkInit;
    RtcPeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    RtcPeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
    if (HAL_RCCEx_PeriphCLKConfig(&RtcPeriphClkInit) != HAL_OK) {
        printf("Error while configuring RTC source to LSI\r\n");
    }
    __HAL_RCC_RTC_ENABLE();
}
