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
  date.years = 1987;
  date.months = 4;
  date.days = 10;
  date.hours = 19;
  date.minutes = 21;
  date.seconds = 0.0;

  JD = ln_get_julian_day(&date);
  ln_hequ_to_equ(&hobject, &object);
  ln_hlnlat_to_lnlat(&hobserver, &observer);

  ln_get_hrz_from_equ(&object, &observer, JD, &hrz);
  failed += test_result("(Transforms) Equ to Horiz ALT ",
                        ln_rad_to_deg(hrz.alt), 15.12426274, 0.00000001);
  failed += test_result("(Transforms) Equ to Horiz AZ ", ln_rad_to_deg(hrz.az),
                        68.03429264, 0.00000001);

  ln_get_hrz_from_equ_sidereal_time(
      &object, &observer,
      ln_deg_to_rad(ln_get_apparent_sidereal_time(JD) * 15.0), &hrz);
  ln_get_equ_from_hrz(&hrz, &observer, JD, &object_hrz);
  failed +=
      test_result("(Transforms) Horiz to Equ RA ", ln_rad_to_deg(object_hrz.ra),
                  ln_rad_to_deg(object.ra), 0.00000001);
  failed += test_result("(Transforms) Horiz to Equ DEC ",
                        ln_rad_to_deg(object_hrz.dec),
                        ln_rad_to_deg(object.dec), 0.00000001);

  /* try something close to the pole */
  object.dec = ln_deg_to_rad(90.0);

  ln_get_hrz_from_equ(&object, &observer, JD, &hrz);
  failed += test_result("(Transforms) Equ to Horiz ALT ",
                        ln_rad_to_deg(hrz.alt), 38.9213888888, 0.00000001);
  failed += test_result("(Transforms) Equ to Horiz AZ ", ln_rad_to_deg(hrz.az),
                        180.0, 0.00000001);

  object.dec = ln_deg_to_rad(-90.0);

  ln_get_hrz_from_equ(&object, &observer, JD, &hrz);
  failed += test_result("(Transforms) Equ to Horiz ALT ",
                        ln_rad_to_deg(hrz.alt), -38.9213888888, 0.00000001);
  failed += test_result("(Transforms) Equ to Horiz AZ ", ln_rad_to_deg(hrz.az),
                        0.0, 0.00000001);

  observer.lat *= -1.0;

  ln_get_hrz_from_equ(&object, &observer, JD, &hrz);
  failed += test_result("(Transforms) Equ to Horiz ALT ",
                        ln_rad_to_deg(hrz.alt), 38.9213888888, 0.00000001);
  failed += test_result("(Transforms) Equ to Horiz AZ ", ln_rad_to_deg(hrz.az),
                        0.0, 0.00000001);

  object.dec = ln_deg_to_rad(90.0);

  ln_get_hrz_from_equ(&object, &observer, JD, &hrz);
  failed += test_result("(Transforms) Equ to Horiz ALT ",
                        ln_rad_to_deg(hrz.alt), -38.9213888888, 0.00000001);
  failed += test_result("(Transforms) Equ to Horiz AZ ", ln_rad_to_deg(hrz.az),
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
                        ln_rad_to_deg(ecl.lng), 113.21584591, 0.00000001);
  failed += test_result("(Transforms) Equ to Ecl latitude",
                        ln_rad_to_deg(ecl.lat), 6.68847935, 0.00000001);

  ln_get_equ_from_ecl(&ecl, JD, &equ);
  failed += test_result("(Transforms) Ecl to Equ RA ", ln_rad_to_deg(equ.ra),
                        116.32894167, 0.00000001);
  failed += test_result("(Transforms) Ecl to Equ DEC", ln_rad_to_deg(equ.dec),
                        28.02618333, 0.00000001);

  /* Nova Serpentis 1978 */
  gal.l = ln_deg_to_rad(12.9593);
  gal.b = ln_deg_to_rad(6.0463);

  ln_get_equ_from_gal(&gal, &equ);
  failed += test_result("(Transforms) Gal to Equ RA", ln_rad_to_deg(equ.ra),
                        267.24894132, 0.00000001);
  failed += test_result("(Transforms) Gal to Equ DEC", ln_rad_to_deg(equ.dec),
                        -14.71890083, 0.00000001);

  ln_get_gal_from_equ(&equ, &gal);
  failed += test_result("(Transforms) Equ to Gal b", gal.b,
                        ln_deg_to_rad(6.0463), 0.00000001);
  failed += test_result("(Transforms) Equ to Gal l", gal.l,
                        ln_deg_to_rad(12.9593), 0.00000001);

  // Swift triger 174738

  equ.ra = ln_deg_to_rad(125.2401);
  equ.dec = ln_deg_to_rad(+31.9260);

  ln_get_gal_from_equ2000(&equ, &gal);
  failed += test_result("(Transforms) Equ J2000 to Gal l", gal.l,
                        ln_deg_to_rad(190.54), 0.005);
  failed += test_result("(Transforms) Equ J2000 to Gal b", gal.b,
                        ln_deg_to_rad(31.92), 0.005);

  return failed;
}
