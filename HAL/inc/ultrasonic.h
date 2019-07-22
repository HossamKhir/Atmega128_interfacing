#ifndef _ULTRASONIC_H
#define _ULTRASONIC_H

#include "../../MCAL/inc/GPIO.h"
#include "../../Utility/interrupt.h"

#define US_TRIG	0
#define US_ECHO	1

#define US_GPIO	GPIOD

void US_init(void);	// initialise trigger & echo pins, and timer to be used
void US_PULSE(void);	// handles the action of triggering, delaying, de-triggering & timer start

// function to calculate distance, probably would be called from ISR
INT32U distance(INT32U time);


#endif
