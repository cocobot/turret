#include <string.h>
#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>
#include <platform.h>
#include <mcual.h>
#include <cocobot.h>

#include <avr/io.h>


void blink(void * arg)
{
  (void)arg;
  unsigned int i = 0;
  while(1)
  {
    platform_led_toggle(1 << (i % 6));
    i += 1;

    vTaskDelay(75 / portTICK_RATE_MS);
  }
}

int console_handler(const char * cmd)
{
  (void)cmd;
  if(strcmp(cmd,"setled") == 0)
  {
    platform_led_set(1 << cocobot_console_get_iargument(0));
    return 1;
  }

  if(strcmp(cmd,"clrled") == 0)
  {
    platform_led_clear(1 << cocobot_console_get_iargument(0));
    return 1;
  }

  if(strcmp(cmd,"pwm") == 0)
  {
    platform_pwm_set(PLATFORM_PWM_M0, (0xffffL * cocobot_console_get_iargument(0)) / 100);
    return 1;
  }

  return 0;
} 

int main(void)
{
  platform_init();
  platform_pwm_init(PLATFORM_PWM_M0, 20000);

  cocobot_console_init(PLATFORM_USART_BAL1, 1, console_handler);
  xTaskCreate(blink, "blink", 400, NULL, 1, NULL );

  vTaskStartScheduler();

  return 0;
}
