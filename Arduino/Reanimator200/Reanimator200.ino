#define yellow0 digitalWrite(2, LOW)
#define green0 digitalWrite(3, LOW)
#define red0 digitalWrite(6, LOW)
#define yellow1 digitalWrite(2, HIGH)
#define green1 digitalWrite(3, HIGH)
#define red1 digitalWrite(6, HIGH)
#define button digitalRead(5)

//#include <SPI.h>
#include <SD.h>             
#include <TMRpcm.h> 

const int chipSelect = 4;

TMRpcm music;

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
  music.play("sounds/3.wav");
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
  music.disable();
}

void engage (void){
  if (button == HIGH){
    green0;
    red0;
    //звук зарядки
    music.play("sounds/1.wav");
    yellow1; 
    red0;
    delay(2000); //время звука зарядки
    // звук импульса
    music.play("sounds/2.wav");
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
  Serial.begin(9600);
  Serial.println("Initializing SD card...");
  if (!SD.begin(chipSelect)) 
  {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  music.speakerPin = 9;
  music.setVolume(5);
  music.quality(1);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, INPUT);
  yellow0;
  green0;
  red0;
  music.disable();
  start();
}

void loop() {
  engage();
}
