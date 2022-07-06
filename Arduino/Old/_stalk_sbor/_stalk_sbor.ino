//#include <LiquidCrystal_I2C.h>             // Подключение библиотеки LiquidCrystal для работы с ЖК-дисплеями
#include <LiquidCrystal_PCF8574.h>
#include <SPI.h>
#include <EEPROM.h>

#define Red1 digitalWrite (A0, HIGH)
#define Red0 digitalWrite (A0, LOW)
#define Yellow1 digitalWrite (A1, HIGH)
#define Yellow0 digitalWrite (A1, LOW)
#define Green1 digitalWrite (A2, HIGH)
#define Green0 digitalWrite (A2, LOW)
//LiquidCrystal lcd(2, 3, 4, 5, 6, 7);   // Инициализация библиотеки LiquidCrystal с номерами контактов к которым подключен дисплей
//LiquidCrystal_I2C lcd(0x38,16,2);
LiquidCrystal_PCF8574 lcd(0x27);

char l = 0;
char r = 0;
char complete = 0;
char tries = 3;
boolean crash = false;
boolean con = false;

// Массивы символов для прогресс-бара
byte p100[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

void progress (void) {
  r = 0;
  if (complete == 0) {
    con = digitalRead(12);
    lcd.setCursor(0, 1);                 // Установка курсора во вторую строку, первый столбец
    lcd.print("                ");       // Очистка второй строки 8-ю пробелами
    for (int i = 0; i < 16; i++)
    {
      con = digitalRead(12);
      if (con == false) {
        digitalWrite(12, LOW);
        break;
      }
      loading();
      lcd.setCursor(i, 1);            // Установка курсора в заданную позицию
      lcd.write(1);                   // Обновление прогресс-бара
      if (tries > 0) {
        con = digitalRead(12);
        if (con == false) {
          digitalWrite(12, LOW);
          break;
        }
        crash = false;
        crash = !random(10);
        if (crash == true) {
          con = digitalRead(12);
          if (con == false) {
            digitalWrite(12, LOW);
            break;
          }
          error();
          tries--;
          break;
        }
        else if (crash == false) {
          con = digitalRead(12);
          if (con == false) {
            digitalWrite(12, LOW);
            break;
          }
        }
      }
      if (i == 7) {
        complete = 1;
      }
      con = digitalRead(12);
      if (con == false) {
        digitalWrite(12, LOW);
        break;
      }
      delay(1000);                     // Ожидание 100 мс.
    }
  }
  else if (complete == 1) {
    //lcd.clear();
    EEPROM.update(0, complete);
    lcd.setCursor(0, 0);
    lcd.print("RECEIVE ");
    lcd.setCursor(0, 1);
    lcd.print("COMPLETE");
    delay(1000);
  }
}

void start (void) {
  lcd.setCursor(0, 0);
  lcd.print("   Welcome      ");
  Red1;
  Yellow1;
  Green1;
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("     Comrade    ");
  Red0;
  Yellow0;
  Green0;
  delay(1000);
  lcd.setCursor(13, 1);
  lcd.print(".");
  Red1;
  Yellow1;
  Green1;
  delay(1000);
  lcd.setCursor(13, 1);
  lcd.print(" ");
  Red0;
  Yellow0;
  Green0;
  delay(1000);
  lcd.setCursor(13, 1);
  lcd.print(".");
  Red1;
  Yellow1;
  Green1;
  delay(1000);
  lcd.setCursor(13, 1);
  lcd.print(" ");
  Red0;
  Yellow0;
  Green0;
  delay(1000);
  lcd.clear();
}

void loading (void) {
  Red0;
  Yellow1;
  Green0;
  if (l == 0) {
    lcd.setCursor(0, 0);
    lcd.print("Receive         ");
    l++;
  }
  else if (l == 1) {
    lcd.setCursor(0, 0);
    lcd.print("Receive.        ");
    l++;
  }
  else if (l == 2) {
    lcd.setCursor(0, 0);
    lcd.print("Receive..       ");
    l++;
  }
  else if (l == 3) {
    lcd.setCursor(0, 0);
    lcd.print("Receive...      ");
    l = 0;
  }
}

void error (void) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("     Error      ");
  lcd.setCursor(0, 1);
  lcd.print("    Retry  4    ");
  Red1;
  Yellow0;
  Green0;
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("    Retry  3    ");
  Red0;
  Yellow0;
  Green0;
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("     Error      ");
  lcd.setCursor(0, 1);
  lcd.print("    Retry  2    ");
  Red1;
  Yellow0;
  Green0;
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("    Retry  1    ");
  Red0;
  Yellow0;
  Green0;
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("     Error      ");
  lcd.setCursor(0, 1);
  lcd.print("    Retry  0    ");
  Red1;
  Yellow0;
  Green0;
  delay(1000);
}

void ready_ (void) {
  crash = false;
  if (r == 0) {
    lcd.setCursor(0, 0);
    lcd.print("  Disconnected  ");
    lcd.setCursor(0, 1);
    lcd.print("  Ready         ");
    r++;
    Red0;
    Yellow1;
    Green1;
  }
  else if (r == 1) {
    lcd.setCursor(0, 0);
    lcd.print("  Disconnected  ");
    lcd.setCursor(0, 1);
    lcd.print("  Ready.         ");
    r++;
    Red0;
    Yellow0;
    Green1;
  }
  else if (r == 2) {
    lcd.setCursor(0, 0);
    lcd.print("  Disconnected  ");
    lcd.setCursor(0, 1);
    lcd.print("  Ready..       ");
    r++;
    Red0;
    Yellow1;
    Green1;
  }
  else if (r == 3) {
    lcd.setCursor(0, 0);
    lcd.print("  Disconnected  ");
    lcd.setCursor(0, 1);
    lcd.print("  Ready...      ");
    r = 0;
    Red0;
    Yellow0;
    Green1;
  }  
  delay(1000);
}

void transit (void) {
  con = digitalRead(12);
  if (con == true) {
    //lcd.clear();
    progress();
  }
  else {
    //lcd.clear();
    ready_();
  }
}

void work (void){
    if (EEPROM.read(0) == 0) {
    transit();
  }
  else if (EEPROM.read(0) == 1){
    Red0;
    Yellow0;
    Green1;
    lcd.setCursor(0, 0);
    lcd.print("RECEIVE ");
    lcd.setCursor(0, 1);
    lcd.print("COMPLETE");
    delay(1000);
  }
}

void sbros (void){
  EEPROM.update(0,0);
  Serial.println(EEPROM.read(0));
  delay(5000);
}

void setup()
{
  Red0;
  Yellow0;
  Green0;
  digitalWrite(12, LOW);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  Serial.begin(9600);
  if ((EEPROM.read(0) != 0) & (EEPROM.read(0) != 1)){
    EEPROM.update(0,0);
  }
  lcd.begin(16, 2);                    // Настройка количества столбцов и строк на ЖК-дисплее
  lcd.init();
  lcd.setBacklight(true);
  lcd.clear();
  // Определение пользовательских символов
  lcd.createChar(1, p100);
  start();
}

void loop()
{
  work();
  //sbros();
}
