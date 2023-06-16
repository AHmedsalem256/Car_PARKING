

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include<avr/io.h>


/*


Timer 0 with PWM used to quick test 

AUTHOR : AHMED SALEM 


*/



void Timer0_PWM_init()
{
	/* TCCR0 register */
	
	TCCR0 |= 1 << 6 | 1 << 3 | 1 << 5 | 1 << 1;
	
	
}


void SET_DUTY_CYCLE(u8 duty)
{
	OCR0 = duty;
}



