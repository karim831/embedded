#ifndef __IO_REG_H__
#define __IO_REG_H__



/* 			MAPPING	I/O	REGISTERS IN DATA MEMORY			*/

#define		__MAP(ADR)	((volatile uint8 *)(ADR + 0x20))


/*				I/O REGISTERS DECLARATION					*/

#define		PORTA		__MAP(0x1B)
#define		DDRA		__MAP(0x1A)
#define		PINA		__MAP(0x19)

#define 	PORTB		__MAP(0x18)
#define		DDRB		__MAP(0x17)
#define		PINB		__MAP(0x16)

#define		PORTC		__MAP(0x15)
#define		DDRC		__MAP(0x14)
#define		PINC		__MAP(0x13)

#define		PORTD		__MAP(0x12)
#define		DDRD		__MAP(0x11)
#define		PIND		__MAP(0x10)


#endif 
