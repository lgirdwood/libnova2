#include "lunar-priv.h"
static const double elp23_iz[] = { 0.0, 0.0 };
static const double elp23_ilu_0[] = { 1.0, 1.0 };
static const double elp23_ilu_1[] = { 1.0, 1.0 };
static const double elp23_ilu_2[] = { 0.0, 0.0 };
static const double elp23_ilu_3[] = { -2.0, 0.0 };
static const double elp23_O[] = { 192.93663, 192.93664 };
static const double elp23_A[] = { 4e-05, 4e-05 };
static const double elp23_P[] = { 0.074, 0.075 };

const struct earth_pert elp23 = { .iz = elp23_iz,
	                              .ilu = { elp23_ilu_0, elp23_ilu_1,
	                                       elp23_ilu_2, elp23_ilu_3 },
	                              .O = elp23_O,
	                              .A = elp23_A,
	                              .P = elp23_P };
