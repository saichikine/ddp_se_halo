/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eig.h
 *
 * Code generation for function 'eig'
 *
 */

#ifndef EIG_H
#define EIG_H

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

/* Type Definitions */
#include "lapacke.h"

/* Function Declarations */
extern void b_eig(const emlrtStack *sp, const creal_T A[9], creal_T V[9],
                  creal_T D[3]);
extern void eig(const emlrtStack *sp, const real_T A[9], creal_T V[9], creal_T
                D[3]);

#endif

/* End of code generation (eig.h) */
