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

#ifndef LN_SIDEREAL_TIME_H
#define LN_SIDEREAL_TIME_H

#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \defgroup sidereal Sidereal Time 
*
* Sidereal time is the hour angle of the vernal equinox.
*
* - **Mean Sidereal Time**: Considers only the mean position of the equinox (date).
* - **Apparent Sidereal Time**: Considers the true position of the equinox (date + nutation).
*
* All angles are expressed in hours (previously radians, changed in v0.13+). 
* *Note*: Function return types are double (hours).
*/

/**
* \brief Calculate mean sidereal time at Greenwich from Julian day. 
* \ingroup sidereal
* \param JD Julian Day
* \return Mean sidereal time in hours
*
* Formula based on Meeus Chapter 12.
*/
double LIBNOVA_EXPORT ln_get_mean_sidereal_time(double JD);

/**
* \brief Calculate apparent sidereal time from date.
* \ingroup sidereal
* \param JD Julian Day
* \return Apparent sidereal time in radians
*/

double LIBNOVA_EXPORT ln_get_apparent_sidereal_time(double JD);

#ifdef __cplusplus
};
#endif

#endif
