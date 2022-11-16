/*
 * appFunctions.h
 *
 *  Created on: Nov 5, 2022
 *      Author: LENOVO
 */

#ifndef APP_APP_FUNCTIONS_H_
#define APP_APP_FUNCTIONS_H_

#include "../std_types.h"
/*structs*/
typedef enum{
	CLOSING,
	OPENING,
	HOLDING
}doorStatus;
/*functions*/
void readPassword(uint8* pass,uint8 size);
void openTheDoor(void);
void closeTheDoor(void);


#endif /* APP_APP_FUNCTIONS_H_ */
