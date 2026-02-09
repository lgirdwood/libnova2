/*
 * Julian Day and Time Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

int julian_test(void) {
  double JD;
  int wday, failed = 0;
  struct ln_date date, pdate;
  struct ln_zonedate zonedate;

  /* Get julian day for 04/10/1957 19:00:00 */
  date.years = 1957;
  date.months = 10;
  date.days = 4;
  date.hours = 19;
  date.minutes = 0;
  date.seconds = 0;
  JD = ln_get_julian_day(&date);
  failed += test_result("(Julian Day) JD for 4/10/1957 19:00:00", JD,
                        2436116.29166667, 0.00001);

  /* Get julian day for 27/01/333 12:00:00 */
  date.years = 333;
  date.months = 1;
  date.days = 27;
  date.hours = 12;
  JD = ln_get_julian_day(&date);
  failed +=
      test_result("(Julian Day) JD for 27/01/333 12:00:00", JD, 1842713.0, 0.1);

  /* Get julian day for 30/06/1954 00:00:00 */
  date.years = 1954;
  date.months = 6;
  date.days = 30;
  date.hours = 0;
  JD = ln_get_julian_day(&date);
  failed += test_result("(Julian Day) JD for 30/06/1954 00:00:00", JD,
                        2434923.5, 0.1);

  wday = ln_get_day_of_week(&date);
  failed += test_result("(Julian Day) Weekday No", wday, 3, 0.1);

  /* Test ln_date_to_zonedate and back */

  ln_date_to_zonedate(&date, &zonedate, 7200);
  ln_zonedate_to_date(&zonedate, &date);

  JD = ln_get_julian_day(&date);

  failed +=
      test_result("(Julian Day) ln_date_to_zonedate and "
                  "ln_zonedate_to_date check - JD for 30/06/1954 00:00:00",
                  JD, 2434923.5, 0.1);

  ln_get_date(JD, &pdate);
  failed += test_result("(Julian Day) Day from JD for 30/06/1954 00:00:00",
                        pdate.days, 30, 0.1);

  failed += test_result("(Julian Day) Month from JD for 30/06/1954 00:00:00",
                        pdate.months, 6, 0.1);

  failed += test_result("(Julian Day) Year from JD for 30/06/1954 00:00:00",
                        pdate.years, 1954, 0.1);

  failed += test_result("(Julian Day) Hour from JD for 30/06/1954 00:00:00",
                        pdate.hours, 0, 0.1);

  failed += test_result("(Julian Day) Minute from JD for 30/06/1954 00:00:00",
                        pdate.minutes, 0, 0.1);

  failed += test_result("(Julian Day) Second from JD for 30/06/1954 00:00:00",
                        pdate.seconds, 0, 0.001);

  JD = ln_get_julian_from_sys();

  ln_get_date(JD, &date);
  JD = ln_get_julian_day(&date);
  /* printf("Sys JD %f\n", JD); */

  /* Get julian day for 01/01/1987 00:00:00 */
  date.years = 1987;
  date.months = 1;
  date.days = 1; /* 1987 JAN 1.5 ? */
  date.hours = 0;
  date.minutes = 0;
  date.seconds = 0;
  JD = ln_get_julian_day(&date);
  failed += test_result("(Julian Day) JD for 01/01/1987 00:00:00", JD,
                        2446796.5, 0.00001);

  /* Get julian day for 01/01/1900 00:00:00 */
  date.years = 1900;
  date.months = 1;
  date.days = 1;
  date.hours = 0;
  date.minutes = 0;
  date.seconds = 0;
  JD = ln_get_julian_day(&date);
  failed += test_result("(Julian Day) JD for 01/01/1900 00:00:00", JD,
                        2415020.5, 0.00001);

  /* Get julian day for 01/01/1600 00:00:00 */
  date.years = 1600;
  date.months = 1;
  date.days = 1;
  date.hours = 0;
  date.minutes = 0;
  date.seconds = 0;
  JD = ln_get_julian_day(&date);
  failed += test_result("(Julian Day) JD for 01/01/1600 00:00:00", JD,
                        2305447.5, 0.00001);

  /* Get julian day for 31/12/1600 00:00:00 */
  date.years = 1600;
  date.months = 12;
  date.days = 31;
  date.hours = 0;
  date.minutes = 0;
  date.seconds = 0;
  JD = ln_get_julian_day(&date);
  failed += test_result("(Julian Day) JD for 31/12/1600 00:00:00", JD,
                        2305812.5, 0.00001);

  /* Get julian day for 10/04/1957 19:21:00 */
  date.years = 1957;
  date.months = 10;
  date.days = 4;
  date.hours = 19;
  date.minutes = 26;
  date.seconds = 24;
  JD = ln_get_julian_day(&date);
  failed += test_result("(Julian Day) JD for 10/04/1957 19:26:24", JD,
                        2436116.31, 0.00001);

  /* Get julian day for 27/01/333 12:00:00 */
  date.years = 333;
  date.months = 1;
  date.days = 27;
  date.hours = 12;
  date.minutes = 0;
  date.seconds = 0;
  JD = ln_get_julian_day(&date);
  failed += test_result("(Julian Day) JD for 27/01/333 12:00:00", JD, 1842713.0,
                        0.00001);

  return failed;
}

