
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
#include "rgb_led.h"
libRGB rgb(12,15,14);

// The setup() method runs once, when the sketch starts

void setup() {                
  //do something
}

/**
 * demo function fades red then green then blue
 * @var int d delay
 **/
int cPin = 0;
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
 * More invloved example function using the rgb method.
 * glows to bright white then to off, steps based on delay
 * @var int d delay
 **/
void whiteFade(int d){
  //fade in one colour at a time
  rgb.fadeinRed(d);
  rgb.fadeinGreen(d);
  rgb.fadeinBlue(d);
  //and out one colour at a timw
  rgb.fadeoutRed(d);
  rgb.fadeoutGreen(d);
  rgb.fadeoutBlue(d);
  //bring all three up
  rgb.fadeinRGB(d);
  rgb.fadeoutRGB(d);
}

/**
 * program loop, I have noticed a delay on re-run
 * at a guess if running on +5v @ 16mhz delay = 1 / 16000 = 0.0625 ms
 **/
void loop(){
  red_green_blue(10);
  whiteFade(10);
}
