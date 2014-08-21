// -*- mode:c++; indent-tabs-mode:nil; -*-

#include "demolib.h"

#include <cstdio>

int32_t const SEED_VALUE = 32;

int32_t
getToken(int32_t seed) {
  if (seed < 10) {
    return 10;
  } else if (seed < 20) {
    return 20;
  } else {
    return seed;
  }
}

char const*
getMessage(int32_t token) {
  switch (token) {
    case 10:
      return "token10";
      break;
    case 20:
      return "token20";
      break;
    case 30:
      return "token30";
      break;
    case 40:
      return "token40";
      break;
    default:
      return "undefined";
  }
}
