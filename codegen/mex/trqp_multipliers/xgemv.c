/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgemv.c
 *
 * Code generation for function 'xgemv'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "xgemv.h"
#include "eml_int_forloop_overflow_check.h"
#include "trqp_multipliers_data.h"

/* Variable Definitions */
static emlrtRSInfo td_emlrtRSI = { 71, /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

static emlrtRSInfo ud_emlrtRSI = { 74, /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

/* Function Definitions */
void b_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const creal_T A[36],
             int32_T ia0, const creal_T x[36], int32_T ix0, creal_T y[6])
{
  int32_T iy;
  int32_T b;
  int32_T iac;
  int32_T ix;
  real_T c_re;
  real_T c_im;
  int32_T b_b;
  int32_T ia;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if ((m == 0) || (n == 0)) {
  } else {
    b_st.site = &nd_emlrtRSI;
    if ((1 <= n) && (n > 2147483646)) {
      c_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (iy = 0; iy < n; iy++) {
      y[iy].re = 0.0;
      y[iy].im = 0.0;
    }

    iy = 0;
    b = ia0 + 6 * (n - 1);
    b_st.site = &td_emlrtRSI;
    if ((ia0 <= b) && (b > 2147483641)) {
      c_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (iac = ia0; iac <= b; iac += 6) {
      ix = ix0 - 1;
      c_re = 0.0;
      c_im = 0.0;
      b_b = (iac + m) - 1;
      b_st.site = &ud_emlrtRSI;
      if ((iac <= b_b) && (b_b > 2147483646)) {
        c_st.site = &bb_emlrtRSI;
        check_forloop_overflow_error(&c_st, true);
      }

      for (ia = iac; ia <= b_b; ia++) {
        c_re += A[ia - 1].re * x[ix].re + A[ia - 1].im * x[ix].im;
        c_im += A[ia - 1].re * x[ix].im - A[ia - 1].im * x[ix].re;
        ix++;
      }

      y[iy].re += c_re - 0.0 * c_im;
      y[iy].im += c_im + 0.0 * c_re;
      iy++;
    }
  }
}

void xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[36],
           int32_T ia0, const real_T x[36], int32_T ix0, real_T y[6])
{
  int32_T iy;
  int32_T b;
  int32_T iac;
  int32_T ix;
  real_T c;
  int32_T b_b;
  int32_T ia;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if ((m == 0) || (n == 0)) {
  } else {
    b_st.site = &nd_emlrtRSI;
    if ((1 <= n) && (n > 2147483646)) {
      c_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    if (0 <= n - 1) {
      memset(&y[0], 0, (uint32_T)(n * (int32_T)sizeof(real_T)));
    }

    iy = 0;
    b = ia0 + 6 * (n - 1);
    b_st.site = &td_emlrtRSI;
    if ((ia0 <= b) && (b > 2147483641)) {
      c_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (iac = ia0; iac <= b; iac += 6) {
      ix = ix0;
      c = 0.0;
      b_b = (iac + m) - 1;
      b_st.site = &ud_emlrtRSI;
      if ((iac <= b_b) && (b_b > 2147483646)) {
        c_st.site = &bb_emlrtRSI;
        check_forloop_overflow_error(&c_st, true);
      }

      for (ia = iac; ia <= b_b; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[iy] += c;
      iy++;
    }
  }
}

/* End of code generation (xgemv.c) */
