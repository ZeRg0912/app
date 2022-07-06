/*
 * AD9854.c
 *
 * Created: 16/02/2017 9:08:28 PM
 *  Author: DaddyASUS
 */ 

#include "config.h"

uint8_t cr[4] ={0x10, 0x64, 0x01, 0x20};			// The 4 bytes of the control register
uint8_t icr[4]={0x10, 0x20, 0x00, 0x40};			// Power invert bits

// Enable functions: Comparator, PLL, Inv Sinc, Amplitude multiplier.
void AD9854_enable(char base_add, uint8_t offset, uint8_t bit)
{
	uint8_t val=cr[offset];
	
	if(bit & icr[offset])							// Power bit is inverted
		val = val & (~bit);
	else
		val = val | bit;
	
	cr[offset] = val;
	transmit_add_data((base_add + offset), val);
}

// Disable functions: Comparator, PLL, Inv Sinc, Amplitude multiplier.
void AD9854_disable(char base_add, uint8_t offset, uint8_t bit)
{
	uint8_t val=cr[offset];
	
	if(!(bit & icr[offset]))						// Power bit is not inverted
		val = val & (~bit);
	else
		val = val | bit;
	
	cr[offset] = val;
	transmit_add_data((base_add + offset), val);
}

void AD9854_init(void)
{
	TX_PORT = 0x00;		// Set the output port to 0
	TX_DDR = TX_BITS;	// Set the output direction bits
	// Set them to a known state
	BITSET(TX_PORT, TX_OE);
	BITSET(TX_PORT, AD9854_WD);
	// Apply a reset to the AD9854
	BITSET(TX_PORT, AD9854_RESET);
	_delay_us(2.0);
	BITCLEAR(TX_PORT, AD9854_RESET);
	_delay_us(2.0);
												
	AD9854_enable(AD9854_CR, AD9854_COMP_OFF, AD9854_COMP_BIT);			//Enable the Comparator
	AD9854_enable(AD9854_CR, AD9854_SINCMUL_OFF, AD9854_AMPL_BIT);		//Enable the Amplitude
	AD9854_disable(AD9854_CR, AD9854_SINCMUL_OFF, AD9854_SINC_BIT);		//Disable the Inv Sinc
	
	AD9854_enable(AD9854_CR, AD9854_PLL_OFF, AD9854_PLL_BIT);			//Enable the PLL
	AD9854_disable(AD9854_CR, AD9854_PLL_OFF, AD9854_PLLRANGE_BIT);		//Disable the PLL range bit
	AD9854_set_mult(AD9854_PLL_MULT);									//Set the PLL multiplier to 10(200MHz)
}
//LSBit becomes MSBit
void inline transmit_add(char add)
{
	char i=8;
	
	add = add << 2;
	while(i > 0)
	{
		if(add & 0x01)
		BITSET(TX_PORT, TX_DATA);
		else
		BITCLEAR(TX_PORT, TX_DATA);

		i--;
		add = add >> 1;
		BITSET(TX_PORT, TX_CLOCK);
		_delay_us(1.0);
		BITCLEAR(TX_PORT, TX_CLOCK);
		_delay_us(1.0);
	}
}
//MSBit to MSBit
void inline transmit_data(char data)
{
	char i=8;
	
	while(i > 0)
	{
		if(data & 0x80)
			BITSET(TX_PORT, TX_DATA);
		else
			BITCLEAR(TX_PORT, TX_DATA);

		i--;
		data = data << 1;
		BITSET(TX_PORT, TX_CLOCK);
		_delay_us(1.0);
		BITCLEAR(TX_PORT, TX_CLOCK);
		_delay_us(1.0);
	}
}
// Needed to load the correct data into the output of the shift register
void inline transmit_load(void)
{
	//An extra clock pulse is needed to get the correct data into
	//the output of the shift register(74AHC595)
	BITSET(TX_PORT, TX_CLOCK);
	_delay_us(1.0);
	BITCLEAR(TX_PORT, TX_CLOCK);
	
	BITCLEAR(TX_PORT, TX_OE);		//Enable the output registers
	BITCLEAR(TX_PORT, AD9854_WD);	//Write the data to the AD9854
	_delay_us(1.0);
	BITSET(TX_PORT, AD9854_WD);		//Finish the write pulse
	_delay_us(1.0);
	BITSET(TX_PORT, TX_OE);			//Disable the outputs
}
// Write the data at the address into the AD9854
void transmit_add_data(char add, char data)
{
	transmit_add(add);
	transmit_data(data);
	transmit_load();
}
//Set the PLL clock frequency to 200MHz
void AD9854_set_mult(uint8_t multiplier)
{
	char add=(AD9854_CR + AD9854_PLL_OFF), data;
	
	data = (cr[AD9854_PLL_OFF] & ~AD9854_PLLMUL_BITS) | (multiplier & AD9854_PLLMUL_BITS);
	cr[AD9854_PLL_OFF] = data;
	transmit_add_data(add, data);
}
//Set the frequency of frequency 1 or 2
void AD9854_set_FQ(char add, double frequency)
{
	char *data;
	uint32_t ftw;
	
	data = (char *) &ftw;
	ftw = 0x80000000;
	ftw = (frequency/((double) AD9854_CLOCK))*ftw;
	ftw = ftw << 1;
	
	transmit_add_data(add, data[3]);
	add++;
	transmit_add_data(add, data[2]);
	add++;
	transmit_add_data(add, data[1]);
	add++;
	transmit_add_data(add, data[0]);
	add++;
	transmit_add_data(add, 0);
	add++;
	transmit_add_data(add, 0);
}
//Set the amplitude for I or Q
void AD9854_set_IQ(char add, uint16_t amplitude)
{
	char *data;
	
	data = (char *) &amplitude;
	
	transmit_add_data(add, data[1]);
	add++;
	transmit_add_data(add, data[0]);
}