#define yellow0 digitalWrite(2, LOW)
#define green0 digitalWrite(3, LOW)
#define red0 digitalWrite(4, LOW)
#define yellow1 digitalWrite(2, HIGH)
#define green1 digitalWrite(3, HIGH)
#define red1 digitalWrite(4, HIGH)
#define button digitalRead(5)

#include <SPI.h>
#include <SD.h>             
#include <TMRpcm.h> 

#define SD_ChipSelectPin 7

TMRpcm tmrpcm;

void start (void){
  delay(1000);
  yellow1;
  delay(1000);
  yellow0;
  delay(1000);
  yellow1;
  delay(1000);
  yellow0;
  delay(1000);
  yellow1;
  delay(1000);
  yellow0;
  delay(1000);
  green1;
}

void reload (void){
  tone(9, 500, 500);
  delay(500);  
  yellow1;
  tone(9, 1000, 500);
  delay(500);  
  yellow0;
  tone(9, 500, 500);
  delay(500);  
  yellow1;
  tone(9, 1000, 500);
  delay(500);  
  yellow0;
  tone(9, 500, 500);
  delay(500);  
  yellow1;
  tone(9, 1000, 500);
  delay(500);  
  yellow0;
  tone(9, 500, 500);
  delay(500);
  green1;
}

void engage (void){
  if (button == HIGH){
    green0;
    red0;
    //звук зарядки
    tone(9, 1000, 2000);
    yellow1; 
    red0;
    delay(2000); //время звука зарядки
    // звук импульса
    tone(9, 3000, 1000);
    yellow0; 
    red1;
    delay(1000); //время звука импульса
    reload(); 
  }
  else if (button == LOW){
    yellow0;
    red0;
    green1; 
  }
}

void setup() {
  tmrpcm.speakerPin = 9;
  tmrpcm.volume(1);
  tmrpcm.play("1.wav");
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, INPUT);
  yellow0;
  green0;
  red0;
  start();
}

void loop() {
  engage();
}
