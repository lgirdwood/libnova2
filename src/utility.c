/* $Id: utility.c,v 1.18 2009-04-20 07:17:00 pkubanek Exp $
 **
 * Copyright (C) 1999, 2000 Juan Carlos Remis
 * Copyright (C) 2002 Liam Girdwood <lgirdwood@gmail.com>
 *
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
 */

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  Module:                                                               */
/*                                                                        */
/*  Description:                                                          */
/*                                                                        */
/*                                                                        */
/*  "CAVEAT UTILITOR".                                                    */
/*                                                                        */
/*                   "Non sunt multiplicanda entia praeter necessitatem"  */
/*                                                   Guillermo de Occam.  */
/*------------------------------------------------------------------------*/
/*  Revision History:                                                     */
/*                                                                        */
/*------------------------------------------------------------------------*/

#include <ctype.h>
#include <libnova/libnova.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __APPLE__
#include <malloc.h>
#endif

/* Include unistd.h only if not on a Win32 platform */
/* Include Win32 Headers sys/types.h and sys/timeb.h if on Win32 */
#ifndef __WIN32__
#include <unistd.h>
#else
#include <sys/timeb.h>
#include <sys/types.h>
#endif

/* Conversion factors between degrees and radians */
#define D2R (1.7453292519943295769e-2) /* deg->radian */
#define R2D (5.7295779513082320877e1) /* radian->deg */
#define R2S (2.0626480624709635516e5) /* arc seconds per radian */
#define S2R (4.8481368110953599359e-6) /* radians per arc second */

/* Golden ratio */
#define GOLDEN 1.61803398875

#define DM_PI (2 * M_PI)
#define RADIAN (180.0 / M_PI)

static const char ln_version[] = LIBNOVA_VERSION;
const char *ln_get_version(void)
{
	return ln_version;
}

/* convert radians to degrees */
/* convert radians to degrees */
double ln_rad_to_deg(double radians)
{
	return LN_R2D(radians);
}

/* convert degrees to radians */
double ln_deg_to_rad(double degrees)
{
	return LN_D2R(degrees);
}

/* convert hours:mins:secs to degrees */
double ln_hms_to_deg(struct ln_hms *hms)
{
	double degrees;

	degrees = ((double)hms->hours / 24.0) * 360.0;
	degrees += ((double)hms->minutes / 60.0) * 15.0;
	degrees += ((double)hms->seconds / 60.0) * 0.25;

	return degrees;
}

/* convert hours:mins:secs to radians */
double ln_hms_to_rad(struct ln_hms *hms)
{
	double radians;

	radians = ((double)hms->hours / 24.0) * 2.0 * M_PI;
	radians += ((double)hms->minutes / 60.0) * 2.0 * M_PI / 24.0;
	radians += ((double)hms->seconds / 60.0) * 2.0 * M_PI / 1440.0;

	return radians;
}

/* convert degrees to hh:mm:ss */
void ln_deg_to_hms(double degrees, struct ln_hms *hms)
{
	double dtemp;

	degrees = ln_range_degrees(degrees);

	/* divide degrees by 15 to get the hours */
	dtemp = degrees / 15.0;
	hms->hours = (unsigned short)dtemp;

	/* multiply remainder by 60 to get minutes */
	dtemp = 60.0 * (dtemp - hms->hours);
	hms->minutes = (unsigned short)dtemp;

	/* multiply remainder by 60 to get seconds */
	hms->seconds = 60.0 * (dtemp - hms->minutes);

	/* catch any overflows */
	if (hms->seconds > 59) {
		hms->seconds = 0.0;
		hms->minutes++;
	}
	if (hms->minutes > 59) {
		hms->minutes = 0;
		hms->hours++;
	}
}

/* convert radians to hh:mm:ss */
void ln_rad_to_hms(double radians, struct ln_hms *hms)
{
	double degrees;

	radians = ln_range_radians(radians);
	degrees = LN_R2D(radians);

	ln_deg_to_hms(degrees, hms);
}

