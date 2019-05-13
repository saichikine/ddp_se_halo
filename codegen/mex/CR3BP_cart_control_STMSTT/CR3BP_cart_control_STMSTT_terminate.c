/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CR3BP_cart_control_STMSTT_terminate.c
 *
 * Code generation for function 'CR3BP_cart_control_STMSTT_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CR3BP_cart_control_STMSTT.h"
#include "CR3BP_cart_control_STMSTT_terminate.h"
#include "_coder_CR3BP_cart_control_STMSTT_mex.h"
#include "CR3BP_cart_control_STMSTT_data.h"

/* Function Definitions */
void CR3BP_cart_control_STMSTT_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void CR3BP_cart_control_STMSTT_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (CR3BP_cart_control_STMSTT_terminate.c) */
