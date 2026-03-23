#include "lunar-priv.h"
static const double elp9_iz[] = { 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
static const double elp9_ilu_0[] = { 0.0, -2.0, -2.0, 0.0, 0.0, 0.0, 2.0, 2.0 };
static const double elp9_ilu_1[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp9_ilu_2[] = { 0.0, 0.0, 1.0, -1.0, -1.0, 1.0, -1.0, 0.0 };
static const double elp9_ilu_3[] = { 0.0, -1.0, -1.0, -1.0,
	                                 1.0, -1.0, -1.0, -1.0 };
static const double elp9_O[] = { 270.0, 270.0, 270.0, 270.0,
	                             90.0,  90.0,  90.0,  90.0 };
static const double elp9_A[] = { 4e-05, 4e-05,   2e-05, 0.00019,
	                             3e-05, 0.00019, 2e-05, 4e-05 };
static const double elp9_P[] = { 99999.999, 0.04,  0.087, 0.075,
	                             0.074,     0.076, 0.088, 0.041 };

const struct earth_pert elp9 = { .iz = elp9_iz,
	                             .ilu = { elp9_ilu_0, elp9_ilu_1, elp9_ilu_2,
	                                      elp9_ilu_3 },
	                             .O = elp9_O,
	                             .A = elp9_A,
	                             .P = elp9_P };
