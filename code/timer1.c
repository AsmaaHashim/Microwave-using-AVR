/*
 * timer1.c
 *
 *  Created on: Feb 19, 2020
 *      Author: Asmaa Hashim
 */



#include "timer1.h"

static void (*CALL_BACK_PTR_OVF)(void)=NULL;
static void (*CALL_BACK_PTR_OCA)(void)=NULL;
static void (*CALL_BACK_PTR_OCB)(void)=NULL;


void timer1_init(timer1_config *data)
{

	TCCR1B |=(data->clock << CS10);    // configure the clock

	// these two line configure the mode
	TCCR1A |=((data->mode & 0X03) << WGM10);

	TCCR1B |=((data->mode << 1) & 0x18) ;

	TCCR1A |=(data->OC1A_state << COM1A0);

	TCCR1A |=(data->OC1B_state << COM1B0);

	TIMSK |= (data->T1_OVFI_state << TOIE1) | (data->T1_OCAI_state << OCIE1A ) \
			              | (data->T1_OCBI_state << OCIE1B);

	if(data->mode == normal_T1 || data->mode == CTC_T_OCR1A || data->mode == CTC_T_ICR1)
	 {
		TCCR1A |=(1 << FOC1A) | (1 << FOC1B);
	}

}

/**************_ Call Back functions _****************/
void timer1_callBack_OVFI(void (*ptr_fun)(void))
{

	CALL_BACK_PTR_OVF = ptr_fun;
	}

void timer1_callBack_OCIA(void (*ptr_fun)(void))
{
	CALL_BACK_PTR_OCA = ptr_fun;
	}

void timer1_callBack_OCIB(void (*ptr_fun)(void))
{
	CALL_BACK_PTR_OCB = ptr_fun;

}


/***************setter functions******************/
void set_OCR1A_val(unint16 val)
{
	OCR1AH = (val >> 8);
	 OCR1AL=(val & 0xff);
	}

void set_OCR1B_val(unint16 val)
{
	OCR1BH = (val >> 8) ;
	OCR1BL=(val & 0xff);

	}

//void set_ICR1_val(unint16 val)
//{
	//ICR1H = (val >> 8);
	//ICR1L = (val & 0x00ff);

//}

void set_TCNT1_val(unint16 val)
{

	TCNT1H = (val >> 8);
	TCNT1L = (val & 0x00ff);
}

/***************getter functions******************/

void get_TCNT1_val(unint16 *val)
{
	*val = TCNT1L;
	*val = *val | ((unint16)TCNT1H << 8) ;

	}


void get_OCR1A_val(unint16 *val)
{
	*val = OCR1AL;
	*val = *val | ((unint16)OCR1AH << 8) ;
}

void get_OCR1B_val(unint16 *val)
{
	*val = OCR1BL;
	*val = *val | ((unint16)OCR1BH << 8) ;
	}

void get_ICR1_val(unint16 *val)
{

	*val = ICR1L;
	*val = *val | ((unint16)ICR1H << 8) ;

}

/***************************interrupt service routine ***************************/
ISR(TIMER1_OVF_vect)
{
	if(CALL_BACK_PTR_OVF != NULL)
	{
	CALL_BACK_PTR_OVF();
	}

}

ISR(TIMER1_COMPA_vect)
{
	if(CALL_BACK_PTR_OCA != NULL)
		{
		CALL_BACK_PTR_OCA();
		}

	}
ISR(TIMER1_COMPB_vect)
{
	if(CALL_BACK_PTR_OCB != NULL)
		{
		CALL_BACK_PTR_OCB();
		}


}
