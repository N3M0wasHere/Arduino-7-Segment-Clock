#include<FastLED.h>
#define NUM_LEDS 28 //total LEDs in system
#define DATA_PIN 8 //data pin on arduino
#define LEDS_PER_SEGMENT 7 //leds per number segment
#define color1 Red //color

//setting time by digits hrs1,hrs2,mins1,mins2,secs
int secs = 0;
int mins1 = 0;
int mins2 = 0;
int hrs1 = 0;
int hrs2 = 0;

CRGB leds[NUM_LEDS];

void setup(){
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds,NUM_LEDS);  
  Serial.begin(9600);
}

void loop(){
clock();
seg1();
seg2();
seg3();
seg4();
}

void clock(){
while(!Serial);
Serial.println((String)hrs1+hrs2+":"+mins1+mins2+":"+secs);//clock function debug
  if(secs < 60){//seconds counter
    secs += 1;
    delay(1);
  }
  if(secs == 60){//convert 60 secs to 1 1st digit minute
    secs = 0;
    mins2 = mins2+1;
  }
  if(mins2 == 10){//convert 10 1st digit minutes to 1 2nd digit minute
    secs = 0;
    mins2 = 0;
    mins1 = mins1+1;
  }
  if(mins1 == 6){//convert 6 2nd digit minutes to 1 1st digit hour
    mins1 = 0;
    mins2 = 0;
    hrs2 = hrs2+1;
  }
  if(hrs2 == 10){
    hrs2 = 0;
    hrs1 = hrs1+1;  
  }
  if(hrs1 == 2 &&(hrs2 == 5)){
    hrs1 = 0;
    hrs2 = 0;
    mins1 = 0;
    mins2 = 0;  
  }
}  

void seg1(){//segment 1 = 1st digit of hour
int segadd = LEDS_PER_SEGMENT*0;
if(hrs1 == 0){  //show 0
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::Black;
  leds[segadd+4] = CRGB::color1;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(hrs1 == 1){  //show 1
  FastLED.clear();
  leds[segadd+0] = CRGB::Black;
  leds[segadd+1] = CRGB::Black;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::Black;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::Black;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(hrs1 == 2){   //show 2
  FastLED.clear();
  leds[segadd+0] = CRGB::Black;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::color1;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::Black;
  FastLED.show();
}  
}

void seg2(){//segment 2 = 2nd digit of hour
int segadd = LEDS_PER_SEGMENT*1;
if(hrs2 == 0){  //show 0
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::Black;
  leds[segadd+4] = CRGB::color1;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(hrs2 == 1){  //show 1
  FastLED.clear();
  leds[segadd+0] = CRGB::Black;
  leds[segadd+1] = CRGB::Black;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::Black;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::Black;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(hrs2 == 2){   //show 2
  FastLED.clear();
  leds[segadd+0] = CRGB::Black;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::color1;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::Black;
  FastLED.show();
}
if(hrs2 == 3){ //show 3
  FastLED.clear();
  leds[segadd+0] = CRGB::Black;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(hrs2 == 4){  //show 4
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::Black;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::Black;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(hrs2 == 5){  //show 5
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::Black;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(hrs2 == 6){  //show 6
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::Black;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::color1;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(hrs2 == 7){  //show 7
  FastLED.clear();
  leds[segadd+0] = CRGB::Black;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::Black;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::Black;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(hrs2 == 8){  //show 8 on segment 0
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::color1;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(hrs2 == 9){  //show 9 on segment 0
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
}

void seg3(){//segment 3 = 1st digit of minutes
int segadd = LEDS_PER_SEGMENT*2;
if(mins1 == 0){  //show0
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::Black;
  leds[segadd+4] = CRGB::color1;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(mins1 == 1){  //show 1
  FastLED.clear();
  leds[segadd+0] = CRGB::Black;
  leds[segadd+1] = CRGB::Black;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::Black;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::Black;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(mins1 == 2){   //show 2
  FastLED.clear();
  leds[segadd+0] = CRGB::Black;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::color1;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::Black;
  FastLED.show();
}
if(mins1 == 3){ //show 3
  FastLED.clear();
  leds[segadd+0] = CRGB::Black;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(mins1 == 4){  //show 4
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::Black;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::Black;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(mins1 == 5){  //show 5
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::Black;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(mins1 == 6){  //show 6
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::Black;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::color1;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
}

void seg4(){//segment 4 = 2nd digit of minutes
int segadd = LEDS_PER_SEGMENT*3;
if(mins2 == 0){  //show0
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::Black;
  leds[segadd+4] = CRGB::color1;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(mins2 == 1){  //show 1
  FastLED.clear();
  leds[segadd+0] = CRGB::Black;
  leds[segadd+1] = CRGB::Black;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::Black;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::Black;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(mins2 == 2){   //show 2
  FastLED.clear();
  leds[segadd+0] = CRGB::Black;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::color1;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::Black;
  FastLED.show();
}
if(mins2 == 3){ //show 3
  FastLED.clear();
  leds[segadd+0] = CRGB::Black;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(mins2 == 4){  //show 4
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::Black;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::Black;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(mins2 == 5){  //show 5
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::Black;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(mins2 == 6){  //show 6
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::Black;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::color1;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(mins2 == 7){  //show 7
  FastLED.clear();
  leds[segadd+0] = CRGB::Black;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::Black;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::Black;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(mins2 == 8){  //show 8 on segment 0
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::color1;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
if(mins2 == 9){  //show 9 on segment 0
  FastLED.clear();
  leds[segadd+0] = CRGB::color1;
  leds[segadd+1] = CRGB::color1;
  leds[segadd+2] = CRGB::color1;
  leds[segadd+3] = CRGB::color1;
  leds[segadd+4] = CRGB::Black;
  leds[segadd+5] = CRGB::color1;
  leds[segadd+6] = CRGB::color1;
  FastLED.show();
}
}
