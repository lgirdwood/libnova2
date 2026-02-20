#include <libnova2/libnova2.h>
#include <libnova2/earth.h>
#include "test_helpers.h"

int test_earth(void)
{
	int failed = 0;
	struct ln_helio_posn helio;
	struct ln_rect_posn rect;
	double dist;
	double JD = 2451545.0;

	ln2_get_earth_helio_coords(JD, &helio);
	failed += test_result("Earth Helio L", helio.L, 1.751898771971, 1e-6);
	failed += test_result("Earth Helio B", helio.B, -0.000016624912, 1e-6);
	failed += test_result("Earth Helio R", helio.R, 0.983327682322, 1e-6);

	ln2_get_earth_rect_helio(JD, &rect);
	failed += test_result("Earth Rect X", rect.X, -0.177111178657, 1e-6);
	failed += test_result("Earth Rect Y", rect.Y, 0.887437422004, 1e-6);
	failed += test_result("Earth Rect Z", rect.Z, 0.384733392332, 1e-6);

	dist = ln2_get_earth_solar_dist(JD);
	failed += test_result("Earth Solar Dist", dist, 0.983327682322, 1e-6);

	/* ln2_get_earth_centre_dist depends on lat/height, tested separately if needed or add check */

	return failed;
}
