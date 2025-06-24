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
#ifndef ADV_MATH_H
#define ADV_MATH_H

/* Includes ----------------------------------------------------------------- */

#include "advm_basic_op.h"

#include "advm_gcd_lcm.h"
#include "advm_modular.h"
#include "advm_prime.h"

#include "adv_math_application.h"
#include "advm_func_register.h"

/* Public defines ----------------------------------------------------------- */
/* Public macros ------------------------------------------------------------ */

typedef struct
{
  const advm_table_entry_t *table;
  const int32_t             size;
} advm_table_group_t;

/* Helper macros ------------------------------------------------------------ */

/* Public typedefs ---------------------------------------------------------- */

/* Function prototypes ------------------------------------------------------ */

void adv_math_init(void);
//! =============

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

#endif /* ADV_MATH_H */

/* End of File -------------------------------------------------------------- */
