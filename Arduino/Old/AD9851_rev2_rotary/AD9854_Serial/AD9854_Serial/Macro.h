#define INT_LOW_LEVEL			0
#define INT_ANY_EDGE			1
#define INT_FALLING_EDGE		2
#define INT_RISING_EDGE		3
//-----------------------------------------------------------------------------
#define PIN_INPUT_HIZ			0
#define PIN_INPUT_PULLUP		1
#define PIN_OUTPUT_LOW			2
#define PIN_OUTPUT_HIGH			3
//-----------------------------------------------------------------------------
//I use macros to simplify bit setting and I also use macros to test bits
#define BIT(bitn) (1 << (bitn))
#define BITSSET(portn, bits) ((portn) |= (bits))
#define BITSCLEAR(portn, bits) ((portn) &= (~(bits)))
#define BITSET(portn, bitn) BITSSET((portn), (BIT((bitn))))
#define BITCLEAR(portn, bitn) BITSCLEAR((portn), (BIT((bitn))))
#define IS_BITSET(portn, bitn) ((portn) & (BIT(bitn)))
#define IS_BITCLEAR(portn, bitn) !IS_BITSET((portn), (bitn))
#define ARE_BITSSET(portn, bits) (((portn) & (bits)) == (bits))
#define ARE_BITSCLEAR(portn, bits) (((portn) & (bits)) == 0)
#define BITVALGET(portn, bitn) (((portn)>>(bitn)) & 1)
#define BITVALSET(portn, bitn, val) (portn = (portn & ~(1<<bitn)) | (val<<bitn))
#define BITTOGGLE(portn, bitn) (portn = portn ^ (1<<bitn))
//For example, if I want to set bit 2 in portd I would simply include the followin C command:
//SETBIT(PORTD,2);
//-----------------------------------------------------------------------------
//Enable an external EICRA interrupt
#define EN_EXT_EICRA_INT(intn, mode)\
({\
	BITCLEAR(EIMSK, intn);\
	EICRA = (EICRA & ~(11<<(2*intn))) | mode<<(2*intn);\
	BITSET(EIFR, intn);\
	BITSET(EIMSK, intn);\
})
//Disable an external interrupt
#define DIS_EXT_INT(intn)\
({\
	BITCLEAR(EIMSK, intn);\
	BITSET(EIFR, intn);\
})
//Set a pin as input or output
#define PIN_GENERAL_IO(ddrn, portn, bitn, mode)\
({\
	ddrn = (ddrn & ~(1<<bitn)) | (((mode & 2)>>1)<<bitn);\
	portn = (portn & ~(1<<bitn)) | 	((mode & 1)<<bitn);\
})
//-----------------------------------------------------------------------------
