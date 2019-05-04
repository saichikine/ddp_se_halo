/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgerc.h
 *
 * Code generation for function 'xgerc'
 *
 */

#ifndef XGERC_H
#define XGERC_H

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
extern void b_xgerc(const emlrtStack *sp, int32_T m, int32_T n, const creal_T
                    alpha1, int32_T ix0, const creal_T y[6], creal_T A[36],
                    int32_T ia0);
extern void xgerc(const emlrtStack *sp, int32_T m, int32_T n, real_T alpha1,
                  int32_T ix0, const real_T y[6], real_T A[36], int32_T ia0);

#endif

/* End of code generation (xgerc.h) */
