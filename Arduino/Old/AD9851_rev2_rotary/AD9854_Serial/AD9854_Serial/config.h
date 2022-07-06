#ifndef CONFIG_H
#define CONFIG_H

#define F_CPU			16000000UL

#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "Macro.h"
#include "serial.h"
#include "AD9854.h"
#include "print.h"
#include "protocol.h"

//#define F_CPU			16000000UL

#endif