/*
 * MIProject.cpp
 *
 * Created: 03/07/2021 1:57:34 PM
 * Author : Muzamil + Mobeen + Akif 
 */ 

#include <avr/io.h>	//AVR IO header file
#include <avr/interrupt.h> //AVR Port pin definition
#define F_CPU 1000000UL //default CPU frequency
#include <util/delay.h>	//delay utility added so that delay functions can be used



int count = 1; //Current floor
int destination = 5; // Last floor
int pinchangeinterupt = 0, UP1 = 0, UP2 = 0, UP3 = 0, UP4 = 0, DOWN5 = 0, DOWN4 = 0, DOWN3 = 0, DOWN2 = 0; 



void init(){
	DDRB = 0b11111100;
	DDRD = 0b11111111;
	DDRC = 0b00011111;
}

//-------Elevator Inside Buttons ------

void Elevator_inside_button(){
	if ((PINC & 0b00000001) == 0b00000001)
	{
		destination = 1;
		
	}
	
	else if ((PINC & 0b00000010) == 0b00000010)
	{
		destination = 2;
	
	}
	
	else if ((PINC & 0b00000100) == 0b00000100)
	{
		destination = 3;
		
	}
	
	else if ((PINC & 0b00001000) == 0b00001000)
	{
		destination = 4;
	
	}
	
	else if ((PINC & 0b00010000) == 0b00010000)
	{
		destination = 5;
	
	}
}

//-------Elevator Inside Buttons ------



void Move_Upward(){		//AntiClockwise Direction
	PORTD = (1<<1);
	PORTD = (1<<6)|(0<<7); 
	_delay_ms(5000);
	PORTD = (0<<6)|(0<<7);
}

void Move_Downward(){		//Clockwise Direction
	PORTD = (1<<2);
	PORTD = (0<<6)|(1<<7);
	_delay_ms(5000);
	PORTD = (0<<6)|(0<<7);
}

//---------Motor Speed ---------//

void Motor_Speed(int x){
	if (x==25)
	{
		OCR0A=0x40;  // 25% Duty Cycle
	}
	if (x==50)
	{
		OCR0A=0x80;  // 50% Duty Cycle
	}
	if (x==75)
	{
		OCR0A=0xC0;  // 75% Duty Cycle
	}
	if (x==100)
	{
		OCR0A=0xFF;  // 100% Duty Cycle
	}
}

//---------Motor Speed ---------// end


//-------- 7 Segment Display ---------
void Seg7Display(){
	if (count == 1)
	{
		PORTB = 1<<4;
	}
	else if (count == 2)
	{
		PORTB = 1<<5;
	}
	else if (count == 3)
	{
		PORTB = (1<<4)|(1<<5);
	}
	else if (count == 4)
	{
		PORTB = 1<<6;
	}
	else if (count == 5)
	{
		PORTB = (1<<6)|(1<<4);
	}
}

//-------- 7 Segment Display ---------// end

void Doors_Open(){
	for (int i=0; i<10; i++)  // Door remians open for 10 seconds
	{
		PORTD = 1<<0;
		_delay_ms(500);
		PORTD = 0<<0;
		_delay_ms(500);
	}
	
}



