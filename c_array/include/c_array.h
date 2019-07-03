#ifndef C_ARRAY_H
#define C_ARRAY_H

#include <stdlib.h>

#include "c_bool.h"
#include "error.h"
#include "c_types.h"

union arr {
	int** 		i;
	float** 	f;
	double** 	d;
	long** 		l;
	long** 		ll;
	char** 		c;
	bool** 		b;
};

typedef struct Array {
	union arr ptr;
	types type;
	int rows;
	int cols;
} array;

void MH_array_init(array** a, types type, int rows, int cols);
void MH_array_malloc(void*** ptr, int size, int rows, int cols);
void MH_array_alloc(array* a);
void MH_array_resize(array* a, int rows, int cols);
void MH_free_union(void*** ptr, int rows, int cols);
array* MH_array_delete(array** a);

#endif //C_ARRAY_H
