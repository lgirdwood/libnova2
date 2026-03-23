/*
 * VSOP87 Tests
 */

#include "test_helpers.h"
#include <libnova2/libnova2.h>
#include <stdio.h>

int vsop87_test(void)
{
	struct ln_helio_posn pos;
	struct ln_equ_posn equ;
	double JD = 2448976.5;
	double au;
	int failed = 0;

	ln2_get_solar_equ_coords(JD, &equ);
	failed += test_result("(Solar Position) RA on JD 2448976.5  ",
	                      LN_R2D(equ.ra), 268.30941158, 0.00000001);
	failed += test_result("(Solar Position) DEC on JD 2448976.5  ",
	                      LN_R2D(equ.dec), -23.42585297, 0.00000001);

	ln2_get_mercury_helio_coords(JD, &pos);
	failed += test_result("(Mercury) Helio L  ", pos.L, 3.531730, 0.000001);
	failed += test_result("(Mercury) Helio B  ", pos.B, 0.053780, 0.000001);
	failed += test_result("(Mercury) Helio R  ", pos.R, 0.419940, 0.000001);
	ln2_get_mercury_equ_coords(JD, &equ);
	failed += test_result("(Mercury) Equ RA   ", LN_R2D(equ.ra), 248.600395,
	                      0.000001);
	failed += test_result("(Mercury) Equ Dec  ", LN_R2D(equ.dec), -20.906439,
	                      0.000001);
	au = ln2_get_mercury_earth_dist(JD);
	failed +=
	    test_result("(Mercury) Earth dist (AU)  ", au, 1.215950, 0.000001);
	au = ln2_get_mercury_solar_dist(JD);
	failed +=
	    test_result("(Mercury) Solar dist (AU)  ", au, 0.419940, 0.000001);
	au = ln2_get_mercury_disk(JD);
	failed +=
	    test_result("(Mercury) Illuminated disk  ", au, 0.836339, 0.000001);
	au = ln2_get_mercury_magnitude(JD);
	failed += test_result("(Mercury) Magnitude  ", au, -1.848023, 0.000001);
	au = ln2_get_mercury_phase(JD);
	failed += test_result("(Mercury) Phase  ", au, 0.832975, 0.000001);
	au = ln2_get_mercury_sdiam(JD);
	failed += test_result("(Mercury) Sdiam  ", au, 0.000013, 0.000001);

	ln2_get_venus_helio_coords(JD, &pos);
	failed += test_result("(Venus) Helio L  ", pos.L, 0.457467, 0.000001);
	failed += test_result("(Venus) Helio B  ", pos.B, -0.045725, 0.000001);
	failed += test_result("(Venus) Helio R  ", pos.R, 0.724602, 0.000001);
	ln2_get_venus_equ_coords(JD, &equ);
	failed +=
	    test_result("(Venus) Equ RA   ", LN_R2D(equ.ra), 316.269950, 0.000001);
	failed +=
	    test_result("(Venus) Equ Dec  ", LN_R2D(equ.dec), -18.859699, 0.000001);
	au = ln2_get_venus_earth_dist(JD);
	failed += test_result("(Venus) Earth dist (AU)  ", au, 0.910846, 0.000001);
	au = ln2_get_venus_solar_dist(JD);
	failed += test_result("(Venus) Solar dist (AU)  ", au, 0.724602, 0.000001);
	au = ln2_get_venus_disk(JD);
	failed += test_result("(Venus) Illuminated disk  ", au, 0.646507, 0.000001);
	au = ln2_get_venus_magnitude(JD);
	failed += test_result("(Venus) Magnitude  ", au, -5.300746, 0.000001);
	au = ln2_get_venus_phase(JD);
	failed += test_result("(Venus) Phase  ", au, 1.273419, 0.000001);
	au = ln2_get_venus_sdiam(JD);
	failed += test_result("(Venus) Sdiam  ", au, 0.000045, 0.000001);

	ln2_get_earth_helio_coords(JD, &pos);
	failed += test_result("(Earth) Helio L  ", pos.L, 1.543810, 0.000001);
	failed += test_result("(Earth) Helio B  ", pos.B, 0.000008, 0.000001);
	failed += test_result("(Earth) Helio R  ", pos.R, 0.983824, 0.000001);
	au = ln2_get_earth_solar_dist(JD);
	failed += test_result("(Earth) Solar dist (AU)  ", au, 0.983824, 0.000001);

	ln2_get_mars_helio_coords(JD, &pos);
	failed += test_result("(Mars) Helio L  ", pos.L, 1.724432, 0.000001);
	failed += test_result("(Mars) Helio B  ", pos.B, 0.024449, 0.000001);
	failed += test_result("(Mars) Helio R  ", pos.R, 1.590873, 0.000001);
	ln2_get_mars_equ_coords(JD, &equ);
	failed +=
	    test_result("(Mars) Equ RA   ", LN_R2D(equ.ra), 117.241177, 0.000001);
	failed +=
	    test_result("(Mars) Equ Dec  ", LN_R2D(equ.dec), 24.576727, 0.000001);
	au = ln2_get_mars_earth_dist(JD);
	failed += test_result("(Mars) Earth dist (AU)  ", au, 0.648345, 0.000001);
	au = ln2_get_mars_solar_dist(JD);
	failed += test_result("(Mars) Solar dist (AU)  ", au, 1.590873, 0.000001);
	au = ln2_get_mars_disk(JD);
	failed += test_result("(Mars) Illuminated disk  ", au, 0.980719, 0.000001);
	au = ln2_get_mars_magnitude(JD);
	failed += test_result("(Mars) Magnitude  ", au, -1.448334, 0.000001);
	au = ln2_get_mars_phase(JD);
	failed += test_result("(Mars) Phase  ", au, 0.278616, 0.000001);
	au = ln2_get_mars_sdiam(JD);
	failed += test_result("(Mars) Sdiam  ", au, 0.000035, 0.000001);

	ln2_get_jupiter_helio_coords(JD, &pos);
	failed += test_result("(Jupiter) Helio L  ", pos.L, 3.181423, 0.000001);
	failed += test_result("(Jupiter) Helio B  ", pos.B, 0.022528, 0.000001);
	failed += test_result("(Jupiter) Helio R  ", pos.R, 5.446765, 0.000001);
	ln2_get_jupiter_equ_coords(JD, &equ);
	failed += test_result("(Jupiter) Equ RA   ", LN_R2D(equ.ra), 191.876253,
	                      0.000001);
	failed += test_result("(Jupiter) Equ Dec  ", LN_R2D(equ.dec), -3.735619,
	                      0.000001);
	au = ln2_get_jupiter_earth_dist(JD);
	failed +=
	    test_result("(Jupiter) Earth dist (AU)  ", au, 5.599155, 0.000001);
	au = ln2_get_jupiter_solar_dist(JD);
	failed +=
	    test_result("(Jupiter) Solar dist (AU)  ", au, 5.446765, 0.000001);
	au = ln2_get_jupiter_disk(JD);
	failed +=
	    test_result("(Jupiter) Illuminated disk  ", au, 0.992256, 0.000001);
	au = ln2_get_jupiter_magnitude(JD);
	failed += test_result("(Jupiter) Magnitude  ", au, -1.977813, 0.000001);
	au = ln2_get_jupiter_phase(JD);
	failed += test_result("(Jupiter) Phase  ", au, 0.176228, 0.000001);
	au = ln2_get_jupiter_pol_sdiam(JD);
	failed += test_result("(Jupiter) Polar Sdiam  ", au, 0.000080, 0.000001);
	au = ln2_get_jupiter_equ_sdiam(JD);
	failed += test_result("(Jupiter) Equ Sdiam  ", au, 0.000085, 0.000001);

	ln2_get_saturn_helio_coords(JD, &pos);
	failed += test_result("(Saturn) Helio L  ", pos.L, 5.574847, 0.000001);
	failed += test_result("(Saturn) Helio B  ", pos.B, -0.018846, 0.000001);
	failed += test_result("(Saturn) Helio R  ", pos.R, 9.867006, 0.000001);
	ln2_get_saturn_equ_coords(JD, &equ);
	failed +=
	    test_result("(Saturn) Equ RA   ", LN_R2D(equ.ra), 318.020347, 0.000001);
	failed += test_result("(Saturn) Equ Dec  ", LN_R2D(equ.dec), -17.232318,
	                      0.000001);
	au = ln2_get_saturn_earth_dist(JD);
	failed +=
	    test_result("(Saturn) Earth dist (AU)  ", au, 10.514363, 0.000001);
	au = ln2_get_saturn_solar_dist(JD);
	failed += test_result("(Saturn) Solar dist (AU)  ", au, 9.867006, 0.000001);
	au = ln2_get_saturn_disk(JD);
	failed +=
	    test_result("(Saturn) Illuminated disk  ", au, 0.998677, 0.000001);
	au = ln2_get_saturn_magnitude(JD);
	failed += test_result("(Saturn) Magnitude  ", au, 1.199842, 0.000001);
	au = ln2_get_saturn_phase(JD);
	failed += test_result("(Saturn) Phase  ", au, 0.072750, 0.000001);
	au = ln2_get_saturn_pol_sdiam(JD);
	failed += test_result("(Saturn) Polar Sdiam  ", au, 0.000034, 0.000001);
	au = ln2_get_saturn_equ_sdiam(JD);
	failed += test_result("(Saturn) Equ Sdiam  ", au, 0.000038, 0.000001);

	ln2_get_uranus_helio_coords(JD, &pos);
	failed += test_result("(Uranus) Helio L  ", pos.L, 5.026336, 0.000001);
	failed += test_result("(Uranus) Helio B  ", pos.B, -0.007518, 0.000001);
	failed += test_result("(Uranus) Helio R  ", pos.R, 19.570238, 0.000001);
	ln2_get_uranus_equ_coords(JD, &equ);
	failed +=
	    test_result("(Uranus) Equ RA   ", LN_R2D(equ.ra), 288.557772, 0.000001);
	failed += test_result("(Uranus) Equ Dec  ", LN_R2D(equ.dec), -22.757668,
	                      0.000001);
	au = ln2_get_uranus_earth_dist(JD);
	failed +=
	    test_result("(Uranus) Earth dist (AU)  ", au, 20.500050, 0.000001);
	au = ln2_get_uranus_solar_dist(JD);
	failed +=
	    test_result("(Uranus) Solar dist (AU)  ", au, 19.570238, 0.000001);
	au = ln2_get_uranus_disk(JD);
	failed +=
	    test_result("(Uranus) Illuminated disk  ", au, 0.999936, 0.000001);
	au = ln2_get_uranus_magnitude(JD);
	failed += test_result("(Uranus) Magnitude  ", au, 5.826755, 0.000001);
	au = ln2_get_uranus_phase(JD);
	failed += test_result("(Uranus) Phase  ", au, 0.016051, 0.000001);
	au = ln2_get_uranus_sdiam(JD);
	failed += test_result("(Uranus) Sdiam  ", au, 0.000008, 0.000001);

	ln2_get_neptune_helio_coords(JD, &pos);
	failed += test_result("(Neptune) Helio L  ", pos.L, 5.037637, 0.000001);
	failed += test_result("(Neptune) Helio B  ", pos.B, 0.012159, 0.000001);
	failed += test_result("(Neptune) Helio R  ", pos.R, 30.188053, 0.000001);
	ln2_get_neptune_equ_coords(JD, &equ);
	failed += test_result("(Neptune) Equ RA   ", LN_R2D(equ.ra), 289.414566,
	                      0.000001);
	failed += test_result("(Neptune) Equ Dec  ", LN_R2D(equ.dec), -21.557733,
	                      0.000001);
	au = ln2_get_neptune_earth_dist(JD);
	failed +=
	    test_result("(Neptune) Earth dist (AU)  ", au, 31.113260, 0.000001);
	au = ln2_get_neptune_solar_dist(JD);
	failed +=
	    test_result("(Neptune) Solar dist (AU)  ", au, 30.188053, 0.000001);
	au = ln2_get_neptune_disk(JD);
	failed +=
	    test_result("(Neptune) Illuminated disk  ", au, 0.999970, 0.000001);
	au = ln2_get_neptune_magnitude(JD);
	failed += test_result("(Neptune) Magnitude  ", au, 7.993903, 0.000001);
	au = ln2_get_neptune_phase(JD);
	failed += test_result("(Neptune) Phase  ", au, 0.010915, 0.000001);
	au = ln2_get_neptune_sdiam(JD);
	failed += test_result("(Neptune) Sdiam  ", au, 0.000005, 0.000001);

	ln2_get_pluto_helio_coords(JD, &pos);
	failed += test_result("(Pluto) Helio L  ", pos.L, 4.070333, 0.000001);
	failed += test_result("(Pluto) Helio B  ", pos.B, 0.253319, 0.000001);
	failed += test_result("(Pluto) Helio R  ", pos.R, 29.717796, 0.000001);
	ln2_get_pluto_equ_coords(JD, &equ);
	failed +=
	    test_result("(Pluto) Equ RA   ", LN_R2D(equ.ra), 235.390012, 0.000001);
	failed +=
	    test_result("(Pluto) Equ Dec  ", LN_R2D(equ.dec), -5.121212, 0.000001);
	au = ln2_get_pluto_earth_dist(JD);
	failed += test_result("(Pluto) Earth dist (AU)  ", au, 30.501621, 0.000001);
	au = ln2_get_pluto_solar_dist(JD);
	failed += test_result("(Pluto) Solar dist (AU)  ", au, 29.717796, 0.000001);
	au = ln2_get_pluto_disk(JD);
	failed += test_result("(Pluto) Illuminated disk  ", au, 0.999902, 0.000001);
	au = ln2_get_pluto_magnitude(JD);
	failed += test_result("(Pluto) Magnitude  ", au, 13.786698, 0.000001);
	au = ln2_get_pluto_phase(JD);
	failed += test_result("(Pluto) Phase  ", au, 0.019749, 0.000001);
	au = ln2_get_pluto_sdiam(JD);
	failed += test_result("(Pluto) Sdiam  ", au, 0.000000, 0.000001);

	return failed;
}
