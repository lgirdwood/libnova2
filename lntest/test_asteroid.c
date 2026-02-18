/*
 * Asteroid and Misc Tests
 */

#include <stdio.h>
#include <libnova/libnova.h>
#include "test_helpers.h"

/* Helper for find_max/zero */
static double test_func(double x, double *arg)
{
	/* Parabola y = -(x-2)^2 + 4. Max at x=2, y=4. Zeros at x=0, x=4. */
	return -(x-2.0)*(x-2.0) + 4.0;
}

int asteroids_misc_test(void)
{
	int failed = 0;
	double res;

	/* Asteroids */
	/* Ceres diam approx 900-1000km */
	/* Mag 10. Dist 2 AU. */
	/* ln2_get_asteroid_sdiam_km(H, A) - Wait, A is Albedo? header said H, A. */
	/* ln2_get_asteroid_sdiam_km(double H, double A) */
	/* Ceres H=3.34, Albedo approx 0.09 */
	res = ln2_get_asteroid_sdiam_km(3.34, 0.09);
	failed += test_result("(Asteroid) Ceres sdiam km (H=3.34, A=0.09)", res, 950.0, 100.0);

	/* ln2_get_asteroid_sdiam_arc(JD, orbit, H, A) */
	{
		struct ln_ell_orbit orbit;
		/* Dummy orbit for Ceres */
		orbit.a = 2.76; orbit.e = 0.08; orbit.i = 10.6; orbit.w = 73.0; orbit.omega = 80.0; orbit.n = 0.214; orbit.JD = 2451545.0;
		res = ln2_get_asteroid_sdiam_arc(2451545.0, &orbit, 3.34, 0.09); /* J2000 */
		/* Should return something reasonable > 0 */
		if (res <= 0.0) {
			printf("TEST (Asteroid) sdiam arc....[FAILED]\n");
            failed++;
		} else {
             printf("TEST (Asteroid) sdiam arc....[PASSED]\n");
        }
	}

	/* Light time */
	/* Dist 1 AU. Light time approx 499s = 0.0057 days */
	res = ln2_get_light_time(1.0);
	failed += test_result("(Misc) Light Time 1AU", res, 0.0057, 0.0001);

	/* Refraction Adj */
	/* Standard conditions. Alt 30 deg. */
	res = ln2_get_refraction_adj(30.0, 1010.0, 10.0);
	failed += test_result("(Misc) Refraction Adj 30deg", res, 0.0, 1.0); /* Just check it returns something small */
	
	/* Math find max/zero */
	/* find max between 0 and 4. Should be 2. */
	/* double ln2_find_max(double (*func) (double, double *), double from, double to, double *arg) */
	res = ln2_find_max(test_func, 0.0, 4.0, NULL);
	failed += test_result("(Misc) find_max Parabola", res, 2.0, 0.001);

	/* find zero between 3 and 5. Should be 4. */
	res = ln2_find_zero(test_func, 3.0, 5.0, NULL);
	failed += test_result("(Misc) find_zero Parabola", res, 4.0, 0.001);

	return failed;
}
