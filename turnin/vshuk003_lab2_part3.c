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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States { start, s0, configure, wait } state;

unsigned char newA = 0x00;
unsigned char first = 0x00, second = 0x00;

void tick() {
    newA = ~PINA;
	switch(state) { //transitions
		case start:
			state = s0;
			break;
		case s0:
			if((newA & 0x0F) == 0x01) {
				state = configure;
			} else {
				state = s0;
			}
			break;
        case configure:
            state = wait;
           break;
        case wait:
            if((newA & 0x01) == 0x01) state = wait;
            else state = s0;
            break;
	default:
            state = s0;
            break;
	}
	switch(state) { //actions
		case start: PORTC = 0; break;
		case s0: break; 
		case configure:
                 first = (rand() % 5) + 1;
                 second = (rand() % 5) + 1;
                 if(first == second) first = ((first + 1) % 5) + 1;
                 PORTC = (0x01 << first) | (0x01 << second);
                 break;
        case wait:
                 break;
		default:
			break;
	}
}


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	state = start;
	while(1) {
		tick();
	};	
    return 1;
}
