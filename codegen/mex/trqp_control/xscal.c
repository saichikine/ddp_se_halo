/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xscal.c
 *
 * Code generation for function 'xscal'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "xscal.h"
#include "eml_int_forloop_overflow_check.h"
#include "trqp_control_data.h"

/* Function Definitions */
void b_xscal(const emlrtStack *sp, int32_T n, const creal_T a, creal_T x[9],
             int32_T ix0)
{
  int32_T b;
  int32_T k;
  real_T x_re;
  real_T x_im;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = (ix0 + n) - 1;
  b_st.site = &nb_emlrtRSI;
  if ((ix0 <= b) && (b > 2147483646)) {
    c_st.site = &bb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (k = ix0; k <= b; k++) {
    x_re = x[k - 1].re;
    x_im = x[k - 1].im;
    x[k - 1].re = a.re * x_re - a.im * x_im;
    x[k - 1].im = a.re * x_im + a.im * x_re;
  }
}

void c_xscal(const emlrtStack *sp, int32_T n, const creal_T a, creal_T x[9],
             int32_T ix0)
{
  int32_T b;
  int32_T k;
  real_T x_re;
  real_T x_im;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = ix0 + 3 * (n - 1);
  b_st.site = &nb_emlrtRSI;
  if ((ix0 <= b) && (b > 2147483644)) {
    c_st.site = &bb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (k = ix0; k <= b; k += 3) {
    x_re = x[k - 1].re;
    x_im = x[k - 1].im;
    x[k - 1].re = a.re * x_re - a.im * x_im;
    x[k - 1].im = a.re * x_im + a.im * x_re;
  }
}

void d_xscal(const emlrtStack *sp, const creal_T a, creal_T x[9], int32_T ix0)
{
  int32_T b;
  int32_T k;
  real_T x_re;
  real_T x_im;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = ix0 + 2;
  b_st.site = &nb_emlrtRSI;
  if ((ix0 <= ix0 + 2) && (ix0 + 2 > 2147483646)) {
    c_st.site = &bb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (k = ix0; k <= b; k++) {
    x_re = x[k - 1].re;
    x_im = x[k - 1].im;
    x[k - 1].re = a.re * x_re - a.im * x_im;
    x[k - 1].im = a.re * x_im + a.im * x_re;
  }
}

void xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[3])
{
  int32_T b;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = n + 1;
  b_st.site = &nb_emlrtRSI;
  if ((2 <= n + 1) && (n + 1 > 2147483646)) {
    c_st.site = &bb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (k = 2; k <= b; k++) {
    x[k - 1] *= a;
  }
}

/* End of code generation (xscal.c) */
