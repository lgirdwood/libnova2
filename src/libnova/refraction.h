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

#ifndef _LN_REFRACTION_H
#define _LN_REFRACTION_H

#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup refraction Atmospheric Refraction
*
* Functions relating to Atmospheric Refraction, which causes celestial bodies to appear higher than they actually are.
*
* - **Bennett's Formula**: Used for calculating refraction from apparent altitude (consistent for altitudes > 0).
* - **Saemundsson's Formula**: Used for calculating true altitude from apparent altitude.
*
* All angles are expressed in degrees. Algorithms based on Meeus Chapter 16.
*/

/**
* \brief Calculate the adjustment in altitude of a body due to atmospheric 
* refraction.
* \ingroup refraction
* \param altitude Altitude in degrees (Apparent or True depending on context, usually Apparent for Bennett's)
* \param atm_pres Atmospheric pressure in mbar
* \param temp Temperature in degrees Celsius
* \return Adjustment in altitude in degrees
*
* Result should be added to true altitude to get apparent altitude, or subtracted from apparent to get true.
*/
double LIBNOVA_EXPORT ln2_get_refraction_adj(double altitude, double atm_pres, double temp);

#ifdef __cplusplus
};
#endif

#endif
