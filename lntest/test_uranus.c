#include <libnova/libnova.h>
#include <libnova/uranus.h>
#include "test_helpers.h"

int test_uranus(void)
{
	int failed = 0;
	struct ln_helio_posn helio;
	struct ln_equ_posn equ;
	struct ln_rect_posn rect;
	double dist, val;
	double JD = 2451545.0;

	ln2_get_uranus_helio_coords(JD, &helio);
	failed += test_result("Uranus Helio L", helio.L, 5.522523433474, 1e-6);
	failed += test_result("Uranus Helio B", helio.B, -0.011937409046, 1e-6);
	failed += test_result("Uranus Helio R", helio.R, 19.924047895209, 1e-6);

	ln2_get_uranus_equ_coords(JD, &equ);
	failed += test_result("Uranus Equ RA", equ.ra, 5.541108980438, 1e-6);
	failed += test_result("Uranus Equ Dec", equ.dec, -0.297027229528, 1e-6);

	ln2_get_uranus_rect_helio(JD, &rect);
	failed += test_result("Uranus Rect X", rect.X, 14.431550962751, 1e-6);
	failed += test_result("Uranus Rect Y", rect.Y, -12.506717547753, 1e-6);
	failed += test_result("Uranus Rect Z", rect.Z, -5.681552385315, 1e-6);

	dist = ln2_get_uranus_earth_dist(JD);
	failed += test_result("Uranus Earth Dist", dist, 20.727185531368, 1e-6);

	dist = ln2_get_uranus_solar_dist(JD);
	failed += test_result("Uranus Solar Dist", dist, 19.924047895209, 1e-6);

	val = ln2_get_uranus_magnitude(JD);
	failed += test_result("Uranus Magnitude", val, 5.889589559486, 1e-6);

	val = ln2_get_uranus_disk(JD);
	failed += test_result("Uranus Disk", val, 0.999805128879, 1e-6);

	val = ln2_get_uranus_phase(JD);
	failed += test_result("Uranus Phase", val, 0.027920156179, 1e-6);

	val = ln2_get_uranus_sdiam(JD);
	failed += test_result("Uranus Sdiam", val, 0.000008191259, 1e-8);

	return failed;
}