/* convert dms to degrees */
double ln_dms_to_deg(struct ln_dms *dms)
{
	double degrees;

	degrees = fabs((double)dms->degrees);
	degrees += fabs((double)dms->minutes / 60.0);
	degrees += fabs((double)dms->seconds / 3600.0);

	// negative ?
	if (dms->neg)
		degrees *= -1.0;

	return degrees;
}

/* convert dms to radians */
double ln_dms_to_rad(struct ln_dms *dms)
{
	double radians;

	radians = fabs((double)dms->degrees / 360.0 * 2.0 * M_PI);
	radians += fabs((double)dms->minutes / 21600.0 * 2.0 * M_PI);
	radians += fabs((double)dms->seconds / 1296000.0 * 2.0 * M_PI);

	// negative ?
	if (dms->neg)
		radians *= -1.0;

	return radians;
}

/* convert dms to radians */
double ln_dms2_to_rad(int degrees, int minutes, double seconds)
{
	double radians;

	radians = fabs((double)degrees / 360.0 * 2.0 * M_PI);
	radians += fabs((double)minutes / 21600.0 * 2.0 * M_PI);
	radians += fabs(seconds / 1296000.0 * 2.0 * M_PI);

	// negative ?
	if (degrees < 0 || minutes < 0 || seconds < 0)
		radians *= -1.0;

	return radians;
}

/* convert degrees to dms */
void ln_deg_to_dms(double degrees, struct ln_dms *dms)
{
	double dtemp;

	if (degrees >= 0.0)
		dms->neg = 0;
	else
		dms->neg = 1;

	degrees = fabs(degrees);
	dms->degrees = (int)degrees;

	/* multiply remainder by 60 to get minutes */
	dtemp = 60.0 * (degrees - dms->degrees);
	dms->minutes = (unsigned short)dtemp;

	/* multiply remainder by 60 to get seconds */
	dms->seconds = 60.0 * (dtemp - dms->minutes);

	/* catch any overflows */
	if (dms->seconds > 59) {
		dms->seconds = 0.0;
		dms->minutes++;
	}
	if (dms->minutes > 59) {
		dms->minutes = 0;
		dms->degrees++;
	}
}

/* convert radians to dms */
void ln_rad_to_dms(double radians, struct ln_dms *dms)
{
	double degrees = LN_R2D(radians);

	ln_deg_to_dms(degrees, dms);
}

/* puts a large angle in the correct range 0 - 360 degrees */
double ln_range_degrees(double angle)
{
	double temp;

	if (angle >= 0.0 && angle < 360.0)
		return angle;

	temp = (int)(angle / 360);
	if (angle < 0.0)
		temp--;
	temp *= 360.0;
	return angle - temp;
}

/* puts a large angle in the correct range 0 - 2PI radians */
double ln_range_radians(double angle)
{
	double temp;

	if (angle >= 0.0 && angle < (2.0 * M_PI))
		return angle;

	temp = (int)(angle / (M_PI * 2.0));

	if (angle < 0.0)
		temp--;
	temp *= (M_PI * 2.0);
	return angle - temp;
}

/* puts a large angle in the correct range -2PI - 2PI radians */
/* preserve sign */
double ln_range_radians2(double angle)
{
	double temp;

	if (angle > (-2.0 * M_PI) && angle < (2.0 * M_PI))
		return angle;

	temp = (int)(angle / (M_PI * 2.0));
	temp *= (M_PI * 2.0);
	return angle - temp;
}

double ln_range_hours(double angle)
{
	double temp;

	if (angle >= 0.0 && angle < 24.0)
		return angle;

	temp = (int)(angle / 24);
	if (angle < 0.0)
		temp--;
	temp *= 24.0;
	return angle - temp;
}

