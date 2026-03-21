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

#include <libnova2/dynamical_time.h>
#include <libnova2/rise_set.h>
#include <libnova2/sidereal_time.h>
#include <libnova2/transform.h>
#include <libnova2/utility.h>
#include <math.h>

/* \brief helper function to check if object can be visible.
 * \param observer Observers position
 * \param H1 cos(hour angle)
 * \param horizon Horizon height
 * \param object Object position
 * \return 0 for success, 1 for circumpolar (above the horizon), -1 for
 * circumpolar (bellow the horizon)
 *
 * all angles in radians.
 */
static int check_coords(struct ln_lnlat_posn *observer, double H1,
						double horizon, struct ln_equ_posn *object)
{
	double h;

	/* check if body is circumpolar */
	if (fabs(H1) > 1.0) {
		/* check if maximal height < horizon */
		// h = asin(cos(LN_D2R(observer->lat - object->dec)))
		h = M_PI_2 + object->dec - observer->lat;
		// normalize to <-90;+90>
		if (h > M_PI_2)
			h = M_PI - h;
		if (h < -M_PI_2)
			h = -M_PI - h;
		if (h < horizon)
			return -1;
		// else it must be above horizon
		return 1;
	}
	return 0;
}

int ln2_get_object_rst(double JD, struct ln_lnlat_posn *observer,
					   struct ln_equ_posn *object, struct ln_rst_time *rst)
{
	return ln2_get_object_rst_horizon(JD, observer, object,
									  LN_STAR_STANDART_HORIZON,
									  rst); /* standard altitude of stars */
}

int ln2_get_object_rst_horizon(double JD, struct ln_lnlat_posn *observer,
							   struct ln_equ_posn *object, long double horizon,
							   struct ln_rst_time *rst)
{
	return ln2_get_object_rst_horizon_offset(JD, observer, object, horizon, rst,
											 0.5);
}

int ln2_get_object_rst_horizon_offset(double JD, struct ln_lnlat_posn *observer,
									  struct ln_equ_posn *object,
									  long double horizon,
									  struct ln_rst_time *rst, double ut_offset)
{
	int jd;
	long double O, JD_UT, H0, H1;
	double Hat, Har, Has, altr, alts;
	double mt, mr, ms, mst, msr, mss;
	double dmt, dmr, dms;
	int ret, i;

	if (isnan(ut_offset)) {
		JD_UT = JD;
	} else {
		jd = (int)JD;
		JD_UT = jd + ut_offset;
	}

	O = ln2_get_apparent_sidereal_time(JD_UT); /* radians */

	/* equ 15.1 */
	H0 = (sin(horizon) - sin(observer->lat) * sin(object->dec));
	H1 = (cos(observer->lat) * cos(object->dec));

	H1 = H0 / H1;
	ret = check_coords(observer, H1, horizon, object);
	if (ret)
		return ret;

	H0 = acos(H1);

	/* equ 15.2 */
	mt = (object->ra - observer->lng - O) / (2.0 * M_PI);
	mr = mt - H0 / (2.0 * M_PI);
	ms = mt + H0 / (2.0 * M_PI);

	for (i = 0; i < 3; i++) {
		/* put in correct range */
		if (mt > 1.0)
			mt--;
		else if (mt < 0)
			mt++;
		if (mr > 1.0)
			mr--;
		else if (mr < 0)
			mr++;
		if (ms > 1.0)
			ms--;
		else if (ms < 0)
			ms++;

		/* find sidereal time at Greenwich, in degrees, for each m */
		mst = O + LN_D2R(360.985647) * mt;
		msr = O + LN_D2R(360.985647) * mr;
		mss = O + LN_D2R(360.985647) * ms;

		/* find local hour angle */
		Hat = mst + observer->lng - object->ra;
		Har = msr + observer->lng - object->ra;
		Has = mss + observer->lng - object->ra;

		/* find altitude for rise and set */
		altr = sin(observer->lat) * sin(object->dec) +
			   cos(observer->lat) * cos(object->dec) * cos(Har);
		alts = sin(observer->lat) * sin(object->dec) +
			   cos(observer->lat) * cos(object->dec) * cos(Has);

		/* corrections for m */
		ln2_range_radians(Hat);
		if (Hat > M_PI)
			Hat -= 2 * M_PI;

		dmt = -(Hat / (2 * M_PI));
		dmr = (altr - horizon) /
			  (cos(object->dec) * cos(observer->lat) * sin(Har));
		dms = (alts - horizon) /
			  (cos(object->dec) * cos(observer->lat) * sin(Has));

		/* add corrections and change to JD */
		mt += dmt;
		mr += dmr;
		ms += dms;

		if (mt <= 1.0 && mt >= 0.0 && mr <= 1.0 && mr >= 0.0 && ms <= 1.0 &&
			ms >= 0.0)
			break;
	}

