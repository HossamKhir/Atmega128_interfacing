/*
 * GPIO.h
 *
 * Created: 18/07/2019 14:59:03
 *  Author: Hossam Khair
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "io_structure.h"
#include "../../Utility/bit_handle.h"

typedef enum PIN_VALUE{RESET, SET}pin_value;
typedef enum PIN_DIRECTION{IN, OUT}pin_direction;

typedef INT8U	pin;

// PORT
void GPIO_write_pin(volatile void* reg, pin P, pin_value PIN_VAL);
// DDR
void GPIO_set_pin_direction(volatile void* reg, pin P, pin_direction PIN_DIR);
// PORT
void GPIO_enable_pullup(volatile void* reg, pin P);
// PIN
INT8U GPIO_read_pin(volatile void* reg, pin P);
// PORT
void GPIO_toggle_pin(volatile void* reg, pin P);

#endif /* GPIO_H_ */
