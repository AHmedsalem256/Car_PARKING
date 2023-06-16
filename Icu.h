

/* Author Ahmed Salem  */

#ifndef ICU_H_
#define ICU_H_


typedef enum EDGE
{
	falling,
	rising

}Icu_edge;



void Icu_CALLBACK(void (*ptr)(void));

void __vector_6(void) __attribute__((signal));

void __vector_6 (void);

void Icu_init();


/* Function to set the edge in icu driver
 *
 * includes void
 *
 * return void
 *
 *  */


void Icu_Edgeselect(Icu_edge REQ_EDGE );

/* Function to Get the ICU value
 *
 * Takes nothing
 *
 * return u16 value
 *
 *  */

u16 Icu_getValue();

/* Function to Clear Icu timer value
 *
 * Takes nothing
 *
 * return u16 value
 *
 *  */

void Icu_ClearTimer();

/* Function to Deinit Icu
 *
 * Takes nothing
 *
 * return u16 value
 *
 *  */

void ICU_Denit();


#endif
