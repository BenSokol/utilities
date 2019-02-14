/**
* @Filename: UTL_colors.hpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  February 13th, 2019 [11:24am]
* @Modified: February 13th, 2019 [1:09pm]
* @Version:  1.0.0
*
* Copyright (C) 2019 by Ben Sokol. All Rights Reserved.
*/

#ifndef UTL_COLORS_HPP
#define UTL_COLORS_HPP

namespace UTL {
  static const char COLOR_RESET[] = "\033[0m";
  static const char COLOR_BOLD[] = "\033[1m";
  static const char COLOR_RED_BOLD[] = "\033[1;91m";
  static const char COLOR_GREEN_BOLD[] = "\033[1;92m";
  static const char COLOR_YELLOW_BOLD[] = "\033[1;93m";
  static const char COLOR_BLUE_BOLD[] = "\033[1;94m";
  static const char COLOR_PURPLE_BOLD[] = "\033[1;95m";
  static const char COLOR_CYAN_BOLD[] = "\033[1;96m";
  static const char COLOR_GRAY_BOLD[] = "\033[1;97m";
  static const char COLOR_RED[] = "\033[91m";
  static const char COLOR_GREEN[] = "\033[92m";
  static const char COLOR_YELLOW[] = "\033[93m";
  static const char COLOR_BLUE[] = "\033[94m";
  static const char COLOR_PURPLE[] = "\033[95m";
  static const char COLOR_CYAN[] = "\033[96m";
  static const char COLOR_GRAY[] = "\033[97m";
}  // namespace UTL

#endif
