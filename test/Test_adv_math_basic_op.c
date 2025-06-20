/**
 *******************************************************************************
 * @file    Test_adv_math_basic_op.c
 * @brief   Test case for basic arithmetic operations in advanced math library.
 * @details
 *             -
 * @date    2025/05/19
 *
 * @author  Binh Pham
 *******************************************************************************
 */
/* Includes ----------------------------------------------------------------- */
#include "Test_adv_math.h"

/* Private defines ---------------------------------------------------------- */
/* Private typedefs --------------------------------------------------------- */

//* Test cases' inputs here =============================================== { */
// Add additional test cases to the table, don't adjust functions

// clang-format off


test_inputs_float_t cases_add_float[] = {
//TESTCASE                        |FLOAT A,    |FLOAT B,      |EXPECTED RESULT      |COMMENT
//------------------------------------------------------------------------------------------------------------
  TEST_CASE("epsilon_vs_zero",     FLT_EPSILON, 0.0f,           FLT_EPSILON),         ///< test sai nếu bị rounded
  TEST_CASE("min_add_min",         FLT_MIN,     FLT_MIN,        2.0f * FLT_MIN),      ///< dễ fail nếu mất precision
  TEST_CASE("max_plus",            FLT_MAX,     1e32f,          INFINITY),            ///< overflow detection
  TEST_CASE("inf_add",             INFINITY,    1000.0f,        INFINITY),            ///< propagate infinity
  TEST_CASE("nan_add",             NAN,         123.0f,         NAN),                 ///< propagate nan
  TEST_CASE("cancel_out",          1e20f,       -1e20f,         0.0f),                ///< catastrophic cancellation
  TEST_CASE("near_one",            1.0f,        FLT_EPSILON,    1.0f + FLT_EPSILON),  ///< detect ULP error
  TEST_CASE("precision_loss",      1e-3f,       1e-7f,          0.0010001f),          ///< loss of significance
  TEST_CASE("underflow",           1e-45f,      -1e-45f,        0.0f),                ///< denormal test (1 bit diff)
  TEST_CASE("associativity_fail",  1e30f,       -1e30f + 1.0f,  0.0f),                ///< floating point associative broken
};

/* Subtraction test cases */
test_inputs_float_t cases_sub_float[] = {
//TESTCASE                        |FLOAT A,    |FLOAT B,      |EXPECTED RESULT      |COMMENT
//------------------------------------------------------------------------------------------------------------
  TEST_CASE("basic",               10.0f,       3.0f,           7.0f),                ///< simple subtraction
  TEST_CASE("zero",                0.0f,        0.0f,           0.0f),                ///< zero minus zero
  TEST_CASE("negative_result",     5.0f,        10.0f,          -5.0f),               ///< negative result
  TEST_CASE("inf_minus",           INFINITY,    1.0f,           INFINITY),            ///< inf - x = inf
  TEST_CASE("minus_inf",           1.0f,        INFINITY,       -INFINITY),           ///< x - inf = -inf
  TEST_CASE("nan_minus",           NAN,         1.0f,           NAN),                 ///< nan - x = nan
  TEST_CASE("sub_nan",             1.0f,        NAN,            NAN),                 ///< x - nan = nan
  TEST_CASE("inf_minus_inf",       INFINITY,    INFINITY,       NAN),                 ///< undefined (inf - inf)
  TEST_CASE("near_cancel",         1.000001f,   1.000000f,      0.000001f),           ///< precision sensitive
  TEST_CASE("eps_sub",             1.0f,        FLT_EPSILON,    1.0f - FLT_EPSILON),  ///< subtract epsilon
  TEST_CASE("min_sub_min",         FLT_MIN,     FLT_MIN,        0.0f),                ///< min - min
  TEST_CASE("underflow",           1e-45f,      1e-45f,         0.0f),                ///< denormal underflow
  TEST_CASE("assoc_fail",          (1e30f + 1.0f) - 1e30f, 1.0f, -1.0f),              ///< breaks associativity
};

