#define sck0 digitalWrite(6,LOW)
#define sck1 digitalWrite(6,HIGH)
#define sdi0 digitalWrite(5,LOW)
#define sdi1 digitalWrite(5,HIGH)
#define scsn0 digitalWrite(4,LOW)
#define scsn1 digitalWrite(4,HIGH)
#define led0 digitalWrite(13,LOW)
#define led1 digitalWrite(13,HIGH)
/////////////////////////////////////////
unsigned int R = 200;          //  Коэффициент деления опорной частоты

long INT = 3000;        //  Коэффициент деления входной частоты целочисленного делителя(PRE/DIVNM). 
                                  //  Если данное полеустановлено в «0», токоэффициент деленияопределяется входами KINT
                                  
unsigned int FRAC = 0;       //  Числитель дробной части коэффициента деления

unsigned int MOD = 0;        //  Знаменатель (модуль) дробной части коэффициента деления 

char RST = 0;                     //  «1» - сброс внутренних счетчикови схемы управления. 
                                  //  Не влияет на значения полей управления

char OFF = 0;                     //  Выключение устройства:
                                  //  «0» - нормальная работа;
                                  //  «1» - асинхронно переводит выход CPO в третье состояние;
                                  //  «2» - асинхронно переводит устройство в режим пониженного энергопотребления. Выход CPO устанавливается в третье состояние;
                                  //  «3» - синхронно переводит устройство в режим пониженного энергопотребления. Выход CPO устанавливается в третье состояние.
                                  //  В режиме пониженного потребления все внутренние счетчики устанавливаются в начальное состояние.
                                    
char PRE = 1;                  //  Код управления коэффициентов
                                  //  деления предделителя:
                                  //  «0» - 4/5 (для частот до 1,8 ГГц); 12...16383
                                  //  «1» - 8/9 (для частот до 3,6 ГГц); 56...32767
                                  //  «2» - 16/17 (для частот до 6,0 ГГц); 240...65535
                                  //  «3» - режим работы с входным импедансом предделителя ~ 100 Ом

char PDP = 0;                     //  Полярность частотно-фазового детектора
                                  //  0 – для ГУН с положительным наклоном вольтчастотной характеристики
                                  //  1 – для ГУН с отрицательным наклоном вольт-частотной характеристики
                                  
char DLY = 0;                     //  Задержка импульса сброса триггеров частотно-фазового детектора:
                                  //  «0» - ~ 1 нс;
                                  //  «1» - ~ 2 нс;
                                  //  «2» - ~ 3 нс;
                                  //  «3» - ~ 4 нс
                                  
char OSEL = 2;                    //  Управление выводом OUT:
                                  //  «0» - SDO – выход SDO последовательного интерфейса;
                                  //  «1» - FCO – выход целочисленного делителя DIVNM;
                                  //  «2» - RCO – выход делителя опорной частоты DIVR;
                                  //  «3» - LOCK – признак захвата фазы;
                                  //  «4» - REFIN;
                                  //  «5» - PRE – выход предделителя;
                                  //  «6» - «0»;
                                  //  «7» - третье состояние
                                  
char AUX45 = 0;                   //  Вспомогательный бит управления режимом работы предделителя рекомендуется устанавливать «1» в режиме деления 4/5, 
                                  //  а также в случаях нарушения работы предделителя
                                  
char PRETM = 0;                   //  «0» - работа в нормальном режиме;
                                  //  «1» - Вспомогательный режим работы предделителя
                                  
char FO = 0;                      //  «1» - режим работы сигма-дельта модулятора первого и пятого порядка

char SDM = 0;                     //  Режим работы сигма-дельта модулятора:
                                  //  «0» - выключен (FO = 0);
                                  //  «0» - SDM первого порядка (FO = 1);
                                  //  «1» - SDM второго порядка (FO = 0);
                                  //  «2» - SDM третьего порядка (FO = 0);
                                  //  «3» - SDM четвёртого порядка (FO = 0);
                                  //  «3» - SDM пятого порядка (FO = 1)
                                  
char DTHE = 0;                    //  «1» - включение схемы рандомизации помех дробности

