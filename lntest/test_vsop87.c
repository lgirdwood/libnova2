/*
 * VSOP87 Tests
 */

#include <stdio.h>
#include <libnova/libnova.h>
#include "test_helpers.h"

int vsop87_test(void)
{
	struct ln_helio_posn pos;
	struct lnh_equ_posn hequ;
	struct ln_equ_posn equ;
	double JD = 2448976.5;
	double au;
	int failed = 0;
	
	ln_get_solar_equ_coords(JD, &equ);
	failed += test_result("(Solar Position) RA on JD 2448976.5  ",
		ln_rad_to_deg(equ.ra), 268.32146893, 0.00000001);
	failed += test_result("(Solar Position) DEC on JD 2448976.5  ",
		ln_rad_to_deg(equ.dec), -23.43026873, 0.00000001);
	
	ln_get_mercury_helio_coords(JD, &pos);
	printf("Mercury L %f B %f R %f\n", pos.L, pos.B, pos.R);
	ln_get_mercury_equ_coords(JD, &equ);
	ln_equ_to_hequ (&equ, &hequ);
	printf("Mercury RA %d:%d:%f Dec %d:%d:%f\n", hequ.ra.hours, hequ.ra.minutes, hequ.ra.seconds, hequ.dec.degrees, hequ.dec.minutes, hequ.dec.seconds);
	au = ln_get_mercury_earth_dist(JD);
	fprintf(stdout, "mercury -> Earth dist (AU) %f\n",au);
	au = ln_get_mercury_solar_dist(JD);
	fprintf(stdout, "mercury -> Sun dist (AU) %f\n",au);
	au = ln_get_mercury_disk(JD);
	fprintf(stdout, "mercury -> illuminated disk %f\n",au);
	au = ln_get_mercury_magnitude(JD);
	fprintf(stdout, "mercury -> magnitude %f\n",au);
	au = ln_get_mercury_phase(JD);
	fprintf(stdout, "mercury -> phase %f\n",au);
	au = ln_get_mercury_sdiam(JD);
	fprintf(stdout, "mercury -> sdiam %f\n",au);
	
	ln_get_venus_helio_coords(JD, &pos);
	printf("Venus L %f B %f R %f\n", pos.L, pos.B, pos.R);
	ln_get_venus_equ_coords(JD, &equ);
	ln_equ_to_hequ (&equ, &hequ);
	printf("Venus RA %d:%d:%f Dec %d:%d:%f\n", hequ.ra.hours, hequ.ra.minutes, hequ.ra.seconds, hequ.dec.degrees, hequ.dec.minutes, hequ.dec.seconds);
	au = ln_get_venus_earth_dist(JD);
	fprintf(stdout, "venus -> Earth dist (AU) %f\n",au);
	au = ln_get_venus_solar_dist(JD);
	fprintf(stdout, "venus -> Sun dist (AU) %f\n",au);
	au = ln_get_venus_disk(JD);
	fprintf(stdout, "venus -> illuminated disk %f\n",au);
	au = ln_get_venus_magnitude(JD);
	fprintf(stdout, "venus -> magnitude %f\n",au);
	au = ln_get_venus_phase(JD);
	fprintf(stdout, "venus -> phase %f\n",au);
	au = ln_get_venus_sdiam(JD);
	fprintf(stdout, "venus -> sdiam %f\n",au);
	
	ln_get_earth_helio_coords(JD, &pos);
	printf("Earth L %f B %f R %f\n", pos.L, pos.B, pos.R);
	au = ln_get_earth_solar_dist(JD);
	fprintf(stdout, "earth -> Sun dist (AU) %f\n",au);

	ln_get_mars_helio_coords(JD, &pos);	
	printf("Mars L %f B %f R %f\n", pos.L, pos.B, pos.R);
	ln_get_mars_equ_coords(JD, &equ);
	ln_equ_to_hequ (&equ, &hequ);
	printf("Mars RA %d:%d:%f Dec %d:%d:%f\n", hequ.ra.hours, hequ.ra.minutes, hequ.ra.seconds, hequ.dec.degrees, hequ.dec.minutes, hequ.dec.seconds);
	au = ln_get_mars_earth_dist(JD);
	fprintf(stdout, "mars -> Earth dist (AU) %f\n",au);
	au = ln_get_mars_solar_dist(JD);
	fprintf(stdout, "mars -> Sun dist (AU) %f\n",au);
	au = ln_get_mars_disk(JD);
	fprintf(stdout, "mars -> illuminated disk %f\n",au);
	au = ln_get_mars_magnitude(JD);
	fprintf(stdout, "mars -> magnitude %f\n",au);
	au = ln_get_mars_phase(JD);
	fprintf(stdout, "mars -> phase %f\n",au);
	au = ln_get_mars_sdiam(JD);
	fprintf(stdout, "mars -> sdiam %f\n",au);
	
	ln_get_jupiter_helio_coords(JD, &pos);
	printf("Jupiter L %f B %f R %f\n", pos.L, pos.B, pos.R);
	ln_get_jupiter_equ_coords(JD, &equ);
	ln_equ_to_hequ (&equ, &hequ);
	printf("Jupiter RA %d:%d:%f Dec %d:%d:%f\n", hequ.ra.hours, hequ.ra.minutes, hequ.ra.seconds, hequ.dec.degrees, hequ.dec.minutes, hequ.dec.seconds);
	au = ln_get_jupiter_earth_dist(JD);
	fprintf(stdout, "jupiter -> Earth dist (AU) %f\n",au);
	au = ln_get_jupiter_solar_dist(JD);
	fprintf(stdout, "jupiter -> Sun dist (AU) %f\n",au);
	au = ln_get_jupiter_disk(JD);
	fprintf(stdout, "jupiter -> illuminated disk %f\n",au);
	au = ln_get_jupiter_magnitude(JD);
	fprintf(stdout, "jupiter -> magnitude %f\n",au);
	au = ln_get_jupiter_phase(JD);
	fprintf(stdout, "jupiter -> phase %f\n",au);
	au = ln_get_jupiter_pol_sdiam(JD);
	fprintf(stdout, "jupiter -> polar sdiam %f\n",au);
	au = ln_get_jupiter_equ_sdiam(JD);
	fprintf(stdout, "jupiter -> equ sdiam %f\n",au);
	
	ln_get_saturn_helio_coords(JD, &pos);
	printf("Saturn L %f B %f R %f\n", pos.L, pos.B, pos.R);
	ln_get_saturn_equ_coords(JD, &equ);
	ln_equ_to_hequ (&equ, &hequ);
	printf("Saturn RA %d:%d:%f Dec %d:%d:%f\n", hequ.ra.hours, hequ.ra.minutes, hequ.ra.seconds, hequ.dec.degrees, hequ.dec.minutes, hequ.dec.seconds);
	au = ln_get_saturn_earth_dist(JD);
	fprintf(stdout, "saturn -> Earth dist (AU) %f\n",au);
	au = ln_get_saturn_solar_dist(JD);
	fprintf(stdout, "saturn -> Sun dist (AU) %f\n",au);
	au = ln_get_saturn_disk(JD);
	fprintf(stdout, "saturn -> illuminated disk %f\n",au);
	au = ln_get_saturn_magnitude(JD);
	fprintf(stdout, "saturn -> magnitude %f\n",au);
	au = ln_get_saturn_phase(JD);
	fprintf(stdout, "saturn -> phase %f\n",au);
	au = ln_get_saturn_pol_sdiam(JD);
	fprintf(stdout, "saturn -> polar sdiam %f\n",au);
	au = ln_get_saturn_equ_sdiam(JD);
	fprintf(stdout, "saturn -> equ sdiam %f\n",au);
	
	ln_get_uranus_helio_coords(JD, &pos);	
	printf("Uranus L %f B %f R %f\n", pos.L, pos.B, pos.R);
	ln_get_uranus_equ_coords(JD, &equ);
	ln_equ_to_hequ (&equ, &hequ);
	printf("Uranus RA %d:%d:%f Dec %d:%d:%f\n", hequ.ra.hours, hequ.ra.minutes, hequ.ra.seconds, hequ.dec.degrees, hequ.dec.minutes, hequ.dec.seconds);
	au = ln_get_uranus_earth_dist(JD);
	fprintf(stdout, "uranus -> Earth dist (AU) %f\n",au);
	au = ln_get_uranus_solar_dist(JD);
	fprintf(stdout, "uranus -> Sun dist (AU) %f\n",au);
	au = ln_get_uranus_disk(JD);
	fprintf(stdout, "uranus -> illuminated disk %f\n",au);
	au = ln_get_uranus_magnitude(JD);
	fprintf(stdout, "uranus -> magnitude %f\n",au);
	au = ln_get_uranus_phase(JD);
	fprintf(stdout, "uranus -> phase %f\n",au);
	au = ln_get_uranus_sdiam(JD);
	fprintf(stdout, "uranus -> sdiam %f\n",au);
	
	ln_get_neptune_helio_coords(JD, &pos);
	printf("Neptune L %f B %f R %f\n", pos.L, pos.B, pos.R);
	ln_get_neptune_equ_coords(JD, &equ);
	ln_equ_to_hequ (&equ, &hequ);
	printf("Neptune RA %d:%d:%f Dec %d:%d:%f\n", hequ.ra.hours, hequ.ra.minutes, hequ.ra.seconds, hequ.dec.degrees, hequ.dec.minutes, hequ.dec.seconds);
	au = ln_get_neptune_earth_dist(JD);
	fprintf(stdout, "neptune -> Earth dist (AU) %f\n",au);
	au = ln_get_neptune_solar_dist(JD);
	fprintf(stdout, "neptune -> Sun dist (AU) %f\n",au);
	au = ln_get_neptune_disk(JD);
	fprintf(stdout, "neptune -> illuminated disk %f\n",au);
	au = ln_get_neptune_magnitude(JD);
	fprintf(stdout, "neptune -> magnitude %f\n",au);
	au = ln_get_neptune_phase(JD);
	fprintf(stdout, "neptune -> phase %f\n",au);
	au = ln_get_neptune_sdiam(JD);
	fprintf(stdout, "neptune -> sdiam %f\n",au);
	
	ln_get_pluto_helio_coords(JD, &pos);
	printf("Pluto L %f B %f R %f\n", pos.L, pos.B, pos.R);
	ln_get_pluto_equ_coords(JD, &equ);
	ln_equ_to_hequ (&equ, &hequ);
	printf("Pluto RA %d:%d:%f Dec %d:%d:%f\n", hequ.ra.hours, hequ.ra.minutes, hequ.ra.seconds, hequ.dec.degrees, hequ.dec.minutes, hequ.dec.seconds);
	au = ln_get_pluto_earth_dist(JD);
	fprintf(stdout, "pluto -> Earth dist (AU) %f\n",au);
	au = ln_get_pluto_solar_dist(JD);
	fprintf(stdout, "pluto -> Sun dist (AU) %f\n",au);
	au = ln_get_pluto_disk(JD);
	fprintf(stdout, "pluto -> illuminated disk %f\n",au);
	au = ln_get_pluto_magnitude(JD);
	fprintf(stdout, "pluto -> magnitude %f\n",au);
	au = ln_get_pluto_phase(JD);
	fprintf(stdout, "pluto -> phase %f\n",au);
	au = ln_get_pluto_sdiam(JD);
	fprintf(stdout, "pluto -> sdiam %f\n",au);
	
	return failed;
}
