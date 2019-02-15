/**
* @Filename: UTL_assert.h
* @Author:   Ben Sokol
* @Email:    ben@bensokol.com
* @Created:  July 3rd, 2018 [9:09pm]
* @Modified: February 15th, 2019 [12:58pm]
* @Version:  1.1.0
*
* Copyright (C) 2018-2019 by Ben Sokol. All Rights Reserved.
*/

#ifndef UTL_ASSERT_H
#define UTL_ASSERT_H

#include <assert.h>

#ifndef UTL_assert
#ifdef NDEBUG
#ifdef __cplusplus
#define UTL_assert(arg) static_cast<void>(arg)
#else
#define UTL_assert(arg) (void)(arg)
#endif
#else
#define UTL_assert(arg) assert(arg)
#endif
#endif

#ifndef UTL_assert_always
#define UTL_assert_always() UTL_assert(false)
#endif

#endif  // #ifndef UTL_ASSERT_HPP
