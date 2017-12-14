#include "main.h"
#include "I2C.h"

extern GPIO_InitTypeDef GPIO_I2C_SDA_SCL_Config;
extern I2C_HandleTypeDef I2cHandle;
extern uint8_t buf;

//GPIO Pin settings for I2C-------------------------------------
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
//I2C settings---------------------------------------------------
void I2CInit() {
	__HAL_RCC_I2C1_CLK_ENABLE();

	I2cHandle.Instance             = I2C1;
	I2cHandle.Init.Timing          = 0x40912732;
	I2cHandle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;

	HAL_I2C_Init(&I2cHandle);

	HAL_NVIC_SetPriority(I2C1_EV_IRQn, 0x01, 0x00);
	HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
}

void I2C1_EV_IRQHandler(I2C_HandleTypeDef *hi2c) {
	HAL_I2C_EV_IRQHandler(&I2cHandle);
}

void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c) {
	HAL_I2C_Master_Receive_IT(&I2cHandle, I2C_ADDRESS << 1, (uint8_t*) &buf, 1);
}

void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c) {
	//Print out temperature value in celsius and a newline char
	printf("%d\n", buf);
	BSP_LED_Toggle(LED_GREEN);
}
