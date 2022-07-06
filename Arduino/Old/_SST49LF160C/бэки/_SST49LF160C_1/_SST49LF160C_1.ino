#define lclk0 digitalWrite(5,LOW)
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
#define led1 digitalWrite(13,HIGH)

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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 7-4
  lad3_1;
  lad2_0;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 7-4
  lad3_1;
  lad2_1;
  lad1_0;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
}

void program (void) {
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 7-4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 7-4
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 7-4
  lad3_0;
  lad2_0;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 7-4
  lad3_1;
  lad2_1;
  lad1_0;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 7-4
  lad3_1;
  lad2_0;
  lad1_0;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
}

void write_acess_34 (void) {
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_0;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 7-4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 7-4
  lad3_1;
  lad2_0;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 7-4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    D3...D0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    D7...D4
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
}

void read_array (void) {
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 0-3
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 7-4
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_0;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    D3...D0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    D7...D4
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
}

void read_01 (void) {
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    D3...D0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    D7...D4
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
}

void read_status (void) {
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 0-3
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    DATA 7-4
  lad3_0;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
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
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  lframe1;
  delayMicroseconds(5);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A19-A16
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A15-A12
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A11-A8
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A7-A4
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    A3-A0
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delayMicroseconds(2);
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(2);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  delayMicroseconds(5);
  //////////////////////    RSYNC
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    D3...D0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    D7...D4
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR0
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
  //////////////////////    TAR1
  lclk1;
  delayMicroseconds(2);
  lclk0;
  delayMicroseconds(5);
}

void setup() {
  pinMode(2, OUTPUT);
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
  pinMode(13, OUTPUT);
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
  delayMicroseconds(2);
  rst1;
  delayMicroseconds(2);
  wp1;
  tbl1;
  lframe1;
  delayMicroseconds(100);
  write_acess_34();
  delayMicroseconds(500);  
  read_01();
  delayMicroseconds(500);
  sector_erase_01();
  delay(30);  
  read_array();
  delayMicroseconds(500);  
  read_01();
  delayMicroseconds(500);
  program();
  delayMicroseconds(10);
  write_01_00();
  delay(2);
  read_array();  
  delayMicroseconds(500);
  read_01();
  delayMicroseconds(20000);
  sector_erase_01();
  delay(30);  
  read_array();
  delayMicroseconds(500);  
  read_01();
  delayMicroseconds(500);
  program();
  delayMicroseconds(10);
  write_01_A5();
  delay(2);
  read_array();  
  delayMicroseconds(500);
  read_01();        
  /*read_01();
  delayMicroseconds(200);
  sector_erase_01();
  delay(5);
  delayMicroseconds(200);
  read_array();
  delayMicroseconds(200);
  program();
  delayMicroseconds(10);
  write_01_A5();
  delayMicroseconds(200);
  read_array();  
  delayMicroseconds(500);
  read_01();
  delayMicroseconds(200);
  sector_erase_01();
  delay(5);
  delayMicroseconds(200);
  read_array();
  delayMicroseconds(200);
  program();
  delayMicroseconds(10);
  write_01_00();
  delayMicroseconds(200);
  read_array();  
  delayMicroseconds(500);
  read_01();
  delayMicroseconds(500);
  write_ID();
  delayMicroseconds(200);
  read_ID();*/
}

void loop() {

}
