/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mldivide.h
 *
 * Code generation for function 'mldivide'
 *
 */

#ifndef MLDIVIDE_H
#define MLDIVIDE_H

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
extern void b_mldivide(const emlrtStack *sp, const creal_T A[36], creal_T B[6]);
extern void mldivide(const emlrtStack *sp, const creal_T A[36], const real_T B[6],
                     creal_T Y[6]);

#endif

/* End of code generation (mldivide.h) */
