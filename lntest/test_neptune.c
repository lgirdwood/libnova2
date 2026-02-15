#include <libnova/libnova.h>
#include <libnova/neptune.h>
#include "test_helpers.h"

int test_neptune(void)
{
	int failed = 0;
	struct ln_helio_posn helio;
	struct ln_equ_posn equ;
	struct ln_rect_posn rect;
	double dist, val;
	double JD = 2451545.0;

	ln_get_neptune_helio_coords(JD, &helio);
	failed += test_result("Neptune Helio L", helio.L, 5.304537824236, 1e-6);
	failed += test_result("Neptune Helio B", helio.B, 0.004238776196, 1e-6);
	failed += test_result("Neptune Helio R", helio.R, 30.120532933189, 1e-6);

	ln_get_neptune_equ_coords(JD, &equ);
	failed += test_result("Neptune Equ RA", equ.ra, 5.330953553703, 1e-6);
	failed += test_result("Neptune Equ Dec", equ.dec, -0.335310748493, 1e-6);

	ln_get_neptune_rect_helio(JD, &rect);
	failed += test_result("Neptune Rect X", rect.X, 16.811482825073, 1e-6);
	failed += test_result("Neptune Rect Y", rect.Y, -22.980574234805, 1e-6);
	failed += test_result("Neptune Rect Z", rect.Z, -9.824141550015, 1e-6);

	dist = ln_get_neptune_earth_dist(JD);
	failed += test_result("Neptune Earth Dist", dist, 31.024432859629, 1e-6);

	dist = ln_get_neptune_solar_dist(JD);
	failed += test_result("Neptune Solar Dist", dist, 30.120532933189, 1e-6);

	val = ln_get_neptune_magnitude(JD);
	failed += test_result("Neptune Magnitude", val, 7.982832514348, 1e-6);

	val = ln_get_neptune_disk(JD);
	failed += test_result("Neptune Disk", val, 0.999959897626, 1e-6);

	val = ln_get_neptune_phase(JD);
	failed += test_result("Neptune Phase", val, 0.012665371650, 1e-6);

	val = ln_get_neptune_sdiam(JD);
	failed += test_result("Neptune Sdiam", val, 0.000005234990, 1e-8);

	return failed;
}
