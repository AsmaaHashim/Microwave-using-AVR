/*
 * timer0.c
 *
 *  Created on: Feb 16, 2020
 *      Author: Asmaa Hashim
 */



#include "timer0.h"

void (*CallBack_ptr_OVF)(void) = NULL;

void (*CallBack_ptr_OC)(void) = NULL;

                    /************functions defination ***************/

void timer0_init(timer0_configer *data)
{

	if(data->t0_mode != phase_correct_PWM_T0 || data->t0_mode != F_PWM_T0)
	{
		TCCR0 |=(1 << FOC0);
	}

	TCCR0 |=((data->t0_mode << WGM01) | (data->t0_mode << WGM00)) & 0XCF ;

	TCCR0 |=(data->OC0_state << COM00);

	TCCR0 |=(data-> clock);

	TIMSK |=(data->TOVFI_state) | (data->TOCI_state << OCIE0);

	if(data->OC0_state != OC0_disconnect_T0)         // configure OC0 pin as output pin
	{
		OCDP |=(1<<OC0);
	}


}


void set_TCCR0_val(unint8 val)
{
	TCNT0 = val;
}

void set_OCR0_val(unint8 val)
{
	OCR0 = val;
}

void timer0_callBack_OVFI(void (*ptr_fun)(void))
{
	CallBack_ptr_OVF = ptr_fun;

}

void timer0_callBack_OCI(void (*ptr_fun)(void))
{
	CallBack_ptr_OC = ptr_fun;
}

                   /*************** ISR functions        ****************/

ISR(TIMER0_OVF_vect)
{
	if(CallBack_ptr_OVF != NULL)
	{
		CallBack_ptr_OVF();
	}
}

ISR(TIMER0_COMP_vect)
{
	if(CallBack_ptr_OC != NULL)
	{
		CallBack_ptr_OC();
	}
}

