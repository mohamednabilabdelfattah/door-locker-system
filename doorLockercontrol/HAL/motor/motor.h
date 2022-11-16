/**********************************************************************************************************************
 * [FILE] : motor.h
 * [Description] : header file of dc motor driver
 * [Author] : Mohamed Nabil
 * [Created at] : 6/10/2022
 * ********************************************************************************************************************/


#ifndef MOTOR_H_
#define MOTOR_H_

/**********************************************************************************************************************
 * INCLUDES
 * ********************************************************************************************************************/
#include "../../std_types.h"

/**********************************************************************************************************************
 * DEFINITIONS
 * ********************************************************************************************************************/
#define MOTOR_PORT PORTB_ID
#define MOTOR_PIN1_ID 1
#define MOTOR_PIN2_ID 2

/**********************************************************************************************************************
 * ENUMERATIOMS
 * ********************************************************************************************************************/
typedef enum{
	CW,
	ACW,
	STOP
}DcMotor_State;



/**********************************************************************************************************************
 * functions prototypes
 * ********************************************************************************************************************/

/*
 * function name: DcMotor_Init
 * return type: void
 * params(in):void
 * params(in&out): None
 * params(out): None
 * desciption: this function to setup direction of specific bit in specific port
 * */
void DcMotor_Init(void);

/*
 * function name: DcMotor_Rotate
 * return type: void
 * params(in): state, speed
 * params(in&out): None
 * params(out): None
 * desciption: The Function responsible for setup the direction for the two motor pins through the GPIO driver
 * */

void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* MOTOR_H_ */
