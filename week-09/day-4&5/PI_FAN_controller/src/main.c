#include "main.h"

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

//Function prototypes
void FanPinPWMInit();
void FanTimerPWMInit();

void ButtonsPinITInit();
void EXTI15_10_IRQHandler();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

void FanPinRPMInit();
void FanTimerRPMInit();
void TIM1_CC_IRQHandler();
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);

void UARTInit();

//Global objects
GPIO_InitTypeDef PWMPinConfig;
GPIO_InitTypeDef RPMPinConfig;
GPIO_InitTypeDef ButtonUP;
GPIO_InitTypeDef ButtonDOWN;
TIM_HandleTypeDef Timer;
TIM_OC_InitTypeDef TimerOC;
TIM_HandleTypeDef TimerRPM;
TIM_IC_InitTypeDef TimerRPMIC;
UART_HandleTypeDef uart_handle;

volatile uint32_t dataBefore = 0;
volatile uint32_t dataAfter = 0;
volatile uint32_t diff;
volatile uint32_t RPM;

int main(void) {
	//Hardware config
	MPU_Config();
	CPU_CACHE_Enable();
	HAL_Init();
	SystemClock_Config();

	BSP_LED_Init(LED_GREEN);
	BSP_LED_On(LED_GREEN);

	FanPinPWMInit();
	FanTimerPWMInit();

	ButtonsPinITInit();

	FanPinRPMInit();
	FanTimerRPMInit();

	UARTInit();

	while (1) {

	}

}

void FanPinPWMInit() { //D9 (A15) (TIM2_CH1 AF1)
	__HAL_RCC_GPIOA_CLK_ENABLE();

	PWMPinConfig.Pin = GPIO_PIN_15;
	PWMPinConfig.Mode = GPIO_MODE_AF_PP;
	PWMPinConfig.Pull = GPIO_NOPULL;
	PWMPinConfig.Speed = GPIO_SPEED_FAST;
	PWMPinConfig.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &PWMPinConfig);
}

void FanTimerPWMInit() {
	__HAL_RCC_TIM2_CLK_ENABLE();

	Timer.Instance = TIM2;
	Timer.Init.Period = 1000;
	Timer.Init.Prescaler = 20000; //Almost the highest frequency the fan working
	Timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	Timer.Init.CounterMode = TIM_COUNTERMODE_UP;

	TimerOC.OCMode = TIM_OCMODE_PWM1;
	TimerOC.Pulse = 500; //Min:150

	HAL_TIM_PWM_Init(&Timer);
	HAL_TIM_PWM_ConfigChannel(&Timer, &TimerOC, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&Timer, TIM_CHANNEL_1);
}

//--------------------------------------------
void ButtonsPinITInit() {
	__HAL_RCC_GPIOB_CLK_ENABLE();
	//D12 (B14)
	ButtonDOWN.Pin = GPIO_PIN_14;
	ButtonDOWN.Mode = GPIO_MODE_IT_RISING;
	ButtonDOWN.Pull = GPIO_PULLUP;
	ButtonDOWN.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOB, &ButtonDOWN);

	//HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0x1F, 0x00);
	//HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

	//D11 (B15)
	ButtonUP.Pin = GPIO_PIN_15;
	ButtonUP.Mode = GPIO_MODE_IT_RISING;
	ButtonUP.Pull = GPIO_PULLUP;
	ButtonUP.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOB, &ButtonUP);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0x1F, 0x00);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == GPIO_PIN_14) {
		if (TIM2->CCR1 >= 160) {
			TIM2->CCR1 -= 10;
			printf("Slowing down, value: %lu%%\n", (TIM2->CCR1 / 10));
		} else {
			TIM2->CCR1 = 150;
			printf("Fan at minimum speed: 15%.\n");
		}
	}

	if (GPIO_Pin == GPIO_PIN_15) {
		if (TIM2->CCR1 <= 990) {
			TIM2->CCR1 += 10;
			printf("Speeding up, value: %lu%%\n", (TIM2->CCR1 / 10));
		} else {
			TIM2->CCR1 = 1000;
			printf("Fan at maximum speed!\n");
		}
	}
}
//SPEED Measuring
//-----------------------------------------------------
void FanPinRPMInit() { //D10 (A8) (TIM1_CH1 AF1)
	//__HAL_RCC_GPIOA_CLK_ENABLE();

	RPMPinConfig.Pin = GPIO_PIN_8;
	RPMPinConfig.Mode = GPIO_MODE_AF_OD;
	RPMPinConfig.Pull = GPIO_PULLUP; //This is a must to work IC
	RPMPinConfig.Speed = GPIO_SPEED_FAST;
	RPMPinConfig.Alternate = GPIO_AF1_TIM1;

	HAL_GPIO_Init(GPIOA, &RPMPinConfig);
}

void FanTimerRPMInit() { //D10 (A8) TIM1_CH1
	__HAL_RCC_TIM1_CLK_ENABLE();

	TimerRPM.Instance = TIM1;
	TimerRPM.Init.Period = 65535;
	TimerRPM.Init.Prescaler = 9999;
	TimerRPM.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimerRPM.Init.CounterMode = TIM_COUNTERMODE_UP;

	TimerRPMIC.ICPolarity = TIM_ICPOLARITY_RISING;
	TimerRPMIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
	TimerRPMIC.ICPrescaler = TIM_ICPSC_DIV2; //Capture every 2nd rising signal
	TimerRPMIC.ICFilter = 0x0;

	HAL_TIM_IC_Init(&TimerRPM);
	HAL_TIM_IC_ConfigChannel(&TimerRPM, &TimerRPMIC, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&TimerRPM, TIM_CHANNEL_1);

	HAL_NVIC_SetPriority(TIM1_CC_IRQn, 0x1F, 0x00);
	HAL_NVIC_EnableIRQ(TIM1_CC_IRQn);
}

void TIM1_CC_IRQHandler() {
	HAL_TIM_IRQHandler(&TimerRPM);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {

	if (dataBefore == 0) {
		dataBefore = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); //TIM1->CCR1;
	} else {
		dataAfter = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); //TIM1->CCR1;

		if (dataAfter == dataBefore) {
			dataBefore = 0;
			dataAfter = 0;
			return;
		}

		dataAfter > dataBefore ? (diff = dataAfter - dataBefore) : (diff = htim->Init.Period + dataAfter - dataBefore);

		RPM = (216000000/htim->Init.Prescaler) / diff * 60;
		printf("RPM: %lu, (dAfter: %lu, dBefore: %lu) diff = %lu CNT: %lu\n", RPM, dataAfter, dataBefore, diff, TIM2->CNT);

		dataBefore = 0;
		dataAfter = 0;
	}
}
//-----------------------------------------------------
void UARTInit() {
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
}

PUTCHAR_PROTOTYPE {
	HAL_UART_Transmit(&uart_handle, (uint8_t *) &ch, 1, 0xFFFF);
	return ch;
}