int main(void)
{
	init();
	
	//PIN CHANGE Interrupt for Elevator Outside Buttons
	PCICR = 1<<PCIE0;
	PCIFR = 1<<PCIF0;
	PCMSK0 = (1<<PCINT1)|(1<<PCINT0);
	
	//FOR PWM, MOTOR SPEED 
	TCCR0A=(1<<COM0A1)|(1<<WGM00); // PWM Phase Corrected mode // Non Inverting Mode
	TCCR0B=(1<<CS02)|(1<<CS00); //Prescallar 1024
	
	sei();
	
	if (count == 1)  // it means lift is on 1st floor.
	{
		//PORTB = (1<<3)|(1<<2);			// Selectlines A = 1 and B = 1
		Seg7Display();
	}
    
    while (1) 
    { 
		
		Elevator_inside_button(); 
	
		if (destination - count == 1)
		{
			Move_Upward();	// moves motor with 25% duty cycle.
			count = 2;
			Seg7Display();
						
		}
		else if (destination - count == 2)
		{
			Move_Upward();	// moves motor with 50% duty cycle.
			count = 3;
			Seg7Display();
		}
		else if (destination - count == 3)
		{
			Move_Upward();	// moves motor with 75% duty cycle.	
			count = 4;
			Seg7Display();
		}
		else if (destination - count == 4)
		{
			Move_Upward();	// moves motor with 100% duty cycle.
			count = 5;
			Seg7Display();
		}
		
		else if (destination - count == -1)
		{
			Move_Downward();	// moves motor with 25% duty cycle.
			count = 4;
			Seg7Display();
			
		}
		else if (destination - count == -2)
		{
			Move_Downward();	// moves motor with 50% duty cycle.
			count = 3;
			Seg7Display();
			
		}
		else if (destination - count == -3)
		{
			Move_Downward();	// moves motor with 75% duty cycle.
			count = 2;
			Seg7Display();
		}
		else if (destination - count == -4)
		{
			Move_Downward();	// moves motor with 100% duty cycle.
			count = 1;
			Seg7Display();
		}
		
		
		if (pinchangeinterupt == 1)
		{
			if ((PINB & 0b00000001) == 0b00000001) //It means any of the 4 DOWN button is pressed.
			{
				if ((PINB & 0b00000000) == 0b00000000) //Selectlines A =0, B=0 // On the 5th floor DOWN button is pressed.
				{
					DOWN5 = 1;
				}
				if ((PINB & 0b00000100) == 0b00000100) //Selectlines A =1, B=0 // On the 4th floor DOWN button is pressed.
				{
					DOWN4 = 1;
				}
				if ((PINB & 0b00001000) == 0b00001000) //Selectlines A =0, B=1 // On the 3rd floor DOWN button is pressed.
				{
					DOWN3 = 1;
				
				if ((PINB & 0b00001100) == 0b00001100)  // Selectlines A =1, B=1 // On the 2nd floor DOWN button is pressed.  
				{
					DOWN2 = 1;
				}
				
			}
			if ((PINB & 0b00000010) == 0b00000010) //It means any of the 4 UP button is pressed.
			{
				if ((PINB & 0b00001100) == 0b00001100) //Selectlines A =0, B=0 // On the 1st floor UP button is pressed.
				{
					UP1 = 1;
	
				}
				if ((PINB & 0b00000100) == 0b00000100) // //Selectlines A =1, B=0 // On the 2nd floor UP button is pressed.
				{
					UP2 = 1;
				}
				
				if ((PINB & 0b00001000) == 0b00001000) //Selectlines A =0, B=1 // On the 3rd floor UP button is pressed.
				{
					UP3 = 1;
				}
				if ((PINB & 0b00001100) == 0b00001100) // //Selectlines A =1, B=1 // On the 4th floor UP button is pressed.
				{
					UP4 = 1;
				}
				
			}
			
		}
		
		if (UP1 == 1) // On the floor 1 the UP button is pressed.
		{
			Doors_Open();
			Move_Upward();
			Seg7Display();
		}
		if (UP1 == 1) // On the floor 2 the UP button is pressed.
		{
			Doors_Open();
			Move_Upward();
			Seg7Display();
		}
		if (UP1 == 1) // On the floor 3 the UP button is pressed.
		{
			Doors_Open();
			Move_Upward();
			Seg7Display();
		}
		if (UP1 == 1) // On the floor 4 the UP button is pressed.
		{
			Doors_Open();
			Move_Upward();
			Seg7Display();
		}
		
		
		if (DOWN2 == 1) // On the floor 2 the DOWN button is pressed.
		{
			Doors_Open();
			Move_Downward();
			Seg7Display();
		}
		if (DOWN3 == 1) // On the floor 2 the DOWN button is pressed.
		{
			Doors_Open();
			Move_Downward();
			Seg7Display();
		}
		if (DOWN4 == 1) // On the floor 4 the DOWN button is pressed.
		{
			Doors_Open();
			Move_Downward();
			Seg7Display();
		}
		if (DOWN5 == 1) // On the floor 5 the DOWN button is pressed.
		{
			Doors_Open();
			Move_Downward();
			Seg7Display();
		}
			
    }
}

ISR (PCINT0_vect){
	pinchangeinterupt = 1;
}
