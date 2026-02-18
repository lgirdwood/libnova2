/*
 * Dynamical Time Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

int dynamical_test(void) {
  struct ln_date date;
  double TD, JD;
  int failed = 0;

  /* Dynamical Time test for 01/01/2000 00:00:00 */
  /* Dynamical Time test for 01/01/2000 00:00:00 */
  date = LN_DATE(2000, 1, 1, 0, 0, 0.0);

  JD = ln2_get_julian_day(&date);
  TD = ln2_get_jde(JD);
  failed += test_result("(Dynamical Time) TD for 01/01/2000 00:00:00", TD,
                        2451544.50073877, 0.000001);
  return failed;
}
