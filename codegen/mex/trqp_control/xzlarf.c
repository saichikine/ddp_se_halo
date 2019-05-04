/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzlarf.c
 *
 * Code generation for function 'xzlarf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "xzlarf.h"
#include "xgerc.h"
#include "xgemv.h"
#include "eml_int_forloop_overflow_check.h"
#include "trqp_control_data.h"

/* Variable Definitions */
static emlrtRSInfo bd_emlrtRSI = { 50, /* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 68, /* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 75, /* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 103,/* lineNo */
  "ilazlc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

/* Function Declarations */
static int32_T b_ilazlc(const emlrtStack *sp, int32_T m, int32_T n, const
  creal_T A[9], int32_T ia0, int32_T lda);
static int32_T ilazlc(const emlrtStack *sp, int32_T m, int32_T n, const real_T
                      A[9], int32_T ia0, int32_T lda);

/* Function Definitions */
static int32_T b_ilazlc(const emlrtStack *sp, int32_T m, int32_T n, const
  creal_T A[9], int32_T ia0, int32_T lda)
{
  int32_T j;
  boolean_T exitg2;
  int32_T coltop;
  int32_T colbottom;
  int32_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  j = n;
  exitg2 = false;
  while ((!exitg2) && (j > 0)) {
    coltop = ia0 + (j - 1) * lda;
    colbottom = (coltop + m) - 1;
    st.site = &ed_emlrtRSI;
    if ((coltop <= colbottom) && (colbottom > 2147483646)) {
      b_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    do {
      exitg1 = 0;
      if (coltop <= colbottom) {
        if ((A[coltop - 1].re != 0.0) || (A[coltop - 1].im != 0.0)) {
          exitg1 = 1;
        } else {
          coltop++;
        }
      } else {
        j--;
        exitg1 = 2;
      }
    } while (exitg1 == 0);

    if (exitg1 == 1) {
      exitg2 = true;
    }
  }

  return j;
}

static int32_T ilazlc(const emlrtStack *sp, int32_T m, int32_T n, const real_T
                      A[9], int32_T ia0, int32_T lda)
{
  int32_T j;
  boolean_T exitg2;
  int32_T coltop;
  int32_T colbottom;
  int32_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  j = n;
  exitg2 = false;
  while ((!exitg2) && (j > 0)) {
    coltop = ia0 + (j - 1) * lda;
    colbottom = (coltop + m) - 1;
    st.site = &ed_emlrtRSI;
    if ((coltop <= colbottom) && (colbottom > 2147483646)) {
      b_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    do {
      exitg1 = 0;
      if (coltop <= colbottom) {
        if (A[coltop - 1] != 0.0) {
          exitg1 = 1;
        } else {
          coltop++;
        }
      } else {
        j--;
        exitg1 = 2;
      }
    } while (exitg1 == 0);

    if (exitg1 == 1) {
      exitg2 = true;
    }
  }

  return j;
}

void b_xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0, const
              creal_T tau, creal_T C[9], int32_T ic0, creal_T work[3])
{
  int32_T lastv;
  int32_T lastc;
  creal_T b_tau;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if ((tau.re != 0.0) || (tau.im != 0.0)) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && ((C[lastc - 2].re == 0.0) && (C[lastc - 2].im == 0.0)))
    {
      lastv--;
      lastc--;
    }

    st.site = &bd_emlrtRSI;
    lastc = b_ilazlc(&st, lastv, n, C, ic0, 3);
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    st.site = &cd_emlrtRSI;
    b_xgemv(&st, lastv, lastc, C, ic0, C, iv0, work);
    b_tau.re = -tau.re;
    b_tau.im = -tau.im;
    st.site = &dd_emlrtRSI;
    b_xgerc(&st, lastv, lastc, b_tau, iv0, work, C, ic0);
  }
}

void xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0, real_T tau,
            real_T C[9], int32_T ic0, real_T work[3])
{
  int32_T lastv;
  int32_T lastc;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (tau != 0.0) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    st.site = &bd_emlrtRSI;
    lastc = ilazlc(&st, lastv, n, C, ic0, 3);
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    st.site = &cd_emlrtRSI;
    xgemv(&st, lastv, lastc, C, ic0, C, iv0, work);
    st.site = &dd_emlrtRSI;
    xgerc(&st, lastv, lastc, -tau, iv0, work, C, ic0);
  }
}

/* End of code generation (xzlarf.c) */
