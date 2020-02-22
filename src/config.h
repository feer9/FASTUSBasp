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

#ifndef _CONFIG_H
#define _CONFIG_H

extern "C"
{
  #include <libopencm3/stm32/rcc.h>
}

#define INBUILT_LED GPIO6
#define INBUILT_LED_PORT GPIOA
#define INBUILT_LED_RCC RCC_GPIOA

#define ISP_BUS SPI1
#define ISP_BUS_RCC RCC_SPI1

#define ISP_PORT_RCC RCC_GPIOB
#define ISP_PORT GPIOB
#define ISP_MOSI GPIO5
#define ISP_MISO GPIO4
#define ISP_SCK  GPIO3

#define ISP_RST_RCC RCC_GPIOB
#define ISP_RST_PORT GPIOB
#define ISP_RST GPIO8

//define this to 1, if blue pill has wrong pull up at USB D+ line
#define USBDPLUS_WRONG_PULLUP 0

#ifdef DEBUG
#include "serial.h"
extern serial s2;
#define dbg(msg)    s2.print(msg)
#define dbgln(msg)  s2.println(msg)
#define dbgnum(num) s2.printint(num)
#else
#define dbg(msg)
#define dbgln(msg)
#define dbgnum(num)
#endif

#endif
