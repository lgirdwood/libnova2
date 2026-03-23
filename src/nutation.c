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

#include <libnova2/dynamical_time.h>
#include <libnova2/nutation.h>
#include <libnova2/utility.h>
#include <math.h>
#include <stdio.h>

#define TERMS 63
#define LN_NUTATION_EPOCH_THRESHOLD 0.1

struct nutation_arguments {
	double D;
	double M;
	double MM;
	double F;
	double O;
};

struct nutation_coefficients {
	double longitude1;
	double longitude2;
	double obliquity1;
	double obliquity2;
};

/* arguments and coefficients taken from table 21A on page 133 */

const static struct nutation_arguments arguments[TERMS] = {
	{ 0.0, 0.0, 0.0, 0.0, 1.0 },   { -2.0, 0.0, 0.0, 2.0, 2.0 },
	{ 0.0, 0.0, 0.0, 2.0, 2.0 },   { 0.0, 0.0, 0.0, 0.0, 2.0 },
	{ 0.0, 1.0, 0.0, 0.0, 0.0 },   { 0.0, 0.0, 1.0, 0.0, 0.0 },
	{ -2.0, 1.0, 0.0, 2.0, 2.0 },  { 0.0, 0.0, 0.0, 2.0, 1.0 },
	{ 0.0, 0.0, 1.0, 2.0, 2.0 },   { -2.0, -1.0, 0.0, 2.0, 2.0 },
	{ -2.0, 0.0, 1.0, 0.0, 0.0 },  { -2.0, 0.0, 0.0, 2.0, 1.0 },
	{ 0.0, 0.0, -1.0, 2.0, 2.0 },  { 2.0, 0.0, 0.0, 0.0, 0.0 },
	{ 0.0, 0.0, 1.0, 0.0, 1.0 },   { 2.0, 0.0, -1.0, 2.0, 2.0 },
	{ 0.0, 0.0, -1.0, 0.0, 1.0 },  { 0.0, 0.0, 1.0, 2.0, 1.0 },
	{ -2.0, 0.0, 2.0, 0.0, 0.0 },  { 0.0, 0.0, -2.0, 2.0, 1.0 },
	{ 2.0, 0.0, 0.0, 2.0, 2.0 },   { 0.0, 0.0, 2.0, 2.0, 2.0 },
	{ 0.0, 0.0, 2.0, 0.0, 0.0 },   { -2.0, 0.0, 1.0, 2.0, 2.0 },
	{ 0.0, 0.0, 0.0, 2.0, 0.0 },   { -2.0, 0.0, 0.0, 2.0, 0.0 },
	{ 0.0, 0.0, -1.0, 2.0, 1.0 },  { 0.0, 2.0, 0.0, 0.0, 0.0 },
	{ 2.0, 0.0, -1.0, 0.0, 1.0 },  { -2.0, 2.0, 0.0, 2.0, 2.0 },
	{ 0.0, 1.0, 0.0, 0.0, 1.0 },   { -2.0, 0.0, 1.0, 0.0, 1.0 },
	{ 0.0, -1.0, 0.0, 0.0, 1.0 },  { 0.0, 0.0, 2.0, -2.0, 0.0 },
	{ 2.0, 0.0, -1.0, 2.0, 1.0 },  { 2.0, 0.0, 1.0, 2.0, 2.0 },
	{ 0.0, 1.0, 0.0, 2.0, 2.0 },   { -2.0, 1.0, 1.0, 0.0, 0.0 },
	{ 0.0, -1.0, 0.0, 2.0, 2.0 },  { 2.0, 0.0, 0.0, 2.0, 1.0 },
	{ 2.0, 0.0, 1.0, 0.0, 0.0 },   { -2.0, 0.0, 2.0, 2.0, 2.0 },
	{ -2.0, 0.0, 1.0, 2.0, 1.0 },  { 2.0, 0.0, -2.0, 0.0, 1.0 },
	{ 2.0, 0.0, 0.0, 0.0, 1.0 },   { 0.0, -1.0, 1.0, 0.0, 0.0 },
	{ -2.0, -1.0, 0.0, 2.0, 1.0 }, { -2.0, 0.0, 0.0, 0.0, 1.0 },
	{ 0.0, 0.0, 2.0, 2.0, 1.0 },   { -2.0, 0.0, 2.0, 0.0, 1.0 },
	{ -2.0, 1.0, 0.0, 2.0, 1.0 },  { 0.0, 0.0, 1.0, -2.0, 0.0 },
	{ -1.0, 0.0, 1.0, 0.0, 0.0 },  { -2.0, 1.0, 0.0, 0.0, 0.0 },
	{ 1.0, 0.0, 0.0, 0.0, 0.0 },   { 0.0, 0.0, 1.0, 2.0, 0.0 },
	{ 0.0, 0.0, -2.0, 2.0, 2.0 },  { -1.0, -1.0, 1.0, 0.0, 0.0 },
	{ 0.0, 1.0, 1.0, 0.0, 0.0 },   { 0.0, -1.0, 1.0, 2.0, 2.0 },
	{ 2.0, -1.0, -1.0, 2.0, 2.0 }, { 0.0, 0.0, 3.0, 2.0, 2.0 },
	{ 2.0, -1.0, 0.0, 2.0, 2.0 }
};

