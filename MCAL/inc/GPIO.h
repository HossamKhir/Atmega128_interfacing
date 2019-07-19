/*
 * GPIO.h
 *
 * Created: 18/07/2019 14:59:03
 *  Author: Hossam Khair
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "io_structure.h"
#include "bit_handle.h"

enum PIN_VALUE{
	RESET, SET
	}pin_value;
enum PIN_DIRECTION{
	IN, OUT
	}pin_direction;

typedef INT8U	pin;

// PORT
void GPIO_write_pin(GPIO* REG, pin PIN, pin_value PIN_VAL);
// DDR
void GPIO_set_pin_direction(GPIO* REG, pin PIN, pin_direction PIN_DIR);
// PORT
void GPIO_enable_pullup(GPIO* REG, pin PIN);
// PIN
INT8U GPIO_read_pin(GPIO* REG, pin PIN);
// PORT
void GPIO_toggle_pin(GPIO* REG, pin PIN);

#endif /* GPIO_H_ */