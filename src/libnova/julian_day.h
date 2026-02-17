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
 *  Copyright (C) 2000 - 2005 Liam Girdwood  
 */

#ifndef _LN_JULIAN_DAY_H
#define _LN_JULIAN_DAY_H

#include <time.h>
#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup calendar General Calendar Functions 
*
* Functions for converting between various time systems and calendar formats.
*
* The Julian Day (JD) is a continuous count of days since the beginning of the Julian Period 
* (January 1, 4713 BC at noon UT). It is the primary time variable used in astronomical calculations.
*
* - **JD at J2000.0**: 2451545.0 (2000 January 1.5 TD)
* - **MJD (Modified Julian Day)**: JD - 2400000.5
*
* Algorithms are based on Chapter 7 of Meeus's *Astronomical Algorithms*.
*/

/**
* \ingroup calendar
* \brief Calculate the julian day from date.
* \param date Date structure
* \return Julian Day
*
* Formula 7.1 (Meeus). Valid for positive and negative years (using astronomical year numbering, 
* where 0 = 1 BC, -1 = 2 BC, etc.).
*/
double LIBNOVA_EXPORT ln_get_julian_day(struct ln_date *date);

/**
* \ingroup calendar
* \brief Calculate the date from the julian day.
* \param JD Julian Day
* \param date Pointer to store date
*
* Inverse of Formula 7.1 (Meeus).
*/
void LIBNOVA_EXPORT ln_get_date(double JD, struct ln_date *date);

/**
* \\ingroup calendar
* \brief Set date from system time
* \param t Time_t structure
* \param date Pointer to store date
*/
void LIBNOVA_EXPORT ln_get_date_from_timet(time_t *t, struct ln_date *date);

/**
* \\ingroup calendar
* \brief Set date from system tm structure
* \param t tm structure
* \param date Pointer to store date
*/
void LIBNOVA_EXPORT ln_get_date_from_tm(struct tm *t, struct ln_date *date);

/**
* \ingroup calender
* \brief Calculate the zone date from the Julian day  
* \param JD Julian Day
* \param zonedate Pointer to store zonedate
*/
void LIBNOVA_EXPORT ln_get_local_date(double JD, struct ln_zonedate *zonedate);

/**
* \ingroup calendar
* \brief Calculate day of the week.
* \param date Date structure
* \return Day of week (0=Sunday, 6=Saturday)
*
* Based on Meeus Chapter 7.
*/
unsigned int LIBNOVA_EXPORT ln_get_day_of_week(struct ln_date *date);

/**
* \brief Calculate julian day from system time.
* \ingroup calendar
* \return Julian Day (UT)
*/
double LIBNOVA_EXPORT ln_get_julian_from_sys();

/**
* \brief Calculate date from system date
* \ingroup calendar
* \param date Pointer to store date
*/
void LIBNOVA_EXPORT ln_get_date_from_sys(struct ln_date *date);

/**
* \brief Calculate julian day from time_t
* \ingroup calendar
* \param in_time Time_t structure
* \return Julian Day
*
* Unix time 1970-01-01 00:00:00 UTC corresponds to JD 2440587.5.
*/
double LIBNOVA_EXPORT ln_get_julian_from_timet(time_t *in_time);

/**
* \brief Calculate time_t from julian day
* \ingroup calendar
* \param JD Julian Day
* \param in_time Pointer to store time_t
*/
void LIBNOVA_EXPORT ln_get_timet_from_julian(double JD, time_t *in_time);

/**
* \brief Calculate Julian day from local date
* \ingroup calendar
* \param zonedate Zonedate structure
* \return Julian Day
*/
double LIBNOVA_EXPORT ln_get_julian_local_date(struct ln_zonedate *zonedate);

/**
* \brief Calculate the local date from the a MPC packed date.
* \ingroup calendar
* \param date Pointer to store date
* \param mpc_date MPC packed date string
* \return 0 for success
*
* See http://cfa-www.harvard.edu/iau/info/PackedDates.html
*/
int LIBNOVA_EXPORT ln_get_date_from_mpc(struct ln_date *date, char *mpc_date);

/**
* \brief Calculate the julian day from the a MPC packed date.
* \ingroup calendar
* \param mpc_date MPC packed date string
* \return Julian Day
*
* See http://cfa-www.harvard.edu/iau/info/PackedDates.html
*/
double LIBNOVA_EXPORT ln_get_julian_from_mpc(char *mpc_date);

/**
* \brief convert ln_date to ln_zonedate, zero zone info
* \ingroup conversion
* \param date Date structure
* \param zonedate Pointer to store zonedate
* \param gmtoff GMT offset in seconds
*/
void LIBNOVA_EXPORT ln_date_to_zonedate(struct ln_date *date, struct ln_zonedate *zonedate, long gmtoff);

/**
* \brief convert ln_zonedate to ln_date
* \ingroup conversion
* \param zonedate Zonedate structure
* \param date Pointer to store date
*/
void LIBNOVA_EXPORT ln_zonedate_to_date(struct ln_zonedate *zonedate, struct ln_date *date);

#ifdef __cplusplus
};
#endif

#endif
