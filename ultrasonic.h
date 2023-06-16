
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

/* Some inportant configurations  */

#define TRIG_PORT 3
#define TRIG_PIN  7
#define HIGH  1
#define LOW   0
/* config enum for edge select */


void Ultrasonic_Init();

void Ultrasonic_trigger();


u16 UltrasonicGet_Distance();

void Edge_Process();

#endif
