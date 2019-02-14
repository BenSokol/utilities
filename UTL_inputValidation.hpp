/**
* @Filename: UTL_inputValidation.hpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  February 13th, 2019 [11:24am]
* @Modified: February 13th, 2019 [1:08pm]
* @Version:  1.0.0
*
* Copyright (C) 2019 by Ben Sokol. All Rights Reserved.
*/

#ifndef UTL_INPUTVALIDATION_HPP
#define UTL_INPUTVALIDATION_HPP

#include <cstdint>
#include <string>

namespace UTL {
  // num is the string to validate
  // min is the minimum valid number
  // max is the maximum valid number
  bool isNumber(const std::string &num, const intmax_t &min = INTMAX_MIN, const intmax_t &max = INTMAX_MAX);
}  // namespace UTL

#endif
