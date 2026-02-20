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

#ifndef _LN_ELLIPTIC_MOTION_H
#define _LN_ELLIPTIC_MOTION_H

#include <libnova2/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup elliptic  Elliptic Motion
*
* Functions relating to the elliptic motion of bodies.
*
* - **Kepler's Equation**: \f$ E = M + e \sin E \f$
*   - \f$ M \f$: Mean Anomaly (angle from perihelion if motion were uniform).
*   - \f$ E \f$: Eccentric Anomaly (auxiliary angle).
*   - \f$ e \f$: Eccentricity of the orbit.
*
* - **True Anomaly (\f$ \nu \f$)**: The actual angle from perihelion.
*
* All angles are expressed in radians. Algorithms based on Meeus Chapter 30.
*/

/**
* \brief Calculate the eccentric anomaly.
* \ingroup elliptic 
* \param E Eccentricity
* \param M Mean anomaly
* \return Eccentric anomaly
*
* Solves Kepler's Equation \f$ E = M + e \sin E \f$ using an iterative method (usually Newton-Raphson).
*/
double LIBNOVA2_EXPORT ln2_solve_kepler(double E, double M);

/**
* \brief Calculate the mean anomaly.
* \ingroup elliptic 
* \param n Mean motion (degrees/day)
* \param delta_JD Time since perihelion in days
* \return Mean anomaly
*/
double LIBNOVA2_EXPORT ln2_get_ell_mean_anomaly(double n, double delta_JD);

/**
* \brief Calculate the true anomaly.
* \ingroup elliptic 
* \param e Eccentricity
* \param E Eccentric anomaly
* \return True anomaly
*/
double LIBNOVA2_EXPORT ln2_get_ell_true_anomaly(double e, double E);

/**
* \brief Calculate the radius vector.
* \ingroup elliptic 
* \param a Semi-major axis
* \param e Eccentricity
* \param E Eccentric anomaly
* \return Radius vector
*/
double LIBNOVA2_EXPORT ln2_get_ell_radius_vector(double a, double e, double E);

/**
* \brief Calculate the semi major diameter.
* \ingroup elliptic 
* \param e Eccentricity
* \param q Perihelion distance
* \return Semi-major diameter
*/
double LIBNOVA2_EXPORT ln2_get_ell_smajor_diam(double e, double q);

/**
* \brief Calculate the semi minor diameter.
* \ingroup elliptic 
* \param e Eccentricity
* \param a Semi-major axis
* \return Semi-minor diameter
*/
double LIBNOVA2_EXPORT ln2_get_ell_sminor_diam(double e, double a);

/**
* \brief Calculate the mean daily motion (radians/day).
* \ingroup elliptic 
* \param a Semi-major axis
* \return Mean daily motion
*/
double LIBNOVA2_EXPORT ln2_get_ell_mean_motion(double a);

/**
* \brief Calculate the objects rectangular geocentric position. 
* \ingroup elliptic 
* \param orbit Orbital parameters
* \param JD Julian Day
* \param posn Pointer to store rectangular position
*/
void LIBNOVA2_EXPORT ln2_get_ell_geo_rect_posn(struct ln_ell_orbit *orbit,
											 double JD,
											 struct ln_rect_posn *posn);

/**
* \brief Calculate the objects rectangular heliocentric position. 
* \ingroup elliptic 
* \param orbit Orbital parameters
* \param JD Julian Day
* \param posn Pointer to store rectangular position
*/
void LIBNOVA2_EXPORT ln2_get_ell_helio_rect_posn(struct ln_ell_orbit *orbit,
											   double JD,
											   struct ln_rect_posn *posn);

/**
* \brief Calculate the orbital length in AU.
* \ingroup elliptic 
* \param orbit Orbital parameters
* \return Orbital length in AU
*/
double LIBNOVA2_EXPORT ln2_get_ell_orbit_len(struct ln_ell_orbit *orbit);

/**
* \brief Calculate orbital velocity in km/s.
* \ingroup elliptic
* \param JD Julian Day
* \param orbit Orbital parameters
* \return Orbital velocity in km/s
*/
double LIBNOVA2_EXPORT ln2_get_ell_orbit_vel(double JD,
										   struct ln_ell_orbit *orbit);

/**
* \brief Calculate orbital velocity at perihelion in km/s.
* \ingroup elliptic
* \param orbit Orbital parameters
* \return Orbital velocity at perihelion in km/s
*/
double LIBNOVA2_EXPORT ln2_get_ell_orbit_pvel(struct ln_ell_orbit *orbit);

/**
* \ingroup elliptic
* \brief Calculate the orbital velocity at aphelion in km/s. 
* \param orbit Orbital parameters
* \return Orbital velocity at aphelion in km/s
*/
double LIBNOVA2_EXPORT ln2_get_ell_orbit_avel(struct ln_ell_orbit *orbit);

