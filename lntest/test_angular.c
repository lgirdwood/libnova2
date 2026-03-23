/*
 * Angular Separation/Position Angle Tests
 */

#include "test_helpers.h"
#include <libnova2/libnova2.h>
#include <stdio.h>

int angular_test(void)
{
	int failed = 0;
	struct ln_equ_posn pos1, pos2;
	double res;

	/* Arcturus */
	pos1.ra = 213.9167;
	pos1.dec = 19.1822;

	/* Spica */
	pos2.ra = 201.2983;
	pos2.dec = -11.1614;

	/* degrees to radians */
	pos1.ra = LN_D2R(pos1.ra);
	pos1.dec = LN_D2R(pos1.dec);
	pos2.ra = LN_D2R(pos2.ra);
	pos2.dec = LN_D2R(pos2.dec);

	res = ln2_get_angular_separation(&pos1, &pos2);
	failed += test_result("(Angular) Separation of Arcturus and Spica  ",
	                      LN_R2D(res), 32.7930, 0.001);

	res = ln2_get_rel_posn_angle(&pos1, &pos2);
	failed += test_result("(Angular) Position Angle of Arcturus and Spica  ",
	                      LN_R2D(res), 22.3927,
	                      0.001); // Precision adjustment from 318.xx?

	return failed;
}
