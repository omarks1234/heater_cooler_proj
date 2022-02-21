/*
 * ADC.c
 *
 * Created: 27/12/2021 23:17:55
 *  Author: MARIO ASHRAF
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "utilites.h"

void ADC1_Init()
{
	CLR_BIT(DDRA, 3);			/* Make ADC port as input */
	ADCSRA = 0x86;			/* Enable ADC, fr/64  */
	ADMUX = 0x40;			/* Vref: Avcc, ADC channel: 0 */ /*ADMUX: 01000010*/
	
}

int ADC1_Read(char channel)
{
	int Ain,AinLow;
	
	ADMUX=ADMUX|(channel & 0x0f);	/* Set input channel to read */

	ADCSRA |= (1<<ADSC);		/* Start conversion */
	while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */
	
	_delay_us(10);
	AinLow = (int)ADCL;		/* Read lower byte*/
	Ain = (int)ADCH*256;		/* Read higher 2 bits and 
					Multiply with weight */
	Ain = Ain + AinLow;				
	return(Ain);			/* Return digital value*/
}