/* add seconds to hms */
void ln_add_secs_hms(struct ln_hms *hms, double seconds)
{
	struct ln_hms source_hms;

	/* breaks double seconds int hms */
	source_hms.hours = (unsigned short)(seconds / 3600);
	seconds -= source_hms.hours * 3600;
	source_hms.minutes = (unsigned short)(seconds / 60);
	seconds -= source_hms.minutes * 60;
	source_hms.seconds = seconds;

	/* add hms to hms */
	ln_add_hms(&source_hms, hms);
}

/* add hms to hms */
void ln_add_hms(struct ln_hms *source, struct ln_hms *dest)
{
	dest->seconds += source->seconds;
	if (dest->seconds >= 60.0) {
		/* carry */
		source->minutes++;
		dest->seconds -= 60.0;
	} else {
		if (dest->seconds < 0.0) {
			/* carry */
			source->minutes--;
			dest->seconds += 60.0;
		}
	}

	dest->minutes += source->minutes;
	if (dest->minutes >= 60) {
		/* carry */
		source->hours++;
		dest->minutes -= 60;
	} else {
		if (dest->seconds < 0.0) {
			/* carry */
			source->hours--;
			dest->minutes += 60;
		}
	}

	dest->hours += source->hours;
}
void ln_hequ_to_equ(struct lnh_equ_posn *hpos, struct ln_equ_posn *pos)
{
	pos->ra = ln_hms_to_rad(&hpos->ra);
	pos->dec = ln_dms_to_rad(&hpos->dec);
}
void ln_equ_to_hequ(struct ln_equ_posn *pos, struct lnh_equ_posn *hpos)
{
	ln_rad_to_hms(pos->ra, &hpos->ra);
	ln_rad_to_dms(pos->dec, &hpos->dec);
}
void ln_hhrz_to_hrz(struct lnh_hrz_posn *hpos, struct ln_hrz_posn *pos)
{
	pos->alt = ln_dms_to_rad(&hpos->alt);
	pos->az = ln_dms_to_rad(&hpos->az);
}
void ln_hrz_to_hhrz(struct ln_hrz_posn *pos, struct lnh_hrz_posn *hpos)
{
	ln_rad_to_dms(pos->alt, &hpos->alt);
	ln_rad_to_dms(pos->az, &hpos->az);
}
const char *ln_hrz_to_nswe(struct ln_hrz_posn *pos)
{
	const char *directions[] = { "S",  "SSW", "SW", "SWW", "W",	 "NWW",
								 "NW", "NNW", "N",	"NNE", "NE", "NEE",
								 "E",  "SEE", "SE", "SSE" };

	return directions[(int)(LN_R2D(pos->az) / 22.5)];
}
void ln_hlnlat_to_lnlat(struct lnh_lnlat_posn *hpos, struct ln_lnlat_posn *pos)
{
	pos->lng = ln_dms_to_rad(&hpos->lng);
	pos->lat = ln_dms_to_rad(&hpos->lat);
}
void ln_lnlat_to_hlnlat(struct ln_lnlat_posn *pos, struct lnh_lnlat_posn *hpos)
{
	ln_rad_to_dms(pos->lng, &hpos->lng);
	ln_rad_to_dms(pos->lat, &hpos->lat);
}

/*
 * *b)
 * \param a First rectangular coordinate
 * \param b Second rectangular coordinate
 * \return Distance between a and b.
 *
 * Calculate the distance between rectangular points a and b.
 */
double ln_get_rect_distance(struct ln_rect_posn *a, struct ln_rect_posn *b)
{
	double x, y, z;

	x = a->X - b->X;
	y = a->Y - b->Y;
	z = a->Z - b->Z;

	x *= x;
	y *= y;
	z *= z;

	return sqrt(x + y + z);
}

/*
 * \param dist Distance in AU
 * \return Distance in light days.
 *
 * Convert units of AU into light days.
 */
double ln_get_light_time(double dist)
{
	return dist * 0.005775183;
}

/* local types and macros */
typedef int BOOL;
#define TRUE 1
#define FALSE 0
#define iswhite(c) ((c) == ' ' || (c) == '\t')

