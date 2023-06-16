#ifndef UARTINTERFACE_H
#define UARTINTERFACE_H


void Uart_Init(void);

void Uart_Sendu8Data(u8 data);

u8 Uart_GetData();


void Uart_Sendstring(u8 *data);

#endif
