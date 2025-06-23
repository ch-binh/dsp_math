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
#include "advm_num_theo.h"

/* Private defines ---------------------------------------------------------- */
// clang-format off
#define _TEST_CASE_ALL_ALGOS(label, a, b, expected, delta)                         \
  TEST_CASE(label " - euclid",         advm_gcd_iter_euclid,    a, b, expected, delta), \
  TEST_CASE(label " - recursion",      advm_gcd_recursion,      a, b, expected, delta), \
  TEST_CASE(label " - binary",         advm_gcd_binary,         a, b, expected, delta), \
  TEST_CASE(label " - stein",          advm_gcd_stein,          a, b, expected, delta), \
  TEST_CASE(label " - stein_naive",    advm_gcd_stein_naive,    a, b, expected, delta)
// clang-format on

/* Private typedefs --------------------------------------------------------- */
/* Private function prototypes ---------------------------------------------- */

//* Test cases' inputs here =============================================== { */
// Add additional test cases to the table, no nedd to adjust functions

// clang-format off
test_comp_int_t cases_gcd[] = {
  // TESTCASE                        | A             | B           |  EXPECTED         | DELTA    | COMMENT
  //-------------------------------------------------------------------------------
  _TEST_CASE_ALL_ALGOS("zero-zero",           0,           0,   GCD_NO_AVAILABLE,      0),      // Both zero
  _TEST_CASE_ALL_ALGOS("zero-left",           0,      123456,             123456,      0),      // Left zero
  _TEST_CASE_ALL_ALGOS("zero-right",     123456,           0,             123456,      0),      // Right zero
  _TEST_CASE_ALL_ALGOS("reverse",            25,         100,                 25,      0),      // GCD(25,100)
  _TEST_CASE_ALL_ALGOS("large",      UINT32_MAX,       65536,                  1,      0),      // Large numbers
  _TEST_CASE_ALL_ALGOS("prime-diff", 1000000000,   999999937,                  1,      0),      // Large primes
  _TEST_CASE_ALL_ALGOS("same",                2,           2,                  2,      0),      // Same numbers
  _TEST_CASE_ALL_ALGOS("complex",        987654,      123456,                  6,      0),      // Arbitrary values
  _TEST_CASE_ALL_ALGOS("classic",            48,          18,                  6,      0),      // Classic example
  _TEST_CASE_ALL_ALGOS("int-extreme", INT32_MIN,   INT32_MAX,   GCD_NO_AVAILABLE,      0),      // Special case where INT32_MIN exists
};
// clang-format on

//* ======================================================================= } */

/* Test helpers ------------------------------------------------------------- */

/*
 * TEST CASES
 * =============================================================================
 */

TEST_GROUP(ADVM_NUM_THEO);

TEST_SETUP(ADVM_NUM_THEO)
{
  // intentionally left empty
}

TEST_TEAR_DOWN(ADVM_NUM_THEO)
{
  // intentionally left empty
}

/*
 *
 * =============================================================================
 */

TEST(ADVM_NUM_THEO, gcd)
{
  test_helper_int(cases_gcd, ARRAY_SIZE(cases_gcd));
}

/* End of File -------------------------------------------------------------- */