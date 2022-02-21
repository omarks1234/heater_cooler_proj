/*
 * timer_prog.c
 *
 *  Created on: 8 Oct 2021
 *      Author: xps
 */
#include "STD_type.h"
#include "Utilites.h"
#include "Dio_Int.h"
#include "DIO_reg.h"
#include <avr/interrupt.h>

#include "timer0_reg.h"



u16 counter0 = 0;


void timer_init()
{

	//Enabling GIE
	SET_BIT(SREG, 7);

	//Enabling normal mode
	CLR_BIT(TCCR0, 3);
	CLR_BIT(TCCR0, 6);


	//Setting prescaler to 64
	SET_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);

/*
	//Setting prescaler to external clock on rising edge
	SET_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);*/

	//CLEAR_BIT(TCCR0, 2);

	//Initialize TCNT0
      TCNT0 = 48;

	//Enabling Over flow Interrupt
	SET_BIT(TIMSK, 0);



}



ISR(TIMER0_OVF_vect)
{
	//SET_BIT(DDRC, 7);
    counter0++;
		if(counter0 == 4883)
		{
			//TOG_BIT(PORTC, 7);
		    //Re-initialize the timer
			counter0 = 0;
			TCNT0 = 48;


		}
}


