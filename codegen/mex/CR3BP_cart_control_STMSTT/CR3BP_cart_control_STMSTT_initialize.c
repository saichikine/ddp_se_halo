/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CR3BP_cart_control_STMSTT_initialize.c
 *
 * Code generation for function 'CR3BP_cart_control_STMSTT_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CR3BP_cart_control_STMSTT.h"
#include "CR3BP_cart_control_STMSTT_initialize.h"
#include "_coder_CR3BP_cart_control_STMSTT_mex.h"
#include "CR3BP_cart_control_STMSTT_data.h"

/* Function Definitions */
void CR3BP_cart_control_STMSTT_initialize(void)
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

/* End of code generation (CR3BP_cart_control_STMSTT_initialize.c) */
