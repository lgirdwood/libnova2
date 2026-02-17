/*
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *  Copyright (C) 2000 - 2005 Liam Girdwood <lgirdwood@gmail.com>
 */

#include <libnova/proper_motion.h>
#include <libnova/utility.h>

/*
** Proper Motion.
*/
/* Example 20.b pg 126
 */
void ln_get_equ_pm(struct ln_equ_posn *mean_position,
                   struct ln_equ_posn *proper_motion, double JD,
                   struct ln_equ_posn *position) {
  ln_get_equ_pm_epoch(mean_position, proper_motion, JD, JD2000, position);
}
/* Example 20.b, pg 126
 */
void ln_get_equ_pm_epoch(struct ln_equ_posn *mean_position,
                         struct ln_equ_posn *proper_motion, double JD,
                         double epoch_JD, struct ln_equ_posn *position) {
  long double T;
  long double ra, dec;

  /* time delta in years*/
  T = (JD - epoch_JD) / 365.25;

  /* calc proper motion */
  /* Equ 20.1 */
  ra = mean_position->ra + T * proper_motion->ra;
  dec = mean_position->dec + T * proper_motion->dec;

  position->ra = ln_range_radians(ra);
  position->dec = dec;
}
