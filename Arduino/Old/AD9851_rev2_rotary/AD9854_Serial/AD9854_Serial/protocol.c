/*
 * protocol.c
 *
 * Created: 21/02/2017 3:20:23 PM
 *  Author: DaddyASUS
 */ 
#include "config.h"

extern double frequency;
extern uint16_t ampl_I, ampl_Q;

uint8_t read_float(char *line, uint8_t *char_counter, float *float_ptr)
{
	char *ptr = line + *char_counter;
	unsigned char c;
	
	// Grab first character and increment pointer. No spaces assumed in line.
	c = *ptr++;
	
	// Capture initial positive/minus character
	bool isnegative = false;
	
	if (c == '-') 
	{
		isnegative = true;
		c = *ptr++;
	} 
	else if (c == '+') 
		c = *ptr++;
	
	// Extract number into fast integer. Track decimal in terms of exponent value.
	uint32_t intval = 0;
	int8_t exp = 0;
	uint8_t ndigit = 0;
	bool isdecimal = false;
	
	while(1) 
	{
		c = c - '0';
		
		if (c <= 9) 
		{
			ndigit++;
			if (ndigit <= MAX_INT_DIGITS) 
			{
				if (isdecimal) 
					exp--;
					
				intval = (((intval << 2) + intval) << 1) + c; // intval*10 + c
			} 
			else 
			{
				if (!(isdecimal)) 
					exp++;  // Drop overflow digits
			}
		} 
		else if (c == (('.'-'0') & 0xff)  &&  !(isdecimal)) 
			isdecimal = true;
		else
			break;
			
		if(*ptr != 0)	
			c = *ptr++;
	}
	
	// Return if no digits have been read.
	if (!ndigit) 
		return(false);
	
	// Convert integer into floating point.
	float fval;
	fval = (float)intval;
	
	// Apply decimal. Should perform no more than two floating point multiplications for the
	// expected range of E0 to E-4.
	if (fval != 0) 
	{
		while (exp <= -2) 
		{
			fval *= 0.01;
			exp += 2;
		}
		
		if (exp < 0) 
			fval *= 0.1;
		else if (exp > 0) 
		{
			do 
			{
				fval *= 10.0;
			} while (--exp > 0);
		}
	}

	// Assign floating point value with correct sign.
	if (isnegative) 
		*float_ptr = -fval;
	else
		*float_ptr = fval;

	*char_counter = ptr - line - 1; // Set char_counter to next statement
	
	return(true);
}

