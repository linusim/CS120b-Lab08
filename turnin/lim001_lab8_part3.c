/*	Name: Linus Im
 *	Partner(s) Name & Email: Festo Bwogi
 *	Lab Section: 022
 *	Assignmetn: Lab 8 Exercise 2
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#include <avr/interrupt.h>

unsigned short my_short;
unsigned char my_char1;
unsigned char my_char2;

void ADC_init() {
	 ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
	DDRA = 0X00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;

	ADC_init();

	unsigned short my_short;
	unsigned short max = 1024;
	unsigned char tempB = 0x00;
		
	while(1) {
		my_short = ADC;
		if(my_short > max) {
			max = my_short;
		}
		if(my_short >= (max / 2)) {
			tempB = 0x00;
		} else {	
			tempB = 0x00;
		}
		PORTB = tempB;
	}
}
