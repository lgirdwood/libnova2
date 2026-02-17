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

#ifndef _LN_ABERRATION_H
#define _LN_ABERRATION_H

#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \defgroup aberration Aberration
*
* Aberration is the apparent displacement of a celestial body due to the finite speed of light
* and the motion of the observer (Earth) relative to the object.
*
* - **Annual Aberration**: Caused by Earth's orbital motion around the Sun (up to ~20.5 arcseconds).
* - **Diurnal Aberration**: Caused by Earth's rotation (much smaller, usually neglected for low precision).
*
* All angles are expressed in degrees. Algorithms based on Meeus Chapter 23.
*/

/**
* \brief Calculate equatorial coordinates with the effects of aberration.
* \ingroup aberration
* \param mean_position Mean position (J2000.0)
* \param JD Julian Day
* \param position Pointer to store new position
*
* Calculates annual aberration using the Ron-Vondrak expression (for high precision) or Meeus Formula 23.2.
* This corrects for the finite speed of light and Earth's velocity vector.
*/
/* Equ 22.3, 22.4 and Ron-Vondrak expression */
void LIBNOVA_EXPORT ln_get_equ_aber(struct ln_equ_posn *mean_position, double JD, struct ln_equ_posn *position);

/**
* \brief Calculate ecliptical coordinates with the effects of aberration.
* \ingroup aberration
* \param mean_position Mean position (J2000.0)
* \param JD Julian Day
* \param position Pointer to store new position
*
* Meeus Formula 23.2.
*/
/* Equ 22.2 pg 139 */
void LIBNOVA_EXPORT ln_get_ecl_aber(struct ln_lnlat_posn *mean_position, double JD, struct ln_lnlat_posn *position);

#ifdef __cplusplus
};
#endif

#endif
