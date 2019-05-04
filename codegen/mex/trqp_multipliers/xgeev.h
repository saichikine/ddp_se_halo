/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgeev.h
 *
 * Code generation for function 'xgeev'
 *
 */

#ifndef XGEEV_H
#define XGEEV_H

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
extern void xgeev(const emlrtStack *sp, const creal_T A[36], int32_T *info,
                  creal_T W[6], creal_T V[36]);

#endif

/* End of code generation (xgeev.h) */
