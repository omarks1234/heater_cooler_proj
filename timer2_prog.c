/*
 * timer_prog.c
 *
 *  Created on: 8 Oct 2021
 *      Author: xps
 */
#include "STD_type.h"
#include "Utilites.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include <avr/interrupt.h>
#include "ADC.h"
#include "ADC_reg.h"
#include "timer2_reg.h"

u16 counter2 = 0;





void timer2_init()
{

	//Enabling GIE
	SET_BIT(SREG, 7);

	//Enabling normal mode
	CLR_BIT(TCCR2, 3);
	CLR_BIT(TCCR2, 6);


	//Setting prescaler to 64
	SET_BIT(TCCR2, 0);
	SET_BIT(TCCR2, 1);


	//CLEAR_BIT(TCCR0, 2);

	//Initialize TCNT0
      TCNT2 = 112;

	//Enabling Over flow Interrupt
	SET_BIT(TIMSK, 6);



}


// 1 second timer
ISR(TIMER2_OVF_vect)
{

    counter2++;
		if(counter2 == 977)
		{
			SET_BIT(DDRD,3);
		    TOG_BIT(PORTD,3);

		    //digital = ADC_read();
		    //analog_value = ((digital*5*1000)/1024);



		   /* SET_BIT(DDRC, 7);
		    TOG_BIT(PORTC, 7);*/
		    //Re-initialize the timer
			counter2 = 0;
			TCNT2 = 112;


		}
}





