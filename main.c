#define F_CPU 16000000UL
#include "util/delay.h"

#define MY_DDRB (*(volatile uint8_t *)(0x24))
#define MY_PORTB (*(volatile uint8_t *)(0x25))
#define MY_PORTB5 5


void setup( void ){
    MY_DDRB |= (1 << MY_PORTB5);
    MY_PORTB |= (1 << MY_PORTB5);
}

int main( void ) {
    setup();
    
    while( 1 ){
        MY_PORTB = (1 << MY_PORTB5);
        _delay_ms(10);

        MY_PORTB &= ~(1 << MY_PORTB5);
        _delay_ms(2990);        
    }
    return(1);
}

