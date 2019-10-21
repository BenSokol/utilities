/**
* @Filename: UTL_textWrap.hpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  February 14th, 2019 [8:11am]
* @Modified: October 21st, 2019 [4:33am]
* @Version:  1.0.0
*
* Copyright (C) 2019 by Ben Sokol. All Rights Reserved.
*/

#ifndef UTL_TEXTWRAP_HPP
#define UTL_TEXTWRAP_HPP

#include <cstdlib>

#include <string>

namespace UTL {
  std::string textWrap(std::string str,
                       const bool hasTab = false,
                       const size_t tabLength = 8,
                       const size_t numTabs = 1,
                       const size_t maxWidth = 0);
}

#endif
