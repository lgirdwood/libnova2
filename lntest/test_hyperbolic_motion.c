/*
 * Hyperbolic Motion Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

/* data from Meeus, chapter 35 */
int hyperbolic_motion_test(void) {
  double r, v, dist;
  double e_JD, o_JD;
  struct ln_hyp_orbit orbit;
  struct ln_date epoch_date, obs_date;
  struct ln_equ_posn equ_posn;
  int failed = 0;

  orbit.q = 3.363943;
  orbit.e = 1.05731;

  // the one from Meeus..
  v = ln_get_hyp_true_anomaly(orbit.q, orbit.e, 1237.1);
  failed +=
      test_result("(True Anomaly) v when q is 3.363943 and e is 1.05731   ", v,
                  ln_deg_to_rad(109.40598), 0.00001);

  r = ln_get_hyp_radius_vector(orbit.q, orbit.e, 1237.1);
  failed +=
      test_result("(Radius Vector) r when q is 3.363943 and e is 1.05731  ", r,
                  10.668551, 0.00001);

  // and now something real.. C/2001 Q4 (NEAT)
  obs_date.years = 2004;
  obs_date.months = 5;
  obs_date.days = 15;
  obs_date.hours = 0;
  obs_date.minutes = 0;
  obs_date.seconds = 0;

  epoch_date.years = 2004;
  epoch_date.months = 5;
  epoch_date.days = 15;
  epoch_date.hours = 23;
  epoch_date.minutes = 12;
  epoch_date.seconds = 37.44;

  e_JD = ln_get_julian_day(&epoch_date);
  o_JD = ln_get_julian_day(&obs_date);

  orbit.q = 0.961957;
  orbit.e = 1.000744;
  orbit.i = ln_deg_to_rad(99.6426);
  orbit.w = ln_deg_to_rad(1.2065);
  orbit.omega = ln_deg_to_rad(210.2785);
  orbit.JD = e_JD;

  r = ln_get_hyp_radius_vector(orbit.q, orbit.e, o_JD - e_JD);
  failed +=
      test_result("(Radius Vector) r for C/2001 Q4 (NEAT)   ", r, 0.962, 0.001);

  ln_get_hyp_body_equ_coords(o_JD, &orbit, &equ_posn);
  failed += test_result("(RA) for comet C/2001 Q4 (NEAT)   ",
                        ln_rad_to_deg(equ_posn.ra), 128.01, 0.01);
  failed += test_result("(Dec) for comet C/2001 Q4 (NEAT)   ",
                        ln_rad_to_deg(equ_posn.dec), 18.3266666666, 0.03);

  dist = ln_get_hyp_body_solar_dist(o_JD, &orbit);
  failed += test_result("(Body Solar Dist) for comet C/2001 Q4 (NEAT) in AU   ",
                        dist, 0.962, 0.001);

  obs_date.years = 2005;
  obs_date.months = 1;

  o_JD = ln_get_julian_day(&obs_date);

  r = ln_get_hyp_radius_vector(orbit.q, orbit.e, o_JD - e_JD);
  failed +=
      test_result("(Radius Vector) r for C/2001 Q4 (NEAT)   ", r, 3.581, 0.001);

  ln_get_hyp_body_equ_coords(o_JD, &orbit, &equ_posn);
  failed += test_result("(RA) for comet C/2001 Q4 (NEAT)   ",
                        ln_rad_to_deg(equ_posn.ra), 332.9025, 0.01);
  failed += test_result("(Dec) for comet C/2001 Q4 (NEAT)   ",
                        ln_rad_to_deg(equ_posn.dec), 58.61288090, 0.001);

  return failed;
}
