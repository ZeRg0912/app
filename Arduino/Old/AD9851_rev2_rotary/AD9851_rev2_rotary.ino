/*
Main code by Igor Krepsky - www.frompinskto.wordpress.com
based on fragments of code by Richard Visokey AD7C - www.ad7c.com
Rev. 2.2 - Spt., 2016  for AD9851 chip.
*/
// Подключение библиотек
#include <LiquidCrystal.h>
#include <rotary.h>

//Определения
#define W_CLK A2     // A2 - connect to AD9851 module word load clock pin (CLK)
#define FQ_UD A3     // A3 - connect to freq update pin (FQ)
#define DATA A4      // A4 - connect to serial data load pin (DATA)
#define RESET A5     // A5 - connect to reset pin (RST)
#define ENC_A 2      // Pin 2 - 1 канал валкодера 
#define ENC_B 3      // Pin 3 - 2 канал валкодера
#define ENC_KEY 4    // Pin 4 - кнопка валкодера
#define MODE_1 0     // Pin 0 - переключатель mode vfo
#define MODE_2 1     // Pin 1 - переключатель mode sweep
#define KEY_1 5      // Pin 5 - доп. кнопка

#define pulseHigh(pin) {digitalWrite(pin, HIGH); digitalWrite(pin, LOW); }

Rotary r = Rotary(2,3); // Устанавливает пины для каналов энкодера.  Должны поддерживать прерывания.

LiquidCrystal lcd(8, 9, 10, 11, 12, 13); // ПРИСВОЕНИЕ ДЛЯ LCD (RS_E_4_5_6_7)R/W=gnd

// Переменные
int_fast32_t rx=1000000;        // Стартовая частота VFO
int_fast32_t rif=0;             // Значение IF
int_fast32_t wif=450000;        // рабочее значение IF
int_fast32_t rx2=1;             // переменная для сохранения обновлённой частоты
int_fast32_t increment = 1000;  // начальный VFO инкремент в HZ.
int_fast32_t delta=1000;        // Стартовая величина ширины качания sweep в Hz
int_fast32_t sstep=1;           // Стартовая величина шага качания sweep в Hz
int buttonstate = 0;            // Переменная для чтения состояния кнопки
String hertz = "1 KHz";
int  hertzPosition = 0;
byte ones,tens,hundreds,thousands,tenthousands,hundredthousands,millions ;  //Разряды для частоты
byte a_1, a_2;            // разряды для отображения IF
String freq;              // string для получения частоты
boolean mod_1;            // текущее значение переключателя mode vfo
boolean mod_1_old;        // сохранённое значение переключателя mode vfo
boolean mod_2;            // текущее значение переключателя mode sweep
boolean mod_2_old;        // сохранённое значение переключателя mode sweep

