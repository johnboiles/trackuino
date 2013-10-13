/* trackuino copyright (C) 2010  EA5HAV Javi
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#if defined(__AVR_ATmega32U4__)

#include <avr/power.h>
#include <avr/signal.h>
#include <avr/sleep.h>
#include <Arduino.h>
#include "config.h"
#include "pin.h"
#include "power.h"

void disable_bod_and_sleep()
{
  /* Atmega32U4 Processors don't have the ability to disable BOD while sleeping.
   * The only BOD configuration is done in the BODLEVEL fuses (p.52)
   */
  sleep_mode();    // Go to sleep
}

void power_save()
{
  /* Enter power saving mode. SLEEP_MODE_IDLE is the least saving
   * mode, but it's the only one that will keep the UART running.
   * In addition, we need timer0 to keep track of time, timer 1
   * to drive the buzzer and timer2 to keep pwm output at its rest
   * voltage.
   */

  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_enable();
  power_adc_disable();
  power_spi_disable();
  power_twi_disable();

  pin_write(LED_PIN, DEBUG_PIN_ON);
  sleep_mode();    // Go to sleep
  pin_write(LED_PIN, DEBUG_PIN_OFF);
  
  sleep_disable();  // Resume after wake up
  power_all_enable();
}


#endif // #ifdef AVR
