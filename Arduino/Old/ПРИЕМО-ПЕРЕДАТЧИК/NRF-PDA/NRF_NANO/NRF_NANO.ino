// include the library code:
#include <SPI.h>
/*
  Подключаем файл настроек из библиотеки RF24
*/
#include <nRF24L01.h>
/*
  Подключаем библиотеку  для работы с nRF24L01+
*/
#include <RF24.h>

//#include <Wire.h>
#include <LiquidCrystal.h>

//#include <printf.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 7, 5, 4, 3, 2);
/*
  Создаём объект radio для работы с библиотекой RF24,
  указывая номера выводов модуля (CE, SS).
*/
RF24 radio(9, 10);
 
/*
  Объявляем массив для хранения и передачи данных
  (до 32 байт включительно).
*/
//////////////////////////////////////////////////////////
/*
int dataToBeTransmitted[5] = {'0', '1', '2', '3', '4'};
int dataToBeTransmitted1[5] = {'3', '3', '3', '3', '3'};
int Data[5];
uint8_t i;
*/
//////////////////////////////////////////////////////////
int receivedData;
float Health = 100;  // --- КОЛИЧЕСТВО ХП ---
float Armor = 100;  // --- КОЛИЧЕСТВО БРОНИ ---
int Hit = 0x42;
int MANA = 100;
unsigned long currentTime = 0;

//uint8_t pipe;

boolean la = false; // --- МЕЛКАЯ АПТЕЧКА ФЛАГ ---
boolean lb = false; // --- БОЛЬШАЯ АПТЕЧКА ФЛАГ ---
boolean arm = false; // --- БРОНЯ ФЛАГ ---
boolean tim = false;

#define lowAPT digitalRead(14)
#define highAPT digitalRead(15)
#define SUIT digitalRead(16)
#define BUT digitalRead(17)  
/*
  Объявляем переменную в которую будет сохраняться
  номер трубы по которой приняты данные.
*/

void radio_setup(void){
/*
    Инициируем передачу данных по шине UART в монитор
    последовательного порта на скорости 115200 бит/сек.
  */
  Serial.begin(9600);
  /*
    Инициируем работу nRF24L01+
  */
  radio.begin();
  /*
    Указываем канал передачи данных (от 0 до 127)
    (на одном канале может быть только 1 приёмник и до 6 передатчиков).
    Выбираем канал в котором нет шумов!
  */
  radio.setChannel(0x55);
  /*
    Указываем скорость передачи данных
    RF24_250KBPS = 250Кбит/сек
    RF24_1MBPS = 1Мбит/сек
    RF24_2MBPS = 2Мбит/сек
    Скорость должна быть одинакова на приёмнике и передатчике.
    При самой низкой скорости имеем самую высокую чувствительность и дальность.
  */
  radio.setDataRate(RF24_2MBPS);
  /*
    Указываем мощность передатчика
    RF24_PA_MIN=-18dBm
    RF24_PA_LOW=-12dBm
    RF24_PA_HIGH=-6dBm
    RF24_PA_MAX=0dBm
  */
  radio.setPALevel(RF24_PA_LOW);
  /*
    Открываем 1 трубу с адресом 1 передатчика 0x0123456789LL, для приема данных.
  */
  radio.setRetries(15,1);
  /*
    Включаем приемник, начинаем прослушивать открытые трубы.
  */
  //radio.startListening();
  radio.openWritingPipe(0x0123456789FF);
  radio.openReadingPipe(1, 0x0123456789FF);  
}
 
void setup() {
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  lcd.begin(16, 2);
  radio_setup();
  lcd.clear();
}

void timer(void){
  if (millis() - currentTime >= 1000)   // Проверяем время для первого диода (1000мс)
  {
    currentTime = millis();
    tim = true;
  }
}

void show_armor(void){           // ВЫВОД КОЛ-ВА ХП
  byte i = 0;
  if (Armor == 100 && SUIT == HIGH)
  {
  lcd.setCursor(0,1);
  lcd.print("ARMOR");
  lcd.setCursor(10,1);                                       
  lcd.print(Armor, 1);                                     
  lcd.print("%");                                           
  lcd.print(" ");                                           
  }
    else if (Armor < 100 && Armor >= 10 && SUIT == HIGH)
    {
    lcd.setCursor(0,1);
    lcd.print("ARMOR");
    lcd.setCursor(10,1);
    lcd.print(" ");                                      
    lcd.print(Armor, 1);                                     
    lcd.print("%");                                           
    lcd.print(" ");                                                   
    }
      else if (Armor < 10 && Armor >= 1 && SUIT == HIGH)
      {
      lcd.setCursor(0,1);
      lcd.print("ARMOR");
      lcd.setCursor(11,1);
      lcd.print(" ");                                      
      lcd.print(Armor, 1);                                     
      lcd.print("%");                                           
      lcd.print(" ");       
      }
        else
        {
        lcd.setCursor(0,1);
          for (i = 0; i < 16; i++)
          {
          lcd.print(" ");
          } 
        }
}

