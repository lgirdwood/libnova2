/*
 * Test Helpers for libnova2 unit tests
 */

#define _GNU_SOURCE

#if defined(__MINGW__) || defined(__MINGW32__) || defined(__MINGW64__)
#define _USE_32BIT_TIME_T
#endif //__MINGW__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <libnova2/utility.h>
#include "test_helpers.h"

#ifndef __WIN32__
#include <unistd.h>
#endif

#ifdef __WIN32__
#include <time.h>

// the usleep function does not exist in visual studio
void usleep(int miliseconds)
{
	clock_t endwait;
	endwait = clock() + miliseconds * CLOCKS_PER_SEC / 1000;
	while (clock() < endwait) {
	}
}
#endif

// holds number of tests
int test_number = 0;

static struct timeval start, end;

void start_timer(void)
{
	gettimeofday(&start, NULL);
}

double end_timer(void)
{
	double secs;

	gettimeofday(&end, NULL);
	secs = ((end.tv_sec * 1000000 + end.tv_usec) -
	        (start.tv_sec * 1000000 + start.tv_usec)) /
	       1000000.0;

	return secs;
}

double compare_results(double calc, double expect, double tolerance)
{
	if (calc - expect > tolerance || calc - expect < (tolerance * -1.0))
		return calc - expect;
	else
		return 0;
}

int test_result(char *test, double calc, double expect, double tolerance)
{
	double diff;

	fprintf(stdout, "TEST %s....", test);

	test_number++;

	diff = compare_results(calc, expect, tolerance);
	if (diff) {
		fprintf(stdout, "[FAILED]\n");
		fprintf(stdout,
		        "	Expected %8.8f but calculated %8.8f %0.12f error.\n\n",
		        expect, calc, diff);
		return 1;
	} else {
		fprintf(stdout, "[PASSED]\n");
		fprintf(stdout, "\tExpected and calculated %8.8f.\n\n", calc);
		return 0;
	}
}

int test_result_dms(char *test, double calc, double expect, double tolerance)
{
	double diff;
	struct ln_dms dms_calc, dms_expect, dms_diff;

	fprintf(stdout, "TEST %s....", test);

	test_number++;

	diff = compare_results(calc, expect, tolerance);
	if (diff != 0.0) {
		ln2_deg_to_dms(calc, &dms_calc);
		ln2_deg_to_dms(expect, &dms_expect);
		ln2_deg_to_dms(diff, &dms_diff);

		fprintf(stdout, "[FAILED]\n");
		fprintf(stdout,
		        "	Expected %s%d\xc2\xb0%d\'%f\" but calculated %s%d\xc2\xb0%d\'%f\". Error %s%d\xc2\xb0%d\'%f\"\n\n",
		        dms_expect.neg ? "-" : "", dms_expect.degrees,
		        dms_expect.minutes, dms_expect.seconds, dms_calc.neg ? "-" : "",
		        dms_calc.degrees, dms_calc.minutes, dms_calc.seconds,
		        dms_diff.neg ? "-" : "", dms_diff.degrees, dms_diff.minutes,
		        dms_diff.seconds);
		return 1;
	} else {
		ln2_deg_to_dms(calc, &dms_calc);
		fprintf(stdout, "[PASSED]\n");
		fprintf(stdout, "\tExpected and calculated %s%d\xc2\xb0%d\'%f\".\n\n",
		        dms_calc.neg ? "-" : "", dms_calc.degrees, dms_calc.minutes,
		        dms_calc.seconds);
		return 0;
	}
}

int test_result_hms(char *test, double calc, double expect, double tolerance)
{
	double diff;
	struct ln_hms hms_calc, hms_expect, hms_diff;

	fprintf(stdout, "TEST %s....", test);

	test_number++;

	diff = compare_results(calc, expect, tolerance);
	if (diff != 0.0) {
		ln2_deg_to_hms(calc * 15.0, &hms_calc);
		ln2_deg_to_hms(expect * 15.0, &hms_expect);
		ln2_deg_to_hms(diff * 15.0, &hms_diff);

		fprintf(stdout, "[FAILED]\n");
		fprintf(stdout,
		        "	Expected %dh %dm %fs but calculated %dh %dm %fs. Error %dh %dm %fs\n\n",
		        hms_expect.hours, hms_expect.minutes, hms_expect.seconds,
		        hms_calc.hours, hms_calc.minutes, hms_calc.seconds,
		        hms_diff.hours, hms_diff.minutes, hms_diff.seconds);
		return 1;
	} else {
		ln2_deg_to_hms(calc * 15.0, &hms_calc);
		fprintf(stdout, "[PASSED]\n");
		fprintf(stdout, "\tExpected and calculated %dh %dm %fs.\n\n",
		        hms_calc.hours, hms_calc.minutes, hms_calc.seconds);
		return 0;
	}
}

int test_str_result(char *test, const char *calc, const char *expect)
{
	int diff;

	fprintf(stdout, "TEST %s....", test);

	test_number++;

	diff = strcmp(calc, expect);
	if (diff) {
		fprintf(stdout, "[FAILED]\n");
		fprintf(stdout, "	Expected %s but calculated %s.\n\n", expect, calc);
		return 1;
	} else {
		fprintf(stdout, "[PASSED]\n");
		fprintf(stdout, "	Expected and calculated %s.\n\n", calc);
		return 0;
	}
}
