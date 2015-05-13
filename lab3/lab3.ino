#include <SPI.h>
#define SS_PIN 10

#define SHIFT_TIME 250

int shiftTimer=0, shiftTimerPrev=0, shiftLength=0;

void setup() {
  pinMode(SS_PIN, OUTPUT);
  SPI.begin();
}

byte mas[]={

/*  	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
  0b00000000,
  0b00000000,*/
  0b00111101,
  0b01000010,
  0b10100101,
  0b10000001,
  0b10100101,
  0b10011001,
  0b01000010,
  0b00111100,
};



void loop(){
	shiftTimer=millis();
	if((shiftTimer-shiftTimerPrev)>=SHIFT_TIME){
		shiftLength++;
 		if(shiftLength>8)shiftLength=0;
 		shiftTimerPrev=shiftTimer;
 	}
	
  for(int i=0; i<8; i++){
    digitalWrite(SS_PIN, LOW);
    SPI.transfer(0xFF-(1<<i));
    SPI.transfer(mas[i-shiftLength]);
    digitalWrite(SS_PIN, HIGH);
    delay(2);
  }


}