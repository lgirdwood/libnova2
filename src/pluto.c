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
 *  Copyright (C) 2000 - 2005 Liam Girdwood  
 */

#include <math.h>
#include <stdlib.h>
#include <libnova/pluto.h>
#include <libnova/vsop87.h>
#include <libnova/solar.h>
#include <libnova/earth.h>
#include <libnova/transform.h>
#include <libnova/rise_set.h>
#include <libnova/utility.h>

#define PLUTO_COEFFS 43

struct pluto_argument {
	double J, S, P;
};

struct pluto_longitude {
	double A, B;
};

struct pluto_latitude {
	double A, B;
};

struct pluto_radius {
	double A, B;
};

/* cache variables */
static double cJD = 0.0, cL = 0.0, cB = 0.0, cR = 0.0;

static const struct pluto_argument argument[PLUTO_COEFFS] = {
	{0, 0, 1},
	{0, 0, 2},
	{0, 0, 3},
	{0, 0, 4},
	{0, 0, 5},
	{0, 0, 6},
	{0, 1, -1},
	{0, 1, 0},
	{0, 1, 1},
	{0, 1, 2},
	{0, 1, 3},
	{0, 2, -2},
	{0, 2, -1},
	{0, 2, 0},
	{1, -1, 0},
	{1, -1, 1},
	{1, 0, -3},
	{1, 0, -2},
	{1, 0, -1},
	{1, 0, 0},
	{1, 0, 1},
	{1, 0, 2},
	{1, 0, 3},
	{1, 0, 4},
	{1, 1, -3},
	{1, 1, -2},
	{1, 1, -1},
	{1, 1, 0},
	{1, 1, 1},
	{1, 1, 3},
	{2, 0, -6},
	{2, 0, -5},
	{2, 0, -4},
	{2, 0, -3},
	{2, 0, -2},
	{2, 0, -1},
	{2, 0, 0},
	{2, 0, 1},
	{2, 0, 2},
	{2, 0, 3},
	{3, 0, -2},
	{3, 0, -1},
	{3, 0, 0}
};


static const struct pluto_longitude longitude[PLUTO_COEFFS] = {
	{-19799805, 19850055},
	{897144, -4954829},
	{611149, 1211027},
	{-341243, -189585},
	{129287, -34992},
	{-38164, 30893},
	{20442, -9987},
	{-4063, -5071},
	{-6016, -3336},
	{-3956, 3039},
	{-667, 3572},
	{1276, 501},
	{1152, -917},
	{630, -1277},
	{2571, -459},
	{899, -1449},
	{-1016, 1043},
	{-2343, -1012},
	{7042, 788},
	{1199, -338},
	{418, -67},
	{120, -274},
	{-60, -159},
	{-82, -29},
	{-36, -20},
	{-40, 7},
	{-14, 22},
	{4, 13},
	{5,2},
	{-1,0},
	{2,0},
	{-4, 5},
	{4, -7},
	{14, 24},
	{-49, -34},
	{163, -48},
	{9, 24},
	{-4, 1},
	{-3,1},
	{1,3},
	{-3, -1},
	{5, -3},
	{0,0}
};

static const struct pluto_latitude latitude[PLUTO_COEFFS] = {
	{-5452852, -14974862},
	{3527812, 1672790},
	{-1050748, 327647},
	{178690, -292153},
	{18650, 100340},
	{-30697, -25823},
	{4878, 11248},
	{226, -64},
	{2030, -836},
	{69, -604},
	{-247, -567},
	{-57, 1},
	{-122, 175},
	{-49, -164},
	{-197, 199},
	{-25, 217},
	{589, -248},
	{-269, 711},
	{185, 193},
	{315, 807},
	{-130, -43},
	{5, 3},
	{2, 17},
	{2, 5},
	{2, 3},
	{3, 1},
	{2, -1},
	{1, -1},
	{0, -1},
	{0, 0},
	{0, -2},
	{2, 2},
	{-7, 0},
	{10, -8},
	{-3, 20},
	{6, 5},
	{14, 17},
	{-2, 0},
	{0, 0},
	{0, 0},
	{0, 1},
	{0, 0},
	{1, 0}
}; 	

static const struct pluto_radius radius[PLUTO_COEFFS] = {
	{66865439, 68951812},
	{-11827535, -332538},
	{1593179, -1438890},
	{-18444, 483220},
	{-65977, -85431},
	{31174, -6032},
	{-5794, 22161},
	{4601, 4032},
	{-1729, 234},
	{-415, 702},
	{239, 723},
	{67, -67},
	{1034, -451},
	{-129, 504},
	{480, -231},
	{2, -441},
	{-3359, 265},
	{7856, -7832},
	{36, 45763},
	{8663, 8547},
	{-809, -769},
	{263, -144},
	{-126, 32},
	{-35, -16},
	{-19, -4},
	{-15, 8},
	{-4, 12},
	{5, 6},
	{3, 1},
	{6, -2},
	{2, 2},
	{-2, -2},
	{14, 13},
	{-63, 13},
	{136, -236},
	{273, 1065},
	{251, 149},
	{-25, -9},
	{9, -2},
	{-8, 7},
	{2, -10},
	{19, 35},
	{10, 2}
}; 
void ln2_get_pluto_equ_coords(double JD, struct ln_equ_posn *position)
{
	struct ln_helio_posn h_sol, h_pluto;
	struct ln_rect_posn g_sol, g_pluto;
	double a,b,c;
	double ra, dec, delta, diff, last, t = 0;
	
	/* need typdef for solar heliocentric coords */
	ln2_get_solar_geom_coords(JD, &h_sol);
	ln2_get_rect_from_helio(&h_sol,  &g_sol);
	
	do {
		last = t;
		ln2_get_pluto_helio_coords(JD - t, &h_pluto);
		ln2_get_rect_from_helio(&h_pluto, &g_pluto);

		/* equ 33.10 pg 229 */
		a = g_sol.X + g_pluto.X;
		b = g_sol.Y + g_pluto.Y;
		c = g_sol.Z + g_pluto.Z;
	
		delta = a * a + b * b + c * c;
		delta = sqrt(delta);
		t = delta * 0.0057755183;
		diff = t - last;
	} while (diff > 0.0001 || diff < -0.0001);
		
	ra = atan2(b, a);
	dec = c / delta;
	dec = asin(dec);

	/* output in radians */
	position->ra = ln2_range_radians(ra);
	position->dec = dec;
}
/* Chap 37. Equ 37.1
*/

