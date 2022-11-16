/*
 * app.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Mohamed Nabil AbdElfattah
 */


#include <avr/io.h>
#include <util/delay.h>
#include "HAL/LCD/lcd.h"
#include "HAL/keypad/keypad.h"
#include "APP/app_functions.h"
#include "MCAL/USART/uart.h"
#include "std_types.h"
#include <string.h>

/*definitions*/
#define PASSWORD_SIZE 5

/*communiacation commands*/
#define ERROR 0
#define CONFIRM 1
#define OPEN 2
#define CHANGE 3


int main(void)
{
	UART_init(9600);
	/*variables*/
	uint8 password[7],confirmPassword[7];
	/*init the peripherals and external devices*/
	LCD_init();
	/*read the password first time*/
	do{
		LCD_clearScreen();
		LCD_displayStringRowColumn(0, 0, "plz enter pass :");
		LCD_displayStringRowColumn(1, 0, "");
		readPassword(password,5);
		password[5] = '#';password[6] = '\0';
		UART_sendString(password);
		LCD_displayStringRowColumn(0, 0, "plz re-enter the ");
		LCD_displayStringRowColumn(1, 0, "same pass:");
		readPassword(confirmPassword,5);
		confirmPassword[5] = '#';confirmPassword[6] = '\0';
		UART_sendString(confirmPassword);
	}while(UART_recieveByte()!=CONFIRM);


	/*clear the screen*/
	LCD_clearScreen();
	/*main loop*/
	while(1){
		/*variables*/
		uint8 choice;
		uint8 enteredPassword[7];
		/*display the options to the user*/
		LCD_displayStringRowColumn(0, 0, "+ : Open Door");
		LCD_displayStringRowColumn(1, 0, "- : Change Pass");
		choice = KEYPAD_getPressedKey();
		if(choice=='+'){
			do{
				/*request from the control ECU to open*/
				UART_sendByte(OPEN);
				/*request the user to open the password*/
				LCD_clearScreen();
				LCD_displayStringRowColumn(0, 0, "plz enter pass :");
				LCD_displayStringRowColumn(1, 0, "");
				readPassword(enteredPassword, 5);
				enteredPassword[5] = '#';
				enteredPassword[6] = '\0';
				/*send the password to the contorl ECU*/
				UART_sendString(enteredPassword);
			}while(UART_recieveByte() != CONFIRM);
		}else if(choice == '-'){
			do{
				/*send the request to the control ECU*/
				UART_sendByte(CHANGE);
				/*read the old password*/
				LCD_clearScreen();
				LCD_displayStringRowColumn(0, 0, "plz enter pass :");
				LCD_displayStringRowColumn(1, 0, "");
				readPassword(enteredPassword, 5);
				enteredPassword[5] = '#';
				enteredPassword[6] = '\0';
				/*send the old password to control ECU*/
				UART_sendString(enteredPassword);
				/*wait until the password is correct*/
			}while(UART_recieveByte()!=CONFIRM);
			/*if it's true password then will read the new Password*/
			LCD_clearScreen();
			LCD_displayStringRowColumn(0, 0, "enter new pass :");
			LCD_displayStringRowColumn(1, 0, "");
			readPassword(password, PASSWORD_SIZE);
			enteredPassword[5] = '#';
			enteredPassword[6] = '\0';
			/*send it to the control ECU*/
			UART_sendString(password);
		}

	}
}
