/*
 * timer1_reg.h
 *
 *  Created on: Jan 6, 2022
 *      Author: My Family
 */

#ifndef TIMER1_REG_H_
#define TIMER1_REG_H_

//Defining the addresses of timer 0 register
#define TCCR1B *((volatile u8*)0x4E) //Normal mode and prescaler
#define TCNT1 *((volatile u16*)0x4C) //Timer Resolution.
#define TIMSK *((volatile u8*)0x59)	//PIE / Overflow Interrupt Enable while GIE is 1
#define TIFR *((volatile u8*)0x58) //

#endif /* TIMER1_REG_H_ */
