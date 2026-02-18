#include <libnova/libnova.h>
#include <libnova/jupiter.h>
#include "test_helpers.h"

int test_jupiter(void)
{
	int failed = 0;
	struct ln_helio_posn helio;
	struct ln_equ_posn equ;
	struct ln_rect_posn rect;
	double dist, val;
	double JD = 2451545.0;

	ln2_get_jupiter_helio_coords(JD, &helio);
	failed += test_result("Jupiter Helio L", helio.L, 0.633436018223, 1e-6);
	failed += test_result("Jupiter Helio B", helio.B, -0.020497775537, 1e-6);
	failed += test_result("Jupiter Helio R", helio.R, 4.965381280274, 1e-6);

	ln2_get_jupiter_equ_coords(JD, &equ);
	failed += test_result("Jupiter Equ RA", equ.ra, 0.416581881921, 1e-6);
	failed += test_result("Jupiter Equ Dec", equ.dec, 0.150022819351, 1e-6);

	ln2_get_jupiter_rect_helio(JD, &rect);
	failed += test_result("Jupiter Rect X", rect.X, 4.001248790611, 1e-6);
	failed += test_result("Jupiter Rect Y", rect.Y, 2.736484869885, 1e-6);
	failed += test_result("Jupiter Rect Z", rect.Z, 1.075485904316, 1e-6);

	dist = ln2_get_jupiter_earth_dist(JD);
	failed += test_result("Jupiter Earth Dist", dist, 4.621126218804, 1e-6);

	dist = ln2_get_jupiter_solar_dist(JD);
	failed += test_result("Jupiter Solar Dist", dist, 4.965381280274, 1e-6);

	val = ln2_get_jupiter_magnitude(JD);
	failed += test_result("Jupiter Magnitude", val, -2.595534898080, 1e-6);

	val = ln2_get_jupiter_disk(JD);
	failed += test_result("Jupiter Disk", val, 0.990756182004, 1e-6);

	val = ln2_get_jupiter_phase(JD);
	failed += test_result("Jupiter Phase", val, 0.192587039860, 1e-6);

	val = ln2_get_jupiter_equ_sdiam(JD);
	failed += test_result("Jupiter Equ Sdiam", val, 0.000103275817, 1e-8);

	val = ln2_get_jupiter_pol_sdiam(JD);
	failed += test_result("Jupiter Pol Sdiam", val, 0.000096582403, 1e-8);

	return failed;
}
