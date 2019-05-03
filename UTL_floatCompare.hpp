/**
* @Filename: UTL_floatCompare.hpp
* @Author:   Ben Sokol <Ben>
* @Email:    ben@bensokol.com
* @Created:  May 3rd, 2019 [5:30pm]
* @Modified: May 3rd, 2019 [5:38pm]
* @Version:  1.0.0
*
* Copyright (C) 2019 by Ben Sokol. All Rights Reserved.
*/

#ifndef UTL_FLOATCOMPARE_HPP
#define UTL_FLOATCOMPARE_HPP

#include <cmath>
#include <limits>

namespace UTL {
  namespace FLOAT {
    template <typename T>
    bool isequal(T a, T b) {
      return std::fabs(a - b) < std::numeric_limits<T>::epsilon();
    }

  }  // namespace FLOAT
}  // namespace UTL

#endif
