/*
 * io_structure.h
 *
 * Created: 17/07/2019 14:59:36
 *  Author: Hossam Khair
 */ 


#ifndef IO_STURCTURE_H
#define IO_STURCTURE_H

#include "avr/io.h"
#include "data_types.h"


typedef struct gpio {
	INT8U PIN;
	INT8U DDR;
	INT8U PORT;
	}GPIO;

#define GPIOA	((volatile GPIO*)(0x39))


#endif /* IO_STURCTURE_H */