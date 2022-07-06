/*
 * protocol.h
 *
 * Created: 21/02/2017 3:21:20 PM
 *  Author: DaddyASUS
 */ 


#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#define MAX_INT_DIGITS 8

uint8_t read_float(char *line, uint8_t *char_counter, float *float_ptr);
void process_command(char *line);

#endif /* PROTOCOL_H_ */