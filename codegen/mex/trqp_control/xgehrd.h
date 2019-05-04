/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgehrd.h
 *
 * Code generation for function 'xgehrd'
 *
 */

#ifndef XGEHRD_H
#define XGEHRD_H

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
extern void b_xgehrd(const emlrtStack *sp, creal_T a[9], creal_T tau[2]);
extern void xgehrd(const emlrtStack *sp, real_T a[9], real_T tau[2]);

#endif

/* End of code generation (xgehrd.h) */
