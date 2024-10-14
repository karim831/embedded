#include "./dio.h"

static volatile uint8 *ports_reg[4] = {
	&PORTA,&PORTB,&PORTC,&PORTD	
}
static volatile uint8 *ddrs_reg[4] = {
	&DDRA,&DDRB,&DDRC,&DDRD 
}
static volatile uint8 *pins_reg[4] = {
	&PINA,&PINB,&PINC,&PIND
}

no_ret dio_pin_input(uint8 port,uint8 pin){
	CLEAR_BIT(*ddrs_reg[port],pin);
	CLEAR_BIT(*ports_reg[port],pin);
}

no_ret dio_pin_input_pullup(uint8 port,uint8 pin){
	CLEAR_BIT(*ddrs_reg[port],pin);
	SET_BIT(*ports_reg[port],pin);
}

no_ret dio_pin_output_low(uint8 port,uint8 pin){
	SET_BIT(*ddrs_reg[port],pin);
	CLEAR_BIT(*ports_reg[port],pin);
}

no_ret dio_pin_output_high(uint8 port,uint8 pin){
	SET_BIT(*ddrs_reg[port],pin);
	SET_BIT(*ports_reg[port],pin);
}

no_ret dio_pin_toggle(uint8 port,uint8 pin){
	if(dio_pin_read_PIN(port,pin))
		dio_pin_output_high(port,pin);
	else
		dio_pin_output_low(port,pin);
}

uint8 dio_pin_read_PIN(uint8 port,uint8 pin){
	return READ_BIT(*pins_reg[port],pin);
}

uint8 dio_pin_read_PORT(uint8 port,uint8 pin){
	return READ_BIT(*ports_reg[port],pin);
}

no_ret dio_port_input(uint8 port){
	*ddrs_reg[port] = *ports_reg[port] = DIO_EMPTY_REG;
}

no_ret dio_port_input_pullup(uint8 port){
	*ddrs_reg[port] = DIO_EMPTY_REG;
	*ports_reg[port] = DIO_FULL_REG;
}

no_ret dio_port_output_low(uint8 port){
	*ddrs_reg[port] = DIO_FULL_REG;
	*ports_reg[port] = DIO_EMPTY_REG;
}

no_ret dio_port_output_high(uint8 port){
	*ddrs_reg[port] = *ports_reg[port] = DIO_FULL_REG;
}

no_ret dio_port_toggle(uint8 port){
	if(dio_port_read_PIN(port))
		dio_port_output_low(port);
	else
		dio_port_ouput_high(port);
}

uint8 dio_port_read_PIN(uint8 port){
	return *pins_reg[port];
}
uint8 dio_port_read_PORT(uint8 port){
	return *ports_reg[port];
}

