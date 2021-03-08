#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_NeoMatrix.h>
#include <gamma.h>
#include <Adafruit_NeoPixel.h>
#include<SoftwareSerial.h>

SoftwareSerial BT(10,11); //RX TX connect rx->11 tx->10
#ifndef PSTR 
#define PSTR 
#endif

#define PIN 6 //led strip pin number
#define mw 30 //led strip width
#define mh 7 // led strip height

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(mw, mh, PIN, NEO_MATRIX_ZIGZAG, NEO_GRB+ NEO_KHZ400); //define matrix constructs

const uint16_t color[] = {matrix.Color(255,255,255)}; //white
  
void setup(){
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  Serial.begin(38400);
  BT.begin(38400);
  Serial.println("!Aura Connected");
  
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(50);
  matrix.setTextColor(color[0]);
}

int x = matrix.width();

void loop(){
  if(BT.available()){ //reads value of data
    data = BT.read();
    Serial.print(F("ABCDE"));    
  }
  
  if(data == '*'){   //clears the text stored in data if * is typed
    data = ' ';
    Serial.println("!Cleared");
  }

  matrix.fillScreen(0);
  matrix.setCursor(x,0);
  matrix.print(data);
  if(--x < -50) {
    x = matrix.width();
    matrix.show();
  }
}
