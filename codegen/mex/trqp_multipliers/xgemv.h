/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgemv.h
 *
 * Code generation for function 'xgemv'
 *
 */

#ifndef XGEMV_H
#define XGEMV_H

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
extern void b_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const creal_T A
                    [36], int32_T ia0, const creal_T x[36], int32_T ix0, creal_T
                    y[6]);
extern void xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[36],
                  int32_T ia0, const real_T x[36], int32_T ix0, real_T y[6]);

#endif

/* End of code generation (xgemv.h) */
