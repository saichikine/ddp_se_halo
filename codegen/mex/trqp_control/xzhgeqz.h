/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzhgeqz.h
 *
 * Code generation for function 'xzhgeqz'
 *
 */

#ifndef XZHGEQZ_H
#define XZHGEQZ_H

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
extern void xzhgeqz(const emlrtStack *sp, creal_T A[9], int32_T ilo, int32_T ihi,
                    creal_T Z[9], int32_T *info, creal_T alpha1[3], creal_T
                    beta1[3]);

#endif

/* End of code generation (xzhgeqz.h) */
