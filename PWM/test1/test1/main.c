/*
 * test1.c
 *
 * Created: 2022-03-08 오후 11:50:50
 * Author : cheag
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

#define LED_TIME 20

void turn_on_LED_in_PWM_manner(int dim){
	 int i;
	 PORTB = 0xFF;
	 
	 for(i = 0; i < 256; i++){
		 if(i > dim) PORTB = 0x00;
		 _delay_ms(LED_TIME);
	 }
}

int main(void)
{
	
	DDRB = 0xFF;
	
	int dim = 0;
	int direction = 1;
	
    /* Replace with your application code */
    while (1) 
    {
		if(dim == 0)
			direction = 1;
		if(dim == 255) 
			direction = -1;
		
		dim += direction;
			
		turn_on_LED_in_PWM_manner(dim);
    }
}

