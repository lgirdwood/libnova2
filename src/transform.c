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
#include <libnova2/precession.h>
#include <libnova2/sidereal_time.h>
#include <libnova2/transform.h>
#include <libnova2/utility.h>
#include <math.h>

/* Equ 37.1 Pg 264
 */
void ln2_get_rect_from_helio(struct ln_helio_posn *object,
                             struct ln_rect_posn *position)
{
	double sin_e, cos_e;
	double cos_B, sin_B, sin_L, cos_L;

	/* ecliptic J2000 */
	sin_e = 0.397777156;
	cos_e = 0.917482062;

	/* calc common values */
	cos_B = cos(object->B);
	cos_L = cos(object->L);
	sin_B = sin(object->B);
	sin_L = sin(object->L);

	/* equ 37.1 */
	position->X = object->R * cos_L * cos_B;
	position->Y = object->R * (sin_L * cos_B * cos_e - sin_B * sin_e);
	position->Z = object->R * (sin_L * cos_B * sin_e + sin_B * cos_e);
}

/* Equ 12.1,12.2 pg 88
 *
 * TODO:
 * Transform horizontal coordinates to galactic coordinates.
 */

void ln2_get_hrz_from_equ(struct ln_equ_posn *object,
                          struct ln_lnlat_posn *observer, double JD,
                          struct ln_hrz_posn *position)
{
	double sidereal;

	/* get mean sidereal time in hours*/
	sidereal = ln2_get_mean_sidereal_time(JD);
	ln2_get_hrz_from_equ_sidereal_time(object, observer, sidereal, position);
}

void ln2_get_hrz_from_equ_sidereal_time(struct ln_equ_posn *object,
                                        struct ln_lnlat_posn *observer,
                                        double sidereal,
                                        struct ln_hrz_posn *position)
{
	long double H, ra, latitude, declination, A, Ac, As, h, Z, Zs;

	/* sidereal time is in radians */

	/* calculate hour angle of object at observers position */
	ra = object->ra;
	H = sidereal + observer->lng - ra;

	/* hence formula 12.5 and 12.6 give */
	/* convert to radians - hour angle, observers latitude, object declination
	 */
	latitude = observer->lat;
	declination = object->dec;

	/* formula 12.6 *; missuse of A (you have been warned) */
	A = sin(latitude) * sin(declination) +
	    cos(latitude) * cos(declination) * cos(H);
	h = asin(A);

	/* output in radians */
	position->alt = h;

	/* zenith distance, Telescope Control 6.8a */
	Z = acos(A);

	/* is'n there better way to compute that? */
	Zs = sin(Z);

	/* sane check for zenith distance; don't try to divide by 0 */
	if (fabs(Zs) < 1e-5) {
		if (object->dec > 0.0)
			position->az = M_PI;
		else
			position->az = 0.0;
		if ((object->dec > 0.0 && observer->lat > 0.0) ||
		    (object->dec < 0.0 && observer->lat < 0.0))
			position->alt = M_PI_2;
		else
			position->alt = -M_PI_2;
		return;
	}

	/* formulas TC 6.8d Taff 1991, pp. 2 and 13 - vector transformations */
	As = (cos(declination) * sin(H)) / Zs;
	Ac = (sin(latitude) * cos(declination) * cos(H) -
	      cos(latitude) * sin(declination)) /
	     Zs;

	// don't blom at atan2
	if (Ac == 0.0 && As == 0.0) {
		if (object->dec > 0)
			position->az = M_PI;
		else
			position->az = 0.0;
		return;
	}
	A = atan2(As, Ac);

	/* output in radians */
	position->az = ln2_range_radians(A);
}

void ln2_get_equ_from_hrz(struct ln_hrz_posn *object,
                          struct ln_lnlat_posn *observer, double JD,
                          struct ln_equ_posn *position)
{
	long double H, longitude, declination, latitude, A, h, sidereal;

	/* change observer/object position into radians */

	/* object alt/az */
	A = object->az;
	h = object->alt;

	/* observer long / lat */
	longitude = observer->lng;
	latitude = observer->lat;

	/* equ on pg89 */
	H = atan2(sin(A), (cos(A) * sin(latitude) + tan(h) * cos(latitude)));
	declination = sin(latitude) * sin(h) - cos(latitude) * cos(h) * cos(A);
	declination = asin(declination);

	/* get ra = sidereal - longitude + H */
	sidereal = ln2_get_apparent_sidereal_time(JD);

	position->ra = ln2_range_radians(sidereal - H + longitude);
	position->dec = declination;
}

/* Equ 12.3, 12.4 pg 89
 */
void ln2_get_equ_from_ecl(struct ln_lnlat_posn *object, double JD,
                          struct ln_equ_posn *position)
{
	double ra, declination, longitude, latitude;
	struct ln_nutation nutation;

