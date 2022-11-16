/**********************************************************************************************************************
 * [FILE] : motor.c
 * [Description] : source file of motor driver
 * [Author] : Mohamed Nabil
 * [Created at] : 6/10/2022
 * ********************************************************************************************************************/


/**********************************************************************************************************************
 * INCLUDES
 * ********************************************************************************************************************/
#include "../../std_types.h"
#include "../../common_macros.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "motor.h"
#include "../../MCAL/timer0_pwm/timer0_pwm.h"


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
void DcMotor_Init(void)
{
	/*setup the direction of the two pins of the motor*/
	GPIO_setupPinDirection(MOTOR_PORT, MOTOR_PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT, MOTOR_PIN2_ID, PIN_OUTPUT);

	/*stop the motor*/
	GPIO_writePin(MOTOR_PORT, MOTOR_PIN1_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT, MOTOR_PIN2_ID, LOGIC_LOW);
}

/*
 * function name: DcMotor_Rotate
 * return type: void
 * params(in): state, speed
 * params(in&out): None
 * params(out): None
 * desciption: The Function responsible for setup the direction for the two motor pins through the GPIO driver
 * */

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	switch (state)
	{
	case CW:
		GPIO_writePin(MOTOR_PORT, MOTOR_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT, MOTOR_PIN2_ID, LOGIC_HIGH);
		break;
	case ACW:
		GPIO_writePin(MOTOR_PORT, MOTOR_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT, MOTOR_PIN2_ID, LOGIC_LOW);
		break;
	case STOP:
		GPIO_writePin(MOTOR_PORT, MOTOR_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT, MOTOR_PIN2_ID, LOGIC_LOW);
		break;
	}
	PWM_Timer0_Start(speed);
}
