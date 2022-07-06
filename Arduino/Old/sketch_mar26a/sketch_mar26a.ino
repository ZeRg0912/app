#define DE0 digitalWrite(2, LOW);
#define DE1 digitalWrite(2, HIGH);
#define DI0 digitalWrite(3, LOW);
#define DI1 digitalWrite(3, HIGH);
#define RE0 digitalWrite(4, LOW);
#define RE1 digitalWrite(4, HIGH);
#define LED0 digitalWrite(13, LOW);
#define LED1 digitalWrite(13, HIGH);
#define RO digitalRead(5);

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(5, INPUT);
}

void loop() {
  DE1;
  RE0;
  DI1;
  if (digitalRead(5) == HIGH){
    LED1;
  }
  else{
    LED0;
  }
  delay(1000);
}
