#include "lunar-priv.h"
static const double elp32_iz[] = { 0.0, 0.0, 0.0, 0.0 };
static const double elp32_ilu_0[] = { 0.0, 0.0, 2.0, 2.0 };
static const double elp32_ilu_1[] = { 1.0, 1.0, 0.0, 0.0 };
static const double elp32_ilu_2[] = { 0.0, 0.0, 0.0, 0.0 };
static const double elp32_ilu_3[] = { -1.0, 1.0, -1.0, 1.0 };
static const double elp32_O[] = { 179.99803, 179.99798, 359.9981, 180.00026 };
static const double elp32_A[] = { 4e-05, 4e-05, 2e-05, 2e-05 };
static const double elp32_P[] = { 0.081, 0.069, 0.088, 0.026 };

const struct earth_pert elp32 = { .iz = elp32_iz,
								  .ilu = { elp32_ilu_0, elp32_ilu_1,
										   elp32_ilu_2, elp32_ilu_3 },
								  .O = elp32_O,
								  .A = elp32_A,
								  .P = elp32_P };
