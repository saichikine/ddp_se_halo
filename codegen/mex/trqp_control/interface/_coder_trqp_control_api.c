/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_trqp_control_api.c
 *
 * Code generation for function '_coder_trqp_control_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "_coder_trqp_control_api.h"
#include "trqp_control_data.h"

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const creal_T u
  [9]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *H, const
  char_T *identifier))[9];
static const mxArray *c_emlrt_marshallOut(const boolean_T u);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[9];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *g, const
  char_T *identifier))[3];
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const creal_T u[3]);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *delta,
  const char_T *identifier);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[9];
static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];
static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const creal_T u
  [9])
{
  const mxArray *y;
  const mxArray *m16;
  static const int32_T iv15[2] = { 3, 3 };

  y = NULL;
  m16 = emlrtCreateNumericArray(2, iv15, mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b(sp, m16, (void *)&u[0], 8);
  emlrtAssign(&y, m16);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *H, const
  char_T *identifier))[9]
{
  real_T (*y)[9];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(H), &thisId);
  emlrtDestroyArray(&H);
  return y;
}
  static const mxArray *c_emlrt_marshallOut(const boolean_T u)
{
  const mxArray *y;
  const mxArray *m17;
  y = NULL;
  m17 = emlrtCreateLogicalScalar(u);
  emlrtAssign(&y, m17);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[9]
{
  real_T (*y)[9];
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *g,
  const char_T *identifier))[3]
{
  real_T (*y)[3];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(g), &thisId);
  emlrtDestroyArray(&g);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const creal_T u[3])
{
  const mxArray *y;
  const mxArray *m15;
  static const int32_T iv14[1] = { 3 };

  y = NULL;
  m15 = emlrtCreateNumericArray(1, iv14, mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b(sp, m15, (void *)&u[0], 8);
  emlrtAssign(&y, m15);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *delta,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(delta), &thisId);
  emlrtDestroyArray(&delta);
  return y;
}

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[9]
{
  real_T (*ret)[9];
  static const int32_T dims[2] = { 3, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[9])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  real_T (*ret)[3];
  static const int32_T dims[1] = { 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void trqp_control_api(const mxArray *prhs[4], int32_T nlhs, const mxArray *plhs
                      [3])
{
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  real_T (*H)[9];
  real_T (*g)[3];
  real_T delta;
  real_T (*M)[9];
  creal_T s_out[3];
  creal_T H_out[9];
  boolean_T bool_TRQP_failure;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  prhs_copy_idx_0 = emlrtProtectR2012b(prhs[0], 0, false, -1);
  prhs_copy_idx_1 = emlrtProtectR2012b(prhs[1], 1, false, -1);

  /* Marshall function inputs */
  H = c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "H");
  g = e_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1), "g");
  delta = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "delta");
  M = c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "M");

  /* Invoke the target function */
  trqp_control(&st, *H, *g, delta, *M, s_out, H_out, &bool_TRQP_failure);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, s_out);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(&st, H_out);
  }

  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(bool_TRQP_failure);
  }
}

/* End of code generation (_coder_trqp_control_api.c) */
