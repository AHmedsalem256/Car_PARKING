/*
 * main.c
 *
 *  Created on: May 19, 2023
 *      Author: Ahmed
 */


/*
 * Car Parking Sensor app
 *
 * */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"Icu.h"
#include"TIMERinterface.h"
#include"UARTINTERFACE.h"
#include"LCDINTERFACE.h"
#include"ultrasonic.h"
#include<avr/io.h>
#include<avr/delay.h>


void GIE_SETUP()
{
	SREG |= 1 << 7;
}

extern u8 counter;


void main()
{

	u16 Distance = 0;
	LCD_VidIntialize();
	Timer0_PWM_init();

	Uart_Init();

	DIO_VidSetPinDirection(1,3,1);

	SREG |= 1 << 7;

	DIO_VidSetPortDirection(0,255);

	Ultrasonic_Init();

	Distance = UltrasonicGet_Distance();

	LCD_VidGOTOPOS(0,0);

	u8 kk;

	while(1)
	{

		Ultrasonic_trigger();

				if(counter == 2)
				{
					counter = 0;

				    Distance = UltrasonicGet_Distance();
				}


				if(Distance > 0 && Distance <= 5 )
				{
					DIO_VidSetPortValue(0,255);

					SET_DUTY_CYCLE(0);

					Uart_Sendstring("Stop");
					Uart_Sendu8Data(5);

				}

				else if(Distance > 5 && Distance <= 10 )
				{
					DIO_VidSetPortValue(0,127);

					SET_DUTY_CYCLE(50);

					Uart_Sendstring("DIST_DANGER");
				}

				else if(Distance > 10 && Distance <= 15 )
				{

					SET_DUTY_CYCLE(75);

					DIO_VidSetPortValue(0,63);
				}

				else if(Distance > 15 && Distance <= 20 )
				{

					SET_DUTY_CYCLE(100);

					DIO_VidSetPortValue(0,31);

				}

				else if(Distance > 20 && Distance <= 25 )
				{

					SET_DUTY_CYCLE(150);

					DIO_VidSetPortValue(0,15);

				}

				else if(Distance > 25 && Distance <= 30 )
				{
					SET_DUTY_CYCLE(200);

					DIO_VidSetPortValue(0,7);

					//UART_SendString("ALMOST_SAFE");

				}

				else if(Distance > 30 && Distance <= 35 )
				{
					SET_DUTY_CYCLE(225);

					DIO_VidSetPortValue(0,3);

				}


				else if(Distance > 35  )
				{
					DIO_VidSetPortValue(0,1);



					SET_DUTY_CYCLE(250);
				}

	}

}



