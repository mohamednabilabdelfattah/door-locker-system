/*
 * app.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Mohamed Nabil AbdElfattah
 */

#include "MCAL/USART/uart.h"
#include "std_types.h"
#include "HAL/EEPROM/external_eeprom.h"
#include "HAL/Buzzer/buzzer.h"
#include "APP/app_functions.h"
#include<string.h>

/*definitions*/
#define PASSWORD_ADDRESS 100
#define PASSWORD_SIZE 5



/*communiacation commands*/
#define ERROR 0
#define CONFIRM 1
#define OPEN 2
#define CHANGE 3

/*variables*/
static volatile uint8 g_u8_wrongAttmepts;
int main(void)
{
	UART_init(9600);
	/*variables*/
	uint8 password[7],confirmPassword[7];
	while(1){
		/*receive the password the first time and checking if they are identical*/
		UART_receiveString(password);
		UART_receiveString(confirmPassword);
		/*check is identical*/
		if(!strcmp(password,confirmPassword))
		{
			/*they are identical*/

			/*will confirm the HMI ECU
			 * will store the password in the EEPROM
			 * */
			UART_sendByte(CONFIRM);
			EEPROM_writeString(PASSWORD_ADDRESS, password, PASSWORD_SIZE);
			break;
		}else{
			/*they aren't identical*/
			/*will refuse the request*/
			UART_sendByte(ERROR);
		}
	}


	/*main loop*/
	while(1){
		/*listen to any command*/
		switch(UART_recieveByte()){
		case OPEN:
			/*will read the entered password*/
			UART_receiveString(password);
			/*will get the password from EEPROM*/
			EEPROM_readString(PASSWORD_ADDRESS, confirmPassword, PASSWORD_SIZE);
			/*will compare them*/
			if(!strcmp(password,confirmPassword)){
				/*if they are identiacl will open the door and set wrongAttmepts to zero*/
				UART_sendByte(CONFIRM);
				/*[TODO]: implement open the door*/
				/*open the door*/
				openTheDoor();
				g_u8_wrongAttmepts = 0;
			}else{
				/*if not will return an error to HMI and increment the wrong attemepts*/
				UART_sendByte(ERROR);
				g_u8_wrongAttmepts++;
				/*if this were the third attempt will enable the alarm*/
				if(g_u8_wrongAttmepts==3){
					BUZZER_enable(1);
				}
			}
			break;
		case CHANGE:
			/*will read the entered password*/
			UART_receiveString(password);
			/*will get the password from EEPROM*/
			EEPROM_readString(PASSWORD_ADDRESS, confirmPassword, PASSWORD_SIZE);
			confirmPassword[6] = '\0';
			/*will compare them*/
			if(!strcmp(password,confirmPassword)){
				/*if they are identiacl will open the door and set wrongAttmepts to zero*/
				UART_sendByte(CONFIRM);
				/*will read the new password*/
				UART_receiveString(password);
				/*will update the password in the EEPROM*/
				EEPROM_writeString(PASSWORD_ADDRESS, password, PASSWORD_SIZE);
			}else{
				/*if not will return an error to HMI*/
				UART_sendByte(ERROR);
			}
			break;
		default:
			break;
		}
	}
}
