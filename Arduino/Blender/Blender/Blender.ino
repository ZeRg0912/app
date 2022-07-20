#define button_1 2     // Кнопка режим РАД. ЗАГРЯЗНЕНИЯ
#define button_2 3     // Кнопка режим ХИМ. ЗАГРЯЗНЕНИЯ
#define button_3 4     // Кнопка режим ОЧИСТКА
#define button_4 5     // Кнопка режим ПЕРЕРАБОТКА
int rele_vibro = 6;    // реле

#define yellow A0         // желтый свет
#define green A1          // зеленый свет
#define blue A2           // синий свет
#define PERIOD_1 100
#define PERIOD_2 200
#define PERIOD_5 500
#define PERIOD2 2000
#define PERIOD1 1000
#define PERIOD5 5000
#define PERIOD10 10000
#define PERIOD20 20000
#define PERIOD30 30000
#define PERIOD40 40000
#define PERIOD45 45000
#define PERIOD120 120000
#define PERIOD123 123000
int volt_mode_4 = 200;
unsigned long timer_1, timer_2, timer_5, timer1, timer2, timer5, timer10, timer20;
unsigned long timer_audio_2, timer_audio_2_1, timer_audio_5, timer_audio_10, timer_audio_20, timer_audio_120;
unsigned long timer_switch_yellow_1, timer_switch_green_1;
unsigned long timer_volt_mode_4;
unsigned long timer_vibro, timer_ready_mode_4, timer_ready_mode_5;

#include <SD.h>            // необходимо включить SD библиотеку
#include <TMRpcm.h>        // также необходимо включить данную библиотеку...
#include <SPI.h>

const int chipSelect = 7;
int volt_meter = 3;      // Значение на ВОЛЬТМЕТР
int value_volt = 0;
TMRpcm music;   // создать объект для использования в данном скетче
boolean flag_volt = false;
boolean flag_start_sound_1 = false;
boolean flag_start_sound_2 = false;
boolean flag_start_sound_3 = false;
boolean flag_start_sound_4 = false;
boolean flag_start_sound_5 = false;
boolean flag_start_sound_ready_4 = false;
boolean flag_start_sound_ready_5 = false;
boolean flag_start_sound_120 = false;
boolean flag_sound_120 = false;
boolean flag_sound_5 = false;
boolean flag_sound_4 = false;
boolean flag_sound_3 = false;
boolean flag_sound_2 = false;
boolean flag_sound_1 = false;
boolean switch_yellow = false;
boolean switch_green = false;
boolean flag_sound_ready_5 = false;
boolean flag_sound_ready_4 = false;
boolean flag_vibro = false;
boolean start_1 = true;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing SD card...");
  if (!SD.begin(chipSelect))
  {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  music.speakerPin = 9;   // 11 на Mega, 9 на Uno, Nano и т.д.
  music.setVolume(4);     //   от 0 до 7. Установка уровня громкости
  music.quality(1);       //  1 для 2x передескритезации, 0 for для нормального режима
  timer_1 = millis();
  timer_2 = millis();
  timer_5 = millis();
  timer1 = millis();
  timer2 = millis();
  timer5 = millis();
  timer10 = millis();
  timer20 = millis();
  timer_audio_2 = millis();
  timer_audio_2_1 = millis();
  timer_audio_5 = millis();
  timer_audio_10 = millis();
  timer_audio_20 = millis();
  timer_audio_120 = millis();
  timer_switch_yellow_1 = millis();
  timer_switch_green_1 = millis();
  timer_volt_mode_4 = millis();
  timer_ready_mode_4 = millis();
  timer_ready_mode_5 = millis();
  timer_vibro = millis();
  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);
  pinMode(button_3, INPUT);
  pinMode(button_4, INPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(rele_vibro, OUTPUT);
  pinMode(volt_meter, OUTPUT);
  digitalWrite(rele_vibro, HIGH);
  mode_1();
  //music.disable();
  delay(2000);
  music.disable();
}

//////////////////////////////////////////////////////
void refresh (void) {
  timer_1 = millis();
  timer_2 = millis();
  timer_5 = millis();
  timer1 = millis();
  timer2 = millis();
  timer5 = millis();
  timer10 = millis();
  timer20 = millis();
  timer_audio_2 = millis();
  timer_audio_2_1 = millis();
  timer_audio_5 = millis();
  timer_audio_10 = millis();
  timer_audio_20 = millis();
  timer_audio_120 = millis();
  timer_switch_yellow_1 = millis();
  timer_switch_green_1 = millis();
  timer_volt_mode_4 = millis();
  timer_ready_mode_4 = millis();
  timer_ready_mode_5 = millis();
  timer_vibro = millis();
  digitalWrite(yellow, LOW);     // гасим зеленый светодиод
  digitalWrite(blue, LOW);     // гасим синий светодиод
  digitalWrite(green, LOW);     // гасим синий светодиод
  digitalWrite(rele_vibro, HIGH);
  flag_volt = false;
  flag_start_sound_2 = false;
  flag_start_sound_3 = false;
  flag_start_sound_4 = false;
  flag_start_sound_5 = false;
  flag_start_sound_ready_4 = false;
  flag_start_sound_ready_5 = false;
  flag_start_sound_120 = false;
  flag_sound_120 = false;
  flag_sound_5 = false;
  flag_sound_4 = false;
  flag_sound_3 = false;
  flag_sound_2 = false;
  switch_yellow = false;
  switch_green = false;
  flag_sound_ready_5 = false;
  flag_sound_ready_4 = false;
  flag_vibro = false;
  music.disable();
  timer_disable_vibro();
  timer_change_volt_mode_4();
  timer_change_ready_mode_4();
  timer_change_ready_mode_5();
  timer_disable_audio_2();
  timer_disable_audio_20();
  timer_disable_audio_120();
  timer_switch_green();
  timer_switch_yellow();
}