void ln2_get_pluto_helio_coords(double JD, struct ln_helio_posn *position)
{
	double sum_longitude = 0, sum_latitude = 0, sum_radius = 0;
	double J, S, P;
	double t, a, sin_a, cos_a;
	int i;
		
	/* check cache first */
	if(JD == cJD) {
		/* cache hit */
		position->L = cL;
		position->B = cB;
		position->R = cR;
		return;
	}
	
	/* get julian centuries since J2000 */
	t =(JD - 2451545.0) / 36525.0;
	
	/* calculate mean longitudes for jupiter, saturn and pluto */
	J =  34.35 + 3034.9057 * t;
   	S =  50.08 + 1222.1138 * t;
   	P = 238.96 +  144.9600 * t;
 		
	/* calc periodic terms in table 37.A */
	for (i = 0; i < PLUTO_COEFFS; i++) {
		a = argument[i].J * J + argument[i].S * S + argument[i].P * P;
		sin_a = sin(LN_D2R(a));
		cos_a = cos(LN_D2R(a));
		
		/* longitude */
		sum_longitude += longitude[i].A * sin_a + longitude[i].B * cos_a;
		
		/* latitude */
		sum_latitude += latitude[i].A * sin_a + latitude[i].B * cos_a;
		
		/* radius */
		sum_radius += radius[i].A * sin_a + radius[i].B * cos_a;
	}
	
	/* calc L, B, R, return in radians */
	position->L = ln2_range_radians(LN_D2R(238.958116 + 144.96 * t + sum_longitude * 0.000001));
	position->B = LN_D2R(-3.908239 + sum_latitude * 0.000001);
	position->R = 40.7241346 + sum_radius * 0.0000001; 
	
	/* save cache */
	cJD = JD;
	cL = position->L;
	cB = position->B;
	cR = position->R;
}
double ln2_get_pluto_earth_dist(double JD)
{
	struct ln_helio_posn h_pluto, h_earth;
	struct ln_rect_posn g_pluto, g_earth;
	double x, y, z;
	
	/* get heliocentric positions */
	ln2_get_pluto_helio_coords(JD, &h_pluto);
	ln2_get_earth_helio_coords(JD, &h_earth);
	
	/* get geocentric coords */
	ln2_get_rect_from_helio(&h_pluto, &g_pluto);
	ln2_get_rect_from_helio(&h_earth, &g_earth);
	
	/* use pythag */
	x = g_pluto.X - g_earth.X;
	y = g_pluto.Y - g_earth.Y;
	z = g_pluto.Z - g_earth.Z;;
	x = x * x;
	y = y * y;
	z = z * z;

	return sqrt(x + y + z);
} 
double ln2_get_pluto_solar_dist(double JD)
{
	struct ln_helio_posn h_pluto;

	/* get heliocentric position */
	ln2_get_pluto_helio_coords(JD, &h_pluto);
	return h_pluto.R;
} 
double ln2_get_pluto_magnitude(double JD)
{
	double delta, r;
	
	/* get distances */
	r = ln2_get_pluto_solar_dist(JD);
	delta = ln2_get_pluto_earth_dist(JD);

	return -1.0 + 5.0 * log10(r * delta);
} 
/* Chapter 41 */
double ln2_get_pluto_disk(double JD)
{
	double r,delta,R;	
	
	/* get distances */
	R = ln2_get_earth_solar_dist(JD);
	r = ln2_get_pluto_solar_dist(JD);
	delta = ln2_get_pluto_earth_dist(JD);
	
	/* calc fraction angle */
	return (((r + delta) * (r + delta)) - R * R) / (4.0 * r * delta);
} 
/* Chapter 41 */
double ln2_get_pluto_phase(double JD)
{
	double i,r,delta,R;	
	
	/* get distances */
	R = ln2_get_earth_solar_dist(JD);
	r = ln2_get_pluto_solar_dist(JD);
	delta = ln2_get_pluto_earth_dist(JD);

	/* calc phase */
	i = (r * r + delta * delta - R * R) / (2.0 * r * delta);
	i = acos(i);
	return i;
}
int ln2_get_pluto_rst(double JD, struct ln_lnlat_posn *observer,
		struct ln_rst_time *rst)
{
	return ln2_get_body_rst_horizon(JD, observer, ln2_get_pluto_equ_coords,
		LN_STAR_STANDART_HORIZON, rst);
}
double ln2_get_pluto_sdiam(double JD)
{
	double So = 2.07; /* at 1 AU */
	double dist;
	
	dist = ln2_get_pluto_earth_dist(JD);
	return LN_D2R(So / 3600.0) / dist;
}
void ln2_get_pluto_rect_helio(double JD, struct ln_rect_posn *position)
{
	struct ln_helio_posn pluto;
		
	ln2_get_pluto_helio_coords(JD, &pluto);
	ln2_get_rect_from_helio(&pluto, position);
}
