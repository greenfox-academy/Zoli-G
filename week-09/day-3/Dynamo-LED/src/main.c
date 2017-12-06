#include "main.h"

//Function prototypes
void LEDInit();
void TimerInit();
void TimerITInit();
void Button_IT_Init();
void EXTI15_10_IRQHandler();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

//Global objects
GPIO_InitTypeDef PWMPinConfig;
GPIO_InitTypeDef Button;
TIM_HandleTypeDef Timer;
TIM_OC_InitTypeDef TimerOC;

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
	TimerInit();

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

void TimerInit() {
	__HAL_RCC_TIM1_CLK_ENABLE();

	Timer.Instance = TIM1;
	Timer.Init.Period = 1000;
	Timer.Init.Prescaler = 0;
	Timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	Timer.Init.CounterMode = TIM_COUNTERMODE_UP;

	TimerOC.OCMode = TIM_OCMODE_PWM1;
	TimerOC.Pulse = 0;

	HAL_TIM_PWM_Init(&Timer);
	HAL_TIM_PWM_ConfigChannel(&Timer, &TimerOC, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&Timer, TIM_CHANNEL_1);
}

void Button_IT_Init() {
	//__HAL_RCC_GPIOA_CLK_ENABLE();

	Button.Pin = GPIO_PIN_15;
	Button.Mode = GPIO_MODE_IT_RISING;
	Button.Pull = GPIO_PULLUP;
	Button.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOA, &Button);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	TIM1->CCR1 += 50;
}