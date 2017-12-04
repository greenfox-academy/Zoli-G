#include "main.h"

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

void LEDInit();
void UARTInit();
void TimerInit();

GPIO_InitTypeDef led;
TIM_HandleTypeDef TimHandle;
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
	TimerInit();
	UARTInit();

	printf("\n-----------------WELCOME-----------------\r\n");
	printf("**********in STATIC timer & pwm WS**********\r\n\n");

	while (1) {
		//Flashing the LED at 1Hz. (0-500ms on, 501-1000ms off)
		//...without delay!
		if (TIM1->CNT <= 2000) { // == __HAL_TIM_GET_COUNTER(&TimHandle);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
		}
	}
}

void LEDInit() {
	__HAL_RCC_GPIOA_CLK_ENABLE();

	led.Pin = GPIO_PIN_0;
	led.Mode = GPIO_MODE_OUTPUT_PP;
	led.Pull = GPIO_PULLDOWN;
	led.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOA, &led);
}

void TimerInit() {
	__HAL_RCC_TIM1_CLK_ENABLE();

	TimHandle.Instance               = TIM1;
	TimHandle.Init.Period            = 4000; //Counting to 4000, so at 4 kHz timer freq the reqister will overflow in 1 sec.
	TimHandle.Init.Prescaler         = 54000; //Now clock speed is 216.000.000 Hz / 54.000 = 4000 Hz(Max value is 65535)
	TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&TimHandle);

	HAL_TIM_Base_Start(&TimHandle);
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
