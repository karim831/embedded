#ifndef __BITS_OP__
#define __BITS_OP__


/*              MAIN_LOGIC          */

#define		LOW 					((Uint8)0x00)
#define		HIGH					((Uint8)0x01)

/*				MASING              */

#define		MASK0					((Uint8)0x01)
#define		MASK1					((Uint8)0x02)
#define		MASK2					((Uint8)0x04)
#define		MASK3					((Uint8)0x08)
#define		MASK4					((Uint8)0x10)
#define		MASK5					((Uint8)0x20)
#define		MASK6					((Uint8)0x40)
#define		MASK7					((Uint8)0x80)

/*              BIT_MANIPUTLATION_DECLARATION               */

#define		SET_BIT(REG,BIT_NO)		((REG)|= 1 << (BIT_NO))
#define 	CLEAR_BIT(REG,BIT_NO)	((REG)&= ~(1 << (BIT_NO)))
#define		TOGGLE_BIT(REG,BIT_NO)	((REG)^= 1 << (BIT_NO))
#define		READ_BIT(REG,BIT_NO)	(1 & ((REG) >> (BIT_NO)))

#endif
