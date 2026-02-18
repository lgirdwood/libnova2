/*
 * Precession Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <libnova/proper_motion.h>
#include <stdio.h>

int precession_test(void)
{
	double JD;
	struct ln_equ_posn object, pos, pos2, pm;
	struct lnh_equ_posn hobject;
	struct ln_date grb_date;
	int failed = 0;

	/* object position */
	hobject.ra.hours = 2;
	hobject.ra.minutes = 44;
	hobject.ra.seconds = 11.986;
	hobject.dec.neg = 0;
	hobject.dec.degrees = 49;
	hobject.dec.minutes = 13;
	hobject.dec.seconds = 42.48;

	JD = 2462088.69;
	ln2_hequ_to_equ(&hobject, &object);

	/* pm measured in arcsec/year - convert to radians */
	pm.ra = LN_D2R(0.03425 / 3600.0);
	pm.dec = LN_D2R(-0.0895 / 3600.0);

	ln2_get_equ_pm(&object, &pm, JD, &object);

	failed += test_result_dms("(Proper motion) RA on JD 2462088.69  ", LN_R2D(object.ra), 41.05021630, 0.00001);
	failed += test_result_dms("(Proper motion) DEC on JD 2462088.69  ", LN_R2D(object.dec), 49.227750, 0.00001);

	ln2_get_equ_prec(&object, JD, &pos);
	failed += test_result_dms("(Precession) RA on JD 2462088.69  ", LN_R2D(pos.ra), 41.54333349, 0.00003);
	failed += test_result_dms("(Precession) DEC on JD 2462088.69  ", LN_R2D(pos.dec), 49.34849687, 0.00001);

	ln2_get_equ_prec2(&object, JD2000, JD, &pos);

	failed += test_result_dms("(Precession 2) RA on JD 2462088.69  ", LN_R2D(pos.ra), 41.54333349, 0.00001);
	failed += test_result_dms("(Precession 2) DEC on JD 2462088.69  ", LN_R2D(pos.dec), 49.34849687, 0.00001);

	ln2_get_equ_prec2(&pos, JD, JD2000, &pos2);

	failed += test_result_dms("(Precession 2) RA on JD 2451545.0  ", LN_R2D(pos2.ra), LN_R2D(object.ra), 0.00001);
	failed += test_result_dms("(Precession 2) DEC on JD 2451545.0  ", LN_R2D(pos2.dec), LN_R2D(object.dec), 0.00001);

	// INTEGRAL GRB050922A coordinates lead to RA not in <0-360> range
	pos.ra = LN_D2R(271.2473);
	pos.dec = LN_D2R(-32.0227);

	grb_date = LN_DATE(2005, 9, 22, 13, 43, 18.0);

	JD = ln2_get_julian_day(&grb_date);
	ln2_get_equ_prec2(&pos, JD, JD2000, &pos2);

	failed += test_result_dms("(Precession 2) RA on JD 2451545.0  ", LN_R2D(pos2.ra), 271.1541, 0.0002);
	failed += test_result_dms("(Precession 2) DEC on JD 2451545.0  ", LN_R2D(pos2.dec), -32.0235, 0.0002);

	// second test from AA, p. 128
	hobject.ra.hours = 2;
	hobject.ra.minutes = 31;
	hobject.ra.seconds = 48.704;
	hobject.dec.neg = 0;
	hobject.dec.degrees = 89;
	hobject.dec.minutes = 15;
	hobject.dec.seconds = 50.72;

	ln2_hequ_to_equ(&hobject, &object);

	// proper motions
	pm.ra = LN_D2R(((long double)0.19877) / 3600.0);
	pm.dec = LN_D2R(((long double)-0.0152) / 3600.0);

	ln2_get_equ_pm(&object, &pm, B1900, &pos);

	ln2_get_equ_prec2(&pos, JD2000, B1900, &pos2);

	// the position is so close to pole, that it depends a lot on how precise
	// functions we will use. So we get such big errors compared to Meeus.
	// I checked results agains SLAlib on-line calculator and SLAlib performs
	// even worse then we

	failed += test_result("(Precession 2) RA on B1900  ", LN_R2D(pos2.ra), 20.68729628, 0.002);
	failed += test_result("(Precession 2) DEC on B1900  ", LN_R2D(pos2.dec), 88.77431170, 0.0001);

	ln2_get_equ_pm(&object, &pm, JD2050, &pos);

	ln2_get_equ_prec2(&pos, JD2000, JD2050, &pos2);

	failed += test_result("(Precession 2) RA on J2050  ", LN_R2D(pos2.ra), 57.02160084, 0.003);
	failed += test_result("(Precession 2) DEC on J2050  ", LN_R2D(pos2.dec), 89.45444522, 0.0001);

	return failed;
}