void process_command(char *line)
{
	uint8_t char_counter=0;
	float fval;

	if(line[0] == 0)
		return;
	else if(line[0] == 'D')
	{
		//Disable functions: Amplitude, Comparator, InvSync, PLL, PLL range
		if(line[1] == 'A')
		{
			AD9854_disable(AD9854_CR, AD9854_SINCMUL_OFF, AD9854_AMPL_BIT);
			printString("Amplitude control disabled\n");
		}
		else if(line[1] == 'C')
		{
			AD9854_disable(AD9854_CR, AD9854_COMP_OFF, AD9854_COMP_BIT);
			printString("Comparator disabled\n");
		}
		else if(line[1] == 'I')
		{
			AD9854_disable(AD9854_CR, AD9854_SINCMUL_OFF, AD9854_SINC_BIT);
			printString("InvSinc disabled\n");
		}
		else if(line[1] == 'P')
		{
			AD9854_disable(AD9854_CR, AD9854_PLL_OFF, AD9854_PLL_BIT);
			printString("PLL disabled\n");
		}
		else if(line[1] == 'R')
		{
			AD9854_disable(AD9854_CR, AD9854_PLL_OFF, AD9854_PLLRANGE_BIT);
			printString("PLL Range disabled\n");
		}
		else
			printString("Invalid Disable command\n");
	}
	else if(line[0] == 'E')
	{
		//Enable functions: Amplitude, Comparator, InvSync, PLL, PLL range
		if(line[1] == 'A')
		{
			AD9854_enable(AD9854_CR, AD9854_SINCMUL_OFF, AD9854_AMPL_BIT);
			printString("Amplitude control enabled\n");
		}
		else if(line[1] == 'C')
		{
			AD9854_enable(AD9854_CR, AD9854_COMP_OFF, AD9854_COMP_BIT);
			printString("Comparator enabled\n");
		}
		else if(line[1] == 'I')
		{
			AD9854_enable(AD9854_CR, AD9854_SINCMUL_OFF, AD9854_SINC_BIT);
			printString("InvSinc enabled\n");
		}
		else if(line[1] == 'P')
		{
			AD9854_enable(AD9854_CR, AD9854_PLL_OFF, AD9854_PLL_BIT);
			printString("PLL enabled\n");
		}
		else if(line[1] == 'R')
		{
			AD9854_enable(AD9854_CR, AD9854_PLL_OFF, AD9854_PLLRANGE_BIT);
			printString("PLL Range enabled\n");
		}
		else
			printString("Invalid Enable command\n");
	}
	else if(line[0] == 'I')
	{
		//Initialise
		AD9854_init();
		frequency = 1000000.0;
		ampl_I = ampl_Q = AD9854_IQ_MAX;
		AD9854_set_FQ(AD9854_FQ1, frequency);
		AD9854_set_IQ((char) AD9854_AI, ampl_I);
		AD9854_set_IQ((char) AD9854_AQ, ampl_Q);
		printString("Initialised the AD9854\n");
	}
	else if(line[0] == 'F')
	{
		//A frequency command
		char_counter++;
		if(read_float(line, &char_counter, &fval))
		{
			frequency = fval;
			AD9854_set_FQ(AD9854_FQ1, frequency);
			printString("Frequency set: ");
			printFloat(fval, 2);
			printString("\n");
		}
		else
			printString("Invalid Frequency command\n");
	}
	else if(line[0] == 'P')
	{
		//A PLL multiplier command
		uint8_t multiplier;
		
		char_counter++;
		if(read_float(line, &char_counter, &fval))
		{
			multiplier = fval;
			multiplier = multiplier & AD9854_PLLMUL_BITS;
			fval = multiplier;
			
			AD9854_set_mult(multiplier);
			printString("PLL multiplier set: ");
			printFloat(fval, 2);
			printString("\n");
		}
		else
			printString("Invalid PLL multiplier command\n");
	}
	else if(line[0] == 'A')
	{
		if(line[1] == 'B')
		{
			//An amplitude command for both I and Q
			char_counter++;
			char_counter++;
			if(read_float(line, &char_counter, &fval))
			{
				ampl_I = ampl_Q = fval;
				AD9854_set_IQ(AD9854_AI, ampl_I);
				AD9854_set_IQ(AD9854_AQ, ampl_Q);
				printString("Amplitude set Both: ");
				printFloat(fval, 2);
				printString("\n");
			}
		}
		else if(line[1] == 'I')
		{
			//An amplitude command for both I and Q
			char_counter++;
			char_counter++;
			if(read_float(line, &char_counter, &fval))
			{
				ampl_I = fval;
				AD9854_set_IQ(AD9854_AI, ampl_I);
				printString("Amplitude set I: ");
				printFloat(fval, 2);
				printString("\n");
			}
		}
		else if(line[1] == 'Q')
		{
			//An amplitude command for both I and Q
			char_counter++;
			char_counter++;
			if(read_float(line, &char_counter, &fval))
			{
				ampl_Q = fval;
				AD9854_set_IQ(AD9854_AQ, ampl_Q);
				printString("Amplitude set Q: ");
				printFloat(fval, 2);
				printString("\n");
			}
		}
		else
			printString("Invalid Amplitude command\n");
	}
	else
		printString("Invalid command\n");
}