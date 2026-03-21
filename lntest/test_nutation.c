/*
 * Nutation Tests
 */

#include "test_helpers.h"
#include <libnova2/libnova2.h>
#include <stdio.h>

int nutation_test(void)
{
	double JD;
	struct ln_nutation nutation;
	struct ln_date date;

	int failed = 0;

	/* 1987 April 10th at 0h TDT */
	JD = 2446895.5;

	ln2_get_nutation(JD, &nutation);
	failed += test_result_dms("(Nutation) longitude (deg) for JD 2446895.5",
							  LN_R2D(nutation.longitude),
							  -3.788 / (60.0 * 360.0), LN_R2D(0.0000001));

	failed += test_result_dms("(Nutation) obliquity (deg) for JD 2446895.5",
							  LN_R2D(nutation.obliquity),
							  9.443 / (60.0 * 360.0), LN_R2D(0.000001));

	failed += test_result_dms("(Nutation) ecliptic (deg) for JD 2446895.5",
							  LN_R2D(nutation.ecliptic),
							  23.0 + 26.0 / 60.0 + 27.407 / (60.0 * 360.0),
							  LN_R2D(0.000001));

	date = LN_DATE(2028, 11, 13, 4, 33, 36);

	JD = ln2_get_julian_day(&date);

	ln2_get_nutation(JD, &nutation);

	failed += test_result_dms("(Nutation) longitude (deg) for JD 2462088.69",
							  LN_R2D(nutation.longitude),
							  14.861 / (60.0 * 360.0), LN_R2D(0.0000001));

	failed += test_result_dms("(Nutation) obliquity (deg) for JD 2462088.69",
							  LN_R2D(nutation.obliquity),
							  2.705 / (60.0 * 360.0), LN_R2D(0.000001));

	failed += test_result_dms("(Nutation) ecliptic (deg) for JD 2462088.69",
							  LN_R2D(nutation.ecliptic), LN_R2D(0.40899523),
							  LN_R2D(0.000001));

	return failed;
}
