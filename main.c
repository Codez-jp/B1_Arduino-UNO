#define F_CPU 16000000UL

#include "sub.h"

//#include "unolib.h"
//#include "pinMode.h"
//#include "digitalWrite.h"
#include "util/delay.h"

#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>


int main(void)
{
    int ret;
    
    ret = sub( );
    return ret; 
}


bool is_bit_on( void )
{
    return true;
}


int _main(void)
{
/*
    DDRB |= (_BV(PORTB5));\
    PORTB |= (_BV(PORTB5));\
*/
    DDRB |= (1 << PORTB5);
    PORTB |= (1 << PORTB5);
    
    while( 1 )
    {
        if ( is_bit_on( ) == true )
        {
/*
 *             _delay_ms(1000);\
 *            PORTB &= ~(_BV(PORTB5));
 */

            PORTB = (1 << PORTB5);
            _delay_ms(33);
            PORTB &= ~(1 << PORTB5);
            _delay_ms(100);
            PORTB = (1 << PORTB5);
            _delay_ms(33);

            PORTB &= ~(1 << PORTB5);
            _delay_ms(980);
        }
    }
    return 0; 
}
