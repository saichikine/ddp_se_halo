/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xnrm2.h
 *
 * Code generation for function 'xnrm2'
 *
 */

#ifndef XNRM2_H
#define XNRM2_H

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
extern real_T b_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[3]);
extern real_T c_xnrm2(const emlrtStack *sp, int32_T n, const creal_T x[36],
                      int32_T ix0);
extern real_T xnrm2(const emlrtStack *sp, int32_T n, const real_T x[36], int32_T
                    ix0);

#endif

/* End of code generation (xnrm2.h) */
