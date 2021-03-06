/* The circuit:
 * NRF24 CE pin ti digital pin 9
 * NRF24 CSN pin ti digital pin 10
 * NRF24 SCK pin ti ICSP
 * NRF24 MOSI pin ti ICSP
 * NRF24 MISO pin ti ICSP
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
/*
  Создаём объект radio для работы с библиотекой RF24,
  указывая номера выводов модуля (CE, SS).
*/
RF24 radio(9, 10);  // указать номера пинов, куда подключаются CE и CSN 9..10
/*
   Объявляем массив для хранения и передачи данных
   (до 32 байт включительно).
*/
int dataToBeTransmitted[5] = {'0', '1', '2', '3', '4'};

void setup()
 {
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
     Открываем трубу с адресом 0x0123456789LL для передачи данных
     (передатчик может одновременно вещать только по одной трубе).
  */                 
  radio.openWritingPipe(0x0123456789);                                            
 }
void loop()
{
  /*
     Отправляем данные из массива dataToBeTransmitted
     указывая весь размер массива в байтах.
  */
  radio.write(&dataToBeTransmitted, sizeof(dataToBeTransmitted));
  /*
     Устанавливаем задержку на 1000 мс.
  */
  delay(1000);
}
