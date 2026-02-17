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
 *  Copyright (C) 2015 Petr Kubánek 
 */

#ifndef _LN_CONSTELLATION_H
#define _LN_CONSTELLATION_H

#ifdef __cplusplus
extern "C" {
#endif

/*!
* \defgroup constellations Celestial constellations
*
* Functions relating to the 88 modern constellations.
*
* - **Boundaries**: Defined by the International Astronomical Union (IAU) in 1930 (Delporte).
* - **Epoch**: Boundaries are defined for epoch B1875.0, so positions must be precessed to this epoch to determine the constellation correctly.
*/

/**
* \ingroup constellations
* \brief Returns name of the constellation at the given position
* \param position Equatorial position (J2000.0)
* \return Constellation name (abbreviation or full name)
*
* The function handles the precession to B1875.0 internally if required (or assumes input is J2000 and precesses).
* *Note*: This implementation typically checks against a list of boundary coordinates.
*/
const char *LIBNOVA_EXPORT ln_get_constellation(struct ln_equ_posn *position);

#ifdef __cplusplus
};
#endif

#endif
