/*
 * AD9854_Serial.c
 *
 * Created: 16/02/2017 8:45:09 PM
 * Author : DaddyASUS
 */ 
#include "config.h"

double frequency=1000000.0;
uint16_t ampl_I=AD9854_IQ_MAX, ampl_Q=AD9854_IQ_MAX;
//extern uint32_t f_cpu;

int main(void)
{
	
	serial_init();
	AD9854_init();											//Set the PLL multiplier to 10(200MHz)
	sei();
	
	AD9854_set_FQ((char) AD9854_FQ1, frequency);			//Set the frequency to 1MHz
	AD9854_set_IQ((char) AD9854_AI, ampl_I);
	AD9854_set_IQ((char) AD9854_AQ, ampl_Q);
	//printFloat(f_cpu, 2);
	
    while (1) 
    {
		serial_loop();
    }
}

