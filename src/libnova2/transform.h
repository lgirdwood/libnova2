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

#ifndef _LN_TRANSFORM_H
#define _LN_TRANSFORM_H

#include <libnova2/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup transform Transformation of Coordinates
*
* Transformations from one coordinate system to another.
*
* - **Equatorial Coordinates**: Right Ascension (RA) and Declination (Dec). Referenced to the equator and equinox of a specific epoch (usually J2000.0).
* - **Ecliptic Coordinates**: Longitude and Latitude. Referenced to the ecliptic plane.
* - **Horizontal Coordinates**: Azimuth and Altitude. Topocentric coordinates relative to the observer's local horizon.
* - **Galactic Coordinates**: Longitude (l) and Latitude (b). Referenced to the galactic plane.
*
* Algorithms based on Meeus Chapter 13.
*/

/**
* \brief Calculate horizontal coordinates from equatorial coordinates 
* \ingroup transform 
* \param object Equatorial position of object
* \param observer Observer's position
* \param JD Julian Day
* \param position Pointer to store horizontal position
*
* Meeus Chapter 13. Uses the observer's longitude and latitude and the sidereal time at Greenwich (calculated from JD).
*/
/* Use get_mean_sidereal_time, get_hrz_from_equ_siderealtime */
void LIBNOVA2_EXPORT ln2_get_hrz_from_equ(struct ln_equ_posn *object, struct ln_lnlat_posn *observer, double JD,
										struct ln_hrz_posn *position);

/**
* \brief Calculate horizontal coordinates from equatorial coordinates,
* using mean sidereal time.
* \ingroup transform 
* \param object Equatorial position of object
* \param observer Observer's position
* \param sidereal Sidereal time in radians
* \param position Pointer to store horizontal position
*
* Meeus Formula 13.5 and 13.6.
*/
/* Equ 12.5,12.6 pg 88 */
void LIBNOVA2_EXPORT ln2_get_hrz_from_equ_sidereal_time(struct ln_equ_posn *object, struct ln_lnlat_posn *observer,
													  double sidereal, struct ln_hrz_posn *position);

/**
* \brief Calculate equatorial coordinates from ecliptical coordinates
* \ingroup transform
* \param object Ecliptical position of object
* \param JD Julian Day
* \param position Pointer to store equatorial position
*
* Meeus Formula 13.3 and 13.4.
*/
/* Equ 12.3, 12.4 pg 89 */
void LIBNOVA2_EXPORT ln2_get_equ_from_ecl(struct ln_lnlat_posn *object, double JD, struct ln_equ_posn *position);

/**
* \brief Calculate ecliptical coordinates from equatorial coordinates 
* \ingroup transform
* \param object Equatorial position of object
* \param JD Julian Day
* \param position Pointer to store ecliptical position
*
* Meeus Formula 13.1 and 13.2.
*/
/* Equ 12.1, 12.2 Pg 88 */
void LIBNOVA2_EXPORT ln2_get_ecl_from_equ(struct ln_equ_posn *object, double JD, struct ln_lnlat_posn *position);

/**
* \brief Calculate equatorial coordinates from horizontal coordinates  
* \ingroup transform
* \param object Horizontal position of object
* \param observer Observer's position
* \param JD Julian Day
* \param position Pointer to store equatorial position
*/
/* Pg 89 */
void LIBNOVA2_EXPORT ln2_get_equ_from_hrz(struct ln_hrz_posn *object, struct ln_lnlat_posn *observer, double JD,
										struct ln_equ_posn *position);

/**
* \brief Calculate geocentric coordinates from heliocentric coordinates  
* \ingroup transform
* \param object Heliocentric position of object
* \param position Pointer to store rectangular position
*/
/* Pg ?? */
void LIBNOVA2_EXPORT ln2_get_rect_from_helio(struct ln_helio_posn *object, struct ln_rect_posn *position);

/**
* \ingroup transform
* \brief Transform an objects rectangular coordinates into ecliptical coordinates.
* \param rect Rectangular position of object
* \param posn Pointer to store ecliptical position
*/
/* Equ 33.2
*/
void LIBNOVA2_EXPORT ln2_get_ecl_from_rect(struct ln_rect_posn *rect, struct ln_lnlat_posn *posn);

/**
* \ingroup transform
* \brief Transform an object galactic coordinates into equatorial coordinates.
* \param gal Galactic position of object
* \param equ Pointer to store equatorial position
*
* Conversion valid for B1950.0 epoch.
*/
/* Pg 94 */
void LIBNOVA2_EXPORT ln2_get_equ_from_gal(struct ln_gal_posn *gal, struct ln_equ_posn *equ);

/**
* \ingroup transform
* \brief Transform an object galactic coordinate into J2000 equatorial coordinates.
* \param gal Galactic position of object
* \param equ Pointer to store J2000 equatorial position
*/
void LIBNOVA2_EXPORT ln2_get_equ2000_from_gal(struct ln_gal_posn *gal, struct ln_equ_posn *equ);

/**
* \ingroup transform
* \brief Transform an object equatorial coordinates into galactic coordinates.
* \param equ Equatorial position of object
* \param gal Pointer to store galactic position
*
* Conversion valid for B1950.0 epoch.
*/
/* Pg 94 */
void LIBNOVA2_EXPORT ln2_get_gal_from_equ(struct ln_equ_posn *equ, struct ln_gal_posn *gal);

/**
* \ingroup transform
* \brief Transform an object J2000 equatorial coordinates into galactic coordinates.
* \param equ J2000 equatorial position of object
* \param gal Pointer to store galactic position
*/
void LIBNOVA2_EXPORT ln2_get_gal_from_equ2000(struct ln_equ_posn *equ, struct ln_gal_posn *gal);

#ifdef __cplusplus
};
#endif

#endif
