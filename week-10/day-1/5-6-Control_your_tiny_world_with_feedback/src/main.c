#include "main.h"
#include "string.h"

void UARTSettings(UART_HandleTypeDef);
void UARTPinSettings(UART_HandleTypeDef);
void ReadFromPC();

UART_HandleTypeDef UartHandle;
char buffer[32];
uint8_t buffer_place_to_write = 0;
char command[32];

int main(void) {
	//Hardware config
	MPU_Config();
	CPU_CACHE_Enable();
	HAL_Init();
	SystemClock_Config();

	BSP_LED_Init(LED_GREEN);
	BSP_LED_On(LED_GREEN);

	UARTPinSettings(UartHandle);
	UARTSettings(UartHandle);

	while (1) {
		ReadFromPC();
	}

}
void UARTSettings(UART_HandleTypeDef huart) {
	UartHandle.Instance         = USART1;
	UartHandle.Init.BaudRate    = 115200;
	UartHandle.Init.WordLength  = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits    = UART_STOPBITS_1;
	UartHandle.Init.Parity      = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl   = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode        = UART_MODE_TX_RX;

	HAL_UART_Init(&UartHandle);
}

void UARTPinSettings(UART_HandleTypeDef huart) {
	GPIO_InitTypeDef gpio_init_structure;

	  /* Enable GPIO clock */
	  __HAL_RCC_GPIOA_CLK_ENABLE(); //DISCOVERY_COMx_TX_GPIO_CLK_ENABLE(COM);
	  __HAL_RCC_GPIOB_CLK_ENABLE(); //DISCOVERY_COMx_RX_GPIO_CLK_ENABLE(COM);

	  /* Enable USART clock */
	  __HAL_RCC_USART1_CLK_ENABLE(); //DISCOVERY_COMx_CLK_ENABLE(COM);

	  /* Configure USART Tx as alternate function */
	  gpio_init_structure.Pin = GPIO_PIN_9; //DISCOVERY_COM1_TX_PIN;
	  gpio_init_structure.Mode = GPIO_MODE_AF_PP;
	  gpio_init_structure.Speed = GPIO_SPEED_FAST;
	  gpio_init_structure.Pull = GPIO_PULLUP;
	  gpio_init_structure.Alternate = GPIO_AF7_USART1; //DISCOVERY_COM1_TX_AF;
	  HAL_GPIO_Init(GPIOA, &gpio_init_structure);

	  /* Configure USART Rx as alternate function */
	  gpio_init_structure.Pin = GPIO_PIN_7; //DISCOVERY_COM1_RX_PIN;
	  gpio_init_structure.Mode = GPIO_MODE_AF_PP;
	  gpio_init_structure.Alternate = GPIO_AF7_USART1; //DISCOVERY_COM1_RX_AF;
	  HAL_GPIO_Init(GPIOB, &gpio_init_structure);
}

void ReadFromPC() {
	//Let receive a byte and put it into the buffer array
	HAL_UART_Receive(&UartHandle, (uint8_t*) &buffer[buffer_place_to_write], 1, 0xFFFF);
	//Increase buffer counter
	++buffer_place_to_write;

	//Check if there is already an enter char inputted (means command finished)
	if (buffer[buffer_place_to_write - 1] == '\n') {
		buffer[buffer_place_to_write - 1] = '\0';		//Change enter char to string termination char
		command[0] = '\0';								//Clear command string just in case
		strcpy(command, buffer);						//Copy buffer content to command
		buffer_place_to_write = 0;						//Virtually clear the buffer by resetting it's counter

		if (strcmp(command, "on") == 0) {				//If the command is "on", then...
			BSP_LED_On(LED_GREEN);						//...turn on the onboard LED.
			HAL_UART_Transmit(&UartHandle, (uint8_t*) "Turning the LED on!\n", 21, 0xFFFF);
		} else if (strcmp(command, "off") == 0) {		//If it's "off", then...
			BSP_LED_Off(LED_GREEN);						//...turn it off.
			HAL_UART_Transmit(&UartHandle, (uint8_t*) "Turning the LED off!\n", 22, 0xFFFF);
		} else {										//If it's neither, than...
			BSP_LED_Toggle(LED_GREEN);					//...flash 3 times.
			HAL_Delay(100);
			BSP_LED_Toggle(LED_GREEN);
			HAL_Delay(100);
			BSP_LED_Toggle(LED_GREEN);
			HAL_Delay(100);
			BSP_LED_Toggle(LED_GREEN);
			HAL_UART_Transmit(&UartHandle, (uint8_t*) "Unknown command!\n", 18, 0xFFFF);
		}
	}
}
