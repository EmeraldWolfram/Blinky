#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"

#include "Gpio.h"

int main(void)
{
	configurePin(GPIO_MODE_OUTPUT_PP, GPIO_PIN_13, GPIOG);
	int a = 4;
	double d = 5.6789123;

	d = d* a;



    while(1)
    {
    	writeOne(GPIO_PIN_13, GPIOG);
    	writeZero(GPIO_PIN_13, GPIOG);
    }
}
