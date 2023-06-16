

/*

AUTHOR: Ahmed salem mohamed

Date : 16/11/2022

Description : Uart driver for ATMEGA32 base on C

*/


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"UARTPRIV.h"


void Uart_Init(void)
{

	 UCSRC = 0x86;
	  // Enable RX and TX
	  UCSRB = 0x18;

	UBRRL = 0x33;
  // UBRRH = 0;
	
	
}

void Uart_Sendu8Data(u8 data)
{
	
	//while(GET_BIT(UCSRA,5) == 0)
	while((UCSRA&0x20) == 0x00);

	UDR = data;
}

u8 Uart_GetData()
{
	//while(GET_BIT(UCSRA,5) == 0)
	while((UCSRA&0x80) == 0x00);

	return UDR;
}


void Uart_Sendstring(u8 *ptr)
{
	u8 i;

		for(i=0;ptr[i]!='\0';i++)
		{
			Uart_Sendu8Data(ptr[i]);
		}
}


