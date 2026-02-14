/*
 * RST Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

int rst_test(void) {
  struct ln_lnlat_posn observer;
  struct ln_rst_time rst;
  struct ln_hms hms;
  struct ln_dms dms;
  struct ln_date date;
  struct ln_equ_posn object;
  double JD, JD_next;
  int ret;
  int failed = 0;

  /* Venus on 1988 March 20 at Boston */
  date.years = 1988;
  date.months = 3;
  date.days = 20;

  date.hours = 0;
  date.minutes = 0;
  date.seconds = 0;

  JD = ln_get_julian_day(&date);

  observer.lng = ln_deg_to_rad(-71.0833);
  observer.lat = ln_deg_to_rad(42.3333);

  ret = ln_get_venus_rst(JD, &observer, &rst);
  failed +=
      test_result("Venus sometime rise on 1988/03/20 at Boston", ret, 0, 0);

  if (!ret) {
    ln_get_date(rst.rise, &date);
    failed += test_result("Venus rise hour on 1988/03/20 at Boston", date.hours,
                          12, 0);
    failed += test_result("Venus rise minute on 1988/03/20 at Boston",
                          date.minutes, 25, 0);

    ln_get_date(rst.transit, &date);
    failed += test_result("Venus transit hour on 1988/03/20 at Boston",
                          date.hours, 19, 0);
    failed += test_result("Venus transit minute on 1988/03/20 at Boston",
                          date.minutes, 41, 0);

    ln_get_date(rst.set, &date);
    failed +=
        test_result("Venus set hour on 1988/03/20 at Boston", date.hours, 2, 0);
    failed += test_result("Venus set minute on 1988/03/20 at Boston",
                          date.minutes, 55, 0);
  }

  return failed;
}

int ell_rst_test(void) {
  struct ln_lnlat_posn observer;
  struct ln_ell_orbit orbit;
  struct ln_date date;
  struct ln_rst_time rst;
  struct ln_equ_posn pos;
  double JD;
  int ret;
  int failed = 0;

  /* Comment C/1996 B2 (Hyakutake) somewhere at Japan */

  observer.lng = ln_deg_to_rad(135.0);
  observer.lat = ln_deg_to_rad(35.0);

  date.years = 1996;
  date.months = 5;
  date.days = 1;

  date.hours = 0;
  date.minutes = 0;
  date.seconds = 0.0;

  orbit.JD = ln_get_julian_day(&date);
  orbit.JD += 0.39481;
  orbit.a = 1014.2022026431;
  orbit.e = 0.9997730;
  orbit.i = 124.92379;
  orbit.omega = 188.04546;
  orbit.w = 130.17654;
  orbit.n = 0.0;

  date.years = 1996;
  date.months = 3;
  date.days = 24;

  date.hours = date.minutes = 0;
  date.seconds = 0.0;

  JD = ln_get_julian_day(&date);

  ln_get_ell_body_equ_coords(JD, &orbit, &pos);
  failed += test_result("(RA) for Hyakutake 1996/03/28 00:00", pos.ra, 220.8554,
                        0.001);
  failed += test_result("(Dec) for Hyakutake 1996/03/28 00:00", pos.dec,
                        36.5341, 0.001);

  date.days = 28;

  date.hours = 10;
  date.minutes = 42;

  JD = ln_get_julian_day(&date);

  ln_get_ell_body_equ_coords(JD, &orbit, &pos);
  failed += test_result("(RA) for Hyakutake 1996/03/28 10:42", pos.ra, 56.2140,
                        0.001);
  failed += test_result("(Dec) for Hyakutake 1996/03/28 10:42", pos.dec,
                        75.4925, 0.001);

  ret = ln_get_ell_body_rst(JD, &observer, &orbit, &rst);
  if (!ret) {
    ln_get_date(rst.rise, &date);
    failed +=
        test_result("Hyakutake rise hour on 1996/05/28 somewhere in Japan",
                    date.hours, 17, 0);
    failed +=
        test_result("Hyakutake rise minute on 1996/05/28 somewhere in Japan",
                    date.minutes, 24, 0);

    ln_get_date(rst.transit, &date);
    failed +=
        test_result("Hyakutake transit hour on 1996/05/28 somewhere in Japan",
                    date.hours, 10, 0);
    failed +=
        test_result("Hyakutake transit minute on 1996/05/28 somewhere in Japan",
                    date.minutes, 29, 0);

    ln_get_date(rst.set, &date);
    failed += test_result("Hyakutake set hour on 1996/05/29 somewhere in Japan",
                          date.hours, 3, 0);
    failed +=
        test_result("Hyakutake set minute on 1996/05/29 somewhere in Japan",
                    date.minutes, 35, 0);
  } else {
    failed += test_result("Hyakutake rise somewhere in Japan", ret, 0, 0);
  }

  return failed;
}

