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
 *  Copyright (C) 2000 - 2026 Liam Girdwood
 */

#include <libnova2/dynamical_time.h>
#include <libnova2/earth.h>
#include <libnova2/elliptic_motion.h>
#include <libnova2/rise_set.h>
#include <libnova2/sidereal_time.h>
#include <libnova2/solar.h>
#include <libnova2/transform.h>
#include <libnova2/utility.h>
#include <math.h>

/* number of steps in calculation, 3.32 steps for each significant
digit required */
#define KEPLER_STEPS 53

/* the BASIC SGN() function  for doubles */
static inline double sgn(double x)
{
	if (x == 0.0)
		return (x);
	else if (x < 0.0)
		return (-1.0);
	else
		return (1.0);
}

double ln2_solve_kepler(double e, double M)
{
	double Eo = M_PI_2;
	double F, M1;
	double D = M_PI_4;
	int i;

	/* covert to radians */
	/* M is already in radians */

	F = sgn(M);
	M = fabs(M) / (2.0 * M_PI);
	M = (M - (int)M) * 2.0 * M_PI * F;

	if (M < 0)
		M = M + 2.0 * M_PI;
	F = 1.0;

	if (M > M_PI)
		F = -1.0;

	if (M > M_PI)
		M = 2.0 * M_PI - M;

	for (i = 0; i < KEPLER_STEPS; i++) {
		M1 = Eo - e * sin(Eo);
		Eo = Eo + D * sgn(M - M1);
		D /= 2.0;
	}
	Eo *= F;

	/* Eo is radians */
	return Eo;
}

double ln2_get_ell_mean_anomaly(double n, double delta_JD)
{
	return delta_JD * n;
}

/* equ 30.1 */
double ln2_get_ell_true_anomaly(double e, double E)
{
	double v;

	/* E is radians */
	v = sqrt((1.0 + e) / (1.0 - e)) * tan(E / 2.0);
	v = 2.0 * atan(v);
	v = ln2_range_radians(v);
	return v;
}

/* equ 30.2 */
double ln2_get_ell_radius_vector(double a, double e, double E)
{
	return a * (1.0 - e * cos(E));
}

double ln2_get_ell_smajor_diam(double e, double q)
{
	return q / (1.0 - e);
}

double ln2_get_ell_sminor_diam(double e, double a)
{
	return a * sqrt(1 - e * e);
}

double ln2_get_ell_mean_motion(double a)
{
	double q = 0.01720209895; /* Gaussian gravitational constant (radians)*/
	return q / (a * sqrt(a));
}

void ln2_get_ell_helio_rect_posn(struct ln_ell_orbit *orbit, double JD,
                                 struct ln_rect_posn *posn)
{
	double A, B, C;
	double F, G, H;
	double P, Q, R;
	double sin_e, cos_e;
	double a, b, c;
	double sin_omega, sin_i, cos_omega, cos_i;
	double M, v, E, r;

	/* J2000 obliquity of the ecliptic */
	sin_e = 0.397777156;
	cos_e = 0.917482062;

	/* equ 33.7 */
	sin_omega = sin(orbit->omega);
	cos_omega = cos(orbit->omega);
	sin_i = sin(orbit->i);
	cos_i = cos(orbit->i);
	F = cos_omega;
	G = sin_omega * cos_e;
	H = sin_omega * sin_e;
	P = -sin_omega * cos_i;
	Q = cos_omega * cos_i * cos_e - sin_i * sin_e;
	R = cos_omega * cos_i * sin_e + sin_i * cos_e;

	/* equ 33.8 */
	A = atan2(F, P);
	B = atan2(G, Q);
	C = atan2(H, R);
	a = sqrt(F * F + P * P);
	b = sqrt(G * G + Q * Q);
	c = sqrt(H * H + R * R);

	/* get daily motion */
	if (orbit->n == 0.0)
		orbit->n = ln2_get_ell_mean_motion(orbit->a);

	/* get mean anomaly */
	M = ln2_get_ell_mean_anomaly(orbit->n, JD - orbit->JD);

	/* get eccentric anomaly */
	E = ln2_solve_kepler(orbit->e, M);

	/* get true anomaly */
	v = ln2_get_ell_true_anomaly(orbit->e, E);

	/* get radius vector */
	r = ln2_get_ell_radius_vector(orbit->a, orbit->e, E);

