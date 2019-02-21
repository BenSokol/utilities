/**
* @Filename: UTL_assert.h
* @Author:   Ben Sokol <Ben>
* @Email:    ben@bensokol.com
* @Created:  February 14th, 2019 [10:14pm]
* @Modified: February 21st, 2019 [3:10am]
* @Version:  1.0.0
*
* Copyright (C) 2019 by Ben Sokol. All Rights Reserved.
*/

#ifndef UTL_ASSERT_H
#define UTL_ASSERT_H

#ifndef __cplusplus
#include <stdnoreturn.h>
#endif

#if defined(NDEBUG)

#if defined(__cplusplus)
#if !defined(UTL_assert)
#define UTL_assert(x) static_cast<void>(x)
#endif
#if !defined(UTL_assert_continue)
#define UTL_assert_continue(x) static_cast<void>(x)
#endif
#if !defined(UTL_assert_always)
#define UTL_assert_always()
#endif
#else  // #if defined(__cplusplus)
#if !defined(UTL_assert)
#define UTL_assert(x) ((void)(x)))
#endif
#if !defined(UTL_assert_continue)
#define UTL_assert_continue(x) ((void)(x)))
#endif
#if !defined(UTL_assert_always)
#define UTL_assert_always()
#endif
#endif  // #if defined(__cplusplus)

#else  // #if defined(NDEBUG)

#if !defined(UTL_assert)
#define UTL_assert(x) UTL_assert_private((x), #x, __func__, __FILE__, __LINE__);
#endif

#if !defined(UTL_assert_continue)
#define UTL_assert_continue(x) UTL_assert_continue_private((x), #x, __func__, __FILE__, __LINE__);
#endif

#if !defined(UTL_assert_always)
#define UTL_assert_always() UTL_assert_always_private(__func__, __FILE__, __LINE__)
#endif

#endif  // #if defined(NDEBUG)


#if defined(__cplusplus)
extern "C" {
#endif

void UTL_assert_private(const int exp, const char *str, const char *func, const char *file, const int line);
void UTL_assert_continue_private(const int exp, const char *str, const char *func, const char *file, const int line);

#if defined(NDEBUG)
void UTL_assert_always_private(const char *func, const char *file, const int line);
#else
#if defined(__cplusplus)
[[noreturn]] void UTL_assert_always_private(const char *func, const char *file, const int line);
#else
noreturn void UTL_assert_always_private(const char *func, const char *file, const int line);
#endif  // #if defined(__cplusplus)
#endif  // #if defined(NDEBUG)

#if defined(__cplusplus)
}
#endif  // #if defined(__cplusplus)

#endif  // #ifndef UTL_ASSERT_HPP