	rst->rise = JD_UT + mr;
	rst->transit = JD_UT + mt;
	rst->set = JD_UT + ms;

	/* not circumpolar */
	return 0;
}

int ln2_get_object_next_rst(double JD, struct ln_lnlat_posn *observer,
							struct ln_equ_posn *object, struct ln_rst_time *rst)
{
	return ln2_get_object_next_rst_horizon(JD, observer, object,
										   LN_STAR_STANDART_HORIZON, rst);
}

// helper functions for ln2_get_object_next_rst_horizon
static void set_next_rst(struct ln_rst_time *rst, double diff,
						 struct ln_rst_time *out)
{
	out->rise = rst->rise + diff;
	out->transit = rst->transit + diff;
	out->set = rst->set + diff;
}

static inline double find_next(double JD, double jd1, double jd2, double jd3)
{
	if (isnan(jd1) && isnan(jd2))
		return jd3;

	if (JD < jd1)
		return jd1;

	if (JD < jd2)
		return jd2;

	return jd3;
}

int ln2_get_object_next_rst_horizon(double JD, struct ln_lnlat_posn *observer,
									struct ln_equ_posn *object, double horizon,
									struct ln_rst_time *rst)
{
	int ret;
	struct ln_rst_time rst_1, rst_2;

	ret = ln2_get_object_rst_horizon_offset(JD, observer, object, horizon, rst,
											nan("0"));
	if (ret)
		// circumpolar
		return ret;

	if (rst->rise > (JD + 0.5) || rst->transit > (JD + 0.5) ||
		rst->set > (JD + 0.5))
		ln2_get_object_rst_horizon_offset(JD - 1.0, observer, object, horizon,
										  &rst_1, nan("0"));
	else
		set_next_rst(rst, -1.0, &rst_1);

	if (rst->rise < JD || rst->transit < JD || rst->set < JD)
		ln2_get_object_rst_horizon_offset(JD + 1.0, observer, object, horizon,
										  &rst_2, nan("0"));
	else
		set_next_rst(rst, 1.0, &rst_2);

	rst->rise = find_next(JD, rst_1.rise, rst->rise, rst_2.rise);
	rst->transit = find_next(JD, rst_1.transit, rst->transit, rst_2.transit);
	rst->set = find_next(JD, rst_1.set, rst->set, rst_2.set);

	if (isnan(rst->rise))
		return ret;

	return 0;
}

int ln2_get_body_rst_horizon(double JD, struct ln_lnlat_posn *observer,
							 void (*get_equ_body_coords)(double,
														 struct ln_equ_posn *),
							 double horizon, struct ln_rst_time *rst)
{
	return ln2_get_body_rst_horizon_offset(JD, observer, get_equ_body_coords,
										   horizon, rst, 0.5);
}

int ln2_get_body_rst_horizon_offset(
	double JD, struct ln_lnlat_posn *observer,
	void (*get_equ_body_coords)(double, struct ln_equ_posn *), double horizon,
	struct ln_rst_time *rst, double ut_offset)
{
	int jd;
	double T, O, JD_UT, H0, H1;
	double Hat, Har, Has, altr, alts;
	double mt, mr, ms, mst, msr, mss, nt, nr, ns;
	struct ln_equ_posn sol1, sol2, sol3, post, posr, poss;
	double dmt, dmr, dms;
	int ret, i;

	/* dynamical time diff */
	T = ln2_get_dynamical_time_diff(JD);

	if (isnan(ut_offset)) {
		JD_UT = JD;
	} else {
		jd = (int)JD;
		JD_UT = jd + ut_offset;
	}
	/* convert local sidereal time into radians
           for 0h of UT on day JD */
	O = ln2_get_apparent_sidereal_time(JD_UT);

	/* get body coords for JD_UT -1, JD_UT and JD_UT + 1 */
	get_equ_body_coords(JD_UT - 1.0, &sol1);
	get_equ_body_coords(JD_UT, &sol2);
	get_equ_body_coords(JD_UT + 1.0, &sol3);

	/* equ 15.1 */
	H0 = (sin(horizon) - sin(observer->lat) * sin(sol2.dec));
	H1 = (cos(observer->lat) * cos(sol2.dec));

	H1 = H0 / H1;

	ret = check_coords(observer, H1, horizon, &sol2);
	if (ret)
		return ret;

