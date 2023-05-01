#define F_CPU 16000000UL
#define T1_MAX 0xFFFFUL
#define T1_PRESCALER 1024
#define T1_TICK_US (T1_PRESCALER/(F_CPU/1000000UL)) /* 64us @ 16MHz */
#define T1_MAX_US (T1_TICK_US * T1_MAX) /* ~4.2s @ 16MHz */
 
// The Port B Data Register
#define MY_PORTB  (*(volatile unsigned char*) 0x25)
// The Port B Data Direction Register
#define MY_DDRB   (*(volatile unsigned char*) 0x24)
// The 6th port B pin <- port number is Zero origin
#define MY_PORTB5 5

#include "util/delay.h"


int sub( void )
{
    MY_DDRB |= (1 << MY_PORTB5);
    MY_PORTB |= (1 << MY_PORTB5);
    
    while( 1 )
    {
        MY_PORTB = (1 << MY_PORTB5);
        _delay_ms(33);
        MY_PORTB &= ~(1 << MY_PORTB5);
        _delay_ms(967);
    }
    return 0; 
}
