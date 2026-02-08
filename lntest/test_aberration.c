/*
 * Aberration Tests
 */

#include <stdio.h>
#include <libnova/libnova.h>
#include "test_helpers.h"

int aberration_test(void)
{
	struct lnh_equ_posn hobject;
	struct ln_equ_posn object, pos;
	struct ln_date date;
	double JD;
	int failed = 0;
	
	/* object position */
	hobject.ra.hours = 2;
	hobject.ra.minutes = 44;
	hobject.ra.seconds = 12.9747;
	hobject.dec.neg = 0;
	hobject.dec.degrees = 49;
	hobject.dec.minutes = 13;
	hobject.dec.seconds = 39.896;

	/* date */
	date.years = 2028;
	date.months = 11;
	date.days = 13;
	date.hours = 4;
	date.minutes = 31;
	date.seconds = 0;

	JD = ln_get_julian_day(&date);

	ln_hequ_to_equ(&hobject, &object);
	ln_get_equ_aber(&object, JD, &pos);
	failed += test_result("(Aberration) RA  ", ln_rad_to_deg(pos.ra),
		41.06238352, 0.00000001);
	failed += test_result("(Aberration) DEC  ", ln_rad_to_deg(pos.dec),
		49.22962359, 0.00000001);
	return failed;
}
