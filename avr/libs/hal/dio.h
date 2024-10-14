#ifndef __DIO_H__
#define __DIO_H__

/*						INCLUDES							*/
#include "../stdlibs/io_reg.h"
#include "../stdlibs/stdtypes.h"
#include "../stdlibs/bits_op.h"


/*					DIO	MACRO DECLARATION					*/


#define			DIO_PORTA			((uint8)0x00)
#define			DIO_PORTB			((uint8)0x01)
#define			DIO_PORTC			((uint8)0x02)
#define			DIO_PORTD			((uint8)0x03)

#define			DIO_PIN0			((uint8)0x00)
#define			DIO_PIN1			((uint8)0x01)
#define			DIO_PIN2			((uint8)0x02)
#define			DIO_PIN3			((uint8)0x03)
#define			DIO_PIN4			((uint8)0x04)
#define			DIO_PIN5			((uint8)0x05)
#define			DIO_PIN6			((uint8)0x06)
#define			DIO_PIN7			((uint8)0x07)

#define			DIO_EMPTY_REG		((uint8)0x00)
#define			DIO_FULL_REG		((uint8)0xFF)

/*					DIO DRIVERS DECLARATION					*/

/*
	parameter 1 for port,
	parameter 2 for pin
*/

no_ret	  dio_pin_input(uint8, uint8);
no_ret	  dio_pin_input_pullup(uint8, uint8);
no_ret	  dio_pin_output_low(uint8, uint8);
no_ret	  dio_pin_output_high(uint8, uint8); 
no_ret	  dio_pin_toggle(uint8, uint8);
uint8	  dio_pin_read_PIN(uint8, uint8);
uint8	  dio_pin_read_PORT(uint8, uint8);

/*
	parameter is for port
*/

no_ret	  dio_port_input(uint8);
no_ret	  dio_port_input_pullup(uint8);
no_ret	  dio_port_output_low(uint8);
no_ret	  dio_port_output_high(uint8);
no_ret	  dio_port_toggle(uint8);
uint8	  dio_port_read_PIN(uint8);
uint8	  dio_port_read_PORT(uint8);

#endif