	/* equ 33.9 */
	posn->X = r * a * sin(A + orbit->w + v);
	posn->Y = r * b * sin(B + orbit->w + v);
	posn->Z = r * c * sin(C + orbit->w + v);
}

void ln2_get_ell_geo_rect_posn(struct ln_ell_orbit *orbit, double JD,
                               struct ln_rect_posn *posn)
{
	struct ln_rect_posn p_posn, e_posn;
	struct ln_helio_posn earth;

	/* elliptic helio rect coords */
	ln2_get_ell_helio_rect_posn(orbit, JD, &p_posn);

	/* earth rect coords */
	ln2_get_earth_helio_coords(JD, &earth);
	ln2_get_rect_from_helio(&earth, &e_posn);

	posn->X = e_posn.X - p_posn.X;
	posn->Y = e_posn.Y - p_posn.Y;
	posn->Z = e_posn.Z - p_posn.Z;
}

void ln2_get_ell_body_equ_coords(double JD, struct ln_ell_orbit *orbit,
                                 struct ln_equ_posn *posn)
{
	struct ln_rect_posn body_rect_posn, sol_rect_posn;
	double dist, t;
	double x, y, z;

	/* get solar and body rect coords */
	ln2_get_ell_helio_rect_posn(orbit, JD, &body_rect_posn);
	ln2_get_solar_geo_coords(JD, &sol_rect_posn);

	/* calc distance and light time */
	dist = ln2_get_rect_distance(&body_rect_posn, &sol_rect_posn);
	t = ln2_get_light_time(dist);

	/* repeat calculation with new time (i.e. JD - t) */
	ln2_get_ell_helio_rect_posn(orbit, JD - t, &body_rect_posn);

	/* calc equ coords equ 33.10 */
	x = sol_rect_posn.X + body_rect_posn.X;
	y = sol_rect_posn.Y + body_rect_posn.Y;
	z = sol_rect_posn.Z + body_rect_posn.Z;

	posn->ra = ln2_range_radians(atan2(y, x));
	posn->dec = asin(z / sqrt(x * x + y * y + z * z));
}

double ln2_get_ell_orbit_len(struct ln_ell_orbit *orbit)
{
	double A, G, H;
	double b;

	b = ln2_get_ell_sminor_diam(orbit->e, orbit->a);

	A = (orbit->a + b) / 2.0;
	G = sqrt(orbit->a * b);
	H = (2.0 * orbit->a * b) / (orbit->a + b);

	/* Meeus, page 239, 2nd edition */
	return M_PI * ((21.0 * A - 2.0 * G - 3.0 * H) / 8.0);
}

double ln2_get_ell_orbit_vel(double JD, struct ln_ell_orbit *orbit)
{
	double V;
	double r;

	r = ln2_get_ell_body_solar_dist(JD, orbit);
	V = 1.0 / r - 1.0 / (2.0 * orbit->a);
	V = 42.1219 * sqrt(V);
	return V;
}

double ln2_get_ell_orbit_pvel(struct ln_ell_orbit *orbit)
{
	double V;

	V = 29.7847 / sqrt(orbit->a);
	V *= sqrt((1.0 + orbit->e) / (1.0 - orbit->e));
	return V;
}

double ln2_get_ell_orbit_avel(struct ln_ell_orbit *orbit)
{
	double V;

	V = 29.7847 / sqrt(orbit->a);
	V *= sqrt((1.0 - orbit->e) / (1.0 + orbit->e));
	return V;
}

double ln2_get_ell_body_solar_dist(double JD, struct ln_ell_orbit *orbit)
{
	struct ln_rect_posn body_rect_posn, sol_rect_posn;

	/* get solar and body rect coords */
	ln2_get_ell_helio_rect_posn(orbit, JD, &body_rect_posn);
	sol_rect_posn.X = 0;
	sol_rect_posn.Y = 0;
	sol_rect_posn.Z = 0;

	/* calc distance */
	return ln2_get_rect_distance(&body_rect_posn, &sol_rect_posn);
}

