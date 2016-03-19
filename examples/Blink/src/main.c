/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f4xx.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stdlib.h"
#include "basic/usart.h"
#include "basic/basic.h"

volatile uint32_t timer_ms = 0;

void delay(int time) {
	int i;
	for (i = 0; i < time * 4000; i++) {
	}
}

void SysTick_Handler() {
	if (timer_ms) {
		timer_ms--;
	}
}

void delay_ms(int time) {
	timer_ms = time;
	while (timer_ms) {
	};
}

int main(void) {
	STM32_GPIO_Enable();
	STM32_BASIC_Init();
	STM32_USART_Init();

	while (1) {

		if (STM32_ButtonStatus() == 0) { // jesli przycisk jest przycisniety,
			STM32_LED_On();
			USART_SendString("Dioda zapalona\r\n");
		} else {
			STM32_LED_Off();
			USART_SendString("Dioda zgaszona\r\n");
		}
	}

	//SysTick_Config(SystemCoreClock / 1000);
}
