/*
 * timer1_prog.c
 *
 *  Created on: Jan 6, 2022
 *      Author: My Family
 */
#include "STD_type.h"
#include "Utilites.h"
#include "Dio_Int.h"
#include "DIO_reg.h"
#include <avr/interrupt.h>
#include "timer1_reg.h"

u16 counter1 = 0;



void timer1_init()

{
	//Enabling GIE
		SET_BIT(SREG, 7);

		//Enabling normal mode
		CLR_BIT(TCCR2, 3);
		CLR_BIT(TCCR2, 6);


		//Setting prescaler to 64
		SET_BIT(TCCR1B, 0);
		SET_BIT(TCCR1B, 1);


		//CLEAR_BIT(TCCR0, 2);

		//Initialize TCNT0
	      TCNT1 = 40540;

		//Enabling Over flow Interrupt
		SET_BIT(TIMSK, 2);

}



ISR(TIMER1_OVF_vect)

{
	 counter1++;
			if(counter1 == 24995)
			{
				counter1 = 0;
				TCNT1 = 40540;
			}
}
