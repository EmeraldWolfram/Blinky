#include "Rcc.h"

void gpioUnresetEnableClock(GPIO* port){
	int valToShift = ((int)port - (0x40020000))/(0x400);
//		int *aPtr = (int *)0x40023810;
//		aPtr[0] = 0x00000000;
//
//		int *bPtr = (int *)0x40023830;
//		bPtr[0] = 0x0010007F;
	RCC_reg->RCC_AHB1RSTR &= ~(1 << (valToShift));
	RCC_reg->RCC_AHB1ENR |= (0x00100000 | ~(0 << (valToShift)));
}
