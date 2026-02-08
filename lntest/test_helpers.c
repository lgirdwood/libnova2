/* 
 * Test Helpers for libnova unit tests
 */

#define _GNU_SOURCE

#if defined(__MINGW__) || defined(__MINGW32__) || defined(__MINGW64__)
#define _USE_32BIT_TIME_T
#endif	//__MINGW__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
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
    endwait = clock () + miliseconds * CLOCKS_PER_SEC / 1000;
    while (clock() < endwait) {}
}
#endif

// holds number of tests
int test_number = 0;

static struct timeval start, end;

void start_timer(void)
{
	gettimeofday(&start, NULL);
}

void end_timer(void)
{
	double secs;

	gettimeofday(&end, NULL);
	secs = ((end.tv_sec * 1000000 + end.tv_usec) -
		(start.tv_sec * 1000000 + start.tv_usec)) / 1000000.0;

	fprintf(stdout, "   Time %3.1f msecs\n", secs * 1000.0);
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
		fprintf(stdout, "	Expected and calculated %8.8f.\n\n", calc);
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
		fprintf(stdout,
			"	Expected %s but calculated %s.\n\n",
			expect, calc);
		return 1;
	} else {
		fprintf(stdout, "[PASSED]\n");
		fprintf(stdout, "	Expected and calculated %s.\n\n", calc);
		return 0;
	}
}
