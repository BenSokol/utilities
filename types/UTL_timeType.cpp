/**
* @Filename: UTL_timeType.cpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  July 19th, 2018 [8:20pm]
* @Modified: February 19th, 2019 [12:40am]
* @Version:  1.0.0
*
* Copyright (C) 2018-2019 by Ben Sokol. All Rights Reserved.
*/


#include <chrono>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <map>
#include <sstream>
#include <string>
#include <typeinfo>

#include "UTL_assert.h"

#include "UTL_timeType.hpp"

namespace UTL {


  template <typename T>
  inline time_t<T>::time_t(TIME_ZONE tz) {
    UTL_assert(atoT.count(typeid(T).hash_code()) != 0);
    UTL_assert(tz < COUNT);

    T hours = 0;
    T minutes = 0;
    T seconds = 0;
    T microseconds = 0;

    if (tz != DEFAULT) {
      std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

      const char* strHours = new char[2];
      const char* strMinutes = new char[2];
      const char* strSeconds = new char[2];

      time_t rawtime = std::chrono::system_clock::to_time_t(now);

      if (tz == LOCAL) {
        strftime(const_cast<char*>(strHours), 2, "%H", localtime(&rawtime));
        strftime(const_cast<char*>(strMinutes), 2, "%M", localtime(&rawtime));
        strftime(const_cast<char*>(strSeconds), 2, "%S", localtime(&rawtime));
      }
      else if (tz == UTC) {
        strftime(const_cast<char*>(strHours), 2, "%H", gmtime(&rawtime));
        strftime(const_cast<char*>(strMinutes), 2, "%M", gmtime(&rawtime));
        strftime(const_cast<char*>(strSeconds), 2, "%S", gmtime(&rawtime));
      }
      else {
        UTL_assert_always();
      }

      hours = atoT[typeid(T).hash_code()](strHours);
      minutes = atoT[typeid(T).hash_code()](strMinutes);
      seconds = atoT[typeid(T).hash_code()](strSeconds);
      microseconds =
          std::chrono::duration_cast<std::chrono::microseconds>(
              now.time_since_epoch() - std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()))
              .count();

      delete[] strHours;
      delete[] strMinutes;
      delete[] strSeconds;
    }

    mHours = hours;
    mMinutes = minutes;
    mSeconds = seconds;
    mMicroseconds = microseconds;
  }

  template <typename T>
  inline time_t<T>::~time_t() {}

  template <typename T>
  inline T time_t<T>::getHours() const noexcept {
    return mHours;
  }

  template <typename T>
  inline T time_t<T>::getMinutes() const noexcept {
    return mMinutes;
  }

  template <typename T>
  inline T time_t<T>::getSeconds() const noexcept {
    return mSeconds;
  }

  template <typename T>
  inline T time_t<T>::getMicroseconds() const noexcept {
    return mMicroseconds;
  }

  template <typename T>
  inline void time_t<T>::setHours(T hours) noexcept {
    UTL_assert(hours < 24);
    mHours = hours;
  }

  template <typename T>
  inline void time_t<T>::setMinutes(T minutes) noexcept {
    UTL_assert(minutes < 60);
    mMinutes = minutes;
  }

  template <typename T>
  inline void time_t<T>::setSeconds(T seconds) noexcept {
    UTL_assert(seconds < 60);
    mSeconds = seconds;
  }

  template <typename T>
  inline void time_t<T>::setMicroseconds(T microseconds) noexcept {
    mMicroseconds = microseconds;
  }

  template <typename T>
  inline std::string time_t<T>::to_string(size_t microsecondsPrecision) const {
    UTL_assert(microsecondsPrecision <= 9);
    std::ostringstream ss;
    ss << std::setw(2) << std::setfill('0') << std::to_string(mHours) << ":";
    ss << std::setw(2) << std::setfill('0') << std::to_string(mMinutes) << ":";
    ss << std::setw(2) << std::setfill('0') << std::to_string(mSeconds);
    if (microsecondsPrecision > 0) {
      ss << ".";
      ss << std::setw(microsecondsPrecision) << std::setfill('0')
         << std::to_string(mMicroseconds).substr(0, microsecondsPrecision);
    }
    return ss.str();
  }

  // map of conversions from char* to T
  template <typename T>
  std::map<size_t, std::function<T(const char*)>> time_t<T>::atoT{
    /* Other types */
    std::make_pair(typeid(bool).hash_code(), [](const char* s) { return std::atoi(s); }),
    /* Char types */
    std::make_pair(typeid(char).hash_code(), [](const char* s) { return std::atoi(s); }),
    std::make_pair(typeid(signed char).hash_code(), [](const char* s) { return std::atoi(s); }),
    std::make_pair(typeid(unsigned char).hash_code(), [](const char* s) { return std::atoi(s); }),
    std::make_pair(typeid(char16_t).hash_code(), [](const char* s) { return std::strtoul(s, nullptr, 10); }),
    std::make_pair(typeid(char32_t).hash_code(), [](const char* s) { return std::strtoul(s, nullptr, 10); }),
    std::make_pair(typeid(wchar_t).hash_code(), [](const char* s) { return std::atoi(s); }),
    /* Signed integer types */
    std::make_pair(typeid(short int).hash_code(), [](const char* s) { return std::atoi(s); }),
    std::make_pair(typeid(int).hash_code(), [](const char* s) { return std::atoi(s); }),
    std::make_pair(typeid(long).hash_code(), [](const char* s) { return std::strtol(s, nullptr, 10); }),
    std::make_pair(typeid(long long).hash_code(), [](const char* s) { return std::strtoll(s, nullptr, 10); }),
    /* Unsigned integer types */
    std::make_pair(typeid(unsigned short int).hash_code(), [](const char* s) { return std::strtoul(s, nullptr, 10); }),
    std::make_pair(typeid(unsigned int).hash_code(), [](const char* s) { return std::strtoul(s, nullptr, 10); }),
    std::make_pair(typeid(unsigned long).hash_code(), [](const char* s) { return std::strtoul(s, nullptr, 10); }),
    std::make_pair(typeid(unsigned long long).hash_code(), [](const char* s) { return std::strtoul(s, nullptr, 10); }),
    /* Floating point types */
    std::make_pair(typeid(float).hash_code(), [](const char* s) { return std::strtof(s, nullptr); }),
    std::make_pair(typeid(double).hash_code(), [](const char* s) { return std::strtod(s, nullptr); }),
    std::make_pair(typeid(long double).hash_code(), [](const char* s) { return std::strtold(s, nullptr); })
  };

}  // namespace UTL
