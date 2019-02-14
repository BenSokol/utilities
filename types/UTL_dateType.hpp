/**
* @Filename: UTL_dateType.hpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  July 19th, 2018 [6:23pm]
* @Modified: February 13th, 2019 [1:09pm]
* @Version:  1.0.0
*
* Copyright (C) 2018-2019 by Ben Sokol. All Rights Reserved.
*/

#ifndef UTL_TYPES_DATETYPE_HPP
#define UTL_TYPES_DATETYPE_HPP

#include <cstdlib>

namespace UTL {
  typedef struct date_t {
    size_t year = 1970;
    size_t month = 1;
    size_t day = 1;
  } date_t;

}  // namespace UTL

#endif
