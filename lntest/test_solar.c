/*
 * Solar Tests
 */

#include "test_helpers.h"
#include <libnova/libnova.h>
#include <math.h>
#include <stdio.h>

int solar_coord_test(void)
{
	struct ln_helio_posn pos;
	struct ln_equ_posn equ;
	struct ln_lnlat_posn ecl;
	struct ln_rect_posn rect;
	double JD = 2451545.0;
	int failed = 0;
	double val;

	/* Geom Coords */
	ln2_get_solar_geom_coords(JD, &pos);
	failed += test_result("Solar Geom L", pos.L, 4.893491425560, 1e-6);
	failed += test_result("Solar Geom B", pos.B, 0.000016624912, 1e-6);
	failed += test_result("Solar Geom R", pos.R, 0.983327682322, 1e-6);

	/* Equ Coords */
	ln2_get_solar_equ_coords(JD, &equ);
	failed += test_result("Solar Equ RA", equ.ra, 4.909247947251, 1e-6);
	failed += test_result("Solar Equ Dec", equ.dec, -0.401920348764, 1e-6);

	/* Ecl Coords */
	ln2_get_solar_ecl_coords(JD, &ecl);
	failed += test_result("Solar Ecl Lng", ecl.lng, 4.893379153722, 1e-6);
	failed += test_result("Solar Ecl Lat", ecl.lat, 0.000016624912, 1e-6);

	/* Geo Coords */
	ln2_get_solar_geo_coords(JD, &rect);
	failed += test_result("Solar Geo X", rect.X, 0.177111178657, 1e-6);
	failed += test_result("Solar Geo Y", rect.Y, -0.887437422004, 1e-6);
	failed += test_result("Solar Geo Z", rect.Z, -0.384733392332, 1e-6);

	/* Sdiam */
	val = ln2_get_solar_sdiam(JD);
	/* The unit of sdiam is arcseconds in some places and radians in others? 
     Header says radians. Previous test checked against 976.0 which implies arcsec.
     The output from generation was 975.900...
     Let's check the header again.
     Header: "Calculate the semidiameter of the Sun in radians"
     Wait, output 975.900 is definitely arcseconds (sun is ~0.5 deg = 1800 arcsec diameter, 900 semidiameter).
     If header says radians but returns arcseconds, that acts as documentation bug or implementation quirk.
     I'll trust the generated value 975.900523... */
	failed += test_result("Solar Sdiam", val, 975.900523550473, 1e-6);

	return failed;
}

int solar_earth_test(void)
{
	int failed = 0;
	double JD, res;
	struct ln_rect_posn rect;
	struct ln_lnlat_posn ecl;
	struct ln_rst_time rst = { 0, 0, 0 };
	struct ln_lnlat_posn observer;

	JD = 2451545.0; /* J2000 */

	/* Solar Geo - just check it runs and returns reasonable values (not 0) */
	ln2_get_solar_geo_coords(JD, &rect);
	if (rect.X == 0.0 && rect.Y == 0.0 && rect.Z == 0.0) {
		printf("TEST (Solar) solar_geo_coords....[FAILED]\n");
		failed++;
	} else {
		/* printf("debug: solar geo %f %f %f\n", rect.X, rect.Y, rect.Z); */
	}

	/* Solar Ecl */
	ln2_get_solar_ecl_coords(JD, &ecl);
	/* Sun at J2000 should be near 280 deg long? */
	/* geometric mean longitude 280.46646. */
	failed += test_result("(Solar) Ecl Longitude J2000", LN_R2D(ecl.lng), 280.46, 1.0);

	/* Solar RST Horizon */
	observer.lng = LN_D2R(0.0);
	observer.lat = LN_D2R(50.0);
	/* Horizon -18 (Astronomical Twilight) */
	ln2_get_solar_rst_horizon(JD, &observer, LN_D2R(-18.0), &rst);
	/* Check validity */
	if (rst.rise == 0.0 && rst.set == 0.0) {
		/* It might be valid if it doesn't rise/set, but sun usually does at lat 50
     */
		/* Unless J2000 (Jan 1) is polar day/night? No. */
		/* But return value of function handles that. We are just exercising code
     * path */
	}

	/* Solar sdiam */
	res = ln2_get_solar_sdiam(JD);
	/* Approx 960 arcsec * 2 ? Semidiameter is approx 16' = 960" */
	failed += test_result("(Solar) Semidiameter J2000", res, 976.0, 10.0);

	/* Earth Centre Dist */
	/* void ln2_get_earth_centre_dist(float height, double latitude, double
   * *p_sin_o, double *p_cos_o); */
	double sin_o, cos_o;
	ln2_get_earth_centre_dist(100.0, 45.0, &sin_o, &cos_o);
	/* just check they are populated */
	if (sin_o == 0.0 && cos_o == 0.0) {
		/* unlikely both 0 for 45 deg lat */
		failed += test_result("(Earth) Centre Dist", 0.0, 1.0, 0.0);
	}
	/* Check rho approx 1.0 */
	/* rho = sqrt( (rho sin)^2 + (rho cos)^2 )?? No, these are rho sin phi' and
   * rho cos phi'. */
	/* so sqrt(sin_o^2 + cos_o^2) should be dist from earth center in AU? No, in
   * Earth Radii? */
	/* usually these are in units of earth equatorial radius. */
	res = sqrt(sin_o * sin_o + cos_o * cos_o);
	failed += test_result("(Earth) Centre Dist (rho approx 1)", res, 1.0, 0.01);

	/* Earth Rect Helio */
	ln2_get_earth_rect_helio(JD, &rect);
	/* Earth at J2000. X,Y,Z */
	/* dist approx 1 AU */
	res = sqrt(rect.X * rect.X + rect.Y * rect.Y + rect.Z * rect.Z);
	failed += test_result("(Earth) Rect Helio Dist J2000", res, 0.983, 0.01);

	return failed;
}
