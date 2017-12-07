#include "main.h"

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

//Function prototypes
void LEDInit();
void TimerPWMInit();
void TimerITInit();
void TIM2_IRQHandler();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void Button_IT_Init();
void EXTI15_10_IRQHandler();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void UARTInit();

//Global objects
GPIO_InitTypeDef PWMPinConfig;
GPIO_InitTypeDef Button;
TIM_HandleTypeDef Timer;
TIM_HandleTypeDef TimerIT;
TIM_OC_InitTypeDef TimerOC;
UART_HandleTypeDef uart_handle;

int main(void) {
	//Hardware config
	MPU_Config();
	CPU_CACHE_Enable();
	HAL_Init();
	SystemClock_Config();

	//Onboard LED on: HW working...
	BSP_LED_Init(LED_GREEN);
	BSP_LED_On(LED_GREEN);

	LEDInit();
	Button_IT_Init();
	TimerPWMInit();
	TimerITInit();
	UARTInit();

	while (1) {
		
	}

}

void LEDInit() {
	__HAL_RCC_GPIOA_CLK_ENABLE();

	PWMPinConfig.Pin = GPIO_PIN_8;
	PWMPinConfig.Mode = GPIO_MODE_AF_PP;
	PWMPinConfig.Pull = GPIO_NOPULL;
	PWMPinConfig.Speed = GPIO_SPEED_FAST;
	PWMPinConfig.Alternate = GPIO_AF1_TIM1;

	HAL_GPIO_Init(GPIOA, &PWMPinConfig);
}

void TimerPWMInit() {
	__HAL_RCC_TIM1_CLK_ENABLE();

	Timer.Instance = TIM1;
	Timer.Init.Period = 1000;
	Timer.Init.Prescaler = 1;
	Timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	Timer.Init.CounterMode = TIM_COUNTERMODE_UP;

	TimerOC.OCMode = TIM_OCMODE_PWM1;
	TimerOC.Pulse = 0;

	HAL_TIM_PWM_Init(&Timer);
	HAL_TIM_PWM_ConfigChannel(&Timer, &TimerOC, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&Timer, TIM_CHANNEL_1);
}

void TimerITInit() {
	__HAL_RCC_TIM2_CLK_ENABLE();

	TimerIT.Instance = TIM2;
	TimerIT.Init.Period = 40;
	TimerIT.Init.Prescaler = 54000;
	TimerIT.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimerIT.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&TimerIT);
	HAL_TIM_Base_Start_IT(&TimerIT);

	HAL_NVIC_SetPriority(TIM2_IRQn, 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&TimerIT);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    TIM1->CCR1 >= 1 ? (TIM1->CCR1 -= 1) : (TIM1->CCR1 = 0);
    if (TIM1->CCR1 % 10 == 0 && TIM1->CCR1 != 0)
    	printf("Timer interrupt -> LED fade (%lu).\n", TIM1->CCR1);
}

void Button_IT_Init() {
	//__HAL_RCC_GPIOA_CLK_ENABLE();

	Button.Pin = GPIO_PIN_15;
	Button.Mode = GPIO_MODE_IT_RISING;
	Button.Pull = GPIO_PULLUP;
	Button.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOA, &Button);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0x1F, 0x00);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	TIM1->CCR1 <= 990 ? (TIM1->CCR1 += 10) : (TIM1->CCR1 = 1000);
	printf("Button interrupt -> LED shine! (%lu)\n", TIM1->CCR1);
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
