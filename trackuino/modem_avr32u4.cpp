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

#include "afsk_avr32u4.h"
#include <avr/interrupt.h>

// This is the timer 2 interrupt service routine (ISR). Multiple
// modems can be operated from here.
#if AFSK_USE_TIMER1

ISR(TIMER1_OVF_vect)
{
  // Call modem ISRs:
  afsk_isr();
}

#endif

#if AFSK_USE_TIMER4

ISR(TIMER4_OVF_vect)
{
  // Call modem ISRs:
  afsk_isr();
}

#endif

#endif
