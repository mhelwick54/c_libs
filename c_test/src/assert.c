#include "assert.h"

bool MH_assert(types type, ...) {
	va_list args;
	va_start(args, type);

	switch(type) {
		case INT: {
			int arg1 = va_arg(args, int);
			int arg2 = va_arg(args, int);
			return (arg1 == arg2);
		}
		case FLOAT: {
			float arg1 = (float)va_arg(args, double);
			float arg2 = (float)va_arg(args, double);
			return (arg1 == arg2);
		}
		case DOUBLE: {
			double arg1 = va_arg(args, double);
			double arg2 = va_arg(args, double);
			return (arg1 == arg2);
		}
		case LONG: {
			long arg1 = va_arg(args, long);
			long arg2 = va_arg(args, long);
			return (arg1 == arg2);
		}
		case LONGLONG: {
			long long arg1 = va_arg(args, long long);
			long long arg2 = va_arg(args, long long);
			return (arg1 == arg2);
		}
		case CHAR: {
			char arg1 = (char)va_arg(args, int);
			char arg2 = (char)va_arg(args, int);
			return (arg1 == arg2);
		}
		case STRING: {
			char* arg1 = va_arg(args, char*);
			char* arg2 = va_arg(args, char*);
			return MH_assert_strcmp(arg1, arg2);
		}
		case BOOL: {
			bool arg1 = va_arg(args, bool);
			bool arg2 = va_arg(args, bool);
			return (arg1 == arg2);
		}
		default: {
			ERROR("unkown type", UNKNOWN_TYPE);
			return false;
		}
	}
}

int MH_assert_strlen(char* s) {
	int len = 0;
	while(*s != '\0') {
		++len;
		++s;
	}
	return len;
}

bool MH_assert_strcmp(char* t1, char* t2) {
	if(!t1 && !t2) {
		return true;
	} else if((!t1 && t2) || (t1 && !t2)) {
		return false;
	}

	int len1 = MH_assert_strlen(t1);
	int len2 = MH_assert_strlen(t2);

	if(len1 != len2) {
		return false;
	}

	char* ptr1, *ptr2;
	for(ptr1 = t1, ptr2 = t2; ptr1 != t1 + len1; ++ptr1, ++ptr2) {
		if(*ptr1 != *ptr2) {
			return false;
		}
	}

	return true;
}
