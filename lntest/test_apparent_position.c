/*
 * Apparent Position Tests
 */

#include "test_helpers.h"
#include <libnova2/libnova2.h>
#include <libnova2/proper_motion.h>
#include <stdio.h>

int apparent_position_test(void) {
  double JD;
  struct lnh_equ_posn hobject, hpm;
  struct ln_equ_posn object, pm, pos;
  int failed = 0;

  /* objects position */
  hobject.ra.hours = 2;
  hobject.ra.minutes = 44;
  hobject.ra.seconds = 12.9747;
  hobject.dec.neg = 0;
  hobject.dec.degrees = 49;
  hobject.dec.minutes = 13;
  hobject.dec.seconds = 39.896;

  /* proper motion of object */
  hpm.ra.hours = 0;
  hpm.ra.minutes = 0;
  hpm.ra.seconds = 0.03425;
  hpm.dec.neg = 1;
  hpm.dec.degrees = 0;
  hpm.dec.minutes = 0;
  hpm.dec.seconds = 0.0895;

  JD = 2462088.69;
  ln2_hequ_to_equ(&hobject, &object);
  ln2_hequ_to_equ(&hpm, &pm);
  ln2_get_apparent_posn(&object, &pm, JD, &pos);

  failed += test_result("(Apparent Position) RA on JD 2462088.69  ",
                        LN_R2D(pos.ra), 41.56039870, 0.00001);
  failed += test_result("(Apparent Position) DEC on JD 2462088.69  ",
                        LN_R2D(pos.dec), 49.34991119, 0.00001);
  return failed;
}
