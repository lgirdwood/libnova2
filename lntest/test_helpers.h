#ifndef _LN_TEST_HELPERS_H
#define _LN_TEST_HELPERS_H

#include <libnova/libnova.h>

void start_timer(void);

void end_timer(void);

double compare_results(double calc, double expect, double tolerance);

int test_result(char *test, double calc, double expect, double tolerance);

int test_str_result(char *test, const char *calc, const char *expect);

extern int test_number;

#endif
