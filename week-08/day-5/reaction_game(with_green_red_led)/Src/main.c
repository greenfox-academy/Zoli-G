 /**
  ******************************************************************************
  * @file    Templates/Src/main.c 
  * @author  MCD Application Team
  * @version V1.0.3
  * @date    22-April-2016 
  * @brief   STM32F7xx HAL API Template project 
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <string.h>


/** @addtogroup STM32F7xx_HAL_Examples
  * @{
  */

/** @addtogroup Templates
  * @{
  */ 
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef uart_handle;

/* Private function prototypes -----------------------------------------------*/

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

/* Private functions ---------------------------------------------------------*/

void WelcomeScreen() {
	printf("\n--------------REACTION GAME------------------\n");
	printf("***********STATIC class reaction game**********\n\n");
}
void InitLEDs() {
	__HAL_RCC_GPIOI_CLK_ENABLE();    //enable GPIO I port's clock

	GPIO_InitTypeDef RedGreenLEDs;   			// create a config structure
	RedGreenLEDs.Pin = GPIO_PIN_0 | GPIO_PIN_3; // this is about PIN 0
	RedGreenLEDs.Mode = GPIO_MODE_OUTPUT_PP;  	// Configure as output with push-up-down enabled
	RedGreenLEDs.Pull = GPIO_PULLDOWN;        	// the push-up-down should work as pulldown
	RedGreenLEDs.Speed = GPIO_SPEED_HIGH;     	// we need a high-speed output

	HAL_GPIO_Init(GPIOI, &RedGreenLEDs);
}
/* Private functions ---------------------------------------------------------*/
int main(void) {
  //HW init...
  MPU_Config();
  CPU_CACHE_Enable();
  HAL_Init();
  SystemClock_Config();

  //Software codes
  BSP_LED_Init(LED_GREEN);
  BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

  uart_handle.Init.BaudRate   = 115200;
  uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
  uart_handle.Init.StopBits   = UART_STOPBITS_1;
  uart_handle.Init.Parity     = UART_PARITY_NONE;
  uart_handle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
  uart_handle.Init.Mode       = UART_MODE_TX_RX;

  BSP_COM_Init(COM1, &uart_handle);

  //Button
  unsigned int buttonPressed = 0;

  //Measure delay until buttonpress
  unsigned int delay = 0;

  //Random number generator initialization before while cycle
  RNG_HandleTypeDef rand;
  rand.Instance = RNG;
  HAL_RNG_Init(&rand);
  uint32_t rand_time = HAL_RNG_GetRandomNumber(&rand);

  //Reaction time start and end stamp variables
  uint32_t tickstart = 0;
  uint32_t tickend = 0;
  uint32_t reaction_time = 0;

  uint8_t game_counter = 0;
  uint32_t sum_of_reaction_times = 0;
  uint8_t game_lost = 0;

  //Print welcome message
  WelcomeScreen();

  InitLEDs();

  while (1) {
	  //Increase game counter for average reaction time calculation
	  ++game_counter;

	  //Promt for game start
	  printf("Prepare! When you're ready press the button!\n");

	  //Turn LED on. If onboard button is pressed, than turn LED off and exit while.
	  //LED is flashing 1Hz, the 1000ms delay is divided to 10ms pieces to listen to keypress.
	  //Turn the LED on...
	  BSP_LED_On(LED_GREEN);
	  //Wait while the button is not pressed and not released (LED off). Inbetween flashing the LED 1Hz.
	  delay = 0;
	  while (1) {
		  HAL_Delay(5);
		  delay += 5;
		  if (BSP_PB_GetState(BUTTON_KEY) == SET) {buttonPressed = 1;}
		  if (BSP_PB_GetState(BUTTON_KEY) == RESET && buttonPressed == 1) {buttonPressed = 0; BSP_LED_Off(LED_GREEN); break;}
		  if (delay == 500) {delay = 0; BSP_LED_Toggle(LED_GREEN);}
	  }

	  //Game starting...
	  printf("\nGame started! Wait for the LED to turn on!\n");

	  //Make a random number between 1 and 10000
	  rand_time = rand_time % 10000 + 1;

	  //Print out this cheat!
	  printf("(Hint: will wait %lu ms.)\n", rand_time);

	  //Reset delay counter
	  delay = 0;
	  //Wait 1sec + random time wait starts to prevent immediate signaling by very slow random times
	  while (delay < rand_time + 1000) {
		  HAL_Delay(5); //Delay is 5ms blocks
		  delay += 5; //Increase delay counter to measure past time
		  if (BSP_PB_GetState(BUTTON_KEY) == SET) { //If there is a button pressed before the random time
			  HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET); //turn on red led
			  printf("You lost the game! (Pressed too early!) 1s penalty time added!\n"); //write sad information to serial
			  sum_of_reaction_times += 1000; //add penalty time to the sum variable
			  game_lost = 1; //set lost game flag
			  break; //exit while loop immediately
		  }
	  }
	  if (game_lost == 1) { //Enter this if block only if the while loop above ended with "game lost" flag
		  game_lost = 0; //reset lost game flag
		  HAL_Delay(2000); //wait 2sec
		  while (BSP_PB_GetState(BUTTON_KEY) == SET) {} //wait until key is not pressed
		  HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_RESET); //turn off red led
		  continue; //start new while loop
	  }

	  //Signal! (there was no buttonpress before time)
	  BSP_LED_On(LED_GREEN);

	  //Make a "timestamp":
	  tickstart = HAL_GetTick();
	  while (BSP_PB_GetState(BUTTON_KEY) != SET) {}	//While button is not pressed do nothing
	  HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET); //Turn on green led
	  tickend = HAL_GetTick();										//Get a timestamp at buttonpress
	  reaction_time = tickend - tickstart;							//Calculate time between gamestart and buttonpress
	  printf("Your reaction time was: %lu ms!\n", reaction_time);	//Print out result
	  sum_of_reaction_times += reaction_time;						//add this game rusult to the current sum
	  printf("Your average reaction time based on %u games is %lu ms.\n", game_counter, sum_of_reaction_times / game_counter);
	  printf("Next game will start in 2 seconds!\n\n\n\n");
	  HAL_Delay(2000);												//Wait 2s between games
	  HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);			//Turn off green led
	  while (BSP_PB_GetState(BUTTON_KEY) == SET) {}					//Do not allow to start a game with pressed button
  }
}
/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
  HAL_UART_Transmit(&uart_handle, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 216000000
  *            HCLK(Hz)                       = 216000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 432
  *            PLL_P                          = 2
  *            PLL_Q                          = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 432;  
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /* activate the OverDrive to reach the 216 Mhz Frequency */
  if(HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  while(1) {
  }
}

static void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;
  
  /* Disable the MPU */
  HAL_MPU_Disable();

  /* Configure the MPU attributes as WT for SRAM */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0x20010000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
