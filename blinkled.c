/*WAP to blink LED at 10 ms if butoon is pressed and at 100ms if  button is not pressed (showing swich bouncing)  */

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{


	DDRB |= 1 << PINB0; 		//Set Direction for output on PINB0 (DDR data direction register)
	PORTB ^= 1<< PINB0 ; 		// Toggling only pin 0on port b
	DDRB |= 1 << PINB2	;	// set direction for output on PINB2
	DDRB &= ~(1 << PINB1);   // Data Direction Register  input PINB1
	PORTB |= 1 << PINB1;		//set PINB1 to a high reading

	int Pressed = 0;
	
	while(1)
	{
		if (bit_is_clear(PINB, 1))
		{
			if (Pressed == 0)
			{

				PORTB ^= 1 << PINB0;
				PORTB ^= 1 << PINB2;
				Pressed = 1;
			}

		}
		
		else
		{
			Pressed = 0;
		}

	}


}
