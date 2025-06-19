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
/* Includes ----------------------------------------------------------------- */
#include "Test_adv_math.h"

/* Private defines ---------------------------------------------------------- */
/* Private typedefs --------------------------------------------------------- */

//* Test cases' inputs here =============================================== { */
test_inputs_int_t cases_add_int[] = {
  { TEST_GRP_TAG_POSITIVE, 40, 60, 101 },
  { TEST_GRP_TAG_NEGATIVE, -40, -60, -102 },
  { TEST_GRP_TAG_OPPOSITE_SIGNS, 80, -60, 20 },
  { TEST_GRP_TAG_EDGES, 0, -42, -42 },
};

#define TEST_GRP_
test_inputs_float_t cases_add_float[] = {
  { "epsilon_vs_zero", FLT_EPSILON, 0.0f, FLT_EPSILON }, // test sai nếu bị rounded
  { "min_add_min", FLT_MIN, FLT_MIN, 2.0f * FLT_MIN },   // dễ fail nếu mất precision
  { "max_plus", FLT_MAX, 1e10f, INFINITY },              // overflow detection
  { "inf_add", INFINITY, 1000.0f, INFINITY },            // propagate infinity
  { "nan_add", NAN, 123.0f, NAN },                       // propagate nan
  { "cancel_out", 1e20f, -1e20f, 0.0f },                 // catastrophic cancellation
  { "near_one", 1.0f, FLT_EPSILON, 1.0f + FLT_EPSILON }, // detect ULP error
  { "precision_loss", 1e-3f, 1e-7f, 0.0010001f },        // loss of significance
  { "underflow", 1e-45f, -1e-45f, 0.0f },                // denormal test (1 bit diff)
  { "associativity_fail", 1e30f, -1e30f + 1.0f, 1.0f },  // floating point associative broken
};

//* ======================================================================= } */

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

TEST(BASIC_OP, add_integers)
{

  for (size_t i = 0; i < ARRAY_SIZE(cases_add_int); ++i)
  {
    int  result = advm_add(cases_add_int[i].a, cases_add_int[i].b);
    char msg[128];
    snprintf(msg, sizeof(msg), "[%s][%zu] Failed: %d + %d != %d", cases_add_int[i].label, i,
             cases_add_int[i].a, cases_add_int[i].b, cases_add_int[i].expected);
    TEST_ASSERT_EQUAL_INT_MESSAGE(cases_add_int[i].expected, result, msg);
  }
}

TEST(BASIC_OP, add_float)
{
  for (size_t i = 0; i < ARRAY_SIZE(cases_add_float); ++i)
  {
    float result = advm_add(cases_add_float[i].a, cases_add_float[i].b);
    char  msg[128];
    snprintf(msg, sizeof(msg), "[%s][%zu] %.9g + %.9g = %.9g, expected %.9g", cases_add_float[i].label, i,
             cases_add_float[i].a, cases_add_float[i].b, result, cases_add_float[i].expected);

    if (isnan(cases_add_float[i].expected))
      TEST_ASSERT_TRUE_MESSAGE(isnan(result), msg);
    else if (isinf(cases_add_float[i].expected))
      TEST_ASSERT_EQUAL_FLOAT_MESSAGE(cases_add_float[i].expected, result, msg);
    else
      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(FLT_EPSILON, cases_add_float[i].expected, result, msg);
  }
}

/*
 * SUBTRACTION
 * =============================================================================
 */

/*
 * MULTIPLICATION
 * =============================================================================
 */

/*
 * DIVISION
 * =============================================================================
 */

/* End of File -------------------------------------------------------------- */