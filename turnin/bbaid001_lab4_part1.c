/*     Author: bbaid001
 *     *      Partner(s) Name:
 *     *      Lab Section:
 *     *      Assignment: Lab #4  Exercise #1
 *     *      Exercise Description: [optional - include for your own benefit]
 *     *      I acknowledge all content contained herein, excluding template or example
 *     *      code, is my own original work.
 *     */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States{INIT, s0, s1, s2, s3, s4}state;

void Tick(){
    switch(state){
        case INIT:
            PORTB = 0x01;
            state = s0;
            break;

        case s0:
            if(PINA == 0x01){
                state = s1;
            }
            else{
                state = s0;
            }
            break;

        case s1:
            if(PINA == 0x00){
                state = s3;
            }
            else{
                state = s1;
            }
            break;

        case s3:
            if(PINA == 0x01){
                state = s2;
            }
            else{
                state = s3;
            }
            break;

        case s2:
            if(PINA == 0x00){
                state = s4;
            }
            else{
                state = s2;
            }
            break;

        case s4:
            if(PINA == 0x01){
                state = s1;
            }
            else{
                state = s4;
            }
            break;

        default:
            break;
    }

    switch(state){
        case INIT:
            break;

        case s0:
            PORTB = 0x01;
            break;

        case s1:
            PORTB = 0x02;
            break;

        case s3:
            break;

        case s2:
            PORTB = 0x01;
            break;

        case s4:
            break;

        default:
            break;
        
    }
}

void main(){
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    state = INIT;
    
    while(1){
        Tick();
    }
    return 0;
}
