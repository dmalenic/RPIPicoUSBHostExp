/**
 * Blink STATUS LED - Ported to Pimoroni Tiny 2040
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/gpio.h"

#define TINY2040_LED_R_PIN 18
#define TINY2040_LED_G_PIN 19
#define TINY2040_LED_B_PIN 20

#define DELAY 500 // in milliseconds

static void tiny2040_rgb_init(void) {
    gpio_init(TINY2040_LED_R_PIN);
    gpio_init(TINY2040_LED_G_PIN);
    gpio_init(TINY2040_LED_B_PIN);
    gpio_set_dir(TINY2040_LED_R_PIN, GPIO_OUT);
    gpio_set_dir(TINY2040_LED_G_PIN, GPIO_OUT);
    gpio_set_dir(TINY2040_LED_B_PIN, GPIO_OUT);
    // LEDs are active-low, turn them off
    gpio_put(TINY2040_LED_R_PIN, 1);
    gpio_put(TINY2040_LED_G_PIN, 1);
    gpio_put(TINY2040_LED_B_PIN, 1);
}

// Active-low: 0 = on, 1 = off
static void tiny2040_rgb_set(const bool red, const bool green, const bool blue) {
    gpio_put(TINY2040_LED_R_PIN, !red);
    gpio_put(TINY2040_LED_G_PIN, !green);
    gpio_put(TINY2040_LED_B_PIN, !blue);
}

__attribute__((noreturn))
int main() {
    stdio_init_all();
    tiny2040_rgb_init();
    bool blue = false;
    while (true) {
        tiny2040_rgb_set(false, false, false);
        sleep_us(200);
        int c = getchar_timeout_us(0);
        if (c <= 0) {
            tiny2040_rgb_set(true, false, false);
        } else {
            tiny2040_rgb_set(false, !blue, blue);
            while (c > 0) {
                c = getchar_timeout_us(1000);
            }
            blue = !blue;
        }
        printf("{\"on\":  true}\n");
        sleep_ms(DELAY);

        tiny2040_rgb_set(false, false, false);
        printf("{\"on\":  false}\n");
        sleep_ms(DELAY);
    }
}
