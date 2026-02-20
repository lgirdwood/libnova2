/*
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *  Copyright (C) 2000 - 2026 Liam Girdwood <lgirdwood@gmail.com>
 */

#if defined(__MINGW__) || defined(__MINGW32__) || defined(__MINGW64__)
#define _USE_32BIT_TIME_T
#endif //__MINGW__

#include <libnova/julian_day.h>
#include <libnova/utility.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if !defined(__WIN32__) || defined(__MINGW__)
#include <sys/time.h>
#endif
/* Formula 7.1 on pg 61
 */
double ln2_get_julian_day(struct ln_date *date) {
  double JD;
  double days;
  int a, b;
  struct ln_date local_date;

  /* create local copy */
  memcpy(&local_date, date, sizeof(struct ln_date));

  /* check for month = January or February */
  if (local_date.months < 3) {
    local_date.years--;
    local_date.months += 12;
  }

  a = local_date.years / 100;

  /* check for Julian or Gregorian calendar (starts Oct 4th 1582) */
  if (local_date.years > 1582 ||
      (local_date.years == 1582 &&
       (local_date.months > 10 ||
        (local_date.months == 10 && local_date.days >= 4)))) {
    /* Gregorian calendar */
    b = 2 - a + (a / 4);
  } else {
    /* Julian calendar */
    b = 0;
  }

  /* add a fraction of hours, minutes and secs to days*/
  days = local_date.days + (double)(local_date.hours / 24.0) +
         (double)(local_date.minutes / 1440.0) +
         (double)(local_date.seconds / 86400.0);

  /* now get the JD */
  JD = (int)(365.25 * (local_date.years + 4716)) +
       (int)(30.6001 * (local_date.months + 1)) + days + b - 1524.5;

  return JD;
}
unsigned int ln2_get_day_of_week(struct ln_date *date) {
  unsigned int day;
  double JD;

  /* get julian day */
  JD = ln2_get_julian_day(date);
  JD += 1.5;
  day = (int)JD % 7;

  return day;
}
void ln2_get_date(double JD, struct ln_date *date) {
  int A, a, B, C, D, E;
  double F, Z;

  JD += 0.5;
  Z = (int)JD;
  F = JD - Z;

  if (Z < 2299161)
    A = (int)Z;
  else {
    a = (int)((Z - 1867216.25) / 36524.25);
    A = (int)(Z + 1 + a - (int)(a / 4));
  }

  B = A + 1524;
  C = (int)((B - 122.1) / 365.25);
  D = (int)(365.25 * C);
  E = (int)((B - D) / 30.6001);

  /* get the hms */
  date->hours = (int)(F * 24);
  F -= (double)date->hours / 24;
  date->minutes = (int)(F * 1440);
  F -= (double)date->minutes / 1440;
  date->seconds = F * 86400;

  /* get the day */
  date->days = B - D - (int)(30.6001 * E);

  /* get the month */
  if (E < 14)
    date->months = E - 1;
  else
    date->months = E - 13;

  /* get the year */
  if (date->months > 2)
    date->years = C - 4716;
  else
    date->years = C - 4715;
}
void ln2_get_date_from_timet(time_t *t, struct ln_date *date) {
  struct tm gmt;

  /* convert to UTC time representation */
  gmtime_r(t, &gmt);

  ln2_get_date_from_tm(&gmt, date);
}
void ln2_get_date_from_tm(struct tm *t, struct ln_date *date) {
  /* fill in date struct */
  date->seconds = t->tm_sec;
  date->minutes = t->tm_min;
  date->hours = t->tm_hour;
  date->days = t->tm_mday;
  date->months = t->tm_mon + 1;
  date->years = t->tm_year + 1900;
}
void ln2_get_date_from_sys(struct ln_date *date) {
  struct tm *gmt;
  struct timeval tv;
  struct timezone tz;

  /* get current time with microseconds precission*/
  gettimeofday(&tv, &tz);

  /* convert to UTC time representation */
  gmt = gmtime(&tv.tv_sec);

  /* fill in date struct */
  date->seconds = gmt->tm_sec + ((double)tv.tv_usec / 1000000);
  date->minutes = gmt->tm_min;
  date->hours = gmt->tm_hour;
  date->days = gmt->tm_mday;
  date->months = gmt->tm_mon + 1;
  date->years = gmt->tm_year + 1900;
}
double ln2_get_julian_from_timet(time_t *in_time) {
  /* 1.1.1970 = JD 2440587.5 */
  return (double)(2440587.5 + (double)(*in_time / (double)86400.0));
}
void ln2_get_timet_from_julian(double JD, time_t *in_time) {
  *in_time = (time_t)round((JD - (double)2440587.5) * (double)86400.0);
}
double ln2_get_julian_from_sys() {
  double JD;
  struct ln_date date;

  /* get sys date */
  ln2_get_date_from_sys(&date);
  JD = ln2_get_julian_day(&date);

  return JD;
}
double ln2_get_julian_local_date(struct ln_zonedate *zonedate) {
  struct ln_date date;

  ln2_zonedate_to_date(zonedate, &date);

  return ln2_get_julian_day(&date);
}
void ln2_get_local_date(double JD, struct ln_zonedate *zonedate) {
  struct ln_date date;
#ifndef __WIN32__
  time_t curtime;
  struct tm *loctime;
#endif
  long gmtoff;

  ln2_get_date(JD, &date);

  /* add day light savings time and hour angle */
#ifdef __WIN32__
  _tzset();
  gmtoff = _timezone;
  if (_daylight)
    gmtoff += 3600;
#else
  curtime = time(NULL);
  loctime = localtime(&curtime);
  gmtoff = loctime->tm_gmtoff;
#endif
  ln2_date_to_zonedate(&date, zonedate, gmtoff);
}
int ln2_get_date_from_mpc(struct ln_date *date, char *mpc_date) {
  char year[3];
  char month[2];
  char day[3];

  memset(date, 0, sizeof(struct ln_date));

  /* is mpc_date correct length */
  if (strlen(mpc_date) != 7)
    return -1;

  /* get the century */
  switch (*mpc_date) {
  case 'I':
    date->years = 1800;
    break;
  case 'J':
    date->years = 1900;
    break;
  case 'K':
    date->years = 2000;
    break;
  default:
    return -1;
  }

  /* get the year */
  year[0] = *(mpc_date + 1);
  year[1] = *(mpc_date + 2);
  year[2] = 0;
  date->years += strtol(year, 0, 10);

  /* month */
  month[0] = *(mpc_date + 3);
  month[1] = 0;
  date->months = strtol(month, 0, 16);

  /* day */
  day[0] = *(mpc_date + 4);
  day[1] = *(mpc_date + 5);
  day[2] = 0;
  date->days = strtol(day, 0, 32);

  return 0;
}
double ln2_get_julian_from_mpc(char *mpc_date) {
  struct ln_date date;
  double JD;

  ln2_get_date_from_mpc(&date, mpc_date);
  JD = ln2_get_julian_day(&date);

  return JD;
}
void ln2_date_to_zonedate(struct ln_date *date, struct ln_zonedate *zonedate,
                         long gmtoff) {
  double jd;
  struct ln_date dat;

  jd = ln2_get_julian_day(date);
  jd += gmtoff / 86400.0;
  ln2_get_date(jd, &dat);

  zonedate->years = dat.years;
  zonedate->months = dat.months;
  zonedate->days = dat.days;
  zonedate->hours = dat.hours;
  zonedate->minutes = dat.minutes;
  zonedate->seconds = dat.seconds;

  zonedate->gmtoff = gmtoff;
}
void ln2_zonedate_to_date(struct ln_zonedate *zonedate, struct ln_date *date) {
  double jd;
  struct ln_date dat;

  dat.years = zonedate->years;
  dat.months = zonedate->months;
  dat.days = zonedate->days;
  dat.hours = zonedate->hours;
  dat.minutes = zonedate->minutes;
  dat.seconds = zonedate->seconds;

  jd = ln2_get_julian_day(&dat);
  jd -= zonedate->gmtoff / 86400.0;
  ln2_get_date(jd, date);
}
