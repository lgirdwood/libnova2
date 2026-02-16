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

#ifndef _LN_UTILITY_H
#define _LN_UTILITY_H

#include <libnova/ln_types.h>

#ifdef __WIN32__
#include <time.h>
// cbrt replacement
#define cbrt(x) pow(x, 1.0 / 3.0)
#endif //! __WIN32__

#ifdef __cplusplus
extern "C" {
#endif

/*! \defgroup version libnova library version information
 */

/*! \fn const char * ln_get_version (void)
 * \brief Library Version Number
 * \ingroup version
 * \return Library version string
 */
const char LIBNOVA_EXPORT *ln_get_version(void);

/*! \defgroup misc Misc. Functions
 *
 * Misc functions.
 */

/*! \fn double ln_get_dec_location(char * s)
 * \ingroup misc
 * \brief Obtains Latitude, Longitude, RA or Declination from a string.
 * \param s String containing location
 * \return Location in degrees
 */
double LIBNOVA_EXPORT ln_get_dec_location(char *s);

/*! \fn char * ln_get_humanr_location(double location)
 *  \ingroup misc
 *  \brief Obtains a human readable location in the form: ddºmm'ss.ss"
 * \param location Location in degrees
 * \return Human readable location string
 */
const char LIBNOVA_EXPORT *ln_get_humanr_location(double location);

/*
 * \fn double ln_get_rect_distance(struct ln_rect_posn *a, struct ln_rect_posn
 * *b)
 * \ingroup misc
 * \param a Rectangular position a
 * \param b Rectangular position b
 * \return Distance between a and b
 */
double LIBNOVA_EXPORT ln_get_rect_distance(struct ln_rect_posn *a, struct ln_rect_posn *b);

/*! \defgroup conversion General Conversion Functions
 *
 * Conversion from one libnova type to another.
 */

/*! \fn double ln_rad_to_deg(double radians)
 * \brief radians to degrees
 * \ingroup conversion
 * \param radians Angle in radians
 * \return Angle in degrees
 */
double LIBNOVA_EXPORT ln_rad_to_deg(double radians);

/*! \fn double ln_deg_to_rad(double degrees)
 * \brief degrees to radians
 * \ingroup conversion
 * \param degrees Angle in degrees
 * \return Angle in radians
 */
double LIBNOVA_EXPORT ln_deg_to_rad(double degrees);

/*! \fn double ln_hms_to_deg(struct ln_hms *hms)
 * \brief hours to degrees
 * \ingroup conversion
 * \param hms Angle in HMS format
 * \return Angle in degrees
 */
double LIBNOVA_EXPORT ln_hms_to_deg(struct ln_hms *hms);

/*! \fn void ln_deg_to_hms(double degrees, struct ln_hms *hms)
 * \brief degrees to hours
 * \ingroup conversion
 * \param degrees Angle in degrees
 * \param hms Pointer to store HMS structure
 */
void LIBNOVA_EXPORT ln_deg_to_hms(double degrees, struct ln_hms *hms);

/*! \fn double ln_hms_to_rad(struct ln_hms *hms)
 * \brief hours to radians.
 * \ingroup conversion
 * \param hms Angle in HMS format
 * \return Angle in radians
 */
double LIBNOVA_EXPORT ln_hms_to_rad(struct ln_hms *hms);

/*! \fn void ln_deg_to_hms(double radians, struct ln_hms *hms)
 * \brief radians to hours
 * \ingroup conversion
 * \param radians Angle in radians
 * \param hms Pointer to store HMS structure
 */
void LIBNOVA_EXPORT ln_rad_to_hms(double radians, struct ln_hms *hms);

/*! \fn double ln_dms_to_deg(struct ln_dms *dms)
 * \brief dms to degrees
 * \ingroup conversion
 * \param dms Angle in DMS format
 * \return Angle in degrees
 */
double LIBNOVA_EXPORT ln_dms_to_deg(struct ln_dms *dms);

/*! \fn void ln_deg_to_dms(double degrees, struct ln_dms *dms)
 * \brief degrees to dms
 * \ingroup conversion
 * \param degrees Angle in degrees
 * \param dms Pointer to store DMS structure
 */
void LIBNOVA_EXPORT ln_deg_to_dms(double degrees, struct ln_dms *dms);

/*! \fn double ln_dms_to_rad(struct ln_dms *dms)
 * \brief dms to radians
 * \ingroup conversion
 * \param dms Angle in DMS format
 * \return Angle in radians
 */
double LIBNOVA_EXPORT ln_dms_to_rad(struct ln_dms *dms);

/*! \fn double ln_dms2_to_rad(int degrees, int minutes, double seconds)
 * \brief dms to radians
 * \ingroup conversion
 * \param degrees Degrees
 * \param minutes Minutes
 * \param seconds Seconds
 * \return Angle in radians
 */
double LIBNOVA_EXPORT ln_dms2_to_rad(int degrees, int minutes, double seconds);

/*! \fn void ln_rad_to_dms(double radians, struct ln_dms *dms)
 * \brief radians to dms
 * \ingroup conversion
 * \param radians Angle in radians
 * \param dms Pointer to store DMS structure
 */
void LIBNOVA_EXPORT ln_rad_to_dms(double radians, struct ln_dms *dms);

/*! \fn void ln_hequ_to_equ(struct lnh_equ_posn *hpos, struct ln_equ_posn *pos)
 * \brief human readable equatorial position to double equatorial position
 * \ingroup conversion
 * \param hpos Human readable equatorial position
 * \param pos Pointer to store equatorial position
 */
void LIBNOVA_EXPORT ln_hequ_to_equ(struct lnh_equ_posn *hpos, struct ln_equ_posn *pos);

/*! \fn void ln_equ_to_hequ(struct ln_equ_posn *pos, struct lnh_equ_posn *hpos)
 * \brief human double equatorial position to human readable equatorial position
 * \ingroup conversion
 * \param pos Equatorial position
 * \param hpos Pointer to store human readable equatorial position
 */
void LIBNOVA_EXPORT ln_equ_to_hequ(struct ln_equ_posn *pos, struct lnh_equ_posn *hpos);

/*! \fn void ln_hhrz_to_hrz(struct lnh_hrz_posn *hpos, struct ln_hrz_posn *pos)
 * \brief human readable horizontal position to double horizontal position
 * \ingroup conversion
 * \param hpos Human readable horizontal position
 * \param pos Pointer to store horizontal position
 */
void LIBNOVA_EXPORT ln_hhrz_to_hrz(struct lnh_hrz_posn *hpos, struct ln_hrz_posn *pos);

/*! \fn void ln_hrz_to_hhrz(struct ln_hrz_posn *pos, struct lnh_hrz_posn *hpos)
 * \brief double horizontal position to human readable horizontal position
 * \ingroup conversion
 * \param pos Horizontal position
 * \param hpos Pointer to store human readable horizontal position
 */
void LIBNOVA_EXPORT ln_hrz_to_hhrz(struct ln_hrz_posn *pos, struct lnh_hrz_posn *hpos);

/*! \fn const char * ln_hrz_to_nswe(struct ln_hrz_posn *pos);
 * \brief returns direction of given azimuth - like N,S,W,E,NSW,...
 * \ingroup conversion
 * \param pos Horizontal position
 * \return String direction
 */
const char LIBNOVA_EXPORT *ln_hrz_to_nswe(struct ln_hrz_posn *pos);

/*! \fn void ln_hlnlat_to_lnlat(struct lnh_lnlat_posn *hpos, struct
 * ln_lnlat_posn *pos)
 * \brief human readable long/lat position to double long/lat position
 * \ingroup conversion
 * \param hpos Human readable long/lat position
 * \param pos Pointer to store long/lat position
 */
void LIBNOVA_EXPORT ln_hlnlat_to_lnlat(struct lnh_lnlat_posn *hpos, struct ln_lnlat_posn *pos);

/*! \fn void ln_lnlat_to_hlnlat(struct ln_lnlat_posn *pos, struct lnh_lnlat_posn
 * *hpos)
 * \brief double long/lat position to human readable long/lat position
 * \ingroup conversion
 * \param pos Long/lat position
 * \param hpos Pointer to store human readable long/lat position
 */
void LIBNOVA_EXPORT ln_lnlat_to_hlnlat(struct ln_lnlat_posn *pos, struct lnh_lnlat_posn *hpos);

/*! \fn void ln_add_secs_hms(struct ln_hms *hms, double seconds)
 * \brief add seconds to hms
 * \ingroup conversion
 * \param hms HMS structure
 * \param seconds Seconds to add
 */
void LIBNOVA_EXPORT ln_add_secs_hms(struct ln_hms *hms, double seconds);

/*! \fn void ln_add_hms(struct ln_hms *source, struct ln_hms *dest)
 * \brief add hms to hms
 * \ingroup conversion
 * \param source Source HMS
 * \param dest Destination HMS (source + dest)
 */
void LIBNOVA_EXPORT ln_add_hms(struct ln_hms *source, struct ln_hms *dest);

/*! \fn void ln_range_degrees(double angle)
 * \brief puts a large angle in the correct range 0 - 360 degrees
 * \ingroup conversion
 * \param angle Angle in degrees
 * \return Angle in range 0-360 degrees
 */
double LIBNOVA_EXPORT ln_range_degrees(double angle);

/*! \fn void ln_range_radians(double angle)
 * \brief puts a large angle in the correct range 0 - 2PI radians
 * \ingroup conversion
 * \param angle Angle in radians
 * \return Angle in range 0-2PI radians
 */
double LIBNOVA_EXPORT ln_range_radians(double angle);
double LIBNOVA_EXPORT ln_range_radians2(double angle);

/*! \fn void ln_range_hours(double angle)
 * \brief puts a large angle in the correct range 0 - 24 hours
 * \ingroup conversion
 * \param angle Angle in hours
 * \return Angle in range 0-24 hours
 */
double LIBNOVA_EXPORT ln_range_hours(double angle);

/*
 * \fn double ln_get_light_time(double dist)
 * \brief Convert units of AU into light days.
 * \ingroup conversion
 * \param dist Distance in AU
 * \return Light time in days
 */
double LIBNOVA_EXPORT ln_get_light_time(double dist);

/*! \fn double ln_interpolate3(double n, double y1, double y2, double y3)
 * \ingroup misc
 * \brief Calculate an intermediate value of the 3 arguments.
 * \param n Interpolation factor (0-1)
 * \param y1 Value 1
 * \param y2 Value 2
 * \param y3 Value 3
 * \return Interpolated value
 */
double LIBNOVA_EXPORT ln_interpolate3(double n, double y1, double y2, double y3);

/*! \fn double ln_interpolate5(double n, double y1, double y2, double y3, double
 * y4, double y5)
 * \ingroup misc
 * \brief Calculate an intermediate value of the 5 arguments.
 * \param n Interpolation factor (0-1)
 * \param y1 Value 1
 * \param y2 Value 2
 * \param y3 Value 3
 * \param y4 Value 4
 * \param y5 Value 5
 * \return Interpolated value
 */
double LIBNOVA_EXPORT ln_interpolate5(double n, double y1, double y2, double y3, double y4, double y5);

/*! \fn double ln_find_max(double (*f) (double, double *), double from, double
 * to, double *arg)
 * \brief Find local maximum of function f() at given interval by Golden Section
 * method.
 * \ingroup misc
 * \param f Function to find maximum of
 * \param from Start of interval
 * \param to End of interval
 * \param arg Argument to pass to f
 * \return Value of x where f(x) is maximum
 */
double LIBNOVA_EXPORT ln_find_max(double (*func)(double, double *), double from, double to, double *arg);

/*! \fn double ln_find_zero(double (*f) (double, double *), double from, double
 * to, double *arg)
 * \brief Find zero of function f() at given interval by Newton method.
 * \ingroup misc
 * \param f Function to find zero of
 * \param from Start of interval
 * \param to End of interval
 * \param arg Argument to pass to f
 * \return Value of x where f(x) is zero
 */
double LIBNOVA_EXPORT ln_find_zero(double (*func)(double, double *), double from, double to, double *arg);

#ifdef __WIN32__

/* Catches calls to the POSIX gmtime_r and converts them to a related WIN32
 * version. */
struct tm *gmtime_r(time_t *t, struct tm *gmt);

#ifndef __MINGW__
/* Catches calls to the POSIX gettimeofday and converts them to a related WIN32
 * version. */
int gettimeofday(struct timeval *tp, struct timezone *tzp);
#endif // !__MINGW__

/* Catches calls to the POSIX strtok_r and converts them to a related WIN32
 * version. */
char *strtok_r(char *str, const char *sep, char **last);

#endif /* __WIN32__ */

/* C89 substitutions for C99 functions. */
#ifdef __C89_SUB__

/* Simple cube root */
double cbrt(double x);

#endif /* __C89_SUB__ */

#if defined(__WIN32__) || defined(sun) || defined(__C89_SUB__)

/* Not a Number function generator */
double nan(const char *code);

#endif /* defined(__WIN32__) || defined(sun) || defined(__C89_SUB__) */

#ifdef __cplusplus
};
#endif

#endif
