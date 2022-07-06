#define clk0 digitalWrite(6,LOW)
#define clk1 digitalWrite(6,HIGH)
#define dat0 digitalWrite(5,LOW)
#define dat1 digitalWrite(5,HIGH)
#define en0 digitalWrite(7,LOW)
#define en1 digitalWrite(7,HIGH)
#define led0 digitalWrite(13,LOW)
#define led1 digitalWrite(13,HIGH)
#define _0 false
#define _1 true

boolean flag = _1;
short value = 0;
int  R0 = '00000001/**/10000000';//Mode0 Вкл. Блок Синтезаторов, Выключены каналы Глонасс, GPS
int  R1 = '01000001/**/10010000';//GLOmode0 Режим выхода Глонасс с АЦП, Порог срабатывания 76мВ, Режим работы АРУ УПЧ2а(канал Глонасс) внутренний
int  R2 = '00100001/**/00000001';//GLOmode1 Установка коэффициента усиления УПЧ2а (канал Глонасс) через ЦАП (продолжение)
int  R3 = '01100001/**/10010000';//GPSmode0 Режим выхода GPS с АЦП, порог срабатывания 76 мВ, Режим работы АРУ УПЧ2б(канал GPS) внутренний
int  R4 = '00010001/**/00000001';//GPSmode1 Установка коэффициента усиления УПЧ2б (канал GPS) через ЦАП (продолжение)
int  R5 = '01010001/**/00111111';//Mode1 Технологические биты и биты усиления второго смесителя GPS и Глонасс
int  R6 = '00110001/**/11111110';//SynthMode Установка коэффициента деления делителя на 7
int  R7 = '01110001/**/10100001';//PFDmode Режим работы детектора захвата частоты - отсутствие контроля захвата частоты
int  R8 = '00001001/**/11000101';//VCOmode0 Разрешает работу стабилизатора напряжения (2.8В) ГУН
int  R9 = '01001001/**/11010101';//VCOmode1 Включает схему автоматического выбора частотного поддиапазона ГУН
int  R10 = '00101001/**/00100000';//LBImode Технологические биты
int  R11 = '01101001/**/00001111';//ShutDown0 Вкл ист опорных токов и напр, Гун и ЧФД, выкл выход Глонасс и GPS
int  R12 = '00011001/**/01000001';//ShutDown1 Разрешает работу делителя и работу драйвера тактовой частоты
int  R13 = '01011001/**/00000000';//ShutDown2 Разрешает работу МШУ(малошумящий усилитель) смесителей и буферов и УПЧ
int  R14 = '00111001/**/00000000';//Test Выбор режима тестирования микросхемы
int  R15 = '01111001/**/00000000';//Outputs Режимы выходов при чтении
int  R16 = '00000101/**/01000000';//Rdata Коэффициент делителя опорной частоты = 2
int  R17 = '01000101/**/10101101';//Ndata0 Коэффициент делителя ГУН
int  R18 = '00100101/**/01000000';//Ndata1 Коэффициент делителя ГУН
int  R19 = '01100101/**/10110000';//AddMode 
int  R20 = '00010101/**/11000101';//ShutDown3 вкл делитель опорной частоты , делитель ГУН, и тд
int  R21 = '01010101/**/01110000';//OutMode Выборы режимов работы и выходных сопротивлений
int  R22 = '00110101/**/00000011';//LNAmode Выбор типа тока МШУ и вкл Гистерезиса уровней компораторов схемы автоматического выбора поддиапозона ГУН

/////////////////////////////////////////

unsigned char bit_ctr;

/////////////////////////////
void R0_reg (void){
byte bit_ctr;
   value = R0;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R1_reg (void){
byte bit_ctr;
   value = R1;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R2_reg (void){
byte bit_ctr;
   value = R2;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R3_reg (void){
byte bit_ctr;
   value = R3;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R4_reg (void){
byte bit_ctr;
   value = R4;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R5_reg (void){
byte bit_ctr;
   value = R5;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R6_reg (void){
byte bit_ctr;
   value = R6;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R7_reg (void){
byte bit_ctr;
   value = R7;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R8_reg (void){
byte bit_ctr;
   value = R8;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R9_reg (void){
byte bit_ctr;
   value = R9;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R10_reg (void){
byte bit_ctr;
   value = R10;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R11_reg (void){
byte bit_ctr;
   value = R11;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R12_reg (void){
byte bit_ctr;
   value = R12;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R13_reg (void){
byte bit_ctr;
   value = R13;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R14_reg (void){
byte bit_ctr;
   value = R14;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R15_reg (void){
byte bit_ctr;
   value = R15;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R16_reg (void){
byte bit_ctr;
   value = R16;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R17_reg (void){
byte bit_ctr;
   value = R17;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R18_reg (void){
byte bit_ctr;
   value = R18;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R19_reg (void){
byte bit_ctr;
   value = R19;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R20_reg (void){
byte bit_ctr;
   value = R20;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R21_reg (void){
byte bit_ctr;
   value = R21;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
void R22_reg (void){
byte bit_ctr;
   value = R22;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0xFF)
        {
        dat1;
   delay(10);
        }
        else
        {
        dat0;
   delay(10);
        }
   value = (value << 1);  
   clk1;
   delay(10);   
   clk0;
   delay(10);   
   }
value = 0;         
}
////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////

void SINTprog(void) {
clk0;
en1;
delay(10);
R0_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R1_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R2_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R3_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R4_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R5_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R6_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R7_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R8_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R9_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R10_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R11_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R12_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R13_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R14_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R15_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R16_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R17_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R18_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R19_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R20_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R21_reg();
en0;
delay(10);
////////////////////////////////////////////////
en1;
delay(10);
R22_reg();
en0;
delay(10);
}  


///////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  delay(10);
SINTprog();


attachInterrupt(0, RESINT, RISING);
}

void loop() {
/*if (flag == _0){
   } 
   else { 
   ce0;
   delay(200);
   ce1;
   delay(500); 
   SINTprog();
   flag = _0; 
   }*/
}

void RESINT() {
  flag = _1;            
}
