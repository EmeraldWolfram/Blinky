#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"

#include "Gpio.h"

int main(void)
{
	configurePin(GPIO_MODE_OUTPUT_PP, PIN_14, PORTG);
	configurePin(GPIO_MODE_OUTPUT_PP, PIN_13, GPIOG);
	configurePin(GPIO_MODE_OUTPUT_PP, PIN_13, GPIOB);
	configurePin(GPIO_MODE_OUTPUT_PP, PIN_5, GPIOC);

	int a = 4;
	double d = 5.6789123;

	d = d* a;

    while(1)
    {
    	writeOne(GPIO_PIN_13, GPIOG);
    	writeZero(GPIO_PIN_14, GPIOG);
    	writeOne(GPIO_PIN_13, GPIOB);
    	writeZero(GPIO_PIN_5, GPIOC);

    	_delay(50000);
    	writeZero(GPIO_PIN_13, GPIOG);
    	writeOne(GPIO_PIN_14, GPIOG);
    	writeZero(GPIO_PIN_13, GPIOB);
    	writeOne(GPIO_PIN_5, GPIOC);
    	_delay(50000);
    }
}

void _delay(int delay){
	while(delay != 0)
		delay--;
}