char CPI1 = 4;                 //  Код управления током генератора тока «1»:
                                  //  «000» - ICPO = 0,625 мА (Rset = 3,2кОм);
                                  //  «001» - ICPO = 1,25 мА (Rset = 3,2кОм);
                                  //  «010» - ICPO = 1,875 мА (Rset = 3,2кОм);
                                  //  «011» - ICPO = 2,5 мА (Rset = 3.2 кОм);
                                  //  «100» - ICPO = 3,125 мА (Rset = 3,2кОм);
                                  //  «101» - ICPO = 3,75 мА (Rset = 3,2кОм);
                                  //  «110» - ICPO = 4,375 мА (Rset = 3,2кОм);
                                  //  «111» - ICPO = 5 мА (Rset = 3,2 кОм)
                                  
char CPI2 = 0;                 //  Код управления током генератора тока «2».
                                  //  Используется в режиме «быстрого захвата» фазы
                                  
char LM = 0;                   //  Режим переключения токов генератора тока (работает если OSEL не равен семи):
                                  //  «0» - применяется CPI1;
                                  //  «1» - применяется CPI2;
                                  //  «2» - применяется CPI2, а через ~ 4*CNT такта применяется CPI1 (значение регистра LM сбрасывается в «0»);
                                  //  «3» - применяется CPI2, а через ~ 4*CNT такта после захвата фазы применяется CPI1(значение регистра LM сбрасывается в «0»)

unsigned int CNT = 0;        //  Задержка переключения генераторовтока (см. поле LM)

char PMT = 0;                  //  Погрешность совпадения фазы для формирования признака захвата фазы:
                                  //  «0» - 1 нс;
                                  //  «1» - 5 нс;
                                  //  «2» - 15 нс;
                                  //  «3» - 25 нс
                                  
unsigned int PMCNT = 5;      //  Счетчик совпадений фазы для формирования признака захвата фазы. Признак захвата фазы формируется, если произошло PMCNT совпадений фазы подряд

char TST = 0;                  //  Режим тестирования. Для нормальной работы должен быть установлен в «0»

unsigned int DFRAC = 0;     //  Приращение частоты ЛЧМ. Приращение частоты рассчитывается как (1/16)*DFRAC[19:0]*FPFD/MOD

unsigned int FRACINC = 0;      //  Приращение развертки (в периодах сигнала «RCO»). Временной интервал между каждым приращение частоты рассчитывается как FRACINC[7:0]/FPFD

unsigned int SAWSTEP = 0;     //  Количество приращений DFRAC

char FMP = 0;                     //  Полярность ЛЧМ:
                                  //  «0» - инкрементирование частоты ЛЧМ;
                                  //  «1» - декриментирование частоты ЛЧМ
                                  
char SETFRQ = 0;                  //  «1» - возврат к начальному значению частоты по окончанию цикла ЛЧМ (переполнению счетчика SAWSTEP);
                                  //  «0» - сохранение текущего значения частоты по окончанию цикла ЛЧМ (переполнению счетчика SAWSTEP)

char P = 0;                       //  Служебный бит.
                                  //  «0» - нормальный режим работы;
                                  //  «1» - происходит декрементированиесчетчика SAWSTEP. При обнулении счетчика SAWSTEP, следующий
                                  //  выполняемый профиль – NEXT2, а значению SAWSTEP присваивается FRAC (SAWSTEP = FRAC[11:0])
                                  
char S = 0;                       //  Служебный бит:
                                  //  «0» - нормальный режим работы;
                                  //  «1» - в профиль NEXT2 записывается SAWSTEP из активного профиля,а ктивным становится профиль NEXT1
                                  
unsigned int NEXT1 = 0;        //  Номер следующего выполняемого профиля. Используется только в режиме «ЛЧМ». Переход к профилю NEXT1 выполняется по переполнению счетчика SAWSTEP

unsigned int NEXT2 = 0;        //  Номер следующего выполняемого профиля (см. описание служебного бита P). Используется только в режиме «ЛЧМ»

char LFMST = 0;                   //  «0» - синтез ЛЧМ сигнала начинается с момента активации профиля;
                                  //  «1» - синтез ЛЧМ сигнала начинается с момента прихода положительного запускающего импульса на вход LFM микросхемы. 
                                  //  При этом используется профиль, записанный в поле NEXT2
                                  
unsigned int PRW = 0;          //  Номер записываемого профилячастотного синтеза

char PROFEN = 0;                  //  «0» - запрет выбора профиля частотного синтеза с помощью выводов микросхемы KINT[4:0];
                                  //  «1» - разрешение выбора профиля частотного синтеза с помощью выводов микросхемы KINT[4:0]. В этом случае автоматическая смена
                                  //  профилей по NEXT1 и NEXT2 не работает
                                  
