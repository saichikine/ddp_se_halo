/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trqp_multipliers_terminate.c
 *
 * Code generation for function 'trqp_multipliers_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "trqp_multipliers_terminate.h"
#include "_coder_trqp_multipliers_mex.h"
#include "trqp_multipliers_data.h"

/* Function Definitions */
void trqp_multipliers_atexit(void)
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

void trqp_multipliers_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (trqp_multipliers_terminate.c) */
