
/*
Teensy Arduino library.
    Copyright (C) 2010 David Busby Saiweb.co.uk

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
    Additional Terms as Per section 7

    Attribution:

    Redistribution/Reuse of this code is permitted under the GNU v3 license, as an additional term ALL code must carry the original Author(s) credit in comment form.
*/
#include "serial.h";
libSerial s(false);
#include "rgb_led.h";
libRGB rgb(12,15,14); //rgb(r,g,b) chnage pins to suit
#include "DateTime.h";
DateTimeClass
// The setup() method runs once, when the sketch starts

void setup() {                
  //serial baud rate setup must occur in setup()
  //s._setup(9600); //USB is always 12 Mbit/sec
}

/**
 * demo function fades red then green then blue
 * @var int d delay
 **/
int cPin = 0; //the current pin
void red_green_blue(int d){
  //using nextpin method to cycle
  int i = 0;
  do {
    cPin = rgb.nextPin(cPin);
    rgb.glow(cPin,0,d);
    rgb.dim(cPin,255,d);
    i++;
  } while( i < 3 );
  //manually cycle pins using fade in/out functions
  rgb.fadeinRed(d);
  rgb.fadeoutRed(d);
  rgb.fadeinGreen(d);
  rgb.fadeoutGreen(d);
  rgb.fadeinBlue(d);
  rgb.fadeoutBlue(d);
  
}
/**
 * program loop, I have noticed a delay on re-run
 * at a guess if running on +5v @ 16mhz delay = 1 / 16000 = 0.0625 ms
 **/
void loop(){
 /* Simple hello world serial write every 1 second */
 /*s.sWrite("Hello world");
 delay(1000);*/
 
 /* RGVB led interaction demos */
  //ON/OFF demos
  /*rgb.redON();
  delay(100);
  rgb.redOFF();
  delay(100);
  rgb.greenON();
  delay(100);
  rgb.greenOFF();
  delay(100);
  rgb.blueON();
  delay(100);
  rgb.blueOFF();
  delay(100);
  rgb.whiteON();
  delay(100);
  rgb.whiteOFF();
  delay(100);*/
  
  //fadein Demos
  /*rgb.fadeinRed(10);
  rgb.fadeoutRed(10);
  rgb.fadeinGreen(10);
  rgb.fadeoutGreen(10);
  rgb.fadeinBlue(10);
  rgb.fadeoutBlue(10);
  //see the function above this uses the switch pin method to cycle the colours
  red_green_blue(10);*/
  //rgb.redON();

}
