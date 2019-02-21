/**
* @Filename: UTL_assert.c
* @Author:   Ben Sokol <Ben>
* @Email:    ben@bensokol.com
* @Created:  February 16th, 2019 [7:50pm]
* @Modified: February 21st, 2019 [3:07am]
* @Version:  1.0.0
*
* Copyright (C) 2019 by Ben Sokol. All Rights Reserved.
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

#include "UTL_assert.h"

#if defined(NDEBUG)

void UTL_assert_private(__attribute__((unused)) const int exp, __attribute__((unused)) const char *str,
                        __attribute__((unused)) const char *func, __attribute__((unused)) const char *file,
                        __attribute__((unused)) const int line) {}
void UTL_assert_continue_private(__attribute__((unused)) const int exp, __attribute__((unused)) const char *str,
                                 __attribute__((unused)) const char *func, __attribute__((unused)) const char *file,
                                 __attribute__((unused)) const int line) {}
void UTL_assert_always_private(__attribute__((unused)) const char *func, __attribute__((unused)) const char *file,
                               __attribute__((unused)) const int line) {}

#else  // #if defined(NDEBUG)

void UTL_assert_private(const int exp, const char *str, const char *func, const char *file, const int line) {
  if (0 == exp) {
    fprintf(stderr, "Assertion failed: (%s), function %s, file %s, line %d.\n", str, func, file, line);
    exit(SIGABRT);
  }
}

void UTL_assert_continue_private(const int exp, const char *str, const char *func, const char *file, const int line) {
  if (0 == exp) {
    fprintf(stderr, "Assertion failed: (%s), function %s, file %s, line %d.\n", str, func, file, line);
  }
}

noreturn void UTL_assert_always_private(const char *func, const char *file, const int line) {
  fprintf(stderr, "Assertion failed: function %s, file %s, line %d.\n", func, file, line);
  exit(SIGABRT);
}

#endif  // #if defined(NDEBUG)
