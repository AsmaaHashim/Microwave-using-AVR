/*
 * timer0.h
 *
 *  Created on: Feb 16, 2020
 *      Author: Asmaa Hashim
 */

#ifndef TIMER0_H_
#define TIMER0_H_

#include "timer0_register.h"

#include<avr/interrupt.h>


#define NULL (void*)0


                     /********************ENUMS *********************/

typedef enum{normal_T0 , phase_correct_PWM_T0 , CTC_T0 , F_PWM_T0}Wave_generation_mode_T0;

typedef enum{OC0_disconnect_T0 , Toggle_T0 , Clear_T0 , Set_T0}compar_match_out_mode_T0;

typedef enum{
	NO_Clock_T0 ,
	CLOCK_DIV_1_T0 ,
	CLOCK_DIV_8_T0 ,
	CLOCK_DIV_64_T0 ,
	CLOCK_DIV_256_T0 ,
	CLOCK_DIV_1024_T0 ,
	External_CLK_Faling_Edge_T0 ,
	External_CLK_rising_Edge_T0  ,
}Clock_select_T0;

typedef enum{disable_OVFI_T0 , enable_OVI_T0}OVFI_state_T0;

typedef enum{disable_OCI_T0 , enable_OCI_T0}OCI_state_T0;

typedef struct{
	Clock_select_T0 clock;
	Wave_generation_mode_T0 t0_mode;
	compar_match_out_mode_T0 OC0_state;
	OVFI_state_T0  TOVFI_state;
	OCI_state_T0 TOCI_state;

}timer0_configer;

                       /****************functions prototype *******************/

void timer0_init(timer0_configer *data);

void set_TCNT0_val(unint8 val);

void set_OCR0_val(unint8 val);

void timer0_callBack_OVFI(void (*ptr_fun)(void));

void timer0_callBack_OCI(void (*ptr_fun)(void));


#endif /* TIMER0_H_ */