const static struct nutation_coefficients coefficients[TERMS] = {
	{ -171996.0, -174.2, 92025.0, 8.9 },
	{ -13187.0, -1.6, 5736.0, -3.1 },
	{ -2274.0, -0.2, 977.0, -0.5 },
	{ 2062.0, 0.2, -895.0, 0.5 },
	{ 1426.0, -3.4, 54.0, -0.1 },
	{ 712.0, 0.1, -7.0, 0.0 },
	{ -517.0, 1.2, 224.0, -0.6 },
	{ -386.0, -0.4, 200.0, 0.0 },
	{ -301.0, 0.0, 129.0, -0.1 },
	{ 217.0, -0.5, -95.0, 0.3 },
	{ -158.0, 0.0, 0.0, 0.0 },
	{ 129.0, 0.1, -70.0, 0.0 },
	{ 123.0, 0.0, -53.0, 0.0 },
	{ 63.0, 0.0, 0.0, 0.0 },
	{ 63.0, 0.1, -33.0, 0.0 },
	{ -59.0, 0.0, 26.0, 0.0 },
	{ -58.0, -0.1, 32.0, 0.0 },
	{ -51.0, 0.0, 27.0, 0.0 },
	{ 48.0, 0.0, 0.0, 0.0 },
	{ 46.0, 0.0, -24.0, 0.0 },
	{ -38.0, 0.0, 16.0, 0.0 },
	{ -31.0, 0.0, 13.0, 0.0 },
	{ 29.0, 0.0, 0.0, 0.0 },
	{ 29.0, 0.0, -12.0, 0.0 },
	{ 26.0, 0.0, 0.0, 0.0 },
	{ -22.0, 0.0, 0.0, 0.0 },
	{ 21.0, 0.0, -10.0, 0.0 },
	{ 17.0, -0.1, 0.0, 0.0 },
	{ 16.0, 0.0, -8.0, 0.0 },
	{ -16.0, 0.1, 7.0, 0.0 },
	{ -15.0, 0.0, 9.0, 0.0 },
	{ -13.0, 0.0, 7.0, 0.0 },
	{ -12.0, 0.0, 6.0, 0.0 },
	{ 11.0, 0.0, 0.0, 0.0 },
	{ -10.0, 0.0, 5.0, 0.0 },
	{ -8.0, 0.0, 3.0, 0.0 },
	{ 7.0, 0.0, -3.0, 0.0 },
	{ -7.0, 0.0, 0.0, 0.0 },
	{ -7.0, 0.0, 3.0, 0.0 },
	{ -7.0, 0.0, 3.0, 0.0 },
	{ 6.0, 0.0, 0.0, 0.0 },
	{ 6.0, 0.0, -3.0, 0.0 },
	{ 6.0, 0.0, -3.0, 0.0 },
	{ -6.0, 0.0, 3.0, 0.0 },
	{ -6.0, 0.0, 3.0, 0.0 },
	{ 5.0, 0.0, 0.0, 0.0 },
	{ -5.0, 0.0, 3.0, 0.0 },
	{ -5.0, 0.0, 3.0, 0.0 },
	{ -5.0, 0.0, 3.0, 0.0 },
	{ 4.0, 0.0, 0.0, 0.0 },
	{ 4.0, 0.0, 0.0, 0.0 },
	{ 4.0, 0.0, 0.0, 0.0 },
	{ -4.0, 0.0, 0.0, 0.0 },
	{ -4.0, 0.0, 0.0, 0.0 },
	{ -4.0, 0.0, 0.0, 0.0 },
	{ 3.0, 0.0, 0.0, 0.0 },
	{ -3.0, 0.0, 0.0, 0.0 },
	{ -3.0, 0.0, 0.0, 0.0 },
	{ -3.0, 0.0, 0.0, 0.0 },
	{ -3.0, 0.0, 0.0, 0.0 },
	{ -3.0, 0.0, 0.0, 0.0 },
	{ -3.0, 0.0, 0.0, 0.0 },
	{ -3.0, 0.0, 0.0, 0.0 }
};

