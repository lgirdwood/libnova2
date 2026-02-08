/*
 * Main Test Runner
 */

#include <stdio.h>
#include "test_helpers.h"

/* Declarations */
int julian_test(void);
int date_time_test(void);
int dynamical_test(void);
int heliocentric_test(void);
int sidereal_test(void);
int nutation_test(void);
int aber_prec_nut_test(void);
int transform_test(void);
int solar_coord_test(void);
int solar_earth_test(void);
int aberration_test(void);
int precession_test(void);
int apparent_position_test(void);
int vsop87_test(void);
int planetary_rect_rst_test(void);
int lunar_test(void);
int lunar_extended_test(void);
int elliptic_motion_test(void);
int parabolic_motion_test(void);
int hyperbolic_motion_test(void);
int elliptic_parabolic_test(void);
int rst_test(void);
int ell_rst_test(void);
int hyp_future_rst_test(void);
int body_future_rst_test(void);
int parallax_test(void);
int angular_test(void);
int utility_test(void);
int utility_conversion_test(void);
int asteroids_misc_test(void);

int airmass_test(void);
int constellation_test(void);

int main(int argc, const char *argv[])
{
	int failed = 0;
	
	start_timer();

	failed += julian_test();
	failed += date_time_test();
	failed += dynamical_test();
	failed += heliocentric_test ();
	failed += sidereal_test();
	failed += nutation_test();
	failed += aber_prec_nut_test();
	failed += transform_test();
	failed += solar_coord_test ();
	failed += solar_earth_test();
	failed += aberration_test();
	failed += precession_test();
	failed += apparent_position_test ();
	failed += vsop87_test();
	failed += planetary_rect_rst_test();
	failed += lunar_test ();
	failed += lunar_extended_test();
	failed += elliptic_motion_test();
	failed += parabolic_motion_test ();
	failed += hyperbolic_motion_test ();
	failed += elliptic_parabolic_test();
	failed += rst_test ();
	failed += ell_rst_test ();
	failed += hyp_future_rst_test ();
	failed += body_future_rst_test ();
	failed += parallax_test ();
	failed += angular_test();
	failed += utility_test();
	failed += utility_conversion_test();
	failed += asteroids_misc_test();

	failed += airmass_test ();
    failed += constellation_test ();
	
	end_timer();
	fprintf(stdout, "Test completed: %d tests, %d errors.\n",
		test_number, failed);
		
	return 0;
}
