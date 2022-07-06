/*#define lclk0 PORTD &= ~(1 << 5);
#define lclk1 PORTD |= (1 << 5);

#define lframe0 PORTD &= ~(1 << 6);
#define lframe1 PORTD |= (1 << 6);

#define gpi0_0 PORTD &= ~(1 << 3);
#define gpi0_1 PORTD |= (1 << 3);

#define gpi1_0 PORTD &= ~(1 << 2);
#define gpi1_1 PORTD |= (1 << 2);

#define wp0 PORTB &= ~(1 << 4);
#define wp1 PORTB |= (1 << 4);

#define tbl0 PORTB &= ~(1 << 3);
#define tbl1 PORTB |= (1 << 3);

#define rst0 PORTD &= ~(1 << 4);
#define rst1 PORTD |= (1 << 4);

#define lad0_0 PORTB &= ~(1 << 2);
#define lad0_1 PORTB |= (1 << 2);

#define lad1_0 PORTB &= ~(1 << 1);
#define lad1_1 PORTB |= (1 << 1);

#define lad2_0 PORTB &= ~(1 << 0);
#define lad2_1 PORTB |= (1 << 0);

#define lad3_0 PORTD &= ~(1 << 7);
#define lad3_1 PORTD |= (1 << 7);

#define led0 PORTB &= ~(1 << 5);
#define led1 PORTB |= (1 << 5);*/

/*#define lclk0 digitalWrite(5,LOW)
#define lclk1 digitalWrite(5,HIGH)

#define lframe0 digitalWrite(6,LOW)
#define lframe1 digitalWrite(6,HIGH)

#define gpi0_0 digitalWrite(3,LOW)
#define gpi0_1 digitalWrite(3,HIGH)

#define gpi1_0 digitalWrite(2,LOW)
#define gpi1_1 digitalWrite(2,HIGH)

#define wp0 digitalWrite(12,LOW)
#define wp1 digitalWrite(12,HIGH)

#define tbl0 digitalWrite(11,LOW)
#define tbl1 digitalWrite(11,HIGH)

#define rst0 digitalWrite(4,LOW)
#define rst1 digitalWrite(4,HIGH)

#define lad0_0 digitalWrite(10,LOW)
#define lad0_1 digitalWrite(10,HIGH)

#define lad1_0 digitalWrite(9,LOW)
#define lad1_1 digitalWrite(9,HIGH)

#define lad2_0 digitalWrite(8,LOW)
#define lad2_1 digitalWrite(8,HIGH)

#define lad3_0 digitalWrite(7,LOW)
#define lad3_1 digitalWrite(7,HIGH)

#define led0 digitalWrite(13,LOW)
#define led1 digitalWrite(13,HIGH)*/

#define lclk0 bitWrite(PORTD, 5, 0);
#define lclk1 bitWrite(PORTD, 5, 1);

#define lframe0 bitWrite(PORTD, 6, 0);
#define lframe1 bitWrite(PORTD, 6, 1);

#define gpi0_0 bitWrite(PORTD, 3, 0);
#define gpi0_1 bitWrite(PORTD, 3, 1);

#define gpi1_0 bitWrite(PORTD, 2, 0);
#define gpi1_1 bitWrite(PORTD, 2, 1);

#define wp0 bitWrite(PORTB, 4, 0);
#define wp1 bitWrite(PORTB, 4, 1);

#define tbl0 bitWrite(PORTB, 3, 0);
#define tbl1 bitWrite(PORTB, 3, 1);

#define rst0 bitWrite(PORTD, 4, 0);
#define rst1 bitWrite(PORTD, 4, 1);

#define lad0_0 bitWrite(PORTB, 2, 0);
#define lad0_1 bitWrite(PORTB, 2, 1);

#define lad1_0 bitWrite(PORTB, 1, 0);
#define lad1_1 bitWrite(PORTB, 1, 1);

