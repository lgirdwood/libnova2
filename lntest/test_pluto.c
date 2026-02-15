#include <libnova/libnova.h>
#include <libnova/pluto.h>
#include "test_helpers.h"

int test_pluto(void)
{
	int failed = 0;
	struct ln_helio_posn helio;
	struct ln_equ_posn equ;
	struct ln_rect_posn rect;
	double dist, val;
	double JD = 2451545.0;

	ln_get_pluto_helio_coords(JD, &helio);
	failed += test_result("Pluto Helio L", helio.L, 4.372856997762, 1e-6);
	failed += test_result("Pluto Helio B", helio.B, 0.194804178211, 1e-6);
	failed += test_result("Pluto Helio R", helio.R, 30.223230095144, 1e-6);

	ln_get_pluto_equ_coords(JD, &equ);
	failed += test_result("Pluto Equ RA", equ.ra, 4.388247863702, 1e-6);
	failed += test_result("Pluto Equ Dec", equ.dec, -0.198904985765, 1e-6);

	ln_get_pluto_rect_helio(JD, &rect);
	failed += test_result("Pluto Rect X", rect.X, -9.875333629852, 1e-6);
	failed += test_result("Pluto Rect Y", rect.Y, -27.978857880534, 1e-6);
	failed += test_result("Pluto Rect Z", rect.Z, -5.753688792823, 1e-6);

	dist = ln_get_pluto_earth_dist(JD);
	failed += test_result("Pluto Earth Dist", dist, 31.064429016632, 1e-6);

	dist = ln_get_pluto_solar_dist(JD);
	failed += test_result("Pluto Solar Dist", dist, 30.223230095144, 1e-6);

	val = ln_get_pluto_magnitude(JD);
	failed += test_result("Pluto Magnitude", val, 13.863021264738, 1e-6);

	val = ln_get_pluto_disk(JD);
	failed += test_result("Pluto Disk", val, 0.999930949325, 1e-6);

	val = ln_get_pluto_phase(JD);
	failed += test_result("Pluto Phase", val, 0.016619538376, 1e-6);

	val = ln_get_pluto_sdiam(JD);
	failed += test_result("Pluto Sdiam", val, 0.000000323059, 1e-10);

	return failed;
}
