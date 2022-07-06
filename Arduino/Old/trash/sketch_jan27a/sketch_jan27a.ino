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
  lframe1;
  gpi0_0;
  gpi1_0;
  wp0;
  tbl0;
  rst0;
  lad0_0;
  lad1_0;
  lad2_0;
  lad3_0;
  led0;
}

void loop() {
  // put your main code here, to run repeatedly:

}
