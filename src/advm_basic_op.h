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
#ifndef _ADVM_BASIC_OP_H
#define _ADVM_BASIC_OP_H

/* Include ------------------------------------------------------------------ */
#include "basetype.h"

/* Public variables --------------------------------------------------------- */

/* Public macros ------------------------------------------------------------ */

/* Function protoypes ------------------------------------------------------- */

/*
 *  BASIC ARITHMETIC
 * =============================================================================
 */

/**
 * @brief
 *
 * @param a
 * @param b
 * @return float64_t
 */
float32_t advm_add(float32_t a, float32_t b);
float32_t advm_sub(float32_t a, float32_t b);
float32_t advm_mul(float32_t a, float32_t b);
float32_t advm_div(float32_t a, float32_t b);
int32_t   advm_mod(int32_t a, int32_t b);

#endif // _ADVM_BASIC_OP_H

/* End of File -------------------------------------------------------------- */
