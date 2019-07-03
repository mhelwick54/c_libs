#include "test.h"

void test_pass(char* name_of_func) {
	printf("%-30s %s[ok]%s\n", name_of_func, PASS_COL, RESET);
}

void test_fail(char* name_of_func) {
	printf("%-30s %s[fail]%s\n", name_of_func, FAIL_COL, RESET);
}
