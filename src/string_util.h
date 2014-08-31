// -*- mode:c++; indent-tabs-mode:nil; -*-

#include <algorithm>
#include <cstdio>
#include <map>
#include <string>


#include <cstring>

void
str_tolower(std::string* str) {
  std::transform(str->begin(), str->end(), str->begin(), ::tolower);
}

void
str_remove(std::string* str, std::string const& arg) {
  str->erase(
      std::remove_if(
          str->begin(), str->end(),
          [arg](char x) {
            return std::find(arg.begin(), arg.end(), x) != arg.end();
          }),
      str->end());
}

void
str_replace(std::string* str, std::string const& arg1, char arg2) {
  std::replace_if(
      str->begin(), str->end(),
      [arg1](char x) {
        return std::find(arg1.begin(), arg1.end(), x) != arg1.end();
      },
      arg2);
}

char*
str_alloc(std::string const& arg) {
  auto cstr = new char[arg.length() + 1];
  memcpy(cstr, arg.c_str(), arg.length());
  cstr[arg.length()] = '\0';
  return cstr;
}
