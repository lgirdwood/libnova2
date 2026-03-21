/*
 * Constellation Tests
 */

#include <stdio.h>
#include <libnova2/libnova2.h>
#include "test_helpers.h"

int constellation_test(void)
{
	int i;

	int failed = 0;

	struct {
		double ra;
		double dec;
		const char *constel;
	} test_c[] = { { 127.1810, 14.2177, "Cnc" },  { 139.0884, 11.5273, "Leo" },
				   { 139.0884, 11.5273, "Leo" },  { 150.7003, 8.3804, "Leo" },
				   { 162.0989, 4.9088, "Leo" },	  { 173.3865, 1.2455, "Vir" },
				   { 184.6787, -2.4756, "Vir" },  { 219.8070, -12.6071, "Lib" },
				   { 232.3073, -15.1551, "Lib" }, { 245.3311, -17.0311, "Oph" },
				   { 258.8877, -18.0809, "Oph" }, { 272.9237, -18.1687, "Sgr" },
				   { 287.3266, -17.2004, "Sgr" }, { 301.9481, -15.1508, "Cap" },
				   { 316.6420, -12.0870, "Aqr" }, { 331.3001, -8.1780, "Aqr" },
				   { 345.8704, -3.6867, "Psc" },  { 0.3515, 1.0575, "Psc" },
				   { 14.7686, 5.6999, "Psc" },	  { 29.1425, 9.9069, "Psc" },
				   { 43.4634, 13.4057, "Ari" },	  { 57.6785, 16.0084, "Tau" },
				   { 71.6973, 17.6196, "Tau" },	  { 85.4141, 18.2277, "Tau" },
				   { 98.7371, 17.8859, "Gem" },	  { 111.6113, 16.6902, "Gem" },
				   { 124.0301, 14.7589, "Cnc" },  { 136.0329, 12.2183, "Cnc" },
				   { 147.6959, 9.1950, "Leo" },	  { 0, 0, NULL } };

	for (i = 0;; i++) {
		if (test_c[i].constel == NULL)
			break;

		struct ln_equ_posn equ;
		const char *constel;
		char test_r[200];

		equ.ra = LN_D2R(test_c[i].ra);
		equ.dec = LN_D2R(test_c[i].dec);
		constel = ln2_get_constellation(&equ);
		sprintf(test_r, "Constellation at %.04f %+.04f", equ.ra, equ.dec);
		failed += test_str_result(test_r, constel, test_c[i].constel);
	}

	return failed;
}
