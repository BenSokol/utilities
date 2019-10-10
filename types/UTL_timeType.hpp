/**
* @Filename: UTL_timeType.hpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  July 19th, 2018 [8:20pm]
* @Modified: October 9th, 2019 [10:05pm]
* @Version:  1.0.0
*
* Copyright (C) 2018-2019 by Ben Sokol. All Rights Reserved.
*/

#ifndef UTL_TYPES_TIMETYPE_HPP
#define UTL_TYPES_TIMETYPE_HPP

#include <cstdlib>

#include <chrono>
#include <functional>
#include <iomanip>
#include <map>
#include <sstream>
#include <string>
#include <typeinfo>

#include "UTL_assert.h"

namespace UTL {

  template <typename T = size_t>
  class timeType {
  public:
    typedef enum TIME_ZONE { LOCAL, UTC, DEFAULT, COUNT } TIME_ZONE;

    explicit inline timeType(TIME_ZONE tz = DEFAULT,
                             std::chrono::system_clock::time_point time = std::chrono::system_clock::now());
    inline ~timeType();

    inline T getHours() const noexcept;
    inline T getMinutes() const noexcept;
    inline T getSeconds() const noexcept;
    inline T getMicroseconds() const noexcept;
    inline void setHours(T hours) noexcept;
    inline void setMinutes(T minutes) noexcept;
    inline void setSeconds(T seconds) noexcept;
    inline void setMicroseconds(T microseconds) noexcept;
    inline std::string to_string(size_t microsecondsPrecision = 6) const;

  private:
    static std::map<size_t, std::function<T(const char*)>> atoT;
    T mHours;
    T mMinutes;
    T mSeconds;
    T mMicroseconds;
  };


  template <typename T>
  inline timeType<T>::timeType(TIME_ZONE tz, std::chrono::system_clock::time_point time) {
    UTL_assert(atoT.count(typeid(T).hash_code()) != 0);
    UTL_assert(tz < COUNT);

    T hours = 0;
    T minutes = 0;
    T seconds = 0;
    T microseconds = 0;

    if (tz != DEFAULT) {
      char strHours[3];
      char strMinutes[3];
      char strSeconds[3];

      time_t rawtime = std::chrono::system_clock::to_time_t(time);

      if (tz == LOCAL) {
        strftime(strHours, 3, "%H", localtime(&rawtime));
        strftime(strMinutes, 3, "%M", localtime(&rawtime));
        strftime(strSeconds, 3, "%S", localtime(&rawtime));
      }
      else if (tz == UTC) {
        strftime(strHours, 3, "%H", gmtime(&rawtime));
        strftime(strMinutes, 3, "%M", gmtime(&rawtime));
        strftime(strSeconds, 3, "%S", gmtime(&rawtime));
      }
      else {
        UTL_assert_always();
      }

      hours = atoT[typeid(T).hash_code()](strHours);
      minutes = atoT[typeid(T).hash_code()](strMinutes);
      seconds = atoT[typeid(T).hash_code()](strSeconds);
      microseconds = static_cast<T>(
        std::chrono::duration_cast<std::chrono::microseconds>(
          time.time_since_epoch() - std::chrono::duration_cast<std::chrono::seconds>(time.time_since_epoch()))
          .count());
    }

    mHours = hours;
    mMinutes = minutes;
    mSeconds = seconds;
    mMicroseconds = microseconds;
  }

  template <typename T>
  inline timeType<T>::~timeType() {
  }

  template <typename T>
  inline T timeType<T>::getHours() const noexcept {
    return mHours;
  }

  template <typename T>
  inline T timeType<T>::getMinutes() const noexcept {
    return mMinutes;
  }

  template <typename T>
  inline T timeType<T>::getSeconds() const noexcept {
    return mSeconds;
  }

  template <typename T>
  inline T timeType<T>::getMicroseconds() const noexcept {
    return mMicroseconds;
  }

  template <typename T>
  inline void timeType<T>::setHours(T hours) noexcept {
    UTL_assert(hours < 24);
    mHours = hours;
  }

