#include "application.h"

int main(void){
    Setup();
    Application();
	
}

void Setup(void){
    PortMode(PTB,OUTPUT);
    PinMode(PTD,PN1,INPUT);
}

void Application(void){
    Uint8 num = 0;
	DicePattern(num);
	while(1){
		if(PinRead(PTD,PN1))
			DicePattern(++num % 7);
	}
}

void DicePattern(Uint8 num){
	if(num%2) PinWrite(PTB,PN1,HIGH);
	else{
		if(!num) 
            PortWrite(PTB,LOW);
	 	else{
            PinWrite(PTB,PN1,LOW);
            PinWrite(PTB,num,HIGH);
		}
	}
	while(PinRead(PTD,PN1));
}