	H0 = acos(H1);

	/* correct ra values for interpolation	- put them to the same side of
   * circle */
	if ((sol1.ra - sol2.ra) > M_PI)
		sol2.ra += 2.0 * M_PI;

	if ((sol2.ra - sol3.ra) > M_PI)
		sol3.ra += 2.0 * M_PI;

	if ((sol3.ra - sol2.ra) > M_PI)
		sol3.ra -= 2.0 * M_PI;

	if ((sol2.ra - sol1.ra) > M_PI)
		sol2.ra -= 2.0 * M_PI;

	/* equ 15.2 */
	mt = (sol2.ra - observer->lng - O) / (2.0 * M_PI);
	mr = mt - H0 / (2.0 * M_PI);
	ms = mt + H0 / (2.0 * M_PI);

	for (i = 0; i < 3; i++) {
		/* put in correct range */
		if (mt > 1.0)
			mt--;
		else if (mt < 0)
			mt++;
		if (mr > 1.0)
			mr--;
		else if (mr < 0)
			mr++;
		if (ms > 1.0)
			ms--;
		else if (ms < 0)
			ms++;

		/* find sidereal time at Greenwich, in degrees, for each m */
		mst = O + LN_D2R(360.985647) * mt;
		msr = O + LN_D2R(360.985647) * mr;
		mss = O + LN_D2R(360.985647) * ms;

		nt = mt + T / 86400.0;
		nr = mr + T / 86400.0;
		ns = ms + T / 86400.0;

		/* interpolate ra and dec for each m, except for transit dec (dec2) */
		posr.ra = ln2_interpolate3(nr, sol1.ra, sol2.ra, sol3.ra);
		posr.dec = ln2_interpolate3(nr, sol1.dec, sol2.dec, sol3.dec);
		post.ra = ln2_interpolate3(nt, sol1.ra, sol2.ra, sol3.ra);
		poss.ra = ln2_interpolate3(ns, sol1.ra, sol2.ra, sol3.ra);
		poss.dec = ln2_interpolate3(ns, sol1.dec, sol2.dec, sol3.dec);

		/* find local hour angle */
		Hat = mst + observer->lng - post.ra;
		Har = msr + observer->lng - posr.ra;
		Has = mss + observer->lng - poss.ra;

		/* find altitude for rise and set */
		altr = sin(observer->lat) * sin(posr.dec) +
			   cos(observer->lat) * cos(posr.dec) * cos(Har);
		alts = sin(observer->lat) * sin(poss.dec) +
			   cos(observer->lat) * cos(poss.dec) * cos(Has);

		/* corrections for m */
		ln2_range_radians(Hat);
		if (Hat > M_PI)
			Hat -= 2 * M_PI;

		dmt = -(Hat / (2 * M_PI));
		dmr = (altr - horizon) /
			  (2 * M_PI * cos(posr.dec) * cos(observer->lat) * sin(Har));
		dms = (alts - horizon) /
			  (2 * M_PI * cos(poss.dec) * cos(observer->lat) * sin(Has));

		/* add corrections and change to JD */
		mt += dmt;
		mr += dmr;
		ms += dms;

		if (mt <= 1.0 && mt >= 0.0 && mr <= 1.0 && mr >= 0.0 && ms <= 1.0 &&
			ms >= 0.0)
			break;
	}

	rst->rise = JD_UT + mr;
	rst->transit = JD_UT + mt;
	rst->set = JD_UT + ms;

	/* not circumpolar */
	return 0;
}

int ln2_get_body_next_rst_horizon(
	double JD, struct ln_lnlat_posn *observer,
	void (*get_equ_body_coords)(double, struct ln_equ_posn *), double horizon,
	struct ln_rst_time *rst)
{
	return ln2_get_body_next_rst_horizon_future(
		JD, observer, get_equ_body_coords, horizon, 1, rst);
}