/*
[]------------------------------------------------------------------------[]
|  trim() & strip()                                                        |
|                                                                          |
|  strips trailing whitespaces from buf.                                   |
|                                                                          |
[]------------------------------------------------------------------------[]
*/
static char *trim(char *x)
{
	char *y;

	if (!x)
		return (x);
	y = x + strlen(x) - 1;
	while (y >= x && isspace(*y))
		*y-- = 0; /* skip white space */
	return x;
}

/*
[]------------------------------------------------------------------------[]
|                                                                          |
|   skipwhite()                                                            |
|   salta espacios en blanco                                               |
|                                                                          |
[]------------------------------------------------------------------------[]
*/
static void skipwhite(char **s)
{
	while (iswhite(**s))
		(*s)++;
}
double ln_get_dec_location(char *s)
{
	char *ptr, *dec, *hh, *ame, *tok_ptr;
	BOOL negative = FALSE;
	char delim1[] = " :.,;DdHhMm'\n\t";
	char delim2[] = " NSEWnsew\"\n\t";
	int dghh = 0, minutes = 0;
	double seconds = 0.0, pos;
	short count;
	enum { HOURS, DEGREES, LAT, LONG } type;

	if (s == NULL || !*s)
		return -0.0;

	count = strlen(s) + 1;
	if ((ptr = (char *)alloca(count)) == NULL)
		return -0.0;

	memcpy(ptr, s, count);
	trim(ptr);
	skipwhite(&ptr);
	if (*ptr == '+' || *ptr == '-')
		negative = (char)(*ptr++ == '-' ? TRUE : negative);

	/* the last letter has precedence over the sign */
	if (strpbrk(ptr, "SsWw") != NULL)
		negative = TRUE;

	skipwhite(&ptr);
	if ((hh = strpbrk(ptr, "Hh")) != NULL && hh < ptr + 3) {
		type = HOURS;
		if (negative) /* if RA no negative numbers */
			negative = FALSE;
	} else if ((ame = strpbrk(ptr, "SsNn")) != NULL) {
		type = LAT;
		if (ame == ptr) /* the North/South found before data */
			ptr++;
	} else
		type = DEGREES; /* unspecified, the caller must control it */
	if ((ptr = strtok_r(ptr, delim1, &tok_ptr)) != NULL)
		dghh = atoi(ptr);
	else
		return (-0.0);
	if ((ptr = strtok_r(NULL, delim1, &tok_ptr)) != NULL) {
		minutes = atoi(ptr);
		if (minutes > 59)
			return -0.0;
	} else
		return -0.0;

	if ((ptr = strtok_r(NULL, delim2, &tok_ptr)) != NULL) {
		if ((dec = strchr(ptr, ',')) != NULL)
			*dec = '.';
		seconds = strtod(ptr, NULL);
		if (seconds >= 60.0)
			return -0.0;
	}

	if ((ptr = strtok(NULL, " \n\t")) != NULL) {
		skipwhite(&ptr);
		if (*ptr == 'S' || *ptr == 'W' || *ptr == 's' || *ptr == 'w')
			negative = TRUE;
	}

	pos = dghh + minutes / 60.0 + seconds / 3600.0;
	if (type == HOURS && pos > 24.0)
		return -0.0;
	if (type == LAT && pos > 90.0)
		return -0.0;
	if (negative == TRUE)
		pos = 0.0 - pos;

	return pos;
}
const char *ln_get_humanr_location(double location)
{
	char buf[32];
	double deg, min, sec;

	sec = fabs(60.0 * (modf(location, &deg)));
	sec = 60.0 * (modf(sec, &min));
	sprintf(buf, "%+dº%d'%.2f\"", (int)deg, (int)min, sec);

	return strdup(buf);
}
double ln_interpolate3(double n, double y1, double y2, double y3)
{
	double y, a, b, c;

	/* equ 3.2 */
	a = y2 - y1;
	b = y3 - y2;
	c = b - a;

	/* equ 3.3 */
	y = y2 + n / 2.0 * (a + b + n * c);

	return y;
}
double ln_interpolate5(double n, double y1, double y2, double y3, double y4,
					   double y5)
{
	double y, A, B, C, D, E, F, G, H, J, K;
	double n2, n3, n4;

	/* equ 3.8 */
	A = y2 - y1;
	B = y3 - y2;
	C = y4 - y3;
	D = y5 - y4;
	E = B - A;
	F = C - B;
	G = D - C;
	H = F - E;
	J = G - F;
	K = J - H;

	y = 0.0;
	n2 = n * n;
	n3 = n2 * n;
	n4 = n3 * n;

	y += y3;
	y += n * ((B + C) / 2.0 - (H + J) / 12.0);
	y += n2 * (F / 2.0 - K / 24.0);
	y += n3 * ((H + J) / 12.0);
	y += n4 * (K / 24.0);

	return y;
}
double ln_find_zero(double (*func)(double, double *), double from, double to,
					double *arg)
{
	double x, x1, x2, f;
	int i = 0;

	x1 = to;
	x = from;

	do {
		f = func(x1, arg);
		x2 = x1 - f * (x1 - x) / (f - func(x, arg));
		x = x1;
		x1 = x2;
	} while ((fabs(x - x1) > 1e-6) && (i++ < 1000));

	return x2;
}
double ln_find_max(double (*func)(double, double *), double from, double to,
				   double *arg)
{
	double a, b, xl, xu, eps;

	a = from;
	b = to;
	xl = b - (b - a) / GOLDEN;
	xu = a + (b - a) / GOLDEN;
	eps = fabs(b - a);

	do {
		if (func(xl, arg) > func(xu, arg)) {
			b = xu;
			xu = xl;
			xl = b - (b - a) / GOLDEN;
		} else {
			a = xl;
			xl = xu;
			xu = a + (b - a) / GOLDEN;
		}
		eps = fabs(b - a);

	} while (eps > 1e-6);

	return (xu + xl) * 0.5;
}

