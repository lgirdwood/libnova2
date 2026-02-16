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

#ifndef _LN_DYNAMICAL_TIME_H
#define _LN_DYNAMICAL_TIME_H

#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
* \defgroup dynamical Dynamical Time
*
* Functions relating to Dynamical Time (TD), which is the uniform time scale used in the ephemerides.
*
* - **Delta T (\f$ \Delta T \f$)**: The difference between Dynamical Time (TD) and Universal Time (UT).
*   - \f$ \Delta T = TD - UT \f$
*   - It accounts for the non-uniform rotation of the Earth.
*
* All angles are expressed in degrees. Algorithms based on Meeus Chapter 10.
*/

/*! \fn double ln_get_dynamical_time_diff(double JD)
* \ingroup dynamical
* \brief Calculate approximate dynamical time difference from Julian day in seconds
* \param JD Julian Day (UT)
* \return Dynamical time difference (\f$ \Delta T \f$) in seconds
*
* Uses polynomial approximations to estimate \f$ \Delta T \f$ for the given date.
*/
double LIBNOVA_EXPORT ln_get_dynamical_time_diff(double JD);

/*! \fn double ln_get_jde(double JD)
* \brief Calculate Julian Ephemeris Day (JDE)
* \ingroup dynamical 
* \param JD Julian Day (UT)
* \return Julian Ephemeris Day (JDE = JD + \f$ \Delta T \f$ / 86400)
*/
double LIBNOVA_EXPORT ln_get_jde(double JD);

#ifdef __cplusplus
};
#endif

#endif
