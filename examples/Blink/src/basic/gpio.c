/*
 * gpio.c
 *
 *  Created on: 19 mar 2016
 *      Author: grafv
 */

#include "stm32f4xx.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

void STM32_GPIO_Enable(void) {
	// uruchomienie zegara modulu GPIO Wszytkie jednoczesnie
	RCC_AHB1PeriphClockCmd(
			RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC
					| RCC_AHB1Periph_GPIOD, ENABLE);
}
