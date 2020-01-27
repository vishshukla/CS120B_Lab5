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

enum States { start, s0, pressed} state;

unsigned char newA = 0x00;

void tick() {
    newA = ~PINA;
	switch(state) { //transitions
		case start:
			state = s0;
			break;
		case s0:
			if((newA & 0x0F) == 0x01) {
				state = pressed;
                if(PORTC < 9) PORTC++;
			} else if((newA & 0x0F) == 0x02){
				state = pressed;
                if(PORTC > 0) PORTC--;
			} else if((newA & 0x0F) == 0x03){
				PORTC = 0x00;
			} else {
				state = s0;
			}
			break;
        case pressed:
            if((newA & 0x0F) == 0x01 || (newA & 0x0F) == 0x02) {
                state = pressed;
            } else if ((newA & 0x0F) == 0x03) {
                PORTC = 0x00;
                state = pressed;
            } else {
                state = s0;
            }
            break;
	default:
            state = s0;
            break;
	}
	switch(state) { //actions
		case start:
		case s0: 
		case pressed:
		default:
			break;
	}
}


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x07;
	state = start;
	while(1) {
		tick();
	};	
    return 1;
}
