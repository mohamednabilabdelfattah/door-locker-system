/*
 * buzzer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: LENOVO
 */


#include "buzzer.h"
/*variables*/
uint8 ticks;
uint8 requiredTicks;
/*includes*/
#include"../../MCAL/GPIO/GPIO.h"
#include"../../MCAL/timers/timer.h"
/*functions definitions*/
void BUZZER_init(void){
	/*setup the pin direction as output*/
	GPIO_setupPinDirection(BUZZER_PORT, BUZZER_PIN, PIN_OUTPUT);
}
void BUZZER_enable(uint8 time)
{
	/*variables*/
	Timer1_ConfigType timer1Conf = (Timer1_ConfigType){
		0,/*initial value*/
		(uint16) 65535,  /*to count 1ms*/
		CPU_8,
		Compare
	};
	/*setup the required ticks*/
	requiredTicks = 16*time;
	/*setup the timer*/
	Timer1_setCallBack(BUZZER_disable);
	Timer1_init(&timer1Conf);
	/*turn on the buzzer*/
	GPIO_writePin(BUZZER_PORT, BUZZER_PORT, LOGIC_HIGH);
}

void BUZZER_disable(void)
{
	if(ticks==requiredTicks){
		/*turnoff the buzzer*/
		GPIO_writePin(BUZZER_PORT,BUZZER_PIN,LOGIC_LOW);
		/*deinit the timer*/
		Timer1_deInit();
	}
	else{
		ticks++;
	}
}
