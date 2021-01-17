/*	Author: lab
 *  Partner(s) Name: Ben Pham
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #4
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
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;

	unsigned short totWeight = 0x0000;
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD0 = 0x00;
	unsigned char tmpD1 = 0x00;
	unsigned char dVal = 0x00;

	while(1) {

		tmpA = PINA & 0xFF;
		tmpB = PINB & 0xFF;
		tmpC = PINC & 0xFF;
		totWeight = tmpA + tmpB + tmpC;

		if (totWeight > 0x008C) {
			tmpD0 = 0x01;
		} else {
			tmpD0 = 0x00;
		}

		if (tmpA > tmpC) {
			if (tmpA - tmpC > 0x50) {
				tmpD1 = 0x02;
			}
		}
		else { 
			if (tmpC - tmpA > 0x50) {
				tmpD1 = 0x02;
			}
		}
		
		totWeight = totWeight >> 2;
		dVal = (totWeight & 0x00FC) | tmpD0 | tmpD1;
		PORTD = dVal;

	}

	return 1;
}

