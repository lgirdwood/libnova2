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
 *  Copyright (C) 2000 - 2026 Petr Kubanek
 *  Copyright (C) 2011 - 2026 Petr Kubanek, Institute of Physics <kubanek@fzu.cz>
 */

#include <math.h>
#include <libnova2/airmass.h>
#include <libnova2/utility.h>

/*
** Airmass
*/
double ln2_get_airmass(double alt, double airmass_scale)
{
	double a;

	a = airmass_scale * sin(alt);
	return sqrt(a * a + 2.0 * airmass_scale + 1.0) - a;
}
double ln2_get_alt_from_airmass(double X, double airmass_scale)
{
	return asin((2.0 * airmass_scale + 1.0 - X * X) /
		(2.0 * X * airmass_scale));
}
