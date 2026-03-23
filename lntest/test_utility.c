/*
 * Utility Tests
 */

#include <stdio.h>
#include <math.h>
#include <libnova2/libnova2.h>
#include "test_helpers.h"

int utility_test(void)
{
	int failed = 0;
	struct ln_dms dms;
	double deg = -1.23, deg2 = 1.23, deg3 = -0.5;
	char buf[256];

	ln2_deg_to_dms(deg, &dms);
	snprintf(buf, sizeof(buf), "deg %c%d min %d sec %f", dms.neg ? '-' : '+',
	         dms.degrees, dms.minutes, dms.seconds);
	failed += test_str_result("(Utility) deg_to_dms -1.23", buf,
	                          "deg -1 min 13 sec 48.000000");

	ln2_deg_to_dms(deg2, &dms);
	snprintf(buf, sizeof(buf), "deg %c%d min %d sec %f", dms.neg ? '-' : '+',
	         dms.degrees, dms.minutes, dms.seconds);
	failed += test_str_result("(Utility) deg_to_dms 1.23", buf,
	                          "deg +1 min 13 sec 48.000000");

	ln2_deg_to_dms(deg3, &dms);
	snprintf(buf, sizeof(buf), "deg %c%d min %d sec %f", dms.neg ? '-' : '+',
	         dms.degrees, dms.minutes, dms.seconds);
	failed += test_str_result("(Utility) deg_to_dms -0.5", buf,
	                          "deg -0 min 30 sec 0.000000");

	return failed;
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
	res = ln2_range_degrees(val);
	failed += test_result("(Utility) range_degrees 370", res, 10.0, 1e-6);

	val = -10.0;
	res = ln2_range_degrees(val);
	failed += test_result("(Utility) range_degrees -10", res, 350.0, 1e-6);

	val = 3.0 * M_PI;
	res = ln2_range_radians(val);
	failed += test_result("(Utility) range_radians 3PI", res, M_PI, 1e-6);

	val = -M_PI;
	res = ln2_range_radians(val);
	failed += test_result("(Utility) range_radians -PI", res, M_PI, 1e-6);

	val = 3.0 * M_PI;
	res = ln2_range_radians2(val);
	failed += test_result("(Utility) range_radians2 3PI", res, M_PI, 1e-6);

	/* Human readable horizontal */
	hlnlat.lng.degrees = 100;
	hlnlat.lng.minutes = 0;
	hlnlat.lng.seconds = 0;
	hlnlat.lng.neg = 0;
	hlnlat.lat.degrees = 50;
	hlnlat.lat.minutes = 0;
	hlnlat.lat.seconds = 0;
	hlnlat.lat.neg = 0;
	ln2_hlnlat_to_lnlat(&hlnlat, &lnlat);
	failed += test_result("(Utility) hlnlat_to_lnlat lng", LN_R2D(lnlat.lng),
	                      100.0, 1e-6);
	failed += test_result("(Utility) hlnlat_to_lnlat lat", LN_R2D(lnlat.lat),
	                      50.0, 1e-6);

	/* hrz to nswe */
	/* 0=N, 90=E? No, 0=S? */
	/* Docs say: 0 is South, 90 West etc. */
	/* Let's verify what it returns. */
	hrz.az = 0.0;
	/* printf("DEBUG: Calling ln_hrz_to_nswe\n"); */
	loc_str = ln_hrz_to_nswe(&hrz);
	failed += test_str_result("(Utility) hrz_to_nswe 0.0",
	                          loc_str ? loc_str : "NULL", "S");

	/* Also test radians? Az=0 -> S. PI -> N. */
	hrz.az = M_PI;
	loc_str = ln_hrz_to_nswe(&hrz);
	failed += test_str_result("(Utility) hrz_to_nswe PI",
	                          loc_str ? loc_str : "NULL", "N");

	/* Interpolation */
	res = ln2_interpolate3(0.5, 0.0, 1.0, 2.0);
	failed += test_result("(Utility) interpolate3 linear", res, 1.5, 1e-6);

	res = ln2_interpolate5(0.5, 0.0, 1.0, 2.0, 3.0, 4.0);
	failed += test_result("(Utility) interpolate5 linear", res, 2.5, 1e-6);

	return failed;
}
