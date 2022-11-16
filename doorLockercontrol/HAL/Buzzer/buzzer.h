/*
 * buzzer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: LENOVO
 */

#ifndef HAL_BUZZER_BUZZER_H_
#define HAL_BUZZER_BUZZER_H_
/*includes*/
#include "../../std_types.h"
/*definitions*/
#define BUZZER_PORT PORTA_ID
#define BUZZER_PIN PIN0_ID
/*functions*/
void BUZZER_init(void);
void BUZZER_enable(uint8 time);
void BUZZER_disable(void);

#endif /* HAL_BUZZER_BUZZER_H_ */
