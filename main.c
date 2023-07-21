// #include "avr/io.h"
#define F_CPU 16000000UL
#include "util/delay.h"  // _delay_ms()

sss
sss

#define MY_DDRB (*(volatile unsigned char *)(0x24))
#define MY_PORTB (*(volatile unsigned char *)(0x25))




void setup( void ) {  // setup()
    MY_DDRB |= (1 << 5);  // set portB bit6 OUTPUT -> 0b00100000
}


int main( void ) {
    setup();

    while( 1 ){  // loop
        MY_PORTB |= (1 << 5);  // set portB bit6
        _delay_ms(50);

        MY_PORTB &= ~(1 << 5);  // clear portB bit6
        _delay_ms(950);        
    }
    return 0;
}