/* This section is for Win32 substitutions. */
#ifdef __WIN32__
#ifndef __MINGW__

/* Catches calls to the POSIX gettimeofday and converts them to a related WIN32
 * version. */
int gettimeofday(struct timeval *tv, struct timezone *tz)
{
	struct _timeb timeptr;

	_ftime_s(&timeptr);

	tv->tv_sec = timeptr.time;
	tv->tv_usec = timeptr.millitm * 1000;

	tz->tz_dsttime = timeptr.dstflag;
	tz->tz_dsttime = timeptr.timezone;

	return 0;
}
#endif // !__MINGW__

/* Catches calls to the POSIX gmtime_r and converts them to a related WIN32
 * version. */
struct tm *gmtime_r(time_t *t, struct tm *gmt)
{
#ifndef __MINGW__
	gmtime_s(gmt, t);
#else
	struct tm *local_gmt;
	local_gmt = gmtime(t);

	if (local_gmt != 0)
		memcpy(gmt, local_gmt, sizeof(gmt));
#endif // !__MINGW__

	return gmt;
}

/* Catches calls to the POSIX strtok_r and converts them to a related WIN32
 * version. */
char *strtok_r(char *str, const char *sep, char **last)
{
#ifndef __MINGW__
	return strtok_s(str, sep, last);
#else
	return strtok(str, sep);
#endif // !__MINGW__
}

#endif /* __WIN32__ */

/* C89 substitutions for C99 functions. */
#ifdef __C89_SUB__

/* Simple cube root */
double cbrt(double x)
{
	return pow(x, 1.0 / 3.0);
}

#endif /* __C89_SUB__ */

#if defined(__WIN32__) || defined(sun) || defined(__C89_SUB__)

/* Not a Number function generator */
double nan(const char *code)
{
	double zero = 0.0;

	return zero / 0.0;
}

#endif /* defined(__WIN32__) || defined(sun) || defined(__C89_SUB__) */
