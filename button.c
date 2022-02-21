/*
 * button.c
 *
 *  Created on: Jan 1, 2022
 *      Author: lenovo
 */

#include"Utilites.h"
#include "Dio_Reg.h"
#include "STD_type.h"
#include "segment.h"
#include "avr/delay.h"
void button_init(void)
{
    SET_BIT(DDRC,2);
    SET_BIT(DDRD,3);
}
u8  button_1 (u8 data)
{
  //  u8 data ;

    if (GET_BIT(PIND,2)==1){
     while (GET_BIT(PIND,2)==1);
        _delay_ms(10);
        data += 5;

    }
    return data ;
}
u8  button_2 (u8 data)
{
   // u8 data ;
    if (GET_BIT(PIND,6)==1){
     while (GET_BIT(PIND,6)==1);
        _delay_ms(10);
        data -= 5;

    }
    return data ;
}
u8   button_3 (void)
{
    u8 counter = 0 ;
    if (GET_BIT(PINB,0)==1){
     while (GET_BIT(PINB,0)==1);
        _delay_ms(10);
       counter++;


    }
    return counter ;
}

