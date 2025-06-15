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

TEST(BASIC_OP, add)
{
  int a        = 5;
  int b        = 3;
  int expected = 8;

  int result = advm_add(a, b);

  TEST_ASSERT_EQUAL_INT(8, result);
}