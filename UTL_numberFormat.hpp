/**
* @Filename: UTL_numberFormat.hpp
* @Author:   Ben Sokol <Ben>
* @Email:    ben@bensokol.com
* @Created:  March 29th, 2019 [2:19pm]
* @Modified: March 29th, 2019 [2:30pm]
* @Version:  1.0.0
*
* Copyright (C) 2019 by Ben Sokol. All Rights Reserved.
*/

#ifndef UTL_NUMBERFORMAT_HPP
#define UTL_NUMBERFORMAT_HPP

#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

namespace UTL {

  template <typename T>
  std::string formatNumberWithCommas(T num) {
    std::stringstream ss;
    ss.imbue(std::locale(""));
    ss << std::fixed << num;
    return ss.str();
  }

  template <typename T>
  std::string formatAsCurrency(T num) {
    std::stringstream ss;
    ss.imbue(std::locale(""));
    ss << "$";
    ss << std::setprecision(2);
    ss << std::fixed << num;
    return ss.str();
  }

}  // namespace UTL

#endif
