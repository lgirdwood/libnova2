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
 *  Copyright (C) 2000 - 2026 Liam Girdwood <lgirdwood@gmail.com>
 */

#include <libnova2/nutation.h>
#include <libnova2/sidereal_time.h>
#include <libnova2/utility.h>
#include <math.h>

/* Formula 11.1, 11.4 pg 83
 */
double ln2_get_mean_sidereal_time(double JD)
{
	long double sidereal;
	long double T;

	T = (JD - 2451545.0) / 36525.0;

	/* calc mean angle in degrees */
	sidereal = 280.46061837 + (360.98564736629 * (JD - 2451545.0)) +
	           (0.000387933 * T * T) - (T * T * T / 38710000.0);

	/* add a convenient multiple of 360 degrees */
	sidereal = ln2_range_degrees(sidereal);

	/* change to radians */
	sidereal = LN_D2R(sidereal);

	return sidereal;
}

/* Formula 11.1, 11.4 pg 83
 */

double ln2_get_apparent_sidereal_time(double JD)
{
	double correction, sidereal;
	struct ln_nutation nutation;

	/* get the mean sidereal time */
	sidereal = ln2_get_mean_sidereal_time(JD);

	/* add corrections for nutation in longitude and for the true obliquity of
  the ecliptic */
	ln2_get_nutation(JD, &nutation);

	/* nutation is in radians */
	correction = (nutation.longitude * cos(nutation.obliquity));

	sidereal += correction;

	return sidereal;
}
