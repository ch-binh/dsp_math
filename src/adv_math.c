/**
 ******************************************************************************
 * @file    adv_math_algorithms.h
 * @brief   Advanced mathematical and algorithmic function declarations.
 * @details This is a high-level interface to various algorithms implemented in
 *C. Designed to support numerical computation, signal processing, and
 *          embedded-friendly math operations.
 *
 * @date    2025/06/15
 * @author  Binh Pham
 ******************************************************************************
 */

/* Includes ----------------------------------------------------------------- */
#include "adv_math.h"

/* Function prototypes ------------------------------------------------------ */

/*
 *  BASIC ARITHMETIC
 * =============================================================================
 */

/**
 * @brief addition
 *
 * @param a
 * @param b
 * @return float64_t
 */
float32_t advm_add(float32_t a, float32_t b)
{
  return a + b;
}

/**
 * !! TODO: UPDATE THIS COMMENT
 * @brief
 *
 * @param a
 * @param b
 * @return float64_t
 */
float32_t advm_sub(float32_t a, float32_t b)
{
  return a - b;
}

/**
 * !! TODO: UPDATE THIS COMMENT
 * @brief
 *
 * @param[in] a
 * @param[in] b
 * @return float64_t
 */
float32_t advm_mul(float32_t a, float32_t b)
{
  return a * b;
}
float32_t advm_div(float32_t a, float32_t b)
{
  // if (b == 0.0)
  // {
  //   return POS_INF;
  // }
  return a / b;
}

int32_t advm_mod(int32_t a, int32_t b)
{
  return a % b;
}
