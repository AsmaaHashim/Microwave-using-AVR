/*
 * keypad.h
 *
 *  Created on: Feb 16, 2020
 *      Author: Asmaa Hashim
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include"gpio_register.h"

#define KEY_DDR  *((volatile unint8* )PORT_A + DIR_OFFSET)

#define KEY_PORT *((volatile unint8*)PORT_A + DATA_OFFSET)

#define KEY_PIN  *((volatile unint8*) PORT_A)

#define ROW_NUM  4

#define COLUM_NUM 4

void keypad_init(void);

unint8 key_pressed();


#endif /* KEYPAD_H_ */
