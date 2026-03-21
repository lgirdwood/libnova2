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

#ifndef _LN_PLUTO_H
#define _LN_PLUTO_H

#include <libnova2/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup pluto Pluto
*
* Functions relating to the planet Pluto.
*
* - **Orbits**: Valid for the years 1885-2099.
* - **Accuracy**:
*   - Longitude: 0.6 arcseconds.
*   - Latitude: 0.2 arcseconds.
*   - Radial Distance: 0.00002 AU.
*
* All angles are expressed in radians. Algorithms based on Meeus Chapter 37.
*/

/**
* \brief Calculate the semidiameter of Pluto in radians.
* \ingroup pluto
* \param JD Julian Day
* \return Semidiameter in radians
*/
double LIBNOVA2_EXPORT ln2_get_pluto_sdiam(double JD);

/**
* \brief Calculate the time of rise, set and transit for Pluto.
* \ingroup pluto
* \param JD Julian Day
* \param observer Observer's position
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*/
int LIBNOVA2_EXPORT ln2_get_pluto_rst(double JD, struct ln_lnlat_posn *observer,
									  struct ln_rst_time *rst);

/**
* \brief Calculate Pluto's heliocentric coordinates.
* \ingroup pluto
* \param JD Julian Day
* \param position Pointer to store heliocentric position
*/
/* Chapter 37 Pg 263  */
void LIBNOVA2_EXPORT ln2_get_pluto_helio_coords(double JD,
												struct ln_helio_posn *position);

/**
* \brief Calculate Pluto's equatorial coordinates.
* \ingroup pluto
* \param JD Julian Day
* \param position Pointer to store equatorial position
*/
/* Chapter 37 */
void LIBNOVA2_EXPORT ln2_get_pluto_equ_coords(double JD,
											  struct ln_equ_posn *position);

/**
* \brief Calculate the distance between Pluto and the Earth.
* \ingroup pluto
* \param JD Julian Day
* \return distance in AU
*/
/* Chapter 37 */
double LIBNOVA2_EXPORT ln2_get_pluto_earth_dist(double JD);

/**
* \brief Calculate the distance between Pluto and the Sun.
* \ingroup pluto
* \param JD Julian Day
* \return Distance in AU
*/
/* Chapter 37 */
double LIBNOVA2_EXPORT ln2_get_pluto_solar_dist(double JD);

/**
* \brief Calculate the visible magnitude of Pluto
* \ingroup pluto
* \param JD Julian Day
* \return Visible magnitude of Pluto.
*/
/* Chapter 41 */
double LIBNOVA2_EXPORT ln2_get_pluto_magnitude(double JD);

/**
* \brief Calculate the illuminated fraction of Pluto's disk
* \ingroup pluto
* \param JD Julian Day
* \return Illuminated fraction of Pluto's disk
*/
/* Chapter 41 */
double LIBNOVA2_EXPORT ln2_get_pluto_disk(double JD);

/**
* \brief Calculate the phase angle of Pluto. 
* \ingroup pluto
* \param JD Julian Day
* \return Phase angle of Pluto (radians).
*/
/* Chapter 41 */
double LIBNOVA2_EXPORT ln2_get_pluto_phase(double JD);

/**
* \ingroup pluto
* \brief Calculate Plutos rectangular heliocentric coordinates.
* \param JD Julian Day
* \param position Pointer to store rectangular position
*/
void LIBNOVA2_EXPORT ln2_get_pluto_rect_helio(double JD,
											  struct ln_rect_posn *position);

#ifdef __cplusplus
};
#endif

#endif
