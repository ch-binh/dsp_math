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

/* Function prototypes ------------------------------------------------------ */
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

/* Public defines ----------------------------------------------------------- */
#define INF long long long

/* Function prototypes ------------------------------------------------------ */

/*
 *  BASIC ARITHMETIC
 * =============================================================================
 */

int advm_add(int a, int b);
int advm_sub(int a, int b);
int advm_mul(int a, int b);
int advm_div(int a, int b);
int advm_mod(int a, int b);

/*
 *  NUMBER THEORY
 * =============================================================================
 */
int advm_gcd(int a, int b);
int advm_lcm(int a, int b);
bool advm_is_prime(int n);
int advm_mod_pow(int base, int exp, int mod); // base^exp % mod

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
void advm_matrix_add(const float *A, const float *B, float *C, int rows,
                     int cols);
void advm_matrix_mul(const float *A, const float *B, float *C, int m, int n,
                     int p); // A[m x n] * B[n x p] = C[m x p]
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
void advm_dfs(int graph[][100], int n, int start, bool *visited);
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