  template <typename T>
  inline void timeType<T>::setMinutes(T minutes) noexcept {
    UTL_assert(minutes < 60);
    mMinutes = minutes;
  }

  template <typename T>
  inline void timeType<T>::setSeconds(T seconds) noexcept {
    UTL_assert(seconds < 60);
    mSeconds = seconds;
  }

  template <typename T>
  inline void timeType<T>::setMicroseconds(T microseconds) noexcept {
    mMicroseconds = microseconds;
  }

  template <typename T>
  inline std::string timeType<T>::to_string(size_t microsecondsPrecision) const {
    UTL_assert(microsecondsPrecision <= 9);
    std::ostringstream ss;
    ss << std::setw(2) << std::setfill('0') << std::to_string(mHours) << ":";
    ss << std::setw(2) << std::setfill('0') << std::to_string(mMinutes) << ":";
    ss << std::setw(2) << std::setfill('0') << std::to_string(mSeconds);
    if (microsecondsPrecision > 0) {
      ss << ".";
      ss << std::setw(static_cast<int>(microsecondsPrecision)) << std::setfill('0')
         << std::to_string(mMicroseconds).substr(0, microsecondsPrecision);
    }
    return ss.str();
  }

  // map of conversions from char* to T
  template <typename T>
  std::map<size_t, std::function<T(const char*)>> timeType<T>::atoT {
    /* Other types */
    std::make_pair(typeid(bool).hash_code(),
                   [](const char* s) {
                     return std::stoi(s);
                   }),
    /* Char types */
    std::make_pair(typeid(char).hash_code(),
                   [](const char* s) {
                     return std::stoi(s);
                   }),
    std::make_pair(typeid(signed char).hash_code(),
                   [](const char* s) {
                     return std::stoi(s);
                   }),
    std::make_pair(typeid(unsigned char).hash_code(),
                   [](const char* s) {
                     return std::stoul(s);
                   }),
    std::make_pair(typeid(char16_t).hash_code(),
                   [](const char* s) {
                     return std::stoi(s);
                   }),
    std::make_pair(typeid(char32_t).hash_code(),
                   [](const char* s) {
                     return std::stoi(s);
                   }),
    std::make_pair(typeid(wchar_t).hash_code(),
                   [](const char* s) {
                     return std::stoi(s);
                   }),
    /* Signed integer types */
    std::make_pair(typeid(short int).hash_code(),
                   [](const char* s) {
                     return std::stoi(s);
                   }),
    std::make_pair(typeid(int).hash_code(),
                   [](const char* s) {
                     return std::stoi(s);
                   }),
    std::make_pair(typeid(long).hash_code(),
                   [](const char* s) {
                     return std::stol(s);
                   }),
    std::make_pair(typeid(long long).hash_code(),
                   [](const char* s) {
                     return std::strtoll(s, nullptr, 10);
                   }),
    /* Unsigned integer types */
    std::make_pair(typeid(unsigned short int).hash_code(),
                   [](const char* s) {
                     return std::stoul(s);
                   }),
    std::make_pair(typeid(unsigned int).hash_code(),
                   [](const char* s) {
                     return std::stoul(s);
                   }),
    std::make_pair(typeid(unsigned long).hash_code(),
                   [](const char* s) {
                     return std::stoul(s);
                   }),
    std::make_pair(typeid(unsigned long long).hash_code(),
                   [](const char* s) {
                     return std::strtoul(s, nullptr, 10);
                   }),
    /* Floating point types */
    std::make_pair(typeid(float).hash_code(),
                   [](const char* s) {
                     return std::strtof(s, nullptr);
                   }),
    std::make_pair(typeid(double).hash_code(),
                   [](const char* s) {
                     return std::strtod(s, nullptr);
                   }),
    std::make_pair(typeid(long double).hash_code(),
                   [](const char* s) {
                     return std::strtold(s, nullptr);
                   })
  };

}  // namespace UTL


#endif  // #ifndef UTL_TIME_HPP