int ln2_get_body_next_rst_horizon_future(
	double JD, struct ln_lnlat_posn *observer,
	void (*get_equ_body_coords)(double, struct ln_equ_posn *), double horizon,
	int day_limit, struct ln_rst_time *rst)
{
	int ret;
	struct ln_rst_time rst_1, rst_2;

	ret = ln2_get_body_rst_horizon_offset(JD, observer, get_equ_body_coords,
										  horizon, rst, nan("0"));
	if (ret && day_limit == 1)
		// circumpolar
		return ret;

	if (!ret && (rst->rise > (JD + 0.5) || rst->transit > (JD + 0.5) ||
				 rst->set > (JD + 0.5))) {
		ret = ln2_get_body_rst_horizon_offset(
			JD - 1, observer, get_equ_body_coords, horizon, &rst_1, nan("0"));
		if (ret)
			set_next_rst(rst, -1, &rst_1);
	} else {
		rst->rise = nan("0");
		rst->transit = nan("0");
		rst->set = nan("0");

		set_next_rst(rst, -1, &rst_1);
	}

	if (ret || (rst->rise < JD || rst->transit < JD || rst->set < JD)) {
		// find next day when it will rise, up to day_limit days
		int day = 1;

		while (day <= day_limit) {
			ret = ln2_get_body_rst_horizon_offset(JD + day, observer,
												  get_equ_body_coords, horizon,
												  &rst_2, nan("0"));

			if (!ret) {
				day = day_limit + 2;
				break;
			}
			day++;
		}
		if (day == day_limit + 1)
			// it's then really circumpolar in searched period
			return ret;
	} else {
		set_next_rst(rst, +1, &rst_2);
	}

	rst->rise = find_next(JD, rst_1.rise, rst->rise, rst_2.rise);
	rst->transit = find_next(JD, rst_1.transit, rst->transit, rst_2.transit);
	rst->set = find_next(JD, rst_1.set, rst->set, rst_2.set);
	if (isnan(rst->rise))
		return ret;

	return 0;
}

int ln2_get_motion_body_rst_horizon(
	double JD, struct ln_lnlat_posn *observer,
	get_motion_body_coords_t get_motion_body_coords, void *orbit,
	double horizon, struct ln_rst_time *rst)
{
	return ln2_get_motion_body_rst_horizon_offset(
		JD, observer, get_motion_body_coords, orbit, horizon, rst, 0.5);
}

int ln2_get_motion_body_rst_horizon_offset(
	double JD, struct ln_lnlat_posn *observer,
	get_motion_body_coords_t get_motion_body_coords, void *orbit,
	double horizon, struct ln_rst_time *rst, double ut_offset)
{
	int jd;
	double T, O, JD_UT, H0, H1;
	double Hat, Har, Has, altr, alts;
	double mt, mr, ms, mst, msr, mss, nt, nr, ns;
	struct ln_equ_posn sol1, sol2, sol3, post, posr, poss;
	double dmt, dmr, dms;
	int ret, i;

	/* dynamical time diff */
	T = ln2_get_dynamical_time_diff(JD);

	if (isnan(ut_offset)) {
		JD_UT = JD;
	} else {
		jd = (int)JD;
		JD_UT = jd + ut_offset;
	}
	/* convert local sidereal time into radians
           for 0h of UT on day JD */
	O = ln2_get_apparent_sidereal_time(JD_UT);

	/* get body coords for JD_UT -1, JD_UT and JD_UT + 1 */
	get_motion_body_coords(JD_UT - 1.0, orbit, &sol1);
	get_motion_body_coords(JD_UT, orbit, &sol2);
	get_motion_body_coords(JD_UT + 1.0, orbit, &sol3);

	/* equ 15.1 */
	H0 = (sin(horizon) - sin(observer->lat) * sin(sol2.dec));
	H1 = (cos(observer->lat) * cos(sol2.dec));

	H1 = H0 / H1;

	ret = check_coords(observer, H1, horizon, &sol2);
	if (ret)
		return ret;

	H0 = acos(H1);

	/* correct ra values for interpolation	- put them to the same side of
   * circle */
	if ((sol1.ra - sol2.ra) > M_PI)
		sol2.ra += 2 * M_PI;

	if ((sol2.ra - sol3.ra) > M_PI)
		sol3.ra += 2 * M_PI;

	if ((sol3.ra - sol2.ra) > M_PI)
		sol3.ra -= 2 * M_PI;

	if ((sol2.ra - sol1.ra) > M_PI)
		sol3.ra -= 2 * M_PI;

	for (i = 0; i < 3; i++) {
		/* equ 15.2 */
		mt = (sol2.ra - observer->lng - O) / (2.0 * M_PI);
		mr = mt - H0 / (2.0 * M_PI);
		ms = mt + H0 / (2.0 * M_PI);

		/* put in correct range */
		if (mt > 1.0)
			mt--;
		else if (mt < 0.0)
			mt++;
		if (mr > 1.0)
			mr--;
		else if (mr < 0.0)
			mr++;
		if (ms > 1.0)
			ms--;
		else if (ms < 0.0)
			ms++;

		/* find sidereal time at Greenwich, in degrees, for each m*/
		mst = O + LN_D2R(360.985647) * mt;
		msr = O + LN_D2R(360.985647) * mr;
		mss = O + LN_D2R(360.985647) * ms;

		nt = mt + T / 86400.0;
		nr = mr + T / 86400.0;
		ns = ms + T / 86400.0;

		/* interpolate ra and dec for each m, except for transit dec (dec2) */
		posr.ra = ln2_interpolate3(nr, sol1.ra, sol2.ra, sol3.ra);
		posr.dec = ln2_interpolate3(nr, sol1.dec, sol2.dec, sol3.dec);
		post.ra = ln2_interpolate3(nt, sol1.ra, sol2.ra, sol3.ra);
		poss.ra = ln2_interpolate3(ns, sol1.ra, sol2.ra, sol3.ra);
		poss.dec = ln2_interpolate3(ns, sol1.dec, sol2.dec, sol3.dec);

		/* find local hour angle */
		Hat = mst + observer->lng - post.ra;
		Har = msr + observer->lng - posr.ra;
		Has = mss + observer->lng - poss.ra;

		/* find altitude for rise and set */
		altr = sin(observer->lat) * sin(posr.dec) +
			   cos(observer->lat) * cos(posr.dec) * cos(Har);
		alts = sin(observer->lat) * sin(poss.dec) +
			   cos(observer->lat) * cos(poss.dec) * cos(Has);

		/* corrections for m */
		dmt = -(Hat / (2.0 * M_PI));
		dmr = (altr - horizon) /
			  (2.0 * M_PI * cos(posr.dec) * cos(observer->lat) * sin(Har));
		dms = (alts - horizon) /
			  (2.0 * M_PI * cos(poss.dec) * cos(observer->lat) * sin(Has));

		/* add corrections and change to JD */
		mt += dmt;
		mr += dmr;
		ms += dms;

		if (mt <= 1.0 && mt >= 0.0 && mr <= 1.0 && mr >= 0.0 && ms <= 1.0 &&
			ms >= 0.0)
			break;
	}

	rst->rise = JD_UT + mr;
	rst->transit = JD_UT + mt;
	rst->set = JD_UT + ms;

	/* not circumpolar */
	return 0;
}

