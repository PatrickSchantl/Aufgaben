/*
 * IINF.c
 *
 * 
 * Author : Patrick
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
   unsigned const char  LED_MASK = (1<<PIND2)|
   (1<<PIND3)|
   (1<<PIND4)|
   (1<<PIND5)|
   (1<<PIND6)|
   (1<<PIND7);
   
   unsigned const char  BUTTON_MASK = (1<<PINC0)|
   (1<<PINC1)|
   (1<<PINC2);
   
   DDRD = LED_MASK;
   
   DDRD |= (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
   
    while (1) 
    { 
		
		
		unsigned char pins = PINC&BUTTON_MASK;
		pins =~pins;
		pins = (BUTTON_MASK&pins);
		
		unsigned char bt0 = (pins&(1<<PINC0))>>PINC0;
		unsigned char bt1 = (pins&(1<<PINC1))>>PINC1;
		unsigned char bt2 = (pins&(1<<PINC2))>>PINC2;
		
if (bt0 == true)
{
		for (int i = 2; i<8; i++)
		{
			PORTD|= (1<<i);
			_delay_ms(2000);
		
		}

}
	
	if (bt1 == true)
	{
		
		PORTD|= -1;
		
    }
	if (bt2 == true)
	{
		for(int i = 2; i <8; i++)
		{
			unsigned char zufallLED = rand()%5+2;
		unsigned char zufallZeit = rand()%1000+300
				PORTD|= (1<<zufallLED);
				_delay_ms((zufallZeit))
		}
		
	
		
		
	}
}