	/* get obliquity of ecliptic */
	ln2_get_nutation(JD, &nutation);

	/* change object's position into radians */

	/* object */
	longitude = object->lng;
	latitude = object->lat;

	/* Equ 12.3, 12.4 */
	ra = atan2((sin(longitude) * cos(nutation.ecliptic) -
	            tan(latitude) * sin(nutation.ecliptic)),
	           cos(longitude));
	declination = sin(latitude) * cos(nutation.ecliptic) +
	              cos(latitude) * sin(nutation.ecliptic) * sin(longitude);
	declination = asin(declination);

	/* store in position and normalize */
	position->ra = ln2_range_radians(ra);
	position->dec = declination;
}

/* Equ 12.1, 12.2 Pg 88
 */
void ln2_get_ecl_from_equ(struct ln_equ_posn *object, double JD,
                          struct ln_lnlat_posn *position)
{
	double ra, declination, latitude, longitude;
	struct ln_nutation nutation;

	/* object position */
	ra = object->ra;
	declination = object->dec;
	ln2_get_nutation(JD, &nutation);

	/* Equ 12.1, 12.2 */
	longitude = atan2((sin(ra) * cos(nutation.ecliptic) +
	                   tan(declination) * sin(nutation.ecliptic)),
	                  cos(ra));
	latitude = sin(declination) * cos(nutation.ecliptic) -
	           cos(declination) * sin(nutation.ecliptic) * sin(ra);
	latitude = asin(latitude);

	/* store in position */
	position->lat = latitude;
	position->lng = ln2_range_radians(longitude);
}

/* Equ 33.2
 */
void ln2_get_ecl_from_rect(struct ln_rect_posn *rect,
                           struct ln_lnlat_posn *posn)
{
	double t;

	t = sqrt(rect->X * rect->X + rect->Y * rect->Y);
	posn->lng = ln2_range_radians(atan2(rect->X, rect->Y));
	posn->lat = atan2(t, rect->Z);
}

/* Pg 94 */
void ln2_get_equ_from_gal(struct ln_gal_posn *gal, struct ln_equ_posn *equ)
{
	double RAD_27_4, SIN_27_4, COS_27_4;
	double l_123, cos_l_123;
	double sin_b, cos_b, rad_gal_b;
	double y;

	RAD_27_4 = LN_D2R(27.4);
	SIN_27_4 = sin(RAD_27_4);
	COS_27_4 = cos(RAD_27_4);

	l_123 = gal->l - LN_D2R(123.0);
	cos_l_123 = cos(l_123);

	rad_gal_b = gal->b;

	sin_b = sin(rad_gal_b);
	cos_b = cos(rad_gal_b);

	y = atan2(sin(l_123), cos_l_123 * SIN_27_4 - (sin_b / cos_b) * COS_27_4);
	equ->ra = ln2_range_radians(y + LN_D2R(12.25));
	equ->dec = asin(sin_b * SIN_27_4 + cos_b * COS_27_4 * cos_l_123);
}

void ln2_get_equ2000_from_gal(struct ln_gal_posn *gal, struct ln_equ_posn *equ)
{
	ln2_get_equ_from_gal(gal, equ);
	ln2_get_equ_prec2(equ, B1950, JD2000, equ);
}

/* Pg 94 */
void ln2_get_gal_from_equ(struct ln_equ_posn *equ, struct ln_gal_posn *gal)
{
	double RAD_27_4, SIN_27_4, COS_27_4;
	double ra_192_25, cos_ra_192_25;
	double rad_equ_dec;
	double cos_dec, sin_dec;
	double x;

	RAD_27_4 = LN_D2R(27.4);
	SIN_27_4 = sin(RAD_27_4);
	COS_27_4 = cos(RAD_27_4);

	ra_192_25 = LN_D2R(192.25) - equ->ra;
	cos_ra_192_25 = cos(ra_192_25);

	rad_equ_dec = equ->dec;

	sin_dec = sin(rad_equ_dec);
	cos_dec = cos(rad_equ_dec);

	x = atan2(sin(ra_192_25),
	          cos_ra_192_25 * SIN_27_4 - (sin_dec / cos_dec) * COS_27_4);
	gal->l = ln2_range_radians(LN_D2R(303.0) - x);
	gal->b = asin(sin_dec * SIN_27_4 + cos_dec * COS_27_4 * cos_ra_192_25);
}

void ln2_get_gal_from_equ2000(struct ln_equ_posn *equ, struct ln_gal_posn *gal)
{
	struct ln_equ_posn equ_1950;
	ln2_get_equ_prec2(equ, JD2000, B1950, &equ_1950);
	ln2_get_gal_from_equ(&equ_1950, gal);
}

/** \example transforms.c
 *
 * Examples of how to use transformation functions.
 */