void timer_change_ready_mode_4 (void) {
  if (millis() - timer_ready_mode_4 >= PERIOD123) {
    timer_ready_mode_4 = millis();
    flag_sound_ready_4 = true;
  }
}

void timer_change_ready_mode_5 (void) {
  if (millis() - timer_ready_mode_5 >= PERIOD123) {
    timer_ready_mode_5 = millis();
    flag_sound_ready_5 = true;
  }
}

void timer_change_volt_mode_4 (void) {
  if (millis() - timer_volt_mode_4 >= PERIOD1) {
    timer_volt_mode_4 = millis();
    volt_mode_4 -= 5;
  }
}

void timer_disable_vibro (void) {
  if (millis() - timer_vibro >= PERIOD5) {
    timer_vibro = millis();
    flag_vibro = !flag_vibro;
  }
}

void timer_disable_audio_2_1 (void) {
  if (millis() - timer_audio_2_1 >= PERIOD2) {
    timer_audio_2_1 = millis();
    flag_sound_1 = true;
  }
}

void timer_disable_audio_2 (void) {
  if (millis() - timer_audio_2 >= PERIOD2) {
    timer_audio_2 = millis();
    flag_sound_2 = true;
    flag_sound_3 = true;
    flag_sound_4 = true;
    flag_sound_5 = true;
  }
}

void timer_disable_audio_10 (void) {
  if (millis() - timer_audio_10 >= PERIOD10) {
    timer_audio_10 = millis();
    flag_sound_2 = false;
    flag_start_sound_2 = false;
  }
}

void timer_disable_audio_20 (void) {
  if (millis() - timer_audio_20 >= PERIOD20) {
    timer_audio_20 = millis();
    flag_sound_2 = false;
    flag_start_sound_2 = false;
    flag_sound_3 = false;
    flag_start_sound_3 = false;
    flag_sound_4 = false;
    flag_start_sound_4 = false;
    flag_sound_5 = false;
    flag_start_sound_5 = false;
  }
}

void timer_disable_audio_120 (void) {
  if (millis() - timer_audio_120 >= PERIOD120) {
    timer_audio_120 = millis();
    flag_sound_120 = true;
  }
}

void timer_switch_yellow (void) {
  if (millis() - timer_switch_yellow_1 >= PERIOD1) {
    timer_switch_yellow_1 = millis();
    switch_yellow = !switch_yellow;
    digitalWrite(yellow, switch_yellow);
  }
}

void timer_switch_green (void) {
  if (millis() - timer_switch_green_1 >= PERIOD1) {
    timer_switch_green_1 = millis();
    switch_green = !switch_green;
    digitalWrite(green, switch_green);
  }
}

void mode_1 (void) {
  switch (flag_sound_1) {
    case true:
      music.disable();
      break;
    case false:
      switch (flag_start_sound_1) {
        case true:
          break;
        case false:
          music.play("sounds/1.wav");
          Serial.println("Play 1.wav");
          flag_start_sound_1 = true;
          break;
      }
      break;
  }
  timer_disable_audio_2_1();
  int rnd = random (10, 30);
  digitalWrite(yellow, LOW);    // гасим желтый светодиод
  digitalWrite(green, LOW);     // гасим зеленый светодиод
  digitalWrite(blue, LOW);     // гасим синий светодиод
  analogWrite(volt_meter, 20);  // Вольтметр показывает 1
  start_1 = false;
}

void mode_2 (void) {
  switch (flag_sound_2) {
    case true:
      music.disable();
      break;
    case false:
      switch (flag_start_sound_2) {
        case true:
          break;
        case false:
          music.play("sounds/2.wav");
          Serial.println("Play 2.wav");
          flag_start_sound_2 = true;
          break;
      }
      break;
  }
  timer_disable_audio_2();
  timer_disable_audio_20();
  timer_switch_yellow();
  int volt = 200;
  int rnd = random (20, 30);
  digitalWrite(green, LOW);     // гасим зеленый светодиод
  digitalWrite(blue, LOW);     // гасим синий светодиод
  analogWrite(volt_meter, volt + rnd);  // Вольтметр показывает максимум
  analogWrite(volt_meter, volt - rnd);  // Вольтметр показывает максимум
}

