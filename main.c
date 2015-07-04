#include <FreeRTOS.h>
#include <task.h>
#include <platform.h>
#include <mcual.h>

void s(char * str)
{
  while(*str)
  {
    mcual_usart_send(PLATFORM_USART_BAL1, *str);
    str += 1;
  }
}

void blink(void * arg)
{
  (void)arg;
  int i = 0;
  while(1)
  {
    platform_led_toggle(1 << (i % 6));
    i += 1;

    vTaskDelay(75 / portTICK_RATE_MS);
  }
}

int main(void)
{
  platform_init();

  xTaskCreate(blink, "blink", 400, NULL, 1, NULL );

  vTaskStartScheduler();

  return 0;
}
