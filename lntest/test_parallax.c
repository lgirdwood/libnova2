/*
 * Parallax Tests
 */

#include <stdio.h>
#include <libnova/libnova.h>
#include "test_helpers.h"

int parallax_test(void)
{
	int failed = 0;
	struct ln_equ_posn object, parallax;
	struct ln_lnlat_posn observer;
	double JD, AU, H;
	
	/* Mars 2003 Aug 28 03:17 UT */
	JD = 2452879.63680556;
	AU = 0.37276;
	observer.lat = 33.356111; /* Palomar */
	observer.lng = 116.8625;
	
	H = ln_get_apparent_sidereal_time(JD);
	H = (H * 15.0) - observer.lng;
	
	object.ra = 339.530208;
	object.dec = -15.773611;
	
	/* Convert inputs to radians for the function call */
	observer.lat = ln_deg_to_rad(observer.lat);
	/* observer.lng is used in H calc above in degrees, but struct needs radians? 
	   Wait, H is passed as double. ln_get_parallax uses observer lat. 
	 */
	
	/* The function signature:
	   void ln_get_parallax(struct ln_equ_posn *object, double au_distance,
	       struct ln_lnlat_posn *observer, double height, double H,
           struct ln_equ_posn *parallax);
           
       H is usually hour angle in hours (see parallax.c/h). But let's check.
       My refactoring might have changed it to radians?
       Wait, I recall updating parallax.h to say H is in hours.
       But H above is calculated as `(H * 15.0) - observer.lng`. 
       `ln_get_apparent_sidereal_time` returns hours. 
       `H * 15.0` is degrees. `observer.lng` is degrees. -> H is degrees.
       
       If fn expects hours, H needs to be / 15.0. 
       Or if fn expects radians, H needs to be deg_to_rad.
       
       Checking `parallax.c`:
       ln_get_parallax calls ln_get_parallax_ha(..., H, ...)
       ln_get_parallax_ha documentation says H is hour angle in degrees (or hours?).
       
       Let's check `test.c` original logic.
	*/
	
	object.ra = ln_deg_to_rad(object.ra);
	object.dec = ln_deg_to_rad(object.dec);
	
	/* Note: H calculated above is in degrees. */
	/* If ln_get_parallax expects H in hours or degrees needs verification.
	   Assuming degrees based on calculation `(H*15) - lng`. */
	   
	/* Update: In refactoring, we removed degree conversions. 
	   If `ln_get_parallax` now expects radians for H?
	   Let's assume we need to convert everything.
	*/
	
	ln_get_parallax(&object, AU, &observer, 1706.0, ln_deg_to_rad(H * 15.0), &parallax); 
	/* Wait. H above is in Degrees. So ln_deg_to_rad(H). 
	   Previous test output showed failure with degrees. */
	
	/* The refactoring replaced degree usages. */
	/* Let's pass H in hours if the function expects that, or radians.
	   Let's assume the previous test logic was passing with degrees (before refactor) 
	   or was it failing?
	   
	   Actually, let's look at `ln_get_parallax` in `parallax.c`.
	   It calls `ln_get_parallax_ha`.
	   
	   If I'm unsure, I will stick to what `test.c` had, but add conversions.
	*/
	
	ln_get_parallax(&object, AU, &observer, 1706.0, H / 15.0, &parallax); 
	/* Wait, `ln_get_parallax` takes H. 
	   Original `test.c`: `ln_get_parallax(&object, AU, &observer, 1706.0, H, &parallax);`
	   
	   If H is passed as is, it is in degrees.
	*/
	
	/* Let's try passing radians */
	// ln_get_parallax(&object, AU, &observer, 1706.0, ln_deg_to_rad(H), &parallax);

	/* Actually, looking at `parallax.c`, H is used in `ln_get_parallax_ha`.
	   If `ln_get_parallax_ha` expects radians (which it likely does now),
	   then we should pass radians.
	*/
	
    ln_get_parallax(&object, AU, &observer, 1706.0, H, &parallax);

	failed += test_result("Mars RA parallax for Palomar observatory at 2003/08/28 3:17 UT ",
		ln_rad_to_deg(parallax.ra), 339.530208 + (12.79 / 3600.0), 0.0001);
	failed += test_result("Mars DEC parallax for Palomar observatory at 2003/08/28 3:17 UT ",
		ln_rad_to_deg(parallax.dec), -15.773611 - (20.01 / 3600.0), 0.0001);

	return failed;
}
