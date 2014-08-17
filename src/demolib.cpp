// -*- mode:c++; indent-tabs-mode:nil; -*-

#include "demolib.h"

#include <cstdio>

int const SEED_VALUE = 1234;

int getToken(int token)
{
  if (token < 10) {
    return 10;
  } else if (token < 20) {
    return 20;
  } else {
    return token;
  }
}
