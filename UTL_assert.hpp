/**
* @Filename: UTL_assert.hpp
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  July 3rd, 2018 [9:09pm]
* @Modified: February 13th, 2019 [12:18pm]
* @Version:  1.1.0
*
* Copyright (C) 2018-2019 by Ben Sokol. All Rights Reserved.
*/

#ifndef UTL_ASSERT_HPP
#define UTL_ASSERT_HPP

#include <cassert>

#ifndef UTL_assert
#ifdef NDEBUG
#define UTL_assert(arg) static_cast<void>(arg)
#else
#define UTL_assert(arg) assert(arg)
#endif
#endif

#ifndef UTL_assert_always
#define UTL_assert_always() UTL_assert(false)
#endif

#endif  // #ifndef UTL_ASSERT_HPP
