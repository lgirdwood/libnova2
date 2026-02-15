/*
 * Hyperbolic Motion Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

/* data from Meeus, chapter 35 */
int hyperbolic_motion_test(void)
{
	double r, v, dist;
	double e_JD, o_JD;
	struct ln_hyp_orbit orbit;
	struct ln_date epoch_date, obs_date;
	struct ln_equ_posn equ_posn;
	int failed = 0;

	orbit = LN_HYP_ORBIT_DEG(3.363943, 1.05731, 0, 0, 0, 0);

	// the one from Meeus..
	v = ln_get_hyp_true_anomaly(orbit.q, orbit.e, 1237.1);
	failed +=
		test_result("(True Anomaly) v when q is 3.363943 and e is 1.05731   ", v, ln_deg_to_rad(109.40598), 0.00001);

	r = ln_get_hyp_radius_vector(orbit.q, orbit.e, 1237.1);
	failed += test_result("(Radius Vector) r when q is 3.363943 and e is 1.05731  ", r, 10.668551, 0.00001);

	// and now something real.. C/2001 Q4 (NEAT)
	obs_date = LN_DATE(2004, 5, 15, 0, 0, 0);

	epoch_date = LN_DATE(2004, 5, 15, 23, 12, 37.44);

	e_JD = ln_get_julian_day(&epoch_date);
	o_JD = ln_get_julian_day(&obs_date);

	orbit = LN_HYP_ORBIT_DEG(0.961957, 1.000744, 99.6426, 1.2065, 210.2785, e_JD);

	r = ln_get_hyp_radius_vector(orbit.q, orbit.e, o_JD - e_JD);
	failed += test_result("(Radius Vector) r for C/2001 Q4 (NEAT)   ", r, 0.962, 0.001);

	ln_get_hyp_body_equ_coords(o_JD, &orbit, &equ_posn);
	failed += test_result("(RA) for comet C/2001 Q4 (NEAT)   ", ln_rad_to_deg(equ_posn.ra), 128.01, 0.01);
	failed += test_result("(Dec) for comet C/2001 Q4 (NEAT)   ", ln_rad_to_deg(equ_posn.dec), 18.3266666666, 0.03);

	dist = ln_get_hyp_body_solar_dist(o_JD, &orbit);
	failed += test_result("(Body Solar Dist) for comet C/2001 Q4 (NEAT) in AU   ", dist, 0.962, 0.001);

	/* obs_date.years = 2005; */
	/* obs_date.months = 1; */
	/* obs_date.days = ??; */
	/* This part seems incomplete or relying on previous values, but let's just
     leave it or fix it if full context allows. Wait, lines 71-72:
     obs_date.years = 2005;
     obs_date.months = 1;
     It reuses days, hours, minutes, seconds from before?
     Previous obs_date was 2004-05-15 00:00:00.
     So this makes it 2005-01-15 00:00:00.
     I should probably not use the macro if it's a partial update unless I
     construct the whole thing. But looking at the code, it seems simpler to
     just set the fields. However, to be consistent with the request "use this
     in ALL tests and examples", I should probably rewrite it to valid full
     initialization if possible, or leave it if it's just a partial update.
     actually, let's look at the code again.
     obs_date is a struct ln_date.
     It was initialized before.
     Now only years and months are updated.
     days, hours, minutes, seconds retain values (15, 0, 0, 0).
     So effectively it is 2005-01-15 00:00:00.
     I can use LN_DATE for this.
  */
	obs_date = LN_DATE(2005, 1, 15, 0, 0, 0);

	o_JD = ln_get_julian_day(&obs_date);

	r = ln_get_hyp_radius_vector(orbit.q, orbit.e, o_JD - e_JD);
	failed += test_result("(Radius Vector) r for C/2001 Q4 (NEAT)   ", r, 3.581, 0.001);

	ln_get_hyp_body_equ_coords(o_JD, &orbit, &equ_posn);
	failed += test_result("(RA) for comet C/2001 Q4 (NEAT)   ", ln_rad_to_deg(equ_posn.ra), 332.9025, 0.01);
	failed += test_result("(Dec) for comet C/2001 Q4 (NEAT)   ", ln_rad_to_deg(equ_posn.dec), 58.61288090, 0.001);

	return failed;
}
