/*
 * Parabolic Motion Tests
 */

#include "libnova/utility.h"
#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

/* need a proper parabolic orbit to properly test */
int parabolic_motion_test(void)
{
	double r, v, dist;
	double e_JD, o_JD;
	struct ln_par_orbit orbit;
	struct ln_rect_posn posn;
	struct ln_date epoch_date, obs_date;
	struct ln_equ_posn equ_posn;
	int failed = 0;

	obs_date = LN_DATE(2003, 1, 11, 0, 0, 0);

	epoch_date = LN_DATE(2003, 1, 29, 0, 6, 37.44);

	e_JD = ln_get_julian_day(&epoch_date);
	o_JD = ln_get_julian_day(&obs_date);

	orbit = LN_PAR_ORBIT_DEG(0.190082, 94.1511, 187.5613, 119.0676, e_JD);

	v = ln_get_par_true_anomaly(orbit.q, o_JD - e_JD);
	failed +=
		test_result("(True Anomaly) v when e is 0.1 and E is 5.5545   ", v, ln_deg_to_rad(247.18968605), 0.00000001);

	r = ln_get_par_radius_vector(orbit.q, o_JD - e_JD);
	failed += test_result("(Radius Vector) r when v is , e is 0.1 and E is 5.5545   ", r, 0.62085992, 0.00000001);

	ln_get_par_geo_rect_posn(&orbit, o_JD, &posn);
	failed += test_result("(Geocentric Rect Coords X) for comet C/2002 X5 (Kudo-Fujikawa)   ", posn.X, 0.29970187,
						  0.00000001);
	failed += test_result("(Geocentric Rect Coords Y) for comet C/2002 X5 (Kudo-Fujikawa)   ", posn.Y, -0.93361510,
						  0.00000001);
	failed += test_result("(Geocentric Rect Coords Z) for comet C/2002 X5 (Kudo-Fujikawa)   ", posn.Z, 0.24641088,
						  0.00000001);

	ln_get_par_helio_rect_posn(&orbit, o_JD, &posn);
	failed += test_result("(Heliocentric Rect Coords X) for comet C/2002 X5 (Kudo-Fujikawa)   ", posn.X, -0.04143700,
						  0.00000001);
	failed += test_result("(Heliocentric Rect Coords Y) for comet C/2002 X5 (Kudo-Fujikawa)   ", posn.Y, -0.08736588,
						  0.00000001);
	failed += test_result("(Heliocentric Rect Coords Z) for comet C/2002 X5 (Kudo-Fujikawa)   ", posn.Z, 0.61328397,
						  0.00000001);

	ln_get_par_body_equ_coords(o_JD, &orbit, &equ_posn);
	failed += test_result("(RA) for comet C/2002 X5 (Kudo-Fujikawa)   ", ln_rad_to_deg(equ_posn.ra), 287.79459742,
						  0.00000001);
	failed += test_result("(Dec) for comet C/2002 X5 (Kudo-Fujikawa)   ", ln_rad_to_deg(equ_posn.dec), 14.11891688,
						  0.00000001);

	dist = ln_get_par_body_solar_dist(o_JD, &orbit);
	failed += test_result("(Body Solar Dist) for comet C/2002 X5 (Kudo-Fujikawa) in AU   ", dist, 0.62085992, 0.00001);

	dist = ln_get_par_body_earth_dist(o_JD, &orbit);
	failed += test_result("(Body Earth Dist) for comet C/2002 X5 (Kudo-Fujikawa) in AU   ", dist, 1.01102754, 0.00001);
	return failed;
}
