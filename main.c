// #include "avr/io.h"
#define F_CPU 16000000UL
#include "util/delay.h"  // _delay_ms()

#define MY_DDRB (*(volatile unsigned char *)(0x24))
#define MY_PORTB (*(volatile unsigned char *)(0x25))

int main( void ) {
    // setup())
    MY_DDRB |= (1 << 5);  // MY_DDRB = 0b00100000;
  
    while( 1 ){
        // Loop()
        MY_PORTB |= (1 << 5);
        _delay_ms(1500);

        MY_PORTB &= ~(1 << 5);
        _delay_ms(1500);        
    }
    return 0;
}
