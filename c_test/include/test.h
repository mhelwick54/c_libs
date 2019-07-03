#ifndef TEST_H
#define TEST_H

#include <stdio.h>

#define PASS_COL "\033[0;32m"
#define FAIL_COL "\033[0;31m"
#define RESET "\033[0m"

void test_pass(char* name_of_func);
void test_fail(char* name_of_func);

#endif //TEST_H
