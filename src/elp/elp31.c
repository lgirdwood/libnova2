#include "lunar-priv.h"
static const double elp31_iz[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
								   0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp31_ilu_0[] = { 0.0, 0.0, 0.0, 1.0, 1.0, 2.0,
									  2.0, 2.0, 2.0, 2.0, 4.0 };
static const double elp31_ilu_1[] = { 1.0, 1.0, 1.0, 0.0, 1.0, -1.0,
									  0.0, 0.0, 0.0, 1.0, 0.0 };
static const double elp31_ilu_2[] = { -1.0, 0.0, 1.0, 0.0,	0.0, -1.0,
									  -1.0, 0.0, 1.0, -1.0, -1.0 };
static const double elp31_ilu_3[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
									  0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp31_O[] = { 179.93473, 179.98532, 179.96323, 1e-05,
								  180.02282, 0.02264,	359.98826, 180.00019,
								  180.00017, 180.74954, 180.00035 };
static const double elp31_A[] = { 6e-05, 0.00081, 5e-05, 0.00013, 1e-05, 2e-05,
								  2e-05, 0.00055, 6e-05, 1e-05,	  1e-05 };
static const double elp31_P[] = { 0.082, 1.0,  0.07,  0.081, 0.075, 0.095,
								  0.087, 0.04, 0.026, 0.08,	 0.028 };

const struct earth_pert elp31 = { .iz = elp31_iz,
								  .ilu = { elp31_ilu_0, elp31_ilu_1,
										   elp31_ilu_2, elp31_ilu_3 },
								  .O = elp31_O,
								  .A = elp31_A,
								  .P = elp31_P };
