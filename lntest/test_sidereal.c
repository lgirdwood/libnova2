/*
 * Sidereal Time Tests
 */

#include "test_helpers.h"
#include <libnova2/libnova2.h>

int sidereal_test(void)
{
	struct ln_date date;
	double sd;
	double JD;
	int failed = 0;

	/* 10/04/1987 19:21:00 */
	/* 10/04/1987 19:21:00 */
	date = LN_DATE(1987, 4, 10, 19, 21, 0.0);

	JD = ln2_get_julian_day(&date);
	sd = ln2_get_mean_sidereal_time(JD);

	/* 2.24689976 radians */
	failed += test_result_hms("(Sidereal) mean radians on 10/04/1987 19:21:00 ",
	                          sd, 2.24689976, 0.000001);
	sd = ln2_get_apparent_sidereal_time(JD);
	/* 2.24689664 radians */
	failed +=
	    test_result_hms("(Sidereal) apparent radians on 10/04/1987 19:21:00 ",
	                    sd, 2.24689664, 0.000001);
	return failed;
}