void show_health(void){           // ВЫВОД КОЛ-ВА ХП
  if (Health == 100.0)
  {
  lcd.setCursor(0,0);
  lcd.print("HEALTH");
  lcd.setCursor(10,0);                                      
  lcd.print(Health, 1);                                     
  lcd.print("%");                                           
  lcd.print(" ");                                          
  }
    else if(Health < 100.0 && Health >= 10.0)
    {
    lcd.setCursor(0,0);
    lcd.print("HEALTH");
    lcd.setCursor(10,0);
    lcd.print(" ");                                      
    lcd.print(Health, 1);                                     
    lcd.print("%");                                           
    lcd.print(" ");                                                   
    }
      else if(Health < 10.0 && Health >= 1.0)
      {
      lcd.setCursor(0,0);
      lcd.print("HEALTH");
      lcd.setCursor(11,0);
      lcd.print(" ");                                      
      lcd.print(Health, 1);                                     
      lcd.print("%");                                           
      lcd.print(" ");                                                   
      }
}

void death(void){
  lcd.clear();                                          //                                          
  lcd.setCursor(6,0);                                   //
  lcd.print("You");                                     //
  lcd.setCursor(7,1);                                   // СМЕРТЬ
  lcd.print("DIE");                                     //
  lcd.print(" ");                                       //
//  delay(500);                                           //  
}

void receive(void)
{
  switch (receivedData)
  {
  case 0x42:              // --- СИГНАЛ АНОМАЛИИ ---
  if (Health <= 0)
  {                                     
  death();
  break;                                                
  }else if(Health > 0 && SUIT == HIGH && Armor > 0) // ЕСЛИ ХП БОЛЬШЕ 0 И ОДЕТ КОСТЮМ
    {
      Health = Health -0.5;
      Armor = Armor - 5;
        if (Armor == 0){
          arm = true;
        }
    }
        else 
        {     
        Health = Health - 1;             // ЕСЛИ ХП БОЛЬШЕ 0 И НЕТУ КОСТЮМА        
        }
  show_health();
  show_armor();  
  break;
  default:                // --- НЕТУ УГРОЗ ---
  if (Health <= 0)
  {                    
  death();                                
  break;                                                                  
  }
  show_health();
  show_armor(); 
  } 
}

void RADIO(void){ // ПРИНИМАЕМ СИГНАЛ
//if (radio.available(&pipe)) {
radio.read(&receivedData, sizeof(receivedData));
 receive();
//}
}  

void APT_L(void){                 // --- МЕЛКАЯ АПТЕЧКА НА 30 ХП ---
  byte a = 0;                     // РАБОТАЕТ ПРИ УСЛОВИИ ЧТО
  byte Healthmax = 100;           // ЕСЛИ ВСТАВЛЕНА В ПОРТ И ХП НЕ 100%
  byte Healthnow = 0;
  if (lowAPT == HIGH && Health < 100 && Health >= 70 && Health > 0 && la == false)
  {
      Healthnow = Healthmax - Health;
      Health = Health + Healthnow;  
      la = true;
  }    
  else if (lowAPT == HIGH && Health < 70 && Health > 0 && la == false)
  {
      Health = Health + 30;
      la = true;
  }
  else
  {
  }
}

void APT_H(void){                 // --- БОЛЬШАЯ АПТЕЧКА НА ФУЛЛ ХП ---
  byte a = 0;                     // РАБОТАЕТ ПРИ УСЛОИИ ЧТО
  byte Healthmax = 100;           // ЕСЛИ ВСТАВЛЕНА В ПОРТ И ХП НЕ 100%
  byte Healthnow = 0;
  if (highAPT == HIGH && Health < 100 && Health > 0 && lb == false)
  {
      Health = Healthmax;  
      lb = true;
  }    
  else
  {
  }
}

void HIT() {
if(BUT == HIGH && MANA >= 5){
radio.stopListening();
radio.write(&Hit, sizeof(Hit));
radio.startListening();
MANA = MANA - 5;
tim = false;
Serial.print("МАНА [");
Serial.print(MANA);
Serial.print('%');
Serial.println(']');
}
  else if(BUT == LOW && MANA == 100)
  { 
  Serial.print("МАНА [");
  Serial.print(MANA);
  Serial.print('%');
  Serial.println(']'); 
  }
    else
    {  
    MANA = MANA + 1;
    tim = false;
    Serial.print("МАНА [");
    Serial.print(MANA);
    Serial.print('%');
    Serial.println(']');  
    }
}
 
void loop() {
  timer();
  RADIO(); 
  APT_L();
  APT_H();
  if (tim == true){
    HIT();
  }
  else{
    tim == false;    
  }


/* 
  radio.stopListening();
  radio.write(&dataToBeTransmitted, sizeof(dataToBeTransmitted));
  radio.startListening();
  delay(1000);
  radio.startListening();
    radio.read(&Data, sizeof(Data));
    Serial.print("Данные [ ");
    for (i = 0; i < 5; i++) {
      Serial.print((char) Data[i]);
      Serial.print(' ');
    }
    Serial.println("] пришли по трубе ");
  delay(1000);
  radio.stopListening();
  radio.write(&dataToBeTransmitted1, sizeof(dataToBeTransmitted1));
  radio.startListening();
  delay(1000);
    radio.startListening();
    radio.read(&Data, sizeof(Data));
    Serial.print("Данные [ ");
    for (i = 0; i < 5; i++) {
      Serial.print((char) Data[i]);
      Serial.print(' ');
    }
    Serial.println("] пришли по трубе ");
  delay(1000);
  */ 
}
