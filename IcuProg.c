
/*

@breif Icu driver for atmega32

DAte : 14/5/2023

Author : Ahmed Salem Mohammed

*/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Icu.h"
#include"DIO_interface.h"
#include"LCDINTERFACE.h"
#include<avr/io.h>


/* Function intialize the icu Intrrupts
 *
 * includes void
 *
 * return void
 *
 *  */

void (*Icu_CallFunction)(void) = 0;

/* Vector 6 Intrrupt function  */

void __vector_6(void) __attribute__((signal));

void __vector_6 (void)
{
	Icu_CallFunction();
}



void Icu_CALLBACK(void (*ptr)(void))
{
	if(ptr != 0)
	{
		Icu_CallFunction = ptr  ;
	}
}

/* Function intialize the icu
 *
 * includes void
 *
 * return void
 *
 *  */


void Icu_init()
{
	/* SEETING PIND6 As i/p pin */

	DIO_VidSetPinDirection(3,6,0);

	/* Timer1 act in normal mode */

	TCCR1A = (1<<3) | (1<<2);

	/* Inserting the required prescaler */

	TCCR1B |= 1 << 1;
	/* insert the required edge  Rising as default  */

	TCCR1B |= 1 << 6;

	/* Enable Icu intrrupt */

	SREG |= 1 << 7;  // GIE enable
	TIMSK |= 1 << 5;

	/* intial values for some register  */


	TCNT1 = 0;
	ICR1 = 0;


}

/* Function to set the edge in icu driver
 *
 * includes void
 *
 * return void
 *
 *  */


void Icu_Edgeselect(const Icu_edge REQ_EDGE)
{
	/* SETTING THE REQUIRED EDGE */

	TCCR1B = (TCCR1B & 0xBF) | (REQ_EDGE<<6);
}

/* Function to Get the ICU value
 *
 * Takes nothing
 *
 * return u16 value
 *
 *  */

u16 Icu_getValue()
{
	return ICR1;
}

/* Function to Clear Icu timer value
 *
 * Takes nothing
 *
 * return u16 value
 *
 *  */

void Icu_ClearTimer()
{
	TCNT1 = 0;
}

/* Function to Deinit Icu
 *
 * Takes nothing
 *
 * return u16 value
 *
 *  */

void ICU_Denit()
{
	/* Clear all timer1 registers */

	TCNT1 = 0;
	ICR1 = 0;
	TCCR1B = 0;
	TCCR1A = 0;

	/* Disable the Input Capture interrupt */
	TIMSK &= ~(1<<TICIE1);
}



