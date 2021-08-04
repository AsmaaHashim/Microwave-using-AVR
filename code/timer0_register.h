/*
 * timer0_register.h
 *
 *  Created on: Feb 17, 2020
 *      Author: Asmaa Hashim
 */

#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_


#include "gpio_register.h"

                          /************"register description"**************/

#define  TCNT0 *((volatile unint8*)0x52)    // timer/counter data register 0

#define  TCCR0 *((volatile unint8*)0x53)    // timer/counter control register 0

#define  TIMSK *((volatile unint8*)0x59)    // timer/counter interrupt register 0

#define  OCR0 *((volatile unint8*)0x5C)    // timer/counter output compar register 0

#define  TIFR *((volatile unint8*)0x58)    // timer/counter interrupt flag register 0

#define  SREG *((volatile unint8*)0x5F)    // global interrupt register



                     /*******************"BITS description"********************/

 /*_ timer/counter control register 0 BITS_*/

      /***********these three bits of clk_select ***********/
#define CS00  0
#define CS01  1
#define CS02  2

/*************** these 5 bits for control the mode ******************/

#define WGM01  3
#define COM00 4
#define COM01  5
#define WGM00  6
#define FOC0  7

/*****************these two bits for control interrupt****************/

#define TOIE0  0
#define OCIE0  1

// flag bits

#define TOV0  0
#define OCF0  1

//this bit of global interrupt control

#define GICB  7

// output compare zero pin  & port

#define OC0  3

#define OCDP *((volatile unint8*)PORTB + DIR_OFFSET)


#endif /* TIMER0_REGISTER_H_ */
