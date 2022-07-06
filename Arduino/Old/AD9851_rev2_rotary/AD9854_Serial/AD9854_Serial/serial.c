#include "config.h"

//uint32_t f_cpu;

uint8_t serial_rx_buffer[RX_BUFFER_SIZE];
uint8_t serial_rx_buffer_head = 0;
volatile uint8_t serial_rx_buffer_tail = 0;

uint8_t serial_tx_buffer[TX_BUFFER_SIZE];
uint8_t serial_tx_buffer_head = 0;
volatile uint8_t serial_tx_buffer_tail = 0;

static char line[LINE_BUFFER_SIZE]; // Line to be executed. Zero-terminated.

// Returns the number of bytes used in the RX serial buffer.
uint8_t serial_get_rx_buffer_count(void)
{
  uint8_t rtail = serial_rx_buffer_tail; // Copy to limit multiple calls to volatile
  if (serial_rx_buffer_head >= rtail) { return(serial_rx_buffer_head-rtail); }
  return (RX_BUFFER_SIZE - (rtail-serial_rx_buffer_head));
}


// Returns the number of bytes used in the TX serial buffer.
// NOTE: Not used except for debugging and ensuring no TX bottlenecks.
uint8_t serial_get_tx_buffer_count(void)
{
  uint8_t ttail = serial_tx_buffer_tail; // Copy to limit multiple calls to volatile
  if (serial_tx_buffer_head >= ttail) { return(serial_tx_buffer_head-ttail); }
  return (TX_BUFFER_SIZE - (ttail-serial_tx_buffer_head));
}


void serial_init(void)
{
  //f_cpu = F_CPU;
  // Set baud rate
  #if BAUD_RATE < 57600
    uint16_t UBRR0_value = ((F_CPU / (8L * BAUD_RATE)) - 1)/2 ;
    UCSR0A &= ~(1 << U2X0); // baud doubler off  - Only needed on Uno XXX
  #else
    uint16_t UBRR0_value = ((F_CPU / (4L * BAUD_RATE)) - 1)/2;
    UCSR0A |= (1 << U2X0);  // baud doubler on for high baud rates, i.e. 115200
  #endif
  UBRR0H = UBRR0_value >> 8;
  UBRR0L = UBRR0_value;
            
  // enable rx and tx
  UCSR0B |= 1<<RXEN0;
  UCSR0B |= 1<<TXEN0;
	
  // enable interrupt on complete reception of a byte
  UCSR0B |= 1<<RXCIE0;
	  
  // defaults to 8-bit, no parity, 1 stop bit
}


// Writes one byte to the TX serial buffer. Called by main program.
// TODO: Check if we can speed this up for writing strings, rather than single bytes.
void serial_write(uint8_t data) 
{
  // Calculate next head
  uint8_t next_head = serial_tx_buffer_head + 1;
  if (next_head == TX_BUFFER_SIZE) { next_head = 0; }

  // Wait until there is space in the buffer
  while (next_head == serial_tx_buffer_tail) 
  { 
  }

  // Store data and advance head
  serial_tx_buffer[serial_tx_buffer_head] = data;
  serial_tx_buffer_head = next_head;
  
  // Enable Data Register Empty Interrupt to make sure tx-streaming is running
  UCSR0B |=  (1 << UDRIE0); 
}


// Data Register Empty Interrupt handler
ISR(USART_UDRE_vect)
{
  uint8_t tail = serial_tx_buffer_tail; // Temporary serial_tx_buffer_tail (to optimize for volatile)
  
  // Send a byte from the buffer	
  UDR0 = serial_tx_buffer[tail];
  
  // Update tail position
  tail++;
  if (tail == TX_BUFFER_SIZE) { tail = 0; }
  
  serial_tx_buffer_tail = tail;
  
  // Turn off Data Register Empty Interrupt to stop tx-streaming if this concludes the transfer
  if (tail == serial_tx_buffer_head) { UCSR0B &= ~(1 << UDRIE0); }
}

// Fetches the first byte in the serial read buffer. Called by main program.
uint8_t serial_read(void)
{
  uint8_t tail = serial_rx_buffer_tail; // Temporary serial_rx_buffer_tail (to optimize for volatile)
  if (serial_rx_buffer_head == tail) 
    return SERIAL_NO_DATA;
  else 
  {
    uint8_t data = serial_rx_buffer[tail];
    
    tail++;
    if (tail == RX_BUFFER_SIZE) 
		tail = 0;
    serial_rx_buffer_tail = tail;

    return data;
  }
}

ISR(USART_RX_vect)
{
  uint8_t data = UDR0;
  uint8_t next_head;
  
  switch (data) 
  {
    default: // Write character to buffer    
      next_head = serial_rx_buffer_head + 1;
      if (next_head == RX_BUFFER_SIZE) 
		  next_head = 0;
    
      // Write data to buffer unless it is full.
      if (next_head != serial_rx_buffer_tail) 
	  {
        serial_rx_buffer[serial_rx_buffer_head] = data;
        serial_rx_buffer_head = next_head;    
      }
  }
}
//
void serial_reset_read_buffer(void) 
{
  serial_rx_buffer_tail = serial_rx_buffer_head;
}
//
void serial_loop(void)
{
	uint8_t iscomment = false;
	uint8_t char_counter = 0;
	uint8_t c;
	
	printString("This is the AD9854 controller\n");
	
	for (;;) 
	{
		while((c = serial_read()) != SERIAL_NO_DATA) 
		{
			if ((c == '\n') || (c == '\r')) 
			{ // End of line reached
				line[char_counter] = 0; // Set string termination character.
				process_command(line); // Line is complete. Execute it!
				iscomment = false;
				char_counter = 0;
			} 
			else 
			{
				if (iscomment) 
				{
					// Throw away all comment characters
					if (c == ')') 
						// End of comment. Resume line.
						iscomment = false;
				} 
				else 
				{
					if (c <= ' ') 
					{
						// Throw away whitespace and control characters
					} 
					else if (c == '/') 
					{
						// Block delete NOT SUPPORTED. Ignore character.
						// NOTE: If supported, would simply need to check the system if block delete is enabled.
					} 
					else if (c == '(') 
						iscomment = true;
					else if (char_counter >= (LINE_BUFFER_SIZE-1)) 
					{
						// Detect line buffer overflow. Report error and reset line buffer.
						//report_status_message(STATUS_OVERFLOW);
						iscomment = false;
						char_counter = 0;
					} 
					else if (c >= 'a' && c <= 'z') 
					{ // Uppercase lowercase
						line[char_counter++] = c - 'a' + 'A';
					} 
					else 
						line[char_counter++] = c;
				}
			}
		}
	}
	
	return; // Never reached
}
