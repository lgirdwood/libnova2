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

#ifndef _LN_NEPTUNE_H
#define _LN_NEPTUNE_H

#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \defgroup neptune Neptune
*
* Functions relating to the planet Neptune.
*
* - **Heliocentric Coordinates**: Calculated using the VSOP87 theory.
*   - **Longitude/Latitude**: In radians.
*   - **Radius Vector**: In Astronomical Units (AU).
*
* - **Physical Ephemeris**: Semidiameter, Magnitude, Phase Angle.
*
* All angles are expressed in radians. Algorithms based on Meeus Chapter 31 (Planets) and 40/41 (magnitude/disk).
*/

/*! \fn double ln_get_neptune_sdiam(double JD)
* \brief Calculate the semidiameter of Neptune in radians.
* \ingroup neptune
* \param JD Julian Day
* \return Semidiameter in radians
*/
double LIBNOVA_EXPORT ln_get_neptune_sdiam(double JD);

/*! \fn double ln_get_neptune_rst(double JD, struct ln_lnlat_posn *observer, struct ln_rst_time *rst);
* \brief Calculate the time of rise, set and transit for Neptune.
* \ingroup neptune
* \param JD Julian Day
* \param observer Observer's position
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*/
int LIBNOVA_EXPORT ln_get_neptune_rst(double JD, struct ln_lnlat_posn *observer, struct ln_rst_time *rst);

/*! \fn void ln_get_neptune_helio_coords(double JD, struct ln_helio_posn *position);
* \brief Calculate Neptune's heliocentric coordinates.
* \ingroup neptune
* \param JD Julian Day
* \param position Pointer to store heliocentric position
*/
/* Chapter 31 Pg 206-207 Equ 31.1 31.2 , 31.3 using VSOP 87 */
void LIBNOVA_EXPORT ln_get_neptune_helio_coords(double JD, struct ln_helio_posn *position);

/*! \fn void ln_get_neptune_equ_coords(double JD, struct ln_equ_posn *position);
* \brief Calculate Neptune's equatorial coordinates.
* \ingroup neptune
* \param JD Julian Day
* \param position Pointer to store equatorial position
*/
/* Chapter 31 Pg 206-207 Equ 31.1 31.2 , 31.3 using VSOP 87 */
void LIBNOVA_EXPORT ln_get_neptune_equ_coords(double JD, struct ln_equ_posn *position);

/*! \fn double ln_get_neptune_earth_dist(double JD);
* \brief Calculate the distance between Neptune and the Earth.
* \ingroup neptune
* \param JD Julian Day
* \return Distance in AU
*/
/* Chapter ?? */
double LIBNOVA_EXPORT ln_get_neptune_earth_dist(double JD);

/*! \fn double ln_get_neptune_solar_dist(double JD);
* \brief Calculate the distance between Neptune and the Sun.
* \ingroup neptune
* \param JD Julian Day
* \return Distance in AU
*/
/* Chapter ?? */
double LIBNOVA_EXPORT ln_get_neptune_solar_dist(double JD);

/*! \fn double ln_get_neptune_magnitude(double JD);
* \brief Calculate the visible magnitude of Neptune.
* \ingroup neptune
* \param JD Julian Day
* \return Visible magnitude of Neptune
*/
/* Chapter ?? */
double LIBNOVA_EXPORT ln_get_neptune_magnitude(double JD);

/*! \fn double ln_get_neptune_disk(double JD);
* \brief Calculate the illuminated fraction of Neptune's disk.
* \ingroup neptune
* \param JD Julian Day
* \return Illuminated fraction of Neptune's disk
*/
/* Chapter 41 */
double LIBNOVA_EXPORT ln_get_neptune_disk(double JD);

/*! \fn double ln_get_neptune_phase(double JD);
* \brief Calculate the phase angle of Neptune.
* \ingroup neptune
* \param JD Julian Day
* \return Phase angle of Neptune (radians)
*/
/* Chapter 41 */
double LIBNOVA_EXPORT ln_get_neptune_phase(double JD);

/*! \fn void ln_get_neptune_rect_helio(double JD, struct ln_rect_posn *position)
* \ingroup neptune
* \brief Calculate Neptunes rectangular heliocentric coordinates.
* \param JD Julian Day
* \param position Pointer to store rectangular position
*/
void LIBNOVA_EXPORT ln_get_neptune_rect_helio(double JD, struct ln_rect_posn *position);

#ifdef __cplusplus
};
#endif

#endif
