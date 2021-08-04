/*
 * gpio_register.h
 *
 *  Created on: Feb 17, 2020
 *      Author: Asmaa Hashim
 */

#ifndef GPIO_REGISTER_H_
#define GPIO_REGISTER_H_



#include "data_types.h"

#define NULL (void*)0

#define DIR_OFFSET  (unint8)1

#define DATA_OFFSET  (unint8)2


  /***** this enum is used to define base address of  ports ******/


typedef enum {PORT_A=0x39 , PORT_B=0x36 , PORT_C=0x33  , PORT_D=0x30  }GPIO_port_type;


#endif /* GPIO_REGISTER_H_ */





