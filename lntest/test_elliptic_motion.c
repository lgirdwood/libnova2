/*
 * Elliptic Motion Tests
 */

#include "libnova/utility.h"
#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

int elliptic_motion_test(void) {
  double r, v, l, V, dist;
  double E, e_JD, o_JD;
  struct ln_ell_orbit orbit;
  struct ln_rect_posn posn;
  struct ln_date epoch_date, obs_date;
  struct ln_equ_posn equ_posn;
  int failed = 0;

  obs_date = LN_DATE(1990, 10, 6, 0, 0, 0);

  epoch_date = LN_DATE(1990, 10, 28, 12, 30, 0);

  e_JD = ln_get_julian_day(&epoch_date);
  o_JD = ln_get_julian_day(&obs_date);

  orbit.JD = e_JD;
  orbit.a = 2.2091404;
  orbit.e = 0.8502196;
  orbit.i = ln_deg_to_rad(11.94525);
  orbit.omega = ln_deg_to_rad(334.75006);
  orbit.w = ln_deg_to_rad(186.23352);
  orbit.n = 0;

  E = ln_solve_kepler(0.1, ln_deg_to_rad(5.0));
  failed += test_result("(Equation of kepler) E when e is 0.1 and M is 5.0   ",
                        E, ln_deg_to_rad(5.554589253872320), 0.000000000001);

  v = ln_get_ell_true_anomaly(0.1, E);
  failed += test_result("(True Anomaly) v when e is 0.1 and E is 5.5545   ", v,
                        ln_deg_to_rad(6.13976152), 0.00000001);

  r = ln_get_ell_radius_vector(0.5, 0.1, E);
  failed +=
      test_result("(Radius Vector) r when v is , e is 0.1 and E is 5.5545   ",
                  r, 0.45023478, 0.00000001);

  ln_get_ell_geo_rect_posn(&orbit, o_JD, &posn);
  failed += test_result("(Geocentric Rect Coords X) for comet Enckle   ",
                        posn.X, 0.72550388, 0.00000001);
  failed += test_result("(Geocentric Rect Coords Y) for comet Enckle   ",
                        posn.Y, -0.28446411, 0.00000001);
  failed += test_result("(Geocentric Rect Coords Z) for comet Enckle   ",
                        posn.Z, -0.27031076, 0.00000001);

  ln_get_ell_helio_rect_posn(&orbit, o_JD, &posn);
  failed += test_result("(Heliocentric Rect Coords X) for comet Enckle   ",
                        posn.X, 0.25017473, 0.00000001);
  failed += test_result("(Heliocentric Rect Coords Y) for comet Enckle   ",
                        posn.Y, 0.48476422, 0.00000001);
  failed += test_result("(Heliocentric Rect Coords Z) for comet Enckle   ",
                        posn.Z, 0.35716517, 0.00000001);

  ln_get_ell_body_equ_coords(o_JD, &orbit, &equ_posn);
  failed += test_result("(RA) for comet Enckle   ", ln_rad_to_deg(equ_posn.ra),
                        158.58060390, 0.00000001);
  failed += test_result("(Dec) for comet Enckle   ",
                        ln_rad_to_deg(equ_posn.dec), 19.13851393, 0.00000001);

  l = ln_get_ell_orbit_len(&orbit);
  failed += test_result("(Orbit Length) for comet Enckle in AU   ", l,
                        10.85028112, 0.00000001);

  V = ln_get_ell_orbit_pvel(&orbit);
  failed += test_result("(Orbit Perihelion Vel) for comet Enckle in kms   ", V,
                        70.43130198, 0.00000001);

  V = ln_get_ell_orbit_avel(&orbit);
  failed += test_result("(Orbit Aphelion Vel) for comet Enckle in kms   ", V,
                        5.70160892, 0.00000001);

  V = ln_get_ell_orbit_vel(o_JD, &orbit);
  failed += test_result("(Orbit Vel JD) for comet Enckle in kms   ", V,
                        48.16148331, 0.00000001);

  dist = ln_get_ell_body_solar_dist(o_JD, &orbit);
  failed += test_result("(Body Solar Dist) for comet Enckle in AU   ", dist,
                        0.65203581, 0.00000001);

  dist = ln_get_ell_body_earth_dist(o_JD, &orbit);
  failed += test_result("(Body Earth Dist) for comet Enckle in AU   ", dist,
                        0.82482945, 0.00000001);

  // TNO http://www.cfa.harvard.edu/mpec/K05/K05O42.html

  obs_date = LN_DATE(2006, 5, 5, 0, 0, 0);

  epoch_date = LN_DATE(2006, 3, 6, 0, 0, 0);

  e_JD = ln_get_julian_day(&epoch_date);
  o_JD = ln_get_julian_day(&obs_date);

  orbit.JD = e_JD;
  orbit.a = 45.7082927;
  orbit.e = 0.1550125;
  orbit.i = ln_deg_to_rad(28.99870);
  orbit.omega = ln_deg_to_rad(79.55499);
  orbit.w = ln_deg_to_rad(296.40937);
  orbit.n = ln_deg_to_rad(0.00318942);

  // MPO refers to Mean anomaly & epoch, we hence need to convert epoch
  // to perihelion pass

  orbit.JD -= ln_deg_to_rad(147.09926) / orbit.n;

  ln_get_ell_body_equ_coords(o_JD, &orbit, &equ_posn);
  failed += test_result("(RA) for TNO K05F09Y   ", ln_rad_to_deg(equ_posn.ra),
                        184.3699999995, 0.001);
  failed += test_result("(Dec) for TNO K05F09Y  ", ln_rad_to_deg(equ_posn.dec),
                        30.3316666666, 0.001);

  return failed;
}
