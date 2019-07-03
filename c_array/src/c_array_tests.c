#include "c_array_tests.h"

void test_array_init() {
	int num_tests = 4;
	bool tests[num_tests];
	array* a;

	MH_array_init(&a, INT, 10, 10);

	tests[0] = MH_assert(INT, (int)a->type, (int)INT);
	tests[1] = MH_assert(INT, a->rows, 10);
	tests[2] = MH_assert(INT, a->cols, 10);
	tests[3] = (a->ptr.i != NULL);

	int i = 0;
	for(i = 0; i < num_tests; ++i) {
		if(!tests[i]) {
			test_fail("MH_array_init");
			return;
		}
	}
	test_pass("MH_array_init");

	a = MH_array_delete(&a);
}

void test_array_malloc() {
	array* a = malloc(sizeof(array));

	a->type = INT;
	a->rows = 10;
	a->cols = 10;

	MH_array_malloc((void***)&(a->ptr.i), sizeof(int), a->rows, a->cols);

	test_pass("MH_array_malloc");

	for(a->rows = a->rows - 1; a->rows >= 0; --(a->rows)) {
		free(a->ptr.i[a->rows]);
	}
	free(a->ptr.i);
	free(a);
}

void test_array_alloc() {
	array* a = malloc(sizeof(array));

	a->type = INT;
	a->rows = 10;
	a->cols = 10;

	MH_array_alloc(a);

	test_pass("MH_array_alloc");

	for(a->rows = a->rows - 1; a->rows >= 0; --(a->rows)) {
		free(a->ptr.i[a->rows]);
	}
	free(a->ptr.i);
	free(a);
}

void test_array_resize() {

}

void test_array_free_union() {
	array* a = malloc(sizeof(array));

	a->type = INT;
	a->rows = 10;
	a->cols = 10;

	MH_array_alloc(a);

	MH_free_union((void***)&(a->ptr.i), a->rows, a->cols);

	test_pass("MH_union_free");

	free(a);
}

void test_array_delete() {
	array* a = malloc(sizeof(array));

	a->type = INT;
	a->rows = 10;
	a->cols = 10;

	MH_array_alloc(a);

	a = MH_array_delete(&a);

	test_pass("MH_array_delete");
}

void test() {
	test_array_malloc();
	test_array_alloc();
	test_array_free_union();
	test_array_delete();
	test_array_init();
	test_array_resize();
}