#define lad2_0 bitWrite(PORTB, 0, 0);
#define lad2_1 bitWrite(PORTB, 0, 1);

#define lad3_0 bitWrite(PORTD, 7, 0);
#define lad3_1 bitWrite(PORTD, 7, 1);

#define led0 bitWrite(PORTB, 5, 0);
#define led1 bitWrite(PORTB, 5, 1);

char lad0 = 0;
char lad1 = 0;
char lad2 = 0;
char lad3 = 0;

int data[8] = {0, 0, 0, 0, 0, 0, 0, 0};

long value = 0x0;
long value_adress = 0x0;
unsigned int bit_ctr_adress = 0;
long value_data = 0x0;
unsigned int bit_ctr_data = 0;
unsigned int access = 0;
unsigned int n_access = 0;
unsigned int erase = 0;
unsigned int n_erase = 0;
long i = 0x0;
boolean dat = false;
long size_write = 0x100;
long size_start = 0x0;
long check = 0x0;

char serial_data = 0;
long adress_all = 0;
char adress_p1 = 0;
char adress_p2 = 0;
char adress_p3 = 0;

void lad_F (void) {
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
}

void lad_E (void) {
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
}

void suspend (void) {
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;

  lclk1;

  lclk0;

  lframe1;

  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A31-A28
  lad_F();

  lclk1;

  lclk0;

  //////////////////////    A27-A24
  lad_F();

  lclk1;

  lclk0;

  //////////////////////    A23-A20
  lad_E();

  lclk1;

  lclk0;

  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    DATA 7-4
  lad3_1;
  lad2_0;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  //////////////////////    RSYNC
  lclk1;

  lclk0;

  //////////////////////    TAR0
  lclk1;

  lclk0;

  //////////////////////    TAR1
  lclk1;

  lclk0;

}

void resumee (void) {
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;

  lclk1;

  lclk0;

  lframe1;

  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A31-A28
  lad_F();

  lclk1;

  lclk0;

  //////////////////////    A27-A24
  lad_F();

  lclk1;

  lclk0;

  //////////////////////    A23-A20
  lad_E();

  lclk1;

  lclk0;

  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    DATA 7-4
  lad3_1;
  lad2_1;
  lad1_0;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  //////////////////////    RSYNC
  lclk1;

  lclk0;

  //////////////////////    TAR0
  lclk1;

  lclk0;

  //////////////////////    TAR1
  lclk1;

  lclk0;

}

void program (void) {
  DDRD = B11111100;
  DDRB = B11111111; 
 /* pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);*/
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;
  lclk1;
  lclk0;
  lframe1;
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A31-A28
  lad_F();
  lclk1;
  lclk0;
  //////////////////////    A27-A24
  lad_F();
  lclk1;
  lclk0;
  //////////////////////    A23-A20
  lad_E();
  lclk1;
  lclk0;
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    DATA 7-4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_1;
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  /*pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);*/
  DDRD = B01111100;
  DDRB = B11111000; 
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  //////////////////////    RSYNC
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lclk1;
  lclk0;
  //////////////////////    TAR1
  lclk1;
  lclk0;
}

void clear_status (void) {
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;

  lclk1;

  lclk0;

  lframe1;

  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A31-A28
  lad_F();

  lclk1;

  lclk0;

  //////////////////////    A27-A24
  lad_F();

  lclk1;

  lclk0;

  //////////////////////    A23-A20
  lad_E();

  lclk1;

  lclk0;

  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    DATA 7-4
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  //////////////////////    RSYNC
  lclk1;

  lclk0;

  //////////////////////    TAR0
  lclk1;

  lclk0;

  //////////////////////    TAR1
  lclk1;

  lclk0;

}

