/**
* @Filename: UTL_textWrap.cpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  February 14th, 2019 [8:11am]
* @Modified: February 15th, 2019 [11:25am]
* @Version:  1.0.0
*
* Copyright (C) 2019 by Ben Sokol. All Rights Reserved.
*/


#include <cstdlib>
#include <string>

#ifdef __has_include
#if __has_include(<sys/ioctl.h>) && __has_include(<unistd.h>)
#include <sys/ioctl.h>  // Get terminal window size
#include <unistd.h>     // Get terminal window size
#endif
#endif

#include "UTL_assert.hpp"

#include "UTL_textWrap.hpp"

namespace UTL {
  std::string textWrap(std::string str, const bool hasTab, const size_t tabLength, const size_t numTabs) {
    // Get window_size
#ifdef TIOCGSIZE
    struct ttysize ts;
    ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
    size_t const window_size = static_cast<size_t>(ts.ts_cols);
#elif defined(TIOCGWINSZ)
    struct winsize ts;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
    size_t const window_size = static_cast<size_t>(ts.ws_col);
#else
    size_t const window_size = 80;
#endif

    size_t segmentLength = 0;

    // Process string, inserting newlines and/or tabs as necessary
    for (size_t i = 0; i < str.length(); ++i) {
      if (str[i] == '\n') {
        segmentLength = 0;
      }
      else if (str[i] == '\t') {
        segmentLength += tabLength;
      }
      else {
        if (segmentLength >= window_size) {
          // Find last space in segment
          size_t brk = str.find_last_of(' ', i);

          if (brk == std::string::npos) {
            // no spaces were found in rest of string. Will not split
            break;
          }

          // Verfiy that str[brk] == ' '
          UTL_assert(str[brk] == ' ');

          // Replace str[brk] with newline
          str[brk] = '\n';

          // if hasTab, insert tab.
          if (hasTab) {
            for (size_t j = 0; j < numTabs; ++j) {
              str.insert(brk + 1, "\t");
            }
          }

          segmentLength = (i - brk) + (hasTab ? (tabLength * numTabs) : 0);
        }
        else {
          segmentLength++;
        }
      }
    }

    return str;
  }
}  // namespace UTL
