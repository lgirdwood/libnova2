/*
 * Nutation Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

int nutation_test(void) {
  double JD;
  struct ln_nutation nutation;
  struct ln_date date;

  int failed = 0;

  /* 1987 April 10th at 0h TDT */
  JD = 2446895.5;

  ln_get_nutation(JD, &nutation);
  failed += test_result("(Nutation) longitude (deg) for JD 2446895.5",
                        nutation.longitude,
                        ln_deg_to_rad(-3.788 / (60.0 * 360.0)), 0.0000001);

  failed += test_result("(Nutation) obliquity (deg) for JD 2446895.5",
                        nutation.obliquity,
                        ln_deg_to_rad(9.443 / (60.0 * 360.0)), 0.000001);

  failed += test_result(
      "(Nutation) ecliptic (deg) for JD 2446895.5", nutation.ecliptic,
      ln_deg_to_rad(23.0 + 26.0 / 60.0 + 27.407 / (60.0 * 360.0)), 0.000001);

  date = LN_DATE(2028, 11, 13, 4, 33, 36);

  JD = ln_get_julian_day(&date);

  ln_get_nutation(JD, &nutation);

  failed += test_result("(Nutation) longitude (deg) for JD 2462088.69",
                        nutation.longitude,
                        ln_deg_to_rad(14.861 / (60.0 * 360.0)), 0.0000001);

  failed += test_result("(Nutation) obliquity (deg) for JD 2462088.69",
                        nutation.obliquity,
                        ln_deg_to_rad(2.705 / (60.0 * 360.0)), 0.000001);

  failed += test_result("(Nutation) ecliptic (deg) for JD 2462088.69",
                        nutation.ecliptic, 0.40899523, 0.000001);

  return failed;
}
