/*
 * Heliocentric Time Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

int heliocentric_test(void) {
  struct ln_equ_posn object;
  struct ln_date date;
  double JD;
  double diff;
  int failed = 0;

  object.ra = 0.0;
  object.dec = LN_D2R(60.0);

  date = LN_DATE(2000, 1, 1, 0, 0, 0.0);

  JD = ln2_get_julian_day(&date);

  diff = ln2_get_heliocentric_time_diff(JD, &object);

  failed += test_result("(Heliocentric time) TD for 01/01, object on 0h +60",
                        diff, 15.0 * 0.0001, 0.0001);

  object.ra = LN_D2R(270.0);
  object.dec = LN_D2R(50.0);

  diff = ln2_get_heliocentric_time_diff(JD, &object);

  failed += test_result("(Heliocentric time) TD for 01/01, object on 18h +50",
                        diff, -16.0 * 0.0001, 0.0001);

  date = LN_DATE(2000, 8, 8, 0, 0, 0.0);

  JD = ln2_get_julian_day(&date);

  diff = ln2_get_heliocentric_time_diff(JD, &object);

  failed += test_result("(Heliocentric time) TD for 08/08, object on 18h +50",
                        diff, 12.0 * 0.0001, 0.0001);

  return failed;
}
