/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzlarf.h
 *
 * Code generation for function 'xzlarf'
 *
 */

#ifndef XZLARF_H
#define XZLARF_H

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
extern void b_xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0,
                     const creal_T tau, creal_T C[36], int32_T ic0, creal_T
                     work[6]);
extern void xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0,
                   real_T tau, real_T C[36], int32_T ic0, real_T work[6]);

#endif

/* End of code generation (xzlarf.h) */
