// -*- mode:c++; indent-tabs-mode:nil; -*-

#include "demolib.h"

#include "string_util.h"

namespace {

std::map<int32_t, std::string> msgs = {
  { 10, "Do. Or do not. There is no try"    },
  { 20, "Judge me by my size, do you!?"     },
  { 30, "Fear is the path to the dark side" },
  { 40, "Wars not make one great"           },
  { 99, "That is why you fail"              }
};

}

int32_t
getToken(int32_t seed) {
  if (seed < 10) {
    return 10;
  } else if (seed < 20) {
    return 20;
  } else if (seed > 50) {
    return 50;
  } else {
    return seed;
  }
}

char const*
getMessage(int32_t token) {
  switch (token) {
    case 10:
    case 20:
    case 30:
    case 40:
      return msgs[token].c_str();
      break;
    default:
      return msgs.rbegin()->second.c_str();
  }
}

char const*
getMessageQuoted(int32_t token) {
  std::string msg = getMessage(token);
  str_remove(&msg, ",.");
  str_replace(&msg, " ", '_');
  str_tolower(&msg);
  return msg.c_str();
}
