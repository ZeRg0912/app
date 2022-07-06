#define yellow0 digitalWrite(2, LOW)
#define green0 digitalWrite(3, LOW)
#define red0 digitalWrite(4, LOW)
#define yellow1 digitalWrite(2, HIGH)
#define green1 digitalWrite(3, HIGH)
#define red1 digitalWrite(4, HIGH)
#define button digitalRead(5)

#include <SD.h>             
#include <TMRpcm.h> 

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  yellow0;
  green0;
  red0;
}

void start (void){
  delay(500);
  yellow1;
  delay(500);
  yellow0;
  delay(500);
  yellow1;
  delay(500);
  yellow0;
  delay(500);
  yellow1;
  delay(500);
  yellow0;
  delay(500);
  green1;
}

void engage (void){
  if (button == HIGH){
    green0;
    red0;
    
    yellow1; //звук зарядки
    red0;
    //delay() время звука зарядки
    
    yellow0; // звук импульса
    red1;
    //delay() время звука импульса
  }
  else if (button == LOW){
    yellow0;
    red0;
    green1;  
  }
}

void loop() {
  //start();
  //engage();
}