void block_erase (void) {  
  /*pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);*/
  DDRD = B11111100;
  DDRB = B11111111; 
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;
  lclk1;
  lclk0;
  lframe1;
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A31-A28
  lad_F();
  lclk1;
  lclk0;
  //////////////////////    A27-A24
  lad_F();
  lclk1;
  lclk0;
  //////////////////////    A23-A20
  lad_E();
  lclk1;
  lclk0;
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    DATA 7-4
  lad3_0;
  lad2_0;
  lad1_1;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  /*pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);*/
  DDRD = B01111100;
  DDRB = B11111000; 
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  //////////////////////    RSYNC
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lclk1;
  lclk0;
  //////////////////////    TAR1
  lclk1;
  lclk0;
  /*pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);*/
  DDRD = B11111100;
  DDRB = B11111111; 
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;
  lclk1;
  lclk0;
  lframe1;
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A31-A28
  lad_F();
  lclk1;
  lclk0;
  //////////////////////    A27-A24
  lad_F();
  lclk1;
  lclk0;
  //////////////////////    A23-A0
  value = value_adress;
  for (bit_ctr_adress = 0; bit_ctr_adress < 6; bit_ctr_adress++) {
    if (value & 0x800000)
    {
      lad3_1;
    }
    else
    {
      lad3_0;
    }
    if (value & 0x400000)
    {
      lad2_1;
    }
    else
    {
      lad2_0;
    }
    if (value & 0x200000)
    {
      lad1_1;
    }
    else
    {
      lad1_0;
    }
    if (value & 0x100000)
    {
      lad0_1;
    }
    else
    {
      lad0_0;
    }
    value = (value << 4);
    lclk1;
    lclk0;
  }
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    DATA 7-4
  lad3_1;
  lad2_1;
  lad1_0;
  lad0_1;
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  /*pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);*/
  DDRD = B01111100;
  DDRB = B11111000; 
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  //////////////////////    RSYNC
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lclk1;
  lclk0;
  //////////////////////    TAR1
  lclk1;
  lclk0;
}

void sector_erase_01 (void) {
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;
  lclk1;
  lclk0;
  lframe1;
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A31-A28
  lad_F();

  lclk1;

  lclk0;

  //////////////////////    A27-A24
  lad_F();

  lclk1;

  lclk0;

  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    DATA 7-4
  lad3_0;
  lad2_0;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  //////////////////////    RSYNC
  lclk1;

  lclk0;

  //////////////////////    TAR0
  lclk1;

  lclk0;

  //////////////////////    TAR1
  lclk1;

  lclk0;
  delayMicroseconds(10);
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;

  lclk1;

  lclk0;

  lframe1;

  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    DATA 7-4
  lad3_1;
  lad2_1;
  lad1_0;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  //////////////////////    RSYNC
  lclk1;

  lclk0;

  //////////////////////    TAR0
  lclk1;

  lclk0;

  //////////////////////    TAR1
  lclk1;

  lclk0;

}

void write_ID (void) {
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;

  lclk1;

  lclk0;

  lframe1;

  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    DATA 7-4
  lad3_1;
  lad2_0;
  lad1_0;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  //////////////////////    RSYNC
  lclk1;

  lclk0;

  //////////////////////    TAR0
  lclk1;

  lclk0;

  //////////////////////    TAR1
  lclk1;

  lclk0;

}

void write_acess (void) {
  /*pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);*/
  DDRD = B11111100;
  DDRB = B11111111;  
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;
  lclk1;
  lclk0;
  lframe1;
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A31-A28
  lad_F();
  lclk1;
  lclk0;
  //////////////////////    A27-A24
  lad_F();
  lclk1;
  lclk0;
  //////////////////////    A23-A0
  value = value_adress;
  for (bit_ctr_adress = 0; bit_ctr_adress < 6; bit_ctr_adress++) {
    if (value & 0x800000)
    {
      lad3_1;
    }
    else
    {
      lad3_0;
    }
    if (value & 0x400000)
    {
      lad2_1;
    }
    else
    {
      lad2_0;
    }
    if (value & 0x200000)
    {
      lad1_1;
    }
    else
    {
      lad1_0;
    }
    if (value & 0x100000)
    {
      lad0_1;
    }
    else
    {
      lad0_0;
    }
    value = (value << 4);
    lclk1;
    lclk0;
  }
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    DATA 7-4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  /*pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);*/
  DDRD = B01111100;
  DDRB = B11111000;  
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  //////////////////////    RSYNC
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lclk1;
  lclk0;
  //////////////////////    TAR1
  lclk1;
  lclk0;
}

