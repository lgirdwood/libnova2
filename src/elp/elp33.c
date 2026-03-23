#include "lunar-priv.h"
static const double elp33_iz[] = { 0.0, 0.0, 0.0, 0.0, 0.0,
	                               0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp33_ilu_0[] = { 0.0, 0.0, 0.0, 0.0, 0.0,
	                                  1.0, 2.0, 2.0, 2.0, 2.0 };
static const double elp33_ilu_1[] = { 0.0, 0.0,  1.0, 1.0, 1.0,
	                                  0.0, -1.0, 0.0, 0.0, 0.0 };
static const double elp33_ilu_2[] = { 0.0, 1.0, -1.0, 0.0, 1.0,
	                                  0.0, 0.0, -1.0, 0.0, 1.0 };
static const double elp33_ilu_3[] = { 0.0, 0.0, 0.0, 0.0, 0.0,
	                                  0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp33_O[] = { 270.0,    89.99994,  269.93292, 270.00908,
	                              89.95765, 270.00002, 89.97071,  269.99367,
	                              90.00014, 90.0001 };
static const double elp33_A[] = { 0.00828, 0.00043, 5e-05, 9e-05,   5e-05,
	                              6e-05,   2e-05,   3e-05, 0.00106, 8e-05 };
static const double elp33_P[] = { 99999.999, 0.075, 0.082, 1.0,  0.07,
	                              0.081,     0.042, 0.087, 0.04, 0.026 };

const struct earth_pert elp33 = { .iz = elp33_iz,
	                              .ilu = { elp33_ilu_0, elp33_ilu_1,
	                                       elp33_ilu_2, elp33_ilu_3 },
	                              .O = elp33_O,
	                              .A = elp33_A,
	                              .P = elp33_P };
