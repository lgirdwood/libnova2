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

#ifndef _LN_PRECESSION_H
#define _LN_PRECESSION_H

#include <libnova2/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup precession Precession
*
* Precession is the changing direction of the Earth's rotational axis over time.
*
* - **General Precession**: The combined effect of luni-solar precession and planetary precession.
* - **Annual Precession**: The amount of precession in one year (approx 50.29 arcseconds).
* - **IAU 1976 Precession**: The standard model used here.
*
* All angles are expressed in radians. Algorithms based on Meeus Chapter 22.
*/

/**
* \brief Calculate the effects of precession on equatorial coordinates, convert current to J2000.
* \ingroup precession
* \param mean_position Mean equatorial position
* \param JD Julian Day
* \param position Pointer to store new equatorial position
*/

/* Equ 20.2, 20.3, 20.4 pg 126 */
void LIBNOVA2_EXPORT ln2_get_equ_prec(struct ln_equ_posn *mean_position,
									  double JD, struct ln_equ_posn *position);

/**
* \brief Calculate the effects of precession on equatorial coordinates, between arbitary Jxxxx epochs.
* \ingroup precession
* \param mean_position Mean equatorial position
* \param fromJD Initial Julian Day
* \param toJD Final Julian Day
* \param position Pointer to store new equatorial position
*/

/* Equ 20.2, 20.3, 20.4 pg 126 */
void LIBNOVA2_EXPORT ln2_get_equ_prec2(struct ln_equ_posn *mean_position,
									   double fromJD, double toJD,
									   struct ln_equ_posn *position);

/**
* \brief Calculate the effects of precession on ecliptical coordinates.
* \ingroup precession
* \param mean_position Mean ecliptical position
* \param JD Julian Day
* \param position Pointer to store new ecliptical position
*/
/* Equ 20.5, 20.6 pg 128 */
void LIBNOVA2_EXPORT ln2_get_ecl_prec(struct ln_lnlat_posn *mean_position,
									  double JD,
									  struct ln_lnlat_posn *position);

#ifdef __cplusplus
};
#endif

#endif
