/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_CR3BP_cart_control_STMSTT_api.c
 *
 * Code generation for function '_coder_CR3BP_cart_control_STMSTT_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CR3BP_cart_control_STMSTT.h"
#include "_coder_CR3BP_cart_control_STMSTT_api.h"
#include "CR3BP_cart_control_STMSTT_data.h"

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier))[1110];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[1110];
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *t, const
  char_T *identifier);
static const mxArray *emlrt_marshallOut(const real_T u[1110]);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1110];

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier))[1110]
{
  real_T (*y)[1110];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(X), &thisId);
  emlrtDestroyArray(&X);
  return y;
}
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[1110]
{
  real_T (*y)[1110];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *t, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(t), &thisId);
  emlrtDestroyArray(&t);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[1110])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[1] = { 0 };

  static const int32_T iv1[1] = { 1110 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m0, iv1, 1);
  emlrtAssign(&y, m0);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1110]
{
  real_T (*ret)[1110];
  static const int32_T dims[1] = { 1110 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[1110])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  void CR3BP_cart_control_STMSTT_api(const mxArray * const prhs[5], int32_T nlhs,
  const mxArray *plhs[1])
{
  real_T (*Xdot)[1110];
  real_T t;
  real_T (*X)[1110];
  real_T mu;
  real_T c;
  real_T Tmax;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  Xdot = (real_T (*)[1110])mxMalloc(sizeof(real_T [1110]));

  /* Marshall function inputs */
  t = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t");
  X = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "X");
  mu = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "mu");
  c = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "c");
  Tmax = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "Tmax");

  /* Invoke the target function */
  CR3BP_cart_control_STMSTT(&st, t, *X, mu, c, Tmax, *Xdot);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*Xdot);
}

/* End of code generation (_coder_CR3BP_cart_control_STMSTT_api.c) */
