#include "c_string_tests.h"

void test_memCheck() {
	char* s = "This is a test";
	char* s1 = malloc(5 * sizeof(char));

	MH_memCheck(s);
	MH_memCheck(s1);

	free(s1);
}

void test_boundCheck() {
	int num_tests = 3;
	bool tests[num_tests];

	char* s = "This is a test";
	tests[0] = MH_assert(BOOL, MH_boundCheck(s, 14), true);
	tests[1] = MH_assert(BOOL, MH_boundCheck(s, -1), false);
	tests[2] = MH_assert(BOOL, MH_boundCheck(s, 20), false);

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_boundCheck");
			return;
		}
	}
	test_pass("MH_boundCheck");
}

void test_strlen() {
	int num_tests = 3;
	bool tests[num_tests];

	char* s1 = "This is a test\0";
	char* s2 = "This is a test";

	tests[0] = MH_assert(INT, MH_strlen(s1), 14);
	tests[1] = MH_assert(INT, MH_strlen(s2), 14);
	tests[2] = !MH_assert(INT, MH_strlen(s2), 12);

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_strlen");
			return;
		}
	}
	test_pass("MH_strlen");
}

void test_at() {
	int num_tests = 1;
	bool tests[num_tests];

	char* s = "ABCDEFG";
	tests[0] = MH_assert(CHAR, MH_at(s, 3), 'D');

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_at");
			return;
		}
	}
	test_pass("MH_at");
}

void test_back() {
	int num_tests = 1;
	bool tests[num_tests];

	char* s = "ABCDEFG";
	tests[0] = MH_assert(CHAR, MH_back(s), 'G');

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_back");
			return;
		}
	}
	test_pass("MH_back");
}

void test_front() {
	int num_tests = 1;
	bool tests[num_tests];

	char* s = "ABCDEFG";
	tests[0] = MH_assert(CHAR, MH_front(s), 'A');

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_front");
			return;
		}
	}
	test_pass("MH_front");
}

void test_append() {
	int num_tests = 1;
	bool tests[num_tests];

	char* app = "appended string";
	char* s = malloc(13 * sizeof(char));
	MH_stringCopy(&s, "first string");
	MH_append(&s, app);

	tests[0] = MH_assert(STRING, s, "first stringappended string");

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_append");
			return;
		}
	}
	test_pass("MH_append");

	free(s);
}

void test_pushBack() {
	int num_tests = 1;
	bool tests[num_tests];

	char* s = malloc(15 * sizeof(char));
	MH_stringCopy(&s, "This is a test");
	char c = '!';
	MH_pushBack(&s, c);

	tests[0] = MH_assert(STRING, s, "This is a test!");

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_pushBack");
			return;
		}
	}
	test_pass("MH_pushBack");

	free(s);
}

void test_popBack() {
	int num_tests = 2;
	bool tests[num_tests];

	char* s = malloc(16 * sizeof(char));
	MH_stringCopy(&s, "This is a test!");

	char c = MH_popBack(&s);

	tests[0] = MH_assert(STRING, s, "This is a test");
	tests[1] = MH_assert(CHAR, c, '!');

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_popBack");
			return;
		}
	}
	test_pass("MH_popBack");

	free(s);
}

void test_insertString() {
	int num_tests = 1;
	bool tests[num_tests];

	char* s = malloc(15 * sizeof(char));
	MH_stringCopy(&s, "This is a test");
	char* s1 = "(insert)";

	MH_insertString(&s, s1, 6);

	tests[0] = MH_assert(STRING, s, "This i(insert)s a test");

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_insertString");
			return;
		}
	}
	test_pass("MH_insertString");

	free(s);
}

void test_insertChar() {
	int num_tests = 1;
	bool tests[num_tests];

	char* s = malloc(15 * sizeof(char));
	MH_stringCopy(&s, "This is a test");
	char c = 'z';

	MH_insertChar(&s, c, 6);

	tests[0] = MH_assert(STRING, s, "This izs a test");

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_insertChar");
			return;
		}
	}
	test_pass("MH_insertChar");

	free(s);
}

void test_replaceString() {
	int num_tests = 1;
	bool tests[num_tests];

	char* s = malloc(15 * sizeof(char));
	MH_stringCopy(&s, "This is a test");
	char* s1 = "es u";

	MH_replaceString(&s, s1, 5);

	tests[0] = MH_assert(STRING, s, "This es u test");

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_replaceString");
			return;
		}
	}
	test_pass("MH_replaceString");

	free(s);
}

void test_replaceChar() {
	int num_tests = 1;
	bool tests[num_tests];

	char* s = malloc(15 * sizeof(char));
	MH_stringCopy(&s, "This is a test");
	char c = 'z';

	MH_replaceChar(&s, c, 6);

	tests[0] = MH_assert(STRING, s, "This iz a test");

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_replaceChar");
			return;
		}
	}
	test_pass("MH_replaceChar");

	free(s);
}

void test_substr() {
	int num_tests = 1;
	bool tests[num_tests];

	char* s = malloc(15 * sizeof(char));
	MH_stringCopy(&s, "This is a test");
	char* s1 = malloc(sizeof(char));

	MH_substr(s, &s1, 5, 8);

	tests[0] = MH_assert(STRING, s1, "is a");

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_substr");
			return;
		}
	}
	test_pass("MH_substr");
}

void test_erase() {
	int num_tests = 1;
	bool tests[num_tests];

	char* s = malloc(15 * sizeof(char));
	MH_stringCopy(&s, "This is a test");

	MH_erase(&s);

	tests[0] = MH_assert(STRING, s, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_erase");
			return;
		}
	}
	test_pass("MH_erase");

	free(s);
}

void test_eraseString() {
	int num_tests = 1;
	bool tests[num_tests];

	char* s = malloc(15 * sizeof(char));
	MH_stringCopy(&s, "This is a test");

	MH_eraseString(&s, 5, 9);

	tests[0] = MH_assert(STRING, s, "This test");

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_eraseString");
			return;
		}
	}
	test_pass("MH_eraseString");

	free(s);
}

void test_eraseChar() {
	int num_tests = 1;
	bool tests[num_tests];

	char* s = malloc(15 * sizeof(char));
	MH_stringCopy(&s, "This is a test");

	MH_eraseChar(&s, 6);

	tests[0] = MH_assert(STRING, s, "This i a test");

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_eraseChar");
			return;
		}
	}
	test_pass("MH_eraseChar");
}

void test_stringCopy() {
	int num_tests = 1;
	bool tests[num_tests];

	char* s = malloc(sizeof(char));
	char* cpy = "String to copy";
	MH_stringCopy(&s, cpy);

	tests[0] = MH_assert(STRING, s, "String to copy");

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_stringCopy");
			return;
		}
	}
	test_pass("MH_stringCopy");

	free(s);
}

void test_deleteString() {
	char* s = malloc(15 * sizeof(char));
	MH_stringCopy(&s, "This is a test");
	
	MH_deleteString(&s);
	test_pass("MH_deleteString");
}

void test() {
	test_memCheck();
	test_boundCheck();
	test_strlen();
	test_at();
	test_back();
	test_front();
	test_append();
	test_pushBack();
	test_popBack();
	test_insertString();
	test_insertChar();
	test_replaceString();
	test_replaceChar();
	test_substr();
	test_erase();
	test_eraseString();
	test_eraseChar();
	test_stringCopy();
	test_deleteString();
}