void write_01_A5 (void) {
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;

  lclk1;

  lclk0;

  lframe1;

  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    DATA 0-3
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    DATA 7-4
  lad3_1;
  lad2_0;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  //////////////////////    RSYNC
  lclk1;

  lclk0;

  //////////////////////    TAR0
  lclk1;

  lclk0;

  //////////////////////    TAR1
  lclk1;

  lclk0;

}

void write_01_00 (void) {
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;

  lclk1;

  lclk0;

  lframe1;

  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    DATA 7-4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  //////////////////////    RSYNC
  lclk1;

  lclk0;

  //////////////////////    TAR0
  lclk1;

  lclk0;

  //////////////////////    TAR1
  lclk1;

  lclk0;

}

void read_ID (void) {
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;

  lclk1;

  lclk0;

  lframe1;

  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  //////////////////////    RSYNC
  lclk1;

  lclk0;

  //////////////////////    D3...D0
  lclk1;

  lclk0;

  //////////////////////    D7...D4
  lclk1;

  lclk0;

  //////////////////////    TAR0
  lclk1;

  lclk0;

  //////////////////////    TAR1
  lclk1;

  lclk0;

}

void read_array (void) {
 /* pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);*/
  DDRD = B11111100;
  DDRB = B11111111;  
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;
  lclk1;
  lclk0;
  lframe1;
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    DATA 0-3
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  //////////////////////    DATA 7-4
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  /*pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);*/
  DDRD = B01111100;
  DDRB = B11111000;
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  //////////////////////    RSYNC
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lclk1;
  lclk0;
  //////////////////////    TAR1
  lclk1;
  lclk0;
}

void read_acess_34 (void) {
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;

  lclk1;

  lclk0;

  lframe1;

  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    A23-A20
  lad3_1;
  lad2_0;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  //////////////////////    RSYNC
  lclk1;

  lclk0;

  //////////////////////    D3...D0
  lclk1;

  lclk0;

  //////////////////////    D7...D4
  lclk1;

  lclk0;

  //////////////////////    TAR0
  lclk1;

  lclk0;

  //////////////////////    TAR1
  lclk1;

  lclk0;

}

void read_status (void) {  
  /*pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);*/
  DDRD = B11111100;
  DDRB = B11111111;  
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;
  lclk1;
  lclk0;
  lframe1;
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    DATA 7-4
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  /*pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);*/
  DDRD = B01111100;
  DDRB = B11111000;  
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  //////////////////////    RSYNC
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lclk1;
  lclk0;
  //////////////////////    TAR1
  lclk1;
  lclk0;
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;
  lclk1;
  lclk0;
  lframe1;
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  //////////////////////    RSYNC
  lclk1;
  lclk0;
  //////////////////////    D3...D0
  lclk1;
  lclk0;
  //////////////////////    D7...D4
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lclk1;
  lclk0;
  //////////////////////    TAR1
  lclk1;
  lclk0;
}

