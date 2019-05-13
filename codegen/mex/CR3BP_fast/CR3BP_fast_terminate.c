/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CR3BP_fast_terminate.c
 *
 * Code generation for function 'CR3BP_fast_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CR3BP_fast.h"
#include "CR3BP_fast_terminate.h"
#include "_coder_CR3BP_fast_mex.h"
#include "CR3BP_fast_data.h"

/* Function Definitions */
void CR3BP_fast_atexit(void)
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

void CR3BP_fast_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (CR3BP_fast_terminate.c) */
