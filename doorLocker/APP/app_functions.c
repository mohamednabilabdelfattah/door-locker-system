/*
 * appFunctions.c
 *
 *  Created on: Nov 5, 2022
 *      Author: LENOVO
 */

#include "app_functions.h"
#include "../HAL/keypad/keypad.h"
#include "../HAL/LCD/lcd.h"
#include "../MCAL/timers/timer.h"
/*variables*/
uint8 ticks;
uint8 requiredTicks;
doorStatus statusOfTheDoor;
void readPassword(uint8* pass,uint8 size){
	uint8 index = 0;

	while(index < size){
		pass[index] = KEYPAD_getPressedKey();
		LCD_displayCharacter('*');
		index++;
	}
}
