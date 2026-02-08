/*
 * Lunar Tests
 */

#include <stdio.h>
#include <libnova/libnova.h>
#include "test_helpers.h"

int lunar_test(void)
{
	double JD = 2448724.5;
	
	struct ln_rect_posn moon;
	struct ln_equ_posn equ;
	struct ln_lnlat_posn ecl;
	int failed = 0;
	
	/*	JD = get_julian_from_sys();*/
	/*JD=2448724.5;*/
	ln_get_lunar_geo_posn(JD, &moon, 0);
	fprintf(stdout, "lunar x %f  y %f  z %f\n",moon.X, moon.Y, moon.Z);
	ln_get_lunar_ecl_coords(JD, &ecl, 0);
	fprintf(stdout, "lunar long %f  lat %f\n",ecl.lng, ecl.lat);
	ln_get_lunar_equ_coords_prec(JD, &equ, 0);
	fprintf(stdout, "lunar RA %f  Dec %f\n",ln_rad_to_deg(equ.ra), ln_rad_to_deg(equ.dec));
	fprintf(stdout, "lunar distance km %f\n", ln_get_lunar_earth_dist(JD));
	fprintf(stdout, "lunar disk %f\n", ln_get_lunar_disk(JD));
	fprintf(stdout, "lunar phase %f\n", ln_get_lunar_phase(JD));
	fprintf(stdout, "lunar bright limb %f\n", ln_get_lunar_bright_limb(JD));
	return failed;
}

int lunar_extended_test(void)
{
	int failed = 0;
	double JD, res;
	struct ln_equ_posn equ;
	/* struct ln_lnlat_posn ecl; */

	JD = 2451545.0; /* J2000 */

	/* Lunar Equ Coords (Prec?) */
	ln_get_lunar_equ_coords(JD, &equ);
	if (equ.ra == 0 && equ.dec == 0) failed++;

	/* Lunar Sdiam */
	res = ln_get_lunar_sdiam(JD);
	failed += test_result("(Lunar) Semidiameter J2000", res, 900.0, 100.0);

	/* Arg Latitude */
	res = ln_get_lunar_arg_latitude(JD);
	/* Mean arg lat at J2000 is 93.27 deg */
	failed += test_result("(Lunar) Arg Latitude J2000", res, 93.27, 10.0);

	/* Long Asc Node */
	res = ln_get_lunar_long_asc_node(JD);
	/* Mean long asc node at J2000 is 125.04 */
	failed += test_result("(Lunar) Long Asc Node J2000", res, 125.04, 1.0);

	/* Long Perigee */
	res = ln_get_lunar_long_perigee(JD);
	/* Mean long perigee at J2000 is 83.35 */
	failed += test_result("(Lunar) Long Perigee J2000", res, 83.35, 1.0);

	/* Lunar next/prev phase/node/perigee/apogee */
	/* ln_lunar_next_phase: phase 0=new, 0.25=first q, 0.5=full, 0.75=last q */
	/* Phase is 0..360? Docs say "0 = New Moon, 90 = First Quarter..." so 0.0, 90.0 etc. */
	/* Wait, param says "0=New Moon, 90=First Quarter". */
	res = ln_lunar_next_phase(JD, 0.0);
	if (res <= JD) failed++;
	res = ln_lunar_next_node(JD, 0); /* 0=Descending? Header says: 1=Ascending, 0=Descending */
	if (res <= JD) failed++;
	
	/* Perigee (mode=0), Apogee (mode=1) */
	res = ln_lunar_next_apsis(JD, 0);
	if (res <= JD) failed++;
	res = ln_lunar_next_apsis(JD, 1);
	if (res <= JD) failed++;
	
	res = ln_lunar_previous_phase(JD, 0.0);
	if (res >= JD) failed++;
	res = ln_lunar_previous_node(JD, 0);
	if (res >= JD) failed++;
	res = ln_lunar_previous_apsis(JD, 0);
	if (res >= JD) failed++;
	res = ln_lunar_previous_apsis(JD, 1);
	if (res >= JD) failed++;

	if (failed == 0) {
        printf("TEST (Lunar) Extended....[PASSED]\n");
    } else {
        printf("TEST (Lunar) Extended....[FAILED] %d errors\n", failed);
    }
	
	return failed;
}
