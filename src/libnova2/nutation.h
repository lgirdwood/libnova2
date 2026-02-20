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

/* taken from table 21.A pg 133 */

#ifndef _LN_NUTATION_H
#define _LN_NUTATION_H

#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup nutation Nutation
*
* Nutation is a periodic oscillation of the Earth's rotational axis around its
* mean position.
*
* This implementation uses the **IAU 1980 Theory of Nutation**, which includes 63 terms 
* in the series expansion for longitude and obliquity.
*
* - **Longitude**: \f$\Delta \psi\f$
* - **Obliquity**: \f$\Delta \epsilon\f$
*
* All angles are expressed in radians. Algorithms based on Meeus Chapter 22.
*/

/**
* \ingroup nutation
* \brief Calculate nutation. 
* \param JD Julian Day
* \param nutation Pointer to store nutation parameters (longitude, obliquity, ecliptic obliquity)
*
* Calculates the nutation in longitude and obliquity using the IAU 1980 theory (Meeus Table 22.A).
* Also calculates the mean obliquity of the ecliptic (Meeus Formula 22.2) and the true obliquity.
*/
void LIBNOVA_EXPORT ln2_get_nutation(double JD, struct ln_nutation *nutation);

/**
* \brief Calculate equatorial coordinates with the effects of nutation.
* \ingroup nutation
* \param mean_position Mean equatorial position (J2000.0)
* \param JD Julian Day
* \param position Pointer to store new equatorial position
*
* Meeus Formula 22.1. Applies the correction to Right Ascension and Declination due to nutation.
*/
void LIBNOVA_EXPORT ln2_get_equ_nut(struct ln_equ_posn *mean_position, double JD, struct ln_equ_posn *position);

#ifdef __cplusplus
};
#endif

#endif
