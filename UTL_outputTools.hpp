/**
* @Filename: UTL_outputTools.hpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  February 14th, 2019 [8:11am]
* @Modified: February 14th, 2019 [9:32am]
* @Version:  1.0.0
*
* Copyright (C) 2019 by Ben Sokol. All Rights Reserved.
*/

#include <cstdlib>
#include <string>

namespace UTL {
  std::string textWrap(std::string str, const bool hasTab = false, const size_t tabLength = 8,
                       const size_t numTabs = 1);
}
