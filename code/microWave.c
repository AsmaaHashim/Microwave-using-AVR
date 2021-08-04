/*
 * microWave.c
 *
 *  Created on: Feb 16, 2020
 *      Author: Asmaa Hashim
 */


#include "microWave.h"

#define NUM_OF_OVF_PER_SEC  3

static volatile unint8 count=0;

volatile unint8   second;

volatile unint16  minutes ;

static void Call_Back_OVFI(void)    // calculate remaning time in back ground
{
	count++;

	if(count == NUM_OF_OVF_PER_SEC)
	{
		second--;   count=0;

		if(second == 0 )
		{
			minutes--; second=60;

		}

	}

}

void microWave_init(void)
{

	CLEAR_BIT(  START_BUTTON_DIR_PORT , START_BUTTON_PIN);  //configure start pin as input pin

	CLEAR_BIT( STOP_BUTTON_DIR_PORT , STOP_BUTTON_PIN); //configure stop pin as input pin

    SET_BIT( START_BUTTON_DATA_PORT , START_BUTTON_PIN );          // configure start pin as internal pull_up

    SET_BIT( STOP_BUTTON_DATA_PORT , STOP_BUTTON_PIN );         // configure stop  pin as internal pull_up

    SET_BIT(LAMP_DIR_PORT , LAMP_PIN);         // start_LED pin as output pin

    CLEAR_BIT( DOOR_BUTTON_DIR_PORT ,  DOOR_BUTTON_PIN);       // configure door pin as input pin

    SET_BIT( DOOR_BUTTON_DATA_PORT   ,  DOOR_BUTTON_PIN);       // configure door pin as internal pull up

    SET_BIT(DOOR_LED_DIR_PORT , DOOR_LED_PIN);        // configure the led that indicates the door state as out pin

    CLEAR_BIT(WEIGHT_BUTTON_DIR_PORT , WEIGHT_BUTTON_PIN);     // configure weight pin as input pin

    SET_BIT(WEIGHT_BUTTON_DATA_PORT  , WEIGHT_BUTTON_PIN);       // configure weight pin as internal pull up

    SET_BIT(WEIGHT_LED_DIR_PORT ,  WEIGHT_LED_PIN  );        // configure the led that indicates the weight state as out pin

    SET_BIT(HEAT_DIR_PORT , HEAT_PIN);        // configure the Heat led  as out pin

    SET_BIT(FAN_DIR_PORT , FAN_PIN_1);        // configure the FAN PIN  as out pin

    SET_BIT(FAN_DIR_PORT , FAN_PIN_2);        // configure the FAN PIN  as out pin

                       /********************timer0 initialization        ******************/

    timer0_configer data={CLOCK_DIV_1024_T0 , normal_T0 , OC0_disconnect_T0  , enable_OVI_T0 , disable_OCI_T0};

    timer0_init(&data);

     timer0_callBack_OVFI(&Call_Back_OVFI);

   /********************_ timer1 initialization _*****************************/

     timer1_config timer1_data={CLOCK_DIV_8_T1 , F_PWM_T_8BIT , Clear_A ,OC1B_disconnect ,\
     			                disable_OVFI_T1 ,  disable_OCIA_T1   , disable_OCIB_T1};

     	timer1_init(&timer1_data);

     	set_OCR1A_val(0);

     	OCDPT1 |=(1<<OC1A);

  /********************'__' keypad & lcd initialization'__'********************/

     keypad_init();

    LCD_init();     second=60;

    }


unint8 start(void)
{
	if(!READ_BIT(START_BUTTON_READ_PORT , START_BUTTON_PIN))
	{

	while(!READ_BIT(START_BUTTON_READ_PORT , START_BUTTON_PIN));

	return 1;

	}
	return 0;
	}

unint8 stop(void)
{
	if(!READ_BIT(STOP_BUTTON_READ_PORT , STOP_BUTTON_PIN))
	{
		while(!READ_BIT(STOP_BUTTON_READ_PORT ,STOP_BUTTON_PIN));

		return 1;

	}

      return 0;
}

void start_LED_ON(void)
{
	SET_BIT(LAMP_DATA_PORT , LAMP_PIN );

}

