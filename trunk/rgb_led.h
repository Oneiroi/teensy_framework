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
#ifndef H_LIB_RGB
#define H_LIB_RGB
class libRGB {
   public:
      libRGB(int redPin, int greenPin, int bluePin);
      ~libRGB();
      void dim();
      int nextPin(int cPin);
      void dim(int p, int v, int d);
      void dimRGB(int v, int d);
      void glow(int p, int v, int d);
      void glowRGB(int v, int d);
      void _setredPin(int redPin);
      int _getredPin();
      void _setgreenPin(int greenPin);
      int _getgreenPin();
      void _setbluePin(int bluePin);
      int _getbluePin();
      void _setDelay(int d);
      int _getDelay();
      void rgb(int r, int g, int b);
      void fadeinRed(int d);
      void fadeinGreen(int d);
      void fadeinBlue(int d);
      void fadeinRGB(int d);
      void fadeoutRed(int d);
      void fadeoutGreen(int d);
      void fadeoutBlue(int d);
      void fadeoutRGB(int d);
      void redON();
      void redOFF();
      void greenON();
      void greenOFF();
      void blueON();
      void blueOFF();
      void whiteON();
      void whiteOFF();
      void morse(char* message);
      void strMorse(char* message);     
      //pin defaults
      int redPin;
      int greenPin;
      int bluePin;       
};
#endif
