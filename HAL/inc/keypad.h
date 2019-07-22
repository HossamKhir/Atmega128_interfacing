/*
 * keypad.h
 *
 * Created: 22/07/2019 11:28:43
 *  Author: Hossam Khair
 */


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "GPIO.h"

#define KEYPAD_REG	GPIOD

void	key_init(void);
INT8U	key_getKey(void);
INT16U	key_scan(void);


#endif /* KEYPAD_H_ */
