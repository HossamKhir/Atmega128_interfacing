/*
 * GPIO.c
 *
 * Created: 18/07/2019 15:21:00
 *  Author: Hossam Khair
 */

#include "../inc/GPIO.h"

// PORT
void GPIO_write_pin(volatile void* reg, pin P, pin_value PIN_VAL)
{
	if(GPIOF == (struct gpiof*)reg)
	{
		switch (PIN_VAL)
		{
			case SET:
				SET_BIT(GPIOF->PORT,P);
			break;
			case RESET:
				CLR_BIT(GPIOF->PORT,P);
			break;
		}
	}
	else
	{
		GPIO* REG = (GPIO*)reg;
		switch (PIN_VAL)
		{
			case SET:
				SET_BIT(REG->PORT,P);
			break;
			case RESET:
				CLR_BIT(REG->PORT,P);
			break;
		}
	}


}

// DDR
void GPIO_set_pin_direction(volatile void* reg, pin P, pin_direction PIN_DIR)
{
	if(GPIOF == (struct gpiof*)reg)
	{
		switch (PIN_DIR)
		{
			case IN:
				CLR_BIT(GPIOF->DDR,P);
			break;
			case OUT:
				SET_BIT(GPIOF->DDR,P);
			break;
		}
	}
	else
	{
		GPIO* REG = (GPIO*)reg;
		switch (PIN_DIR)
		{
			case IN:
				CLR_BIT(REG->DDR,P);
			break;
			case OUT:
				SET_BIT(REG->DDR,P);
			break;
		}
	}
}

// PORT
void GPIO_enable_pullup(volatile void* reg, pin P)
{
	if(GPIOF == (struct gpiof*)reg)
	{
		SET_BIT(GPIOF->PORT,P);
	}
	else
	{
		GPIO* REG = (GPIO*)reg;
		SET_BIT(REG->PORT,P);
	}
}

// PIN
INT8U GPIO_read_pin(volatile void* reg, pin P)
{
	if(GPIOF == (struct gpiof*)reg)
	{
		return GET_BIT(GPIOF->PIN,P);
	}
	else
	{
		GPIO* REG = (GPIO*)reg;
		return GET_BIT(REG->PIN,P);
	}
}

// PORT
void GPIO_toggle_pin(volatile void* reg, pin P)
{
	if(GPIOF == (struct gpiof*)reg)
	{
		TOG_BIT(GPIOF->PORT,P);
	}
	else
	{
		GPIO* REG = (GPIO*)reg;
		TOG_BIT(REG->PORT,P);
	}
}
