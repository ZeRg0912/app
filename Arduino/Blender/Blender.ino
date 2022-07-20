//boolean button_2 = 2;     // Кнопка режим РАД. ЗАГРЯЗНЕНИЯ
//boolean button_3 = 3;     // Кнопка режим ХИМ. ЗАГРЯЗНЕНИЯ
//boolean button_4 = 4;     // Кнопка режим ОЧИСТКА
//boolean button_5 = 5;     // Кнопка режим ПЕРЕРАБОТКА
//boolean rele_vibro = 6;   // реле

#define yellow A1         // желтый свет
#define green A2          // зеленый свет
#define blue A3           // синий свет
#define PERIOD_1 100
#define PERIOD_2 200
#define PERIOD_5 500
#define PERIOD2 2000
#define PERIOD1 1000
#define PERIOD5 5000
#define PERIOD10 10000
#define PERIOD20 20000
unsigned long timer_1, timer_2, timer_5, timer1, timer2, timer5, timer10, timer20;
unsigned long timer_audio_5, timer_audio_10, timer_audio_20;
unsigned long timer_switch_yellow_1, timer_switch_green_1;

#include <SD.h>            // необходимо включить SD библиотеку
#include <TMRpcm.h>        // также необходимо включить данную библиотеку...
//#include <SPI.h>

const int chipSelect = 4;
int volt_meter = 3;      // Значение на ВОЛЬТМЕТР
int value_volt = 0;
TMRpcm music;   // создать объект для использования в данном скетче
boolean flag_volt = false;
boolean flag_start_sound_1 = false;
boolean flag_start_sound_2 = false;
boolean flag_start_sound_3 = false;
boolean flag_sound_3 = false;
boolean flag_sound_2 = false;
boolean flag_sound_1 = false;
boolean switch_yellow = false;
boolean switch_green = false;

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
  music.setVolume(5);     //   от 0 до 7. Установка уровня громкости
  music.quality(1);       //  1 для 2x передескритезации, 0 for для нормального режима
  timer_1 = millis();
  timer_2 = millis();
  timer_5 = millis();
  timer1 = millis();
  timer5 = millis();
  timer10 = millis();
  timer20 = millis();
  timer_audio_5 = millis();
  timer_audio_10 = millis();
  timer_audio_20 = millis();
  //  pinMode(rele_vibro, OUTPUT); // Инициализируем цифровой вход/выход в режиме выхода.
  //  pinMode(button_2, INPUT);
  //  pinMode(button_3, INPUT);
  //  pinMode(button_4, INPUT);
  //  pinMode(button_5, INPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(volt_meter, OUTPUT);
  music.disable();
}

/*void timer_switch_1 (void) {
  int rnd = random (10, 30);
  if (millis() - timer_1 >= PERIOD_1) {
    timer_1 = millis();
    switch (flag_volt) {
      case false:
        rnd = random (10, 30);
        value_volt = 50 + rnd;
        rnd = random (10, 30);
        value_volt = value_volt - rnd;
        analogWrite(volt_meter, value_volt);
        break;
      case true:
        rnd = random (10, 30);
        value_volt = 150 + rnd;
        rnd = random (10, 30);
        value_volt = value_volt - rnd;
        analogWrite(volt_meter, value_volt);
        break;
    }
  }
  }

  void timer_switch_2 (void) {
  if (millis() - timer_2 >= PERIOD_2) {
    timer_2 = millis();

  }
  }

  void timer_switch_5 (void) {
  if (millis() - timer_5 >= PERIOD_5) {
    timer_5 = millis();

  }
  }

  void timer_switch1 (void) {
  if (millis() - timer1 >= PERIOD1) {
    timer1 = millis();

  }
  }

  void timer_switch2 (void) {
  if (millis() - timer2 >= PERIOD2) {
    timer2 = millis();
    flag_volt = !flag_volt;
  }
  }

  void timer_switch5 (void) {
  if (millis() - timer5 >= PERIOD5) {
    timer5 = millis();
    flag_volt = !flag_volt;
    music.disable();
  }
  }

  void timer_switch10 (void) {
  if (millis() - timer10 >= PERIOD10) {
    timer10 = millis();

  }
  }

  void meter_1_3 (void) {
  timer_switch5();
  timer_switch_1();
  switch (flag_volt) {
    case false:
      timer_switch_1();
      analogWrite(volt_meter, value_volt);
      break;
    case true:
      timer_switch_1();
      analogWrite(volt_meter, value_volt);
      break;
  }
  }*/

//////////////////////////////////////////////////////
void timer_disable_audio_5 (void) {
  if (millis() - timer_audio_5 >= PERIOD5) {
    timer_audio_5 = millis();
    flag_sound_1 = true;
    flag_sound_2 = true;
    flag_sound_3 = true;
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
  timer_disable_audio_5();
  int rnd = random (10, 30);
  digitalWrite(yellow, LOW);    // гасим желтый светодиод
  digitalWrite(green, LOW);     // гасим зеленый светодиод
  digitalWrite(blue, LOW);     // гасим синий светодиод
  analogWrite(volt_meter, rnd);  // Вольтметр показывает 1
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
          music.play("sounds/1.wav");
          Serial.println("Play 1.wav");
          flag_start_sound_2 = true;
          break;
      }
      break;
  }
  timer_disable_audio_5();
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
          music.play("sounds/1.wav");
          Serial.println("Play 1.wav");
          flag_start_sound_3 = true;
          break;
      }
      break;
  }
  timer_disable_audio_5();
  timer_disable_audio_20();
  timer_switch_green();
  int volt = 200;
  int rnd = random (20, 30);
  digitalWrite(yellow, LOW);     // гасим зеленый светодиод
  digitalWrite(blue, LOW);     // гасим синий светодиод
  analogWrite(volt_meter, volt + rnd);  // Вольтметр показывает максимум
  analogWrite(volt_meter, volt - rnd);  // Вольтметр показывает максимум
}

void mode_4 (void) {
  digitalWrite(blue, HIGH);    // зажигаем синий светодиод
  digitalWrite(yellow, LOW);     // гасим желтый светодиод
  digitalWrite(green, LOW);     // гасим зеленый светодиод
  analogWrite(volt_meter, 135);  // Вольтметр показывает максимум
}

void mode_5 (void) {
  int rnd = random (0, 255);
  //  digitalWrite(rele_vibro, HIGH);
  digitalWrite(blue, LOW);    // зажигаем синий светодиод
  digitalWrite(yellow, LOW);     // гасим желтый светодиод
  digitalWrite(green, LOW);     // гасим зеленый светодиод
  analogWrite(volt_meter, 55);  // Вольтметр показывает максимум
  rnd = random (0, 255);
  music.play("sounds/номер 5.wav");
  analogWrite(volt_meter, rnd);
}

void loop() {
  mode_3();
}
