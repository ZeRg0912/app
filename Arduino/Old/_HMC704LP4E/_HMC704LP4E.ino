#define clk0 digitalWrite(6,LOW)
#define clk1 digitalWrite(6,HIGH)
#define dat0 digitalWrite(5,LOW)
#define dat1 digitalWrite(5,HIGH)
#define le0 digitalWrite(4,LOW)
#define le1 digitalWrite(4,HIGH)
#define ce0 digitalWrite(7,LOW)
#define ce1 digitalWrite(7,HIGH)
#define led0 digitalWrite(13,LOW)
#define led1 digitalWrite(13,HIGH)
#define _0 false
#define _1 true


////////////////////////////////////////////////
boolean flag = _1;
unsigned long value, bit_ctr;
unsigned long R_DIV = 0x04; //0x02 for 200MHz = 100 MHz PFD
unsigned long N_INT_DIV = 0x32;// 0x1E for 3GHz = 100 MHz PFD
unsigned long N_FRAC_DIV = 0x00;
unsigned long GPO_SEL = 0x09;

unsigned long KEEP_CHIP_EN = 0xFE;
unsigned long AUX_SPI = 0x00;
unsigned long SEED_SEL = 0x00;
unsigned long MOD_ORDER = 0x02;
unsigned long FRAC_BYPASS = 0x01;
unsigned long AUTOSEED = 0x01;
unsigned long CLK_REF_DIV_SEL = 0x01;
unsigned long MOD_CLK_SEL = 0x01;
unsigned long FRAC_RSTB = 0x00;
unsigned long RDIV_BIST = 0x00;
unsigned long LKD_WINCNT_MAX = 0x00;
unsigned long EN_INTERNAL_LD = 0x01;
unsigned long LD_TYPE = 0x00;
unsigned long LD_DURATION = 0x00;
unsigned long LD_TIM_FREQ_CONTROL = 0x00;
unsigned long LD_TIM_TEST = 0x00;
unsigned long AUTORELOCK = 0x00;
unsigned long ANALOG_EN = 0xC9BEFF; // 0xC1BEFF - divider /2 OFF | 0xC9BEFF - divider /2 ON

unsigned long CP_DWN_GAIN = 0x0A;
unsigned long CP_UP_GAIN = 0x0A;
unsigned long OFFSET_CURR = 0x00;
unsigned long OFFSET_DWN = 0x01;
unsigned long OFFSET_UP = 0x00;
unsigned long HIK_CP = 0x00;
unsigned long MOCUNTER = 0x03;
unsigned long CP_INTERNAL_BIAS = 0x03;
unsigned long PS_BIAS = 0x00;
unsigned long FORCE_CP_MID = 0x00;
unsigned long FORCE_CP_DN = 0x00;
unsigned long FORCE_CP_UP = 0x00;
unsigned long CSP_MOD = 0x00;
unsigned long PD_UP = 0x01;
unsigned long PD_DWN = 0x01;
unsigned long PD_INVERT = 0x00;
unsigned long SHORT_PD_IN = 0x00;
unsigned long PD_DEL_SEL = 0x01;


////////////////////////////////////////////////
void ID_REG (void){
unsigned long bit_ctr;
unsigned long value=0;
dat0;
delay(1);
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x00;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   } 
   ////////RESET/////////
   value = 0x10;
   for(bit_ctr=0;bit_ctr<24;bit_ctr++)   
   {  
        if(value & 0x800000)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);  
   }
dat0;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
le0;
delay(1);
}
////////////////////////////////////////////////

////////////////////////////////////////////////
void GPO_REG (void){
unsigned long bit_ctr;
unsigned long value=0;
dat0;
delay(1);
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x0F;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////14 zero/////////
   value = 0x00;
   for(bit_ctr=0;bit_ctr<14;bit_ctr++)   
   {  
   dat0;
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);  
   }
   ////////DISABLE PFET_NFET/////////
dat0;
clk1;
delay(1);
clk0;
delay(1);
dat0;
clk1;
delay(1);
clk0;
delay(1);
   ////////PREVENT_DRIVER_DISABLE/////////
dat1;
clk1;
delay(1);
clk0;
delay(1);
   ////////PREVENT_AUTOMUX_SDO/////////
dat0;
clk1;
delay(1);
clk0;
delay(1);  
   ////////GPO_TEST_DATA/////////
dat0;
clk1;
delay(1);
clk0;
delay(1);     
   ////////GPO_SEL/////////
   value = GPO_SEL;
   for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {  
        if(value & 0x10)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);  
   }
