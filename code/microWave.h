/*
 * microWave.h
 *
 *  Created on: Feb 16, 2020
 *      Author: Asmaa Hashim
 */

#ifndef MICROWAVE_H_
#define MICROWAVE_H_

#include "microWave_HW.h"

#include "LCD.h"            //used to display remaining time

#include "timer0.h"         // used to calculate the time

#include "timer1.h"         //used to generate pwm for the FAN

#include "keypad.h"        // used to enter the time

extern volatile unint16 minutes ;

extern volatile unint8   second;


                /*********************** '__' functions prototype  '__' ***********************/


void microWave_init(void);

unint8 start(void);             // there i will on the start led

unint8 stop(void);              // there i will off the start led

void start_LED_ON(void);

void start_LED_OFF(void);

void scan_minutes(void);

unint8 door_is_close();

unint8 door_is_open();

unint8 foodIsInMicro(void);         // wait there till button is pressed & then led will toggle its state

unint8 foodOutMicro(void);

void heat_on(void);

void heat_off(void);

void show_remaining_time(void);

void start_calc_time(void);

void stop_cal_time(void);

void FAN_ON(void);

void FAN_OFF(void);
























#endif /* MICROWAVE_H_ */
