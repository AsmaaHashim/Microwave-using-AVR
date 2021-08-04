/*
 * timer1_registers.h
 *
 *  Created on: Feb 19, 2020
 *      Author: Asmaa Hashim
 */

#ifndef TIMER1_REGISTERS_H_
#define TIMER1_REGISTERS_H_


#include "gpio_register.h"

                          /************"register description"**************/

#define  TCNT1L *((volatile unint8*)0x4C)

#define  TCNT1H *((volatile unint8*)0x4D)

#define  OCR1AH *((volatile unint8*)0x4B)

#define  OCR1AL *((volatile unint8*)0x4A)

#define  OCR1BL *((volatile unint8*)0x48)
#define  OCR1BH *((volatile unint8*)0x49)

#define  ICR1L *((volatile unint8*)0x46)
#define  ICR1H *((volatile unint8*)0x47)



#define  TCCR1A *((volatile unint8*)0x4F)    // timer/counter control register A

#define  TCCR1B *((volatile unint8*)0x4E)    // timer/counter control register B


#define  TIMSK *((volatile unint8*)0x59)    // timer/counter interrupt register 0


#define  TIFR *((volatile unint8*)0x58)    // timer/counter interrupt flag register 0

#define  SREG *((volatile unint8*)0x5F)    // global interrupt register



                     /*******************"BITS description"********************/

 /* _ timer/counter control register A&B BITS _ */

      /***********these three bits of clk_select ***********/
#define CS10  0
#define CS11  1
#define CS12  2

/*************** these 5 bits for control the mode ******************/

#define WGM11  1
#define WGM10  0
#define WGM12  3
#define WGM13  4

#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7
#define FOC1A   3
#define FOC1B   2


/*****************these two bits for control interrupt****************/

#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4


// flag bits

#define TOV1  2
#define OCF1B 3
#define OCF1A 4


//this bit of global interrupt control

#define GICB  7

// output compare zero pin  & port

#define OC1A  5
#define OC1B  4


#define OCDPT1 *((volatile unint8*)0X31)


#endif /* TIMER1_REGISTERS_H_ */
