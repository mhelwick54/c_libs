#include <stdio.h>

#include "c_bool.h"

#include "internal_tests.h"

int main() {
	test_MH_assert_strlen();
	test_MH_assert_strcmp();
	test_MH_assert();

	return 0;
}
