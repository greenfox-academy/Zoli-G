#include "main.h"

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

void LEDInit();
void UARTInit();
void TimerPWMInit();

GPIO_InitTypeDef led;
TIM_HandleTypeDef TimHandle;
TIM_OC_InitTypeDef sConfig;
UART_HandleTypeDef uart_handle;

int main(void) {
	//Hardware config
	MPU_Config();
	CPU_CACHE_Enable();
	HAL_Init();
	SystemClock_Config();

	BSP_LED_Init(LED_GREEN);
	BSP_LED_On(LED_GREEN);

	LEDInit();
	TimerPWMInit();
	UARTInit();

	printf("\n-----------------WELCOME-----------------\r\n");
	printf("**********in STATIC timer & pwm WS**********\r\n\n");

	while (1) {
		//LED PWM
		for (int i = 0; i <= 100; ++i) {
			TIM2->CCR1 =  i;
			HAL_Delay(10);
		}
		for (int i = 100; i >= 0; --i) {
			TIM2->CCR1 =  i;
			HAL_Delay(10);
		}

	}
}

void LEDInit() {
	__HAL_RCC_GPIOA_CLK_ENABLE();

	led.Pin = GPIO_PIN_0;
	led.Mode = GPIO_MODE_AF_PP;
	//led.Pull = GPIO_PULLDOWN;
	led.Speed = GPIO_SPEED_HIGH;
	led.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &led);
}

void TimerPWMInit() {
	__HAL_RCC_TIM2_CLK_ENABLE();

	TimHandle.Instance               = TIM2;
	TimHandle.Init.Period            = 100; //Max = 100%
	TimHandle.Init.Prescaler         = 1; //Using full speed 216MHz
	TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;

	//HAL_TIM_Base_Init(&TimHandle);
	//HAL_TIM_Base_Start(&TimHandle);

	sConfig.OCMode = TIM_OCMODE_PWM1;
	//sConfig.Pulse	= 0;

	HAL_TIM_PWM_Init(&TimHandle);
	HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1);
}

void UARTInit() {
	uart_handle.Init.BaudRate   = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits   = UART_STOPBITS_1;
	uart_handle.Init.Parity     = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode       = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
}

PUTCHAR_PROTOTYPE {
	HAL_UART_Transmit(&uart_handle, (uint8_t *)&ch, 1, 0xFFFF);
	return ch;
}
