

/*
 * Ultrasonic driver for Based on ICU
 *
 *
 * */
#include"BIT_MATH.h"
#include"STD_TYPES.h"

#include"DIO_interface.h"
#include"Icu.h"
#include"ultrasonic.h"
#include<avr/delay.h>

u16 Distance = 0;

u8 counter;

u16 g_counter;

/*
 *
 * */

void Ultrasonic_Init();

void Ultrasonic_trigger();


u16 UltrasonicGet_Distance();

void Edge_Process();


/**/

void Ultrasonic_Init()
{
	Icu_init();

	/* Set Pin Trigger for triggring  */

	DIO_VidSetPinDirection(TRIG_PORT,TRIG_PIN,HIGH);

	/* Set call back for the icu  */

	Icu_CALLBACK(Edge_Process);



}

void Ultrasonic_trigger()
{
	DIO_VidSetPinValue(TRIG_PORT,TRIG_PIN,HIGH);

	_delay_us(15);

	DIO_VidSetPinValue(TRIG_PORT,TRIG_PIN,LOW);


}


u16 UltrasonicGet_Distance()
{
	u16 distance;

	Ultrasonic_trigger();

	distance = ((float)(g_counter)/58.5);

	return distance;
}



void Edge_Process()
{
	++ counter;
	if(counter == 1)
	{

		Icu_Edgeselect(falling);

		Icu_ClearTimer();

	}

	else if(counter == 2)
	{
		g_counter = Icu_getValue();

		Icu_Edgeselect(rising);

		Icu_ClearTimer();
	}

	else
	{
		counter = 0;
	}

}

