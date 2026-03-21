/*
 * Aberration, Precession, Nutation Combined Tests
 */

#include "test_helpers.h"
#include <libnova2/libnova2.h>
#include <stdio.h>

int aber_prec_nut_test(void)
{
	double JD;
	struct ln_date date;
	struct ln_equ_posn mean_position, nutated, precessed, aberated;
	struct lnh_equ_posn hmean_position;

	int failed = 0;

	date = LN_DATE(2028, 11, 13, 4, 33, 36);

	JD = ln2_get_julian_day(&date);

	hmean_position.ra.hours = 2;
	hmean_position.ra.minutes = 44;
	hmean_position.ra.seconds = 12.9747;

	hmean_position.dec.neg = 0;
	hmean_position.dec.degrees = 49;
	hmean_position.dec.minutes = 13;
	hmean_position.dec.seconds = 39.896;

	ln2_hequ_to_equ(&hmean_position, &mean_position);

	failed += test_result("(Nutation) Theta Persei RA",
						  LN_R2D(mean_position.ra), 41.0540613, 0.00001);
	failed += test_result("(Nutation) Theta Persei DEC",
						  LN_R2D(mean_position.dec), 49.2277489, 0.00001);

	ln2_get_equ_aber(&mean_position, JD, &aberated);

	failed += test_result(
		"(Aberation) Theta Persei position on 13th November 2028 RA",
		LN_R2D(aberated.ra), 41.0623836, 0.0001);
	failed += test_result(
		"(Aberation) Theta Persei position on 13th November 2028 DEC",
		LN_R2D(aberated.dec), 49.2296238, 0.00001);

	ln2_get_equ_prec(&aberated, JD, &precessed);

	failed += test_result(
		"(Aberation + Precession) Theta Persei position on 13th November 2028 RA",
		LN_R2D(precessed.ra), 41.5555635, 0.0001);
	failed += test_result("(Aberation + Precession) Theta Persei position on "
						  "13th November 2028 DEC",
						  LN_R2D(precessed.dec), 49.3503415, 0.00001);

	ln2_get_equ_nut(&precessed, JD, &nutated);

	failed += test_result("(Aberation + Precession + Nutation) Theta Persei "
						  "position on 13th November 2028 RA",
						  LN_R2D(nutated.ra), 41.55627214, 0.0001);
	failed += test_result("(Aberation + Precession + Nutation) Theta Persei "
						  "position on 13th November 2028 DEC",
						  LN_R2D(nutated.dec), 49.35063679, 0.00001);

	return failed;
}
