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

#ifndef _LN_RISE_SET_H
#define _LN_RISE_SET_H

#include <libnova/ln_types.h>

#define LN_STAR_STANDART_HORIZON -0.00989019909

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup rst Rise, Set, Transit
*
* Functions relating to an object's rise, set and transit times.
*
* - **Standard Horizon**: -0.5667 degrees (34 arcminutes).
*   - Accounts for refraction at the horizon (approx 34').
*   - For Sun/Moon, upper limb touches horizon.
*
* All angles are expressed in radians. Algorithms based on Meeus Chapter 15.
*/

/**
* \brief Calculate the time of rise, set and transit for an object not orbiting the Sun.
* \ingroup rst
* \param JD Julian Day
* \param observer Observer's position
* \param object Equatorial position of object
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*
* Uses the standard horizon of 34 arcminutes.
*/
int LIBNOVA_EXPORT ln_get_object_rst(double JD, struct ln_lnlat_posn *observer, struct ln_equ_posn *object,
									 struct ln_rst_time *rst);

/**
* \brief Calculate the time of rise, set and transit above local horizon for
* an object not orbiting the Sun.
* \param JD Julian Day
* \param observer Observer's position
* \param object Equatorial position of object
* \param horizon Horizon altitude
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*/
int LIBNOVA_EXPORT ln_get_object_rst_horizon(double JD, struct ln_lnlat_posn *observer, struct ln_equ_posn *object,
											 long double horizon, struct ln_rst_time *rst);

int LIBNOVA_EXPORT ln_get_object_rst_horizon_offset(double JD, struct ln_lnlat_posn *observer,
													struct ln_equ_posn *object, long double horizon,
													struct ln_rst_time *rst, double ut_offset);

/**
* \brief Calculate the time of next rise, set and transit for an object not orbiting the Sun.
* E.g. it's sure, that rise, set and transit will be in <JD, JD+1> range.
* This function is not too precise, it's good to get general idea when object will rise.
* \ingroup rst
* \param JD Julian Day
* \param observer Observer's position
* \param object Equatorial position of object
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*/
int LIBNOVA_EXPORT ln_get_object_next_rst(double JD, struct ln_lnlat_posn *observer, struct ln_equ_posn *object,
										  struct ln_rst_time *rst);

/**
* \brief Calculate the time of next rise, set and transit for an object not orbiting the Sun.
* E.g. it's sure, that rise, set and transit will be in <JD, JD+1> range.
* \ingroup rst
* \param JD Julian Day
* \param observer Observer's position
* \param object Equatorial position of object
* \param horizon Horizon altitude
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*/
int LIBNOVA_EXPORT ln_get_object_next_rst_horizon(double JD, struct ln_lnlat_posn *observer, struct ln_equ_posn *object,
												  double horizon, struct ln_rst_time *rst);

/**
 * \brief Calculate the time of rise, set and transit for an object a body, usually Sun, a planet or Moon.
 * \ingroup rst
 * \param JD Julian Day
 * \param observer Observer's position
 * \param get_equ_body_coords Function to get body's equatorial coordinates
 * \param horizon Horizon altitude
 * \param rst Pointer to store rise, set and transit times
 * \return 0 for success, 1 for circumpolar, -1 for never rises
 */
int LIBNOVA_EXPORT ln_get_body_rst_horizon(double JD, struct ln_lnlat_posn *observer,
										   void (*get_equ_body_coords)(double, struct ln_equ_posn *), double horizon,
										   struct ln_rst_time *rst);

int LIBNOVA_EXPORT ln_get_body_rst_horizon_offset(double JD, struct ln_lnlat_posn *observer,
												  void (*get_equ_body_coords)(double, struct ln_equ_posn *),
												  double horizon, struct ln_rst_time *rst, double ut_offset);

/**
 * \brief Calculate the time of next  rise, set and transit for an object a body, usually Sun, a planet or Moon.
 * E.g. it's sure, that rise, set and transit will be in <JD, JD+1> range.
 * \ingroup rst
 * \param JD Julian Day
 * \param observer Observer's position
 * \param get_equ_body_coords Function to get body's equatorial coordinates
 * \param horizon Horizon altitude
 * \param rst Pointer to store rise, set and transit times
 * \return 0 for success, 1 for circumpolar, -1 for never rises
 */
int LIBNOVA_EXPORT ln_get_body_next_rst_horizon(double JD, struct ln_lnlat_posn *observer,
												void (*get_equ_body_coords)(double, struct ln_equ_posn *),
												double horizon, struct ln_rst_time *rst);

/**
 * \brief Calculate the time of next  rise, set and transit for an object a body, usually Sun, a planet or Moon.
 * E.g. it's sure, that rise, set and transit will be in <JD, JD+day_limit> range.
 * \ingroup rst
 * \param JD Julian Day
 * \param observer Observer's position
 * \param get_equ_body_coords Function to get body's equatorial coordinates
 * \param horizon Horizon altitude
 * \param day_limit Limit in days to search for next rise/set
 * \param rst Pointer to store rise, set and transit times
 * \return 0 for success, 1 for circumpolar, -1 for never rises
 */
int LIBNOVA_EXPORT ln_get_body_next_rst_horizon_future(double JD, struct ln_lnlat_posn *observer,
													   void (*get_equ_body_coords)(double, struct ln_equ_posn *),
													   double horizon, int day_limit, struct ln_rst_time *rst);

typedef void (*get_motion_body_coords_t)(double, void *orbit, struct ln_equ_posn *);

/**
 * \brief Calculate the time of rise, set and transit for an object a body on elliptic, parabolic or hyperbolic orbit.
 * \ingroup rst
 * \param JD Julian Day
 * \param observer Observer's position
 * \param get_motion_body_coords Function to get body's motion coordinates
 * \param orbit Orbital parameters
 * \param horizon Horizon altitude
 * \param rst Pointer to store rise, set and transit times
 * \return 0 for success, 1 for circumpolar, -1 for never rises
 */
int LIBNOVA_EXPORT ln_get_motion_body_rst_horizon(double JD, struct ln_lnlat_posn *observer,
												  get_motion_body_coords_t get_motion_body_coords, void *orbit,
												  double horizon, struct ln_rst_time *rst);

int LIBNOVA_EXPORT ln_get_motion_body_rst_horizon_offset(double JD, struct ln_lnlat_posn *observer,
														 get_motion_body_coords_t get_motion_body_coords, void *orbit,
														 double horizon, struct ln_rst_time *rst, double offset);

/**
 * \brief Calculate the time of next  rise, set and transit for an object a body on elliptic, parabolic or hyperbolic orbit.
 * E.g. it's sure, that rise, set and transit will be in <JD, JD+1> range.
 * \ingroup rst
 * \param JD Julian Day
 * \param observer Observer's position
 * \param get_motion_body_coords Function to get body's motion coordinates
 * \param orbit Orbital parameters
 * \param horizon Horizon altitude
 * \param rst Pointer to store rise, set and transit times
 * \return 0 for success, 1 for circumpolar, -1 for never rises
 */
int LIBNOVA_EXPORT ln_get_motion_body_next_rst_horizon(double JD, struct ln_lnlat_posn *observer,
													   get_motion_body_coords_t get_motion_body_coords, void *orbit,
													   double horizon, struct ln_rst_time *rst);

/**
 * \brief Calculate the time of next  rise, set and transit for an object a body on elliptic, parabolic or hyperbolic orbit.
 * E.g. it's sure, that rise, set and transit will be in <JD, JD+day_limit> range.
 * \ingroup rst
 * \param JD Julian Day
 * \param observer Observer's position
 * \param get_motion_body_coords Function to get body's motion coordinates
 * \param orbit Orbital parameters
 * \param horizon Horizon altitude
 * \param day_limit Limit in days to search for next rise/set
 * \param rst Pointer to store rise, set and transit times
 * \return 0 for success, 1 for circumpolar, -1 for never rises
 */
int LIBNOVA_EXPORT ln_get_motion_body_next_rst_horizon_future(double JD, struct ln_lnlat_posn *observer,
															  get_motion_body_coords_t get_motion_body_coords,
															  void *orbit, double horizon, int day_limit,
															  struct ln_rst_time *rst);

#ifdef __cplusplus
};
#endif

#endif