/////////////////////////////////////////
dat0;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
le0;
delay(1);
}
////////////////////////////////////////////////

////////////////////////////////////////////////
void PWDWN_REG (void){
unsigned long bit_ctr;
unsigned long value=0;
dat0;
delay(1);
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x01;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////16 zero/////////
   value = 0x00;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
   dat0;
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);  
   }    
   ////////PWDWN/////////
   value = KEEP_CHIP_EN;
   for(bit_ctr=0;bit_ctr<9;bit_ctr++)   
   {  
        if(value & 0x100)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);  
   }
dat0;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
le0;
delay(1);
}
////////////////////////////////////////////////

////////////////////////////////////////////////
void RDIV_REG (void){
unsigned long bit_ctr;
unsigned long value=0;
dat0;
delay(1);
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x02;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////10 zero/////////
   for(bit_ctr=0;bit_ctr<10;bit_ctr++)   
   {
   dat0;   
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);  
   }    
   ////////RDIV/////////
   value = R_DIV;
   for(bit_ctr=0;bit_ctr<14;bit_ctr++)   
   {  
        if(value & 0x2000)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);  
   }
dat0;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
le0;
delay(1);
}
////////////////////////////////////////////////

////////////////////////////////////////////////
void N_DIV_INT_REG (void){
unsigned long bit_ctr;
unsigned long value=0;
dat0;
delay(1);
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x03;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////5 zero/////////
   for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {  
   dat0;
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);  
   }    
   ////////N_DIV/////////
   value = N_INT_DIV;
   for(bit_ctr=0;bit_ctr<19;bit_ctr++)   
   {  
        if(value & 0x40000)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);  
   }
dat0;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
le0;
delay(1);
}
////////////////////////////////////////////////

////////////////////////////////////////////////
void N_DIV_FRAC_REG (void){
unsigned long bit_ctr;
unsigned long value=0;
dat0;
delay(1);
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x04;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////N_DIV/////////
   value = N_FRAC_DIV;
   for(bit_ctr=0;bit_ctr<24;bit_ctr++)   
   {  
        if(value & 0x800000)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);  
   }
dat0;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
le0;
delay(1);
}
////////////////////////////////////////////////

