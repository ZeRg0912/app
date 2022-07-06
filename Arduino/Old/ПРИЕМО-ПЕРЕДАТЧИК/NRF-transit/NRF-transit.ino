/* The circuit:
 * NRF24 CE pin ti digital pin 9
 * NRF24 CSN pin ti digital pin 10
 * NRF24 SCK pin ti ICSP
 * NRF24 MOSI pin ti ICSP
 * NRF24 MISO pin ti ICSP
 */
// include the library code:
//#include <SPI.h>
/*
  Подключаем файл настроек из библиотеки RF24
*/
#include <nRF24L01.h>
/*
  Подключаем библиотеку  для работы с nRF24L01+
*/
#include <RF24.h>

//#include <printf.h>
/*
  Создаём объект radio для работы с библиотекой RF24,
  указывая номера выводов модуля (CE, SS).
*/
RF24 radio(9, 10);  // указать номера пинов, куда подключаются CE и CSN 9..10
/*
   Объявляем массив для хранения и передачи данных
   (до 32 байт включительно).
*/
int GOOD = 0x41;
int RANIL = 0x42;
int MANA = 100;

#define BUT digitalRead(3) //кнопка режима 3

 
void setup() {
  pinMode(3, INPUT);
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
  radio.setChannel(100);
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
     Открываем трубу с адресом 0x0123456789LL для передачи данных
     (передатчик может одновременно вещать только по одной трубе).
  */
  radio.setRetries(15,1);
  radio.openWritingPipe(0x0123456789FF);
}
 
void loop() {
if(BUT == HIGH ){
radio.write(&RANIL, sizeof(RANIL));
MANA = MANA - 5;
Serial.print("МАНА [");
Serial.print(MANA);
Serial.print('%');
Serial.println('}'); 
}
  else if(BUT == LOW && MANA == 100)
  {
  radio.write(&GOOD, sizeof(GOOD));
  Serial.print("МАНА [");
  Serial.print(MANA);
  Serial.print('%');
  Serial.println(']'); 
  }
    else
    {
    radio.write(&GOOD, sizeof(GOOD));
    MANA = MANA + 1;
    Serial.print("МАНА [");
    Serial.print(MANA);
    Serial.print('%');
    Serial.println(']');  
    }
delay(1000);
}
