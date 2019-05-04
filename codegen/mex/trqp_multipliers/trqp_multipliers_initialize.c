/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trqp_multipliers_initialize.c
 *
 * Code generation for function 'trqp_multipliers_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "trqp_multipliers_initialize.h"
#include "_coder_trqp_multipliers_mex.h"
#include "trqp_multipliers_data.h"

/* Function Definitions */
void trqp_multipliers_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (trqp_multipliers_initialize.c) */