void setup() {
  // put your setup code here, to run once:
  pinMode(ENC_KEY,INPUT); // кнопка валкодера, 0 при нажатии
  digitalWrite(ENC_KEY,HIGH);
  lcd.begin(16, 2);
  pinMode(ENC_A, INPUT);
  pinMode(ENC_B, INPUT);
  pinMode(MODE_1, INPUT);
  pinMode(MODE_2, INPUT);
  PCICR |= (1 << PCIE2);
  PCMSK2 |= (1 << PCINT18) | (1 << PCINT19);
  sei();
  pinMode(FQ_UD, OUTPUT);
  pinMode(W_CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(RESET, OUTPUT); 
  pulseHigh(RESET);
  pulseHigh(W_CLK);
  pulseHigh(FQ_UD);  // this pulse enables serial mode on the AD9851 - see datasheet
  lcd.setCursor(0,0);  
  lcd.print("     AD9851     "); 
  lcd.setCursor(0,1);  
  lcd.print("  IS LOADING... ");
  delay(1000);
  lcd.setCursor(hertzPosition,1); 
  lcd.print(hertz);
}// END SETUP

void loop() {
     
// ИЗМЕНЕНИЕ ИНКРЕМЕНТА (кнопка валкодера)
      buttonstate = digitalRead(ENC_KEY); // если нажатие кнопки валкодера - изменить инкремент
      if(buttonstate == LOW) {
      setincrement();        
      }
// ВОЗВРАТ ШАГА ИЗМЕНЕНИЯ ЧАСТОТЫ к 1КГЦ в РЕЖИМЕ ГЕНЕРАТОРА
      if ((mod_1 == 1)&&(mod_2 == 1)){
      buttonstate = digitalRead(KEY_1);
      if (buttonstate == LOW){increment = 1000; hertz="1 KHz"; hertzPosition=0;
      lcd.setCursor(hertzPosition,1);
      lcd.print("       ");
      lcd.setCursor(hertzPosition,1); 
      lcd.print(hertz);
      delay(250); // Adjust this delay to speed up/slow down the button menu scroll speed.  
      }
      }    
// ПЕРЕКЛЮЧАТЕЛЬ MODE
      mod_1 = digitalRead (MODE_1); // чтение значения переключателя mode vfo.
      mod_2 = digitalRead (MODE_2); // чтение значения переключателя mode sweep.
      
// ДЕЙСТВИЯ ПОСЛЕ ПЕРЕКЛЮЧЕНИЯ MODE 
      if ((mod_1 != mod_1_old)||(mod_2 != mod_2_old)){// если произошло переключение mode
      // и вывод на дисплей
      
      // 1.очистка
      
      lcd.setCursor(0,1);
      lcd.print("                ");
      
      // 2.вывод значения
      
      if ((mod_1 == 1)&&(mod_2 == 1)){// если режим генератора
        rif=0;
        lcd.setCursor(hertzPosition,1); 
        lcd.print(hertz);
        lcd.setCursor(8,1);
        lcd.print("OSC.MODE");
      
      }

      if ((mod_1 == 1)&&(mod_2 == 0)){// если режим генератора с ПЧ
        rif=wif;
        sendFrequency(rx+rif);// отправить частоту в синтезатор
        lcd.setCursor(hertzPosition,1); 
        lcd.print(hertz);
        lcd.setCursor(7,1);  
        lcd.print("IF:");
        if (wif < 1000000){                       
        lcd.print(wif/1000);
        lcd.print("KHz ");}
        else{
        a_1 = ((wif/1000)%10);
        a_2 = ((wif/100)%10);
          lcd.print (a_1);
          lcd.print ("."); 
          lcd.print (a_2);
          lcd.print("MHz ");}
      
       }
                                                                           
      if ((mod_1 == 0)&&(mod_2 == 1)){// если режим SWEEP
      rif=0;
      lcd.setCursor(hertzPosition,1); 
      lcd.print(hertz);
      if (delta < 10000){
      lcd.setCursor(6,1);  
      lcd.print("  SWP:");                       
      lcd.print(delta/1000);
      lcd.print("KHz ");
      }
      else if (delta >= 100000){
      lcd.setCursor(6,1);  
      lcd.print("SWP:");                       
      lcd.print(delta/1000);
      lcd.print("KHz ");
      }
      else
      {
      lcd.setCursor(6,1);  
      lcd.print(" SWP:");                       
      lcd.print(delta/1000);
      lcd.print("KHz ");
      } 
      } 
      
// ВЫВОД НА ДИСПЛЕЙ ЧАСТОТЫ И ПЕРЕДАЧА ЕЁ В DDS ПОСЛЕ ПЕРЕКЛЮЧЕНИЯ MODE      
      showFreq();
      sendFrequency(rx+rif);
      rx2 = rx;
      mod_1_old = mod_1;
      mod_2_old = mod_2;  
      } 
// ОКОНЧАНИЕ ДЕЙСТВИЯ ПОСЛЕ ПЕРЕКЛЮЧЕНИЯ MODE 
      
// ВЫЧИСЛЕНИЕ ЧАСТОТЫ ДЛЯ РЕЖИМА SWEEP
      if ((mod_1 == 0)&&(mod_2 == 1)){
      rif = rif + sstep;
      if (rif > delta) {rif = 0;}
      sendFrequency(rx+rif);// отправить частоту в синтезатор
      // переключение delta 
      buttonstate = digitalRead(KEY_1);
      if (buttonstate == LOW) {
      if (delta == 1000){delta = 5000;}
      else if (delta == 5000){delta = 10000; sstep = 2;}
      else if (delta == 10000){delta = 50000; sstep = 5;}
      else if (delta == 50000){delta = 100000; sstep = 10;}
      else {delta = 1000; sstep = 1;}
      if (delta < 10000){
      lcd.setCursor(6,1);  
      lcd.print("  SWP:");                       
      lcd.print(delta/1000);
      lcd.print("kHz ");
      }
      else if (delta == 100000){
      lcd.setCursor(6,1);  
      lcd.print("SWP:");                       
      lcd.print(delta/1000);
      lcd.print("kHz ");
      }
      else
      {
      lcd.setCursor(6,1);  
      lcd.print(" SWP:");                       
      lcd.print(delta/1000);
      lcd.print("kHz ");
      } 
      delay(500);
      }  
      }
// ВЫЧИСЛЕНИЕ ЧАСТОТЫ ДЛЯ РЕЖИМА УЧЁТА ПРОМЕЖУТОЧНОЙ ЧАСТОТЫ
      if ((mod_1 == 1)&&(mod_2 == 0)){
      rif = wif;
      
      // переключение wif 
      buttonstate = digitalRead(KEY_1);
      if (buttonstate == LOW) {
      // нужные значения промежуточных частот прописываются здесь. при желании - как угодно много.  
      if (wif == 450000){wif = 455000;}
      else if (wif == 455000){wif = 460000;}
      else if (wif == 460000){wif = 465000;}
      else if (wif == 465000){wif = 1600000;}
      else if (wif == 1600000){wif = 1800000;}
      else if (wif == 1800000){wif = 5500000;}
      else if (wif == 5500000){wif = 10700000;}
      else if (wif == 10700000){wif = 21400000;}
      else {wif = 450000;}
      sendFrequency(rx+rif);// отправить частоту в синтезатор
      if (wif < 1000000){
      lcd.setCursor(6,1);  
      lcd.print(" IF:");
      lcd.print(wif/1000);
      lcd.print("KHz ");}
      else{
      lcd.setCursor(7,1);  
      lcd.print("IF:");
      lcd.print(wif/1000);
      lcd.print("K ");}   
      delay(250);
        
      }
      }
      
// ВЫВОД НА ДИСПЛЕЙ ЧАСТОТЫ И ПЕРЕДАЧА ЕЁ В DDS В ОБЩЕМ СЛУЧАЕ 
          
        if (rx != rx2)
        {
        showFreq();// при изменении частоты вывести на дисплей
        sendFrequency(rx+rif);// отправить частоту в синтезатор
        rx2 = rx;
        }
            
}// END LOOP

// ПОДПРОГРАММЫ

// Обработка прерывания
ISR(PCINT2_vect) {
  
    // обработка энкодера
    unsigned char result = r.process();
    if (result) {    
    if (result == DIR_CW){rx=rx+increment;}
    else {rx=rx-increment;};       
    // конец обработки валкодера
    if ((rx+rif) >60000000){rx=(60000000-rif);}; // ВЕРХНИЙ VFO LIMIT
    if (rx <5){rx=5;}; // НИЖНИЙ VFO LIMIT
    }
    }
    
// расчёт частоты на основе докумментации на микросхему = <sys clock> * <frequency tuning word>/2^32
void sendFrequency(double frequency) {  
  int32_t freq = frequency * 4294967296./180000000;  // note 180 MHz clock on 9851.
  for (int b=0; b<4; b++, freq>>=8) 
  {
   tfr_byte(freq & 0xFF);
  }
  tfr_byte(0x001);   // Final control byte, LSB 1 to enable 6 x xtal multiplier on 9851 set to 0x000 for 9850
  pulseHigh(FQ_UD);  // Сделано!  Должен увидеть выход.
  }

// передаёт байт, по биту за раз, начиная с LSB  на 9851 через serial DATA line
void tfr_byte(byte data)
{
  for (int i=0; i<8; i++, data>>=1) {
    digitalWrite(DATA, data & 0x01);
    pulseHigh(W_CLK);   //после передачи каждого бита, CLK is pulsed high
  }
}

void setincrement(){// установка значения инкремента частоты
  if(increment == 1){increment = 10; hertz = "10 Hz"; hertzPosition=0;} 
  else if(increment == 10){increment = 100; hertz = "100 Hz"; hertzPosition=0;}
  else if (increment == 100){increment = 1000; hertz="1 Khz"; hertzPosition=0;}
  else if (increment == 1000){increment = 10000; hertz="10 Khz"; hertzPosition=0;}
  else if (increment == 10000){increment = 100000; hertz="100Khz"; hertzPosition=0;}
  else if (increment == 100000){increment = 1000000; hertz="1 Mhz"; hertzPosition=0;} 
  else{increment = 1; hertz = "1 Hz"; hertzPosition=0;};  
   lcd.setCursor(hertzPosition,1);
   lcd.print("       ");
   lcd.setCursor(hertzPosition,1); 
   lcd.print(hertz);
   delay(500); // Adjust this delay to speed up/slow down the button menu scroll speed.
};

void showFreq(){// вывод значения частоты на дисплей
    millions = int(rx/1000000);
    hundredthousands = ((rx/100000)%10);
    tenthousands = ((rx/10000)%10);
    thousands = ((rx/1000)%10);
    hundreds = ((rx/100)%10);
    tens = ((rx/10)%10);
    ones = ((rx/1)%10);
    lcd.setCursor(0,0);
    lcd.print("                ");
   if (millions > 9){lcd.setCursor(1,0);}
   else{lcd.setCursor(2,0);}
    lcd.print(millions);
    lcd.print(".");
    lcd.print(hundredthousands);
    lcd.print(tenthousands);
    lcd.print(thousands);
    lcd.print(".");
    lcd.print(hundreds);
    lcd.print(tens);
    lcd.print(ones);
    lcd.print(" Mhz ");
  
};

