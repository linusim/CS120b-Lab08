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

	unsigned short max = 1024;
	unsigned char tempB = 0x00;
		
	while(1) {
		unsigned short my_short = ADC;
		
		if(my_short <= 0) {
			tempB = 0x00;
		} else if(my_short <= (max * 0.125)) {
			tempB = 0x01;
		} else if(my_short <= (max * 0.25)) {
			tempB = 0x03;
		} else if(my_short <= (max * 0.375)) {
			tempB = 0x07;
		} else if(my_short <= (max * 0.5)) {
			tempB = 0x0F;
		} else if(my_short <= (max * 0.625)) {
			tempB = 0x1F;
		} else if(my_short <= (max * 0.75)) {
			tempB = 0x3F;
		} else if(my_short <= (max * 0.875)) {
			tempB = 0x7F;
		} else if(my_short <= (max)) {
			tempB = 0xFF;
		}
		
		PORTB = tempB;
	}
}
