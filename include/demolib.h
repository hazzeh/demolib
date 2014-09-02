// -*- mode:c++; indent-tabs-mode:nil; -*-

#ifndef DEMOLIB_H
#define DEMOLIB_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int32_t getToken(int32_t seed);
char const* getMessage(int32_t token);
char const* getMessageQuoted(int32_t token);
char const* getVersion();

#ifdef __cplusplus
}
#endif

#endif
