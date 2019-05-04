/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xhseqr.h
 *
 * Code generation for function 'xhseqr'
 *
 */

#ifndef XHSEQR_H
#define XHSEQR_H

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
extern int32_T b_xhseqr(const emlrtStack *sp, creal_T h[36], creal_T z[36]);
extern int32_T xhseqr(const emlrtStack *sp, real_T h[36], real_T z[36]);

#endif

/* End of code generation (xhseqr.h) */
