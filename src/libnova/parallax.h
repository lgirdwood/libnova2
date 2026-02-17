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
 *  Copyright (C) 2000 - 2005 Petr Kubanek
 */

#ifndef _LN_PARALLAX_H
#define _LN_PARALLAX_H

#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \defgroup parallax Parallax
*
* Functions relating to Parallax.
*
* - **Equatorial Horizontal Parallax**: The angle subtended by the Earth's equatorial radius as seen from the object.
*   - \f$ \sin(\pi) = \frac{R_{\oplus}}{\Delta} \f$
*   - \f$ R_{\oplus} \f$: Earth's equatorial radius (6378.14 km).
*   - \f$ \Delta \f$: Distance to the object.
*
* - **Topocentric Coordinates**: Position seen from a specific location on Earth's surface.
*
* All angles are expressed in degrees. Algorithms based on Meeus Chapter 40.
*/

/**
* \ingroup parallax
* \brief Calculate parallax in RA and DEC for given geographic location
* \param object Geocentric equatorial position of object
* \param au_distance Distance to object in AU
* \param observer Observer's position (geographical coordinates)
* \param height Observer's height in meters
* \param JD Julian Day (UT)
* \param parallax Pointer to store topocentric (parallax corrected) position
*
* Calculates the shift in Right Ascension and Declination due to the observer's location on Earth.
*/
void LIBNOVA_EXPORT ln_get_parallax(struct ln_equ_posn *object, double au_distance, struct ln_lnlat_posn *observer,
									double height, double JD, struct ln_equ_posn *parallax);

/**
* \ingroup parallax
* \brief Calculate parallax in RA and DEC for given geographic location
* \param object Equatorial position of object
* \param au_distance Distance to object in AU
* \param observer Observer's position
* \param height Observer's height in meters
* \param H Hour angle in hours
* \param parallax Pointer to store parallax corrected position
*/
void LIBNOVA_EXPORT ln_get_parallax_ha(struct ln_equ_posn *object, double au_distance, struct ln_lnlat_posn *observer,
									   double height, double H, struct ln_equ_posn *parallax);

#ifdef __cplusplus
};
#endif

#endif
