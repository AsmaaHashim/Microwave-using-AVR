/*
 * timer1.h
 *
 *  Created on: Feb 19, 2020
 *      Author: Asmaa Hashim
 */

#ifndef TIMER1_H_
#define TIMER1_H_


#include "timer1_registers.h"

#include "avr/interrupt.h"

typedef enum{
		normal_T1 ,           // T1 means timer1
		phase_PWM_T_8BIT ,   // T means TOP
		phase_PWM_T_9BIT ,
		phase_PWM_T_10BIT ,
		CTC_T_OCR1A ,
        F_PWM_T_8BIT ,
		F_PWM_T_9BIT ,
		F_PWM_T_10BIT ,
		phase_PWM_T_ICR1=10,
		phase_PWM_T_OCR1A=11,
		CTC_T_ICR1 =12,
		F_PWM_T_ICR1=14 ,
		F_PWM_T_OCR1A=15 ,

		}Wave_generation_mode_T1;

typedef enum{OC1A_disconnect , Toggle_A , Clear_A , Set_A}CTC_STATE_A;

typedef enum{OC1B_disconnect , Toggle_B , Clear_B , Set_B}CTC_STATE_B;

typedef enum{
	NO_Clock_T1 ,
	CLOCK_DIV_1_T1 ,
	CLOCK_DIV_8_T1 ,
	CLOCK_DIV_64_T1 ,
	CLOCK_DIV_256_T1 ,
	CLOCK_DIV_1024_T1 ,
	External_CLK_Faling_Edge_T1,
	External_CLK_rising_Edge_T1,
}Clock_select_T1;

typedef enum{disable_OVFI_T1 , enable_OVI_T1}OVFI_state_T1;

typedef enum{disable_OCIA_T1 , enable_OCIA_T1}OCAI_state_T1;

typedef enum{disable_OCIB_T1 , enable_OCIB_T1}OCBI_state_T1;

typedef struct{

	Clock_select_T1 clock;

	Wave_generation_mode_T1 mode;

	CTC_STATE_A  OC1A_state;

	CTC_STATE_A  OC1B_state;

	OVFI_state_T1 T1_OVFI_state;

	OCAI_state_T1 T1_OCAI_state;

	OCBI_state_T1 T1_OCBI_state;

}timer1_config;


void timer1_init(timer1_config *data);

void set_TCNT1_val(unint16 val);

void set_OCR1A_val(unint16 val);

void set_OCR1B_val(unint16 val);

//void set_ICR1_val(unint16 *val);

void get_TCNT1_val(unint16 *val);

void get_OCR1A_val(unint16 *val);

void get_OCR1B_val(unint16 *val);

void get_ICR1_val(unint16 *val);



void timer1_callBack_OVFI(void (*ptr_fun)(void));

void timer1_callBack_OCIA(void (*ptr_fun)(void));

void timer1_callBack_OCIB(void (*ptr_fun)(void));


#endif /* TIMER1_H_ */
