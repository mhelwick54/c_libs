#ifndef C_STRING_H
#define C_STRING_H

#include <stdlib.h>

#include "error.h"
#include "c_bool.h"

void 	MH_memCheck(char* ptr);
bool 	MH_boundCheck(char* s, int index);
int		MH_strlen(char* s);
char 	MH_at(char* s, int index);
char 	MH_back(char* s);
char 	MH_front(char* s);
void 	MH_append(char** s, char* str);
void 	MH_pushBack(char** s, char c);
char 	MH_popBack(char** s);
bool 	MH_insertString(char** s, char* str, int index);
bool 	MH_insertChar(char** s, char c, int index);
bool 	MH_replaceString(char** s, char* str, int start);
bool 	MH_replaceChar(char** s, char c, int index);
bool 	MH_substr(char* s, char** sub, int start, int end);
void 	MH_erase(char** s);
bool 	MH_eraseString(char** s, int start, int end);
bool 	MH_eraseChar(char** s, int index);
void 	MH_stringCopy(char** s, char* str);
bool 	MH_deleteString(char** s);

#endif //C_STRING_H
