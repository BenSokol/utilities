/**
* @Filename: UTL_timeType.hpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  July 19th, 2018 [8:20pm]
* @Modified: February 18th, 2019 [2:11pm]
* @Version:  1.0.0
*
* Copyright (C) 2018-2019 by Ben Sokol. All Rights Reserved.
*/

#ifndef UTL_TYPES_TIMETYPE_HPP
#define UTL_TYPES_TIMETYPE_HPP

#include <cstdlib>
#include <functional>
#include <map>
#include <string>

namespace UTL {

  template <typename T = size_t>
  class time_t {
  public:
    typedef enum TIME_ZONE { LOCAL, UTC, DEFAULT, COUNT } TIME_ZONE;

    inline time_t(TIME_ZONE tz = DEFAULT);
    inline ~time_t();

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

}  // namespace UTL

#endif  // #ifndef UTL_TIME_HPP
