#include "main.h"

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

void LEDInit();
void NumberToLED(uint16_t, uint16_t);
void UARTInit();

UART_HandleTypeDef uart_handle;

int main(void) {
	//Hardware config
	MPU_Config();
	CPU_CACHE_Enable();
	HAL_Init();
	SystemClock_Config();

	BSP_LED_Init(LED_GREEN);
	BSP_LED_On(LED_GREEN);

	UARTInit();
	LEDInit();

	uint16_t delay = 150;
	printf("10bit binary counter\n");

	while (1) {
		for (uint16_t i = 0; i <= 1023; ++i) {
			printf("%d\n", i);
			NumberToLED(i, delay);
		}
	}
}

void LEDInit() {
	//Digits ON PINS: (highest) D0-D1-D11-D12-D14-D15-D9-D10-A0 (lowest)
	//----------A port---------- A0, D10, D9
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef LEDA;
	LEDA.Pin = GPIO_PIN_0 | GPIO_PIN_8 | GPIO_PIN_15;
	LEDA.Mode = GPIO_MODE_OUTPUT_PP;
	LEDA.Pull = GPIO_PULLDOWN;
	LEDA.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOA, &LEDA);
	//----------B port---------- D15, D14, D12, D11
	__HAL_RCC_GPIOB_CLK_ENABLE();

	GPIO_InitTypeDef LEDB;
	LEDB.Pin = GPIO_PIN_4 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_14 | GPIO_PIN_15;
	LEDB.Mode = GPIO_MODE_OUTPUT_PP;
	LEDB.Pull = GPIO_PULLDOWN;
	LEDB.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOB, &LEDB);
	//----------C port---------- D1, D0
	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitTypeDef LEDC;
	LEDC.Pin = GPIO_PIN_6 | GPIO_PIN_7;
	LEDC.Mode = GPIO_MODE_OUTPUT_PP;
	LEDC.Pull = GPIO_PULLDOWN;
	LEDC.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOC, &LEDC);
}

void NumberToLED(uint16_t number, uint16_t delay) {
	//0: A0, 1: A8, 2: A15
	uint16_t push_to_A = (number & 0b1) << 0 | (number & 0b10) << 7 | (number & 0b100) << 13;
	GPIOA->ODR |= push_to_A;

	//3: B4, 4-5: B8-B9, 6-7: B14-B15
	uint16_t push_to_B = (number & 0b1000) << 1 | (number & 0b110000) << 4 | (number & 0b11000000) << 8;
	GPIOB->ODR |= push_to_B;

	//8-9: C6-C7
	uint16_t push_to_C = (number & 0b1100000000) >> 2;
	GPIOC->ODR |= push_to_C;

	HAL_Delay(delay);

	GPIOA->ODR &= ~push_to_A;
	GPIOB->ODR &= ~push_to_B;
	GPIOC->ODR &= ~push_to_C;
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
