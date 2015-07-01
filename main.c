#include <platform.h>
#include <mcual.h>

int main(void)
{
  platform_init();

  while(1) 
  {
    platform_led_toggle(0xffffffff);
    volatile uint32_t tempo;
    for(tempo = 0; tempo < 10000; tempo += 1);
  }

  return 0;
}
