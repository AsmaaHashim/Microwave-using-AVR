/*
 * std_macros.h
 *
 *  Created on: Feb 16, 2020
 *      Author: Asmaa Hashim
 */

#ifndef STD_MACROS_H_
#define STD_MACROS_H_


#include "data_types.h"

#define SET_BIT(reg , bit)  ( reg |=(unint8)1 << bit )

#define CLEAR_BIT(reg , bit )  (reg &=~((unint8)1  << bit))

#define READ_BIT(REG , BIT) (REG & (1 << BIT))

#define TOGGLE_BIT(REG , BIT) (REG ^=((unint8)1 << BIT))


#endif /* STD_MACROS_H_ */
