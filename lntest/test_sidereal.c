/*
 * Sidereal Time Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

int sidereal_test(void) {
  struct ln_date date;
  double sd;
  double JD;
  int failed = 0;

  /* 10/04/1987 19:21:00 */
  date.years = 1987;
  date.months = 4;
  date.days = 10;
  date.hours = 19;
  date.minutes = 21;
  date.seconds = 0.0;

  JD = ln_get_julian_day(&date);
  sd = ln_get_mean_sidereal_time(JD);

  failed += test_result("(Sidereal) mean hours on 10/04/1987 19:21:00 ", sd,
                        8.58252488, 0.000001);
  sd = ln_get_apparent_sidereal_time(JD);
  failed += test_result("(Sidereal) apparent hours on 10/04/1987 19:21:00 ", sd,
                        8.58251295, 0.000001);
  return failed;
}
