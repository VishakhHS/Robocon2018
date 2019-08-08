
  /*
 * devya_1sept.c
 *
 * Created: 01/09/2016 7:05:13 PM
 * Author : Shubham_D
 */ 



#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
	volatile int i=0,x=0;
	volatile float count_add=10;//11 fr 1 rps,,21=2,,32=3,,43=4,,54=5,,108 fr10rps
	volatile float kp=1,corr;
	volatile int prev_i=0;
	volatile int timercount=0;
	volatile int input=0;
	
	
ISR(INT0_vect)
{  cli();
	if((PIND & 0b00010000)==0b00010000)
	{
		i--;
		
	}  
	else
	{
		i++;
	   //  PORTA=0b10000000;
	} 
	sei();	
}
volatile int req_count=0;
ISR(TIMER1_COMPA_vect)
{
	/*
	if(i<10)
	{
		count_add=count_add+1;
	}
	if(i>10000)
	{
		
		count_add=count_add-100*0.001;
	}*/
	//if(count_add>=0)
	//{
		req_count=req_count+count_add;
		//}

}
ISR(TIMER0_COMP_vect)
{
	corr=kp*(req_count-i);
	OCR2=abs(corr);

}

int main(void)
{	DDRD=0b10000000;
	DDRB=0;
	DDRA=0;
	//PORTA=0b11111111;
	DDRC=255;
	PORTC=255;
	//PORTA=255;
	//int i=0;
	
	TCCR2=0x6C; // TCCR0=0X0C;//12    for encoder:-0x66;
	//	OCR2=200;  
	//TIMSK=(1<<OCIE0);
	TCCR0=(1<<WGM01)|(1<<CS02)|(1<<CS00);
	
	TCCR1B=(1<<CS12)|(1<<WGM12)|(1<<CS10);
	
	
	TIMSK=(1<<OCIE1A)|(1<<OCIE0);
	OCR1A=15625/100;
	OCR0=15;
	MCUCR= (1<<ISC01) | (1<<ISC00);
	GICR= (1<<INT0);
//	GIFR= (1<<INTF0);
	sei();
	int flag=0;
    while (flag==0) 
    {
  sei();
		if(corr>235)
		{
			corr=235;
		//	OCR2=100;
		}
input=PINA & 0b00000001;

 if (input==0b00000001)
 {
	  OCR2=0;
	   	  PORTC=0;
	   	   OCR2=50;
			  _delay_ms(70);
			  OCR2=0;
			  flag=1;
 }

 // while(flag==1)
 // {
 	// OCR2=0;
 	 
 	 //}



		
    }
}






