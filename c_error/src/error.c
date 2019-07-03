#include "error.h"

void error(const char* file, int line, const char* msg, int err) {
	if(err < 0 && err > FATAL_LIMIT) {
		fprintf(stderr, "in %s, line %d: fatal error - %s (%d)\n", file, line, msg, err);
		exit(err);
	} else {
		fprintf(stderr, "in %s, line %d: error - %s (%d)\n", file, line, msg, err);
	}
}
