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

/* Prevent includes recursive ----------------------------------------------- */
#ifndef ADV_MATH_ALGORITHMS_H
#define ADV_MATH_ALGORITHMS_H

/* Includes ----------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>
#include "basetype.h"

#include "advm_basic_op.h"
#include "advm_num_theo.h"
#include "adv_math_application.h"

/* Public defines ----------------------------------------------------------- */
/* Public macros ------------------------------------------------------------ */

// Logging
#if !defined(__USE_LOG)
#define LOG(msg, ...) ((void)0)
#else
#define LOG(msg, ...) printf("[%s] " msg "\n", TAG, ##__VA_ARGS__)
#endif // __USE_LOG

// Assertion
#if !defined(__USE_FULL_ASSERTION)
#define ADVM_CHECK(cond, ret) ((void)0)
#else
#define ADVM_CHECK(cond, ret)           \
  if (!(cond))                          \
  {                                     \
    LOG("Condition failed: %s", #cond); \
    return ret;                         \
  }
#endif // __USE_FULL_ASSERTION

/* Helper macros ------------------------------------------------------------ */
#define SIGN(x)      ((x < 0) ? BS_NEG : BS_POS) ///< Sign of a number
#define IS_EVEN(num) (!((num) & 1))           ///< Check if input is an even number, return Boolean True/False
#define IS_ODD(num)  ((num) & 1)              ///< Check if input is an odd number, return Boolean True/False
#define ABS(x)       (((x) < 0) ? -(x) : (x)) ///< Absolute
/**
 * @brief Swap 2 intergers using XOR algorithm
 *
 * @warning Do not use this for floating numbers, use @ref SWAP_FLOAT instead
 *
 */
#define SWAP_XOR(a, b) \
  a ^= b;              \
  b ^= a;              \
  a ^= b;

#define SWAP_INT(a, b) SWAP_XOR(a, b)

#define SWAP_FLOAT(a, b) \
  float32_t temp = a;    \
  a              = b;    \
  b              = temp;

/* Public typedefs ---------------------------------------------------------- */
typedef int32_t (*op_func_int_t)(int32_t a, int32_t b);
typedef float32_t (*op_func_float_t)(float32_t a, float32_t b);

typedef int32_t (*op_func_pair_transform_int_t)(int32_t *a, int32_t *b);

/* Function prototypes ------------------------------------------------------ */

/*
 *  CALCULUS (NUMERICAL)
 * =============================================================================
 */
double advm_derivative(double (*f)(double), double x,
                       double h); // f'(x) ≈ [f(x + h) - f(x)] / h
double advm_integrate(double (*f)(double), double a, double b,
                      int n); // numerical integration using Trapezoidal Rule

/*
 *  ALGEBRA / LINEAR ALGEBRA
 * =============================================================================
 */
void  advm_matrix_add(const float *A, const float *B, float *C, int rows, int cols);
void  advm_matrix_mul(const float *A, const float *B, float *C, int m, int n,
                      int p);                       // A[m x n] * B[n x p] = C[m x p]
float advm_determinant(const float *matrix, int n); // square matrix only

/*
 *  DYNAMIC PROGRAMMING
 * =============================================================================
 */
int advm_fibonacci_dp(int n);
int advm_knapsack_01(const int *w, const int *v, int n, int W);

/*
 *  GRAPH THEORY (BASIC)
 * =============================================================================
 */
void advm_dfs(int graph[][100], int n, int start, bool_t *visited);
void advm_bfs(int graph[][100], int n, int start);

/*
 *  MISCELLANEOUS
 * =============================================================================
 */
void advm_swap(int *a, int *b);
void advm_reverse(int arr[], int n);
void advm_shuffle(int arr[], int n); // Fisher–Yates shuffle

/*
 *  SORTING ALGORITHMS
 * =============================================================================
 */
void advm_bubble_sort(int arr[], int n);
void advm_selection_sort(int arr[], int n);
void advm_insertion_sort(int arr[], int n);
void advm_merge_sort(int arr[], int l, int r);
void advm_quick_sort(int arr[], int l, int r);
void advm_heap_sort(int arr[], int n);

/*
 *  SEARCHING ALGORITHMS
 * =============================================================================
 */
int advm_linear_search(const int arr[], int n, int target);
int advm_binary_search(const int arr[], int l, int r, int target);

#endif /* ADV_MATH_ALGORITHMS_H */

/* End of File -------------------------------------------------------------- */
