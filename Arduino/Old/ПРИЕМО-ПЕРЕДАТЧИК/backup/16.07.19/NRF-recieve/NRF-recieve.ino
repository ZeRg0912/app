 /* The circuit:
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

/* The circuit:
 * NRF24 CE pin ti digital pin 14
 * NRF24 CSN pin ti digital pin 15
 * NRF24 SCK pin ti digital pin 13
 * NRF24 MOSI pin ti digital pin 11
 * NRF24 MISO pin ti digital pin 12
 */
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

#include <Wire.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 5, 4, 3, 2);
/*
  Создаём объект radio для работы с библиотекой RF24,
  указывая номера выводов модуля (CE, SS).
*/
RF24 radio(6, 7);  
/*
  Объявляем массив для хранения и передачи данных
  (до 32 байт включительно).
*/
int receivedData[5];
/*
  Объявляем переменную в которую будет сохраняться
  номер трубы по которой приняты данные.
*/
uint8_t pipe;
 
uint8_t i;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Arduino");
  lcd.setCursor(0,1); 
  lcd.print("started");
  delay(1000);
/*
    Инициируем работу nRF24L01+
*/
    radio.begin();
/*
    Указываем канал передачи данных (от 0 до 127)
    (на одном канале может быть только 1 приёмник и до 6 передатчиков).
    Выбираем канал в котором нет шумов!
*/                                        
    radio.setChannel(0x50);
/*
    Указываем скорость передачи данных
    RF24_250KBPS = 250Кбит/сек
    RF24_1MBPS = 1Мбит/сек
    RF24_2MBPS = 2Мбит/сек
    Скорость должна быть одинакова на приёмнике и передатчике.
    При самой низкой скорости имеем самую высокую чувствительность и дальность.
*/                                     
    radio.setDataRate(RF24_1MBPS);
/*
    Указываем мощность передатчика
    RF24_PA_MIN=-18dBm
    RF24_PA_LOW=-12dBm
    RF24_PA_HIGH=-6dBm
    RF24_PA_MAX=0dBm
*/                   
    radio.setPALevel(RF24_PA_MAX);
/*
    Открываем 1 трубу с адресом 1 передатчика 0x0123456789LL, для приема данных.
*/                 
    radio.openReadingPipe (1, 0x0123456789);
/*
    Включаем приемник, начинаем прослушивать открытые трубы.
*/            
    radio.startListening  ();                             
//  radio.stopListening   ();                          

  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("listening..."); 
  delay(1000);
}

void loop() 
{
  /*
    Если в буфере имеются принятые данные, то получаем номер трубы
    по которой эти данные пришли в переменную pipe.
  */
    /*
      Читаем данные из буфера в массив receivedData указывая
      сколько всего байт может поместиться в массив.
    */
    radio.read(&receivedData, sizeof(receivedData));
    /*
      Если данные пришли от 1 передатчика (по 1 трубе),
      то можно выполнить соответствующее действие ...
    */
    for (i=0;i<5;i++)
    {
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print(receivedData[i]);
      delay(1000);
    }                
  delay(1000);
}
