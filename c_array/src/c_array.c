#include "c_array.h"

void MH_array_init(array** a, types type, int rows, int cols) {
	*a = malloc(sizeof(array));
	(*a)->type = type;
	(*a)->rows = rows;
	(*a)->cols = cols;
	MH_array_alloc(*a);
}

void MH_array_malloc(void*** ptr, int size, int rows, int cols) {
	*ptr = malloc(rows * size);
	mem_check2(*ptr);

	int i = 0;
	for(i = 0; i < rows; ++i) {
		(*ptr)[i] = malloc(cols * size);
		mem_check1((*ptr)[i]);
	}
}

void MH_array_alloc(array* a) {
	switch(a->type) {
		case INT: {
			MH_array_malloc((void***)&(a->ptr.i), sizeof(int), a->rows, a->cols);
		}
			break;
		case FLOAT: {
			MH_array_malloc((void***)&(a->ptr.f), sizeof(float), a->rows, a->cols);
		}
			break;
		case DOUBLE: {
			MH_array_malloc((void***)&(a->ptr.d), sizeof(double), a->rows, a->cols);
		}
			break;
		case LONG: {
			MH_array_malloc((void***)&(a->ptr.l), sizeof(long), a->rows, a->cols);
		}
			break;
		case LONGLONG: {
			MH_array_malloc((void***)&(a->ptr.ll), sizeof(long long), a->rows, a->cols);
		}
			break;
		case CHAR: {
			MH_array_malloc((void***)&(a->ptr.c), sizeof(char), a->rows, a->cols);
		}
			break;
		case BOOL: {
			MH_array_malloc((void***)&(a->ptr.b), sizeof(bool), a->rows, a->cols);
		}
			break;
		default:
			ERROR("unkown type", UNKNOWN_TYPE);
	}
}

void MH_array_resize(array* a, int rows, int cols) {

}

void MH_free_union(void*** ptr, int rows, int cols) {
	for(rows = rows - 1; rows >= 0; --rows) {
		free((*ptr)[rows]);
	}
	free(*ptr);
}

array* MH_array_delete(array** a) {
	switch((*a)->type) {
		case INT: {
			MH_free_union((void***)&((*a)->ptr.i), (*a)->rows, (*a)->cols);
		}
			break;
		case FLOAT: {
			MH_free_union((void***)&((*a)->ptr.f), (*a)->rows, (*a)->cols);
		}
			break;
		case DOUBLE: {
			MH_free_union((void***)&((*a)->ptr.d), (*a)->rows, (*a)->cols);
		}
			break;
		case LONG: {
			MH_free_union((void***)&((*a)->ptr.l), (*a)->rows, (*a)->cols);
		}
			break;
		case LONGLONG: {
			MH_free_union((void***)&((*a)->ptr.ll), (*a)->rows, (*a)->cols);
		}
			break;
		case CHAR: {
			MH_free_union((void***)&((*a)->ptr.c), (*a)->rows, (*a)->cols);
		}
			break;
		case BOOL: {
			MH_free_union((void***)&((*a)->ptr.b), (*a)->rows, (*a)->cols);
		}
			break;
		default:
			ERROR("unkown type", UNKNOWN_TYPE);
	}
	free(*a);
	return NULL;
}
