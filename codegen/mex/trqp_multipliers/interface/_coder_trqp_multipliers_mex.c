/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_trqp_multipliers_mex.c
 *
 * Code generation for function '_coder_trqp_multipliers_mex'
 *
 */

/* Include files */
#include "trqp_multipliers.h"
#include "_coder_trqp_multipliers_mex.h"
#include "trqp_multipliers_terminate.h"
#include "_coder_trqp_multipliers_api.h"
#include "trqp_multipliers_initialize.h"
#include "trqp_multipliers_data.h"

/* Function Declarations */
static void trqp_multipliers_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T
  nrhs, const mxArray *prhs[4]);

/* Function Definitions */
static void trqp_multipliers_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T
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
                        16, "trqp_multipliers");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 16,
                        "trqp_multipliers");
  }

  /* Call the function. */
  trqp_multipliers_api(prhs, nlhs, outputs);

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
  mexAtExit(trqp_multipliers_atexit);

  /* Module initialization. */
  trqp_multipliers_initialize();

  /* Dispatch the entry-point. */
  trqp_multipliers_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  trqp_multipliers_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_trqp_multipliers_mex.c) */
