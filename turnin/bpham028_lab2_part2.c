/*	Author: lab
 *  Partner(s) Name: Ben Pham
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {

	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;

	unsigned char tmpA0 = 0x00;
	unsigned char tmpA1 = 0x00;
	unsigned char tmpA2 = 0x00;
	unsigned char tmpA3 = 0x00;

	while (1) {
		tmpA0 = PINA & 0x01;
		tmpA1 = PINA & 0x02;
		tmpA2 = PINA & 0x04;
		tmpA3 = PINA & 0x08;

		if (!tmpA0 && !tmpA1 && !tmpA2 && !tmpA3) {
			PORTB = 0x04;
		} else if ((!tmpA3 && !tmpA2 && !tmpA1 && tmpA0) || (!tmpA3 && !tmpA2 && tmpA1 && !tmpA0) || (!tmpA3 && tmpA2 && !tmpA1 && !tmpA0) || (tmpA3 && !tmpA2 && !tmpA1 && !tmpA0) {
			PORTB = 0x03;
		} else if ((tmpA3 && !tmpA2 && !tmpA1 && tmpA0) || (tmpA3 && !tmpA2 && tmpA1 && !tmpA0) || (tmpA3 && tmpA2 && !tmpA1 && !tmpA0) || (!tmpA3 && tmpA2 && !tmpA1 && tmpA0) || (!tmpA3 && tmpA2 && tmpA1 && !tmpA0) || (!tmpA3 && !tmpA2 && tmpA1 && tmpA0)) {
			PORTB = 0x02;
		} else if ((tmpA3 && tmpA2 && tmpA1 && !tmpA0) || (tmpA3 && tmpA2 && !tmpA1 && tmpA0) || (tmpA3 && !tmpA2 && tmpA1 && tmpA0) || (!tmpA3 && tmpA2 && tmpA1 && tmpA0)) {
			PORTB = 0x01;
		} else {
			PORTB = 0x00;
		}
	}
	
	return 1;

}

