/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * toLogicalCheck.c
 *
 * Code generation for function 'toLogicalCheck'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "toLogicalCheck.h"

/* Variable Definitions */
static emlrtRTEInfo f_emlrtRTEI = { 12,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

/* Function Definitions */
void toLogicalCheck(const emlrtStack *sp, real_T x)
{
  if (muDoubleScalarIsNaN(x)) {
    emlrtErrorWithMessageIdR2018a(sp, &f_emlrtRTEI, "MATLAB:nologicalnan",
      "MATLAB:nologicalnan", 0);
  }
}

/* End of code generation (toLogicalCheck.c) */
