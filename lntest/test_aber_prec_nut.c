/*
 * Aberration, Precession, Nutation Combined Tests
 */

#include <stdio.h>
#include <libnova/libnova.h>
#include "test_helpers.h"

int aber_prec_nut_test(void)
{
	double JD;
	struct ln_date date;
	struct ln_equ_posn mean_position, nutated, precessed, aberated;
	struct lnh_equ_posn hmean_position;

	int failed = 0;

	date.years = 2028;
	date.months = 11;
	date.days = 13;
	date.hours = 4;
	date.minutes = 33;
	date.seconds = 36;

	JD = ln_get_julian_day(&date);

	hmean_position.ra.hours = 2;
	hmean_position.ra.minutes = 44;
	hmean_position.ra.seconds = 12.9747;

	hmean_position.dec.neg = 0;
	hmean_position.dec.degrees = 49;
	hmean_position.dec.minutes = 13;
	hmean_position.dec.seconds = 39.896;

	ln_hequ_to_equ(&hmean_position, &mean_position);

	failed += test_result("(Nutation) Theta Persei RA",
		ln_rad_to_deg(mean_position.ra), 41.0540613, 0.00001);
	failed += test_result("(Nutation) Theta Persei DEC",
		ln_rad_to_deg(mean_position.dec), 49.2277489, 0.00001);

	ln_get_equ_aber(&mean_position, JD, &aberated);

	failed += test_result ("(Aberation) Theta Persei position on 13th November 2028 RA",
		ln_rad_to_deg(aberated.ra), 41.0623836, 0.0001);
	failed += test_result ("(Aberation) Theta Persei position on 13th November 2028 DEC",
		ln_rad_to_deg(aberated.dec), 49.2296238, 0.00001);

	ln_get_equ_prec(&aberated, JD, &precessed);

	failed += test_result ("(Aberation + Precession) Theta Persei position on 13th November 2028 RA",
		ln_rad_to_deg(precessed.ra), 41.5555635, 0.0001);
	failed += test_result ("(Aberation + Precession) Theta Persei position on 13th November 2028 DEC",
		ln_rad_to_deg(precessed.dec), 49.3503415, 0.00001);

	ln_get_equ_nut(&precessed, JD, &nutated);

	failed += test_result ("(Aberation + Precession + Nutation) Theta Persei position on 13th November 2028 RA",
		ln_rad_to_deg(nutated.ra), 41.5599646, 0.0001);
	failed += test_result ("(Aberation + Precession + Nutation) Theta Persei position on 13th November 2028 DEC",
		ln_rad_to_deg(nutated.dec), 49.3520685, 0.00001);

	return failed;
}
