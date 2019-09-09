// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      240

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
bool colorWheel = false;
int randomRed = 0;
int randomGreen = 0;
int randomBlue = 0;

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
  
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.setBrightness(255);
  pinMode(13, OUTPUT); //Output for LED_BUILTIN
  pinMode(12, INPUT); // Input for color switch
  pinMode(9, INPUT); // Mic input
  digitalWrite(13,HIGH);

  // Jordad color switch är satt till default low Sätter vi den high vid start får vi color wheel

  //colorWheel = digitalRead(12); // Colorwheel can't be changed during runtime
  
  
}

void loop(){
//  if (colorWheel){
//    if (digitalRead(9)){
//      randomRed = random(1,255);
//      randomGreen = random(1,255);
//      randomBlue = random(1,255);
//      for(int i=0;i<NUMPIXELS;i++){
//      pixels.setPixelColor(i,pixels.Color(randomRed,randomGreen,randomBlue));
//      }
//      pixels.show();
//      delay(100); // Replace with delayval
//      for(int i=0;i<NUMPIXELS;i++){
//        pixels.setPixelColor(i,pixels.Color(0,0,0));
//      }
//      pixels.show();
//    }
//
//    
//    
//  }else{ // Standard mode
    if (digitalRead(9)){
      
      if (digitalRead(12)){
        for(int i=0;i<NUMPIXELS;i++){
        pixels.setPixelColor(i,pixels.Color(230,0,0));
        }
        pixels.show();
        delay(90); // Replace with delayval
        for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i,pixels.Color(0,0,0));
        }
        pixels.show();
      }else{
        for(int i=0;i<NUMPIXELS;i++){
//        pixels.setPixelColor(i,pixels.Color(190,50,140));
          pixels.setPixelColor(i,pixels.Color(128,20,128)); 
        }
        pixels.show();
        delay(90); // Replace with delayval
        for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i,pixels.Color(0,0,0));
        }
        pixels.show();
      }
  
    }    
  
  

  



}
