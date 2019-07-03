#ifndef ASSERT_H
#define ASSERT_H

#include <stdarg.h>

#include "c_bool.h"
#include "c_types.h"
#include "error.h"

bool MH_assert(types type, ...);
int MH_assert_strlen(char* s);
bool MH_assert_strcmp(char* t1, char* t2);

#endif //ASSERT_H
