/*
 * timer_reg.h
 *
 *  Created on: 8 Oct 2021
 *      Author: xps
 */

#ifndef TIMER0_REG_H_
#define TIMER0_REG_H_

//Defining the addresses of timer 0 register
#define TCCR0 *((volatile u8*)0x53) //Normal mode and prescaler
#define TCNT0 *((volatile u8*)0x52) //Timer Resolution.
#define TIMSK *((volatile u8*)0x59)	//PIE / Overflow Interrupt Enable while GIE is 1
#define OCR0 *((volatile u8*)0x5C) //Timer Compare match
#define TIFR *((volatile u8*)0x58) //





#endif /* TIMER0_REG_H_ */