void mode_3 (void) {
  switch (flag_sound_3) {
    case true:
      music.disable();
      break;
    case false:
      switch (flag_start_sound_3) {
        case true:
          break;
        case false:
          music.play("sounds/3.wav");
          Serial.println("Play 3.wav");
          flag_start_sound_3 = true;
          break;
      }
      break;
  }
  timer_disable_audio_2();
  timer_disable_audio_20();
  timer_switch_green();
  int volt = 200;
  int rnd = random (20, 30);
  digitalWrite(yellow, LOW);     // гасим зеленый светодиод
  digitalWrite(blue, LOW);     // гасим синий светодиод
  analogWrite(volt_meter, volt_mode_4 + rnd);  // Вольтметр показывает максимум
  analogWrite(volt_meter, volt_mode_4 - rnd);  // Вольтметр показывает максимум
}

void mode_4 (void) {
  switch (flag_sound_120) {
    case true:
      digitalWrite(blue, LOW);
      switch (flag_sound_ready_4) {
        case true:
          music.disable();
          break;
        case false:
          switch (flag_start_sound_ready_4) {
            case true:
              break;
            case false:
              music.play("sounds/ready_4.wav");
              Serial.println("Play ready_4.wav");
              flag_start_sound_ready_4 = true;
              break;
          }
          break;
      }
      break;
    case false:
      digitalWrite(blue, HIGH);     // гасим синий светодиод
      switch (flag_sound_4) {
        case true:
          music.disable();
          break;
        case false:
          switch (flag_start_sound_4) {
            case true:
              break;
            case false:
              music.play("sounds/4.wav");
              Serial.println("Play 4.wav");
              flag_start_sound_4 = true;
              break;
          }
          break;
      }
      break;
  }
  timer_change_ready_mode_4();
  timer_change_volt_mode_4();
  timer_disable_audio_2();
  timer_disable_audio_20();
  timer_disable_audio_120();
  value_volt = volt_mode_4;
  int rnd = random (20, 30);
  digitalWrite(yellow, LOW);     // гасим зеленый светодиод
  digitalWrite(green, LOW);     // гасим зеленый светодиод
  analogWrite(volt_meter, value_volt + rnd);  // Вольтметр показывает максимум
  analogWrite(volt_meter, value_volt - rnd);  // Вольтметр показывает максимум
}

void mode_5 (void) {
  switch (flag_sound_120) {
    case true:
      digitalWrite(rele_vibro, LOW);
      switch (flag_sound_ready_5) {
        case true:
          music.disable();
          break;
        case false:
          switch (flag_start_sound_ready_5) {
            case true:
              break;
            case false:
              music.play("sounds/ready_5.wav");
              Serial.println("Play ready_5.wav");
              flag_start_sound_ready_5 = true;
              break;
          }
          break;
      }
      break;
    case false:
      switch (flag_vibro) {
        case true:
          digitalWrite(rele_vibro, HIGH);
          break;
        case false:
          digitalWrite(rele_vibro, LOW);
          break;
      }
      switch (flag_sound_5) {
        case true:
          music.disable();
          break;
        case false:
          switch (flag_start_sound_5) {
            case true:
              break;
            case false:
              music.play("sounds/5.wav");
              Serial.println("Play 5.wav");
              flag_start_sound_5 = true;
              break;
          }
          break;
      }
      break;
  }
  timer_disable_vibro();
  timer_change_ready_mode_5();
  timer_disable_audio_2();
  timer_disable_audio_20();
  timer_disable_audio_120();
  int rnd = random (20, 40);
  int rnd2 = random (20, 200);
  digitalWrite(yellow, LOW);     // гасим зеленый светодиод
  digitalWrite(blue, LOW);     // гасим синий светодиод
  digitalWrite(green, LOW);     // гасим синий светодиод
  analogWrite(volt_meter, rnd2 + rnd);  // Вольтметр показывает максимум
  analogWrite(volt_meter, rnd2 - rnd);  // Вольтметр показывает максимум
}

void loop() {
  if ((digitalRead(button_1) == HIGH) & (digitalRead(button_2) == LOW) & (digitalRead(button_3) == LOW) & (digitalRead(button_4) == LOW)) {
    mode_2();
  }
  else  if ((digitalRead(button_1) == LOW) & (digitalRead(button_2) == HIGH) & (digitalRead(button_3) == LOW) & (digitalRead(button_4) == LOW)) {
    mode_3();
  }
  else  if ((digitalRead(button_1) == LOW) & (digitalRead(button_2) == LOW) & (digitalRead(button_3) == HIGH) & (digitalRead(button_4) == LOW)) {
    mode_4();
  }
  else  if ((digitalRead(button_1) == LOW) & (digitalRead(button_2) == LOW) & (digitalRead(button_3) == LOW) & (digitalRead(button_4) == HIGH)) {
    mode_5();
  }
  else if ((digitalRead(button_1) == LOW) & (digitalRead(button_2) == LOW) & (digitalRead(button_3) == LOW) & (digitalRead(button_4) == LOW)) {
    refresh();
  }
}
