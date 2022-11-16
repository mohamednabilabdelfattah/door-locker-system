 /******************************************************************************
 *
 * Module: ICU
 *
 * File Name: Timer.c
 *
 * Description: Source file for the AVR Timer1 driver
 *
 * Author: Mohamed Nabil
 *
 * Date created : 29/10/2022
 *
 *******************************************************************************/
 
#include "timer.h"
#include "../../common_macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/*******************************************************************************
 *                      Global Variables                                        *
 *******************************************************************************/
 
static volatile void (*g_callBackPtr)(void) = NULL_PTR;  /*the pointer of the callback function*/
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description : Function to initialize the TIMER1 driver
 * 1. set the mode
 * 2. initial value of compare mode
 * 3. enable the mode interrupt
 * 4. set prescalar
 */
void Timer1_init(const Timer1_ConfigType * Config_Ptr){
	/*set the mode*/
	TCCR1B = (TCCR1B & 0xF7) | (Config_Ptr->mode<<WGM12);
	/*set the initial value */
	TCNT1 = Config_Ptr -> initial_value;
	/*set the compare value in case of compare mode*/
	if(Config_Ptr -> mode)
	{
		OCR1A = Config_Ptr -> compare_value;
		/*enable the interrupt*/
		SET_BIT(TIMSK,OCIE1A);
	}else{
		/*enable the interrupt*/
		SET_BIT(TIMSK,TOIE1);
	}
	/*set the prescalar*/
	TCCR1B = (TCCR1B & 0xF8) | (Config_Ptr -> prescaler);
}
/*
 * Description : Function to deinit the TIMER1 driver
 *  . disable the clock of the timer and intertupts
 */
void Timer1_deInit(void){
	/*disable the clock*/
	TCCR1B = (TCCR1B & 0xF8);
	/*disable the interrupt*/
	CLEAR_BIT(TIMSK,OCIE1A);
	CLEAR_BIT(TIMSK,TOIE1);
}
/*
 * Description : Function to set the TIMER1 call back
 */
void Timer1_setCallBack(void(*a_ptr)(void)){
	g_callBackPtr = a_ptr;
}
/*******************************************************************************
 *                      ISRs implementations                                   *
 *******************************************************************************/

ISR(TIMER1_COMPA_vect){
	/*call the callback function*/
	(*g_callBackPtr)();
}
ISR(TIMER1_OVF_vect){
	/*call the callback function*/
	(*g_callBackPtr)();
}
