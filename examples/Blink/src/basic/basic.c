/*
 * basic.c
 *
 *  Created on: 19 mar 2016
 *      Author: grafv
 */
#include "stm32f4xx.h"

void STM32_BASIC_Init(void) {
	GPIO_InitTypeDef gpio;          // obiekt gpio bêd¹cy konfiguracj¹ portów GPIO
	GPIO_StructInit(&gpio);         // domyœlna konfiguracja
	gpio.GPIO_Pin = GPIO_Pin_5;     // konfigurujemy pin 5
	gpio.GPIO_Mode = GPIO_Mode_OUT;	// jako wyjœcie
	GPIO_Init(GPIOA, &gpio);        // inicjalizacja modu³u GPIOA

	gpio.GPIO_Pin = GPIO_Pin_13;    // konfigurujemy pin 13
	gpio.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init(GPIOC, &gpio);        // port GPIOC
}

void STM32_LED_On(void){
	GPIO_SetBits(GPIOA, GPIO_Pin_5); // zapalenie diody
}

void STM32_LED_Off(void){
	GPIO_ResetBits(GPIOA, GPIO_Pin_5); // zgaszenie diody
}

int STM32_ButtonStatus(void)
{
	return GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);
}
