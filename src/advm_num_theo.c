/**
 *******************************************************************************
 * @file    adv_math_algorithms.h
 * @brief   Advanced mathematical and algorithmic function declarations.
 * @details This is a high-level interface to various algorithms implemented in
 *C. Designed to support numerical computation, signal processing, and
 *          embedded-friendly math operations.
 *
 * @date    2025/06/15
 * @author  Binh Pham
 *******************************************************************************
 * @attention
 *
 *******************************************************************************
 */
/* Include ------------------------------------------------------------------ */
#include "advm_num_theo.h"
#include "advm_basic_op.h"

/* Private macros ----------------------------------------------------------- */

// op_func_int_t g_advm_gcd_func_table[GCD_NUM_OF_ALGO] = {
//   [GCD_ALGO_ITER_EUCLID] = advm_gcd_iter_euclid,
//   [GCD_ALGO_STEIN]       = advm_gcd_stein,
// };

#define _GCD_PRE_CHECK(a, b)                \
  if ((a == INT32_MIN) || (b == INT32_MIN)) \
    return GCD_NO_AVAILABLE;                \
  else if (a == 0 && b == 0)                \
    return GCD_NO_AVAILABLE;                \
  else if (a == 0)                          \
    return b;                               \
  else if (b == 0)                          \
    return a;

#define _GCD_ABS_INPUTS(a, b) \
  a = ABS(a);                 \
  b = ABS(b);
/* Function protoypes ------------------------------------------------------- */
/*
 *  NUMBER THEORY
 * =============================================================================
 */

// TODO: Update comments

/**
 * @brief   Compute the greatest common divisor (GCD) of two integers using the selected algorithm.
 *
 * @param[in] a         First integer.
 * @param[in] b         Second integer.
 * @param[in] algorithm Algorithm to use for GCD computation (see advm_gcd_algo_t).
 *
 * @retval    int32_t   The greatest common divisor of a and b.
 * @retval    GCD_NO_AVAILABLE (0) if either input a or b is zero.
 */
int32_t advm_gcd(int32_t a, int32_t b, advm_gcd_algo_t algorithm)
{
  _GCD_PRE_CHECK(a, b);
  _GCD_ABS_INPUTS(a, b);

  switch (algorithm)
  {
  case GCD_ALGO_RECURSION:
    return advm_gcd_recursion(a, b);
  case GCD_ALGO_ITER_EUCLID:
    return advm_gcd_iter_euclid(a, b);
  case GCD_ALGO_BINARY:
    return advm_gcd_binary(a, b);
  case GCD_ALGO_STEIN:
    return advm_gcd_stein(a, b);
  case GCD_ALGO_STEIN_NAIVE:
    return advm_gcd_stein_naive(a, b);
  default:
    return GCD_NO_AVAILABLE;
  }
}

/**
 * @brief   Compute the greatest common divisor (GCD) of two integers recursively using the Euclidean
 * algorithm.
 *
 * @param[in] a First integer.
 * @param[in] b Second integer.
 *
 * @retval    int32_t The greatest common divisor of a and b.
 */
int32_t advm_gcd_recursion(int32_t a, int32_t b)
{
  _GCD_PRE_CHECK(a, b);
  _GCD_ABS_INPUTS(a, b);

  return (b == 0) ? a : advm_gcd_recursion(b, a % b);
}

/**
 * @brief   Compute the greatest common divisor (GCD) of two integers using the iterative Euclidean algorithm.
 *
 * @details This method uses modulo (division) operations for GCD calculation.
 *          For a division-free approach, use Stein's algorithm (@ref advm_gcd_stein).
 *
 * @param[in] a First integer.
 * @param[in] b Second integer.
 *
 * @retval    int32_t The greatest common divisor of a and b.
 * @retval    GCD_NO_AVAILABLE (0) if either input a or b is zero.
 */
int32_t advm_gcd_iter_euclid(int32_t a, int32_t b)
{
  _GCD_PRE_CHECK(a, b);
  _GCD_ABS_INPUTS(a, b);

  while (b != 0)
  {
    int32_t temp = b;
    b            = advm_mod(a, b);
    a            = temp;
  }
  return a;
}

