/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CR3BP_fast.h
 *
 * Code generation for function 'CR3BP_fast'
 *
 */

#ifndef CR3BP_FAST_H
#define CR3BP_FAST_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "CR3BP_fast_types.h"

/* Function Declarations */
extern void CR3BP_fast(const emlrtStack *sp, real_T t, const real_T X[6], real_T
  mu, real_T X_dot[6]);

#endif

/* End of code generation (CR3BP_fast.h) */