#ifndef __BITS_OP__
#define __BITS_OP__

/*		bit manipulation declaration		*/
#define		SET_BIT(REG,BIT_NO)		(REG |= 1 << (BIT_NO))
#define 	CLEAR_BIT(REG,BIT_NO)	(REG &= ~(1 << (BIT_NO)))
#define		TOGGLE_BIT(REG,BIT_NO)	(REG ^= 1 << (BIT_NO))
#define		READ_BIT(REG,BIT_NO)	(1 & (REG >> (BIT_NO)))

#endif