/**
 * @brief   Compute the greatest common divisor (GCD) of two integers using the binary GCD (Stein's)
 * algorithm.
 *
 * @details This function is an alias for advm_gcd_stein(), providing a more descriptive name for the binary
 * GCD method.
 *
 * @param[in] a First integer.
 * @param[in] b Second integer.
 *
 * @retval    int32_t The greatest common divisor of a and b.
 */
int32_t advm_gcd_binary(int32_t a, int32_t b)
{
  return advm_gcd_stein(a, b);
}

/**
 * @brief   Compute the greatest common divisor (GCD) of two integers using Stein's (binary GCD) algorithm.
 *
 * @details This algorithm avoids division and uses only subtraction, bit-shifts, and comparisons.
 *
 * @param[in] a First integer.
 * @param[in] b Second integer.
 *
 * @retval    int32_t The greatest common divisor of a and b.
 * @retval    GCD_NO_AVAILABLE (0) if either input a or b is zero.
 */
int32_t advm_gcd_stein(int32_t a, int32_t b)
{
  _GCD_PRE_CHECK(a, b);
  _GCD_ABS_INPUTS(a, b);

  int32_t shift = 0;

  //  1. If both a and b are even → GCD(a, b) = 2 × GCD(a/2, b/2)
  while (((a | b) & 1) == 0)
  {
    a >>= 1;
    b >>= 1;
    shift++;
  }

  //  2. If one is even and the other is odd → divide the even number by 2
  while (IS_EVEN(a))
    a >>= 1;

  //  3. If both are odd → GCD(a, b) = GCD(|a - b|, min(a, b))
  do
  {
    while (IS_EVEN(b))
      b >>= 1;

    if (a > b)
    {
      SWAP_INT(a, b);
    }

    b = b - a;
  } while (b != 0);

  //  4. If one number is 0 → GCD = the other number
  return a << shift;
}

/**
 * @brief   Compute the greatest common divisor (GCD) of two integers using the naive recursive Stein's
 * algorithm.
 *
 * @details This is a straightforward recursive implementation of the binary GCD algorithm.
 *
 * @param[in] a First integer.
 * @param[in] b Second integer.
 *
 * @retval    int32_t The greatest common divisor of a and b.
 */
int32_t advm_gcd_stein_naive(int32_t a, int32_t b)
{
  // Original algorithm:
  //
  // 1. If a == b → GCD is a
  // 2. If a == 0 → GCD is b; if b == 0 → GCD is a
  // 3. If both are even → GCD(a, b) = 2 × GCD(a/2, b/2)
  // 4. If a is even, b is odd → GCD(a, b) = GCD(a/2, b)
  // 5. If a is odd, b is even → GCD(a, b) = GCD(a, b/2)
  // 6. If both are odd and a > b → GCD(a, b) = GCD((a - b)/2, b)
  // 7. Otherwise → GCD(a, b) = GCD((b - a)/2, a)
  _GCD_PRE_CHECK(a, b);
  _GCD_ABS_INPUTS(a, b);

  if (a == b)
    return a;
  if (a == 0)
    return b;
  if (b == 0)
    return a;

  if (IS_EVEN(a) && IS_EVEN(b))
  {
    return 2 * advm_gcd_stein_naive(a >> 1, b >> 1);
  }
  else if IS_EVEN (a)
  {
    return advm_gcd_stein_naive(a >> 1, b);
  }
  else if IS_EVEN (b)
  {
    return advm_gcd_stein_naive(a, b >> 1);
  }
  else
  {
    return advm_gcd_stein_naive((a - b) >> 1, MIN(a, b));
  }
}

//!=============================================================================

/**
 * @brief
 *
 * @param a
 * @param b
 * @return int32_t
 */
int32_t advm_lcm(int32_t a, int32_t b)
{
  return 1;
}

/**
 * @brief
 *
 * @param n
 * @return bool_t
 */
bool_t advm_is_prime(int n)
{
  return 1;
}

/**
 * @brief
 *
 * @param base
 * @param exp
 * @param mod
 * @return int32_t
 */
int32_t advm_mod_pow(int32_t base, int32_t exp, int32_t mod); // base^exp % mod

/* End of File -------------------------------------------------------------- */
