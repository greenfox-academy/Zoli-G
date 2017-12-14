#include "main.h"
#include "UART.h"
#include "RTC.h"
#include "TIM.h"
#include "I2C.h"

void Logo();

//Global variables
UART_HandleTypeDef UartHandle;
GPIO_InitTypeDef GPIO_I2C_SDA_SCL_Config;
I2C_HandleTypeDef I2cHandle;
RTC_HandleTypeDef RtcHandle;
TIM_HandleTypeDef TimHandle;

uint8_t cmd = 0;
uint8_t buf;

int main(void) {
	//Hardware config
	MPU_Config();
	CPU_CACHE_Enable();
	HAL_Init();
	SystemClock_Config();

	BSP_LED_Init(LED_GREEN);
	BSP_LED_On(LED_GREEN);

	//Start UART serial communication with printf support
	UART_Config();

	Logo();
	printf("STM32 - TC74 Temperature Logger Node Initializing...\n\n");

    RTC_Config();
	RTC_SetDateTime(
	            17,                         // 2017
	            12,                         // december
	            14,                         // 12th
	            RTC_WEEKDAY_THURSDAY,        // tuesday
	            11,                         // hour: 13
	            0,                         // minute: 11
	            0                           // second: 0
	);

	//Initializing I2C with GPIO pins
	GPIOInit();
	I2CInit();

	//Timer starts... (every 1s)
	TimerITInit();

	while (1) {
		//Nothing to see here...
		//Timer IT -> RTC & I2C Transmit IT -> Receive IT -> printf
	}
}

void Logo() {
	printf(
	 "  _____ _______ __  __ ____ ___             _______ _____ ______ _  _\n"
	 " / ____|__   __|  \\/  |___ \\__ \\           |__   __/ ____|____  | || |\n"
	 "| (___    | |  | \\  / | __) | ) |  ______     | | | |        / /| || |_\n"
	 " \\___ \\   | |  | |\\/| ||__ < / /  |______|    | | | |       / / |__   _|\n"
	 " ____) |  | |  | |  | |___) / /_              | | | |____  / /     | |\n"
	 "|_____/   |_|  |_|  |_|____/____|             |_|  \\_____|/_/      |_|\n"
	 "=======================================================================\n"
	);
}