/**
* \ingroup elliptic
* \brief Calculate the phase angle of the body. The angle Sun - body - Earth. 
* \param JD Julian Day
* \param orbit Orbital parameters
* \return Phase angle
*/
double LIBNOVA2_EXPORT ln2_get_ell_body_phase_angle(double JD,
												  struct ln_ell_orbit *orbit);

/**
* \ingroup elliptic
* \brief Calculate the bodies elongation to the Sun.. 
* \param JD Julian Day
* \param orbit Orbital parameters
* \return Elongation to the Sun
*/
double LIBNOVA2_EXPORT ln2_get_ell_body_elong(double JD,
											struct ln_ell_orbit *orbit);

/**
* \brief Calculate the distance between a body and the Sun
* \ingroup elliptic
* \param JD Julian Day
* \param orbit Orbital parameters
* \return Solar distance in AU
*/
double LIBNOVA2_EXPORT ln2_get_ell_body_solar_dist(double JD,
												 struct ln_ell_orbit *orbit);

/**
* \brief Calculate the distance between a body and the Earth
* \ingroup elliptic
* \param JD Julian Day
* \param orbit Orbital parameters
* \return Earth distance in AU
*/
double LIBNOVA2_EXPORT ln2_get_ell_body_earth_dist(double JD,
												 struct ln_ell_orbit *orbit);

/**
* \brief Calculate a bodies equatorial coords
* \ingroup elliptic
* \param JD Julian Day
* \param orbit Orbital parameters
* \param posn Pointer to store equatorial position
*/
void LIBNOVA2_EXPORT ln2_get_ell_body_equ_coords(double JD,
											   struct ln_ell_orbit *orbit,
											   struct ln_equ_posn *posn);

/**
* \brief Calculate the time of rise, set and transit for a body with an elliptic orbit.
* \ingroup elliptic
* \param JD Julian Day
* \param observer Observer's position
* \param orbit Orbital parameters
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*/
int LIBNOVA2_EXPORT ln2_get_ell_body_rst(double JD,
									   struct ln_lnlat_posn *observer,
									   struct ln_ell_orbit *orbit,
									   struct ln_rst_time *rst);

/**
* \brief Calculate the time of rise, set and transit for a body with an elliptic orbit.
* \ingroup elliptic
* \param JD Julian Day
* \param observer Observer's position
* \param orbit Orbital parameters
* \param horizon Horizon altitude
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*/
int LIBNOVA2_EXPORT ln2_get_ell_body_rst_horizon(double JD,
											   struct ln_lnlat_posn *observer,
											   struct ln_ell_orbit *orbit,
											   double horizon,
											   struct ln_rst_time *rst);

/**
* \brief Calculate the time of rise, set and transit for a body with an elliptic orbit.
* \ingroup elliptic
* \param JD Julian Day
* \param observer Observer's position
* \param orbit Orbital parameters
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*/
int LIBNOVA2_EXPORT ln2_get_ell_body_next_rst(double JD,
											struct ln_lnlat_posn *observer,
											struct ln_ell_orbit *orbit,
											struct ln_rst_time *rst);

/**
* \brief Calculate the time of rise, set and transit for a body with an elliptic orbit.
* \ingroup elliptic
* \param JD Julian Day
* \param observer Observer's position
* \param orbit Orbital parameters
* \param horizon Horizon altitude
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*/
int LIBNOVA2_EXPORT ln2_get_ell_body_next_rst_horizon(
	double JD, struct ln_lnlat_posn *observer, struct ln_ell_orbit *orbit,
	double horizon, struct ln_rst_time *rst);

/**
* \brief Calculate the time of rise, set and transit for a body with an elliptic orbit.
* \ingroup elliptic
* \param JD Julian Day
* \param observer Observer's position
* \param orbit Orbital parameters
* \param horizon Horizon altitude
* \param day_limit Limit in days to search for next rise/set
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*/
int LIBNOVA2_EXPORT ln2_get_ell_body_next_rst_horizon_future(
	double JD, struct ln_lnlat_posn *observer, struct ln_ell_orbit *orbit,
	double horizon, int day_limit, struct ln_rst_time *rst);

/**\fn double ln2_get_ell_last_perihelion(double epoch_JD, double M, double n);
* \brief Calculate the julian day of the last perihelion.
* \ingroup elliptic
* \param epoch_JD Epoch Julian Day
* \param M Mean anomaly
* \param n Mean motion
* \return Julian Day of last perihelion
*/
double LIBNOVA2_EXPORT ln2_get_ell_last_perihelion(double epoch_JD, double M,
												 double n);

#ifdef __cplusplus
};
#endif

#endif
