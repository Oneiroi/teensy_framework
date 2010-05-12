
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
rgb_led rgb(12,15,14);

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
  cPin = rgb.nextPin(cPin);
  rgb.glow(cPin,0,d);
  rgb.dim(cPin,255,d);
}

/**
 * More invloved example function using the rgb method.
 * glows to bright white then to off, steps based on delay
 * @var int d delay
 **/
void whiteBeacon(int d){
  int i = 0;
  //get brighter
  while(i < 255){
    rgb.rgb(i,i,i);
    i++;
    delay(d);
    //this is here to break the loop at the right time
    //otherwise it will appear to flicker on chage
    if(i >= 255){
       break;
    }
   }
  //fade out
  while(i > 0){
     rgb.rgb(i,i,i);
     i--;
     delay(d);
     //this is here to break the loop at the right time
     //otherwise it will appear to flicker on chage
     if(i <= 0){
       break;
     }
  }
}

void loop(){
  red_green_blue(10);
  whiteBeacon(10);
}
