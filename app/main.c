#include "stm32f4xx.h"

#include "Gpio.h"

int main(void)
{
	configurePin(GPIO_MODE_OUTPUT, PIN_14, PORTG);
	configurePin(GPIO_MODE_OUTPUT, PIN_13, PORTG);
	configurePin(GPIO_MODE_OUTPUT, PIN_13, PORTB);
	configurePin(GPIO_MODE_OUTPUT, PIN_5,  PORTC);


    while(1)
    {
    	writeOne(PIN_13, PORTG);
    	writeZero(PIN_14, PORTG);
    	writeOne(PIN_13, PORTB);
    	writeZero(PIN_5, PORTC);

    	_delay(50000);
    	writeZero(PIN_13, PORTG);
    	writeOne(PIN_14, PORTG);
    	writeZero(PIN_13, PORTB);
    	writeOne(PIN_5, PORTC);
    	_delay(50000);
    }
}

void _delay(int delay){
	while(delay != 0)
		delay--;
}
