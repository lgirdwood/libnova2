#include "lunar-priv.h"
static const double elp29_iz[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
								   0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp29_ilu_0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
									  0.0, 0.0, 0.0, 2.0, 2.0, 2.0 };
static const double elp29_ilu_1[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
									  1.0, 1.0, 1.0, 0.0, 0.0, 0.0 };
static const double elp29_ilu_2[] = { 1.0, 1.0, 1.0, 2.0,  2.0,	 -1.0,
									  0.0, 0.0, 1.0, -2.0, -2.0, 0.0 };
static const double elp29_ilu_3[] = { -1.0, 0.0, 1.0, -3.0, -1.0, -1.0,
									  -1.0, 1.0, 1.0, -1.0, 1.0,  -1.0 };
static const double elp29_O[] = { 0.02199,	 245.99067, 0.0053,	   0.42283,
								  0.74505,	 359.99982, 359.99982, 359.99982,
								  359.99982, 179.98356, 179.98353, 179.99478 };
static const double elp29_A[] = { 3e-05,  1e-05,  1e-05, 2e-05, 1e-05, 1e-05,
								  0.0001, 0.0001, 1e-05, 1e-05, 1e-05, 5e-05 };
static const double elp29_P[] = { 5.997, 0.075, 0.037, 0.073, 0.076, 0.039,
								  0.081, 0.069, 0.036, 0.066, 0.086, 0.088 };

const struct earth_pert elp29 = { .iz = elp29_iz,
								  .ilu = { elp29_ilu_0, elp29_ilu_1,
										   elp29_ilu_2, elp29_ilu_3 },
								  .O = elp29_O,
								  .A = elp29_A,
								  .P = elp29_P };
