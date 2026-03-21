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

#ifndef _LN_ANGULAR_SEPARATION_H
#define _LN_ANGULAR_SEPARATION_H

#include <libnova2/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup angular Angular Separation
*
* Functions relating to the angular separation and position angle between 2 bodies.
*
* - **Angular Separation**: The shortest apparent distance on the celestial sphere.
* - **Position Angle**: Angle measured eastward from the North Celestial Pole to the object.
*
* All angles are expressed in degrees. Algorithms based on Meeus Chapter 17.
*/

/**
* \brief Calculate the angular separation between 2 bodies
* \ingroup angular
* \param posn1 Position of first body
* \param posn2 Position of second body
* \return Angular separation in degrees
*
* Uses the spherical cosine formula or Haversine formula for better precision at small angles (Meeus Formula 17.1).
*/
double LIBNOVA2_EXPORT ln2_get_angular_separation(struct ln_equ_posn *posn1,
												  struct ln_equ_posn *posn2);

/**
* \brief Calculate the relative position angle between 2 bodies
* \ingroup angular
* \param posn1 Position of first body
* \param posn2 Position of second body
* \return Position angle in degrees
*
* The angle is measured counter-clockwise (East) from North.
*/
double LIBNOVA2_EXPORT ln2_get_rel_posn_angle(struct ln_equ_posn *posn1,
											  struct ln_equ_posn *posn2);

#ifdef __cplusplus
};
#endif

#endif
