#include "Gpio.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_rcc.h"

void configurePin(int direction, int pinNum, GPIO *portNum){
	GPIO_InitTypeDef gpio;

	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	portNum->MODER &= ~(3 << (pinNum*2));
	portNum->MODER |= direction << (pinNum*2);
	portNum->OTYPER &= ~(1 << (pinNum));
	portNum->OSPEED &= ~(3 << (pinNum*2));
	portNum->OSPEED |= GPIO_SPEED_V_HIGH << (pinNum*2);


//	int *ptr = (int *)0x40021800;
//	ptr[0] = 0x14000000;			//MODE.pin14 = output
//	ptr[1] = 0;						//OTYPE.pin14 = push pull
//	ptr[2] = 0x28000000;			//OSPEED.pin14 = high speed
//
//	int *bPtr = (int*)0x40020400;
//	bPtr[0] = 0x04000000;
//	bPtr[1] = 0;
//	bPtr[2] = 0x08000000;
//
//	int *cPtr = (int*)0x40020800;
//	bPtr[0] = 0x00000400;
//	bPtr[1] = 0;
//	bPtr[2] = 0x00000800;
}

void writeOne(int pinNum, GPIO_InitTypeDef *port){
	HAL_GPIO_WritePin(port, pinNum, GPIO_PIN_SET);
}

void writeZero(int pinNum, GPIO_InitTypeDef *port){
	HAL_GPIO_WritePin(port, pinNum, GPIO_PIN_RESET);
}
