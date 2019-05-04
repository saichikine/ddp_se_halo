/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trqp_control.h
 *
 * Code generation for function 'trqp_control'
 *
 */

#ifndef TRQP_CONTROL_H
#define TRQP_CONTROL_H

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
extern void trqp_control(const emlrtStack *sp, real_T H[9], real_T g[3], real_T
  delta, const real_T M[9], creal_T s_out[3], creal_T H_out[9], boolean_T
  *bool_TRQP_failure);

#endif

/* End of code generation (trqp_control.h) */
