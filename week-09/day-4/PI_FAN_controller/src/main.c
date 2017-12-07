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
void UARTInit();

//Global objects
GPIO_InitTypeDef PWMPinConfig;
GPIO_InitTypeDef RPMPinConfig;
GPIO_InitTypeDef ButtonUP;
GPIO_InitTypeDef ButtonDOWN;
TIM_HandleTypeDef Timer;
TIM_OC_InitTypeDef TimerOC;
UART_HandleTypeDef uart_handle;

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
	Timer.Init.Prescaler = 54000;
	Timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	Timer.Init.CounterMode = TIM_COUNTERMODE_UP;

	TimerOC.OCMode = TIM_OCMODE_PWM1;
	TimerOC.Pulse = 130; //Min:110

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
		TIM2->CCR1 >= 10 ? (TIM2->CCR1 -= 10) : (TIM2->CCR1 = 0);
		printf("Down! Status: %lu%\n", (unsigned)TIM2->CCR1 / 1000);
		//HAL_Delay(50);
	} else if (GPIO_Pin == GPIO_PIN_15) {
		TIM2->CCR1 <= 990 ? (TIM2->CCR1 += 10) : (TIM2->CCR1 = 1000);
		printf("Up! Status: %lu%\n", (unsigned)TIM2->CCR1 / 1000);
		//HAL_Delay(50);
	}
}

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