int hyp_future_rst_test(void) {
  struct ln_lnlat_posn observer;
  struct ln_hyp_orbit orbit;
  struct ln_date date;
  struct ln_rst_time rst;
  double JD;
  int ret;
  int failed = 0;

  observer.lng = ln_deg_to_rad(15.0);
  observer.lat = ln_deg_to_rad(50.0);

  /* C/2006 P1 (McNaught) */

  orbit.q = 0.170742005109787;
  orbit.e = 1.00001895427704;
  orbit.i = 77.8348999023438;
  orbit.w = 155.977096557617;
  orbit.omega = 267.414398193359;
  orbit.JD = 2454113.251;

  date.years = 2007;
  date.months = 1;
  date.days = 17;

  date.hours = 12;
  date.minutes = 0;
  date.seconds = 0.0;

  JD = ln_get_julian_day(&date);

  ret = ln_get_hyp_body_next_rst_horizon(JD, &observer, &orbit, 0, &rst);
  failed += test_result("McNaught rise on 2997/01/18 at 15 E, 50 N", ret, 0, 0);

  if (!ret) {
    ln_get_date(rst.rise, &date);
    failed += test_result("McNaught rise hour on 2007/01/18 at 15 E, 50 N",
                          date.hours, 9, 0);
    failed += test_result("McNaught rise minute on 2007/01/18 at 15 E, 50 N",
                          date.minutes, 6, 0);

    ln_get_date(rst.transit, &date);
    failed += test_result("McNaught transit hour on 2007/01/18 at 15 E, 50 N",
                          date.hours, 11, 0);
    failed += test_result("McNaught transit minute on 2007/01/18 at 15 E, 50 N",
                          date.minutes, 38, 0);

    ln_get_date(rst.set, &date);
    failed += test_result("McNaught set hour on 2007/01/17 at 15 E, 50 N",
                          date.hours, 14, 0);
    failed += test_result("McNaught set minute on 2007/01/17 at 15 E, 50 N",
                          date.minutes, 37, 0);
  }

  ret = ln_get_hyp_body_next_rst_horizon(JD, &observer, &orbit, 15, &rst);
  failed += test_result("McNaught does not rise above 15 degrees on"
                        "2007/01/17 at 15 E, 50 N",
                        ret, -1, 0);

  return failed;
}

