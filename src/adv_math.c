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

/* Includes ----------------------------------------------------------------- */
#include "adv_math.h"

#define _FUNC_TABLE              \
  {                              \
    ADVM_BASIC_OP_FUNC_TABLE,    \
    ADVM_GCD_LCM_FUNC_TABLE,     \
    ADVM_APPLICATION_FUNC_TABLE, \
  }

void adv_math_init(void)
{
  advm_table_entry_t func_table[] = _FUNC_TABLE;

  for (uint_fast32_t i = 0; i < (sizeof(func_table) / sizeof(func_table[0])); i++)
  {
    advm_register_function(func_table[i].name, func_table[i].sig_type, func_table[i].func_ptr);
  }
}

/* End of file -------------------------------------------------------------- */
