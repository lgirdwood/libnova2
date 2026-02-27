#include "lunar-priv.h"
static const double elp27_iz[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp27_ilu_0[] = { 0.0, 0.0, 0.0, 2.0, 2.0 };
static const double elp27_ilu_1[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp27_ilu_2[] = { 0.0, 1.0, 2.0, -1.0, 0.0 };
static const double elp27_ilu_3[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
static const double elp27_O[] = { 90.0, 270.0, 270.0, 270.0, 270.0 };
static const double elp27_A[] = { 0.00356, 0.00072, 3e-05, 0.00019, 0.00013 };
static const double elp27_P[] = { 99999.999, 0.075, 0.038, 0.087, 0.04 };

const struct earth_pert elp27 = { .iz = elp27_iz,
								  .ilu = { elp27_ilu_0, elp27_ilu_1,
										   elp27_ilu_2, elp27_ilu_3 },
								  .O = elp27_O,
								  .A = elp27_A,
								  .P = elp27_P };
