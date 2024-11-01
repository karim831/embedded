#include "dio.h"

/*              DIO_REGISTERS_ARRAY_MAP             */

static volatile Uint8 *PORT_Regs[4] = {
	&PORTA,&PORTB,&PORTC,&PORTD	
};

static volatile Uint8 *DDR_Regs[4] = {
	&DDRA,&DDRB,&DDRC,&DDRD 
};


static volatile Uint8 *PIN_Regs[4] = {
	&PINA,&PINB,&PINC,&PIND
};


/*              DIO_DRIVER_IMPLEMENTATION               */

void PinMode(Uint8 port,Uint8 pin,Uint8 mode){
    switch(mode){ 
        case OUTPUT : 
            SET_BIT(*DDR_Regs[port],pin);
            CLEAR_BIT(*PORT_Regs[port],pin);
            break; 
        case INPUT_PULLUP :
            CLEAR_BIT(*DDR_Regs[port],pin);
            SET_BIT(*PORT_Regs[port],pin);
            break;
        default:
            CLEAR_BIT(*DDR_Regs[port],pin);
            CLEAR_BIT(*PORT_Regs[port],pin);
    }
}

void PortMode(Uint8 port,Uint8 mode){
    switch(mode){ 
        case OUTPUT : 
            *DDR_Regs[port] = 0xFF;
            *PORT_Regs[port] = 0x00;
            break; 
        case INPUT_PULLUP :
            *DDR_Regs[port] = 0x00;
            *PORT_Regs[port] = 0xFF;
            break;
        default:
            *DDR_Regs[port] = *PORT_Regs[port] = 0x00;
    }
}
void PinWrite(Uint8 port,Uint8 pin,Uint8 logic){
    if(logic == HIGH)
        SET_BIT(*PORT_Regs[port],pin);
    else
        CLEAR_BIT(*PORT_Regs[port],pin);
}

void PortWrite(Uint8 port,Uint8 logic){
    if(logic == HIGH)
        *PORT_Regs[port] = 0xFF; 
    else
        *PORT_Regs[port] = 0x00; 
}

Uint8 PinRead(Uint8 port,Uint8 pin){
    return READ_BIT(*PIN_Regs[port],pin);
}

Uint8 PortRead(Uint8 port){
    return *PIN_Regs[port];
}
