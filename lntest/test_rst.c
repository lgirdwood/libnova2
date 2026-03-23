/*
 * RST Tests
 */

#include "test_helpers.h"
#include <libnova2/libnova2.h>
#include <stdio.h>

int rst_test(void)
{
	struct ln_lnlat_posn observer;
	struct ln_rst_time rst;
	struct ln_hms hms;
	struct ln_dms dms;
	struct ln_date date;
	struct ln_equ_posn object;
	double JD, JD_next;
	int ret;
	int failed = 0;

	/* Venus on 1988 March 20 at Boston */
	/* Venus on 1988 March 20 at Boston */
	date = LN_DATE(1988, 3, 20, 0, 0, 0);

	JD = ln2_get_julian_day(&date);

	observer.lng = LN_D2R(-71.0833);
	observer.lat = LN_D2R(42.3333);

	ret = ln2_get_venus_rst(JD, &observer, &rst);
	failed +=
	    test_result("Venus sometime rise on 1988/03/20 at Boston", ret, 0, 0);

	if (!ret) {
		ln2_get_date(rst.rise, &date);
		failed += test_result("Venus rise hour on 1988/03/20 at Boston",
		                      date.hours, 12, 0);
		failed += test_result("Venus rise minute on 1988/03/20 at Boston",
		                      date.minutes, 25, 0);

		ln2_get_date(rst.transit, &date);
		failed += test_result("Venus transit hour on 1988/03/20 at Boston",
		                      date.hours, 19, 0);
		failed += test_result("Venus transit minute on 1988/03/20 at Boston",
		                      date.minutes, 41, 0);

		ln2_get_date(rst.set, &date);
		failed += test_result("Venus set hour on 1988/03/20 at Boston",
		                      date.hours, 2, 0);
		failed += test_result("Venus set minute on 1988/03/20 at Boston",
		                      date.minutes, 55, 0);
	}

	return failed;
}

int ell_rst_test(void)
{
	struct ln_lnlat_posn observer;
	struct ln_ell_orbit orbit;
	struct ln_date date;
	struct ln_rst_time rst;
	struct ln_equ_posn pos;
	double JD;
	int ret;
	int failed = 0;
	int circumpolar;

	/* Comment C/1996 B2 (Hyakutake) somewhere at Japan */

	observer.lng = LN_D2R(135.0);
	observer.lat = LN_D2R(35.0);

	date = LN_DATE(1996, 5, 1, 0, 0, 0.0);

	orbit = LN_ELL_ORBIT_DEG(1014.2022026431, 0.9997730, 124.92379, 130.17654,
	                         188.04546, 0.0,
	                         ln2_get_julian_day(&date) + 0.39481);

	date = LN_DATE(1996, 3, 24, 0, 0, 0.0);

	JD = ln2_get_julian_day(&date);

	ln2_get_ell_body_equ_coords(JD, &orbit, &pos);
	failed += test_result("(RA) for Hyakutake 1996/03/28 00:00", pos.ra,
	                      LN_D2R(220.8554), 0.001);
	failed += test_result("(Dec) for Hyakutake 1996/03/28 00:00", pos.dec,
	                      0.63755628, 0.001);

	date.days = 28;
	date.hours = 10;
	date.minutes = 42;
	/* partial update again.
	 Previous date was 1996-03-24 00:00:00.
	 This makes it 1996-03-28 10:42:00.
	 I can make it a full update since I know the previous state.
  */
	date = LN_DATE(1996, 3, 28, 10, 42, 0.0);

	JD = ln2_get_julian_day(&date);

	ln2_get_ell_body_equ_coords(JD, &orbit, &pos);
	failed += test_result("(RA) for Hyakutake 1996/03/28 10:42", pos.ra,
	                      LN_D2R(56.2140), 0.001);
	failed += test_result("(Dec) for Hyakutake 1996/03/28 10:42", pos.dec,
	                      1.29918254, 0.001);

	circumpolar = ln2_get_ell_body_rst(JD, &observer, &orbit, &rst);

	/* TODO: test circumpolar and RST by converting back to JD */

	return failed;
}

int hyp_future_rst_test(void)
{
	struct ln_lnlat_posn observer;
	struct ln_hyp_orbit orbit;
	struct ln_date date;
	struct ln_rst_time rst;
	double JD;
	int ret;
	int circumpolar;
	int failed = 0;

	observer.lng = LN_D2R(15.0);
	observer.lat = LN_D2R(50.0);

	/* C/2006 P1 (McNaught) */

	orbit = LN_HYP_ORBIT_DEG(0.170742005109787, 1.00001895427704,
	                         77.8348999023438, 155.977096557617,
	                         267.414398193359, 2454113.251);

	date = LN_DATE(2007, 1, 17, 12, 0, 0.0);

	JD = ln2_get_julian_day(&date);

	circumpolar =
	    ln2_get_hyp_body_next_rst_horizon(JD, &observer, &orbit, 0, &rst);

	/* TODO: test circumpolar and RST by converting back to JD */

	return failed;
}

int body_future_rst_test(void)
{
	struct ln_lnlat_posn observer;
	struct ln_date date;
	struct ln_rst_time rst;
	double JD;
	int ret;
	int failed = 0;
	int circumpolar;

	observer.lng = LN_D2R(0.0);
	observer.lat = LN_D2R(85.0);

	date = LN_DATE(2006, 1, 1, 0, 0, 0.0);

	JD = ln2_get_julian_day(&date);

	circumpolar =
	    ln2_get_body_next_rst_horizon_future(JD, &observer,
	                                         ln2_get_solar_equ_coords,
	                                         LN_SOLAR_STANDART_HORIZON, 300,
	                                         &rst);

	return failed;
}
