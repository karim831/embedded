#include "../libs/hal/dio.h"

int main(void){
	uint8 pins = DIO_PIN0;
	dio_pin_output_high(DIO_PORTB,pins++ % 8);
	while(1){

	}
	return EXIT_SUCCESS;	
}
