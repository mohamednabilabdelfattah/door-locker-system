/**********************************************************************************************************************
 * [FILE] : GPIO.c
 * [Description] : source file of GPIO driver
 * [Author] : Mohamed Nabil
 * [Created at] : 5/10/2022
 * ********************************************************************************************************************/


/**********************************************************************************************************************
 * INCLUDES
 * ********************************************************************************************************************/
#include "../../std_types.h"
#include "../../common_macros.h"
#include <avr/io.h>
#include "gpio.h"


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

 void GPIO_setupPinDirection(GPIO_PortId portId,GPIO_PinId pinId,GPIO_PinDirection pinDirection)
 {
	volatile uint8* ptr;
	switch(portId)
	{
		case PORTA_ID:
			ptr = &DDRA;
			break;
		case PORTB_ID:
			ptr = &DDRB;
			break;
		case PORTC_ID:
			ptr = &DDRC;
			break;
		case PORTD_ID:
			ptr = &DDRD;
			break;
		default:
			break;
	}
	if(pinDirection == PIN_INPUT)
	{
		CLEAR_BIT(*ptr,pinId);
	}
	else
	{
		SET_BIT(*ptr,pinId);
	}
 }


 /*
 * function name: GPIO_setupPortDirection
 * return type: void
 * params(in):GPIO_PortId ,GPIO_PortDirection
 * params(in&out): None
 * params(out): None
 * desciption: this function to setup direction of specific port
 * */

 void GPIO_setupPortDirection(GPIO_PortId portID,GPIO_PortDirection portDirection)
 {
	 volatile uint8* ptr;
	 switch(portID)
	 {
			case PORTA_ID:
			ptr = &DDRA;
			break;
		case PORTB_ID:
			ptr = &DDRB;
			break;
		case PORTC_ID:
			ptr = &DDRC;
			break;
		case PORTD_ID:
			ptr = &DDRD;
			break;
		default:
			break;
	 }
	 *ptr = portDirection;
 }


/*
 * function name: GPIO_readPin
 * return type: GPIO_LogicStatus
 * params(in):GPIO_PortId ,GPIO_PinId
 * params(in&out): None
 * params(out): None
 * desciption: this function to read value of a pin
 * */

 uint8 GPIO_readPin(GPIO_PortId portId,GPIO_PinId pinId)
 {
	 volatile uint8* ptr;
	 switch(portId)
	 {
		 case PORTA_ID:
			ptr = &PINA;
			break;
		case PORTB_ID:
			ptr = &PINB;
			break;
		case PORTC_ID:
			ptr = &PINC;
			break;
		case PORTD_ID:
			ptr = &PIND;
			break;
		default:
			break;
	 }
	 return GET_BIT(*ptr,pinId);
 }

 /*
 * function name: GPIO_writePin
 * return type: void
 * params(in):GPIO_PortId,GPIO_PinId,GPIO_LogicStatus
 * params(in&out): None
 * params(out): None
 * desciption: this function to write value to a pin
 * */

void GPIO_writePin(GPIO_PortId portId,GPIO_PinId pinId,uint8 value)
{
	 volatile uint8* ptr;
	 switch(portId)
	 {
		 case PORTA_ID:
			ptr = &PORTA;
			break;
		case PORTB_ID:
			ptr = &PORTB;
			break;
		case PORTC_ID:
			ptr = &PORTC;
			break;
		case PORTD_ID:
			ptr = &PORTD;
			break;
		default:
			break;
	 }
	 if(value == LOGIC_HIGH){
		 SET_BIT(*ptr,pinId);
	 }
	 else{
		 CLEAR_BIT(*ptr,pinId);
	 }
}


/*
 * function name: GPIO_readPort
 * return type: uint8
 * params(in):GPIO_PortId ,GPIO_PinId
 * params(in&out): None
 * params(out): None
 * desciption: this function to read value of a port
 * */

uint8 GPIO_readPort(GPIO_PortId portId)
{
	volatile uint8* ptr;
	 switch(portId)
	 {
		 case PORTA_ID:
			ptr = &PINA;
			break;
		case PORTB_ID:
			ptr = &PINB;
			break;
		case PORTC_ID:
			ptr = &PINC;
			break;
		case PORTD_ID:
			ptr = &PIND;
			break;
		default:
			break;
	 }
	 return *ptr;
}


/*
 * function name: GPIO_writePort
 * return type: void
 * params(in):GPIO_PortId ,uint8 value
 * params(in&out): None
 * params(out): None
 * desciption: this function to write value of a port
 * */

void GPIO_writePort(GPIO_PortId portId,uint8 value)
{
	 volatile uint8* ptr;
	 switch(portId)
	 {
		 case PORTA_ID:
			ptr = &PORTA;
			break;
		case PORTB_ID:
			ptr = &PORTB;
			break;
		case PORTC_ID:
			ptr = &PORTC;
			break;
		case PORTD_ID:
			ptr = &PORTD;
			break;
		default:
			break;
	 }
	*ptr = value;
}
