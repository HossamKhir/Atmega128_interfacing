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

typedef enum PIN_VALUE{RESET, SET}pin_value;
typedef enum PIN_DIRECTION{IN, OUT}pin_direction;

typedef INT8U	pin;

// PORT
void GPIO_write_pin(GPIO* reg, pin P, pin_value PIN_VAL);
// DDR
void GPIO_set_pin_direction(GPIO* reg, pin P, pin_direction PIN_DIR);
// PORT
void GPIO_enable_pullup(GPIO* reg, pin P);
// PIN
INT8U GPIO_read_pin(GPIO* reg, pin P);
// PORT
void GPIO_toggle_pin(GPIO* reg, pin P);

#endif /* GPIO_H_ */