/* Multiplication test cases */
test_inputs_float_t cases_mul_float[] = {
//TESTCASE                        |FLOAT A,    |FLOAT B,      |EXPECTED RESULT      |COMMENT
//------------------------------------------------------------------------------------------------------------
  TEST_CASE("zero",                0.0f,        1234.5f,        0.0f),                ///< zero times anything
  TEST_CASE("negative",            -3.0f,       2.0f,           -6.0f),               ///< negative result
  TEST_CASE("inf",                 INFINITY,    2.0f,           INFINITY),            ///< inf * x = inf
  TEST_CASE("nan",                 NAN,         1.0f,           NAN),                 ///< nan * x = nan
  TEST_CASE("small",               FLT_MIN,     2.0f,           2.0f * FLT_MIN),      ///< small value
  TEST_CASE("large",               FLT_MAX/2.0f,2.0f,           FLT_MAX),             ///< large value
  TEST_CASE("overflow",            FLT_MAX,     2.0f,           INFINITY),            ///< overflow
  TEST_CASE("denorm",              1e-38f,      1e-10f,         0),                   ///< denormalized result
  TEST_CASE("epsilon",             1.0f,        FLT_EPSILON,    FLT_EPSILON),         ///< multiply by epsilon
};

/* Division test cases */
test_inputs_float_t cases_div_float[] = {
//TESTCASE                        |FLOAT A,    |FLOAT B,      |EXPECTED RESULT      |COMMENT
//------------------------------------------------------------------------------------------------------------
  TEST_CASE("basic",               10.0f,       2.0f,           5.0f),                ///< simple division
  TEST_CASE("div_by_zero",         1.0f,        0.0f,           INFINITY),            ///< divide by zero
  TEST_CASE("neg_div_by_zero",     -23.0f,      0.0f,           -INFINITY),           ///< negative divided by zero
  TEST_CASE("zero_div_zero",       0.0f,        0.0f,           NAN),                 ///< zero divided by zero
  TEST_CASE("inf_div",             INFINITY,    2.0f,           INFINITY),            ///< inf / x = inf
  TEST_CASE("div_inf",             2.0f,        INFINITY,       0.0f),                ///< x / inf = 0
  TEST_CASE("nan",                 NAN,         1.0f,           NAN),                 ///< nan / x = nan
  TEST_CASE("rounding",            1.0f,        3.0f,           1.0f / 3.0f),         ///< rounding test
  TEST_CASE("tiny",                FLT_MIN,     2.0f,           FLT_MIN / 2.0f),      ///< tiny / 2
  TEST_CASE("large",               FLT_MAX,     2.0f,           FLT_MAX / 2.0f),      ///< large / 2
};
// clang-format on
//* ======================================================================= } */

/* Test helpers ------------------------------------------------------------- */
_STATIC void test_helper_basic_op_float(test_inputs_float_t *test_case, uint32_t num_tests,
                                        float (*op)(float, float))
{
  for (uint32_t i = 0; i < num_tests; ++i)
  {
    float result = op(test_case[i].a, test_case[i].b);
    char  msg[128];
    snprintf(msg, sizeof(msg), "[%s][%d] %.9g op %.9g = %.9g, expected %.9g", test_case[i].label, i,
             test_case[i].a, test_case[i].b, result, test_case[i].expected);

    if (isnan(test_case[i].expected))
      TEST_ASSERT_TRUE_MESSAGE(isnan(result), msg);
    else
      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(FLT_EPSILON, test_case[i].expected, result, msg);
  }
}

/*
 * TEST CASES
 * =============================================================================
 */

TEST_GROUP(BASIC_OP);

TEST_SETUP(BASIC_OP)
{
  // intentionally left empty
}

TEST_TEAR_DOWN(BASIC_OP)
{
  // intentionally left empty
}

/*
 * ADDITION
 * =============================================================================
 */

TEST(BASIC_OP, add_float)
{
  test_helper_basic_op_float(cases_add_float, ARRAY_SIZE(cases_add_float), advm_add);
}

/*
 * SUBTRACTION
 * =============================================================================
 */

TEST(BASIC_OP, sub_float)
{
  test_helper_basic_op_float(cases_sub_float, ARRAY_SIZE(cases_sub_float), advm_sub);
}

/*
 * MULTIPLICATION
 * =============================================================================
 */

TEST(BASIC_OP, mul_float)
{
  test_helper_basic_op_float(cases_mul_float, ARRAY_SIZE(cases_mul_float), advm_mul);
}

/*
 * DIVISION
 * =============================================================================
 */

TEST(BASIC_OP, div_float)
{
  test_helper_basic_op_float(cases_div_float, ARRAY_SIZE(cases_div_float), advm_div);
}

/* End of File -------------------------------------------------------------- */