#ifndef	__Rng_H__
#define	__Rng_H__

#include <stdint.h>
typedef struct RNG_t RNG;
struct RNG_t{
	uint32_t  RNG_CR;
	uint32_t  RNG_SR;
	uint32_t  RNG_DR;
};

#define RNG_reg ((RNG*)0x50060800)

#endif	//__Rng_H__
