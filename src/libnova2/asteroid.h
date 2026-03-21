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

#ifndef _LN_ASTEROID_H
#define _LN_ASTEROID_H

#include <libnova2/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup asteroid Asteroids
*
* Functions relating to Asteroids.
*
* - **Magnitude System**: Uses the IAU (H, G) magnitude system.
*   - **H**: Absolute magnitude (brightness at 1 AU from Sun and Earth, at zero phase angle).
*   - **G**: Slope parameter (describes how brightness changes with phase angle).
*
* - **Semi-diameter**: Calculated from absolute magnitude and albedo.
*
* All angles are expressed in degrees.
*/

/**
* \brief Calculate the visual magnitude of an asteroid.
* \ingroup asteroid
* \param JD Julian Day
* \param orbit Orbital parameters
* \param H Absolute magnitude
* \param G Slope parameter
* \return Visual magnitude
*
* Uses the IAU (H, G) magnitude system (Bowell et al. 1989).
*/
double LIBNOVA2_EXPORT ln2_get_asteroid_mag(double JD,
											struct ln_ell_orbit *orbit,
											double H, double G);

/**
* \brief Calculate the semi-diameter of an asteroid in km.
* \ingroup asteroid
* \param H Absolute magnitude
* \param A Albedo (0.0 to 1.0)
* \return Semi-diameter in km
*
* Standard relation between diameter, albedo, and absolute magnitude.
*/
double LIBNOVA2_EXPORT ln2_get_asteroid_sdiam_km(double H, double A);

/**
* \brief Calculate the semi-diameter of an asteroid in arc seconds.
* \ingroup asteroid
* \param JD Julian Day
* \param orbit Orbital parameters
* \param H Absolute magnitude
* \param A Albedo
* \return Semi-diameter in arc seconds
*/
double LIBNOVA2_EXPORT ln2_get_asteroid_sdiam_arc(double JD,
												  struct ln_ell_orbit *orbit,
												  double H, double A);

#ifdef __cplusplus
};
#endif

#endif
