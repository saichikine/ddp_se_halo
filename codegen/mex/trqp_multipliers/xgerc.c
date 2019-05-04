/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgerc.c
 *
 * Code generation for function 'xgerc'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "xgerc.h"
#include "eml_int_forloop_overflow_check.h"
#include "trqp_multipliers_data.h"

/* Function Definitions */
void b_xgerc(const emlrtStack *sp, int32_T m, int32_T n, const creal_T alpha1,
             int32_T ix0, const creal_T y[6], creal_T A[36], int32_T ia0)
{
  int32_T jA;
  int32_T jy;
  int32_T j;
  real_T temp_re;
  real_T temp_im;
  int32_T ix;
  int32_T b;
  int32_T ijA;
  real_T A_im;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &ig_emlrtRSI;
  if ((!(alpha1.re == 0.0)) || (!(alpha1.im == 0.0))) {
    jA = ia0;
    jy = 0;
    c_st.site = &ec_emlrtRSI;
    if ((1 <= n) && (n > 2147483646)) {
      d_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&d_st, true);
    }

    for (j = 0; j < n; j++) {
      if ((y[jy].re != 0.0) || (y[jy].im != 0.0)) {
        temp_re = y[jy].re * alpha1.re + y[jy].im * alpha1.im;
        temp_im = y[jy].re * alpha1.im - y[jy].im * alpha1.re;
        ix = ix0;
        b = (m + jA) - 1;
        c_st.site = &fc_emlrtRSI;
        if ((jA <= b) && (b > 2147483646)) {
          d_st.site = &bb_emlrtRSI;
          check_forloop_overflow_error(&d_st, true);
        }

        for (ijA = jA; ijA <= b; ijA++) {
          A_im = A[ix - 1].re * temp_im + A[ix - 1].im * temp_re;
          A[ijA - 1].re += A[ix - 1].re * temp_re - A[ix - 1].im * temp_im;
          A[ijA - 1].im += A_im;
          ix++;
        }
      }

      jy++;
      jA += 6;
    }
  }
}

void xgerc(const emlrtStack *sp, int32_T m, int32_T n, real_T alpha1, int32_T
           ix0, const real_T y[6], real_T A[36], int32_T ia0)
{
  int32_T jA;
  int32_T jy;
  int32_T j;
  real_T temp;
  int32_T ix;
  int32_T b;
  int32_T ijA;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &od_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &cc_emlrtRSI;
  c_st.site = &dc_emlrtRSI;
  if (!(alpha1 == 0.0)) {
    jA = ia0;
    jy = 0;
    d_st.site = &ec_emlrtRSI;
    if ((1 <= n) && (n > 2147483646)) {
      e_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&e_st, true);
    }

    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        b = (m + jA) - 1;
        d_st.site = &fc_emlrtRSI;
        if ((jA <= b) && (b > 2147483646)) {
          e_st.site = &bb_emlrtRSI;
          check_forloop_overflow_error(&e_st, true);
        }

        for (ijA = jA; ijA <= b; ijA++) {
          A[ijA - 1] += A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 6;
    }
  }
}

/* End of code generation (xgerc.c) */
