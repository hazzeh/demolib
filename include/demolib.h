// -*- mode:c++; indent-tabs-mode:nil; -*-

#ifndef DEMOLIB_H
#define DEMOLIB_H

#include <cstdlib>

extern int const SEED_VALUE;

int32_t getToken(int32_t seed);
char const* getMessage(int32_t token);

#endif
