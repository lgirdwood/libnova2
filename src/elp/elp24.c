#include "lunar-priv.h"
static const double elp24_iz[] = { 0.0, 0.0 };
static const double elp24_ilu_0[] = { 1.0, 1.0 };
static const double elp24_ilu_1[] = { 1.0, 1.0 };
static const double elp24_ilu_2[] = { -1.0, 1.0 };
static const double elp24_ilu_3[] = { -1.0, -1.0 };
static const double elp24_O[] = { 282.93665, 102.93665 };
static const double elp24_A[] = { 4e-05, 4e-05 };
static const double elp24_P[] = { 0.075, 0.076 };

const struct earth_pert elp24 = { .iz = elp24_iz,
	                              .ilu = { elp24_ilu_0, elp24_ilu_1,
	                                       elp24_ilu_2, elp24_ilu_3 },
	                              .O = elp24_O,
	                              .A = elp24_A,
	                              .P = elp24_P };
