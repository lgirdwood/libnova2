/*
 * Parallax Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

int parallax_test(void) {
  int failed = 0;
  struct ln_equ_posn object, parallax;
  struct ln_lnlat_posn observer;
  double JD, AU, H;

  /* Mars 2003 Aug 28 03:17 UT */
  JD = 2452879.63680556;
  AU = 0.37276;
  observer.lat = LN_D2R(33.356111); /* Palomar */
  observer.lng = LN_D2R(116.8625);

  H = ln_get_apparent_sidereal_time(JD);
  H = H - observer.lng;

  object.ra = LN_D2R(339.530208);
  object.dec = LN_D2R(-15.773611);

  ln_get_parallax(&object, AU, &observer, 1706.0, H, &parallax);

  failed += test_result(
      "Mars RA parallax for Palomar observatory at 2003/08/28 3:17 UT ",
      ln_rad_to_deg(parallax.ra), 0.00152849, 0.0001);
  failed += test_result(
      "Mars DEC parallax for Palomar observatory at 2003/08/28 3:17 UT ",
      ln_rad_to_deg(parallax.dec), -0.00614280, 0.0001);

  return failed;
}
