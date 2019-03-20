/**
* @Filename: UTL_colors.hpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  February 13th, 2019 [11:24am]
* @Modified: March 20th, 2019 [3:21am]
* @Version:  1.0.0
*
* Copyright (C) 2019 by Ben Sokol. All Rights Reserved.
*/

#ifndef UTL_COLORS_HPP
#define UTL_COLORS_HPP

#if !defined(__unix__) && !defined(__unix) && !defined(__linux__) && !defined(__APPLE__) && !defined(__MACH__)
#error Unknown Operating System
#endif

#include <iostream>

namespace UTL {

  class COLOR {
  public:
    typedef enum class CODES : uint8_t {
      // styles
      reset = 0,
      bold = 1,
      dim = 2,
      italic = 3,
      underline = 4,
      blink = 5,
      invert = 7,
      conceal = 8,
      hide = 8,
      hidden = 8,
      crossed = 9,

      // Foreground
      fg_black = 30,
      fg_red = 31,
      fg_green = 32,
      fg_yellow = 33,
      fg_blue = 34,
      fg_magenta = 35,
      fg_cyan = 36,
      fg_gray = 37,
      fg_reset = 39,

      // Background
      bg_black = 40,
      bg_red = 41,
      bg_green = 42,
      bg_yellow = 43,
      bg_blue = 44,
      bg_magenta = 45,
      bg_cyan = 46,
      bg_gray = 47,
      bg_reset = 49,

      // Foreground Bright
      fg_bright_black = 90,
      fg_bright_red = 91,
      fg_bright_green = 92,
      fg_bright_yellow = 93,
      fg_bright_blue = 94,
      fg_bright_magenta = 95,
      fg_bright_cyan = 96,
      fg_bright_gray = 97,
      fg_bright_reset = 39,

      // Background Bright
      bg_bright_black = 100,
      bg_bright_red = 101,
      bg_bright_green = 102,
      bg_bright_yellow = 103,
      bg_bright_blue = 104,
      bg_bright_magenta = 105,
      bg_bright_cyan = 106,
      bg_bright_gray = 107,
      bg_bright_reset = 49
    } CODE;

    typedef enum MODES : uint8_t {
      OFF = 0,     // Disable Color
      AUTO = 1,    // (Default) Enable Color if supported
      FORCE = 2,   // Enable Color always
      ON = FORCE,  // Enable Color always
    } MODE;

    friend std::ostream& operator<<(std::ostream& os, const CODE& value);
    static void setMode(const MODE value) noexcept;
    static MODE getMode() noexcept;
    static bool isColorEnabled(std::ostream& os = std::cout) noexcept;

    static constexpr CODE reset = CODES::reset;
    static constexpr CODE bold = CODES::bold;
    static constexpr CODE dim = CODES::dim;
    static constexpr CODE italic = CODES::italic;
    static constexpr CODE underline = CODES::underline;
    static constexpr CODE blink = CODES::blink;
    static constexpr CODE invert = CODES::invert;
    static constexpr CODE conceal = CODES::conceal;
    static constexpr CODE hide = CODES::hide;
    static constexpr CODE hidden = CODES::hidden;
    static constexpr CODE crossed = CODES::crossed;

    class FG {
    public:
      static constexpr CODE black = CODES::fg_black;
      static constexpr CODE red = CODES::fg_red;
      static constexpr CODE green = CODES::fg_green;
      static constexpr CODE yellow = CODES::fg_yellow;
      static constexpr CODE blue = CODES::fg_blue;
      static constexpr CODE magenta = CODES::fg_magenta;
      static constexpr CODE cyan = CODES::fg_cyan;
      static constexpr CODE gray = CODES::fg_gray;
      static constexpr CODE reset = CODES::fg_reset;

      class BRIGHT {
      public:
        static constexpr CODE black = CODES::fg_bright_black;
        static constexpr CODE red = CODES::fg_bright_red;
        static constexpr CODE green = CODES::fg_bright_green;
        static constexpr CODE yellow = CODES::fg_bright_yellow;
        static constexpr CODE blue = CODES::fg_bright_blue;
        static constexpr CODE magenta = CODES::fg_bright_magenta;
        static constexpr CODE cyan = CODES::fg_bright_cyan;
        static constexpr CODE gray = CODES::fg_bright_gray;
        static constexpr CODE reset = CODES::fg_bright_reset;
      };
    };

    class BG {
      static constexpr CODE black = CODES::bg_black;
      static constexpr CODE red = CODES::bg_red;
      static constexpr CODE green = CODES::bg_green;
      static constexpr CODE yellow = CODES::bg_yellow;
      static constexpr CODE blue = CODES::bg_blue;
      static constexpr CODE magenta = CODES::bg_magenta;
      static constexpr CODE cyan = CODES::bg_cyan;
      static constexpr CODE gray = CODES::bg_gray;
      static constexpr CODE reset = CODES::bg_reset;

      class BRIGHT {
        static constexpr CODE black = CODES::bg_bright_black;
        static constexpr CODE red = CODES::bg_bright_red;
        static constexpr CODE green = CODES::bg_bright_green;
        static constexpr CODE yellow = CODES::bg_bright_yellow;
        static constexpr CODE blue = CODES::bg_bright_blue;
        static constexpr CODE magenta = CODES::bg_bright_magenta;
        static constexpr CODE cyan = CODES::bg_bright_cyan;
        static constexpr CODE gray = CODES::bg_bright_gray;
        static constexpr CODE reset = CODES::bg_bright_reset;
      };
    };

  private:
    // Instances of this class cannot be declared
    COLOR() {}
  };

}  // namespace UTL


#endif  // #ifndef UTL_COLORS_HPP
