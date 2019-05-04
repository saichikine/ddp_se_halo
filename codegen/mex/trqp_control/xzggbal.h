/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzggbal.h
 *
 * Code generation for function 'xzggbal'
 *
 */

#ifndef XZGGBAL_H
#define XZGGBAL_H

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
extern void xzggbal(const emlrtStack *sp, creal_T A[9], int32_T *ilo, int32_T
                    *ihi, int32_T rscale[3]);

#endif

/* End of code generation (xzggbal.h) */
