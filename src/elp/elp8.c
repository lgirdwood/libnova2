#include "lunar-priv.h"
static const double elp8_iz[] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
	                              1.0, 1.0, 1.0, 1.0, 2.0 };
static const double elp8_ilu_0[] = { -2.0, -2.0, 0.0, 0.0, 0.0, 0.0,
	                                 0.0,  0.0,  2.0, 2.0, 0.0 };
static const double elp8_ilu_1[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	                                 0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp8_ilu_2[] = { 0.0, 1.0, -1.0, -1.0, 0.0, 0.0,
	                                 1.0, 2.0, -1.0, 0.0,  0.0 };
static const double elp8_ilu_3[] = { 0.0, 0.0, -2.0, 0.0, -2.0, 0.0,
	                                 0.0, 0.0, 0.0,  0.0, -1.0 };
static const double elp8_O[] = { 180.0, 180.0, 180.0, 180.0, 180.0, 0.0,
	                             0.0,   0.0,   0.0,   0.0,   180.0 };
static const double elp8_A[] = { 0.00012, 3e-05,   1e-05,   0.00019,
	                             0.00014, 0.00342, 0.00018, 1e-05,
	                             4e-05,   2e-05,   9e-05 };
static const double elp8_P[] = { 0.088, 0.53,  0.037, 8.847, 0.074, 0.075,
	                             0.038, 0.025, 0.04,  0.026, 0.075 };

const struct earth_pert elp8 = { .iz = elp8_iz,
	                             .ilu = { elp8_ilu_0, elp8_ilu_1, elp8_ilu_2,
	                                      elp8_ilu_3 },
	                             .O = elp8_O,
	                             .A = elp8_A,
	                             .P = elp8_P };
