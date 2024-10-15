#include <util/delay.h>
#include "../libs/hal/dio.h"

int main(void){
	uint8 pins = DIO_PIN0;
	while(1){
		dio_pin_output_high(DIO_PORTB,pins % 8);
		_delay_ms(500);	
		dio_pin_output_low(DIO_PORTB,pins++ % 8); 
	}
	return EXIT_SUCCESS;	
}
