/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "mldivide.h"
#include "xtrsm.h"
#include "warning.h"
#include "xgetrf.h"

/* Variable Definitions */
static emlrtRSInfo pf_emlrtRSI = { 20, /* lineNo */
  "mldivide",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

static emlrtRSInfo qf_emlrtRSI = { 42, /* lineNo */
  "mldiv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

static emlrtRSInfo rf_emlrtRSI = { 67, /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo sf_emlrtRSI = { 109,/* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo tf_emlrtRSI = { 107,/* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo uf_emlrtRSI = { 150,/* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo vf_emlrtRSI = { 152,/* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo yf_emlrtRSI = { 90, /* lineNo */
  "warn_singular",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

/* Function Definitions */
void b_mldivide(const emlrtStack *sp, const creal_T A[36], creal_T B[6])
{
  creal_T b_A[36];
  int32_T ipiv[6];
  int32_T info;
  real_T temp_re;
  real_T temp_im;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &qf_emlrtRSI;
  c_st.site = &rf_emlrtRSI;
  memcpy(&b_A[0], &A[0], 36U * sizeof(creal_T));
  d_st.site = &tf_emlrtRSI;
  xgetrf(&d_st, b_A, ipiv, &info);
  if (info > 0) {
    d_st.site = &sf_emlrtRSI;
    e_st.site = &yf_emlrtRSI;
    warning(&e_st);
  }

  for (info = 0; info < 5; info++) {
    if (ipiv[info] != info + 1) {
      temp_re = B[info].re;
      temp_im = B[info].im;
      B[info] = B[ipiv[info] - 1];
      B[ipiv[info] - 1].re = temp_re;
      B[ipiv[info] - 1].im = temp_im;
    }
  }

  d_st.site = &uf_emlrtRSI;
  xtrsm(b_A, B);
  d_st.site = &vf_emlrtRSI;
  b_xtrsm(b_A, B);
}

void mldivide(const emlrtStack *sp, const creal_T A[36], const real_T B[6],
              creal_T Y[6])
{
  creal_T b_A[36];
  int32_T ipiv[6];
  int32_T i;
  real_T temp_re;
  real_T temp_im;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &qf_emlrtRSI;
  c_st.site = &rf_emlrtRSI;
  memcpy(&b_A[0], &A[0], 36U * sizeof(creal_T));
  d_st.site = &tf_emlrtRSI;
  xgetrf(&d_st, b_A, ipiv, &i);
  if (i > 0) {
    d_st.site = &sf_emlrtRSI;
    e_st.site = &yf_emlrtRSI;
    warning(&e_st);
  }

  for (i = 0; i < 6; i++) {
    Y[i].re = B[i];
    Y[i].im = 0.0;
  }

  for (i = 0; i < 5; i++) {
    if (ipiv[i] != i + 1) {
      temp_re = Y[i].re;
      temp_im = Y[i].im;
      Y[i] = Y[ipiv[i] - 1];
      Y[ipiv[i] - 1].re = temp_re;
      Y[ipiv[i] - 1].im = temp_im;
    }
  }

  d_st.site = &uf_emlrtRSI;
  xtrsm(b_A, Y);
  d_st.site = &vf_emlrtRSI;
  b_xtrsm(b_A, Y);
}

/* End of code generation (mldivide.c) */
