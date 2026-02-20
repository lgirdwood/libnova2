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
 *  Copyright (C) 2000 - 2026 Liam Girdwood  <lgirdwood@gmail.com>
 */
 
#include <math.h>
#include <libnova/angular_separation.h>
#include <libnova/utility.h>	
/* Chap 17 page 115 */
double ln2_get_angular_separation(struct ln_equ_posn* posn1,
	struct ln_equ_posn* posn2)
{
	double d;
	double x,y,z;
	double a1,a2,d1,d2;
	
	/* input is in radians */
	a1 = posn1->ra;
	d1 = posn1->dec;
	a2 = posn2->ra;
	d2 = posn2->dec;
	
	x = (cos(d1) * sin(d2)) 
		- (sin(d1) * cos(d2) * cos(a2 - a1));
	y = cos(d2) * sin(a2 - a1);
	z = (sin(d1) * sin(d2)) + (cos(d1) * cos(d2) * cos(a2 - a1));

	x = x * x;
	y = y * y;
	d = atan2(sqrt(x + y), z);
	
	return d;
}	
/* Chapt 17, page 116 */
double ln2_get_rel_posn_angle(struct ln_equ_posn* posn1,
	struct ln_equ_posn* posn2)
{
	double P;
	double a1,a2,d1,d2;
	double x,y;
	
	/* input is in radians */
	a1 = posn1->ra;
	d1 = posn1->dec;
	a2 = posn2->ra;
	d2 = posn2->dec;
	
	y = sin(a1 - a2);
	x = (cos(d2) * tan(d1)) - (sin(d2) * cos(a1 - a2));
	
	P = atan2(y, x);
	return P;
}
