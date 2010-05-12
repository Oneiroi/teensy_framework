
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

/**
 * redPin setter
 * @var int redPin
 **/
void rgb_led::_setredPin(int redPin){
  rgb_led::redPin = redPin;
}
/**
 * redPin getter
 * @return int
 **/
int rgb_led::_getredPin(){
  return rgb_led::redPin;
}
/**
 * greenPin setter
 * @var int redPin
 **/
void rgb_led::_setgreenPin(int greenPin){
  rgb_led::greenPin = greenPin;
}
/**
 * greenPin getter
 * @return int
 **/
int rgb_led::_getgreenPin(){
  return rgb_led::greenPin;
}
/**
 * bluePin setter
 * @var int redPin
 **/
void rgb_led::_setbluePin(int bluePin){
  rgb_led::bluePin = bluePin;
}
/**
 * bluePin getter
 * @return int
 **/
int rgb_led::_getbluePin(){
  return rgb_led::bluePin;
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
 * same as rgb_led::dim() only addresses all 3 pins at once
 * @int v the starting value (0-255)
 * @int d the delay in milliseconds
 **/
void rgb_led::dimRGB(int v, int d){
  //glow dimmer
  while(v > 0){
     analogWrite(rgb_led::redPin,v);
     analogWrite(rgb_led::greenPin,v);
     analogWrite(rgb_led::bluePin,v);
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
 * same as rgb_led::glow() only addresses all 3 pins at once
 * @int v the starting value (0-255)
 * @int d the delay in milliseconds
 **/
void rgb_led::glowRGB(int v, int d){
  //glow brighter
  while(v < 255){
     analogWrite(rgb_led::redPin,v);
     analogWrite(rgb_led::greenPin,v);
     analogWrite(rgb_led::bluePin,v);
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
 * @return int
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

/**
 * This function will set the Red,Green and blue values on the LED
 * @var int r red value (0-255)
 * @var int g green value (0-255)
 * @var int b blue value (0-255)
 **/
void rgb_led::rgb(int r, int g, int b){
    analogWrite(rgb_led::redPin,r);
    analogWrite(rgb_led::greenPin,g);
    analogWrite(rgb_led::bluePin,b);
}

/**
 * wrapper for rgb_led::glow() fades in red
 * @int d delay in milliseconds
 **/
void rgb_led::fadeinRed(int d){
  rgb_led::glow(rgb_led::redPin,0,d);
}
/**
 * wrapper for rgb_led::glow() fades in green
 * @int d delay in milliseconds
 **/
void rgb_led::fadeinGreen(int d){
  rgb_led::glow(rgb_led::greenPin,0,d);
}
/**
 * wrapper for rgb_led::glow() fades in blue
 * @int d delay in milliseconds
 **/
void rgb_led::fadeinBlue(int d){
  rgb_led::glow(rgb_led::bluePin,0,d);
}
/**
 * wrapper for rgb_led::glowRGB() fades in blue
 * @int d delay in milliseconds
 **/
void rgb_led::fadeinRGB(int d){
  rgb_led::glowRGB(0,d);
}
/**
 * wrapper for rgb_led::dim() fades out red
 * @int d delay in milliseconds
 **/
void rgb_led::fadeoutRed(int d){
  rgb_led::dim(rgb_led::redPin,255,d);
}
/**
 * wrapper for rgb_led::dim() fades out green
 * @int d delay in milliseconds
 **/
void rgb_led::fadeoutGreen(int d){
  rgb_led::dim(rgb_led::greenPin,255,d);
}
/**
 * wrapper for rgb_led::dim() fades out blue
 * @int d delay in milliseconds
 **/
void rgb_led::fadeoutBlue(int d){
  rgb_led::dim(rgb_led::bluePin,255,d);
}
/**
 * wrapper for rgb_led::dimRGB() fades out blue
 * @int d delay in milliseconds
 **/
void rgb_led::fadeoutRGB(int d){
  rgb_led::dimRGB(255,d);
}