int body_future_rst_test(void) {
  struct ln_lnlat_posn observer;
  struct ln_date date;
  struct ln_rst_time rst;
  double JD;
  int ret;
  int failed = 0;

  observer.lng = ln_deg_to_rad(0.0);
  observer.lat = ln_deg_to_rad(85.0);

  date.years = 2006;
  date.months = 1;
  date.days = 1;

  date.hours = date.minutes = 0;
  date.seconds = 0.0;

  JD = ln_get_julian_day(&date);

  ret = ln_get_body_next_rst_horizon_future(
      JD, &observer, ln_get_solar_equ_coords, LN_SOLAR_STANDART_HORIZON, 300,
      &rst);

  failed += test_result("Sun is above horizon sometimes at 0, 85 N", ret, 0, 0);

  if (!ret) {
    ln_get_date(rst.rise, &date);
    failed +=
        test_result("Solar next rise years at 0, 85 N", date.years, 2006, 0);
    failed +=
        test_result("Solar next rise months at 0, 85 N", date.months, 3, 0);
    failed += test_result("Solar next rise days at 0, 85 N", date.days, 7, 0);
    failed += test_result("Solar next rise hour at 0, 85 N", date.hours, 10, 0);
    failed +=
        test_result("Solar next rise minute at 0, 85 N", date.minutes, 19, 0);

    ln_get_date(rst.transit, &date);
    failed +=
        test_result("Solar next transit years at 0, 85 N", date.years, 2006, 0);
    failed +=
        test_result("Solar next transit months at 0, 85 N", date.months, 3, 0);
    failed +=
        test_result("Solar next transit days at 0, 85 N", date.days, 7, 0);
    failed +=
        test_result("Solar next transit hour at 0 E, 85 N", date.hours, 12, 0);
    failed += test_result("Solar next transit minute at 0 E, 85 N",
                          date.minutes, 10, 0);

    ln_get_date(rst.set, &date);
    failed +=
        test_result("Solar next set years at 0, 85 N", date.years, 2006, 0);
    failed +=
        test_result("Solar next set months at 0, 85 N", date.months, 3, 0);
    failed += test_result("Solar next set days at 0, 85 N", date.days, 7, 0);
    failed +=
        test_result("Solar next set hour at 0 E, 85 N", date.hours, 14, 0);
    failed +=
        test_result("Solar next set minute at 0, 85 N", date.minutes, 8, 0);
  }

  ret = ln_get_body_next_rst_horizon_future(
      JD, &observer, ln_get_solar_equ_coords, 0, 300, &rst);
  failed +=
      test_result("Sun is above 0 horizon sometimes at 0, 85 N", ret, 0, 0);

  if (!ret) {
    ln_get_date(rst.rise, &date);
    failed += test_result("Solar next rise years at 0, 85 N with 0 horizon",
                          date.years, 2006, 0);
    failed += test_result("Solar next rise months at 0, 85 N with 0 horizon",
                          date.months, 3, 0);
    failed += test_result("Solar next rise days at 0, 85 N with 0 horizon",
                          date.days, 9, 0);
    failed += test_result("Solar next rise hour at 0, 85 N with 0 horizon",
                          date.hours, 10, 0);
    failed += test_result("Solar next rise minute at 0, 85 N with 0 horizon",
                          date.minutes, 23, 0);

    ln_get_date(rst.transit, &date);
    failed += test_result("Solar next transit years at 0, 85 N with 0 horizon",
                          date.years, 2006, 0);
    failed += test_result("Solar next transit months at 0, 85 N with 0 horizon",
                          date.months, 3, 0);
    failed += test_result("Solar next transit days at 0, 85 N with 0 horizon",
                          date.days, 9, 0);
    failed += test_result("Solar next transit hour at 0 E, 85 N with 0 horizon",
                          date.hours, 12, 0);
    failed +=
        test_result("Solar next transit minute at 0 E, 85 N with 0 horizon",
                    date.minutes, 10, 0);

    ln_get_date(rst.set, &date);
    failed += test_result("Solar next set years at 0, 85 N with 0 horizon",
                          date.years, 2006, 0);
    failed += test_result("Solar next set months at 0, 85 N with 0 horizon",
                          date.months, 3, 0);
    failed += test_result("Solar next set days at 0, 85 N with 0 horizon",
                          date.days, 9, 0);
    failed += test_result("Solar next set hour at 0 E, 85 N with 0 horizon",
                          date.hours, 14, 0);
    failed += test_result("Solar next set minute at 0, 85 N with 0 horizon",
                          date.minutes, 2, 0);
  }

  return failed;
}
