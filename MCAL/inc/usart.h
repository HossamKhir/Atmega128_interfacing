#ifndef _USART_H
#define _USART_H

#include "../../Utility/data_types.h"

struct ucsrc {
	INT8U UCPOL	:1;
	INT8U UCSZ	:2;
	INT8U USBS	:1;
	INT8U UPM	:2;
	INT8U UMSEL	:1;
};

struct ucsrb{
	// UCSRxB
	INT8U TXB	:1;
	INT8U RXB	:1;
	INT8U UCSZ	:1;
	INT8U TXEN	:1;
	INT8U RXEN	:1;
	INT8U UDRIE	:1;
	INT8U TXCIE	:1;
	INT8U RXCIE	:1;
};

struct ucsra{
	INT8U MPCM	:1;
	INT8U U2X	:1;
	INT8U UPE	:1;
	INT8U DOR	:1;
	INT8U FE	:1;
	INT8U UDRE	:1;
	INT8U TXC	:1;
	INT8U RXC	:1;
};

struct ucsr1{
	struct ucsrb B;
	struct ucsra A;
	const INT8U reserved;
	struct ucsrc C;
};

struct ucsr0{
	struct ucsrb B;
	struct ucsra A;
	const INT8U reserved[104];
	struct ucsrc C;
};


struct ubrr1{
	INT8U H				:4;
	const INT8U pads	:4;
	INT8U L;
};

struct ubrr0{
	INT8U L;
	const INT8U reserved[101];
	INT8U H	:4;
};

#define UDR0	*((volatile INT8U*)(0x2C))
#define UDR1	*((volatile INT8U*)(0x9C))
#define UCSR1	((volatile struct ucsr1*)(0x9A))
#define UCSR0	((volatile struct ucsr0*)(0x2A))
#define UBRR1	((volatile struct ubrr0*)(0x98))
#define UBBR0	((volatile struct ubrr1*)(0x29))

#endif
