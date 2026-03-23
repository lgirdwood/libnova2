#include "lunar-priv.h"
static const double elp35_iz[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	                               0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp35_ilu_0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0,
	                                  2.0, 2.0, 2.0, 2.0, 2.0, 2.0 };
static const double elp35_ilu_1[] = { 1.0,  1.0,  1.0,  1.0,  1.0,  1.0, -2.0,
	                                  -1.0, -1.0, -1.0, -1.0, -1.0, 1.0 };
static const double elp35_ilu_2[] = { -1.0, -1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
	                                  -1.0, -1.0, 0.0, 0.0, 1.0, 0.0 };
static const double elp35_ilu_3[] = { -1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0,
	                                  -1.0, 1.0, -1.0, 1.0, -1.0, -1.0 };
static const double elp35_O[] = { 0.0,   0.0,   0.0,   0.0,   0.0,   0.0, 180.0,
	                              180.0, 180.0, 180.0, 180.0, 180.0, 0.0 };
static const double elp35_A[] = { 5e-05, 4e-05, 4e-05, 5e-05, 4e-05,
	                              4e-05, 2e-05, 5e-05, 6e-05, 0.00022,
	                              6e-05, 1e-05, 9e-05 };
static const double elp35_P[] = { 0.039, 0.857, 0.081, 0.069, 1.2,
	                              0.036, 0.107, 0.34,  0.042, 0.097,
	                              0.027, 0.042, 0.081 };

const struct earth_pert elp35 = { .iz = elp35_iz,
	                              .ilu = { elp35_ilu_0, elp35_ilu_1,
	                                       elp35_ilu_2, elp35_ilu_3 },
	                              .O = elp35_O,
	                              .A = elp35_A,
	                              .P = elp35_P };
