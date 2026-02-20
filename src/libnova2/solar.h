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

#ifndef _LN_SOLAR_H
#define _LN_SOLAR_H

#include <libnova/ln_types.h>

#define LN_SOLAR_STANDART_HORIZON -0.8333
#define LN_SOLAR_CIVIL_HORIZON -6.0
#define LN_SOLAR_NAUTIC_HORIZON -12.0
#define LN_SOLAR_ASTRONOMICAL_HORIZON -18.0

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup solar Solar
*
* Calculate solar ecliptical/equatorial coordinates for a given julian date.  
* Accuracy 0.01 arc second error - uses **VSOP87 solution** (Variations Séculaires des Orbites Planétaires).
*
* - **VSOP87**: Complete theory for high precision.
*
* **Horizons**:
* - **Standard**: -0.8333 degrees (refraction + semi-diameter)
* - **Civil**: -6.0 degrees
* - **Nautical**: -12.0 degrees
* - **Astronomical**: -18.0 degrees
*
* All angles are expressed in degrees.
*/

/**
* \brief Return solar rise/set time over local horizon (specified in degrees).
*  \ingroup solar
* \param JD Julian Day
* \param observer Observer's position
* \param horizon Horizon altitude
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*/
int LIBNOVA_EXPORT ln2_get_solar_rst_horizon(double JD,
											struct ln_lnlat_posn *observer,
											double horizon,
											struct ln_rst_time *rst);

/**
* \brief Calculate the time of rise, set and transit for the Sun.
* \ingroup solar
* \param JD Julian Day
* \param observer Observer's position
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*/
int LIBNOVA_EXPORT ln2_get_solar_rst(double JD, struct ln_lnlat_posn *observer,
									struct ln_rst_time *rst);

/**
* \brief Calculate solar geometric coordinates. 
* \ingroup solar 
* \param JD Julian Day
* \param position Pointer to store geometric position
*/
void LIBNOVA_EXPORT ln2_get_solar_geom_coords(double JD,
											 struct ln_helio_posn *position);

/**
* \brief Calculate apparent equatorial coordinates.
* \ingroup solar
* \param JD Julian Day
* \param position Pointer to store equatorial position
*/
void LIBNOVA_EXPORT ln2_get_solar_equ_coords(double JD,
											struct ln_equ_posn *position);

/**
* \brief Calculate apparent ecliptical coordinates.
* \ingroup solar
* \param JD Julian Day
* \param position Pointer to store ecliptical position
*/
void LIBNOVA_EXPORT ln2_get_solar_ecl_coords(double JD,
											struct ln_lnlat_posn *position);

/**
* \brief Calculate geocentric coordinates (rectangular)
* \ingroup solar
* \param JD Julian Day
* \param position Pointer to store rectangular position
*/
void LIBNOVA_EXPORT ln2_get_solar_geo_coords(double JD,
											struct ln_rect_posn *position);

/**
* \param JD Julian day
* \return Semidiameter in arc seconds
*
* Calculate the semidiameter of the Sun in arc seconds for the 
* given julian day.
*/
double LIBNOVA_EXPORT ln2_get_solar_sdiam(double JD);

#ifdef __cplusplus
};
#endif

#endif
