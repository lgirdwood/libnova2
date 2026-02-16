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

#ifndef _LN_LUNAR_H
#define _LN_LUNAR_H

#include <libnova/ln_types.h>

#define LN_LUNAR_STANDART_HORIZON 0.125

#ifdef __cplusplus
extern "C" {
#endif

/*! \defgroup lunar Lunar
*
* Functions relating to the Moon.
*
* - **Theory**: ELP 2000-82B (Ephemeride Lunaire Parisienne) by Chapront-Touze and Chapront.
* - **Accuracy**: High precision, suitable for modern astrometry.
*
* All angles are expressed in degrees. Algorithms based on Meeus Chapter 47.
*/

/*! \fn double ln_get_lunar_sdiam(double JD)
* \brief Calculate the semidiameter of the Moon in arc seconds.
* \ingroup lunar
* \param JD Julian Day
* \return Semidiameter in arc seconds
*/
double LIBNOVA_EXPORT ln_get_lunar_sdiam(double JD);

/*! \fn double ln_get_lunar_rst(double JD, struct ln_lnlat_posn *observer, struct ln_rst_time *rst);
* \brief Calculate the time of rise, set and transit for the Moon.
* \ingroup lunar
* \param JD Julian Day
* \param observer Observer's position
* \param rst Pointer to store rise, set and transit times
* \return 0 for success, 1 for circumpolar, -1 for never rises
*/

int LIBNOVA_EXPORT ln_get_lunar_rst(double JD, struct ln_lnlat_posn *observer, struct ln_rst_time *rst);

/*! \fn void ln_get_lunar_geo_posn(double JD, struct ln_rect_posn *moon, double precision);
* \brief Calculate the rectangular geocentric lunar cordinates.
* \ingroup lunar
* \param JD Julian Day
* \param moon Pointer to store lunar position
* \param precision Calculation precision
*/
/* ELP 2000-82B theory */
void LIBNOVA_EXPORT ln_get_lunar_geo_posn(double JD, struct ln_rect_posn *moon, double precision);

/*! \fn void ln_get_lunar_equ_coords_prec(double JD, struct ln_equ_posn *position, double precision);
* \brief Calculate lunar equatorial coordinates.
* \ingroup lunar
* \param JD Julian Day
* \param position Pointer to store equatorial position
* \param precision Calculation precision
*/
void LIBNOVA_EXPORT ln_get_lunar_equ_coords_prec(double JD, struct ln_equ_posn *position, double precision);

/*! \fn void ln_get_lunar_equ_coords(double JD, struct ln_equ_posn *position);
* \brief Calculate lunar equatorial coordinates.
* \ingroup lunar
* \param JD Julian Day
* \param position Pointer to store equatorial position
*/
void LIBNOVA_EXPORT ln_get_lunar_equ_coords(double JD, struct ln_equ_posn *position);

/*! \fn void ln_get_lunar_ecl_coords(double JD, struct ln_lnlat_posn *position, double precision);
* \brief Calculate lunar ecliptical coordinates.
* \ingroup lunar
* \param JD Julian Day
* \param position Pointer to store ecliptical position
* \param precision Calculation precision
*/
void LIBNOVA_EXPORT ln_get_lunar_ecl_coords(double JD, struct ln_lnlat_posn *position, double precision);

/*! \fn double ln_get_lunar_phase(double JD);
* \brief Calculate the phase angle of the Moon.
* \ingroup lunar
*
* Calculates the angle Sun - Moon - Earth.
* \param JD Julian Day
* \return Phase angle in radians.
*/
double LIBNOVA_EXPORT ln_get_lunar_phase(double JD);

/*! \fn double ln_get_lunar_disk(double JD);
* \brief Calculate the illuminated fraction of the Moons disk
* \ingroup lunar
* \param JD Julian Day
* \return Illuminated fraction of the Moons disk
*/
double LIBNOVA_EXPORT ln_get_lunar_disk(double JD);

/*! \fn double ln_get_lunar_earth_dist(double JD);
* \brief Calculate the distance between the Earth and the Moon.
* \ingroup lunar
* \param JD Julian Day
* \return Distance in km
*/
double LIBNOVA_EXPORT ln_get_lunar_earth_dist(double JD);

/*! \fn double ln_get_lunar_bright_limb(double JD);
* \brief Calculate the position angle of the Moon's bright limb.
* \ingroup lunar
* \param JD Julian Day
* \return The position angle in radians.
*/
double LIBNOVA_EXPORT ln_get_lunar_bright_limb(double JD);

/*! \fn double ln_get_lunar_long_asc_node(double JD);
* \brief Calculate the longitude of the Moon's mean ascending node.
* \ingroup lunar
*
* Calculate the mean longitude of the Moons ascening node
* \param JD Julian Day
* \return Longitude of ascending node in radians.
*/
double LIBNOVA_EXPORT ln_get_lunar_long_asc_node(double JD);

/*! \fn double ln_get_lunar_long_perigee(double JD);
* \brief Calculate the longitude of the Moon's mean perigee.
* \ingroup lunar
*
* Calculate the longitude of the Moon's mean perigee.
* \param JD Julian Day
* \return Longitude of Moons mean perigee in radians.
*/
double LIBNOVA_EXPORT ln_get_lunar_long_perigee(double JD);

/*! \fn double ln_get_lunar_arg_latitude(double JD);
* \brief Calculate the Moon's argument of latitude (mean distance of the Moon from its ascending node)
* \ingroup lunar
*
* Calculate the Moon's argument of latitude (mean distance of the Moon from its ascending node)
* \param JD Julian Day
* \return Moon's argument of latitude in radians
*/
double LIBNOVA_EXPORT ln_get_lunar_arg_latitude(double JD);

/*! \fn void ln_get_lunar_opt_libr_coords(double JD, struct ln_lnlat_posn *position);
* \brief Calculate selenographic optical libration coordinates.
* \ingroup lunar
* \param JD Julian Day
* \param position Pointer to store selenographic coordinates
*/
void LIBNOVA_EXPORT ln_get_lunar_opt_libr_coords(double JD, struct ln_lnlat_posn *position);

/*! \fn void ln_get_lunar_subsolar(double JD, struct ln_lnlat_posn *position);
* \brief Calculate selenographic subsolar point coordinates.
* \ingroup lunar
* \param JD Julian Day
* \param position Pointer to store subsolar coordinates
*/
void LIBNOVA_EXPORT ln_get_lunar_subsolar_coords(double JD, struct ln_lnlat_posn *position);

/*! \fn double ln_lunar_next_phase(double jd, double phase)
* \brief Find next moon phase relative to given time expressed as Julian Day.
* \ingroup lunar
* \param jd Julian Day
* \param phase Phase to search for (0=New Moon, 90=First Quarter, 180=Full Moon, 270=Last Quarter)
* \return Julian Day of next phase
*/
double LIBNOVA_EXPORT ln_lunar_next_phase(double jd, double phase);

/*! \fn double ln_lunar_previous_phase(double jd, double phase)
* \brief Find previous moon phase relative to given time expressed as Julian Day.
* \ingroup lunar
* \param jd Julian Day
* \param phase Phase to search for (0=New Moon, 90=First Quarter, 180=Full Moon, 270=Last Quarter)
* \return Julian Day of previous phase
*/
double LIBNOVA_EXPORT ln_lunar_previous_phase(double jd, double phase);

/*! \fn double ln_lunar_next_apsis(double jd, int mode)
* \brief Find next moon apogee or perigee relative to given time expressed as Julian Day.
* \ingroup lunar
* \param jd Julian Day
* \param mode 1=Apogee, 0=Perigee
* \return Julian Day of next apsis
*/
double LIBNOVA_EXPORT ln_lunar_next_apsis(double jd, int apogee);

/*! \fn double ln_lunar_previous_apsis(double jd, int mode)
* \brief Find previous moon apogee or perigee relative to given time expressed as Julian Day.
* \ingroup lunar
* \param jd Julian Day
* \param mode 1=Apogee, 0=Perigee
* \return Julian Day of previous apsis
*/
double LIBNOVA_EXPORT ln_lunar_previous_apsis(double jd, int apogee);

/*! \fn double ln_lunar_next_node(double jd, int mode)
* \brief Find next moon node relative to given time expressed as Julian Day.
* \ingroup lunar
* \param jd Julian Day
* \param mode 1=Ascending Node, 0=Descending Node
* \return Julian Day of next node
*/
double LIBNOVA_EXPORT ln_lunar_next_node(double jd, int mode);

/*! \fn double ln_lunar_previous_node(double jd, int mode)
* \brief Find previous lunar node relative to given time expressed as Julian Day.
* \ingroup lunar
* \param jd Julian Day
* \param mode 1=Ascending Node, 0=Descending Node
* \return Julian Day of previous node
*/
double LIBNOVA_EXPORT ln_lunar_previous_node(double jd, int mode);

#ifdef __cplusplus
};
#endif

#endif
