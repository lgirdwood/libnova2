/*
 * Nutation Tests
 */

#include <stdio.h>
#include <libnova/libnova.h>
#include "test_helpers.h"

int nutation_test(void)
{
	double JD;
	struct ln_nutation nutation;
	struct ln_date date;

	int failed = 0;
		
	JD = 2446895.5;

	ln_get_nutation(JD, &nutation);
	failed += test_result("(Nutation) longitude (deg) for JD 2446895.5",
		nutation.longitude, -3.788 / 3600.0, 0.0000001);
	
	failed += test_result("(Nutation) obliquity (deg) for JD 2446895.5",
		nutation.obliquity, 9.443 / 3600.0, 0.000001);
	
	failed += test_result("(Nutation) ecliptic (deg) for JD 2446895.5",
		nutation.ecliptic, 23 + 26 / 60.0 + 27.407 / 3600.0, 0.000001);

	date.years = 2028;
	date.months = 11;
	date.days = 13;
	date.hours = 4;
	date.minutes = 33;
	date.seconds = 36;

	JD = ln_get_julian_day(&date);

	ln_get_nutation(JD, &nutation);

	failed += test_result("(Nutation) longitude (deg) for JD 2446895.5",
		nutation.longitude, 14.861 / 3600.0, 0.0000001);

	failed += test_result("(Nutation) obliquity (deg) for JD 2446895.5",
		nutation.obliquity, 2.705 / 3600.0, 0.000001);

	failed += test_result("(Nutation) ecliptic (deg) for JD 2446895.5",
		nutation.ecliptic, 23.436, 0.001);

	return failed;
}
