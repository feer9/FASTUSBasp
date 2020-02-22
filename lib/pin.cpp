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

#include "pin.h"
/*
uint8_t pin::_getNativePinMode(PinMode pm)
{
  
  if (pm == PinMode::INPUT)
  {
    return GPIO_MODE_INPUT;
  }
  else if (pm == PinMode::OUTPUT)
  {
    return GPIO_MODE_OUTPUT;
  }
  else if (pm == PinMode::AF)
  {
    return GPIO_MODE_AF;
  }
  else if (pm == PinMode::ANALOG)
  {
    return GPIO_MODE_ANALOG;
  }

  return GPIO_MODE_INPUT;
}
*/
/*
uint8_t pin::_getNativePinConfig(PinConfig pc)
{
  if (pc == PinConfig::INPUT_ANALOG)
  {
    return 0;
  }
  else if (pc == PinConfig::INPUT_FLOAT)
  {
    return 1;
  }
  else if (pc == PinConfig::INPUT_PULLUPDOWN)
  {
    return 2;
  }
  else if (pc == PinConfig::OUTPUT_PUSHPULL)
  {
    return GPIO_PUPD_NONE;
  }
  else if (pc == PinConfig::OUTPUT_ALTFPUSHPULL)
  {
    return GPIO_PUPD_NONE;
  }
  else if (pc == PinConfig::OUTPUT_ALTFOPENDRAIN)
  {
    return 3;
  }

  return 0;
}
*/

pin::pin(volatile uint32_t pinBaseAddr, uint32_t port): _pinBaseAddr(pinBaseAddr), _port(port) {}

void pin::assign(volatile uint32_t pinBaseAddr, uint32_t port)
{
  _pinBaseAddr = pinBaseAddr;
  _port = port;
}

void pin::setMode(uint8_t mode, uint8_t pull_up_down)
{
  gpio_mode_setup(_port, mode, pull_up_down, _pinBaseAddr);
}

void pin::setOutputOptions(uint8_t otype, uint8_t speed)
{
  gpio_set_output_options(_port, otype, speed, _pinBaseAddr);
}

void pin::setAF(uint8_t alt_fun_num)
{
  gpio_set_af(_port, alt_fun_num, _pinBaseAddr);
}

void pin::on()
{
  gpio_set(_port, _pinBaseAddr);
}

void pin::off()
{
  gpio_clear(_port, _pinBaseAddr);
}

void pin::toggle()
{
  gpio_toggle(_port, _pinBaseAddr);
}

bool pin::get()
{
  return gpio_get(_port, _pinBaseAddr);
}
