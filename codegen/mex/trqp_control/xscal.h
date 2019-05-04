/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xscal.h
 *
 * Code generation for function 'xscal'
 *
 */

#ifndef XSCAL_H
#define XSCAL_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "trqp_control_types.h"

/* Function Declarations */
extern void b_xscal(const emlrtStack *sp, int32_T n, const creal_T a, creal_T x
                    [9], int32_T ix0);
extern void c_xscal(const emlrtStack *sp, int32_T n, const creal_T a, creal_T x
                    [9], int32_T ix0);
extern void d_xscal(const emlrtStack *sp, const creal_T a, creal_T x[9], int32_T
                    ix0);
extern void xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[3]);

#endif

/* End of code generation (xscal.h) */
