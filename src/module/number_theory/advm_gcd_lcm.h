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
/* Prvent recursion --------------------------------------------------------- */
#ifndef _ADVM_NUMBER_THEORY_GCD_LCM_H
#define _ADVM_NUMBER_THEORY_GCD_LCM_H

/* Include ------------------------------------------------------------------ */
#include "advm_config.h"

/* Function tables ---------------------------------------------------------- */
//! add function here
// clang-format off
#define ADVM_GCD_LCM_FUNC_TABLE \
  { "gcd",             FUNC_INT32, advm_gcd_iter_euclid }, \
  { "gcd_iter_euclid", FUNC_INT32, advm_gcd_iter_euclid }, \
  { "gcd_binary",      FUNC_INT32, advm_gcd_binary }, \
  { "gcd_stein",       FUNC_INT32, advm_gcd_stein }, \
  { "gcd_stein_naive", FUNC_INT32, advm_gcd_stein_naive }, \
  { "gcd_recursion",   FUNC_INT32, advm_gcd_recursion }, \
  { "lcm",             FUNC_INT32, advm_lcm_classic }, \
  { "lcm_classic",     FUNC_INT32, advm_lcm_classic }
// clang-format on

/* Public defines ----------------------------------------------------------- */
#define GCD_SPECIAL_CASE_RETURN 0 ///< inputs have 0
#define LCD_SPECIAL_CASE_RETURN 0 ///< special return value for LCD's invalid inputs
/// default GCD Algorithm
#if !defined(DEF_GCD_ALGORITHM)
#define DEF_GCD_ALGORITHM (GCD_ALGO_ITER_EUCLID)
#endif

/* Public variables --------------------------------------------------------- */
typedef enum
{
  GCD_ALGO_RECURSION = 0, ///< Simplest idea of GCD algorithm
  GCD_ALGO_ITER_EUCLID,   ///< Iterative Euclidean algorithm
  GCD_ALGO_BINARY,        ///< Different name for optimized Stein's GCD algorithm
  GCD_ALGO_STEIN,         ///< Optimized Stein's GCD algorithm
  GCD_ALGO_STEIN_NAIVE,   ///< Original Stein's GCD algorithm (for demonstration)
  GCD_NUM_OF_ALGO,
} advm_gcd_algo_t;

typedef enum
{
  LCM_ALGO_CLASSIC = 0, ///< Standard LCM: lcm(a, b) = |a * b| / gcd(a, b)
  // LCM_ALGO_BRUTE_FORCE, ///< Naive brute force (educational) - Not implemented
  // LCM_ALGO_FACTORIZE, ///< Prime factorization (if implemented) - Not implemented
  LCM_NUM_OF_ALGO
} advm_lcm_algo_t;

/* Public macros ------------------------------------------------------------ */

/* Function protoypes ------------------------------------------------------- */

int32_t advm_gcd_iter_euclid(int32_t a, int32_t b);
int32_t advm_gcd_binary(int32_t a, int32_t b);
int32_t advm_gcd_stein(int32_t a, int32_t b);
int32_t advm_gcd_stein_naive(int32_t a, int32_t b);
int32_t advm_gcd_recursion(int32_t a, int32_t b);

int32_t advm_lcm_classic(int32_t a, int32_t b);

#endif // _ADVM_NUMBER_THEORY_GCD_LCM_H

/* End of File -------------------------------------------------------------- */
