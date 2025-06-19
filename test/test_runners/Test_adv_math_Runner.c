#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(BASIC_OP)
{
  RUN_TEST_CASE(BASIC_OP, add_positive_int);
  RUN_TEST_CASE(BASIC_OP, add_negative_int);
  RUN_TEST_CASE(BASIC_OP, add_opposite_signs_int);
  RUN_TEST_CASE(BASIC_OP, add_zero_int);
  RUN_TEST_CASE(BASIC_OP, add_small_floats);
  RUN_TEST_CASE(BASIC_OP, add_large_floats);
  RUN_TEST_CASE(BASIC_OP, add_infinity);
  RUN_TEST_CASE(BASIC_OP, add_nan);
  RUN_TEST_CASE(BASIC_OP, add_infinity_and_neg_infinity);
  RUN_TEST_CASE(BASIC_OP, add_commutative);
  RUN_TEST_CASE(BASIC_OP, add_identity);
  RUN_TEST_CASE(BASIC_OP, add_associative);
  RUN_TEST_CASE(BASIC_OP, add_inverse);
  RUN_TEST_CASE(BASIC_OP, add_floating_point_precision);
  RUN_TEST_CASE(BASIC_OP, add_determinism);
  RUN_TEST_CASE(BASIC_OP, add_overflow);
  RUN_TEST_CASE(BASIC_OP, add_underflow);
  RUN_TEST_CASE(BASIC_OP, add_branch_coverage);
}