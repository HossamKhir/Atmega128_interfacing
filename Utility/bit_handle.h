/*
 * bit_handle.h
 *
 * Created: 18/07/2019 11:14:18 
 *  Author: Hossam Khair
 */ 


#ifndef BIT_HANDLE_H_
#define BIT_HANDLE_H_

#define SET_BIT(REG,BIT)	(REG |= (1<<BIT))
#define CLR_BIT(REG,BIT)	(REG &= ~(1<<BIT))
#define TOG_BIT(REG,BIT)	(REG ^= (1<<BIT))
#define GET_BIT(REG,BIT)	((REG>>BIT) & (1))

#define SET_BITS(REG,MASK)	(REG |= (MASK))
#define CLR_BITS(REG,MASK)	(REG &= ~(MASK))
#define TOG_BITS(REG,MASK)	(REG ^= (MASK))
#define GET_BITS(REG,MASK)	(REG & (MASK))

#define SET_BYTE(REG)	(REG = 0xFF)
#define CLR_BYTE(REG)	(REG = ~0xFF)
#define TOG_BYTE(REG)	(REG ^= 0xFF)
#define GET_BYTE(REG)	(REG & 0xFF)







#endif /* BIT_HANDLE_H_ */