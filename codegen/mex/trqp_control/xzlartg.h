/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzlartg.h
 *
 * Code generation for function 'xzlartg'
 *
 */

#ifndef XZLARTG_H
#define XZLARTG_H

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
extern void b_xzlartg(const emlrtStack *sp, const creal_T f, const creal_T g,
                      real_T *cs, creal_T *sn);
extern void xzlartg(const emlrtStack *sp, const creal_T f, const creal_T g,
                    real_T *cs, creal_T *sn, creal_T *r);

#endif

/* End of code generation (xzlartg.h) */
