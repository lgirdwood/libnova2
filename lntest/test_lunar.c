/*
 * Lunar Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <stdio.h>

int lunar_test(void)
{
	double JD = 2451545.0;
	struct ln_rect_posn rect;
	struct ln_equ_posn equ;
	struct ln_lnlat_posn ecl;
	double val, dist;
	int failed = 0;

	/* Geo Posn */
	ln2_get_lunar_geo_posn(JD, &rect, 0.0);
	failed += test_result("Lunar Geo X", rect.X, -291608.232406131981, 1e-4); /* Larger tolerance for km? */
	failed += test_result("Lunar Geo Y", rect.Y, -274979.944143373286, 1e-4);
	failed += test_result("Lunar Geo Z", rect.Z, 36271.170510452852, 1e-4);

	/* Equ Coords */
	ln2_get_lunar_equ_coords(JD, &equ);
	failed += test_result("Lunar Equ RA", equ.ra, 3.882450687979, 1e-6);
	failed += test_result("Lunar Equ Dec", equ.dec, -0.190185905046, 1e-6);

	/* Ecl Coords */
	ln2_get_lunar_ecl_coords(JD, &ecl, 0.0);
	failed += test_result("Lunar Ecl Lng", ecl.lng, -2.385534171769, 1e-6);
	failed += test_result("Lunar Ecl Lat", ecl.lat, 0.090248663859, 1e-6);

	/* Phase */
	val = ln2_get_lunar_phase(JD);
	failed += test_result("Lunar Phase", val, 2.140926075489, 1e-6);

	/* Disk */
	val = ln2_get_lunar_disk(JD);
	failed += test_result("Lunar Disk", val, 0.230129360128, 1e-6);

	/* Earth Dist */
	dist = ln2_get_lunar_earth_dist(JD);
	failed += test_result("Lunar Earth Dist", dist, 402448.665916933736, 1e-4);

	/* Sdiam */
	val = ln2_get_lunar_sdiam(JD);
	failed += test_result("Lunar Sdiam", val, 890.730744959134, 1e-6);

	/* Bright Limb */
	val = ln2_get_lunar_bright_limb(JD);
	failed += test_result("Lunar Bright Limb", val, 1.928220661158, 1e-6);

	/* Long Asc Node */
	val = ln2_get_lunar_long_asc_node(JD);
	failed += test_result("Lunar Long Asc Node", val, 2.182439072523, 1e-6);

	/* Long Perigee */
	val = ln2_get_lunar_long_perigee(JD);
	failed += test_result("Lunar Long Perigee", val, 1.454788593651, 1e-6);

	/* Arg Latitude */
	val = ln2_get_lunar_arg_latitude(JD);
	failed += test_result("Lunar Arg Latitude", val, 1.627905233032, 1e-6);

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
	ln2_get_lunar_equ_coords(JD, &equ);
	if (equ.ra == 0 && equ.dec == 0)
		failed++;

	/* Lunar Sdiam */
	res = ln2_get_lunar_sdiam(JD);
	failed += test_result("(Lunar) Semidiameter J2000", res, 900.0, 100.0);

	/* Arg Latitude */
	res = ln2_get_lunar_arg_latitude(JD);
	/* Mean arg lat at J2000 is 93.27 deg */
	failed += test_result("(Lunar) Arg Latitude J2000", res, LN_D2R(93.27), 10.0);

	/* Long Asc Node */
	res = ln2_get_lunar_long_asc_node(JD);
	/* Mean long asc node at J2000 is 125.04 */
	failed += test_result("(Lunar) Long Asc Node J2000", res, LN_D2R(125.04), 1.0);

	/* Long Perigee */
	res = ln2_get_lunar_long_perigee(JD);
	/* Mean long perigee at J2000 is 83.35 */
	failed += test_result("(Lunar) Long Perigee J2000", res, LN_D2R(83.35), 1.0);

	/* Lunar next/prev phase/node/perigee/apogee */
	/* ln2_lunar_next_phase: phase 0=new, 0.25=first q, 0.5=full, 0.75=last q */
	/* Phase is 0..360? Docs say "0 = New Moon, 90 = First Quarter..." so
   * 0.0, 90.0 etc. */
	/* Wait, param says "0=New Moon, 90=First Quarter". */
	res = ln2_lunar_next_phase(JD, 0.0);
	if (res <= JD)
		failed++;
	res = ln2_lunar_next_node(JD, 0); /* 0=Descending? Header says: 1=Ascending, 0=Descending */
	if (res <= JD)
		failed++;

	/* Perigee (mode=0), Apogee (mode=1) */
	res = ln2_lunar_next_apsis(JD, 0);
	if (res <= JD)
		failed++;
	res = ln2_lunar_next_apsis(JD, 1);
	if (res <= JD)
		failed++;

	res = ln2_lunar_previous_phase(JD, 0.0);
	if (res >= JD)
		failed++;
	res = ln2_lunar_previous_node(JD, 0);
	if (res >= JD)
		failed++;
	res = ln2_lunar_previous_apsis(JD, 0);
	if (res >= JD)
		failed++;
	res = ln2_lunar_previous_apsis(JD, 1);
	if (res >= JD)
		failed++;

	if (failed == 0) {
		printf("TEST (Lunar) Extended....[PASSED]\n");
	} else {
		printf("TEST (Lunar) Extended....[FAILED] %d errors\n", failed);
	}

	return failed;
}
