/**
* @Filename: UTL_inputValidation.hpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  February 13th, 2019 [11:24am]
* @Modified: February 22nd, 2019 [5:01pm]
* @Version:  1.0.0
*
* Copyright (C) 2019 by Ben Sokol. All Rights Reserved.
*/

#ifndef UTL_INPUTVALIDATION_HPP
#define UTL_INPUTVALIDATION_HPP

#include <limits>
#include <string>

namespace UTL {
  // num is the string to validate
  // min is the minimum valid number
  // max is the maximum valid number
  bool isNumber(const std::string &num, const intmax_t &min = std::numeric_limits<intmax_t>::min(),
                const intmax_t &max = std::numeric_limits<intmax_t>::max());
}  // namespace UTL

#endif