////////////////////////////////////////////////
void SD_CFG_REG (void){
unsigned long bit_ctr;
unsigned long value=0;
dat0;
delay(1);
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x06;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////1 zero/////////
   dat0; 
   clk1;
   delay(1);   
   clk0;
   delay(1);    
   ////////2 reserved/////////
   dat0; 
   clk1;
   delay(1);   
   clk0;
   delay(1);
   dat0; 
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////RDIV_BIST/////////
   value = RDIV_BIST;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////BIST_EN/////////
   dat0;
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   ////////PFD RATES/////////
   dat1;
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   dat1;
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////4 reserved/////////
   for(bit_ctr=0;bit_ctr<4;bit_ctr++)   
   {  
   dat0;
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////FRAC_RSTB/////////
   if (FRAC_RSTB == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   ////////MOD_CLK_SEL/////////
   if (MOD_CLK_SEL == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////CLK_REF_DIV_SEL/////////
   if (CLK_REF_DIV_SEL == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////AUTOSEED/////////
   if (AUTOSEED == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////FRAC_BYPASS/////////
   if (FRAC_BYPASS == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////3 reserved/////////
   value = 0x04;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////MOD_ORDER/////////
   value = MOD_ORDER;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////SEED_SEL/////////
   value = SEED_SEL;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }                                               
dat0;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
le0;
delay(1);
}
////////////////////////////////////////////////

////////////////////////////////////////////////
void LD_REG (void){
unsigned long bit_ctr;
unsigned long value=0;
dat0;
delay(1);
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x07;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////10 zero/////////
   for(bit_ctr=0;bit_ctr<10;bit_ctr++)   
   {  
   dat0;
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }   
   ////////AUTORELOCK/////////
   if (AUTORELOCK == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////LD_TIM_TEST/////////
   if (LD_TIM_TEST == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);       
   ////////LD_TIM_FREQ_CONTROL/////////
   value = LD_TIM_FREQ_CONTROL;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////LD_DURATION/////////
   value = LD_DURATION;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////LD_TYPE/////////
   if (LD_TYPE == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   ////////2 reserved/////////
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
   dat0;  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////EN_INTERNAL_LD/////////
   if (EN_INTERNAL_LD == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////LKD_WINCNT_MAX/////////
   value = LKD_WINCNT_MAX;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }                                                          
dat0;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
le0;
delay(1);
}
////////////////////////////////////////////////

////////////////////////////////////////////////
void ANALOG_EN_REG (void){
unsigned long bit_ctr;
unsigned long value=0;
dat0;
delay(1);
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x08;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////ANALOG_EN/////////
   value = ANALOG_EN;
   for(bit_ctr=0;bit_ctr<24;bit_ctr++)   
   {  
        if(value & 0x800000)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }                                                 
dat0;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
le0;
delay(1);
}
////////////////////////////////////////////////

////////////////////////////////////////////////
void CP_REG (void){
unsigned long bit_ctr;
unsigned long value=0;
dat0;
delay(1);
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x09;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////HIK_CP/////////
   if (HIK_CP == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////OFFSET_UP/////////
   if (OFFSET_UP == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////OFFSET_DWN/////////
   if (OFFSET_DWN == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   ////////OFFSET_CURR/////////
   value = OFFSET_CURR;
   for(bit_ctr=0;bit_ctr<7;bit_ctr++)   
   {  
        if(value & 0x40)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }                                                  
   ////////CP_UP_GAIN/////////
   value = CP_UP_GAIN;
   for(bit_ctr=0;bit_ctr<7;bit_ctr++)   
   {  
        if(value & 0x40)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////CP_DWN_GAIN/////////
   value = CP_DWN_GAIN;
   for(bit_ctr=0;bit_ctr<7;bit_ctr++)   
   {  
        if(value & 0x40)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }    
dat0;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
le0;
delay(1);
}
////////////////////////////////////////////////

void AUX_SPI_REG (void){
unsigned long bit_ctr;
unsigned long value=0;
dat0;
delay(1);
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x05;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////8 zero/////////
   for(bit_ctr=0;bit_ctr<8;bit_ctr++)   
   {  
   dat0;
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }      
   ////////RESERVED/////////
   value = AUX_SPI;
   for(bit_ctr=0;bit_ctr<16;bit_ctr++)   
   {  
        if(value & 0x8000)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }    
dat0;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
le0;
delay(1);
}
////////////////////////////////////////////////

////////////////////////////////////////////////
void AUX_SPI_TRIG_REG (void){
unsigned long bit_ctr;
unsigned long value=0;
dat0;
delay(1);
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x0A;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////RESERVED/////////
   value = 0x1800;
   for(bit_ctr=0;bit_ctr<24;bit_ctr++)   
   {  
        if(value & 0x800000)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }    
dat0;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
le0;
delay(1);
}
////////////////////////////////////////////////

////////////////////////////////////////////////
void PD_REG (void){
unsigned long bit_ctr;
unsigned long value=0;
dat0;
delay(1);
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x0B;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////1 res/////////
   dat0;
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   ////////5 res/////////
   for(bit_ctr=0;bit_ctr<5;bit_ctr++)   
   {  
   dat0;
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////MCOUNTER/////////
   value = MOCUNTER;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }         
   ////////CP_INTERNAL_BIAS/////////
   value = CP_INTERNAL_BIAS;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }       
   ////////PS_BIAS/////////
   value = PS_BIAS;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   } 
   ////////FORCE_CP_MID/////////
   if (FORCE_CP_MID == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////FORCE_CP_DN/////////
   if (FORCE_CP_DN == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////FORCE_CP_UP/////////
   if (FORCE_CP_UP == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////CSP_MOD/////////
   value = CSP_MOD;
   for(bit_ctr=0;bit_ctr<2;bit_ctr++)   
   {  
        if(value & 0x02)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   } 
   ////////PD_UP/////////
   if (PD_UP == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////PD_DWN/////////
   if (PD_DWN == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////PD_INVERT/////////
   if (PD_INVERT == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////SHORT_PD_IN/////////
   if (SHORT_PD_IN == 1){
   dat1;
   }
   else
   {
    dat0;
   }
   delay(1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);
   ////////PD_DEL_SEL/////////
   value = PD_DEL_SEL;
   for(bit_ctr=0;bit_ctr<3;bit_ctr++)   
   {  
        if(value & 0x04)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   } 
dat0;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
le0;
delay(1);
}
////////////////////////////////////////////////

////////////////////////////////////////////////
void EXACT_FREQ_REG (void){
unsigned long bit_ctr;
unsigned long value=0;
dat0;
delay(1);
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x0C;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////10 res/////////
   value = 0x00;
   for(bit_ctr=0;bit_ctr<10;bit_ctr++)   
   {
   dat0;    
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }    
   ////////RESERVED/////////
   value = 0x00;
   for(bit_ctr=0;bit_ctr<14;bit_ctr++)   
   {  
        if(value & 0x2000)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }    
dat0;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
le0;
delay(1);
}
////////////////////////////////////////////////

////////////////////////////////////////////////
void readtest (void){
unsigned long bit_ctr;
unsigned long value=0;
dat1;
le1;
delay(1);
clk1;
delay(1);
clk0;
delay(1);
   ////////ID_reg/////////
   value = 0x0F;
   for(bit_ctr=0;bit_ctr<6;bit_ctr++)   
   {  
        if(value & 0x20)
        {
        dat1;
        }
        else
        {
        dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
   ////////DATA/////////
   value = 0x00;
   for(bit_ctr=0;bit_ctr<25;bit_ctr++)   
   {  
        if(value & 0x1000000)
        {
        //dat1;
        }
        else
        {
        //dat0;
        }
   value = (value << 1);  
   clk1;
   delay(1);   
   clk0;
   delay(1);   
   }
le0;
delay(1); 
}
////////////////////////////////////////////////


void SINTprog(void) {
ID_REG();
delayMicroseconds(10);
GPO_REG();
delayMicroseconds(10);
PWDWN_REG();
delayMicroseconds(10);
RDIV_REG();
delayMicroseconds(10);
N_DIV_INT_REG();
delayMicroseconds(10);
N_DIV_FRAC_REG();
delayMicroseconds(10);
AUX_SPI_REG();
delayMicroseconds(10);
SD_CFG_REG();
delayMicroseconds(10);
LD_REG();
delayMicroseconds(10);
ANALOG_EN_REG();
delayMicroseconds(10);
CP_REG();
delayMicroseconds(10);
PD_REG();
delayMicroseconds(10);
EXACT_FREQ_REG();
delayMicroseconds(10);
}  

void test(void){
  readtest();
}

void test_write(void){
  //ID_REG();
  //delay(10);
  PWDWN_REG();
  delay(10);
  GPO_REG();
  delay(10);
  RDIV_REG();
  delay(10);
  N_DIV_INT_REG();
  delay(10);
  N_DIV_FRAC_REG();
  delay(10);
  SD_CFG_REG();
  delay(10);
  LD_REG();
  delay(10);
  ANALOG_EN_REG();
  delay(10);
  CP_REG();
  delay(10);
  AUX_SPI_REG();
  delay(10);
  AUX_SPI_TRIG_REG();
  delay(10);
  PD_REG();
  delay(10);
  EXACT_FREQ_REG();
  delay(10); 
}

///////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);

ce1;
//OUTPOW = 0x03;
// Установка частоты
// для установки частоты необходимо оставить рабочими только две нужные строчки
//========200=========
//long=0xC80;          
//DIVSEL = 0x04;
//========400=========
//long=0xC80;          
//DIVSEL = 0x03;
//========430=========
//long=0xD70;          
//DIVSEL = 0x03;
//========240=========
//long=0xF00;          
//DIVSEL = 0x04;
//========229.3=======
//long=0xE54;          
//DIVSEL = 0x04;
//========800=========
//long=0xC80;          
//DIVSEL = 0x02;
//========1600=========
//long=0xC80;          
//DIVSEL = 0x01;
//========1500=========
//long=0xBB8;          
//DIVSEL = 0x01;
//========2380=========
//long=0x94C;          
//DIVSEL = 0x00;
//========2500=========
//long=0x9C4;          
//DIVSEL = 0x00;
//SINTprog();
//test();
test_write();
attachInterrupt(0, RESINT, RISING);
}

void loop() {
  /*led1;  
  delay(1000);              
  led0;    
  delay(1000); 
  led1;  
  delay(1000);              
  led0;    
  delay(1000); 
//cli();
//sei();
   if (flag == _0){
   } 
   else { 
   ce0;
   delay(200);
   ce1;
   delay(500); 
   //SINTprog();
   //test();
   test_write();
   flag = _0; 
   }   */
   GPO_SEL = 0x09;// R_DIV
   test_write();
   delay(5000);
   GPO_SEL = 0x0A;// N_DIV
   test_write();
   delay(5000);
   GPO_SEL = 0x01;// LD
   test_write();
   delay(5000);
}

void RESINT() {
flag = _1;             
}
