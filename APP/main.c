/*
 * main.c
 *
 * Created: 17/07/2019 13:56:04
 *  Author: Hossam Khair
 */ 


#include <avr/io.h>
#include "io_structure.h"

int main(void)
{
	
	GPIOA->PORT = 55;
	
    while(1)
    {
        //YOLO:: You Only Live Once
    }
}