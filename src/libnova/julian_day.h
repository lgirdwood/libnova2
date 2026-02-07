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

/*! \defgroup calendar General Calendar Functions 
*/
 
/*! \fn double ln_get_julian_day(struct ln_date *date)
* \ingroup calendar
* \brief Calculate the julian day from date.
* \param date Date structure
* \return Julian Day
*/
double LIBNOVA_EXPORT ln_get_julian_day(struct ln_date *date);

/*! \fn void ln_get_date(double JD, struct ln_date *date)
* \ingroup calendar
* \brief Calculate the date from the julian day.
* \param JD Julian Day
* \param date Pointer to store date
*/
void LIBNOVA_EXPORT ln_get_date(double JD, struct ln_date *date);

/*! \fn void ln_get_date_from_timet (time_t *t, struct ln_date *date)
* \\ingroup calendar
* \brief Set date from system time
* \param t Time_t structure
* \param date Pointer to store date
*/
void LIBNOVA_EXPORT ln_get_date_from_timet (time_t *t, struct ln_date *date);

/*! \fn void ln_get_date_from_tm(struct tm *t, struct ln_date *date)
* \\ingroup calendar
* \brief Set date from system tm structure
* \param t tm structure
* \param date Pointer to store date
*/
void LIBNOVA_EXPORT ln_get_date_from_tm(struct tm *t, struct ln_date *date);

/*! \fn void ln_get_local_date(double JD, struct ln_zonedate *zonedate)
* \ingroup calender
* \brief Calculate the zone date from the Julian day  
* \param JD Julian Day
* \param zonedate Pointer to store zonedate
*/
void LIBNOVA_EXPORT ln_get_local_date(double JD, struct ln_zonedate *zonedate);

/*! \fn unsigned int ln_get_day_of_week(struct ln_date *date)
* \ingroup calendar
* \brief Calculate day of the week.
* \param date Date structure
* \return Day of week (0=Sunday, 6=Saturday)
*/
unsigned int LIBNOVA_EXPORT ln_get_day_of_week(struct ln_date *date);
	
/*! \fn double ln_get_julian_from_sys()
* \brief Calculate julian day from system time.
* \ingroup calendar
* \return Julian Day
*/
double LIBNOVA_EXPORT ln_get_julian_from_sys();


/*! \fn void ln_get_date_from_sys(struct ln_date *date)
* \brief Calculate date from system date
* \ingroup calendar
* \param date Pointer to store date
*/
void LIBNOVA_EXPORT ln_get_date_from_sys(struct ln_date *date);
	
/*! \fn double ln_get_julian_from_timet(time_t *time)
* \brief Calculate julian day from time_t
* \ingroup calendar
* \param in_time Time_t structure
* \return Julian Day
*/
double LIBNOVA_EXPORT ln_get_julian_from_timet(time_t * in_time);

/*! \fn void ln_get_timet_from_julian(double JD, time_t * in_time)
* \brief Calculate time_t from julian day
* \ingroup calendar
* \param JD Julian Day
* \param in_time Pointer to store time_t
*/
void LIBNOVA_EXPORT ln_get_timet_from_julian(double JD, time_t * in_time);

/*! \fn double ln_get_julian_local_date(struct ln_zonedate* zonedate)
* \brief Calculate Julian day from local date
* \ingroup calendar
* \param zonedate Zonedate structure
* \return Julian Day
*/
double LIBNOVA_EXPORT ln_get_julian_local_date(struct ln_zonedate* zonedate);
	
/*! \fn int ln_get_date_from_mpc(struct ln_date *date, char *mpc_date)
* \brief Calculate the local date from the a MPC packed date.
* \ingroup calendar
* \param date Pointer to store date
* \param mpc_date MPC packed date string
* \return 0 for success
*/
int LIBNOVA_EXPORT ln_get_date_from_mpc(struct ln_date *date, char *mpc_date);
	
/*! \fn double ln_get_julian_from_mpc(char *mpc_date)
* \brief Calculate the julian day from the a MPC packed date.
* \ingroup calendar
* \param mpc_date MPC packed date string
* \return Julian Day
*/
double LIBNOVA_EXPORT ln_get_julian_from_mpc(char *mpc_date);

/*! \fn void ln_date_to_zonedate(struct ln_date *date, struct ln_zonedate *zonedate, long gmtoff)
* \brief convert ln_date to ln_zonedate, zero zone info
* \ingroup conversion
* \param date Date structure
* \param zonedate Pointer to store zonedate
* \param gmtoff GMT offset in seconds
*/
void LIBNOVA_EXPORT ln_date_to_zonedate(struct ln_date *date,
	struct ln_zonedate *zonedate, long gmtoff);

/*! \fn void ln_zonedate_to_date(struct ln_zonedate *zonedate, struct ln_date *date)
* \brief convert ln_zonedate to ln_date
* \ingroup conversion
* \param zonedate Zonedate structure
* \param date Pointer to store date
*/
void LIBNOVA_EXPORT ln_zonedate_to_date(struct ln_zonedate *zonedate,
	struct ln_date *date);

#ifdef __cplusplus
};
#endif

#endif
