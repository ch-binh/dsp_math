#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(BASIC_OP)
{
  RUN_TEST_CASE(BASIC_OP, add_float);
  RUN_TEST_CASE(BASIC_OP, sub_float);
  RUN_TEST_CASE(BASIC_OP, mul_float);
  RUN_TEST_CASE(BASIC_OP, div_float);
}