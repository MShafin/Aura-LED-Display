// PROGRAM BLUETOOTH BLE HM-10
// https://www.sunfounder.com/wiki/index.php?title=Bluetooth_4.0_HM-10_Master_Slave_Module


#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>


SoftwareSerial BT(10,11);  // TX, RX of the Bluetooth Module 

#define PIXEL_PIN      6    // Data Pin of Led strip 
#define PIXEL_COUNT    300   // Number of LEDs in the strip
#define BRIGHTNESS     255    // use 96 for medium brightness
#define SPEED          50    // Speed of each Color Transition (in ms)
#define IMMEDIATELY    0    // Transition happen instantly
#define RAINBOW_SPEED  50    // Rainbow Transition speed


Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

bool offOld = LOW;
bool WhiteOld = LOW;
bool RedOld = LOW;
bool GreenOld = LOW;
bool BlueOld = LOW;
bool TopazOld = LOW;
bool LilacOld = LOW;
bool RainbowOld = LOW;
bool rgbOld = LOW;
int  showType = 0;


void setup() {
   BT.begin(9600);
   BT.println("!Connected to AURA");
   Serial.print("Connected to AURA");
  strip.setBrightness(BRIGHTNESS);  
  strip.begin();
  strip.show();
}
char a;

void loop() {
  bool off = LOW;
  bool White = LOW;
  bool Blue = LOW;
  bool Red = LOW;
  bool Green = LOW;
  bool Topaz = LOW;
  bool Lilac = LOW;
  bool Rainbow = LOW;
  bool rgb = LOW;
  bool ende;
   if (BT.available()){
    a= (char)BT.read();
    
// ===========================================================================================
    if(a=='o')
    {
      off = HIGH;
          BT.println("TURNING OFF LEDs..");

    }else{
          off = LOW;
    }
// ===========================================================================================
    if(a=='w')
    {
      White = HIGH;
          BT.println("TURNING LEDs WHITE");

    }else{
          White = LOW;
    }
// ===========================================================================================
    if(a=='b')
    {
      Blue = HIGH;
          BT.println("CHANGING TO BLUE");      
          
    }else{
          Blue = LOW;  
    }
// ===========================================================================================
    if(a=='r')
        {
          Red = HIGH;
              BT.println("CHANGING TO RED");            
        }else{
              Red = LOW;  
        }
// ===========================================================================================
    if(a=='g')
        {
          Green = HIGH;
              BT.println("CHANGING TO GREEN");      
              
        }else{
              Green = LOW;
        }
// ===========================================================================================
    if(a=='t')
        {
          Topaz = HIGH;
              BT.println("CHANGING TO TOPAZ");      
              
        }else{
              Topaz = LOW;
        }
// ===========================================================================================
    if(a=='l')
        {
          Lilac = HIGH;
              BT.println("CHANGING TO LILAC");      
              
        }else{
              Lilac = LOW;
        }
// ===========================================================================================
    if(a=='a')
    {
      Rainbow = HIGH;
          BT.println("RAINBOW ANIMATION");      
          
    }else{
          Rainbow = LOW;  
    }
// ===========================================================================================
     if(a=='m')
    {
      rgb = HIGH;
          BT.println("MIX COLORS");      
          
    }else{
          rgb = LOW;  
    }
}
// ===========================================================================================
  if (off == LOW && offOld == HIGH) {
    delay(20);
   
    
    if (off == LOW) {
       showType = 0  ;                            // Off animation Type 0
     
      startShow(showType);
    }
  }
// ===========================================================================================
  if (White == LOW && WhiteOld == HIGH) {
      delay(20);
     
      
      if (White == LOW) {
         showType = 1  ;                            // White animation Type 1
       
        startShow(showType);
      }
    }
// ===========================================================================================  
  if (Red == LOW && RedOld == HIGH) {
    delay(20);
   
    
    if (Red == LOW) {
       showType = 2  ;                            // Red animation Type 2
     
      startShow(showType);
    }
  }
// ===========================================================================================
  if (Green == LOW && GreenOld == HIGH) {
      delay(20);
     
      
      if (Green == LOW) {
         showType = 3  ;                            // Green animation Type 3
       
        startShow(showType);
      }
    }
// ===========================================================================================
  if (Blue == LOW && BlueOld == HIGH) {
      delay(20);
     
      
      if (Blue == LOW) {
         showType = 4  ;                            // Blue animation Type 4
       
        startShow(showType);
      }
    }
// ===========================================================================================
  if (Topaz == LOW && TopazOld == HIGH) {
      delay(20);
     
      
      if (Topaz == LOW) {
         showType = 5  ;                            // Topaz animation Type 5
       
        startShow(showType);
      }
    }
// ===========================================================================================
  if (Lilac == LOW && LilacOld == HIGH) {
      delay(20);
     
      
      if (Lilac == LOW) {
         showType = 6  ;                            // Topaz animation Type 6
       
        startShow(showType);
      }
    }    
// ===========================================================================================
    if (Rainbow == LOW && RainbowOld == HIGH) {
    delay(20);

    if (Rainbow == LOW) {
      showType = 8;   // Rainbow animation Type 8
      startShow(showType);
    }
  }
// ===========================================================================================
      if (rgb == LOW && rgbOld == HIGH) {
    delay(20);

    if (rgb == LOW) {
   showType = 7;                            // Mix animation Type 7
     rgb = HIGH;

      startShow(showType);
    }
  }
// ===========================================================================================
// ===========================================================================================
WhiteOld = White;
RedOld = Red;
BlueOld = Blue;
GreenOld = Green;
TopazOld = Topaz;
LilacOld = Lilac;
offOld = off;
RainbowOld = Rainbow;
rgbOld = rgb;
}

void startShow(int i) {
  switch(i){

    case 0: colorWipe(strip.Color(0, 0, 0), SPEED);    // Black/off
            break;

    case 1: strip.setBrightness(255);                            // Changes the Brightness to MAX
            colorWipe(strip.Color(255, 255, 255), IMMEDIATELY);  // White
            strip.setBrightness(BRIGHTNESS);                     // Reset the Brightness to Default value
            break;  

    case 2: colorWipe(strip.Color(255, 0, 0), SPEED);  // Red
            break;

    case 3: colorWipe(strip.Color(0, 255, 0), SPEED);  // Green
            break;

    case 4: colorWipe(strip.Color(0, 0, 255), SPEED);  // Blue
            break;

    case 5: colorWipe(strip.Color(0, 250, 255), SPEED);  // Topaz
            break;            

    case 6: colorWipe(strip.Color(221, 130, 255), SPEED);  // Lilac
            break;            
    
    case 7: colorWipe(strip.Color(255, 0, 0), SPEED);  // Red
            colorWipe(strip.Color(0, 255, 0), SPEED);  // Green
            colorWipe(strip.Color(0, 0, 255), SPEED);  // Blue
            theaterChase(strip.Color(  0,   0, 127), SPEED); // Blue
            theaterChase(strip.Color(127,   0,   0), SPEED); // Red
            theaterChase(strip.Color(0,   127,   0), SPEED); // Green
            break;

    case 8: rainbowCycle(25);
            break;
  }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*10; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