void start_LED_OFF(void)
{
	CLEAR_BIT(LAMP_DATA_PORT , LAMP_PIN );
}

void scan_minutes(void)
{

	 unint8 minutes_digits[5]   ;

	 unint8  indix_of_digit=0  , digit;

	while(digit !='c')
	{
		digit=key_pressed();                    // scan the digit  from the user

		minutes_digits[indix_of_digit]=digit;   // store the digit

       indix_of_digit++;

	}

	indix_of_digit =0;

	// this while used to calculate the minutes

	while(minutes_digits[indix_of_digit] != 'c' )
	{

		if(indix_of_digit == 0)
		{
			minutes = minutes_digits[indix_of_digit];
		}
		else
		{
			minutes = minutes * 10 +  minutes_digits[indix_of_digit];
		}

		indix_of_digit++;

		}

	minutes--;
}

unint8 door_is_close()
{

	while(READ_BIT(DOOR_BUTTON_READ_PORT , DOOR_BUTTON_PIN));

	while(!READ_BIT(DOOR_BUTTON_READ_PORT , DOOR_BUTTON_PIN));

	TOGGLE_BIT(DOOR_LED_DATA_PORT , DOOR_LED_PIN);

	return 1;
}

void show_remaining_time(void)
{

	      LCD_goToRowColum(0 , 1);

	      LCD_displayString("R_TIME = ");

          LCD_goToRowColum(0 , 9);

	      LCD_intgerToString(minutes);
	      if(minutes < 10)
	          {
	               	 LCD_goToRowColum(0 , 10);
	               	 LCD_displayCharacter(' ');

	          }

          LCD_goToRowColum(0 , 11);

          LCD_displayCharacter(':');

          LCD_intgerToString(second);
	          if(second < 10)
	             {
	        	    	 LCD_goToRowColum(0 , 13);
	        	    	 LCD_displayCharacter(' ');
	                  	     }
}

unint8 door_is_open()
{
	while(READ_BIT(DOOR_BUTTON_READ_PORT , DOOR_BUTTON_PIN));

	while(!READ_BIT(DOOR_BUTTON_READ_PORT , DOOR_BUTTON_PIN));

	TOGGLE_BIT(DOOR_LED_DATA_PORT , DOOR_LED_PIN);

	return 1;


}

unint8 foodIsInMicro()
{
	while(READ_BIT(WEIGHT_BUTTON_READ_PORT , WEIGHT_BUTTON_PIN));

	while(!READ_BIT(WEIGHT_BUTTON_READ_PORT , WEIGHT_BUTTON_PIN));

	TOGGLE_BIT(WEIGHT_LED_DATA_PORT , WEIGHT_LED_PIN );

		return 1;



}// wait there till button is pressed & then led will toggle its state

unint8 foodOutMicro()
{
	while(READ_BIT(WEIGHT_BUTTON_READ_PORT , WEIGHT_BUTTON_PIN));

		while(!READ_BIT(WEIGHT_BUTTON_READ_PORT , WEIGHT_BUTTON_PIN));

		TOGGLE_BIT(WEIGHT_LED_DATA_PORT , WEIGHT_LED_PIN );

			return 1;
	}

void heat_on(void)
{

    SET_BIT(HEAT_DATA_PORT , HEAT_PIN);

}

void heat_off(void)
{
    CLEAR_BIT(HEAT_DATA_PORT , HEAT_PIN);

}

void FAN_ON(void)
{
	 SET_BIT( FAN_DATA_PORT , FAN_PIN_1);

	 CLEAR_BIT( FAN_DATA_PORT , FAN_PIN_2);

  	set_OCR1A_val(128);

}

void FAN_OFF(void)
{
	 CLEAR_BIT( FAN_DATA_PORT , FAN_PIN_1);
	 CLEAR_BIT( FAN_DATA_PORT , FAN_PIN_2);
  	set_OCR1A_val(0);

}

void start_calc_time(void)
{

	SREG |=((unint8)1 << (unint8)7);

	}

void stop_cal_time(void)
{
	SREG &=~((unint8)1 << (unint8)7);

}
