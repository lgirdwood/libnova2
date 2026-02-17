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

#ifndef _LN_EARTH_H
#define _LN_EARTH_H

#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \defgroup earth Earth
*
* Functions relating to the planet Earth.
*
* - **Heliocentric Coordinates**: Calculated using the VSOP87 theory.
*   - **Longitude/Latitude**: In radians.
*   - **Radius Vector**: In Astronomical Units (AU).
*
* All angles are expressed in radians. Algorithms based on Meeus Chapter 32 (VSOP87).
*/

/*
** Earth
*/

/**
* \brief Calculate Earth's heliocentric coordinates (referenced to the center of the Sun).
* \ingroup earth
* \param JD Julian Day
* \param position Pointer to store heliocentric position
*
* Uses the high-precision VSOP87 theory.
*/
/* Chapter 31 Pg 206-207 Equ 31.1 31.2 , 31.3 using VSOP 87 */
void LIBNOVA_EXPORT ln_get_earth_helio_coords(double JD, struct ln_helio_posn *position);

/**
* \brief Calculate the distance between Earth and the Sun.
* \ingroup earth
* \param JD Julian Day
* \return Distance in AU
*
* Uses VSOP87 to calculate the radius vector.
*/
/* Chapter ?? */
double LIBNOVA_EXPORT ln_get_earth_solar_dist(double JD);

/**
* \ingroup earth
* \brief Calculate the Earths rectangular heliocentric coordinates.
* \param JD Julian Day
* \param position Pointer to store rectangular position
*/
void LIBNOVA_EXPORT ln_get_earth_rect_helio(double JD, struct ln_rect_posn *position);

/**
* \ingroup earth
* \brief Calculate Earth globe centre distance.
* \param height Height above sea level in meters
* \param latitude Latitude in radians
* \param p_sin_o Pointer to store p * sin(o')
* \param p_cos_o Pointer to store p * cos(o')
*/
void LIBNOVA_EXPORT ln_get_earth_centre_dist(float height, double latitude, double *p_sin_o, double *p_cos_o);

#ifdef __cplusplus
};
#endif

#endif