void read_loop (void) {
  /*pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);*/
  DDRD = B11111100;
  DDRB = B11111111;  
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;
  lclk1;
  lclk0;
  lframe1;
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A31-A28
  lad_F();
  lclk1;
  lclk0;
  //////////////////////    A27-A24
  lad_F();
  lclk1;
  lclk0;
  //////////////////////    A23-A20
  lad_E();
  lclk1;
  lclk0;
  //////////////////////    A19-A0
  value = value_adress;
  for (bit_ctr_adress = 0; bit_ctr_adress < 5; bit_ctr_adress++) {
    if (value & 0x80000)
    {
      lad3_1;
    }
    else
    {
      lad3_0;
    }
    if (value & 0x40000)
    {
      lad2_1;
    }
    else
    {
      lad2_0;
    }
    if (value & 0x20000)
    {
      lad1_1;
    }
    else
    {
      lad1_0;
    }
    if (value & 0x10000)
    {
      lad0_1;
    }
    else
    {
      lad0_0;
    }
    value = (value << 4);
    lclk1;
    lclk0;
  }
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  /*pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);*/
  DDRD = B01111100;
  DDRB = B11111000;  
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  //////////////////////    RSYNC
  lclk1;
  lclk0;
  //////////////////////    D3...D0
  lclk1;
  lclk0;
  data[4] = bitRead(PIND, 7);
  data[5] = bitRead(PINB, 0);
  data[6] = bitRead(PINB, 1);
  data[7] = bitRead(PINB, 2);
  bitWrite(serial_data, 7, data[7]);
  bitWrite(serial_data, 6, data[6]);
  bitWrite(serial_data, 5, data[5]);
  bitWrite(serial_data, 4, data[4]);
  //////////////////////    D7...D4
  lclk1;
  lclk0;
  data[0] = bitRead(PIND, 7);
  data[1] = bitRead(PINB, 0);
  data[2] = bitRead(PINB, 1);
  data[3] = bitRead(PINB, 2);
  bitWrite(serial_data, 3, data[3]);
  bitWrite(serial_data, 2, data[2]);
  bitWrite(serial_data, 1, data[1]);
  bitWrite(serial_data, 0, data[0]);
  //////////////////////    TAR0
  lclk1;
  lclk0;
  //////////////////////    TAR1
  lclk1;
  lclk0;
    Serial.print(adress_p3);
    Serial.print(adress_p2);
    Serial.print(adress_p1);
    Serial.print("/"); 
    Serial.print(serial_data);
    Serial.print("."); 
}

void write_AA (void) {
  //////////////////////    DATA 0-3
  lad3_1;
  lad2_0;
  lad1_1;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    DATA 7-4
  lad3_1;
  lad2_0;
  lad1_1;
  lad0_0;
  lclk1;
  lclk0;
}

void write_55 (void) {
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_1;
  lclk1;
  lclk0;
  //////////////////////    DATA 7-4
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_1;
  lclk1;
  lclk0;
}

void write_access_all (void) {
  value_adress = 0xA00002;
  for (access = 0; access < 32; access++) {
    write_acess();
    value_adress = value_adress + 0x10000;
  }
}

void block_erase_all (void) {
  value_adress = 0xE00000;
  for (erase = 0; erase < 32; erase++) {
    block_erase();
    value_adress = value_adress + 0x10000;
    delay(50);
  }
}

void write_loop (void) {
  /*pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);*/
  DDRD = B11111100;
  DDRB = B11111111;
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;
  lclk1;
  lclk0;
  lframe1;
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  lclk1;
  lclk0;
  //////////////////////    A31-A28
  lad_F();
  lclk1;
  lclk0;
  //////////////////////    A27-A24
  lad_F();
  lclk1;
  lclk0;
  //////////////////////    A23-A20
  lad_E();
  lclk1;
  lclk0;
  //////////////////////    A19-A0
  value = value_adress;
  for (bit_ctr_adress = 0; bit_ctr_adress < 5; bit_ctr_adress++) {
    if (value & 0x80000)
    {
      lad3_1;
    }
    else
    {
      lad3_0;
    }
    if (value & 0x40000)
    {
      lad2_1;
    }
    else
    {
      lad2_0;
    }
    if (value & 0x20000)
    {
      lad1_1;
    }
    else
    {
      lad1_0;
    }
    if (value & 0x10000)
    {
      lad0_1;
    }
    else
    {
      lad0_0;
    }
    value = (value << 4);
    lclk1;
    lclk0;
  }
  if (dat == 1) {
    write_AA();
  }
  else {
    write_55();
  }
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  lclk1;
  lclk0;
  /*pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);*/
  DDRD = B01111100;
  DDRB = B11111000;
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  //////////////////////    RSYNC
  lclk1;
  lclk0;
  //////////////////////    TAR0
  lclk1;
  lclk0;
  //////////////////////    TAR1
  lclk1;
  lclk0;
  delayMicroseconds(10);
}

