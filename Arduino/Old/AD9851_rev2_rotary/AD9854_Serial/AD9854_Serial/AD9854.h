/*
 * AD9854.h
 *
 * Created: 16/02/2017 9:08:57 PM
 *  Author: DaddyASUS
 */ 


#ifndef AD9854_H_
#define AD9854_H_

#define AD9854_CLOCK		200000000UL	// 200MHz

#define TX_PORT				PORTC
#define TX_DDR				DDRC
#define TX_BITS				0b00011111

#define AD9854_RESET		0				// A0
#define TX_CLOCK			1				// A1
#define TX_OE				2				// A2
#define TX_DATA				3				// A3
#define AD9854_WD			4				// A4

#define AD9854_FQ1			0x04
#define AD9854_FQ2			0x0A
#define AD9854_CR			0x1D
#define AD9854_AI			0x21
#define AD9854_AQ			0x23

#define AD9854_COMP_OFF		0x00
#define AD9854_COMP_BIT		0x10

#define AD9854_SINCMUL_OFF	0x03
#define AD9854_SINC_BIT		0x40
#define AD9854_AMPL_BIT		0x20

#define AD9854_PLL_OFF		0x01
#define AD9854_PLL_BIT		0x20
#define AD9854_PLLRANGE_BIT	0x40
#define AD9854_PLLMUL_BITS	0x1F
#define AD9854_PLL_MULT		10			// 10x20MHz		

#define AD9854_IQ_MAX	(uint16_t) 0x0FFF	//Maximum amplitude

void AD9854_enable(char base_add, uint8_t offset, uint8_t bit);
void AD9854_disable(char base_add, uint8_t offset, uint8_t bit);
void AD9854_init(void);
void transmit_add(char add);
void transmit_data(char data);
void transmit_load(void);
void transmit_add_data(char add, char data);
void AD9854_set_mult(uint8_t multiplier);
void AD9854_set_FQ(char add, double frequency);
void AD9854_set_IQ(char add, uint16_t amplitude);

#endif /* AD9854_H_ */