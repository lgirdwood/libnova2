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
 *  Copyright (C) 2009 - 2026 Petr Kubanek
 */

#include <math.h>

#include <libnova/earth.h>
#include <libnova/heliocentric_time.h>
#include <libnova/nutation.h>
#include <libnova/utility.h>
double ln2_get_heliocentric_time_diff(double JD, struct ln_equ_posn *object) {
  double theta, ra, dec, c_dec, obliq;
  struct ln_nutation nutation;
  struct ln_helio_posn earth;

  ln2_get_nutation(JD, &nutation);
  ln2_get_earth_helio_coords(JD, &earth);

  /* add 180 degrees to the longitude in radians */
  theta = earth.L + M_PI;
  ra = object->ra;
  dec = object->dec;
  c_dec = cos(dec);
  obliq = nutation.ecliptic;

  /* L.Binnendijk Properties of Double Stars,
   * Philadelphia, University of Pennselvania Press, pp. 228-232, 1960 */
  return -0.0057755 * earth.R *
         (cos(theta) * cos(ra) * c_dec +
          sin(theta) * (sin(obliq) * sin(dec) + cos(obliq) * c_dec * sin(ra)));
}
