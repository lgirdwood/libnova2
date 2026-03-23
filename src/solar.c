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

#include <libnova2/earth.h>
#include <libnova2/nutation.h>
#include <libnova2/rise_set.h>
#include <libnova2/solar.h>
#include <libnova2/transform.h>
#include <libnova2/utility.h>
#include <math.h>
#include <stdio.h>

void ln2_get_solar_geom_coords(double JD, struct ln_helio_posn *position)
{
	/* get earths heliocentric position */
	ln2_get_earth_helio_coords(JD, position);

	position->L += M_PI;
	position->L = ln2_range_radians(position->L);
	position->B *= -1.0;
}

void ln2_get_solar_equ_coords(double JD, struct ln_equ_posn *position)
{
	struct ln_helio_posn sol;
	struct ln_lnlat_posn LB;
	struct ln_nutation nutation;
	double aberration;

	/* get geometric coords */
	ln2_get_solar_geom_coords(JD, &sol);

	/* add nutation */
	ln2_get_nutation(JD, &nutation);
	sol.L += nutation.longitude;

	/* aberration */
	aberration = LN_D2R(20.4898 / 3600.0) / sol.R;
	sol.L -= aberration;

	/* transform to equatorial */
	LB.lat = sol.B;
	LB.lng = sol.L;
	ln2_get_equ_from_ecl(&LB, JD, position);
}

void ln2_get_solar_ecl_coords(double JD, struct ln_lnlat_posn *position)
{
	struct ln_helio_posn sol;
	struct ln_nutation nutation;
	double aberration;

	/* get geometric coords */
	ln2_get_solar_geom_coords(JD, &sol);

	/* add nutation */
	ln2_get_nutation(JD, &nutation);
	sol.L += nutation.longitude;

	/* aberration */
	aberration = LN_D2R(20.4898 / 3600.0) / sol.R;
	sol.L -= aberration;

	position->lng = sol.L;
	position->lat = sol.B;
}

void ln2_get_solar_geo_coords(double JD, struct ln_rect_posn *position)
{
	/* get earths's heliocentric position */
	struct ln_helio_posn sol;
	ln2_get_earth_helio_coords(JD, &sol);

	/* now get rectangular coords */
	ln2_get_rect_from_helio(&sol, position);
	position->X *= -1.0;
	position->Y *= -1.0;
	position->Z *= -1.0;
}

int ln2_get_solar_rst_horizon(double JD, struct ln_lnlat_posn *observer,
                              double horizon, struct ln_rst_time *rst)
{
	return ln2_get_body_rst_horizon(JD, observer, ln2_get_solar_equ_coords,
	                                LN_D2R(horizon), rst);
}

int ln2_get_solar_rst(double JD, struct ln_lnlat_posn *observer,
                      struct ln_rst_time *rst)
{
	return ln2_get_solar_rst_horizon(JD, observer, LN_SOLAR_STANDART_HORIZON,
	                                 rst);
}

double ln2_get_solar_sdiam(double JD)
{
	double So = 959.63; /* at 1 AU */
	double dist;

	dist = ln2_get_earth_solar_dist(JD);
	return So / dist;
}

/** \example sun.c
 *
 * Examples of how to use solar functions.
 */
