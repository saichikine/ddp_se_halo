/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fX.h
 *
 * Code generation for function 'fX'
 *
 */

#ifndef FX_H
#define FX_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "CR3BP_cart_control_STMSTT_types.h"

/* Function Declarations */
extern void fX(const emlrtStack *sp, const real_T X[1110], real_T c, real_T mu,
               real_T Tmax, real_T b_fX[100]);

#endif

/* End of code generation (fX.h) */