unsigned int PRA = 0;          //  Номер используемого профиля частотного синтеза

char CMD = 0;                  //  При каждом прописывании этого регистра, следующая «SPI» команда возвращает команду (на выход SDO),
                                  //  код которой содержится в поле CMD. Команда считывается из записываемого профиля PRW

char res = 0;                                  
/////////////////////////////////////////

char REG_REF = 0;
char REG_INT = 2;
char REG_FRAC = 4;
char REG_MOD = 6;
char REG_CTR1 = 8;
char REG_CTR2 = 10;
char REG_CTR3 = 12;
char REG_LFM1 = 1;
char REG_LFM2 = 3;
char REG_LFM3 = 5;
char REG_PRW = 7;
char REG_PRA = 9;
char REG_READ = 14;

/////////////////////////////////////////

unsigned char value, bit_ctr;

/////////////////////////////////////////

/////////////////////////////
//======== ref register==========
void Ref (void){
int bit_ctr;
unsigned int value=0;
   ////////REG_REF/////////

   value = REG_REF;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;   
   } 
   //////res(6)////////
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   } 
   //////R//////// 
   value = R;
   for(bit_ctr=0;bit_ctr<14;bit_ctr++)   
   {  
        if(value & 0x02000)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }

}

//======== int register==========
/////////////////////////////
void Int (void){
long bit_ctr;
long value=0;
   ////////REG_INT/////////

   value = REG_INT;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;   
   } 
   //////res(3)////////
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   } 
   //////INT//////// 
   value = INT;
   for(bit_ctr=0;bit_ctr<17;bit_ctr++)   
   {  
        if(value & 0x010000)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }

}

//======== frac register==========
/////////////////////////////
void Frac (void){
int bit_ctr;
unsigned int value=0;
//======== Frac register==========
   ////////REG_FRAC/////////

   value = REG_FRAC;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;   
   } 
   //////res(4)////////
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   } 
   //////FRAC//////// 
   value = FRAC;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0x08000)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }

}

//======== mod register==========
/////////////////////////////
void Mod (void){
int bit_ctr;
unsigned int value=0;
//======== Mod register==========
   ////////REG_MOD/////////

   value = REG_MOD;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;   
   } 
   //////res(4)////////
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   } 
   //////MOD//////// 
   value = MOD;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0x08000)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }

}

//======== ctr1 register==========
/////////////////////////////
void Ctr1 (void){
int bit_ctr;
unsigned int value=0;
//======== Frac register==========
   ////////REG_CTR1/////////

   value = REG_CTR1;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;   
   } 
   //////DTHE//////// 
        if(DTHE == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;    
   //////SDM//////// 
   value = SDM;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////FO//////// 
        if(FO == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////PRETM//////// 
        if(PRETM == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////AUX45//////// 
        if(AUX45 == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////res(2)////////
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////OSEL//////// 
   value = OSEL;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////DLY//////// 
   value = DLY;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////PDP//////// 
        if(PDP == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////res//////// 
   res;
   sck1;   
   sck0;
   //////PRE//////// 
   value = PRE;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////OFF//////// 
   value = OFF;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////RST//////// 
        if(RST == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;                               

}

/////////////////////////////
//======== ctr2 register==========
void Ctr2 (void){
int bit_ctr;
unsigned int value=0;
   ////////REG_CTR2/////////

   value = REG_CTR2;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;   
   } 
   //////res(4)////////
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   } 
   //////CNT//////// 
   value = CNT;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////LM//////// 
   value = LM;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////CPI2//////// 
   value = CPI2;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////CPI1//////// 
   value = CPI1;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }          

}

/////////////////////////////
//======== ctr3 register==========
void Ctr3 (void){
int bit_ctr;
unsigned int value=0;
   ////////REG_CTR3/////////

   value = REG_CTR3;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;   
   } 
   //////TST//////// 
   value = TST;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   } 
   //////res(7)////////
   for(bit_ctr=0;bit_ctr<7;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////PMCNT//////// 
   value = PMCNT;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x080)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////PMT//////// 
   value = TST;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }       

}

/////////////////////////////
//======== lfm1 register==========
void Lfm1 (void){
int bit_ctr;
unsigned int value=0;
   ////////REG_LFM1/////////

   value = REG_LFM1;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;   
   } 
   //////DFRAC//////// 
   value = DFRAC;
   for(bit_ctr=0;bit_ctr<20;bit_ctr++)   
   {  
        if(value & 0x080000)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }

}

