/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xnrm2.c
 *
 * Code generation for function 'xnrm2'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "xnrm2.h"
#include "eml_int_forloop_overflow_check.h"
#include "trqp_multipliers_data.h"

/* Variable Definitions */
static emlrtRSInfo hd_emlrtRSI = { 23, /* lineNo */
  "xnrm2",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xnrm2.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 38, /* lineNo */
  "xnrm2",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xnrm2.m"/* pathName */
};

/* Function Definitions */
real_T b_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[3])
{
  real_T y;
  real_T scale;
  int32_T kend;
  int32_T k;
  real_T absxk;
  real_T t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = muDoubleScalarAbs(x[1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = n + 1;
      b_st.site = &id_emlrtRSI;
      if ((2 <= n + 1) && (n + 1 > 2147483646)) {
        c_st.site = &bb_emlrtRSI;
        check_forloop_overflow_error(&c_st, true);
      }

      for (k = 2; k <= kend; k++) {
        absxk = muDoubleScalarAbs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = 1.0 + y * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * muDoubleScalarSqrt(y);
    }
  }

  return y;
}

real_T c_xnrm2(const emlrtStack *sp, int32_T n, const creal_T x[36], int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  int32_T k;
  real_T absxk;
  real_T t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = muDoubleScalarHypot(x[ix0 - 1].re, x[ix0 - 1].im);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      b_st.site = &id_emlrtRSI;
      if ((ix0 <= kend) && (kend > 2147483646)) {
        c_st.site = &bb_emlrtRSI;
        check_forloop_overflow_error(&c_st, true);
      }

      for (k = ix0; k <= kend; k++) {
        absxk = muDoubleScalarAbs(x[k - 1].re);
        if (absxk > scale) {
          t = scale / absxk;
          y = 1.0 + y * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }

        absxk = muDoubleScalarAbs(x[k - 1].im);
        if (absxk > scale) {
          t = scale / absxk;
          y = 1.0 + y * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * muDoubleScalarSqrt(y);
    }
  }

  return y;
}

real_T xnrm2(const emlrtStack *sp, int32_T n, const real_T x[36], int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  int32_T k;
  real_T absxk;
  real_T t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = muDoubleScalarAbs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      b_st.site = &id_emlrtRSI;
      if ((ix0 <= kend) && (kend > 2147483646)) {
        c_st.site = &bb_emlrtRSI;
        check_forloop_overflow_error(&c_st, true);
      }

      for (k = ix0; k <= kend; k++) {
        absxk = muDoubleScalarAbs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = 1.0 + y * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * muDoubleScalarSqrt(y);
    }
  }

  return y;
}

/* End of code generation (xnrm2.c) */
