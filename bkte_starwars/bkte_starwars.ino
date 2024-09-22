/*********************************************************************
MADE BY BKTE
FOR THE LIBRARIES ; bkte.xyz


THANKS TO
Volos Projects for main idea and base code
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h> 
#include <Fonts/FreeSans9pt7b.h>

#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);







const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

const unsigned char PROGMEM dioda16 [] = {

0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x3F, 0xF0, 0x3C, 0x00, 0x3C, 0x00, 0xFF, 0x00, 0x7F, 0xFF,
0x7F, 0xFF, 0xFF, 0x00, 0x3C, 0x00, 0x3C, 0x00, 0x1F, 0xF0, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00

};

const unsigned char PROGMEM storm [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x7F, 0xFE, 0x00, 0x00, 0x00, 0x07, 0x80, 0x01, 0xE0, 0x00, 0x00, 0x0C,
0x00, 0x00, 0x20, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x30, 0x00, 0x00, 0x04, 0x00,
0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 0x00, 0x60, 0x00, 0x00,
0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x00, 0x40,
0x00, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x00, 0x7F, 0xE0, 0x00, 0x01, 0x00,
0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xD7, 0xFF, 0xFF,
0xE1, 0x00, 0x01, 0xBF, 0xFC, 0x1F, 0xFA, 0x80, 0x01, 0xBF, 0xF1, 0xCF, 0xFA, 0x80, 0x01, 0x3F,
0xC2, 0x37, 0xF7, 0x80, 0x01, 0xEF, 0x9C, 0x01, 0xE7, 0xC0, 0x01, 0xE0, 0x70, 0x06, 0x06, 0x80,
0x01, 0xE0, 0xC0, 0x03, 0x06, 0x80, 0x01, 0xFF, 0x80, 0x01, 0xFF, 0x80, 0x01, 0xF8, 0x00, 0x00,
0x1D, 0xC0, 0x03, 0x70, 0x00, 0x80, 0x0C, 0x60, 0x05, 0xB0, 0x07, 0xF0, 0x08, 0x90, 0x09, 0x10,
0x1F, 0xF8, 0x09, 0xD0, 0x0B, 0x90, 0x1F, 0x7C, 0x03, 0xF0, 0x0F, 0xC0, 0xFC, 0x0F, 0x07, 0x90,
0x0D, 0x43, 0xC0, 0x03, 0x07, 0x90, 0x05, 0x64, 0x00, 0x00, 0xCF, 0x10, 0x07, 0xFC, 0x00, 0x00,
0x26, 0x10, 0x01, 0x80, 0x00, 0x00, 0x10, 0x20, 0x01, 0x00, 0x00, 0x00, 0x0E, 0x40, 0x01, 0x80,
0x07, 0xF0, 0x01, 0x80, 0x00, 0x80, 0x07, 0xC8, 0x00, 0x80, 0x00, 0x80, 0x0B, 0xE8, 0x00, 0x80,
0x00, 0x87, 0x97, 0xE9, 0xE0, 0x80, 0x00, 0x87, 0xDF, 0xEF, 0xA0, 0x80, 0x00, 0x4B, 0xFF, 0xFF,
0xA0, 0x80, 0x00, 0x6B, 0xDF, 0xFB, 0xA3, 0x00, 0x00, 0x24, 0x97, 0xE8, 0x24, 0x00, 0x00, 0x1E,
0x1F, 0xC0, 0x2C, 0x00, 0x00, 0x07, 0xF8, 0x1F, 0xF0, 0x00, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00
};



void setup()   {                
 

 pinMode(3,INPUT_PULLUP);
 pinMode(12,INPUT_PULLUP);
 pinMode(11,INPUT_PULLUP);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);  
  display.display();
  display.clearDisplay();
display.setTextSize(0);
   display.drawBitmap(6, 11,storm, 48,48, 1);
    display.setFont(&FreeSans9pt7b);
  display.setTextColor(WHITE);
    display.setCursor(65,14);
  display.println("BKTE");
   display.setFont();
  display.setCursor(65,17);
  display.setTextSize(0);
  display.println("vs");
  display.setCursor(0,0);
  float voltage=readVcc()/1000;
  display.println(voltage);;
  display.setFont(&FreeSans9pt7b);
  display.setCursor(65,39);
  display.println("Death");
  display.setFont();
  display.setCursor(65,42);
  display.println("star ");
  display.setTextSize(0);
  
  display.setCursor(65,55);
 
  display.println("by Bkte");
  
    display.setCursor(65,20);

   display.display();
   
 

display.setFont(); 
 beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
 
 
 
  delay(500);
}
int BulletX=0;
int BulletY=0;
int exists=0;
int enemyPosition=8;
int direction=0;
int gameOver=0;
int enemyBulletX=95;
int enemyBulletY=0;
int enemyBulletX2=95;
int enemyBulletY2=0;
int enemyBulletX3=95;
int enemyBulletY3=0;
int points=0;

int speed=3; //speed of bullet
int ball=1;
int smallest=600;
int largest=1200;
int diameter=10;

int enemyBulletX4=95;
int enemyBulletY4=0;
int lives=5;
int start=0;
int fired=0;
int level=1;
int center=95;
unsigned long startetno=0;
unsigned long selected=0;
unsigned long current=0;
unsigned long levelclear=0;
int position=30;
void loop() {

  if(gameOver==0){
  display.clearDisplay();

display.drawPixel(50,30,1);
display.drawPixel(30,17,1);
display.drawPixel(60,18,1);
display.drawPixel(55,16,1);
display.drawPixel(25,43,1);
 display.drawPixel(100,43,1); 
display.drawPixel(117,52,1);
display.drawPixel(14,49,1);
display.drawPixel(24,24,1);
display.drawPixel(78,36,1);
display.drawPixel(80,57,1);
display.drawPixel(107,11,1);
display.drawPixel(150,11,1);
display.drawPixel(5,5,1);
display.drawPixel(8,7,1);
display.drawPixel(70,12,1);
display.drawPixel(10,56,1);
display.drawPixel(70,25,1);


  
  if(start==0){
  startetno=millis();
  selected= random(400,1200);
  start=1;
  }
 current=millis();




if((current-levelclear)>50000)
{
  levelclear=current;
  level=level+1;

 speed=speed+1; 
 if ( level % 2 == 0 )
    {
       ball=ball+1;
       diameter=diameter-1;
    }
smallest=smallest-50;
largest=largest-50;

  }



 if((selected+startetno)<current)
  {
    start=0;
   fired=fired+1;
   if(fired==1)
   {enemyBulletX=95;
    enemyBulletY=enemyPosition;}
     if(fired==2){
      enemyBulletX2=95;
      enemyBulletY2=enemyPosition;}
      if(fired==3)
      {
        enemyBulletX3=95;
          enemyBulletY3=enemyPosition;
      }
  
      
     if(fired==4){
      enemyBulletX4=95;
      enemyBulletY4=enemyPosition;
     
     }
     
    
      
   }

  
    if(fired>0)
    {
    display.drawCircle(enemyBulletX,enemyBulletY,2,1);
    enemyBulletX=enemyBulletX-speed;}

    if(fired>1)
    {
    display.drawCircle(enemyBulletX2,enemyBulletY2,1,1);
    enemyBulletX2=enemyBulletX2-speed;}

     if(fired>2)
    {
    display.drawCircle(enemyBulletX3,enemyBulletY3,4,1);
    enemyBulletX3=enemyBulletX3-speed;}

     if(fired>3)
    {
    display.drawCircle(enemyBulletX4,enemyBulletY4,2,1);
    enemyBulletX4=enemyBulletX4-speed;}

 if(digitalRead(12)==0 && position>=2){
 position=position-2;}

  if(digitalRead(11)==0&& position<=46){
 position=position+2;}
  

   if(digitalRead(3)==0 && exists==0)
  {
    exists=1;
    BulletX=6;
    BulletY=position+8;
    tone(9,1200,20);
  
    
    }
   if(exists==1)

    {
    BulletX=BulletX+8 ;
    
    display.drawLine(BulletX,BulletY,BulletX+4,BulletY,1);
    }
   
   display.drawBitmap(4, position,dioda16, 16,16, 1);
   display.fillCircle(center,enemyPosition,diameter,1);
   display.fillCircle(center+2,enemyPosition+3,diameter/3,0);

 display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(33,57);
  display.println("score:");
    display.setCursor(68,57);
  display.println(points);

   display.setCursor(33,0);
  display.println("lives:");
    display.setCursor(68,0);
  display.println(lives);
   
   display.setCursor(110,0);
  display.println("L:");

  display.setCursor(122,0);
  display.println(level);

  display.setCursor(108,57);
  display.println(current/1000);
   display.display();

   if(BulletX>128)exists=0;
  
 
  
   if(direction==0){
   enemyPosition=enemyPosition+ball;}
   else
   {enemyPosition=enemyPosition-ball;}

   if(enemyPosition>=(64-diameter))
   direction=1;
   if(enemyPosition<=diameter)
   direction=0;

   if(BulletY>=enemyPosition-diameter && BulletY<=enemyPosition+diameter)
   if(BulletX>(center-diameter)&&BulletX<(center+diameter))
   {
   BulletX=-20;
   tone(9,500,20);
   points=points+1;
   exists=0;
   }

int positionicija=position+8;
     if(enemyBulletY>=positionicija-8 && enemyBulletY<=positionicija+8)
   if(enemyBulletX<12&&enemyBulletX>4)
   {
   enemyBulletX=95;
   enemyBulletY=-50;
   tone(9,100,100);
 lives=lives-1;
   }

        if(enemyBulletY2>=positionicija-8 && enemyBulletY2<=positionicija+8)
   if(enemyBulletX2<12&&enemyBulletX2>4)
   {
   enemyBulletX2=-50;
   enemyBulletY2=-50;
   tone(9,100,100);
 lives=lives-1;
   }

      if(enemyBulletY3>=positionicija-8 && enemyBulletY3<=positionicija+8)
   if(enemyBulletX3<12&&enemyBulletX3>4)
   {
   enemyBulletX3=-50;
   enemyBulletY3=-50;
   tone(9,100,100);
 lives=lives-1;
   }

      if(enemyBulletY4>=positionicija-8 && enemyBulletY4<=positionicija+8)
   if(enemyBulletX4<12&&enemyBulletX4>4)
   {
   enemyBulletX4=200;
   enemyBulletY4=-50;
   fired=0;
   tone(9,100,100);
 lives=lives-1;
   }
 
if(enemyBulletX4<1){
   fired=0;
   enemyBulletX4=200;}

   if(lives==0)
   gameOver=1;
  }

  if(gameOver==1)
  {
    if(lives==0){
     tone(9,200,300);
     delay(300);
      tone(9,250,200);
      delay(200);
       tone(9,300,300);
       delay(300);
       lives=5;
    }
   display.clearDisplay();
   display.setFont();  
 display.setTextSize(2);
  display.setTextColor(WHITE);
    display.setCursor(7,10);
  display.println("GAME OVER!");
   display.setTextSize(1);
  display.setCursor(7,30);
   display.println("score:");
    display.setCursor(44,30);
    display.println(points);
    display.setCursor(7,40);
    display.println("level:");
     display.setCursor(44,40);
     display.println(level);
     display.setCursor(7,50);
     display.println("time(s):");
       display.setCursor(60,50);
       
       display.println(current/1000);
  display.display();

    if(digitalRead(3)==0)
    {
       tone(9,280,300);
     delay(300);
      tone(9,250,200);
      delay(200);
       tone(9,370,300);
       delay(300);
      restart();
    }
    }
}

void restart()
{
 BulletX=0;
 BulletY=0;
exists=0;
 enemyPosition=8;
 direction=0;
 gameOver=0;
 enemyBulletX=95;
 enemyBulletY=0;
 enemyBulletX2=95;
 enemyBulletY2=0;
enemyBulletX3=95;
enemyBulletY3=0;
points=0;

 speed=3; 
ball=1;
 smallest=600;
 largest=1200;
 diameter=12;

 enemyBulletX4=95;
enemyBulletY4=0;
lives=5;
start=0;
 fired=0;
level=1;
 startetno=0;
 selected=0;
 current=0;
levelclear=0;
  
  
  
  
  }

long readVcc() {

  #if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  #elif defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
    ADMUX = _BV(MUX5) | _BV(MUX0);
  #elif defined (__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
    ADMUX = _BV(MUX3) | _BV(MUX2);
  #else
    ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  #endif  

  delay(2); 
  ADCSRA |= _BV(ADSC); 
  while (bit_is_set(ADCSRA,ADSC)); 

  uint8_t low  = ADCL; 
  uint8_t high = ADCH; 

  long result = (high<<8) | low;

  result = 1125300L / result; 
  return result; 
}


void beep(int note, int duration)
{
 
  tone(9, note, duration);
 

  
    delay(duration);
    


  noTone(9);
 
  delay(50);
 
 
}



