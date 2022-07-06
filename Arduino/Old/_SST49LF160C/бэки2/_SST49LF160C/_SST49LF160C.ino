#define lclk0 digitalWrite(5,LOW)
#define lclk1 digitalWrite(5,HIGH)

#define lframe0 digitalWrite(6,LOW)
#define lframe1 digitalWrite(6,HIGH)

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

void read_ (void) {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  //lclk1;
  //delay(5);
  //lclk0;
  delay(10);
  //////////////////////    START
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  lframe0;
  delay(5);
  lclk1;
  delay(5);
  lclk0;
  lframe1;
  delay(10);
  //////////////////////    DIRECTION
  lad3_0;
  lad2_1;
  lad1_0;
  lad0_0;
  delay(5);
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  //////////////////////    A31-A28
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delay(5);
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  //////////////////////    A27-A24
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delay(5);
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  //////////////////////    A23-A20
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delay(5);
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  //////////////////////    A19-A16
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delay(5);
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  //////////////////////    A15-A12
  lad3_1;
  lad2_0;
  lad1_1;
  lad0_1;
  delay(5);
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  //////////////////////    A11-A8
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delay(5);
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  //////////////////////    A7-A4
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delay(5);
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  //////////////////////    A3-A0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delay(5);
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  //////////////////////    TAR0
  lad3_1;
  lad2_1;
  lad1_1;
  lad0_1;
  delay(5);
  lclk1;
  delay(5);
  lclk0;
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  delay(10);
  //////////////////////    TAR1
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  //////////////////////    RSYNC
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  //////////////////////    D3...D0
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  //////////////////////    D7...D4
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  //////////////////////    TAR0
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  //////////////////////    TAR1
  lclk1;
  delay(5);
  lclk0;
  delay(10);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  lad3_0;
  lad2_0;
  lad1_0;
  lad0_0;
}

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(4, OUTPUT);
  rst1;
  lframe1;
  delay(100);
  read_();

}

void loop() {
  // put your main code here, to run repeatedly:

}
