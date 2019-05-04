/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzggev.h
 *
 * Code generation for function 'xzggev'
 *
 */

#ifndef XZGGEV_H
#define XZGGEV_H

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
extern void xzggev(const emlrtStack *sp, creal_T A[9], int32_T *info, creal_T
                   alpha1[3], creal_T beta1[3], creal_T V[9]);

#endif

/* End of code generation (xzggev.h) */
