/*
 * ADC_reg.h
 *
 *  Created on: Dec 24, 2021
 *      Author: My Family
 */

#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX *((volatile u8*)0x27)
#define ADCSRA *((volatile u8*)0x26)
#define ADCL *((volatile u8*)0x24)
#define ADCH *((volatile u8*)0x25)

#endif /* ADC_REG_H_ */
