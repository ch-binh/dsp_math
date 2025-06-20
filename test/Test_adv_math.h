/**
 *******************************************************************************
 * @file    test_4.c
 * @brief   test case 4: Reading
 * @details
 *             -
 * @date    2025/05/19
 *
 * @author  Binh Pham
 *******************************************************************************
 */
/* Prevent recursion -------------------------------------------------------- */
#ifndef TEST_ADV_MATH_H
#define TEST_ADV_MATH_H

/* Includes ----------------------------------------------------------------- */
#include "adv_math.h"
#include "unity.h"
#include "unity_fixture.h"

/* Public defines ----------------------------------------------------------- */

/* Test group tag */
#define TEST_GRP_TAG_POSITIVE       "positive"
#define TEST_GRP_TAG_NEGATIVE       "negative"
#define TEST_GRP_TAG_OPPOSITE_SIGNS "opposite_signs"
#define TEST_GRP_TAG_EDGES          "edges"
// 2. Mathematical Properties

/* Macros */
#define TEST_CASE(label, a, b, expect) { label, a, b, expect }

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* Public typedefs ---------------------------------------------------------- */
typedef struct
{
  const char *label;
  int         a;
  int         b;
  int         expected;
} test_inputs_int_t;

typedef struct
{
  const char *label;
  float       a;
  float       b;
  float       expected;
} test_inputs_float_t;

/* Function prototypes ------------------------------------------------------ */

#endif /* TEST_ADV_MATH_H */

/* End of File -------------------------------------------------------------- */