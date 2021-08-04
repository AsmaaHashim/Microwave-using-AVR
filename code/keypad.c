/*
 * keypad.c
 *
 *  Created on: Feb 16, 2020
 *      Author: Asmaa Hashim
 */



#include "keypad.h"

static const unsigned char keypad[4][4]={ {7 , 8 , 9 , '/' },
		                                  {4 , 5 , 6 , '*' },
	                             	      {1 , 2 , 3 , '-' },
	                             	      {'c', 0 ,'=','+' },
                                         };

void keypad_init(void)
{
	KEY_DDR = 0x0f;

    KEY_PORT = 0xff;
}

unint8 key_pressed()
{
	unint8 i , j ;

	while(1)
	{
		for(i=0 ; i < ROW_NUM ; i++)
		{
			KEY_PORT &=~(1u << i);

			for(j=0 ; j < COLUM_NUM  ; j++)
			{
				if(!(KEY_PIN & (1u<<(j+4))))
				{

					while(!(KEY_PIN & (1u<< (j+4))));

					return keypad[i][j];
				}
			}

			KEY_PORT |=(1u << i);

		}

	}
}
