/*
 * appFunctions.c
 *
 *  Created on: Nov 5, 2022
 *      Author: LENOVO
 */

#include "app_functions.h"
#include "../HAL/motor/motor.h"
#include "../MCAL/timers/timer.h"
/*variables*/
static volatile uint8 ticks;
static volatile uint8 requiredTicks;
doorStatus statusOfTheDoor;

void openTheDoor(void){
	/*variables*/
	Timer1_ConfigType timerConfig = (Timer1_ConfigType){
		0,
		15625,
		CPU_64,
		Compare
	};
	/*setup timer for 15s*/
	requiredTicks = 12;
	Timer1_setCallBack(closeTheDoor);
	Timer1_init(&timerConfig);
	DcMotor_Init();
	DcMotor_Rotate(CW, 50);
	statusOfTheDoor = OPENING;
}
void closeTheDoor(void){
	if(ticks == requiredTicks && requiredTicks == 3){
		/*here will be called when the door is already holded 3s then will close it*/
		DcMotor_Init();
		DcMotor_Rotate(ACW, 50);
		ticks = 0;
		requiredTicks = 12;
		statusOfTheDoor = CLOSING;
	}
	else if(ticks == requiredTicks && requiredTicks == 12)
	{
		if(statusOfTheDoor == OPENING){
			/*here will be called when the door was being opened then will
			 * hold the door 3s  */
			ticks = 0;
			requiredTicks = 3;
			DcMotor_Rotate(STOP, 0);
			statusOfTheDoor = HOLDING;
		}
		else{
			/*here will be called when the door was being closed then will deinit
			 * the timer and motor  */
			Timer1_deInit();
			DcMotor_Rotate(STOP, 0);
			ticks = 0;
			requiredTicks = 3;
			statusOfTheDoor = HOLDING;
		}
	}
	else{
		ticks++;
	}
}
