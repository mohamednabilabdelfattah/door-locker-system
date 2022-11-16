/**********************************************************************************************************************
 * [FILE] : GPIO.h
 * [Description] : header file of GPIO driver
 * [Author] : Mohamed Nabil
 * [Created at] : 5/10/2022
 * ********************************************************************************************************************/
#ifndef GPIO_H_
#define GPIO_H_

/**********************************************************************************************************************
 * INCLUDES
 * ********************************************************************************************************************/
#include "../../std_types.h"


/**********************************************************************************************************************
 * ENUMERATIOMS
 * ********************************************************************************************************************/
typedef enum{
	PIN_INPUT,
	PIN_OUTPUT
}GPIO_PinDirection;


typedef enum{
	PORT_INPUT,
	PORT_OUTPUT = 0xFF
}GPIO_PortDirection;


typedef enum{
	PORTA_ID,
	PORTB_ID,
	PORTC_ID,
	PORTD_ID
}GPIO_PortId;

typedef enum{
	PIN0_ID,
	PIN1_ID,
	PIN2_ID,
	PIN3_ID,
	PIN4_ID,
	PIN5_ID,
	PIN6_ID,
	PIN7_ID
}GPIO_PinId;

/**********************************************************************************************************************
 * functions
 * ********************************************************************************************************************/

/*
 * function name: GPIO_setupPinDirection
 * return type: void
 * params(in):GPIO_PortId ,GPIO_PinId ,GPIO_PinDirection
 * params(in&out): None
 * params(out): None
 * desciption: this function to setup direction of specific bit in specific port
 * */

 void GPIO_setupPinDirection(GPIO_PortId ,GPIO_PinId ,GPIO_PinDirection);


 /*
 * function name: GPIO_setupPortDirection
 * return type: void
 * params(in):GPIO_PortId ,GPIO_PortDirection
 * params(in&out): None
 * params(out): None
 * desciption: this function to setup direction of specific port
 * */

 void GPIO_setupPortDirection(GPIO_PortId ,GPIO_PortDirection);


/*
 * function name: GPIO_readPin
 * return type: GPIO_LogicStatus
 * params(in):GPIO_PortId ,GPIO_PinId
 * params(in&out): None
 * params(out): None
 * desciption: this function to read value of a pin
 * */

 uint8 GPIO_readPin(GPIO_PortId ,GPIO_PinId);

 /*
 * function name: GPIO_writePin
 * return type: void
 * params(in):GPIO_PortId,GPIO_PinId,GPIO_LogicStatus
 * params(in&out): None
 * params(out): None
 * desciption: this function to write value to a pin
 * */

void GPIO_writePin(GPIO_PortId ,GPIO_PinId,uint8);


/*
 * function name: GPIO_readPort
 * return type: uint8
 * params(in):GPIO_PortId ,GPIO_PinId
 * params(in&out): None
 * params(out): None
 * desciption: this function to read value of a port
 * */

uint8 GPIO_readPort(GPIO_PortId);


/*
 * function name: GPIO_writePort
 * return type: void
 * params(in):GPIO_PortId ,uint8 value
 * params(in&out): None
 * params(out): None
 * desciption: this function to write value of a port
 * */

void GPIO_writePort(GPIO_PortId ,uint8);
#endif
