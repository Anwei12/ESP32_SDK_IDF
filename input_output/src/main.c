#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_wifi.h"
#include "esp_system.h"
//#include "driver/gpio.h"

void app_main(void)
{
    gpio_pad_select_gpio(GPIO_NUM_15);
    gpio_pad_select_gpio(GPIO_NUM_12);
    gpio_set_direction(GPIO_NUM_15, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_12, GPIO_MODE_INPUT);
    gpio_set_pull_mode(GPIO_NUM_12, GPIO_PULLUP_ONLY);
    int level = 0;

    while (true) {
      if(gpio_get_level(GPIO_NUM_12)==0){
        printf("Hello, world.\n");
        gpio_set_level(GPIO_NUM_15, level);
        level = !level;
        vTaskDelay(500 / portTICK_PERIOD_MS);
      }

    }
}
