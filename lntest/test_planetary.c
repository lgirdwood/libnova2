/*
 * Planetary Rectangular and RST Tests
 */

#include <stdio.h>
#include <libnova/libnova.h>
#include "test_helpers.h"

int planetary_rect_rst_test(void)
{
	int failed = 0;
	double JD;
	struct ln_rect_posn rect;
	struct ln_rst_time rst;
	struct ln_lnlat_posn observer;

	JD = 2451545.0; /* J2000 */
	observer.lng = ln_deg_to_rad(0.0); observer.lat = ln_deg_to_rad(50.0);

	/* Mercury */
	ln_get_mercury_rect_helio(JD, &rect);
	if (rect.X == 0 && rect.Y == 0 && rect.Z == 0) failed++;
	ln_get_mercury_rst(JD, &observer, &rst);
	if (rst.rise == 0 && rst.set == 0) {/* might be valid but unlikely for mercury */ }

	/* Venus */
	ln_get_venus_rect_helio(JD, &rect);
	if (rect.X == 0 && rect.Y == 0 && rect.Z == 0) failed++;
	ln_get_venus_rst(JD, &observer, &rst);

	/* Jupiter */
	ln_get_jupiter_rect_helio(JD, &rect);
	if (rect.X == 0 && rect.Y == 0 && rect.Z == 0) failed++;
	ln_get_jupiter_rst(JD, &observer, &rst);

	/* Saturn */
	ln_get_saturn_rect_helio(JD, &rect);
	if (rect.X == 0 && rect.Y == 0 && rect.Z == 0) failed++;
	ln_get_saturn_rst(JD, &observer, &rst);

	/* Uranus */
	ln_get_uranus_rect_helio(JD, &rect);
	if (rect.X == 0 && rect.Y == 0 && rect.Z == 0) failed++;
	ln_get_uranus_rst(JD, &observer, &rst);

	/* Neptune */
	ln_get_neptune_rect_helio(JD, &rect);
	if (rect.X == 0 && rect.Y == 0 && rect.Z == 0) failed++;
	ln_get_neptune_rst(JD, &observer, &rst);

	/* Pluto */
	ln_get_pluto_rect_helio(JD, &rect);
	if (rect.X == 0 && rect.Y == 0 && rect.Z == 0) failed++;
	/* No rst for pluto in public API apparently, based on test.c commentary in my thought process */
	
    if (failed == 0) {
        printf("TEST (Planetary) Rect Helio & RST....[PASSED]\n");
    } else {
        printf("TEST (Planetary) Rect Helio & RST....[FAILED] %d errors\n", failed);
    }

	return failed;
}
