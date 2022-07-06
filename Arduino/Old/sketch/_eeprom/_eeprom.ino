#include <EEPROM.h>
#include <SPI.h>
void setup() {
  Serial.begin(9600);
  
  // объявляем данные разных типов
  byte dataB = 120;
  float dataF = 3.14;
  int16_t dataI = -634;  
  // пишем друг за другом
  eeprom_write_byte(0, dataB);  // 1 байт
  eeprom_write_float(1, dataF);  // 4 байта
  // для разнообразия "обновим"
  eeprom_update_word(5, dataI);
  // объявляем переменные, куда будем читать
  byte dataB_read = 0;
  float dataF_read = 0;
  int16_t dataI_read = 0;
  // читаем
  dataB_read = eeprom_read_byte(0);
  dataF_read = eeprom_read_float(1);
  dataI_read = eeprom_read_word(5);
  // выведет 120 3.14 -634
  Serial.println(dataB_read);
  Serial.println(dataF_read);
  Serial.println(dataI_read);
}
void loop() {}
