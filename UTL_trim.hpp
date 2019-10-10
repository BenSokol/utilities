/**
* @Filename: UTL_trim.hpp
* @Author:   Ben Sokol <Ben>
* @Email:    ben@bensokol.com
* @Created:  October 9th, 2019 [7:06pm]
* @Modified: October 9th, 2019 [7:15pm]
* @Version:  1.0.0
*
* Copyright (C) 2019 by Ben Sokol. All Rights Reserved.
*/

#include <algorithm>
#include <locale>
#include <string>

namespace UTL {
  // trim from start (in place)
  static inline void ltrim_inplace(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
              return !std::isspace(ch);
            }));
  }

  // trim from end (in place)
  static inline void rtrim_inplace(std::string &s) {
    s.erase(std::find_if(s.rbegin(),
                         s.rend(),
                         [](int ch) {
                           return !std::isspace(ch);
                         })
              .base(),
            s.end());
  }

  // trim from both ends (in place)
  static inline void trim_inplace(std::string &s) {
    ltrim_inplace(s);
    rtrim_inplace(s);
  }

  // trim from start (copying)
  static inline std::string ltrim(std::string s) {
    ltrim_inplace(s);
    return s;
  }

  // trim from end (copying)
  static inline std::string rtrim(std::string s) {
    rtrim_inplace(s);
    return s;
  }

  // trim from both ends (copying)
  static inline std::string trim(std::string s) {
    trim_inplace(s);
    return s;
  }
}  // namespace UTL
