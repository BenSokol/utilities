/**
* @Filename: UTL_inputValidation.cpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  February 13th, 2019 [11:28am]
* @Modified: March 29th, 2019 [10:58pm]
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
    bool foundDecimalPoint = false;
    for (char chr : num) {
      if (num[0] == '-') {
        continue;
      }
      if (!foundDecimalPoint && chr == '.') {
        foundDecimalPoint = true;
        continue;
      }
      if (!isdigit(chr)) {
        return false;
      }
    }
    try {
      if (foundDecimalPoint) {
        double temp = std::stod(num);
        if (temp >= min && temp <= max) {
          return true;
        }
      }
      else {
        int temp = std::stoi(num);
        if (temp >= min && temp <= max) {
          return true;
        }
      }
    } catch (const std::exception &) {
      return false;
    }
    return false;
  }
}  // namespace UTL
