/**********************************************************************************************************************
 * [FILE] : timer0_pwm.c
 * [Description] : source file of timer0_pwm driver
 * [Author] : Mohamed Nabil
 * [Created at] : 6/10/2022
 * ********************************************************************************************************************/



/**********************************************************************************************************************
 * INCLUDES
 * ********************************************************************************************************************/

#include "../../std_types.h"
#include "../../common_macros.h"
#include "../GPIO/GPIO.h"
#include <avr/io.h>

/**********************************************************************************************************************
 * functions prototypes
 * ********************************************************************************************************************/

/*
 * function name: PWM_Timer0_Start
 * return type: void
 * params(in): duty_cycle
 * params(in&out): None
 * params(out): None
 * desciption: this function to setup direction of specific bit in specific port
 * */

void PWM_Timer0_Start(uint8 duty_cycle)
{
	/*specify the mode of the timer with pwm*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	/*set the mode to non-inverting mode*/
	SET_BIT(TCCR0,COM01);

	/*set the prescalar*/
	SET_BIT(TCCR0,CS01);

	/*set the initial value of timer*/
	TCNT0 = 0;

	/*set the compare value based on the duty cycle*/
	OCR0 = (uint8)((uint16)(255*duty_cycle)/100);

	/*setup the direction of the pin of the timer 0 pwm*/
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);
}
