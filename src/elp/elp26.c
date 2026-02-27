#include "lunar-priv.h"
static const double elp26_iz[] = { 0.0, 0.0, 0.0, 0.0 };
static const double elp26_ilu_0[] = { 0.0, 0.0, 0.0, 2.0 };
static const double elp26_ilu_1[] = { 0.0, 0.0, 0.0, 0.0 };
static const double elp26_ilu_2[] = { 0.0, 1.0, 1.0, 0.0 };
static const double elp26_ilu_3[] = { 1.0, -1.0, 1.0, -1.0 };
static const double elp26_O[] = { 180.0, 0.0, 0.0, 0.0 };
static const double elp26_A[] = { 5e-05, 3e-05, 3e-05, 1e-05 };
static const double elp26_P[] = { 0.075, 5.997, 0.037, 0.088 };

const struct earth_pert elp26 = { .iz = elp26_iz,
								  .ilu = { elp26_ilu_0, elp26_ilu_1,
										   elp26_ilu_2, elp26_ilu_3 },
								  .O = elp26_O,
								  .A = elp26_A,
								  .P = elp26_P };
