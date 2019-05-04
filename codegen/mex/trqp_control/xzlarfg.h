/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzlarfg.h
 *
 * Code generation for function 'xzlarfg'
 *
 */

#ifndef XZLARFG_H
#define XZLARFG_H

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
extern creal_T b_xzlarfg(const emlrtStack *sp, creal_T *alpha1, creal_T *x);
extern real_T xzlarfg(const emlrtStack *sp, int32_T n, real_T *alpha1, real_T x
                      [3]);

#endif

/* End of code generation (xzlarfg.h) */
