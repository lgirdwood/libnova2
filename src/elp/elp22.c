#include "lunar-priv.h"
static const double elp22_iz[] = { 0.0, 0.0, 0.0 };
static const double elp22_ilu_0[] = { 1.0, 1.0, 1.0 };
static const double elp22_ilu_1[] = { 1.0, 1.0, 1.0 };
static const double elp22_ilu_2[] = { -1.0, 0.0, 1.0 };
static const double elp22_ilu_3[] = { -1.0, -1.0, -1.0 };
static const double elp22_O[] = { 192.93665, 192.93665, 192.93665 };
static const double elp22_A[] = { 4e-05, 0.00082, 4e-05 };
static const double elp22_P[] = { 0.075, 18.6, 0.076 };

const struct earth_pert elp22 = { .iz = elp22_iz,
	                              .ilu = { elp22_ilu_0, elp22_ilu_1,
	                                       elp22_ilu_2, elp22_ilu_3 },
	                              .O = elp22_O,
	                              .A = elp22_A,
	                              .P = elp22_P };
