/*
 * GPIO.c
 *
 * Created: 18/07/2019 15:21:00
 *  Author: Hossam Khair
 */ 

#include "GPIO.h"

// PORT
void GPIO_write_pin(GPIO* REG, pin PIN, pin_value PIN_VAL)
{
	switch (PIN_VAL)
	{
		case SET:
			SET_BIT(REG->PORT,PIN);
		break;
		case RESET:
			CLR_BIT(REG->PORT,PIN);
		break;
	}
}

// DDR
void GPIO_set_pin_direction(GPIO* REG, pin PIN, pin_direction PIN_DIR)
{
	switch (PIN_DIR)
	{
		case IN:
			CLR_BIT(REG->DDR,PIN);
		break;
		case OUT:
			SET_BIT(REG->DDR,PIN);
		break;
	}
}

// PORT
void GPIO_enable_pullup(GPIO* REG, pin PIN)
{
	SET_BIT(REG->PORT,PIN);
}

// PIN
INT8U GPIO_read_pin(GPIO* REG, pin PIN)
{
	return 0;
}
// PORT
void GPIO_toggle_pin(GPIO* REG, pin PIN)
{
	
}
