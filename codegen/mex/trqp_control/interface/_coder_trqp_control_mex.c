/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_trqp_control_mex.c
 *
 * Code generation for function '_coder_trqp_control_mex'
 *
 */

/* Include files */
#include "trqp_control.h"
#include "_coder_trqp_control_mex.h"
#include "trqp_control_terminate.h"
#include "_coder_trqp_control_api.h"
#include "trqp_control_initialize.h"
#include "trqp_control_data.h"

/* Function Declarations */
static void trqp_control_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T
  nrhs, const mxArray *prhs[4]);

/* Function Definitions */
static void trqp_control_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T
  nrhs, const mxArray *prhs[4])
{
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        12, "trqp_control");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "trqp_control");
  }

  /* Call the function. */
  trqp_control_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(trqp_control_atexit);

  /* Module initialization. */
  trqp_control_initialize();

  /* Dispatch the entry-point. */
  trqp_control_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  trqp_control_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_trqp_control_mex.c) */
