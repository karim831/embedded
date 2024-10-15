#ifndef __BITS_OP__
#define __BITS_OP__


/*				MASING						*/

#define		MASK0					((uint8)0x01)
#define		MASK1					((uint8)0x02)
#define		MASK2					((uint8)0x04)
#define		MASK3					((uint8)0x08)
#define		MASK4					((uint8)0x10)
#define		MASK5					((uint8)0x20)
#define		MASK6					((uint8)0x40)
#define		MASK7					((uint8)0x80)

/*		bit manipulation declaration		*/
#define		SET_BIT(REG,BIT_NO)		(REG |= 1 << (BIT_NO))
#define 	CLEAR_BIT(REG,BIT_NO)	(REG &= ~(1 << (BIT_NO)))
#define		TOGGLE_BIT(REG,BIT_NO)	(REG ^= 1 << (BIT_NO))
#define		READ_BIT(REG,BIT_NO)	(1 & (REG >> (BIT_NO)))

#endif
