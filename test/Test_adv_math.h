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
#include "unity.h"
#include "unity_fixture.h"
#include "adv_math.h"

/* Public defines ----------------------------------------------------------- */

/* Test group tag */
#define TEST_GRP_TAG_POSITIVE       "positive"
#define TEST_GRP_TAG_NEGATIVE       "negative"
#define TEST_GRP_TAG_OPPOSITE_SIGNS "opposite_signs"
#define TEST_GRP_TAG_EDGES          "edges"
// 2. Mathematical Properties

/* Macros */
#define TEST_CASE(label, func, a, b, expect, delta) { label, func, a, b, expect, delta }

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* Public typedefs ---------------------------------------------------------- */

typedef struct
{
  const char   *label;
  op_func_int32_t func;
  int32_t       a;
  int32_t       b;
  int32_t       expected;
  int32_t       delta;
} test_comp_int_t;

typedef struct
{
  const char     *label;
  op_func_float32_t func;
  float_t         a;
  float_t         b;
  float_t         expected;
  float_t         delta;
} test_comp_float_t;

typedef struct
{
  const char                  *label;
  op_func_pair_transform_int_t func;
  int32_t                      a;
  int32_t                      b;
  int32_t                      expected_a;
  int32_t                      expected_b;
  int32_t                      delta;
} test_pair_transform_case_int_t;

/* Function prototypes ------------------------------------------------------ */

void test_helper_int(test_comp_int_t *test_case, uint32_t num_tests);
void test_helper_float(test_comp_float_t *test_case, uint32_t num_tests);

void test_helper_pair_transform_int(test_pair_transform_case_int_t *test_case, uint32_t num_tests);

#endif /* TEST_ADV_MATH_H */

/* End of File -------------------------------------------------------------- */
