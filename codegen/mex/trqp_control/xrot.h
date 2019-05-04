/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xrot.h
 *
 * Code generation for function 'xrot'
 *
 */

#ifndef XROT_H
#define XROT_H

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
extern void b_xrot(real_T x[9], int32_T ix0, int32_T iy0, real_T c, real_T s);
extern void xrot(const emlrtStack *sp, int32_T n, real_T x[9], int32_T ix0,
                 int32_T iy0, real_T c, real_T s);

#endif

/* End of code generation (xrot.h) */
