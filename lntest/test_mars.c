#include <libnova2/libnova2.h>
#include <libnova2/mars.h>
#include "test_helpers.h"

int test_mars(void)
{
	int failed = 0;
	struct ln_helio_posn helio;
	struct ln_equ_posn equ;
	struct ln_rect_posn rect;
	double dist, val;
	double JD = 2451545.0;

	ln2_get_mars_helio_coords(JD, &helio);
	failed += test_result("Mars Helio L", helio.L, 6.273513628573, 1e-6);
	failed += test_result("Mars Helio B", helio.B, -0.024767000164, 1e-6);
	failed += test_result("Mars Helio R", helio.R, 1.391207693716, 1e-6);

	ln2_get_mars_equ_coords(JD, &equ);
	failed += test_result("Mars Equ RA", equ.ra, 5.768703792263, 1e-6);
	failed += test_result("Mars Equ Dec", equ.dec, -0.230041415922, 1e-6);

	ln2_get_mars_rect_helio(JD, &rect);
	failed += test_result("Mars Rect X", rect.X, 1.390715981865, 1e-6);
	failed += test_result("Mars Rect Y", rect.Y, 0.001363394408, 1e-6);
	failed += test_result("Mars Rect Z", rect.Z, -0.036960059447, 1e-6);

	dist = ln2_get_mars_earth_dist(JD);
	failed += test_result("Mars Earth Dist", dist, 1.849603891357, 1e-6);

	dist = ln2_get_mars_solar_dist(JD);
	failed += test_result("Mars Solar Dist", dist, 1.391207693716, 1e-6);

	val = ln2_get_mars_magnitude(JD);
	failed += test_result("Mars Magnitude", val, 0.541140670105, 1e-6);

	val = ln2_get_mars_disk(JD);
	failed += test_result("Mars Disk", val, 0.926471785277, 1e-6);

	val = ln2_get_mars_phase(JD);
	failed += test_result("Mars Phase", val, 0.549197755642, 1e-6);

	val = ln2_get_mars_sdiam(JD);
	failed += test_result("Mars Sdiam", val, 0.000012267102, 1e-8);

	return failed;
}
