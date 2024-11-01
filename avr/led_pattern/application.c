#include "application.h"


int main(void){
    Setup();
    Application();
	return 0;	
}

void Setup(void){
    PortMode(PTB,OUTPUT);
}

void Application(void){
   Uint8 pinsCounter = PN0;
   while(1){
       if(pinsCounter > PN7)
           pinsCounter = PN0;
       PinWrite(PTB,pinsCounter,HIGH);
       _delay_ms(500);
       PinWrite(PTB,pinsCounter++,LOW);
   }
}
