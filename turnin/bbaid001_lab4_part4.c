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

enum States{INIT, s0, s1, s2, s3, s4, s5}state;

void Tick(){
    switch(state){
        case INIT:
            state = s0;
            break;

        case s0:
            if((PINA & 0x04) && !(PINA & 0x83)){
                state = s1;
            }
            else{
                state = s0;
            }
            break;

        case s1:
            if((PINA & 0x04) && !(PINA & 0x83)){
                state = s1;
            }
            else if(PINA == 0x00){
                state = s2;
            }
            else{
                state = s0;
            }
            break;

        case s2:
            if((PINA & 0x02) && !(PINA & 0x85)){
                state = s3;
            }
            else if(PINA == 0x00){
                state = s2;
            }
            else{
                state = s0;
            }
            break;

        case s3:
            if((PINA & 0x80) && !(PINA & 0x07)){
                state = s0;
            }
            else if((PINA & 0x04) && !(PINA & 0x03)){
                state = s4;
            }
            else{
                state = s3;
            }
            break;

        case s4:
            if((PINA & 0x04) && !(PINA & 0x83)){
                state = s4;
            }
            else if(PINA == 0x00){
                state = s5;
            }
            else{
                state = s3;
            }
            break;

        case s5:
            if((PINA & 0x02) && !(PINA & 0x85)){
                state = s0;
            }
            else if(PINA == 0x00){
                state = s5;
            }
            else{
                state = s3;
            }
            break;

        default:
            state = INIT;
            break;
    }

    switch(state){
        case INIT:
            PORTC = 0x00;
            break;

        case s0:
            PORTB = 0x00;
            PORTC = 0x01;
            break;

        case s1:
            PORTC = 0x02;
            break;

        case s2:
            PORTC = 0x03;
            break;

        case s3:
            PORTB = 0x01;
            PORTC = 0x04;
            break;

        case s4:
            PORTB = 0x01;
            PORTC = 0x05;
            break;

        case s5:
            PORTB = 0x01;
            PORTC = 0x06;
            break;

        default:
            break;
    }
}
 
int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;
    
    state = INIT;
        
    while (1)
    {
        Tick();
    }
    return 0;
}

