/*
 * main.c
 *
 *  Created on: Feb 16, 2020
 *      Author: Asmaa Hashim
 */


#include "microWave.h"

int main(void)
{
	microWave_init();

	SREG &=~(1 << 7);

         while(1)
             {

        	 if(start())
        	 {
        		 start_LED_ON();

        		 if(foodIsInMicro() && door_is_close())
        		 {
        			 scan_minutes();      heat_on();     FAN_ON();

        			 start_calc_time();

        			 while(!stop()  && (minutes > 0 || second==0))
        			      {

        				 show_remaining_time();

        					 }

        			 stop_cal_time();

        			 heat_off();

        			 FAN_OFF();

        			 door_is_open();      // will wait here till the door is opened

        			 foodOutMicro();     // will wait here till the food is taken out microwave

        			 start_LED_OFF();

        			 LCD_clear_screen();

        			  }
        	 }     // end microwave

             } // end while(1)

         return 0;
}
