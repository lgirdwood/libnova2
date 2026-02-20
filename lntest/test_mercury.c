#include <libnova2/libnova2.h>
#include <libnova2/mercury.h>
#include "test_helpers.h"

int test_mercury(void)
{
	int failed = 0;
	struct ln_helio_posn helio;
	struct ln_equ_posn equ;
	struct ln_rect_posn rect;
	double dist, val;
	double JD = 2451545.0;

	ln2_get_mercury_helio_coords(JD, &helio);
	failed += test_result("Mercury Helio L", helio.L, 4.429323724587, 1e-6);
	failed += test_result("Mercury Helio B", helio.B, -0.052749934007, 1e-6);
	failed += test_result("Mercury Helio R", helio.R, 0.466471475117, 1e-6);

	ln2_get_mercury_equ_coords(JD, &equ);
	failed += test_result("Mercury Equ RA", equ.ra, 4.748733628559, 1e-6);
	failed += test_result("Mercury Equ Dec", equ.dec, -0.426204382900, 1e-6);

	ln2_get_mercury_rect_helio(JD, &rect);
	failed += test_result("Mercury Rect X", rect.X, -0.130104367201, 1e-6);
	failed += test_result("Mercury Rect Y", rect.Y, -0.400592364401, 1e-6);
	failed += test_result("Mercury Rect Z", rect.Z, -0.200485032615, 1e-6);

	dist = ln2_get_mercury_earth_dist(JD);
	failed += test_result("Mercury Earth Dist", dist, 1.415524982431, 1e-6);

	dist = ln2_get_mercury_solar_dist(JD);
	failed += test_result("Mercury Solar Dist", dist, 0.466471475117, 1e-6);

	val = ln2_get_mercury_magnitude(JD);
	failed += test_result("Mercury Magnitude", val, -1.309228633846, 1e-6);

	val = ln2_get_mercury_disk(JD);
	failed += test_result("Mercury Disk", val, 0.974924061866, 1e-6);

	val = ln2_get_mercury_phase(JD);
	failed += test_result("Mercury Phase", val, 0.318046463283, 1e-6);

	val = ln2_get_mercury_sdiam(JD);
	failed += test_result("Mercury Sdiam", val, 0.000011507914, 1e-8);

	return failed;
}
