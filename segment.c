/*
 * segment.c
 *
 *  Created on: Sep 23, 2021
 *      Author: lenovo
 */

#include "Dio_int.h"
#include "Dio_Reg.h"
#include "segment.h"
#include<avr/delay.h>

void intit_pins(void)
{
	Dio_SetPinDirection(GroupB, PIN1, OUTPUT);
	Dio_SetPinDirection(GroupB, PIN2, OUTPUT);
	Dio_SetPinDirection(GroupA,  PIN4, OUTPUT);
	Dio_SetPinDirection(GroupA,  PIN5, OUTPUT);
	Dio_SetPinDirection(GroupA,  PIN6, OUTPUT);
	Dio_SetPinDirection(GroupA,  PIN7, OUTPUT);

}
void display (u32 i)
{
  // for (int i = 0 ; i<=99 ; i++)
             //   {
                    for (int j = 0 ; j <19; j++)
                    {

                    Dio_SetPinValue(GroupB, PIN2, HIGH);
                    Dio_SetPinValue(GroupB, PIN1, LOW);
                    PORTA = (i / 10) <<4;
                    _delay_ms(j);
                  Dio_SetPinValue(GroupB, PIN1, HIGH);
                    Dio_SetPinValue(GroupB, PIN2, LOW);
                    PORTA = (i % 10) <<4;
                     _delay_ms(j);
                   }
           //  }
}
