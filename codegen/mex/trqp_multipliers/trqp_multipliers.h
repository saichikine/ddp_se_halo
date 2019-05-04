/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trqp_multipliers.h
 *
 * Code generation for function 'trqp_multipliers'
 *
 */

#ifndef TRQP_MULTIPLIERS_H
#define TRQP_MULTIPLIERS_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "trqp_multipliers_types.h"

/* Function Declarations */
extern void trqp_multipliers(const emlrtStack *sp, real_T H[36], real_T g[6],
  real_T delta, const real_T M[36], creal_T s_out[6], creal_T H_out[36],
  boolean_T *bool_TRQP_failure);

#endif

/* End of code generation (trqp_multipliers.h) */
