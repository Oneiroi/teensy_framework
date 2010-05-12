
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
#include "WProgram.h"

/**
 * class construct sets up required vars / methods
 **/
rgb_led::rgb_led(int redPin, int greenPin, int bluePin){
  rgb_led::redPin = redPin;
  rgb_led::greenPin = greenPin;
  rgb_led::bluePin = bluePin;
  pinMode(rgb_led::redPin, OUTPUT);
  pinMode(rgb_led::greenPin, OUTPUT);
  pinMode(rgb_led::bluePin, OUTPUT); 
}

rgb_led::~rgb_led(){
  //do something 
}

void rgb_led::_setredPin(int redPin){
  rgb_led::redPin = redPin;
}
int rgb_led::_getredPin(){
  return rgb_led::redPin;
}
void rgb_led::_setgreenPin(int greenPin){
  rgb_led::greenPin = greenPin;
}
int rgb_led::_getgreenPin(){
  return rgb_led::greenPin;
}
void rgb_led::_setbluePin(int bluePin){
  rgb_led::bluePin = bluePin;
}
int rgb_led::_getbluePin(){
  return rgb_led::bluePin;
}
int rgb_led::_getDelay(){
  return rgb_led::d;
}
void rgb_led::_setDelay(int d){
  rgb_led::d = d;
}
/**
 * This function causes the LED to glow dimmer for the selected pin,
 * this can either be set at run time, or will default to the class global value.
 * @var int p the pin number
 * @int v the starting value (0-255)
 * @int d the delay in milliseconds
 **/
void rgb_led::dim(int p, int v, int d){
  //glow dimmer
  while(v > 0){
     analogWrite(p,v);
     v = v-1;
     delay(d);
     if(v <= 0){
       break;
     }
  }
}

/**
 * This function causes the LED to glow brighter for the selected pin,
 * this can either be set at run time, or will default to the class global value.
 * @var int p the pin number
 * @int v the starting value (0-255)
 * @int d the delay in milliseconds
 **/
void rgb_led::glow(int p, int v, int d){
  //glow brighter
  while(v < 255){
     analogWrite(p,v);
     v = v+1;
     delay(d);
     if(v >= 255){
       break;
     }
   }
}

/**
 * This function can be used to jump to the "next" pin
 * following this order: red -> green -> blue -> red ...
 **/
int rgb_led::nextPin(int cPin){
   //pin swap
    if(cPin == rgb_led::redPin){
      return rgb_led::greenPin;
    } else if(cPin == rgb_led::greenPin) {
      return rgb_led::bluePin;
    } else {
      return rgb_led::redPin; 
    }
}
