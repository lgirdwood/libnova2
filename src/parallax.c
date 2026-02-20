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
 *  Copyright (C) 2000 - 2026 Petr Kubanek
 */

#include <libnova/earth.h>
#include <libnova/parallax.h>
#include <libnova/sidereal_time.h>
#include <libnova/utility.h>
#include <math.h>

/* Equ 39.1, 39.2, 39.3 Pg 263 and 264
 */
void ln2_get_parallax(struct ln_equ_posn *object, double au_distance,
					 struct ln_lnlat_posn *observer, double height, double JD,
					 struct ln_equ_posn *parallax)
{
	double H;

	/* use radians for H */
	H = ln2_get_apparent_sidereal_time(JD) - (observer->lng - object->ra);
	H = ln2_range_radians(H);
	ln2_get_parallax_ha(object, au_distance, observer, height, H, parallax);
}
/* Equ 39.1, 39.2, 39.3 Pg 263 and 264
 */
void ln2_get_parallax_ha(struct ln_equ_posn *object, double au_distance,
						struct ln_lnlat_posn *observer, double height, double H,
						struct ln_equ_posn *parallax)
{
	double sin_pi, ro_sin, ro_cos, sin_H, cos_H, cos_dec;

	ln2_get_earth_centre_dist(height, observer->lat, &ro_sin, &ro_cos);
	sin_pi = sin(LN_D2R((8.794 / au_distance) / 3600.0)); // (39.1)

	/* hour angle is in radians */

	sin_H = sin(H);
	cos_H = cos(H);
	cos_dec = cos(object->dec);
	parallax->ra = atan2(-ro_cos * sin_pi * sin_H,
						 cos_dec - ro_cos * sin_pi * cos_H); // (39.2)
	parallax->ra = ln2_range_radians(parallax->ra);

	/* we use the rigorous method 39.3 but its calculation object + parallax
   * in one step for declination and we need the delta parallax only so need
   to subtract the object declination*/
	parallax->dec =
		atan2((sin(object->dec) - ro_sin * sin_pi) * cos(parallax->ra),
			  cos_dec - ro_cos * sin_pi * cos_H); // (39.3)
	parallax->dec -= object->dec;
}
