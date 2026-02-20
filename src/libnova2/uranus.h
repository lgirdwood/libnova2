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

#ifndef _LN_URANUS_H
#define _LN_URANUS_H

#include <libnova2/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup uranus Uranus
*
* Functions relating to the planet Uranus.
*
* - **Heliocentric Coordinates**: Calculated using the VSOP87 theory.
*   - **Longitude/Latitude**: In radians.
*   - **Radius Vector**: In Astronomical Units (AU).
*
* - **Physical Ephemeris**: Semidiameter, Magnitude, Phase Angle.
*
* All angles are expressed in radians. Algorithms based on Meeus Chapter 31 (Planets) and 40/41 (magnitude/disk).
*/

/**
* \brief Calculate the semidiameter of Uranus in radians.
* \ingroup uranus
* \param JD Julian Day
* \return Semidiameter in radians
*/
double LIBNOVA2_EXPORT ln2_get_uranus_sdiam(double JD);

/**
* \brief Calculate the time of rise, set and transit for Uranus.
* \ingroup uranus
* \param JD Julian Day
* \param observer Observer's position
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*/
int LIBNOVA2_EXPORT ln2_get_uranus_rst(double JD, struct ln_lnlat_posn *observer, struct ln_rst_time *rst);

/**
* \brief Calculate Uranus heliocentric coordinates
* \ingroup uranus
* \param JD Julian Day
* \param position Pointer to store heliocentric position
*/
/* Chapter 31 Pg 206-207 Equ 31.1 31.2 , 31.3 using VSOP 87 */
void LIBNOVA2_EXPORT ln2_get_uranus_helio_coords(double JD, struct ln_helio_posn *position);

/**
* \brief Calculate Uranus equatorial coordinates.
* \ingroup uranus
* \param JD Julian Day
* \param position Pointer to store equatorial position
*/
/* Chapter 31 Pg 206-207 Equ 31.1 31.2 , 31.3 using VSOP 87 */
void LIBNOVA2_EXPORT ln2_get_uranus_equ_coords(double JD, struct ln_equ_posn *position);

/**
* \brief Calculate the distance between Uranus and the Earth.
* \ingroup uranus
* \param JD Julian Day
* \return Distance in AU
*/
/* Chapter ?? */
double LIBNOVA2_EXPORT ln2_get_uranus_earth_dist(double JD);

/**
* \brief Calculate the distance between Uranus and the Sun.
* \ingroup uranus
* \param JD Julian Day
* \return Distance in AU
*/
/* Chapter ?? */
double LIBNOVA2_EXPORT ln2_get_uranus_solar_dist(double JD);

/**
* \brief Calculate the visible magnitude of Uranus
* \ingroup uranus
* \param JD Julian Day
* \return Visible magnitude of Uranus
*/
/* Chapter ?? */
double LIBNOVA2_EXPORT ln2_get_uranus_magnitude(double JD);

/**
* \brief Calculate the illuminated fraction of Uranus's disk
* \ingroup uranus
* \param JD Julian Day
* \return Illuminated fraction of Uranus disk
*/
/* Chapter 41 */
double LIBNOVA2_EXPORT ln2_get_uranus_disk(double JD);

/**
* \brief Calculate the phase angle of Uranus.
* \ingroup uranus
* \param JD Julian Day
* \return Phase angle of Uranus (radians)
*/
/* Chapter 41 */
double LIBNOVA2_EXPORT ln2_get_uranus_phase(double JD);

/**
* \ingroup uranus
* \brief Calculate Uranus rectangular heliocentric coordinates.
* \param JD Julian Day
* \param position Pointer to store rectangular position
*/
void LIBNOVA2_EXPORT ln2_get_uranus_rect_helio(double JD, struct ln_rect_posn *position);

#ifdef __cplusplus
};
#endif

#endif