int date_time_test(void) {
  int failed = 0;
  double JD, TD_diff;
  time_t t, t2;
  struct ln_date date;

  /* Time_t <-> JD */
  t = 1000000000; /* 2001-09-09 ... */
  JD = ln_get_julian_from_timet(&t);
  ln_get_timet_from_julian(JD, &t2);
  /* Allow 1 sec diff due to double precision */
  if (fabs(difftime(t, t2)) > 1.0) {
    printf("TEST (Date) timet -> JD -> timet....[FAILED]\n");
    printf(" Expected %ld, got %ld\n", (long)t, (long)t2);
    failed++;
  } else {
    printf("TEST (Date) timet -> JD -> timet....[PASSED]\n");
    printf(" Expected and calculated %ld\n", (long)t);
  }

  /* MPC Date */
  /* K01I090 -> 2001-09-09 (I=9) */
  /* Packed MPC format: Year: I=18, J=19, K=20. Month: 1-9, A, B, C. Day: 1-9,
   * A-V. */
  /* K01909 -> K=20, 01=01, 9=Sep, 09=9. 2001-Sep-09. Not quite. */
  /* MPC strings are 1 based? */
  /* Example: J96J010 = 1996 Oct 1 */
  JD = ln_get_julian_from_mpc("K019090");
  /* 2001 Sept 09 */
  date.years = 2001;
  date.months = 9;
  date.days = 9;
  date.hours = 0;
  date.minutes = 0;
  date.seconds = 0;
  failed +=
      test_result("(Date) MPC 'K019090'", JD, ln_get_julian_day(&date), 1e-6);

  /* Dynamical Time Diff */
  /* Simple check it returns something non-zero and reasonable */
  TD_diff = ln_get_dynamical_time_diff(2451545.0); /* J2000 */
  /* Delta T at J2000 is approx 64s. 64/86400 days. */
  failed += test_result("(Date) Dynamical Time Diff J2000", TD_diff,
                        64.0 / 86400.0, 5.0 / 86400.0);

  /* 12th April 1957 19:21:00 */
  JD = 2436116.31;
  ln_get_date(JD, &date);
  if (date.years != 1957 && date.months != 10 && date.days != 4 &&
      date.hours != 19 && date.minutes != 26 && date.seconds != 24) {
    printf("TEST (Date Time) date for JD 2436116.31....[FAILED]\n");
    failed++;
  } else {
    printf("TEST (Date Time) date for JD 2436116.31....[PASSED]\n");
  }

  return failed;
}
