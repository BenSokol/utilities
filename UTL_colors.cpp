/**
* @Filename: UTL_colors.cpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  February 13th, 2019 [11:24am]
* @Modified: October 2nd, 2019 [9:49pm]
* @Version:  1.0.0
*
* Copyright (C) 2019 by Ben Sokol. All Rights Reserved.
*/

#if defined(__unix__) || defined(__unix) || defined(__linux__) || defined(__APPLE__) || defined(__MACH__)
#else
  #error This operating system is NOT supported.
#endif

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <array>
#include <atomic>
#include <iostream>
#include <string>

#include <unistd.h>

#include "UTL_colors.hpp"

namespace UTL {

  const char *COLOR::availableTerms[] = { "ansi",  "color", "console", "gnome", "konsole", "kterm",
                                          "linux", "rxvt",  "screen",  "vt100", "vt102",   "xterm" };

  static std::atomic<UTL::COLOR::MODE> COLOR_MODE(UTL::COLOR::AUTO);

  bool COLOR::isColorEnabled(std::ostream &os) noexcept {
    if (COLOR_MODE == MODES::AUTO) {
      const char *currentTerm = std::getenv("TERM");

      if (((os.rdbuf() == std::cout.rdbuf() && isatty(fileno(stdout)) != 0)
           || ((os.rdbuf() == std::cerr.rdbuf() || os.rdbuf() == std::clog.rdbuf()) && isatty(fileno(stderr)) != 0))
          && (currentTerm != nullptr
              && std::any_of(std::begin(availableTerms), std::end(availableTerms), [currentTerm](std::string str) {
                   return std::string(currentTerm).find(str) != std::string::npos;
                 }))) {
        return true;
      }
    }
    else if (COLOR_MODE == MODE::FORCE) {
      return true;
    }
    return false;
  }

  std::ostream &operator<<(std::ostream &os, const UTL::COLOR::CODE &value) {
    if (UTL::COLOR::isColorEnabled(os)) {
      os << ("\033[" + std::to_string(static_cast<uint8_t>(value)) + "m");
    }
    return os;
  }

  std::string COLOR::getColorCode(const UTL::COLOR::CODE &value) {
    return "\033[" + std::to_string(static_cast<uint8_t>(value)) + "m";
  }

  void COLOR::setMode(const MODE value) noexcept {
    COLOR_MODE = value;
  }

  UTL::COLOR::MODE COLOR::getMode() noexcept {
    return COLOR_MODE;
  }

}  // namespace UTL
