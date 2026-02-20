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
 *  Copyright (C) 2000 - 2026 Liam Girdwood
 */

#ifndef _LN_TYPES_H
#define _LN_TYPES_H

#if !defined(__WIN32__) && (defined(__WIN32) || defined(WIN32))
#define __WIN32__
#define ALIGN32
#else
#define ALIGN32 __attribute__((aligned(32)))
#endif

/* add a specific macro for mingw */
#if defined(__MINGW32__) || defined(__MINGW64__)
#define __MINGW__
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || \
	defined(__BCPLUSPLUS__) || defined(__MWERKS__)
#if defined(LIBNOVA_STATIC)
#define LIBNOVA_EXPORT
#elif defined(LIBNOVA_SHARED)
#define LIBNOVA_EXPORT __declspec(dllexport)
#else
#define LIBNOVA_EXPORT
#endif
#else
#define LIBNOVA_EXPORT
#endif

/* define some useful constants if they are not already defined */
#if (!defined(M_PI_2) && (!defined(_MSC_VER) || !defined(_USE_MATH_DEFINES)))
#define M_PI_2 1.5707963267948966192313216916398
#define M_PI_4 0.78539816339744830961566084581988
#define M_PI 3.1415926535897932384626433832795
#endif

/* sidereal day length in seconds and days (for JD)*/
#define LN_SIDEREAL_DAY_SEC 86164.09
#define LN_SIDEREAL_DAY_DAY (LN_SIDEREAL_DAY_SEC / 86400.0)

/* Degree to Radian conversion */
#define LN_D2R(d) ((d) * (M_PI / 180.0))
#define LN_R2D(r) ((r) * (180.0 / M_PI))

/* 1.1.2000 Julian Day & others */
#define JD2000 2451545.0
#define JD2050 2469807.50

#define B1900 2415020.3135
#define B1950 2433282.4235

/**
** Date
* \struct ln_date
* \brief Human readable Date and time used by libnova
*
* This is the Human readable (easy printf) date format used
* by libnova. It's always in UTC. For local time, please use
* ln_zonedate.
*/

struct ln_date {
	int years; /**< Years. All values are valid */
	int months; /**< Months. Valid values : 1 (January) - 12 (December) */
	int days; /**< Days. Valid values 1 - 28,29,30,31 Depends on month.*/
	int hours; /**< Hours. Valid values 0 - 23. */
	int minutes; /**< Minutes. Valid values 0 - 59. */
	double seconds; /**< Seconds. Valid values 0 - 59.99999.... */
};

/*
 * \def LN_DATE
 * \brief Macro to initialize a ln_date structure
 */
#define LN_DATE(y, m, d, h, min, s)      \
	((struct ln_date){ .years = (y),     \
					   .months = (m),    \
					   .days = (d),      \
					   .hours = (h),     \
					   .minutes = (min), \
					   .seconds = (s) })

/**
** Zone date
* \struct ln_zonedate
* \brief Human readable Date and time with timezone information used
* by libnova
*
* This is the Human readable (easy printf) date with timezone format
* used by libnova.
*/

struct ln_zonedate {
	int years; /**< Years. All values are valid */
	int months; /**< Months. Valid values : 1 (January) - 12 (December) */
	int days; /**< Days. Valid values 1 - 28,29,30,31 Depends on month.*/
	int hours; /**< Hours. Valid values 0 - 23. */
	int minutes; /**< Minutes. Valid values 0 - 59. */
	double seconds; /**< Seconds. Valid values 0 - 59.99999.... */
	long gmtoff; /**< Timezone offset. Seconds east of UTC. Valid values 0..86400
                */
};

/** \struct ln_dms
** \brief Degrees, minutes and seconds.
*
* Human readable Angle in degrees, minutes and seconds
*/

struct ln_dms {
	unsigned short neg; /**< Non zero if negative */
	unsigned short degrees; /**< Degrees. Valid 0 - 360 */
	unsigned short minutes; /**< Minutes. Valid 0 - 59 */
	double seconds; /**< Seconds. Valid 0 - 59.9999... */
};

/** \struct ln_hms
** \brief Hours, minutes and seconds.
*
* Human readable Angle in hours, minutes and seconds
*/

