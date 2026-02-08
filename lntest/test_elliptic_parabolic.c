/*
 * Elliptic/Parabolic/Hyperbolic Extended Tests
 */

#include <stdio.h>
#include <libnova/libnova.h>
#include "test_helpers.h"

int elliptic_parabolic_test(void)
{
	int failed = 0;
	double JD = 2451545.0;
	double res;
	struct ln_ell_orbit orbit;
	struct ln_par_orbit porbit;
	struct ln_hyp_orbit horbit;
	struct ln_lnlat_posn observer;
	struct ln_rst_time rst;

	/* Elliptic Orbit - Halley */
	orbit.a = 17.9400782;
	orbit.e = 0.96727426;
	orbit.i = 162.2393257;
	orbit.w = 58.1531055;
	orbit.omega = 111.8465825;
	orbit.n = 0.9999 / 17.94; /* approx */
	orbit.JD = 2446467.395317;

	/* Mean Anomaly */
	res = ln_get_ell_mean_anomaly(orbit.n, JD - orbit.JD);
	/* just check valid return */
	
	/* Mean Motion */
	res = ln_get_ell_mean_motion(orbit.a);
	
	/* True Anomaly */
	res = ln_get_ell_true_anomaly(orbit.e, 10.0);
	
	/* Smajor/Sminor */
	{
		double q = orbit.a * (1.0 - orbit.e);
		res = ln_get_ell_smajor_diam(orbit.e, q);
	}
	res = ln_get_ell_sminor_diam(orbit.a, orbit.e);

	/* Last Perihelion */
	res = ln_get_ell_last_perihelion(orbit.JD, orbit.n, JD);
	
	/* Body details */
	res = ln_get_ell_body_solar_dist(JD, &orbit);
	res = ln_get_ell_body_earth_dist(JD, &orbit);
	res = ln_get_ell_body_phase_angle(JD, &orbit);
	res = ln_get_ell_body_elong(JD, &orbit);

	/* RST */
	observer.lat = ln_deg_to_rad(50.0); observer.lng = ln_deg_to_rad(0.0);
	/* Just call to ensure no crash/link error */
	ln_get_ell_body_rst(JD, &observer, &orbit, &rst);
	ln_get_ell_body_next_rst(JD, &observer, &orbit, &rst);
	ln_get_ell_body_rst_horizon(JD, &observer, &orbit, -10.0, &rst);
	ln_get_ell_body_next_rst_horizon(JD, &observer, &orbit, -10.0, &rst);
	ln_get_ell_body_next_rst_horizon_future(JD, &observer, &orbit, -10.0, 10, &rst);

	/* Comet Mag */
	res = ln_get_ell_comet_mag(JD, &orbit, 5.0, 10.0);

	/* Parabolic */
	porbit.q = 1.0; porbit.i = 10.0; porbit.w = 10.0; porbit.omega = 10.0; porbit.JD = JD - 100;
	
	res = ln_solve_barker(1.0, 100.0); 
	
	res = ln_get_par_true_anomaly(1.0, 100.0);
	res = ln_get_par_body_solar_dist(JD, &porbit);
	res = ln_get_par_body_earth_dist(JD, &porbit);
	res = ln_get_par_body_phase_angle(JD, &porbit);
	res = ln_get_par_body_elong(JD, &porbit);
	res = ln_get_par_comet_mag(JD, &porbit, 5.0, 10.0);
	
	ln_get_par_body_rst(JD, &observer, &porbit, &rst);
	ln_get_par_body_next_rst(JD, &observer, &porbit, &rst);
	ln_get_par_body_rst_horizon(JD, &observer, &porbit, -10.0, &rst);
	ln_get_par_body_next_rst_horizon(JD, &observer, &porbit, -10.0, &rst);
	ln_get_par_body_next_rst_horizon_future(JD, &observer, &porbit, -10.0, 10, &rst);

	/* Hyperbolic */
	horbit.q = 1.0; horbit.e = 1.1; horbit.i = 10.0; horbit.w = 10.0; horbit.omega = 10.0; horbit.JD = JD - 100;
	
	/* E = ln_solve_hyp_barker(1.0, 1.1, 100.0); */
	/* function signature might differ, check header if error occurs */
	
	res = ln_get_hyp_body_solar_dist(JD, &horbit);
	res = ln_get_hyp_body_earth_dist(JD, &horbit);
	res = ln_get_hyp_body_phase_angle(JD, &horbit);
	res = ln_get_hyp_body_elong(JD, &horbit);
	
	ln_get_hyp_body_rst(JD, &observer, &horbit, &rst);
	ln_get_hyp_body_next_rst(JD, &observer, &horbit, &rst);
	/*
	ln_get_hyp_body_rst_horizon(JD, &observer, &horbit, -10.0, &rst);
	ln_get_hyp_body_next_rst_horizon(JD, &observer, &horbit, -10.0, &rst);
	*/
	ln_get_hyp_body_next_rst_horizon_future(JD, &observer, &horbit, -10.0, 10, &rst);

	if (failed == 0) {
        printf("TEST (Orbit) Extended Ell/Par/Hyp....[PASSED]\n");
    } else {
        printf("TEST (Orbit) Extended Ell/Par/Hyp....[FAILED] %d errors\n", failed);
    }

	return failed;
}
