/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mod.c
 *
 * Code generation for function 'mod'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "mod.h"

/* Function Definitions */
int32_T b_mod(int32_T x)
{
  return x - x / 10 * 10;
}

/* End of code generation (mod.c) */
