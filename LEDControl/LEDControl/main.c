#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include <queue.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

#define POT_PIN 26
#define LED_PIN 14

static QueueHandle_t xQueue = NULL;

void adc_task(void *pvParameters)
{
    uint16_t uIValueToSend = 0;
    adc_init();
    adc_gpio_init(POT_PIN);
    adc_select_input(0);

    while(true)
    {
        uIValueToSend = adc_read();
        uIValueToSend = (uIValueToSend - 0) * (255 - 0) / (4095 - 0) + 0;
        xQueueSend(xQueue, &uIValueToSend, 0U);
        vTaskDelay(10); //Allows pwm task execute (pwm lower priority)
    }
}

void pwm_task(void *pvParameters)
{   
    uint slice_num = pwm_gpio_to_slice_num(LED_PIN);
    uint16_t uIReceivedValue;

    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);

    pwm_set_wrap(slice_num, 255);
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 0);
    pwm_set_enabled(slice_num, true);

    while(true)
    {
        xQueueReceive(xQueue, &uIReceivedValue, portMAX_DELAY);
        pwm_set_chan_level(slice_num, PWM_CHAN_A, uIReceivedValue);
    }
}

int main()
{
    stdio_init_all();
        
    xQueue = xQueueCreate(1, sizeof(uint16_t));
    
    xTaskCreate(adc_task, "ADC_Task", 256, NULL, 2, NULL);
    xTaskCreate(pwm_task, "PWM_Task", 256, NULL, 1, NULL);
    vTaskStartScheduler();

    while(1){};
}
