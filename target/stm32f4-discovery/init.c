/*
 * Copyright (c) 2012 Travis Geiselbrecht
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT
 */
#include <lk/err.h>
#include <lk/debug.h>
#include <lk/trace.h>
#include <target.h>
#include <lk/compiler.h>
#include <dev/gpio.h>
#include <stm32f4xx_usart.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_gpio.h>
#include <platform/stm32.h>
#include <platform/gpio.h>
#include <target/debugconfig.h>
#include <target/gpioconfig.h>

void target_early_init(void) {
#ifdef DEBUG_UART
#if DEBUG_UART == 2
    gpio_config(GPIO_USART2_TX, GPIO_STM32_AF |
                GPIO_STM32_AFn(GPIO_AF_USART2) | GPIO_PULLUP);
    gpio_config(GPIO_USART2_RX, GPIO_STM32_AF |
                GPIO_STM32_AFn(GPIO_AF_USART2) | GPIO_PULLUP);
#endif // DEBUG_UART == 2
#else
#warn DEBUG_UART only supports USART2!!!
#endif // defined DEBUG_UART

    stm32_debug_early_init();

    /* configure some status leds */
    gpio_config(GPIO_LED2, GPIO_OUTPUT);
}

void target_init(void) {
    TRACE_ENTRY;

    stm32_debug_init();

    TRACE_EXIT;
}

void target_set_debug_led(unsigned int led, bool on) {
    switch (led) {
        case 0:
        case 1:
        case 2:
        case 3:
            gpio_set(GPIO_LED2, on);
            break;
    }
}
