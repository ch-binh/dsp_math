/**
 *******************************************************************************
 * @file    advm_calculus.h
 * @brief   Advanced mathematical and algorithmic function declarations.
 * @details This is a high-level interface to various algorithms implemented in
 *C. Designed to support numerical computation, signal processing, and
 *          embedded-friendly math operations.
 *
 * @date    2025/06/15
 * @author  Binh Pham
 *******************************************************************************
 * @attention
 * ! Update information
 *******************************************************************************
 */

/* Include ------------------------------------------------------------------ */
#include "advm_sort.h"

/* Function tables ---------------------------------------------------------- */

/* Public defines ----------------------------------------------------------- */

/* Public variables --------------------------------------------------------- */

/* Public macros ------------------------------------------------------------ */

/* Function protoypes ------------------------------------------------------- */

void advm_bubble_sort(float32_t *arr, uint32_t n) {}; 

void advm_selection_sort(int arr[], int n);
void advm_insertion_sort(int arr[], int n);
void advm_merge_sort(int arr[], int l, int r);
void advm_quick_sort(int arr[], int l, int r);
void advm_heap_sort(int arr[], int n);

/* End of File -------------------------------------------------------------- */