double ln2_get_ell_body_earth_dist(double JD, struct ln_ell_orbit *orbit)
{
	struct ln_rect_posn body_rect_posn, earth_rect_posn;

	/* get solar and body rect coords */
	ln2_get_ell_geo_rect_posn(orbit, JD, &body_rect_posn);
	earth_rect_posn.X = 0;
	earth_rect_posn.Y = 0;
	earth_rect_posn.Z = 0;

	/* calc distance */
	return ln2_get_rect_distance(&body_rect_posn, &earth_rect_posn);
}

double ln2_get_ell_body_phase_angle(double JD, struct ln_ell_orbit *orbit)
{
	double r, R, d;
	double E, M;
	double phase;

	/* get mean anomaly */
	if (orbit->n == 0.0)
		orbit->n = ln2_get_ell_mean_motion(orbit->a);
	M = ln2_get_ell_mean_anomaly(orbit->n, JD - orbit->JD);

	/* get eccentric anomaly */
	E = ln2_solve_kepler(orbit->e, M);

	/* get radius vector */
	r = ln2_get_ell_radius_vector(orbit->a, orbit->e, E);

	/* get solar and Earth distances */
	R = ln2_get_ell_body_earth_dist(JD, orbit);
	d = ln2_get_ell_body_solar_dist(JD, orbit);

	phase = (r * r + d * d - R * R) / (2.0 * r * d);
	return ln2_range_radians(acos(phase));
}

double ln2_get_ell_body_elong(double JD, struct ln_ell_orbit *orbit)
{
	double r, R, d;
	double t;
	double elong;
	double E, M;

	/* time since perihelion */
	t = JD - orbit->JD;

	/* get mean anomaly */
	if (orbit->n == 0.0)
		orbit->n = ln2_get_ell_mean_motion(orbit->a);
	M = ln2_get_ell_mean_anomaly(orbit->n, t);

	/* get eccentric anomaly */
	E = ln2_solve_kepler(orbit->e, M);

	/* get radius vector */
	r = ln2_get_ell_radius_vector(orbit->a, orbit->e, E);

	/* get solar and Earth-Sun distances */
	R = ln2_get_earth_solar_dist(JD);
	d = ln2_get_ell_body_solar_dist(JD, orbit);

	elong = (R * R + d * d - r * r) / (2.0 * R * d);
	return ln2_range_radians(acos(elong));
}

int ln2_get_ell_body_rst(double JD, struct ln_lnlat_posn *observer,
                         struct ln_ell_orbit *orbit, struct ln_rst_time *rst)
{
	return ln2_get_ell_body_rst_horizon(JD, observer, orbit,
	                                    LN_STAR_STANDART_HORIZON, rst);
}

int ln2_get_ell_body_rst_horizon(double JD, struct ln_lnlat_posn *observer,
                                 struct ln_ell_orbit *orbit, double horizon,
                                 struct ln_rst_time *rst)
{
	return ln2_get_motion_body_rst_horizon(JD, observer,
	                                       (get_motion_body_coords_t)
	                                           ln2_get_ell_body_equ_coords,
	                                       orbit, horizon, rst);
}

int ln2_get_ell_body_next_rst(double JD, struct ln_lnlat_posn *observer,
                              struct ln_ell_orbit *orbit,
                              struct ln_rst_time *rst)
{
	return ln2_get_ell_body_next_rst_horizon(JD, observer, orbit,
	                                         LN_STAR_STANDART_HORIZON, rst);
}

int ln2_get_ell_body_next_rst_horizon(double JD, struct ln_lnlat_posn *observer,
                                      struct ln_ell_orbit *orbit,
                                      double horizon, struct ln_rst_time *rst)
{
	return ln2_get_motion_body_next_rst_horizon(JD, observer,
	                                            (get_motion_body_coords_t)
	                                                ln2_get_ell_body_equ_coords,
	                                            orbit, horizon, rst);
}

int ln2_get_ell_body_next_rst_horizon_future(double JD,
                                             struct ln_lnlat_posn *observer,
                                             struct ln_ell_orbit *orbit,
                                             double horizon, int day_limit,
                                             struct ln_rst_time *rst)
{
	return ln2_get_motion_body_next_rst_horizon_future(JD, observer,
	                                                   (get_motion_body_coords_t)
	                                                       ln2_get_ell_body_equ_coords,
	                                                   orbit, horizon,
	                                                   day_limit, rst);
}

double ln2_get_ell_last_perihelion(double epoch_JD, double M, double n)
{
	return epoch_JD - (M / n);
}
