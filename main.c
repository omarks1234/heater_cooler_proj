/*
 * main.c
 *
 *  Created on: Oct 29, 2021
 *      Author: lenovo
 */
/*
 */
#include "STD_type.h"
#include "Utilites.h"
#include "Dio_Reg.h"
#include "util/delay.h"
#include "Dio_Int.h"
#include "I2C_Int.h"
#include "EEPROM_INT.h"
#include "segment.h"
#include"button.h"
#include <avr/delay.h>
#include "timer0_int.h"
#include "timer0_reg.h"
#include "timer2_int.h"
#include "timer2_reg.h"
#include "timer1_int.h"
#include "timer1_reg.h"

#define F_CPU 16000000UL
 u32 counter_timer = 0 ;
u8 power_flag = 0 ;
u32 set_temperature = 600 ;
 u32 analog_value = 450;
 u32 data ;

int main(void)
{

	 //  intit_pins();
	   EEPROM_INIT();
	//   ADC1_Init();


 //  u32 digital;

  ;
  data=EEPROM_readData (4);
  SET_BIT(DDRD,3);
  	SET_BIT(DDRC,2);
  	SET_BIT(DDRC,7);
    timer1_init();
 while(1)
 {
	 // OFF state
	 end:
	  	  PORTA = 0x00 ;
	      PORTB = 0;
	      PORTC = 0x00 ;
	      PORTD = 0x00 ;
	      power_flag = 0 ;

	 if (GET_BIT(PIND , 2) == 1 )  // ON button
	 {
		 while (GET_BIT(PIND,2)==1);  // take action on removing hand
		        _delay_ms(10);
		 power_flag++ ;
		 if ( power_flag %2 == 1 )
		 		{
			      intit_pins();

			        start:
					 while  (GET_BIT(TIFR,2)==0)  // Timer with adc read
							   	 {
							timer2_init();
					       // digital = ADC1_Read(0);
						   //   analog_value = ((digital*5*1000)/1024);
						     display ((analog_value/10));

				      if(analog_value <= (set_temperature - 40)) // Heater and cooler
				       {

							     	SET_BIT(TIMSK, 6);
							        SET_BIT(PORTC,2); // heating led
							        CLR_BIT(PORTC,7); // cooling led
							       }
							      if(analog_value >= (set_temperature + 50))
							       {
							    	CLR_BIT(TIMSK, 6);
						           SET_BIT(PORTC,7);
							       SET_BIT(PORTD,3);  // indicator led
							       CLR_BIT(PORTC,2);
							       }
							      if (analog_value == set_temperature)
							       {
							        CLR_BIT(TIMSK, 6);
							        CLR_BIT(PORTC,2);
							        CLR_BIT(PORTC,7);
							        CLR_BIT(PORTD,3);
						           }
							          goto code ;
										}
					 code:
			 while(1)
			 {

				 display ((analog_value/10));
				 if (GET_BIT(PIND , 2) == 1 )  // OFF button
					 {
					 while (GET_BIT(PIND,2)==1);
					        _delay_ms(10);
						 power_flag++ ;
				 if(power_flag % 2 ==0)
				 {
					 goto end;
				 }
					 }



        		 if( (GET_BIT(PINB,0)==1) || (GET_BIT(PIND,6)==1)) // Enter setting mode
        		 {
        			 // stop heater and cooler and their led
        			  CLR_BIT(PORTC,2);
        		      CLR_BIT(PORTC,7);
        			  CLR_BIT(PORTD,3);

        			 timer_init();


                        	while (1)
                                	{
                                     // 5 seconds timer to exit setting mode
        	                      while((GET_BIT(TIFR , 0)) == 0 )
        	                      {
        	                    	  counter_timer++ ;

        	                    	  if ( counter_timer == 103767)
        	                    	  {
        	                    		  counter_timer = 0 ;

        	                    	     goto start ;

        	                    	  }
        	                      }

        	                      display(data);
        	                      // Rising button
        			         if (GET_BIT(PINB,0)==1){
        			            while (GET_BIT(PIND,2)==1);
        			               _delay_ms(10);
        			               data += 5;
        			               set_temperature = (data*10) ;
        			               counter_timer = 0 ;


        			         }

                                     // decreasing button
        			         if (GET_BIT(PIND,6)==1){
        			              while (GET_BIT(PIND,6)==1);
        			                 _delay_ms(10);
        			                 data -= 5;
        			                 set_temperature = (data*10) ;
        	                         counter_timer = 0 ;

        			             }

        			       		 EEPROM_Write_data(4,data);
        			       		 // minimum temperature to be 35
        			       		 if(data <35 )
        			       		        {
        			       		           data = 35 ;
        			       		           set_temperature = (data*10) ;
        			       		        }
        			       		 // maximum temperature to be 75
        			       		        if(data >75 )
        			       		             {
        			       		                 data = 75 ;
        			       		                 set_temperature = (data*10) ;
        			       		             }
        			       		     if (GET_BIT(PIND , 2) == 1 )
        			       		     	 {
        			       		     		 while (GET_BIT(PIND,2)==1);
        			       		     		   _delay_ms(10);
        			       		     			 power_flag++ ;
        			       		     		 if(power_flag % 2 ==0)
        			       		     		 {
        			       		     			 goto end;
        			       		     		 }
        			       		     	 }

                           	}

                         	}






			                }
		 	            	}
	                       }








 }
}
