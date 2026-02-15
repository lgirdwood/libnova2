/*
 * Transform Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

int transform_test(void) {
  struct lnh_equ_posn hobject, hpollux;
  struct lnh_lnlat_posn hobserver, hecl;
  struct ln_equ_posn object, object_hrz, pollux, equ;
  struct ln_hrz_posn hrz;
  struct ln_lnlat_posn observer, ecl;
  struct ln_gal_posn gal;
  double JD;
  struct ln_date date;
  int failed = 0;

  /* observers position */
  hobserver.lng.neg = 0;
  hobserver.lng.degrees = 282;
  hobserver.lng.minutes = 56;
  hobserver.lng.seconds = 4.0;
  hobserver.lat.neg = 0;
  hobserver.lat.degrees = 38;
  hobserver.lat.minutes = 55;
  hobserver.lat.seconds = 17.0;

  /* object position */
  hobject.ra.hours = 23;
  hobject.ra.minutes = 9;
  hobject.ra.seconds = 16.641;
  hobject.dec.neg = 1;
  hobject.dec.degrees = 6;
  hobject.dec.minutes = 43;
  hobject.dec.seconds = 11.61;

  /* date and time */
  /* date and time */
  date = LN_DATE(1987, 4, 10, 19, 21, 0.0);

  JD = ln_get_julian_day(&date);
  ln_hequ_to_equ(&hobject, &object);
  ln_hlnlat_to_lnlat(&hobserver, &observer);

  ln_get_hrz_from_equ(&object, &observer, JD, &hrz);
  failed += test_result("(Transforms) Equ to Horiz ALT ",
                        LN_R2D(hrz.alt), 15.12426274, 0.00000001);
  failed += test_result("(Transforms) Equ to Horiz AZ ", LN_R2D(hrz.az),
                        68.03429264, 0.00000001);

  ln_get_hrz_from_equ_sidereal_time(
      &object, &observer,
      LN_D2R(ln_get_apparent_sidereal_time(JD) * 15.0), &hrz);
  ln_get_equ_from_hrz(&hrz, &observer, JD, &object_hrz);
  failed +=
      test_result("(Transforms) Horiz to Equ RA ", LN_R2D(object_hrz.ra),
                  LN_R2D(object.ra), 0.00000001);
  failed += test_result("(Transforms) Horiz to Equ DEC ",
                        LN_R2D(object_hrz.dec),
                        LN_R2D(object.dec), 0.00000001);

  /* try something close to the pole */
  object.dec = LN_D2R(90.0);

  ln_get_hrz_from_equ(&object, &observer, JD, &hrz);
  failed += test_result("(Transforms) Equ to Horiz ALT ",
                        LN_R2D(hrz.alt), 38.9213888888, 0.00000001);
  failed += test_result("(Transforms) Equ to Horiz AZ ", LN_R2D(hrz.az),
                        180.0, 0.00000001);

  object.dec = LN_D2R(-90.0);

  ln_get_hrz_from_equ(&object, &observer, JD, &hrz);
  failed += test_result("(Transforms) Equ to Horiz ALT ",
                        LN_R2D(hrz.alt), -38.9213888888, 0.00000001);
  failed += test_result("(Transforms) Equ to Horiz AZ ", LN_R2D(hrz.az),
                        0.0, 0.00000001);

  observer.lat *= -1.0;

  ln_get_hrz_from_equ(&object, &observer, JD, &hrz);
  failed += test_result("(Transforms) Equ to Horiz ALT ",
                        LN_R2D(hrz.alt), 38.9213888888, 0.00000001);
  failed += test_result("(Transforms) Equ to Horiz AZ ", LN_R2D(hrz.az),
                        0.0, 0.00000001);

  object.dec = LN_D2R(90.0);

  ln_get_hrz_from_equ(&object, &observer, JD, &hrz);
  failed += test_result("(Transforms) Equ to Horiz ALT ",
                        LN_R2D(hrz.alt), -38.9213888888, 0.00000001);
  failed += test_result("(Transforms) Equ to Horiz AZ ", LN_R2D(hrz.az),
                        180.0, 0.00000001);

  /* Equ position of Pollux */
  hpollux.ra.hours = 7;
  hpollux.ra.minutes = 45;
  hpollux.ra.seconds = 18.946;
  hpollux.dec.neg = 0;
  hpollux.dec.degrees = 28;
  hpollux.dec.minutes = 1;
  hpollux.dec.seconds = 34.26;

  ln_hequ_to_equ(&hpollux, &pollux);
  ln_get_ecl_from_equ(&pollux, JD, &ecl);

  ln_lnlat_to_hlnlat(&ecl, &hecl);
  failed += test_result("(Transforms) Equ to Ecl longitude ",
                        LN_R2D(ecl.lng), 113.21584591, 0.00000001);
  failed += test_result("(Transforms) Equ to Ecl latitude",
                        LN_R2D(ecl.lat), 6.68847935, 0.00000001);

  ln_get_equ_from_ecl(&ecl, JD, &equ);
  failed += test_result("(Transforms) Ecl to Equ RA ", LN_R2D(equ.ra),
                        116.32894167, 0.00000001);
  failed += test_result("(Transforms) Ecl to Equ DEC", LN_R2D(equ.dec),
                        28.02618333, 0.00000001);

  /* Nova Serpentis 1978 */
  gal.l = LN_D2R(12.9593);
  gal.b = LN_D2R(6.0463);

  ln_get_equ_from_gal(&gal, &equ);
  failed += test_result("(Transforms) Gal to Equ RA", LN_R2D(equ.ra),
                        267.24894132, 0.00000001);
  failed += test_result("(Transforms) Gal to Equ DEC", LN_R2D(equ.dec),
                        -14.71890083, 0.00000001);

  ln_get_gal_from_equ(&equ, &gal);
  failed += test_result("(Transforms) Equ to Gal b", gal.b,
                        LN_D2R(6.0463), 0.00000001);
  failed += test_result("(Transforms) Equ to Gal l", gal.l,
                        LN_D2R(12.9593), 0.00000001);

  // Swift triger 174738

  equ.ra = LN_D2R(125.2401);
  equ.dec = LN_D2R(+31.9260);

  ln_get_gal_from_equ2000(&equ, &gal);
  failed += test_result("(Transforms) Equ J2000 to Gal l", gal.l,
                        LN_D2R(190.54), 0.005);
  failed += test_result("(Transforms) Equ J2000 to Gal b", gal.b,
                        LN_D2R(31.92), 0.005);

  return failed;
}
