#include "lunar-priv.h"
static const double elp25_iz[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp25_ilu_0[] = { 0.0, 0.0, 2.0, 2.0, 2.0, 2.0 };
static const double elp25_ilu_1[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp25_ilu_2[] = { 1.0, 2.0, -2.0, -1.0, 0.0, 1.0 };
static const double elp25_ilu_3[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp25_O[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp25_A[] = { 0.00058, 4e-05, 2e-05, 0.00021, 9e-05, 1e-05 };
static const double elp25_P[] = { 0.075, 0.038, 0.564, 0.087, 0.04, 0.026 };

const struct earth_pert elp25 = { .iz = elp25_iz,
								  .ilu = { elp25_ilu_0, elp25_ilu_1,
										   elp25_ilu_2, elp25_ilu_3 },
								  .O = elp25_O,
								  .A = elp25_A,
								  .P = elp25_P };
