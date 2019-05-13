/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "CR3BP_cart_control_STMSTT.h"
#include "sqrt.h"
#include "CR3BP_cart_control_STMSTT_data.h"

/* Function Definitions */
void b_sqrt(const emlrtStack *sp, real_T *x)
{
  if (*x < 0.0) {
    emlrtErrorWithMessageIdR2018a(sp, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  *x = muDoubleScalarSqrt(*x);
}

/* End of code generation (sqrt.c) */
