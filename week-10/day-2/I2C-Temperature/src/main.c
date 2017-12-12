#include "main.h"

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

#define I2C_ADDRESS 0x4D

void GPIOInit();
void I2CInit();
void UARTInit();

GPIO_InitTypeDef GPIO_I2C_SDA_SCL_Config;
I2C_HandleTypeDef I2cHandle;
UART_HandleTypeDef uart_handle;
uint8_t send[32];
uint8_t receive[32];

int main(void) {
	//Hardware config
	MPU_Config();
	CPU_CACHE_Enable();
	HAL_Init();
	SystemClock_Config();

	BSP_LED_Init(LED_GREEN);

	GPIOInit();
	I2CInit();

	uint8_t cmd;

	while (1) {
		HAL_I2C_Master_Transmit(&I2cHandle, I2C_ADDRESS, 0x0, 2, 0xFFFF);
		HAL_Delay(50);
		HAL_I2C_Master_Receive(&I2cHandle, I2C_ADDRESS, cmd, 2, 0xFFFF);
		HAL_Delay(50);

		printf("%d\n", cmd);
	}

}

void GPIOInit() {
	//D14 (B9) & D15 (B8)

	__HAL_RCC_GPIOB_CLK_ENABLE();

	GPIO_I2C_SDA_SCL_Config.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	GPIO_I2C_SDA_SCL_Config.Mode = GPIO_MODE_AF_OD; //Open-drain for I2C
	GPIO_I2C_SDA_SCL_Config.Pull = GPIO_PULLUP;
	GPIO_I2C_SDA_SCL_Config.Speed = GPIO_SPEED_FAST;
	GPIO_I2C_SDA_SCL_Config.Alternate = GPIO_AF4_I2C1;

	HAL_GPIO_Init(GPIOB, &GPIO_I2C_SDA_SCL_Config);
}

void I2CInit() {
	__HAL_RCC_I2C1_CLK_ENABLE();

	I2cHandle.Instance             = I2C1;
	I2cHandle.Init.Timing          = 0x40912732;
	I2cHandle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;

	HAL_I2C_Init(&I2cHandle);
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

