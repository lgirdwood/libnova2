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


typedef struct {
    int (*func)(void);
    const char *name;
    int tests_run;
    int tests_failed;
} test_module_t;

int main(int argc, const char *argv[])
{
	int failed = 0;
    int i;
    
    test_module_t modules[] = {
        { julian_test, "Julian Day" },
        { date_time_test, "Date Time" },
        { dynamical_test, "Dynamical Time" },
        { heliocentric_test, "Heliocentric Time" },
        { sidereal_test, "Sidereal Time" },
        { nutation_test, "Nutation" },
        { aber_prec_nut_test, "Aberration, Prec, Nut" },
        { transform_test, "Coordinate Transforms" },
        { solar_coord_test, "Solar Coordinates" },
        { solar_earth_test, "Solar/Earth" },
        { aberration_test, "Aberration" },
        { precession_test, "Precession" },
        { apparent_position_test, "Apparent Position" },
        { vsop87_test, "VSOP87" },
        { planetary_rect_rst_test, "Planetary Rect/RST" },
        { lunar_test, "Lunar" },
        { lunar_extended_test, "Lunar Extended" },
        { elliptic_motion_test, "Elliptic Motion" },
        { parabolic_motion_test, "Parabolic Motion" },
        { hyperbolic_motion_test, "Hyperbolic Motion" },
        { elliptic_parabolic_test, "Elliptic/Parabolic" },
        { rst_test, "Rise/Set/Transit" },
        { ell_rst_test, "Elliptic RST" },
        { hyp_future_rst_test, "Hyperbolic Future RST" },
        { body_future_rst_test, "Body Future RST" },
        { parallax_test, "Parallax" },
        { angular_test, "Angular Separation" },
        { utility_test, "Utility" },
        { utility_conversion_test, "Utility Conversion" },
        { asteroids_misc_test, "Asteroids/Misc" },
        { airmass_test, "Airmass" },
        { constellation_test, "Constellation" }
    };

    int num_modules = sizeof(modules) / sizeof(modules[0]);

	start_timer();

    for (i = 0; i < num_modules; i++) {
        int start_tests = test_number;
        modules[i].tests_failed = modules[i].func();
        modules[i].tests_run = test_number - start_tests;
        failed += modules[i].tests_failed;
    }
	
	end_timer();

    fprintf(stdout, "\n\nTest Summary:\n");
    fprintf(stdout, "------------------------------------------------------------------\n");
    fprintf(stdout, "%-25s | %5s | %6s | %6s\n", "Module", "Run", "Passed", "Failed");
    fprintf(stdout, "------------------------------------------------------------------\n");
    for (i = 0; i < num_modules; i++) {
        fprintf(stdout, "%-25s | %5d | %6d | %6d\n", 
               modules[i].name, 
               modules[i].tests_run, 
               modules[i].tests_run - modules[i].tests_failed, 
               modules[i].tests_failed);
    }
    fprintf(stdout, "------------------------------------------------------------------\n");
	fprintf(stdout, "Total: %d tests, %d errors.\n",
		test_number, failed);
		
	return 0;
}