void write_all (void) {
  value_adress = size_start;
  for (i = size_start; i < size_write; i++) {
    program();
    write_loop();
    if (dat == true){
      dat = false;
    }
    else{
      dat = true;
    }
    value_adress++;
    //delay(10);
  }
}

void read_all (void) {
  value_adress = size_start;
  dat = 0;
  for (i = size_start; i < size_write; i++) {
    read_loop();
    value_adress++;
    if ((dat == 1) & (data[0] == 1) & (data[1] == 0) & (data[2] == 1) & (data[3] == 0) & (data[4] == 1) & (data[5] == 0) & (data[6] == 1) & (data[7] == 0)) {      
      check++;
    }
    else if ((dat == 0) & (data[0] == 0) & (data[1] == 1) & (data[2] == 0) & (data[3] == 1) & (data[4] == 0) & (data[5] == 1) & (data[6] == 0) & (data[7] == 1)){
      check++;
    }
    else{      
    }
    if (dat == true){
      dat = false;
    }
    else{
      dat = true;
    }
  }
  if (check > (size_write - 1)){
    led1;
  }
  else{
    led0;
  }
}

void reprog (void){ 
  read_01();
  sector_erase_01();
  //delay(30);  
  read_array();
  read_01();
  program();
  write_01_00();
  read_array();  
  read_01();
  sector_erase_01();
  //delay(30);  
  read_array(); 
  read_01();
  program();
  write_01_A5();
  read_array();  
  read_01();   
}

void read_01 (void) {
  /*pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);*/
  DDRD = B11111100;
  DDRB = B11111111;
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;

  lclk1;

  lclk0;

  lframe1;

  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  lclk1;

  lclk0;

  //////////////////////    A3-A0
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_1;

  lclk1;

  lclk0;

  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;

  lclk1;

  lclk0;

  /*pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);*/
  DDRD = B01111100;
  DDRB = B11111000;
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;

  //////////////////////    RSYNC
  lclk1;

  lclk0;

  //////////////////////    D3...D0
  lclk1;

  lclk0;

  //////////////////////    D7...D4
  lclk1;

  lclk0;

  //////////////////////    TAR0
  lclk1;

  lclk0;

  //////////////////////    TAR1
  lclk1;

  lclk0;

}

void write_once (void) {
  //block_erase_all();
  value_adress = 0x0;
  read_array();
  value_adress = 0x0;
  write_all();
  value_adress = 0x0;
}

void setup() {
  Serial.begin(4800);
  DDRD = B11111100;
  DDRB = B11111111;
  /*pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);*/
  check = 0;
  lclk0;
  lframe0;
  gpi0_0;
  gpi1_0;
  wp0;
  tbl0;
  rst0;
  lad0_1;
  lad1_1;
  lad2_1;
  lad3_1;
  led0;
  rst1;
  wp1;
  tbl1;
  lframe1;
  value_adress = 0x0;
  erase = 0;
  access = 0;
  delay(1000);
  write_access_all();
  value_adress = 0x0;
  block_erase_all();
  read_array();
  value_adress = 0x0;
  write_access_all();
  value_adress = 0x0;
  write_once();
  value_adress = 0x0;
  read_array();
  read_all();
}

void loop() {
  
}
