#include <libnova2/libnova2.h>
#include <libnova2/venus.h>
#include "test_helpers.h"

int test_venus(void)
{
	int failed = 0;
	struct ln_helio_posn helio;
	struct ln_equ_posn equ;
	struct ln_rect_posn rect;
	double dist, val;
	double JD = 2451545.0;

	ln2_get_venus_helio_coords(JD, &helio);
	failed += test_result("Venus Helio L", helio.L, 3.186996451320, 1e-6);
	failed += test_result("Venus Helio B", helio.B, 0.056967912384, 1e-6);
	failed += test_result("Venus Helio R", helio.R, 0.720212924847, 1e-6);

	ln2_get_venus_equ_coords(JD, &equ);
	failed += test_result("Venus Equ RA", equ.ra, 4.187024301976, 1e-6);
	failed += test_result("Venus Equ Dec", equ.dec, -0.322032848138, 1e-6);

	ln2_get_venus_rect_helio(JD, &rect);
	failed += test_result("Venus Rect X", rect.X, -0.718303542252, 1e-6);
	failed += test_result("Venus Rect Y", rect.Y, -0.046254654975, 1e-6);
	failed += test_result("Venus Rect Z", rect.Z, 0.024641128166, 1e-6);

	dist = ln2_get_venus_earth_dist(JD);
	failed += test_result("Venus Earth Dist", dist, 1.137689108561, 1e-6);

	dist = ln2_get_venus_solar_dist(JD);
	failed += test_result("Venus Solar Dist", dist, 0.720212924847, 1e-6);

	val = ln2_get_venus_magnitude(JD);
	failed += test_result("Venus Magnitude", val, -4.831400020325, 1e-6);

	val = ln2_get_venus_disk(JD);
	failed += test_result("Venus Disk", val, 0.758156009963, 1e-6);

	val = ln2_get_venus_phase(JD);
	failed += test_result("Venus Phase", val, 1.028257367122, 1e-6);

	val = ln2_get_venus_sdiam(JD);
	failed += test_result("Venus Sdiam", val, 0.000035838289, 1e-8);

	return failed;
}