struct ln_hms {
	unsigned short hours; /**< Hours. Valid 0 - 23 */
	unsigned short minutes; /**< Minutes. Valid 0 - 59 */
	double seconds; /**< Seconds. Valid 0 - 59.9999... */
};

/** \struct lnh_equ_posn
** \brief Right Ascension and Declination.
*
* Human readable Equatorial Coordinates.
*/

struct lnh_equ_posn {
	struct ln_hms ra; /**< RA. Object right ascension.*/
	struct ln_dms dec; /**< DEC. Object declination */
};

/** \struct lnh_hrz_posn
** \brief Azimuth and Altitude.
*
* Human readable Horizontal Coordinates.
*/

struct lnh_hrz_posn {
	struct ln_dms az; /**< AZ. Object azimuth. */
	struct ln_dms alt; /**< ALT. Object altitude. */
};

/** \struct lnh_lnlat_posn
** \brief Ecliptical (or celestial) Latitude and Longitude.
*
* Human readable Ecliptical (or celestial) Longitude and Latitude.
*/

struct lnh_lnlat_posn {
	struct ln_dms lng; /**< longitude. Object longitude.*/
	struct ln_dms lat; /**< latitude. Object latitude */
};

/** \struct ln_equ_posn
** \brief Equatorial Coordinates.
*
* The Right Ascension and Declination of an object.
*
* Angles are expressed in radians.
*/

struct ln_equ_posn {
	double ra; /**< RA. Object right ascension in radians.*/
	double dec; /**< DEC. Object declination in radians */
};

/** \struct ln_hrz_posn
** \brief Horizontal Coordinates.
*
* The Azimuth and Altitude of an object.
*
* Angles are expressed in radians.
*/

struct ln_hrz_posn {
	double az; /**< AZ. Object azimuth in radians. <p>
                0 = South, PI/2 = West, PI = North, 3PI/2 = East */
	double alt; /**< ALT. Object altitude in radians. <p> 0 = horizon, PI/2 =
                 zenith, -PI/2 = nadir */
};

/** \struct ln_lnlat_posn
** \brief Ecliptical (or celestial) Longitude and Latitude.
*
* The Ecliptical (or celestial) Latitude and Longitude of and object.
*
* Angles are expressed in radians. East is positive, West negative.
*/

struct ln_lnlat_posn {
	double lng; /**< longitude. Object longitude in radians. */
	double lat; /**< latitude. Object latitude in radians. */
};

/** \struct ln_helio_posn
 * \brief Heliocentric position
 *
 * A heliocentric position is an objects position relative to the
 * centre of the Sun.
 *
 * Angles are expressed in radians.
 * Radius vector is in AU.
 */
struct ln_helio_posn {
	double L; /**< Heliocentric longitude in radians */
	double B; /**< Heliocentric latitude in radians */
	double R; /**< Heliocentric radius vector */
};

/** \struct ln_rect_posn
 * \brief Rectangular coordinates
 *
 * Rectangular Coordinates of a body. These coordinates can be either
 * geocentric or heliocentric.
 *
 * A heliocentric position is an objects position relative to the
 * centre of the Sun.
 * A geocentric position is an objects position relative to the centre
 * of the Earth.
 *
 * Position is in units of AU for planets and in units of km
 * for the Moon.
 */
struct ln_rect_posn {
	double X; /**< Rectangular X coordinate */
	double Y; /**< Rectangular Y coordinate */
	double Z; /**< Rectangular Z coordinate */
};

/**
 * \struct ln_gal_posn
 * \brief Galactic coordinates
 *
 * The Galactic Latitude and Longitude of and object.
 *
 * Angles are expressed in radians.
 */
struct ln_gal_posn {
	double l; /**< Galactic longitude (radians) */
	double b; /**< Galactic latitude (radians) */
};

/**
 * \struct ln_ell_orbit
 * \brief Elliptic Orbital elements
 *
 *  TODO.
 * Angles are expressed in radians.
 */
