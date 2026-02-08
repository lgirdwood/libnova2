/*
 * Dynamical Time Tests
 */

#include <stdio.h>
#include <libnova/libnova.h>
#include "test_helpers.h"

int dynamical_test(void)
{
	struct ln_date date;
	double TD,JD;
	int failed = 0;
 
	/* Dynamical Time test for 01/01/2000 00:00:00 */
	date.years = 2000;
	date.months = 1;
	date.days = 1;
	date.hours = 0;
	date.minutes = 0;
	date.seconds = 0.0;

	JD = ln_get_julian_day(&date);
	TD = ln_get_jde(JD);
	failed += test_result("(Dynamical Time) TD for 01/01/2000 00:00:00",
		TD, 2451544.50073877, 0.000001);
	return failed;
}
