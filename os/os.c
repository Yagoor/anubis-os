#include "os.h"

#include "soc.h"
#include "clock.h"
#include "timer.h"
#include "gpio.h"
#include "led.h"
#include "watchdog.h"
#include "uart.h"
#include "usb.h"
#include "random.h"

static struct pt os_pt;

static void main_loop(void)
{
  PT_INIT(&os_pt);

  do
  {
    watchdog_kick();
  } while (PT_SCHEDULE(os_protothread(&os_pt)));
}


int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  /*
   * Initialize device's critical modules
   *
   * - The first has to the system on chip
   */
  soc_init();

  clock_init();

  timer_init();

  gpio_init();

  led_init();

  watchdog_init();

  /*
   * Initialize os's critical modules
   */


  /*
   * Initialize device's remaining modules
   */

  uart_init();

  usb_init();

  random_init();

  /*
   * Initialize os's remaining modules
   */

  /*
   * Start watch dog before main loop
   */
  watchdog_start();

  main_loop();

  return (0);
}