struct ln_ell_orbit {
	double a; /**< Semi major axis, in AU */
	double e; /**< Eccentricity */
	double i; /**< Inclination in radians */
	double w; /**< Argument of perihelion in radians */
	double omega; /**< Longitude of ascending node in radians*/
	double n; /**< Mean motion, in radians/day */
	double JD; /**< Time of last passage in Perihelion, in julian day*/
};

/*
 * \def LN_ELL_ORBIT_DEG
 * \brief Macro to initialize a ln_ell_orbit structure with angles in degrees
 */
#define LN_ELL_ORBIT_DEG(_a, _e, _i, _w, _omega, _n, _JD)         \
	((struct ln_ell_orbit){ .a = (_a),                            \
							.e = (_e),                            \
							.i = ((_i) * (M_PI / 180.0)),         \
							.w = ((_w) * (M_PI / 180.0)),         \
							.omega = ((_omega) * (M_PI / 180.0)), \
							.n = ((_n) * (M_PI / 180.0)),         \
							.JD = (_JD) })

/**
 * \struct ln_par_orbit
 * \brief Parabolic Orbital elements
 *
 *  TODO.
 * Angles are expressed in radians.
 */
struct ln_par_orbit {
	double q; /**< Perihelion distance in AU */
	double i; /**< Inclination in radians */
	double w; /**< Argument of perihelion in radians */
	double omega; /**< Longitude of ascending node in radians*/
	double JD; /**< Time of last passage in Perihelion, in julian day */
};

/*
 * \def LN_PAR_ORBIT_DEG
 * \brief Macro to initialize a ln_par_orbit structure with angles in degrees
 */
#define LN_PAR_ORBIT_DEG(_q, _i, _w, _omega, _JD)                 \
	((struct ln_par_orbit){ .q = (_q),                            \
							.i = ((_i) * (M_PI / 180.0)),         \
							.w = ((_w) * (M_PI / 180.0)),         \
							.omega = ((_omega) * (M_PI / 180.0)), \
							.JD = (_JD) })

/**
 * \struct ln_hyp_orbit
 * \brief Hyperbolic Orbital elements
 *
 *  TODO.
 * Angles are expressed in radians.
 */
struct ln_hyp_orbit {
	double q; /**< Perihelion distance in AU */
	double e; /**< Eccentricity */
	double i; /**< Inclination in radians */
	double w; /**< Argument of perihelion in radians */
	double omega; /**< Longitude of ascending node in radians*/
	double JD; /**< Time of last passage in Perihelion, in julian day*/
};

/*
 * \def LN_HYP_ORBIT_DEG
 * \brief Macro to initialize a ln_hyp_orbit structure with angles in degrees
 */
#define LN_HYP_ORBIT_DEG(_q, _e, _i, _w, _omega, _JD)             \
	((struct ln_hyp_orbit){ .q = (_q),                            \
							.e = (_e),                            \
							.i = ((_i) * (M_PI / 180.0)),         \
							.w = ((_w) * (M_PI / 180.0)),         \
							.omega = ((_omega) * (M_PI / 180.0)), \
							.JD = (_JD) })

/**
 * \struct ln_rst_time
 * \brief Rise, Set and Transit times.
 *
 * Contains the Rise, Set and transit times for a body.
 *
 */
struct ln_rst_time {
	double rise; /**< Rise time in JD */
	double set; /**< Set time in JD */
	double transit; /**< Transit time in JD */
};

/**
 * \struct ln_nutation
 * \brief Nutation in longitude, ecliptic and obliquity.
 *
 * Contains Nutation in longitude, obliquity and ecliptic obliquity.
 *
 * Angles are expressed in radians.
 */
struct ln_nutation {
	double longitude; /**< Nutation in longitude, in radians */
	double obliquity; /**< Nutation in obliquity, in radians */
	double ecliptic; /**< Mean obliquity of the ecliptic, in radians */
};

#if defined(__WIN32__) && !defined(__MINGW__)

#include <time.h>

struct timeval {
	time_t tv_sec; /* count of seconds since Jan. 1, 1970 */
	long tv_usec; /* and microseconds */
};

struct timezone {
	int tz_minuteswest; /* Minutes west of GMT */
	int tz_dsttime; /* DST correction offset */
};

#endif /* __WIN32__ */

#ifdef __cplusplus
};
#endif

#endif
