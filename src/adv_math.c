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

int advm_add(int a, int b)
{
  return a + b;
}

int advm_sub(int a, int b)
{
  return a - b;
}

int advm_mul(int a, int b)
{
  return a * b;
}

int advm_div(int a, int b)
{
  if (b == 0)
  {
    // Handle division by zero, could return an error code or raise an exception
    return 0; // Placeholder for error handling
  }
  return a / b;
}