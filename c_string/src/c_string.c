#include "c_string.h"

void MH_memCheck(char* ptr) {
	if(!ptr) {
		ERROR("memory allocation failed", MALLOC);
	}
}

bool MH_boundCheck(char* s, int index) {
	if(index > MH_strlen(s) || index < 0) {
		return false;
	}
	return true;
}

int	MH_strlen(char* s) {
	int len = 0;
	while(*s != '\0') {
		++s;
		++len;
	}
	return len;
}

char MH_at(char* s, int index) {
	MH_memCheck(s);
	if(!MH_boundCheck(s, index)) {
		return 0;
	}

	return s[index];
}

char MH_back(char* s) {
	MH_memCheck(s);

	return s[MH_strlen(s) - 1];
}

char MH_front(char* s) {
	MH_memCheck(s);

	return s[0];
}

void MH_append(char** s, char* str) {
	MH_memCheck(*s);
	MH_memCheck(str);

	*s = realloc(*s, (MH_strlen(*s) + MH_strlen(str) + 1) * sizeof(char));
	MH_memCheck(*s);

	int i = MH_strlen(*s);
	while(*str != '\0') {
		*(*s + i) = *str;
		++str;
		++i;
	}
	*(*s + i) = '\0';
}

void MH_pushBack(char** s, char c) {
	MH_memCheck(*s);

	int len = MH_strlen(*s);

	*s = realloc(*s, (len + 2) * sizeof(char));
	MH_memCheck(*s);

	*(*s + len) = c;
	*(*s + len + 1) = '\0';
}

char MH_popBack(char** s) {
	MH_memCheck(*s);

	int len = MH_strlen(*s);

	char c = (*s)[len - 1];

	*s = realloc(*s, len * sizeof(char));
	(*s)[len - 1] = '\0';

	return c;
}

bool MH_insertString(char** s, char* str, int index) {
	MH_memCheck(*s);
	MH_memCheck(str);
	if(!MH_boundCheck(*s, index)) {
		return false;
	}

	int old_len = MH_strlen(*s);
	int new_len = old_len + MH_strlen(str) + 1;

	*s = realloc(*s, (new_len) * sizeof(char));
	MH_memCheck(*s);

	int i = new_len - 2;
	int j = old_len - 1;
	while(j >= index) {
		*(*s + i) = *(*s + j);
		--i;
		--j;
	}

	++j;
	while(*str != '\0') {
		*(*s + j) = *str;
		++j;
		++str;
	}
	*(*s + new_len - 1) = '\0';

	return true;
}

bool MH_insertChar(char** s, char c, int index) {
	MH_memCheck(*s);
	if(!MH_boundCheck(*s, index)) {
		return false;
	}

	int old_len = MH_strlen(*s);

	*s = realloc(*s, (old_len + 2) * sizeof(char));
	MH_memCheck(*s);

	int i = old_len;
	while(i >= index) {
		*(*s + i) = *(*s + (i - 1));
		--i;
	}

	++i;
	*(*s + i) = c;
	*(*s + old_len + 1) = '\0';

	return true;
}

bool MH_replaceString(char** s, char* str, int index) {
	MH_memCheck(*s);
	MH_memCheck(str);
	if(!MH_boundCheck(*s, index)) {
		return false;
	}

	if(index + MH_strlen(str) > MH_strlen(*s)) {
		return false;
	}

	int i = index;
	while(*str != '\0') {
		*(*s + i) = *str;
		++i;
		++str;
	}
	return true;
}

bool MH_replaceChar(char** s, char c, int index) {
	MH_memCheck(*s);
	if(!MH_boundCheck(*s, index)) {
		return false;
	}

	*(*s + index) = c;
	return true;
}

bool MH_substr(char* s, char** sub, int start, int end) {
	MH_memCheck(s);
	MH_memCheck(*sub);
	if(!MH_boundCheck(s, start) || !MH_boundCheck(s, end)) {
		return false;
	}

	*sub = realloc(*sub, (end - start + 1) * sizeof(char));
	MH_memCheck(*sub);

	int i = 0;
	while(start <= end) {
		*(*sub + i) = *(s + start);
		++i;
		++start;
	}
	return true;
}

void MH_erase(char** s) {
	MH_memCheck(*s);

	char* ptr = *s;
	while(*ptr != '\0') {
		*ptr = '\0';
		++ptr;
	}
}

bool MH_eraseString(char** s, int start, int end) {
	MH_memCheck(*s);
	if(!MH_boundCheck(*s, start) || !MH_boundCheck(*s, end)) {
		return false;
	}

	int old_len = MH_strlen(*s);

	char* endPtr = *s + end + 1;
	char* startPtr = *s + start;
	while(*endPtr != '\0') {
		*startPtr = *endPtr;
		++startPtr;
		++endPtr;
	}
	*s = realloc(*s, (old_len - (end - start) - 1) * sizeof(char));
	MH_memCheck(*s);
	*(*s + old_len - (end - start) - 1) = '\0';
	return true;
}

bool MH_eraseChar(char** s, int index) {
	MH_memCheck(*s);
	if(!MH_boundCheck(*s, index)) {
		return false;
	}

	int old_len = MH_strlen(*s);

	char* endPtr = *s + index + 1;
	char* startPtr = *s + index;
	while(*endPtr != '\0') {
		*startPtr = *endPtr;
		++startPtr;
		++endPtr;
	}
	*s = realloc(*s, old_len * sizeof(char));
	*(*s + old_len - 1) = '\0';
	return true;
}

void MH_stringCopy(char** s, char* str) {
	MH_memCheck(*s);
	MH_memCheck(str);

	*s = realloc(*s, (MH_strlen(str) + 1) * sizeof(char));
	MH_memCheck(*s);

	char* ptr = *s;
	while(*str != '\0') {
		*ptr = *str;
		++ptr;
		++str;
	}
	*ptr = '\0';
}

bool MH_deleteString(char** s) {
	MH_memCheck(*s);

	MH_erase(s);
	free(*s);
	return true;
}
