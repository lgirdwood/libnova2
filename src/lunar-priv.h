/* used for elp1 - 3 */
struct main_problem {
	const double *ilu[4];
	const double *A;
	const double *B[6];
};

/* used for elp 4 - 9 */
struct earth_pert {
	const double *iz;
	const double *ilu[4];
	const double *O;
	const double *A;
	const double *P;
};

/* used for elp 10 - 21 */
struct planet_pert {
	const double *ipla[11];
	const double *theta;
	const double *O;
	const double *P;
};
