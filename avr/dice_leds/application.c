#include <util/delay.h>
#include "../libs/hal/dio.h"
void dice_pattern(uint8);

int main(void){
	uint8 num = 0;
	dice_pattern(num);
	dio_pin_input(DIO_PORTD,DIO_PIN1);
	while(1){
		if(dio_pin_read_PIN(DIO_PORTD,DIO_PIN1))
			dice_pattern(++num % 7);
	}
}


void dice_pattern(uint8 num){
	if(num%2) dio_pin_output_high(DIO_PORTB,DIO_PIN1);
	else{
		if(!num) 
			dio_port_output_low(DIO_PORTB);
	 	else{
			dio_pin_output_low(DIO_PORTB,DIO_PIN1);
			dio_pin_output_high(DIO_PORTB,num);
		}
	}
	while(dio_pin_read_PIN(DIO_PORTD,DIO_PIN1));
}
