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
libRGB::libRGB(int redPin, int greenPin, int bluePin){
  libRGB::redPin = redPin;
  libRGB::greenPin = greenPin;
  libRGB::bluePin = bluePin;
  pinMode(libRGB::redPin, OUTPUT);
  pinMode(libRGB::greenPin, OUTPUT);
  pinMode(libRGB::bluePin, OUTPUT); 
}

libRGB::~libRGB(){
  //do something 
}

/**
 * redPin setter
 * @var int redPin
 **/
void libRGB::_setredPin(int redPin){
  libRGB::redPin = redPin;
}
/**
 * redPin getter
 * @return int
 **/
int libRGB::_getredPin(){
  return libRGB::redPin;
}
/**
 * greenPin setter
 * @var int redPin
 **/
void libRGB::_setgreenPin(int greenPin){
  libRGB::greenPin = greenPin;
}
/**
 * greenPin getter
 * @return int
 **/
int libRGB::_getgreenPin(){
  return libRGB::greenPin;
}
/**
 * bluePin setter
 * @var int redPin
 **/
void libRGB::_setbluePin(int bluePin){
  libRGB::bluePin = bluePin;
}
/**
 * bluePin getter
 * @return int
 **/
int libRGB::_getbluePin(){
  return libRGB::bluePin;
}
/**
 * This function causes the LED to glow dimmer for the selected pin,
 * this can either be set at run time, or will default to the class global value.
 * @var int p the pin number
 * @int v the starting value (0-255)
 * @int d the delay in milliseconds
 **/
void libRGB::dim(int p, int v, int d){
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
 * same as libRGB::dim() only addresses all 3 pins at once
 * @int v the starting value (0-255)
 * @int d the delay in milliseconds
 **/
void libRGB::dimRGB(int v, int d){
  //glow dimmer
  while(v > 0){
     analogWrite(libRGB::redPin,v);
     analogWrite(libRGB::greenPin,v);
     analogWrite(libRGB::bluePin,v);
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
void libRGB::glow(int p, int v, int d){
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
 * same as libRGB::glow() only addresses all 3 pins at once
 * @int v the starting value (0-255)
 * @int d the delay in milliseconds
 **/
void libRGB::glowRGB(int v, int d){
  //glow brighter
  while(v < 255){
     analogWrite(libRGB::redPin,v);
     analogWrite(libRGB::greenPin,v);
     analogWrite(libRGB::bluePin,v);
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
int libRGB::nextPin(int cPin){
   //pin swap
    if(cPin == libRGB::redPin){
      return libRGB::greenPin;
    } else if(cPin == libRGB::greenPin) {
      return libRGB::bluePin;
    } else {
      return libRGB::redPin; 
    }
}

/**
 * This function will set the Red,Green and blue values on the LED
 * @var int r red value (0-255)
 * @var int g green value (0-255)
 * @var int b blue value (0-255)
 **/
void libRGB::rgb(int r, int g, int b){
    analogWrite(libRGB::redPin,r);
    analogWrite(libRGB::greenPin,g);
    analogWrite(libRGB::bluePin,b);
}

/**
 * wrapper for libRGB::glow() fades in red
 * @int d delay in milliseconds
 **/
void libRGB::fadeinRed(int d){
  libRGB::glow(libRGB::redPin,0,d);
}
/**
 * wrapper for libRGB::glow() fades in green
 * @int d delay in milliseconds
 **/
void libRGB::fadeinGreen(int d){
  libRGB::glow(libRGB::greenPin,0,d);
}
/**
 * wrapper for libRGB::glow() fades in blue
 * @int d delay in milliseconds
 **/
void libRGB::fadeinBlue(int d){
  libRGB::glow(libRGB::bluePin,0,d);
}
/**
 * wrapper for libRGB::glowRGB() fades in blue
 * @int d delay in milliseconds
 **/
void libRGB::fadeinRGB(int d){
  libRGB::glowRGB(0,d);
}
/**
 * wrapper for libRGB::dim() fades out red
 * @int d delay in milliseconds
 **/
void libRGB::fadeoutRed(int d){
  libRGB::dim(libRGB::redPin,255,d);
}
/**
 * wrapper for libRGB::dim() fades out green
 * @int d delay in milliseconds
 **/
void libRGB::fadeoutGreen(int d){
  libRGB::dim(libRGB::greenPin,255,d);
}
/**
 * wrapper for libRGB::dim() fades out blue
 * @int d delay in milliseconds
 **/
void libRGB::fadeoutBlue(int d){
  libRGB::dim(libRGB::bluePin,255,d);
}
/**
 * wrapper for libRGB::dimRGB() fades out blue
 * @int d delay in milliseconds
 **/
void libRGB::fadeoutRGB(int d){
  libRGB::dimRGB(255,d);
}
