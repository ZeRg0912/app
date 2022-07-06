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
byte value = 0;
/////////////////////////////////////////
byte  R0 = 0;//0;
byte  R1 = 16;//1;
byte  R2 = 8;//2;
byte  R3 = 24;//3;
byte  R4 = 4;//4;
byte  R5 = 20;//5;
byte  R6 = 12;//6;
byte  R7 = 28;//7;
byte  R8 = 2;//8;
byte  R9 = 18;//9;
byte  R10 = 10;//10;
byte  R11 = 26;//11;
byte  R12 = 6;//12;
byte  R13 = 22;//13;
byte  R14 = 14;//14;
byte  R15 = 30;//15;
byte  R16 = 1;//16;
byte  R17 = 17;//17;
byte  R18 = 9;//18;
byte  R19 = 25;//19;
byte  R20 = 5;//20;
byte  R21 = 21;//21;
byte  R22 = 13;//22;
/////////////////////////////////////////
byte  R0_data = 0;//128;//1; 
byte  R1_data = 0;//9; 
byte  R2_data = 1;//128; 
byte  R3_data = 0;//9; 
byte  R4_data = 1;//128; 
byte  R5_data = 252;//63; 
byte  R6_data = 126;//127; 
byte  R7_data = 161;//133; 
byte  R8_data = 197;//163; 
byte  R9_data = 213;//171; 
byte  R10_data = 32;//4; 
byte  R11_data = 0;//64;//15; 
byte  R12_data = 0;//130;//65; 
byte  R13_data = 0;//0; 
byte  R14_data = 0;//0; 
byte  R15_data = 0;//0; 
byte  R16_data = 64;//64; 
byte  R17_data = 255;//181; 
byte  R18_data = 15;//2; 
byte  R19_data = 45;//176; 
byte  R20_data = 3;//227;//199; 
byte  R21_data = 14;//112; 
byte  R22_data = 192;//3; 
/////////////////////////////
void R0_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R0;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R0_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R1_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R1;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R1_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R2_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R2;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R2_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R3_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R3;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R3_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R4_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R4;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R4_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R5_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R5;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R5_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R6_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R6;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R6_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R7_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R7;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R7_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R8_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R8;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R8_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R9_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R9;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R9_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R10_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R10;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R10_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R11_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R11;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R11_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R12_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R12;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R12_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R13_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R13;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R13_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R14_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R14;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R14_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R15_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R15;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R15_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R16_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R16;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R16_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R17_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R17;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R17_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R18_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R18;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R18_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R19_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R19;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R19_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R20_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R20;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R20_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R21_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R21;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R21_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
void R22_reg (void){
byte bit_ctr;
en1;
////////////WR///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
//////////ADDRESS////////////
   value = R22;
   for(bit_ctr=5;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x10)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0; 
////////////01///////////////
   dat0;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);
   dat1;
   delay(1);
   clk1;
   delay(10);   
   clk0;
   delay(1);                   
///////////DATA//////////////
   value = R22_data;
   for(bit_ctr=8;bit_ctr>0;bit_ctr--)   
   {  
        if(value & 0x80)
        {
        dat1;
   delay(1);
        }
        else
        {
        dat0;
   delay(1);
        }
   value = (value >> 1);  
   clk1;
   delay(10);   
   clk0;
   delay(1);   
   }
value = 0;
en0; 
   }
////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////
void SINTprog (void) {
////////////////////////////////////////////////
delay(10);
R0_reg();
delay(10);
R1_reg();
delay(10);
R2_reg();
delay(10);
R3_reg();
delay(10);
R4_reg();
delay(10);
R5_reg();
delay(10);
R6_reg();
delay(10);
R7_reg();
delay(10);
R8_reg();
delay(10);
R9_reg();
delay(10);
R10_reg();
delay(10);
R11_reg();
delay(10);
R12_reg();
delay(10);
R13_reg();
delay(10);
R14_reg();
delay(10);
R15_reg();
delay(10);
R16_reg();
delay(10);
R17_reg();
delay(10);
R18_reg();
delay(10);
R19_reg();
delay(10);
R20_reg();
delay(10);
R21_reg();
delay(10);
R22_reg();
delay(10);
////////////////////////////////////////////////
}  
///////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
//  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
//  pinMode(13, OUTPUT);
//  pinMode(8, OUTPUT);
  delay(10);
  delay(10);
  delay(10000);
    /*pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);*/
}

void loop() {
  //delay(10000);
  SINTprog(); 
  delay(1800000);           
  }

void RESINT() {
  flag = _1;            
}
