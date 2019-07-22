/*
 * adc.h
 *
 * Created: 22/07/2019 15:53:11 
 *  Author: Hossam Khair
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "io_structure.h"
#include "bit_handle.h"

void ADC_init(INT8U channel);
INT16U ADC_read(void);


#endif /* ADC_H_ */