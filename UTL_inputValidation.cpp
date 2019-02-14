/**
* @Filename: UTL_inputValidation.cpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  February 13th, 2019 [11:28am]
* @Modified: February 14th, 2019 [5:48pm]
* @Version:  1.0.0
*
* Copyright (C) 2019 by Ben Sokol. All Rights Reserved.
*/

#include <cctype>
#include <exception>
#include <string>

#include "UTL_inputValidation.hpp"

namespace UTL {

  bool isNumber(const std::string &num, const intmax_t &min, const intmax_t &max) {
    if (num.length() < 1) {
      return false;
    }
    for (char chr : num) {
      if (num[0] == '-') {
        continue;
      }
      if (!isdigit(chr)) {
        return false;
      }
    }
    try {
      int temp = std::stoi(num);
      if (temp >= min && temp <= max) {
        return true;
      }
    } catch (const std::exception &) {
      return false;
    }
    return false;
  }
}  // namespace UTL
