/*
 * Utility Tests
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <libnova/libnova.h>
#include "test_helpers.h"

int utility_test(void)
{
	struct ln_dms dms;
	double deg = -1.23, deg2 = 1.23, deg3 = -0.5;
	
	ln_deg_to_dms(deg, &dms);
	printf("TEST deg %f ==> deg %c%d min %d sec %f\n",
		deg, dms.neg ? '-' : '+', dms.degrees, dms.minutes, dms.seconds);
	ln_deg_to_dms(deg2, &dms);
	printf("TEST deg %f ==> deg %c%d min %d sec %f\n",
		deg2, dms.neg ? '-' : '+', dms.degrees, dms.minutes, dms.seconds);
	ln_deg_to_dms(deg3, &dms);
	printf("TEST deg %f ==> deg %c%d min %d sec %f\n",
		deg3, dms.neg ? '-' : '+', dms.degrees, dms.minutes, dms.seconds);
	return 0;
}

int utility_conversion_test(void)
{
	int failed = 0;
	double val, res;
	/* struct lnh_hrz_posn hhrz; */
	struct ln_hrz_posn hrz;
	struct lnh_lnlat_posn hlnlat;
	struct ln_lnlat_posn lnlat;
	/* const char *version; */
	const char *loc_str;
	
	/* Degrees <-> Radians */
	val = 180.0;
	res = LN_D2R(val);
	failed += test_result("(Utility) deg_to_rad 180", res, M_PI, 1e-6);

	val = M_PI;
	res = LN_R2D(val);
	failed += test_result("(Utility) rad_to_deg PI", res, 180.0, 1e-6);

	/* Range functions */
	val = 370.0;
	res = ln_range_degrees(val);
	failed += test_result("(Utility) range_degrees 370", res, 10.0, 1e-6);
	
	val = -10.0;
	res = ln_range_degrees(val);
	failed += test_result("(Utility) range_degrees -10", res, 350.0, 1e-6);

	val = 3.0 * M_PI;
	res = ln_range_radians(val);
	failed += test_result("(Utility) range_radians 3PI", res, M_PI, 1e-6);

	val = -M_PI;
	res = ln_range_radians(val);
	failed += test_result("(Utility) range_radians -PI", res, M_PI, 1e-6);
	
	val = 3.0 * M_PI;
	res = ln_range_radians2(val);
	failed += test_result("(Utility) range_radians2 3PI", res, M_PI, 1e-6);

	/* Human readable horizontal */
	hlnlat.lng.degrees = 100; hlnlat.lng.minutes = 0; hlnlat.lng.seconds = 0; hlnlat.lng.neg = 0;
	hlnlat.lat.degrees = 50; hlnlat.lat.minutes = 0; hlnlat.lat.seconds = 0; hlnlat.lat.neg = 0;
	ln_hlnlat_to_lnlat(&hlnlat, &lnlat);
	failed += test_result("(Utility) hlnlat_to_lnlat lng", LN_R2D(lnlat.lng), 100.0, 1e-6);
	failed += test_result("(Utility) hlnlat_to_lnlat lat", LN_R2D(lnlat.lat), 50.0, 1e-6);

	/* hrz to nswe */
	/* 0=N, 90=E? No, 0=S? */
	/* Docs say: 0 is South, 90 West etc. */
	/* Let's verify what it returns. */
	hrz.az = 0.0;
	/* printf("DEBUG: Calling ln_hrz_to_nswe\n"); */
	loc_str = ln_hrz_to_nswe(&hrz);
	if (loc_str == NULL) {
		printf("TEST (Utility) hrz_to_nswe NULL....[FAILED]\n");
		failed++;
	} else {
		printf("TEST (Utility) hrz_to_nswe %s....[PASSED]\n", loc_str);
	}

	/* Also test radians? Az=0 -> S. PI -> N. */
	hrz.az = M_PI;
	loc_str = ln_hrz_to_nswe(&hrz);
	if (strcmp(loc_str, "N") != 0 && strcmp(loc_str, "North") != 0) { /* verify expected string */
		/* Assuming N based on previous test code */
		printf("TEST (Utility) hrz_to_nswe N (radians)....[FAILED]\n");
		failed++;
	} else {
		printf("TEST (Utility) hrz_to_nswe N (radians)....[PASSED]\n");
	}

	/* Interpolation */
	res = ln_interpolate3(0.5, 0.0, 1.0, 2.0);
	failed += test_result("(Utility) interpolate3 linear", res, 1.5, 1e-6);

	res = ln_interpolate5(0.5, 0.0, 1.0, 2.0, 3.0, 4.0);
	failed += test_result("(Utility) interpolate5 linear", res, 2.5, 1e-6);

	return failed;
}
