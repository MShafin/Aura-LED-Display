#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_NeoMatrix.h>
#include <gamma.h>
#include <Adafruit_NeoPixel.h>
#include<SoftwareSerial.h>


SoftwareSerial AURA(10, 11);      //RX and TX
int nt, ct, c=0;              //nt-next time, ct-current time, c-counter
String DATA;                //DATA from bluetooth

#ifndef PSTR 
#define PSTR 
#endif

#define PIN 6 //led strip pin number
#define mw 30 //led strip width
#define mh 7 // led strip height

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(mw, mh, PIN, NEO_MATRIX_ZIGZAG, NEO_GRB+ NEO_KHZ400); //define matrix constructs

const uint16_t color[] = {matrix.Color(255,255,255)}; //white

void setup()
{
  AURA.begin(38400);
  Serial.begin(38400);
  Serial.println("!Aura Connected");

  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(50);
  matrix.setTextColor(color[0]);
}

int x = matrix.width();

void loop(){
  ct=micros();
  if(ct>=nt){
    nt=ct+100000;
    while (AURA.available()){
      DATA=AURA.readString();
      c=c+1;
      Serial.print(c);
      Serial.println(DATA);
    }
  }
  
if(DATA == '*'){   //clears the text stored in data if * is typed
    DATA = ' ';
    Serial.println("!Cleared");
  }
    
    matrix.fillScreen(0);
    matrix.setCursor(0,0);
    matrix.print(DATA);
    if(--x < -50) {
      x = matrix.width();
      matrix.show();
    }
}
