/*
 * microWave_HW.h
 *
 *  Created on: Feb 17, 2020
 *      Author: Asmaa Hashim
 */

#ifndef MICROWAVE_HW_H_
#define MICROWAVE_HW_H_

#include "gpio_register.h"

// start button port & pin
#define START_BUTTON_DIR_PORT *((volatile unint8*)PORT_B + DIR_OFFSET)

#define START_BUTTON_DATA_PORT *((volatile unint8*)PORT_B + DATA_OFFSET)

#define START_BUTTON_READ_PORT *((volatile unint8*)PORT_B)

#define START_BUTTON_PIN  0

//stop port pin & port

#define STOP_BUTTON_DIR_PORT *((volatile unint8*)PORT_B + DIR_OFFSET)

#define STOP_BUTTON_DATA_PORT *((volatile unint8*)PORT_B + DATA_OFFSET)

#define STOP_BUTTON_READ_PORT *((volatile unint8*)PORT_B)


#define STOP_BUTTON_PIN  1

//HEAT port pin & port

#define HEAT_DIR_PORT *((volatile unint8*)PORT_B + DIR_OFFSET)
#define HEAT_DATA_PORT *((volatile unint8*)PORT_B + DATA_OFFSET)
#define HEAT_PIN  2

//FAN port pin & port

#define FAN_DIR_PORT *((volatile unint8*)PORT_B + DIR_OFFSET)
#define FAN_DATA_PORT *((volatile unint8*)PORT_B + DATA_OFFSET)
#define FAN_PIN_1  5
#define FAN_PIN_2  6

//start lamp port pin & port

#define LAMP_DIR_PORT *((volatile unint8*)PORT_B + DIR_OFFSET)
#define LAMP_DATA_PORT *((volatile unint8*)PORT_B + DATA_OFFSET)
#define LAMP_PIN  3

//DOOR button & led ----->>> port & pin

#define DOOR_BUTTON_DIR_PORT  *((volatile unint8*)PORT_D + DIR_OFFSET)

#define DOOR_BUTTON_DATA_PORT  *((volatile unint8*)PORT_D + DATA_OFFSET)

#define DOOR_BUTTON_READ_PORT  *((volatile unint8*)PORT_D )


#define DOOR_LED_DIR_PORT    *((volatile unint8*)PORT_D + DIR_OFFSET)
#define DOOR_LED_DATA_PORT    *((volatile unint8*)PORT_D + DATA_OFFSET)

#define DOOR_BUTTON_PIN  3
#define DOOR_LED_PIN     7


//weight button & led ----->>> port & pin

#define WEIGHT_BUTTON_DIR_PORT  *((volatile unint8*)PORT_D + DIR_OFFSET)

#define WEIGHT_BUTTON_DATA_PORT  *((volatile unint8*)PORT_D + DATA_OFFSET)

#define WEIGHT_BUTTON_READ_PORT  *((volatile unint8*)PORT_D )


#define WEIGHT_LED_DIR_PORT    *((volatile unint8*)PORT_D + DIR_OFFSET)
#define WEIGHT_LED_DATA_PORT    *((volatile unint8*)PORT_D + DATA_OFFSET)

#define WEIGHT_BUTTON_PIN  4
#define WEIGHT_LED_PIN     6








#endif /* MICROWAVE_HW_H_ */
