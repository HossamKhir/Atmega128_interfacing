#ifndef _INTERRUPT_H
#define _INTERRUPT_H

//status register
//#define SREG	(*(volatile char*)(0x00))

//external interrupts
//Exteranl Interrupt Control Register
//#define EICRA	(*(volatile char*)(0x00))
//#define EICRB	(*(volatile char*)(0x00))
//Interrupt Sense Control
typedef enum ISC{
	D00, D01, D10, D11, D20, D21, D30, D31
}isc;

//External Interrupt MaSK register
//#define EIMSK	(*(volatile char*)(0x00))
//interrupt
typedef enum interrupt{
	i0, i1, i2, i3, i4, i5, i6, i7
}INT;

//External Interrupt Flag Register
//#define EIFR	(*(volatile char*)(0x00))
//interrupt flag
typedef enum INTF{
	f0, f1, f2, f3, f4, f5, f6, f7
}intf;

#endif
