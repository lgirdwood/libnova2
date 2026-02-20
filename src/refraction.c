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
 *  Copyright (C) 2000 - 2026 Liam Girdwood <lgirdwood@gmail.com>
 */

#include <math.h>
#include <libnova/refraction.h>
#include <libnova/utility.h>
double ln2_get_refraction_adj(double altitude, double atm_pres, double temp)
{
	long double R;

	/* equ 16.3 */
	R = 1.0 / tan(LN_D2R(altitude + (7.31 / (altitude + 4.4))));
	R -= 0.06 * sin(LN_D2R(14.7 * (R / 60.0) + 13.0));

	/* take into account of atm press and temp */
	R *= ((atm_pres / 1010.0) * (283.0 / (273.0 + temp)));
	
	/* convert from arcminutes to degrees */
	R /= 60.0;
	
	return R;
}
