/*	Author: vshuk003
 *  Partner(s) Name: Nicole Nguyen
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
    /* Insert DDR and PORT initializations */
	// Configure port B's 8 pins as outputs
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char led = 0x00;
	unsigned char button = 0x00;
    /* Insert your solution below */
    while (1) {
	// input
	button = ~PINA & 0x01;
	
	if (button) {
		led = (led & 0xFC) | 0x01;
	} else {
		led = (led & 0xFC) | 0x02;
	}

	PORTC = led;
    }
    return 1;
}
