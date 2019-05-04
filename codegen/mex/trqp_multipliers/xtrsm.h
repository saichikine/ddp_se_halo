/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xtrsm.h
 *
 * Code generation for function 'xtrsm'
 *
 */

#ifndef XTRSM_H
#define XTRSM_H

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
extern void b_xtrsm(const creal_T A[36], creal_T B[6]);
extern void xtrsm(const creal_T A[36], creal_T B[6]);

#endif

/* End of code generation (xtrsm.h) */
