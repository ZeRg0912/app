#include "config.h"

void printString(const char *s)
{
  while (*s)
    serial_write(*s++);
}
// Print a string stored in PGM-memory
void printPgmString(const char *s)
{
  char c;
  
  while ((c = pgm_read_byte_near(s++)))
    serial_write(c);
}

void print_uint8_base2(uint8_t n)
{ 
	unsigned char buf[8];
	uint8_t i = 0;

	for (; i < 8; i++) 
	{
		buf[i] = n & 1;
		n >>= 1;
	}

	for (; i > 0; i--)
		serial_write('0' + buf[i - 1]);
}

void print_uint8_base10(uint8_t n)
{ 
  if (n == 0) 
  {
    serial_write('0');
    return;
  } 

  unsigned char buf[3];
  uint8_t i = 0;

  while (n > 0) 
  {
      buf[i++] = n % 10 + '0';
      n /= 10;
  }

  for (; i > 0; i--)
      serial_write(buf[i - 1]);
}

void print_uint32_base10(uint32_t n)
{ 
  if (n == 0) 
  {
    serial_write('0');
    return;
  } 

  unsigned char buf[10]; 
  uint8_t i = 0;  
  
  while (n > 0) 
  {
    buf[i++] = n % 10;
    n /= 10;
  }
    
  for (; i > 0; i--)
    serial_write('0' + buf[i-1]);
}

void printInteger(long n)
{
  if (n < 0) 
  {
    serial_write('-');
    print_uint32_base10((-n));
  } 
  else 
    print_uint32_base10(n);
}
// Convert float to string by immediately converting to a long integer, which contains
// more digits than a float. Number of decimal places, which are tracked by a counter,
// may be set by the user. The integer is then efficiently converted to a string.
// NOTE: AVR '%' and '/' integer operations are very efficient. Bitshifting speed-up 
// techniques are actually just slightly slower. Found this out the hard way.
void printFloat(float n, uint8_t decimal_places)
{
  if (n < 0) 
  {
    serial_write('-');
    n = -n;
  }

  uint8_t decimals = decimal_places;
  
  while (decimals >= 2) 
  { // Quickly convert values expected to be E0 to E-4.
    n *= 100;
    decimals -= 2;
  }
  if (decimals) 
    n *= 10;
	
  n += 0.5; // Add rounding factor. Ensures carryover through entire value.
    
  // Generate digits backwards and store in string.
  unsigned char buf[10]; 
  uint8_t i = 0;
  uint32_t a = (long)n;  
  buf[decimal_places] = '.'; // Place decimal point, even if decimal places are zero.
  
  while(a > 0) 
  {
    if (i == decimal_places) { i++; } // Skip decimal point location
    buf[i++] = (a % 10) + '0'; // Get digit
    a /= 10;
  }
  
  while (i < decimal_places)
     buf[i++] = '0'; // Fill in zeros to decimal point for (n < 1)

  if (i == decimal_places) 
  { // Fill in leading zero, if needed.
    i++;
    buf[i++] = '0'; 
  }   
  
  // Print the generated string.
  for (; i > 0; i--)
    serial_write(buf[i-1]);
}
// Debug tool to print free memory in bytes at the called point. Not used otherwise.
void printFreeMemory()
{
  extern int __heap_start, *__brkval; 
  uint16_t free;  // Up to 64k values.
  free = (int) &free - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
  printInteger((int32_t)free);
  printString(" ");
}
