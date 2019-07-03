#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

#include "error_defs.h"

void error(const char* file, int line, const char* msg, int err);

#define ERROR(MESSAGE, ERR) error(__FILE__, __LINE__, MESSAGE, ERR)

static inline void mem_check1(void* ptr) {
	if(!ptr) {
		ERROR("memory allocation failed", MALLOC);
	}
}

static inline void mem_check2(void** ptr) {
	if(!ptr) {
		ERROR("memory allocation failed", MALLOC);
	}
}

#endif //ERROR_H