/* cache values */
static long double c_JD = 0.0, c_longitude = 0.0, c_obliquity = 0.0,
                   c_ecliptic = 0.0;

/* Chapter 21 pg 131-134 Using Table 21A
 */
/* TODO: add argument to specify this */
/* TODO: use JD or JDE. confirm */
void ln2_get_nutation(double JD, struct ln_nutation *nutation)
{
	long double D, M, MM, F, O, T, T2, T3, JDE;
	long double coeff_sine, coeff_cos;
	long double argument;
	int i;

	/* should we bother recalculating nutation */
	if (fabs(JD - c_JD) > LN_NUTATION_EPOCH_THRESHOLD) {
		/* set the new epoch */
		c_JD = JD;
		c_longitude = 0;
		c_obliquity = 0;

		/* get julian ephemeris day */
		JDE = (long double)ln2_get_jde(JD);

		/* calc T */
		T = (JDE - 2451545.0) / 36525.0;
		T2 = T * T;
		T3 = T2 * T;

		/* calculate D,M,M',F and Omega - all in degrees */
		D = 297.85036 + 445267.111480 * T - 0.0019142 * T2 + T3 / 189474.0;
		M = 357.52772 + 35999.050340 * T - 0.0001603 * T2 - T3 / 300000.0;
		MM = 134.96298 + 477198.867398 * T + 0.0086972 * T2 + T3 / 56250.0;
		F = 93.2719100 + 483202.017538 * T - 0.0036825 * T2 + T3 / 327270.0;
		O = 125.04452 - 1934.136261 * T + 0.0020708 * T2 + T3 / 450000.0;

		/* calc sum of terms in table 21A */
		for (i = 0; i < TERMS; i++) {
			/* calc coefficients of sine and cosine */
			coeff_sine = (coefficients[i].longitude1 +
			              (coefficients[i].longitude2 * T)) /
			             (10000.0 * 60.0 * 360.0);
			coeff_cos = (coefficients[i].obliquity1 +
			             (coefficients[i].obliquity2 * T)) /
			            (10000.0 * 60.0 * 360.0);

			argument = arguments[i].D * D + arguments[i].M * M +
			           arguments[i].MM * MM + arguments[i].F * F +
			           arguments[i].O * O;
			argument = LN_D2R(argument);

			c_longitude += coeff_sine * sinl(argument);
			c_obliquity += coeff_cos * cosl(argument);
		}

		/* calculate mean ecliptic - Meeus 2nd edition, eq. 22.2 */
		c_ecliptic = 23.0 + 26.0 / 60.0 + 21.448 / (60.0 * 360.0) -
		             46.8150 / (60.0 * 360.0) * T -
		             0.00059 / (60.0 * 360.0) * T2 +
		             0.001813 / (60.0 * 360.0) * T3;

		/* c_ecliptic += c_obliquity; * Uncomment this if function should
		                     return true obliquity rather than
		                     mean obliquity */
	}

	/* return results in radians */
	nutation->longitude = LN_D2R(c_longitude);
	nutation->obliquity = LN_D2R(c_obliquity);
	nutation->ecliptic = LN_D2R(c_ecliptic);
}

/* Equ 22.1
 */
void ln2_get_equ_nut(struct ln_equ_posn *mean_position, double JD,
                     struct ln_equ_posn *position)
{
	struct ln_nutation nut;
	ln2_get_nutation(JD, &nut);

	long double mean_ra, mean_dec, delta_ra, delta_dec;

	mean_ra = mean_position->ra;
	mean_dec = mean_position->dec;

	// Equ 22.1

	long double nut_ecliptic = nut.ecliptic + nut.obliquity;
	long double sin_ecliptic = sinl(nut_ecliptic);

	long double sin_ra = sinl(mean_ra);
	long double cos_ra = cosl(mean_ra);

	long double tan_dec = tanl(mean_dec);

	/* nutation is in radians */
	long double nut_longitude_rad = nut.longitude;
	long double nut_obliquity_rad = nut.obliquity;

	delta_ra = (cosl(nut_ecliptic) + sin_ecliptic * sin_ra * tan_dec) *
	               nut_longitude_rad -
	           cos_ra * tan_dec * nut_obliquity_rad;
	delta_dec = (sin_ecliptic * cos_ra) * nut_longitude_rad +
	            sin_ra * nut_obliquity_rad;

	position->ra = mean_position->ra + delta_ra;
	position->dec = mean_position->dec + delta_dec;
}
