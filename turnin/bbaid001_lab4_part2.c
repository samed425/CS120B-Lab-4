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
            state = s0;
            break;

        case s0:
            if(PINA == 0x01){
                state = s1;
            }
            else if(PINA == 0x02){
                state = s2;
            }
            else if(PINA == 0x03){
                state = s4;
            }
            else{
                state = s0;
            }
            break;

        case s1:
            state = s3;
            break;

        case s2:
            state = s3;
            break;

        case s3:
            if((PINA == 0x01) || (PINA == 0x02)){
                state = s3;
            }
            else if(PINA == 0x03){
                state = s4;
            }
            else{
                state = s0;
            }
            break;

        case s4:
            if((PINA == 0x01) || (PINA == 0x02)){
                state = s4;
            }
            else{
                state = s0;
            }
            break;

        default:
            break;

    }
    switch(state){
        case INIT:
            PORTC = 0x07;
            break;

        case s0:
            break;

        case s1:
            if(PORTC >= 0x09){
                PORTC = 0x09;
            }
            else{
                PORTC += 0x01;
            }
            break;

        case s2:
            if(PORTC <= 0x00){
                PORTC = 0x00;
            }
            else{
                PORTC -= 0x01;
            }
            break;

        case s3:
            break;

        case s4:
            PORTC = 0x00;
            break;

        default:
            break;
    }
}

void main(){
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x07;
    state = INIT;
    
    while(1){
        Tick();
    }
    return 0;
}

