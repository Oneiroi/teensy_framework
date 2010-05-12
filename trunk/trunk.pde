
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

int cPin = 0;
void loop(){
  if(cPin == 0){
    cPin = rgb.nextPin(0);
  } else {
    cPin = rgb.nextPin(cPin);
  }
  rgb.glow(cPin,0,10);
  rgb.dim(cPin,255,10);
}
