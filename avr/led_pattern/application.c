#include "application.h"


int main(void){
    Setup();
    Application();
	return 0;	
}

void Setup(void){
   for(Uint8 i=PN0;i<=PN7;i++)
       PinMode(PTB,i,OUTPUT);
}

void Application(void){
   Uint8 pinsCounter = PN0;
   while(1){
       if(pinsCounter > PN7)
           pinsCounter = PN0;
       DigitalWrite(PTB,pinsCounter,HIGH);
       _delay_ms(500);
       DigitalWrite(PTB,pinsCounter++,LOW);
   }
}
