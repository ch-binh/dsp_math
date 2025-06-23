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

/* Inlcludes ---------------------------------------------------------------- */
#include "Test_adv_math.h"

/* Test helpers ------------------------------------------------------------- */

void test_helper_int(test_comp_int_t *test_case, uint32_t num_tests)
{
  for (uint32_t i = 0; i < num_tests; ++i)
  {
    int32_t result = test_case[i].func(test_case[i].a, test_case[i].b);
    char    msg[128];
    snprintf(msg, sizeof(msg), "[%s][%d] %d op %d = %d, expected %d, delta: %d", test_case[i].label, i,
             test_case[i].a, test_case[i].b, result, test_case[i].expected, test_case[i].delta);

    TEST_ASSERT_INT32_WITHIN_MESSAGE(test_case[i].delta, test_case[i].expected, result, msg);
  }
}

void test_helper_float(test_comp_float_t *test_case, uint32_t num_tests)
{
  for (uint32_t i = 0; i < num_tests; ++i)
  {
    float32_t result = test_case[i].func(test_case[i].a, test_case[i].b);
    char      msg[128];
    snprintf(msg, sizeof(msg), "[%s][%d] %.5f op %.5f = %.5f, expected %.5f, delta %.5f", test_case[i].label,
             i, test_case[i].a, test_case[i].b, result, test_case[i].expected, test_case[i].delta);

    if (isnan(test_case[i].expected))
      TEST_ASSERT_TRUE_MESSAGE(isnan(result), msg);
    else
      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(test_case[i].delta, test_case[i].expected, result, msg);
  }
}

/* End of File -------------------------------------------------------------- */