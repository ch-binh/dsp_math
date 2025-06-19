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

#include "adv_math.h"
#include "unity.h"
#include "unity_fixture.h"

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

TEST(BASIC_OP, add_positive_int)
{
  TEST_ASSERT_EQUAL_INT(100, advm_add(40, 60));
}

TEST(BASIC_OP, add_negative_int)
{
  TEST_ASSERT_EQUAL_INT(-100, advm_add(-40, -60));
}

TEST(BASIC_OP, add_opposite_signs_int)
{
  TEST_ASSERT_EQUAL_INT(20, advm_add(80, -60));
  TEST_ASSERT_EQUAL_INT(-20, advm_add(-80, 60));
}

TEST(BASIC_OP, add_zero_int)
{
  TEST_ASSERT_EQUAL_INT(42, advm_add(42, 0));
  TEST_ASSERT_EQUAL_INT(-42, advm_add(0, -42));
}

TEST(BASIC_OP, add_small_floats)
{
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f * FLT_MIN, advm_add(FLT_MIN, FLT_MIN));
}

TEST(BASIC_OP, add_large_floats)
{
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, FLT_MAX, advm_add(FLT_MAX, 2323.0f));
}

TEST(BASIC_OP, add_infinity)
{
  TEST_ASSERT_EQUAL_FLOAT(INFINITY, advm_add(INFINITY, 1234123.0f));
  TEST_ASSERT_EQUAL_FLOAT(-INFINITY, advm_add(-INFINITY, -11234234.0f));
}

TEST(BASIC_OP, add_nan)
{
  float nan = NAN;
  TEST_ASSERT_TRUE(isnan(advm_add(nan, 1.0f)));
  TEST_ASSERT_TRUE(isnan(advm_add(1.0f, nan)));
}

TEST(BASIC_OP, add_infinity_and_neg_infinity)
{
  TEST_ASSERT_TRUE(isnan(advm_add(INFINITY, -INFINITY)));
}

// 2. Mathematical Properties

TEST(BASIC_OP, add_commutative)
{
  TEST_ASSERT_EQUAL_FLOAT(advm_add(3.5f, 7.2f), advm_add(7.2f, 3.5f));
}

TEST(BASIC_OP, add_identity)
{
  TEST_ASSERT_EQUAL_FLOAT(5.5f, advm_add(5.5f, 0.0f));
}

TEST(BASIC_OP, add_associative)
{
  float a = 1.1f, b = 2.2f, c = 3.3f;
  float left  = advm_add(advm_add(a, b), c);
  float right = advm_add(a, advm_add(b, c));
  TEST_ASSERT_FLOAT_WITHIN(1e-6f, left, right);
}

TEST(BASIC_OP, add_inverse)
{
  float a = 123.456f;
  TEST_ASSERT_FLOAT_WITHIN(1e-6f, 0.0f, advm_add(a, -a));
}

// 3. Accuracy & Rounding

TEST(BASIC_OP, add_floating_point_precision)
{
  TEST_ASSERT_FLOAT_WITHIN(1e-6f, 0.3f, advm_add(0.1f, 0.2f));
  TEST_ASSERT_FLOAT_WITHIN(1e-3f, 1e6f, advm_add(1e6f, 1e-3f));
}

// 4. Determinism

TEST(BASIC_OP, add_determinism)
{
  float result1 = advm_add(123.45f, 67.89f);
  float result2 = advm_add(123.45f, 67.89f);
  TEST_ASSERT_EQUAL_FLOAT(result1, result2);
}

// 5. System/Hardware Errors

TEST(BASIC_OP, add_overflow)
{
  float result = advm_add(FLT_MAX, 1e32f);
  TEST_ASSERT_EQUAL_FLOAT(INFINITY, result);
}

TEST(BASIC_OP, add_underflow)
{
  float result = advm_add(FLT_MIN, -FLT_MIN);
  TEST_ASSERT_FLOAT_WITHIN(1e-38f, 0.0f, result);
}

// 6. Code Coverage

TEST(BASIC_OP, add_branch_coverage)
{
  TEST_ASSERT_EQUAL_INT(0, advm_add(0, 0));
  TEST_ASSERT_EQUAL_FLOAT(0.0f, advm_add(0.0f, 0.0f));
}

/* End of File -------------------------------------------------------------- */