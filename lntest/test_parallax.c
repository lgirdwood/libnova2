/*
 * Parallax Tests
 */

#include "libnova/utility.h"
#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

int parallax_test(void)
{
	int failed = 0;
	struct ln_equ_posn object, parallax;
	struct ln_lnlat_posn observer;
	double JD, AU;

	/* Mars 2003 Aug 28 03:17 UT */
	JD = 2452879.63680556;
	AU = 0.37276;
	observer.lat = LN_D2R(33.356111); /* Palomar */
	observer.lng = LN_D2R(116.8625);

	object.ra = LN_D2R(339.530208);
	object.dec = LN_D2R(-15.773611);

	ln2_get_parallax(&object, AU, &observer, 1706.0, JD, &parallax);

	failed += test_result_dms("Mars RA parallax for Palomar observatory at 2003/08/28 3:17 UT ", LN_R2D(parallax.ra),
							  0.0053917, 0.001);
	failed += test_result_dms("Mars DEC parallax for Palomar observatory at 2003/08/28 3:17 UT ", LN_R2D(parallax.dec),
							  -9.0 / 3600.0, 0.001);

	return failed;
}
