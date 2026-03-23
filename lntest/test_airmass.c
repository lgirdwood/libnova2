/*
 * Airmass Tests
 */

#include <stdio.h>
#include <libnova2/libnova2.h>
#include "test_helpers.h"

int airmass_test(void)
{
	int failed = 0;
	double x, X, res;

	X = ln2_get_airmass(LN_D2R(90.0), 750.0);
	failed += test_result("(Airmass) Airmass at Zenith", X, 1.0, 0.01);

	X = ln2_get_airmass(LN_D2R(10.0), 750.0);
	failed +=
	    test_result("(Airmass) Airmass at 10 degrees altitude", X, 5.64, 0.1);

	X = ln2_get_alt_from_airmass(1.0, 750.0);
	failed +=
	    test_result("(Airmass) Altitude at airmass 1", LN_R2D(X), 90.0, 0.01);

	for (x = -10; x < 90; x += 10.54546456) {
		res =
		    ln2_get_alt_from_airmass(ln2_get_airmass(LN_D2R(x), 750.0), 750.0);
		failed += test_result("(Airmass) Altitude->Airmass->Altitude",
		                      LN_R2D(res), x, 0.0001);
	}

	return failed;
}
