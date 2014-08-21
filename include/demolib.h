// -*- mode:c++; indent-tabs-mode:nil; -*-

#ifndef DEMOLIB_H
#define DEMOLIB_H

#include <cstdlib>

int32_t getToken(int32_t seed);
char const* getMessage(int32_t token);
char const* getMessageQuoted(int32_t token);

#endif
