#include "Gpio.h"
//#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_rcc.h"

void configurePin(int direction, int pinNum, GPIO *portNum){

	gpioUnresetEnableClock(portNum);

//	int *aPtr = (int *)0x40023810;
//	aPtr[0] = 0x00000000;
//
//	int *bPtr = (int *)0x40023830;
//	bPtr[0] = 0x0010007F;

//	__HAL_RCC_GPIOG_CLK_ENABLE();
//	__HAL_RCC_GPIOC_CLK_ENABLE();
//	__HAL_RCC_GPIOB_CLK_ENABLE();

	portNum->MODER &= ~(3 << (pinNum*2));
	portNum->MODER |= direction << (pinNum*2);
	portNum->OTYPER &= ~(1 << (pinNum));
	portNum->OSPEED &= ~(3 << (pinNum*2));
	portNum->OSPEED |= GPIO_SPEED_V_HIGH << (pinNum*2);

}

void writeOne(uint16_t pinNum, GPIO *port){
	port->ODR &= ~( 1 << (pinNum));
	port->ODR |= 1 << (pinNum);
}

void writeZero(uint16_t pinNum, GPIO *port){

	port->ODR &= ~( 1 << (pinNum));
	port->ODR |= 0 << (pinNum);
}


