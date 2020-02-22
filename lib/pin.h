/*
 * FASTUSBasp v2 - Fastest programmer for AVR
 * Copyright (C) 2018  Amitesh Singh <singh.amitesh@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _PIN_H
#define _PIN_H

extern "C"
{
  #include <libopencm3/stm32/gpio.h>
}
/*
enum class PinMode
{
  INPUT,
  OUTPUT,
  AF,
  ANALOG
};

enum class PinConfig
{
  INPUT_ANALOG,
  INPUT_FLOAT,
  INPUT_PULLUPDOWN,
  OUTPUT_PUSHPULL,
  OUTPUT_OPENDRAIN,
  OUTPUT_ALTFPUSHPULL,
  OUTPUT_ALTFOPENDRAIN
};
*/

class pin
{
  volatile uint32_t _pinBaseAddr;
  uint32_t _port;

//  uint8_t _getNativePinMode(PinMode pm);

//  uint8_t _getNativePinConfig(PinConfig pc);

public:
  pin(volatile uint32_t pinBaseAddr, uint32_t port);
  pin() {}

  
  void assign(volatile uint32_t pinBaseAddr, uint32_t port);
  void setMode(uint8_t mode, uint8_t pull_up_down);
  void setAF(uint8_t alt_fun_num);
  void setOutputOptions(uint8_t otype, uint8_t speed);
  void on();
  void off();
  void toggle();
  bool get();
};

#endif