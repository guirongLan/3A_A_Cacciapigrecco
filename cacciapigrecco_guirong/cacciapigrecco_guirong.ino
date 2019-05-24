//bottoni
int button1=6;
int button2=5;
int button3=4;
int button4=3;
int button5=2;

int score=0; 
int volte=3;
int tempo;
//LCD
#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//caraterri personarizzati
byte Cuore[8] = {
        B00000,
        B01010,
        B11111,
        B11111,
        B11111,
        B01110,
        B00100,
        B00000
};

byte ghostChar[8] = {
        B00000,
        B01110,
        B10101,
        B11111,
        B11111,
        B11111,
        B10101,
        B00000
};

void setup() {
  // put your setup code here, to run once:
pinMode(button1,INPUT);
pinMode(button2,INPUT);
pinMode(button3,INPUT);
pinMode(button4,INPUT);
pinMode(button5,INPUT);
//lcd
lcd.begin(16, 2);
lcd.createChar(0, Cuore);
lcd.write(byte(0));
lcd.createChar(1,ghostChar);
lcd.write(byte(1));  
}

void programma()
{
  lcd.clear();
  lcd.print("punteggi:");
  lcd.print(score);
  lcd.print(" ");
    if(volte==3){
  lcd.write(0);
  lcd.write(0);
  lcd.write(0);
  }
   if(volte==2){
  lcd.write(0);
  lcd.write(0);
   }
    if(volte==1){
  lcd.write(0);
   }
   
  lcd.setCursor(0,1); //la parte del LCD
  
  if(tempo==1)
  {
   lcd.write(1);
   int i=0;
   while(digitalRead(button1)==LOW && digitalRead(button2)==LOW && digitalRead(button3)==LOW && digitalRead(button4)==LOW && digitalRead(button5)==LOW){
    delay(1);
    i++;
   }
    if (digitalRead(button1)==HIGH)
    {
     if(i<3000)
     {
      score++;
      delay(200);
      i=0;
      }
      else
      {
        delay(200);
        volte--;
      }
   }
   else{
        delay(200);
        volte--;
   }
  }
  if(tempo==2)
  {
   lcd.print(" ");
   lcd.write(1);
   int i=0;
   while(digitalRead(button1)==LOW && digitalRead(button2)==LOW && digitalRead(button3)==LOW && digitalRead(button4)==LOW && digitalRead(button5)==LOW){
    delay(1);
    i++;
   }
    if (digitalRead(button2)==HIGH)
    {
     if(i<3000)
     {
      score++;
      delay(200);
      i=0;
      }
      else
      {
        delay(200);
        volte--;
      }
   }
   else{
        delay(200);
        volte--;
   }
  }

  if(tempo==3)
  {
    lcd.print(" ");
    lcd.print(" ");
    lcd.write(1);
   int i=0;
   while(digitalRead(button1)==LOW && digitalRead(button2)==LOW && digitalRead(button3)==LOW && digitalRead(button4)==LOW && digitalRead(button5)==LOW){
    delay(1);
    i++;
   }
    if (digitalRead(button3)==HIGH)
    {
     if(i<3000)
     {
      score++;
      delay(200);
      i=0;
      }
      else
      {
        delay(200);
        volte--;
      }
   }
   else{
        delay(200);
        volte--;
   }
  }
  if(tempo==4)
  {
    lcd.print(" ");
    lcd.print(" ");
    lcd.print(" ");
   lcd.write(1);
   int i=0;
   while(digitalRead(button1)==LOW && digitalRead(button2)==LOW && digitalRead(button3)==LOW && digitalRead(button4)==LOW && digitalRead(button5)==LOW){
    delay(1);
    i++;
   }
    if (digitalRead(button4)==HIGH)
    {
     if(i<3000)
     {
      score++;
      delay(200);
      i=0;
      }
      else
      {
        delay(200);
        volte--;
      }
   }
   else{
        delay(200);
        volte--;
   }
  }
  if(tempo==5)
  {
    lcd.print(" ");
    lcd.print(" ");
    lcd.print(" ");
    lcd.print(" ");
   lcd.write(1);
   int i=0;
   while(digitalRead(button1)==LOW && digitalRead(button2)==LOW && digitalRead(button3)==LOW && digitalRead(button4)==LOW && digitalRead(button5)==LOW){
    delay(1);
    i++;
   }
    if (digitalRead(button5)==HIGH)
    {
     if(i<3000)
     {
      score++;
      delay(200);
      i=0;
      }
      else
      {
        delay(200);
        volte--;
      }
   }
   else{
        delay(200);
        volte--;
   }
  }
  if (volte == 0){
    lcd.clear();
    lcd.print("hai perso");
    delay(5000);
  }
 }

void loop() {
  // put your main code here, to run repeatedly: 
  //random
while(volte!=0){
randomSeed(analogRead(0));
tempo=random(1,6);//random da 1 a 5
programma();
}

}