/////////////////////////////
//======== lfm2 register==========
void Lfm2 (void){
int bit_ctr;
unsigned int value=0;
   ////////REG_LFM2/////////

   value = REG_LFM2;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;   
   } 
   //////SAWSTEP//////// 
   value = SAWSTEP;
   for(bit_ctr=0;bit_ctr<12;bit_ctr++)   
   {  
        if(value & 0x0800)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////FRACINC//////// 
   value = FRACINC;
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
        if(value & 0x80)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }

}

/////////////////////////////
//======== lfm3 register==========
void Lfm3 (void){
int bit_ctr;
unsigned int value=0;
   ////////REG_LFM3/////////

   value = REG_LFM3;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;   
   }
   //////res(1)////////  
   res;  
   sck1;   
   sck0;       
   //////NEXT2//////// 
   value = NEXT2;
   for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {  
        if(value & 0x010)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////NEXT1//////// 
   value = NEXT1;
   for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {  
        if(value & 0x010)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////res(4)////////
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////S//////// 
        if(S == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////P//////// 
        if(P == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////SETFRQ//////// 
        if(SETFRQ == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////FMP//////// 
        if(FMP == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   sck1;   
   sck0;
   //////res(1)//////// 
   res;
   sck1;   
   sck0;                
}

/////////////////////////////
//======== prw register==========
void Prw (void){
int bit_ctr;
unsigned int value=0;
   ////////REG_PRW/////////

   value = REG_PRW;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;   
   } 
   //////res(1)////////  
   res;  
   sck1;   
   sck0;    
   //////PRW//////// 
   value = PRW;
   for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {  
        if(value & 0x010)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////res(13)////////
   for(bit_ctr=0;bit_ctr<13;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////LFMST////////  
        if(LFMST == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }  
   sck1;   
   sck0;
}

/////////////////////////////
//======== pra register==========
void Pra (void){
int bit_ctr;
unsigned int value=0;
   ////////REG_PRA/////////

   value = REG_PRA;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;   
   } 
   //////res(1)////////  
   res;  
   sck1;   
   sck0;    
   //////PRA//////// 
   value = PRA;
   for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {  
        if(value & 0x010)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////res(10)////////
   for(bit_ctr=0;bit_ctr<10;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   }
   //////PROFEN////////  
        if(PROFEN == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }  
   sck1;   
   sck0;  
   //////OFF//////// 
   value = OFF;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }
   //////RST////////  
        if(RST == 1)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }  
   sck1;   
   sck0;  
}         


/////////////////////////////
//======== read register==========
void Read (void){
int bit_ctr;
unsigned int value=0;
   ////////REG_READ/////////

   value = REG_READ;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;   
   } 
   //////res(16)////////
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
   res;  
   sck1;   
   sck0;   
   } 
   //////CMD//////// 
   value = CMD;
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
        if(value & 0x08)
        {
        sdi1;
        }
        else
        {
        sdi0;
        }
   value = (value << 1);  
   sck1;   
   sck0;  
   }

}
////////////////////////////////////////////////
///////////////////////////////////////////////

void SINTprog(void) {
scsn0;
Ref();
scsn1;
delayMicroseconds(10);
scsn0;
Int();
scsn1;
delayMicroseconds(10);
scsn0;
Frac();
scsn1;
delayMicroseconds(10);
scsn0;
Mod();
scsn1;
delayMicroseconds(10);
scsn0;
Ctr1();
scsn1;
delayMicroseconds(10);
scsn0;
Ctr2();
scsn1;
delayMicroseconds(10);
scsn0;
Ctr3();
scsn1;
delayMicroseconds(10);
scsn0;
Lfm1();
scsn1;
delayMicroseconds(10);
scsn0;
Lfm2();
scsn1;
delayMicroseconds(10);
scsn0;
Lfm3();
scsn1;
delayMicroseconds(10);
scsn0;
Prw();
scsn1;
delayMicroseconds(10);
scsn0;
Pra();
scsn1;
delayMicroseconds(10);
scsn0;
Read();
scsn1;
delayMicroseconds(10);
}  

///////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);

//SINTprog();
}

void loop() {
  led1;
  OSEL = 1;
  SINTprog();   
  delay(5000);              
  led0;
  OSEL = 2;
  SINTprog();        
  delay(5000);
  led1;
  OSEL = 3;
  SINTprog();   
  delay(5000);                 
}
