// -*- mode:c++; indent-tabs-mode:nil; -*-

#include <algorithm>
#include <cstdio>
#include <map>
#include <string>

void
str_remove(std::string* str, std::string arg) {
  str->erase(
      std::remove_if(
          str->begin(), str->end(),
          [arg](char x) {
            return std::find(arg.begin(), arg.end(), x) != arg.end();
          }),
      str->end());
}

void
str_replace(std::string* str, std::string arg1, char arg2) {
  std::replace_if(
      str->begin(), str->end(),
      [arg1](char x) {
        return std::find(arg1.begin(), arg1.end(), x) != arg1.end();
      },
      arg2);
}
