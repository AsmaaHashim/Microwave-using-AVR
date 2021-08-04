/*
 * LCD.c
 *
 *  Created on: Feb 16, 2020
 *      Author: Asmaa Hashim
 */




#include "LCD.h"

#include <util/delay.h>

static void delay_us(unint32 time)  // because of the difference between delay function shape
{
	_delay_us(time);
}

void LCD_init(void)
{

	LCD_CTRL_PORT_DIR |=((1 << E) | (1 << RS) | (1 << RW) );

#if(DATA_BITS_MODE == 4)

#ifdef (UPPER_PORT_BINS)
		LCD_DIR_PORT =0X0F;
#else
		LCD_DIR_PORT =0XF0;

#endif

		LCD_sendCommand(TWO_LINE_LCD_4BITS_MODE);

#elif (DATA_BITS_MODE == 8)

		LCD_DIR_PORT = 0XFF;

		LCD_sendCommand(TWO_LINE_LCD_8BITS_MODE);

#endif

		LCD_sendCommand(CURSOR_OFF); /* cursor off */
		LCD_sendCommand(CLEAR_COMMAND);

}

void LCD_sendCommand(unint8 commond)
{
	CLEAR_BIT(LCD_CTRL_PORT , RS );

	CLEAR_BIT(LCD_CTRL_PORT , RW);

	delay_us(1);

	SET_BIT(LCD_CTRL_PORT , E);

	delay_us(1);

#if(DATA_BITS_MODE ==4)

#ifdef(UPPER_PORT_PINS )
	LCD_DATA_PORT = (LCD_DATA_PORT & 0XF0) | (commond >> 4);
#else
	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F) | (commond & 0xf0);

#endif
	delay_us(1); 						/* delay for processing Tdsw = 100ns */
		CLEAR_BIT(LCD_CTRL_PORT,E); 		/* disable LCD E=0 */
		delay_us(1);						/* delay for processing Th = 13ns */
		SET_BIT(LCD_CTRL_PORT,E); 			/* Enable LCD E=1 */
		delay_us(1);



#ifdef(UPPER_PORT_PINS )
	LCD_DATA_PORT = (LCD_DATA_PORT & 0XF0) | (commond & 0x0f);
#else
	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F) | (commond << 4);

#endif
	    delay_us(1); 						/* delay for processing Tdsw = 100ns */
		CLEAR_BIT(LCD_CTRL_PORT,E); 		/* disable LCD E=0 */
		delay_us(1);						/* delay for processing Th = 13ns */
		SET_BIT(LCD_CTRL_PORT,E); 			/* Enable LCD E=1 */
		delay_us(1);



#elif(DATA_BITS_MODE == 8)

	LCD_DATA_PORT = commond;
	delay_us(1);
	CLEAR_BIT(LCD_CTRL_PORT , E);
	delay_us(1);

#endif





}

void LCD_displayCharacter(unint8 ch)
{
	SET_BIT(LCD_CTRL_PORT , RS);  // mean that will write data

	CLEAR_BIT(LCD_CTRL_PORT , RW);

		delay_us(1);

		SET_BIT(LCD_CTRL_PORT , E);

		delay_us(1);


#if (DATA_BITS_MODE ==4)

#ifdef UPPER_PORT_PINS
		LCD_DATA_PORT =(LCD_DATA_PORT & 0XF0) | (ch >>4)
#else
		LCD_DATA_PORT =(LCD_DATA_PORT & 0X0F ) | (ch & 0xf0);
#endif

		delay_us(1);
		CLEAR_BIT(LCD_CTRL_PORT , E);
		delay_us(1);

		SET_BIT(LCD_CTRL_PORT , E);
		delay_us(1);

#ifdef UPPER_PORT_PINS
		LCD_DATA_PORT =(LCD_DATA_PORT & 0XF0) | (ch & 0x0f);
#else
		LCD_DATA_PORT =(LCD_DATA_PORT & 0X0F ) | (ch << 4);
#endif
		   delay_us(1);
			CLEAR_BIT(LCD_CTRL_PORT , E);
			delay_us(1);


#elif(DATA_BITS_MODE==8)

LCD_DATA_PORT = ch;
delay_us(1);
CLEAR_BIT(LCD_CTRL_PORT ,E);
delay_us(1);

#endif

	}

void LCD_displayString(const unint8 *str)
{
	unint8 i=0;

	while(str[i] !='\0')
	{

		LCD_displayCharacter(str[i]);

		i++;
	}


}
void LCD_goToRowColum(unint8 row , unint8 colum)
{
	unint8 Address;

	switch(row)
	{

	case 0:
		Address =colum;
		break;
	case 1:
		Address = colum + 0x40;
		break;


	}

	LCD_sendCommand(Address + SET_CURSOR_LOCATION);



}

void LCD_displayStringOnRowColum(unint8 row , unint8 colum , const unint8 *str)
{
	LCD_goToRowColum(row , colum);
	LCD_displayString(str);





}



void LCD_clear_screen(void)
{
	LCD_sendCommand(CLEAR_COMMAND);

}

void LCD_intgerToString(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* 10 for decimal */
   LCD_displayString(buff);
}

void LCD_store_pattren(unint8 *pattren , unint8 indix)
{
	unint8 address , i;

	address=indix * 8;

	LCD_sendCommand(address | SET_CGRAM_ADDRESS);

	for(i=0 ; i< 8 ; i++ )
	{
		LCD_displayCharacter(pattren[i]);

	}

	LCD_sendCommand(RETURN_HOME);

}
