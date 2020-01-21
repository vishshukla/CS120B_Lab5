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
	DDRB = 0xFF; PORTB = 0x00;

    /* Insert your solution below */
    while (1) {
	// Writes port B's 8 pins with 00001111
	PORTB = 0x0F;
    }
    return 1;
}
