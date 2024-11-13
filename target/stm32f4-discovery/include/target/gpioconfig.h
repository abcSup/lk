/*
 * Copyright (c) 2012 Travis Geiselbrecht
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT
 */
#ifndef __TARGET_GPIOCONFIG_H
#define __TARGET_GPIOCONFIG_H

#include <platform/gpio.h>

#define GPIO_USART2_TX GPIO(GPIO_PORT_A, 2)
#define GPIO_USART2_RX GPIO(GPIO_PORT_A, 3)

#define GPIO_LED2 GPIO(GPIO_PORT_A, 5) // LD2 - Green

#endif
