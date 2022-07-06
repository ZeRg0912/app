
#define DDS_CLOCK 300000000

#define  UD_CLK 53  //AD9854 UD_CLOCK
#define  WD     52  //Write parallel data
#define  RESET  51  //Master Reset

/* Ref-Clock des AD9854 */
#define AD9854_REFCLK            30000000UL

/* Register */
#define AD9854_PHASE1_H          0x00
#define AD9854_PHASE1_L          0x01
#define AD9854_PHASE2_H          0x02
#define AD9854_PHASE2_L          0x03
#define AD9854_FREQ1_5           0x04
#define AD9854_FREQ1_4           0x05
#define AD9854_FREQ1_3           0x06
#define AD9854_FREQ1_2           0x07
#define AD9854_FREQ1_1           0x08
#define AD9854_FREQ1_0           0x09
#define AD9854_FREQ2_5           0x0A
#define AD9854_FREQ2_4           0x0B
#define AD9854_FREQ2_3           0x0C
#define AD9854_FREQ2_2           0x0D
#define AD9854_FREQ2_1           0x0E
#define AD9854_FREQ2_0           0x0F
#define AD9854_DELTA_5           0x10
#define AD9854_DELTA_4           0x11
#define AD9854_DELTA_3           0x12
#define AD9854_DELTA_2           0x13
#define AD9854_DELTA_1           0x14
#define AD9854_DELTA_0           0x15
#define AD9854_UPDCLOCK_3        0x16
#define AD9854_UPDCLOCK_2        0x17
#define AD9854_UPDCLOCK_1        0x18
#define AD9854_UPDCLOCK_0        0x19
#define AD9854_RMPRTCLOCK_2      0x1A
#define AD9854_RMPRTCLOCK_1      0x1B
#define AD9854_RMPRTCLOCK_0      0x1C
#define AD9854_CONTROLWRD_3      0x1D
#define AD9854_CONTROLWRD_2      0x1E
#define AD9854_CONTROLWRD_1      0x1F
#define AD9854_CONTROLWRD_0      0x20
#define AD9854_OSKMULT_I_H       0x21
#define AD9854_OSKMULT_I_L       0x22
#define AD9854_OSKMULT_Q_H       0x23
#define AD9854_OSKMULT_Q_L       0x24
#define AD9854_OSKRMPRT          0x25
#define AD9854_QDAC_H            0x26
#define AD9854_QDAC_L            0x27


/* AD9854-Reset */
void ad9854_reset( void )
{
   digitalWrite(RESET,LOW);
   delay(1);
   digitalWrite(RESET,HIGH);
   delay(1);
   digitalWrite(RESET,LOW);
   delay(1);
}

/* AD9854 init */
void ad9854_init( void )
{
   ad9854_reset();
}

void ad9854_set_data( uint8_t data )
{
   PORTF = data;
}

/* AD9854-Adresse anlegen */
void ad9854_set_addr( uint8_t addr )
{
   PORTK = addr;
}

/* AD9854-Write registers*/
void ad9854_write( uint8_t addr, uint8_t data )
{
   digitalWrite(WD,HIGH);   // WR high
   ad9854_set_addr( addr );
   digitalWrite(WD,LOW);  // WR low
   ad9854_set_data( data );
   digitalWrite(WD,HIGH);   // WR high

   digitalWrite(UD_CLK,HIGH);
   digitalWrite(UD_CLK,LOW);
}

void ad9854_set_update_clock(uint32_t v )
{
   ad9854_write( AD9854_UPDCLOCK_0, v );
   ad9854_write( AD9854_UPDCLOCK_1, v>>8 );
   ad9854_write( AD9854_UPDCLOCK_2, v>>16 );
   ad9854_write( AD9854_UPDCLOCK_3, v>>24 );
}

void ad9854_set_freq_1(uint64_t f)
{
   ad9854_write( AD9854_FREQ1_0, f );
   ad9854_write( AD9854_FREQ1_1, f>>8 );
   ad9854_write( AD9854_FREQ1_2, f>>16 );
   ad9854_write( AD9854_FREQ1_3, f>>24 );
   ad9854_write( AD9854_FREQ1_4, f>>32 );
   ad9854_write( AD9854_FREQ1_5, f>>40 );
}
void setup()
{
  pinMode (UD_CLK, OUTPUT); 
  pinMode (WD,  OUTPUT); 
  pinMode (RESET, OUTPUT); 
  ad9854_init();
  ad9854_set_freq_1(28000000);
}

void loop()
{

  //TODO: Some work

}
