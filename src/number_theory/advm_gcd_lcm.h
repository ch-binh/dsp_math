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
#include "basetype.h"
#include "adv_math.h"

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
/*
 *  NUMBER THEORY
 * =============================================================================
 */

int32_t advm_gcd(int32_t a, int32_t b, advm_gcd_algo_t algorithm);
int32_t advm_gcd_iter_euclid(int32_t a, int32_t b);
int32_t advm_gcd_binary(int32_t a, int32_t b);
int32_t advm_gcd_stein(int32_t a, int32_t b);
int32_t advm_gcd_stein_naive(int32_t a, int32_t b);
int32_t advm_gcd_recursion(int32_t a, int32_t b);
int32_t advm_lcm(int32_t a, int32_t b);
int32_t advm_lcm_classic(int32_t a, int32_t b);

/* Function tables ---------------------------------------------------------- */

// extern op_func_int_t g_advm_gcd_func_table[GCD_NUM_OF_ALGO];

#endif // _ADVM_NUMBER_THEORY_GCD_LCM_H

/* End of File -------------------------------------------------------------- */
