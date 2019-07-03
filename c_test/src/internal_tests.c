#include "tests.h"

void test_MH_assert() {
	bool tests[16];

	int i1 = 10, i2 = 10;
	tests[0] = MH_assert(INT, i1, i2);
	i2 = 12;
	tests[1] = !MH_assert(INT, i1, i2);

	float f1 = 1.45, f2 = 1.45;
	tests[2] = MH_assert(FLOAT, f1, f2);
	f2 = 1.44;
	tests[3] = !MH_assert(FLOAT, f1, f2);

	double d1 = 4.34, d2 = 4.34;
	tests[4] = MH_assert(DOUBLE, d1, d2);
	d2 = 4.33;
	tests[5] = !MH_assert(DOUBLE, d1, d2);

	long l1 = 4295730, l2 = 4295730;
	tests[6] = MH_assert(LONG, l1, l2);
	l2 = 4829573;
	tests[7] = !MH_assert(LONG, l1, l2);

	long long ll1 = 6285938563, ll2 = 6285938563;
	tests[8] = MH_assert(LONGLONG, ll1, ll2);
	ll2 = 8;
	tests[9] = !MH_assert(LONGLONG, ll1, ll2);

	char c1 = 'a', c2 = 'a';
	tests[10] = MH_assert(CHAR, c1, c2);
	c2 = 'b';
	tests[11] = !MH_assert(CHAR, c1, c2);

	char* s1 = "This is a test", *s2 = "This is a test", *s3 = "This is not a test";
	tests[12] = MH_assert(STRING, s1, s2);
	tests[13] = !MH_assert(STRING, s1, s3);

	bool b1 = true, b2 = true;
	tests[14] = MH_assert(BOOL, b1, b2);
	tests[15] = !MH_assert(BOOL, b1, !b2);

	int i = 0;
	for(i = 0; i < 16; ++i) {
		if(!tests[i]) {
			test_fail("MH_assert");
			return;
		}
	}
	test_pass("MH_assert");
}

void test_MH_assert_strlen() {
	bool tests[3];

	char* s = "This is a test\0";
	int len = 14;
	tests[0] = (len == MH_assert_strlen(s));

	char* s1 = "This is a test";
	tests[1] = (len == MH_assert_strlen(s1));

	char* s2 = "This is another test";
	tests[2] = (len != MH_assert_strlen(s2));

	if(tests[0] && tests[1] && tests[2]) {
		test_pass("MH_assert_strlen");
	} else {
		test_fail("MH_assert_strlen");
	}
}

void test_MH_assert_strcmp() {
	bool tests[3];

	char* s1 = "This is a test";
	char* s2 = "This is a test";
	char* s3 = malloc(15 * sizeof(char));
	int i = 0;
	for(i = 0; i < 15; ++i) {
		s3[i] = s1[i];
	}

	tests[0] = MH_assert_strcmp(s1, s2);
	tests[1] = MH_assert_strcmp(s1, s3);
	s3[5] = 'b';
	tests[2] = !MH_assert_strcmp(s1, s3);

	if(tests[0] && tests[1] && tests[2]) {
		test_pass("MH_assert_strcmp");
	} else {
		test_fail("MH_assert_strcmp");
	}
}
