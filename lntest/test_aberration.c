/*
 * Aberration Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

int aberration_test(void) {
  struct lnh_equ_posn hobject;
  struct ln_equ_posn object, pos;
  struct ln_date date;
  double JD;
  int failed = 0;

  /* object position */
  hobject.ra.hours = 2;
  hobject.ra.minutes = 44;
  hobject.ra.seconds = 12.9747;
  hobject.dec.neg = 0;
  hobject.dec.degrees = 49;
  hobject.dec.minutes = 13;
  hobject.dec.seconds = 39.896;

  /* date */
  /* date */
  date = LN_DATE(2028, 11, 13, 4, 31, 0);

  JD = ln_get_julian_day(&date);

  ln_hequ_to_equ(&hobject, &object);
  ln_get_equ_aber(&object, JD, &pos);
  failed += test_result("(Aberration) RA  ", LN_R2D(pos.ra), 41.06238352,
                        0.00000001);
  failed += test_result("(Aberration) DEC  ", LN_R2D(pos.dec),
                        49.22962359, 0.00000001);
  return failed;
}
