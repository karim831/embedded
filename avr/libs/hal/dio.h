#ifndef __DIO_H__
#define __DIO_H__

/*						INCLUDES							*/

#include "../stdlibs/std_libs.h"


/*              PORTS_DECLARATION               */

#define         PTA          ((Uint8)0x00)
#define         PTB          ((Uint8)0x01)
#define         PTC          ((Uint8)0x02)
#define         PTD          ((Uint8)0x03)

/*              PINS_DECLARATION               */

#define			PN0             ((Uint8)0x00)
#define			PN1             ((Uint8)0x01)
#define			PN2             ((Uint8)0x02)
#define			PN3             ((Uint8)0x03)
#define			PN4             ((Uint8)0x04)
#define			PN5             ((Uint8)0x05)
#define			PN6             ((Uint8)0x06)
#define			PN7             ((Uint8)0x07)


/*              MODES               */
 
#define         INPUT           ((Uint8)0x00) 
#define         INPUT_PULLUP    ((Uint8)0x01)
#define         OUTPUT          ((Uint8)0x02)


/*              DIO_DRIVERS_DECLARATION             */ 

void PinMode(Uint8 port,Uint8 pin,Uint8 mode);
void PortMode(Uint8 port,Uint8 mode);

void PinWrite(Uint8 port,Uint8 pin,Uint8 logic);
void PortWrite(Uint8 port,Uint8 logic);

Uint8 PinRead(Uint8 port,Uint8 pin);
Uint8 PortRead(Uint8 port);
#endif
