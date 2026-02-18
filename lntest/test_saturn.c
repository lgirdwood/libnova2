#include <libnova/libnova.h>
#include <libnova/saturn.h>
#include "test_helpers.h"

int test_saturn(void)
{
	int failed = 0;
	struct ln_helio_posn helio;
	struct ln_equ_posn equ;
	struct ln_rect_posn rect;
	double dist, val;
	double JD = 2451545.0;

	ln2_get_saturn_helio_coords(JD, &helio);
	failed += test_result("Saturn Helio L", helio.L, 0.797978176403, 1e-6);
	failed += test_result("Saturn Helio B", helio.B, -0.040198608837, 1e-6);
	failed += test_result("Saturn Helio R", helio.R, 9.183848288053, 1e-6);

	ln2_get_saturn_equ_coords(JD, &equ);
	failed += test_result("Saturn Equ RA", equ.ra, 0.676569701411, 1e-6);
	failed += test_result("Saturn Equ Dec", equ.dec, 0.220188858339, 1e-6);

	ln2_get_saturn_rect_helio(JD, &rect);
	failed += test_result("Saturn Rect X", rect.X, 6.406575817362, 1e-6);
	failed += test_result("Saturn Rect Y", rect.Y, 6.174510113950, 1e-6);
	failed += test_result("Saturn Rect Z", rect.Z, 2.274704491565, 1e-6);

	dist = ln2_get_saturn_earth_dist(JD);
	failed += test_result("Saturn Earth Dist", dist, 8.652748861917, 1e-6);

	dist = ln2_get_saturn_solar_dist(JD);
	failed += test_result("Saturn Solar Dist", dist, 9.183848288053, 1e-6);

	val = ln2_get_saturn_magnitude(JD);
	failed += test_result("Saturn Magnitude", val, 0.620893998576, 1e-6);

	val = ln2_get_saturn_disk(JD);
	failed += test_result("Saturn Disk", val, 0.997845396910, 1e-6);

	val = ln2_get_saturn_phase(JD);
	failed += test_result("Saturn Phase", val, 0.092868774282, 1e-6);

	val = ln2_get_saturn_equ_sdiam(JD);
	failed += test_result("Saturn Equ Sdiam", val, 0.000046353635, 1e-8);

	val = ln2_get_saturn_pol_sdiam(JD);
	failed += test_result("Saturn Pol Sdiam", val, 0.000041361360, 1e-8);

	return failed;
}
