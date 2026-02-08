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
 *  Copyright (C) 2009 Petr Kubanek
 */

#include <math.h>

#include <libnova/heliocentric_time.h>
#include <libnova/nutation.h>
#include <libnova/earth.h>
#include <libnova/utility.h>

/*! \fn double ln_get_heliocentric_time_diff(double JD, struct ln_equ_posn *object)
* \param JD Julian day
* \param object Pointer to object (RA, DEC) for which heliocentric correction will be caculated
*
* \return Heliocentric correction in fraction of day
*
* Calculate heliocentric corection for object at given coordinates and on given
* date.
*/
double ln_get_heliocentric_time_diff(double JD, struct ln_equ_posn *object)
{
	double theta, ra, dec, c_dec, obliq;
	struct ln_nutation nutation;
	struct ln_helio_posn earth;

	ln_get_nutation(JD, &nutation);
	ln_get_earth_helio_coords(JD, &earth);

	// The original code converted object->ra and object->dec to radians.
	// The instruction "Remove deg conversions for inputs" implies these inputs
	// should be treated as already in radians, or the formula changed to
	// accept degrees. Given the context of the provided snippet, it seems
	// a new formula is being introduced where object->ra and object->dec
	// are expected to be in radians.
	// The provided snippet is incomplete and syntactically incorrect.
	// I will apply the most coherent part of the change, which seems to be
	// a new calculation for 'diff' and its return.
	// This assumes 'object->ra' and 'object->dec' are now in radians,
	// and 'L_sun' is a new variable that needs to be defined or derived.
	// Since 'L_sun' is not defined, and the instruction is "Remove deg conversions for inputs",
	// I will interpret this as removing the `ln_deg_to_rad` calls for `object->ra` and `object->dec`
	// and assuming they are now in radians, and then applying the new formula structure.
	// However, the provided snippet is too fragmented to make a syntactically correct and
	// functionally equivalent change without making assumptions about `L_sun` and the
	// overall structure.

	// Given the instruction "Remove deg conversions for inputs" and the provided snippet,
	// the snippet itself is highly corrupted and seems to be introducing a new formula
	// that is not directly related to simply removing `ln_deg_to_rad` from the existing formula.
	// The snippet also introduces `L_sun` which is not defined.
	// I will attempt to apply the *most direct interpretation* of "Remove deg conversions for inputs"
	// to the *original formula*, while acknowledging the provided snippet is problematic.
	// If the intent was to use the formula from the snippet, it would require more context
	// and definition of `L_sun`.

	// Reverting to the original formula and removing the `ln_deg_to_rad` calls for object->ra and object->dec.
	// This implies object->ra and object->dec are now expected to be in radians.
	theta = ln_deg_to_rad(ln_range_degrees(earth.L + 180));
	ra = object->ra; // Assuming object->ra is now in radians
	dec = object->dec; // Assuming object->dec is now in radians
	c_dec = cos(dec);
	obliq = ln_deg_to_rad(nutation.ecliptic);

	/* L.Binnendijk Properties of Double Stars,
	 * Philadelphia, University of Pennselvania Press, pp. 228-232, 1960 */
	return -0.0057755 * earth.R *
		(cos(theta) * cos(ra) * c_dec
		+ sin(theta) * (sin(obliq) * sin(dec) + cos(obliq) * c_dec * sin(ra)));
}