int ln2_get_motion_body_next_rst_horizon(
	double JD, struct ln_lnlat_posn *observer,
	get_motion_body_coords_t get_motion_body_coords, void *orbit,
	double horizon, struct ln_rst_time *rst)
{
	return ln2_get_motion_body_next_rst_horizon_future(
		JD, observer, get_motion_body_coords, orbit, horizon, 1, rst);
}

int ln2_get_motion_body_next_rst_horizon_future(
	double JD, struct ln_lnlat_posn *observer,
	get_motion_body_coords_t get_motion_body_coords, void *orbit,
	double horizon, int day_limit, struct ln_rst_time *rst)
{
	int ret;
	struct ln_rst_time rst_1, rst_2;

	ret = ln2_get_motion_body_rst_horizon_offset(
		JD, observer, get_motion_body_coords, orbit, horizon, rst, nan("0"));
	if (ret && day_limit == 1)
		// circumpolar
		return ret;

	if (!ret && (rst->rise > (JD + 0.5) || rst->transit > (JD + 0.5) ||
				 rst->set > (JD + 0.5))) {
		ret = ln2_get_motion_body_rst_horizon_offset(JD - 1.0, observer,
													 get_motion_body_coords,
													 orbit, horizon, &rst_1,
													 nan("0"));
		if (ret)
			set_next_rst(rst, -1.0, &rst_1);
	} else {
		rst->rise = nan("0");
		rst->transit = nan("0");
		rst->set = nan("0");

		set_next_rst(rst, -1.0, &rst_1);
	}

	if (ret || (rst->rise < JD || rst->transit < JD || rst->set < JD)) {
		// find next day when it will rise, up to day_limit days
		int day = 1;

		while (day <= day_limit) {
			ret = ln2_get_motion_body_rst_horizon_offset(JD + day, observer,
														 get_motion_body_coords,
														 orbit, horizon, &rst_2,
														 nan("0"));

			if (!ret) {
				day = day_limit + 2;
				break;
			}
			day++;
		}

		if (day == day_limit + 1)

			// it's then really circumpolar in searched period
			return ret;
	} else {
		set_next_rst(rst, +1.0, &rst_2);
	}

	rst->rise = find_next(JD, rst_1.rise, rst->rise, rst_2.rise);
	rst->transit = find_next(JD, rst_1.transit, rst->transit, rst_2.transit);
	rst->set = find_next(JD, rst_1.set, rst->set, rst_2.set);

	if (isnan(rst->rise))
		return ret;

	return 0;
}
