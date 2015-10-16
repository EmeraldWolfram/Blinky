#include "Gpio.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_rcc.h"

void configurePin(int direction, int pinNum, GPIO_InitTypeDef *portNum){
	GPIO_InitTypeDef gpio;
	__HAL_RCC_GPIOG_CLK_ENABLE();
		gpio.Pin = pinNum;
		gpio.Mode = direction;
		gpio.Speed = GPIO_SPEED_MEDIUM;
		gpio.Pull = GPIO_NOPULL;

		HAL_GPIO_Init(portNum, &gpio);
}

void writeOne(int pinNum, GPIO_InitTypeDef *port){
	HAL_GPIO_WritePin(port, pinNum, GPIO_PIN_SET);
}

void writeZero(int pinNum, GPIO_InitTypeDef *port){
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
}
