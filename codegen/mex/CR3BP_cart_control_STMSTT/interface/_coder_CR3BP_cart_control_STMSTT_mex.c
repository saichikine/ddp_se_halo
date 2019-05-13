/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_CR3BP_cart_control_STMSTT_mex.c
 *
 * Code generation for function '_coder_CR3BP_cart_control_STMSTT_mex'
 *
 */

/* Include files */
#include "CR3BP_cart_control_STMSTT.h"
#include "_coder_CR3BP_cart_control_STMSTT_mex.h"
#include "CR3BP_cart_control_STMSTT_terminate.h"
#include "_coder_CR3BP_cart_control_STMSTT_api.h"
#include "CR3BP_cart_control_STMSTT_initialize.h"
#include "CR3BP_cart_control_STMSTT_data.h"

/* Function Declarations */
static void c_CR3BP_cart_control_STMSTT_mex(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[5]);

/* Function Definitions */
static void c_CR3BP_cart_control_STMSTT_mex(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[5])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        25, "CR3BP_cart_control_STMSTT");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 25,
                        "CR3BP_cart_control_STMSTT");
  }

  /* Call the function. */
  CR3BP_cart_control_STMSTT_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(CR3BP_cart_control_STMSTT_atexit);

  /* Module initialization. */
  CR3BP_cart_control_STMSTT_initialize();

  /* Dispatch the entry-point. */
  c_CR3BP_cart_control_STMSTT_mex(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  CR3BP_cart_control_STMSTT_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_CR3BP_cart_control_STMSTT_mex.c) */
