/*
 * Sidereal Time Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

int sidereal_test(void)
{
	struct ln_date date;
	double sd;
	double JD;
	int failed = 0;

	/* 10/04/1987 19:21:00 */
	/* 10/04/1987 19:21:00 */
	date = LN_DATE(1987, 4, 10, 19, 21, 0.0);

	JD = ln_get_julian_day(&date);
	sd = ln_get_mean_sidereal_time(JD);

	failed += test_result_hms("(Sidereal) mean hours on 10/04/1987 19:21:00 ", sd, 8.58252488, 0.000001);
	sd = ln_get_apparent_sidereal_time(JD);
	failed += test_result_hms("(Sidereal) apparent hours on 10/04/1987 19:21:00 ", sd, 8.58251295, 0.000001);
	return failed;
}
