/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * schur.h
 *
 * Code generation for function 'schur'
 *
 */

#ifndef SCHUR_H
#define SCHUR_H

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
extern void b_schur(const emlrtStack *sp, const creal_T A[36], creal_T V[36],
                    creal_T T[36]);
extern void schur(const emlrtStack *sp, const real_T A[36], creal_T V[36],
                  creal_T T[36]);

#endif

/* End of code generation (schur.h) */
