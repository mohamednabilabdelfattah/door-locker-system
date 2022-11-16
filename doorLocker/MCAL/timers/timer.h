/**********************************************************************************************************
*FILE: timer.h
*Module: timer1 
*author: Mohamed Nabil
*date created: 29/10/2022
**********************************************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_
#include "../../std_types.h"
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
 typedef enum{
	 OFF,
	 CPU,
	 CPU_8,
	 CPU_64,
	 CPU_256,
	 CPU_1024
 } Timer1_Prescaler;
 
 
 typedef enum{
	 Overflow,
	 Compare
 }Timer1_Mode;
 
 
 typedef struct{
	uint16 initial_value;
	uint16 compare_value; // it will be used in compare mode only.
	Timer1_Prescaler prescaler;
	Timer1_Mode mode;
 }Timer1_ConfigType;
 
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
void Timer1_init(const Timer1_ConfigType * Config_Ptr);


/*
 * Description : Function to deinit the TIMER1 driver
 *  . disable the clock of the timer
 */
void Timer1_deInit(void);
/*
 * Description : Function to set the TIMER1 call back
 *  set the callback of the timer
 */
void Timer1_setCallBack(void(*a_ptr)(void));


#endif
