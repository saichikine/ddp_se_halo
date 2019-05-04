/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgetrf.c
 *
 * Code generation for function 'xgetrf'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "xgetrf.h"
#include "eml_int_forloop_overflow_check.h"
#include "trqp_multipliers_data.h"

/* Variable Definitions */
static emlrtRSInfo wf_emlrtRSI = { 52, /* lineNo */
  "xgeru",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru.m"/* pathName */
};

static emlrtRSInfo xf_emlrtRSI = { 15, /* lineNo */
  "xgeru",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgeru.m"/* pathName */
};

/* Function Definitions */
void xgetrf(const emlrtStack *sp, creal_T A[36], int32_T ipiv[6], int32_T *info)
{
  int32_T iy;
  int32_T j;
  int32_T b;
  int32_T jj;
  int32_T jp1j;
  int32_T n;
  int32_T jA;
  int32_T ix;
  real_T smax;
  int32_T k;
  real_T s;
  real_T A_re;
  real_T A_im;
  real_T b_A_re;
  real_T b_A_im;
  real_T brm;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ub_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  for (iy = 0; iy < 6; iy++) {
    ipiv[iy] = 1 + iy;
  }

  *info = 0;
  for (j = 0; j < 5; j++) {
    b = j * 7;
    jj = j * 7;
    jp1j = b + 2;
    n = 6 - j;
    b_st.site = &vb_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    jA = 0;
    ix = b;
    smax = muDoubleScalarAbs(A[jj].re) + muDoubleScalarAbs(A[jj].im);
    d_st.site = &ac_emlrtRSI;
    for (k = 2; k <= n; k++) {
      ix++;
      s = muDoubleScalarAbs(A[ix].re) + muDoubleScalarAbs(A[ix].im);
      if (s > smax) {
        jA = k - 1;
        smax = s;
      }
    }

    if ((A[jj + jA].re != 0.0) || (A[jj + jA].im != 0.0)) {
      if (jA != 0) {
        iy = j + jA;
        ipiv[j] = iy + 1;
        ix = j;
        for (k = 0; k < 6; k++) {
          smax = A[ix].re;
          s = A[ix].im;
          A[ix] = A[iy];
          A[iy].re = smax;
          A[iy].im = s;
          ix += 6;
          iy += 6;
        }
      }

      iy = (jj - j) + 6;
      b_st.site = &wb_emlrtRSI;
      for (jA = jp1j; jA <= iy; jA++) {
        A_re = A[jA - 1].re;
        A_im = A[jA - 1].im;
        b_A_re = A[jj].re;
        b_A_im = A[jj].im;
        if (b_A_im == 0.0) {
          if (A_im == 0.0) {
            A[jA - 1].re = A_re / b_A_re;
            A[jA - 1].im = 0.0;
          } else if (A_re == 0.0) {
            A[jA - 1].re = 0.0;
            A[jA - 1].im = A_im / b_A_re;
          } else {
            A[jA - 1].re = A_re / b_A_re;
            A[jA - 1].im = A_im / b_A_re;
          }
        } else if (b_A_re == 0.0) {
          if (A_re == 0.0) {
            A[jA - 1].re = A_im / b_A_im;
            A[jA - 1].im = 0.0;
          } else if (A_im == 0.0) {
            A[jA - 1].re = 0.0;
            A[jA - 1].im = -(A_re / b_A_im);
          } else {
            A[jA - 1].re = A_im / b_A_im;
            A[jA - 1].im = -(A_re / b_A_im);
          }
        } else {
          brm = muDoubleScalarAbs(b_A_re);
          smax = muDoubleScalarAbs(b_A_im);
          if (brm > smax) {
            s = b_A_im / b_A_re;
            smax = b_A_re + s * b_A_im;
            A[jA - 1].re = (A_re + s * A_im) / smax;
            A[jA - 1].im = (A_im - s * A_re) / smax;
          } else if (smax == brm) {
            if (b_A_re > 0.0) {
              s = 0.5;
            } else {
              s = -0.5;
            }

            if (b_A_im > 0.0) {
              smax = 0.5;
            } else {
              smax = -0.5;
            }

            A[jA - 1].re = (A_re * s + A_im * smax) / brm;
            A[jA - 1].im = (A_im * s - A_re * smax) / brm;
          } else {
            s = b_A_re / b_A_im;
            smax = b_A_im + s * b_A_re;
            A[jA - 1].re = (s * A_re + A_im) / smax;
            A[jA - 1].im = (s * A_im - A_re) / smax;
          }
        }
      }
    } else {
      *info = j + 1;
    }

    n = 4 - j;
    iy = b + 6;
    b_st.site = &xb_emlrtRSI;
    c_st.site = &wf_emlrtRSI;
    d_st.site = &xf_emlrtRSI;
    jA = jj + 8;
    e_st.site = &ec_emlrtRSI;
    for (k = 0; k <= n; k++) {
      if ((A[iy].re != 0.0) || (A[iy].im != 0.0)) {
        smax = -A[iy].re - A[iy].im * 0.0;
        s = A[iy].re * 0.0 + -A[iy].im;
        ix = jj + 1;
        b = (jA - j) + 4;
        e_st.site = &fc_emlrtRSI;
        if ((jA <= b) && (b > 2147483646)) {
          f_st.site = &bb_emlrtRSI;
          check_forloop_overflow_error(&f_st, true);
        }

        for (jp1j = jA; jp1j <= b; jp1j++) {
          A_im = A[ix].re * s + A[ix].im * smax;
          A[jp1j - 1].re += A[ix].re * smax - A[ix].im * s;
          A[jp1j - 1].im += A_im;
          ix++;
        }
      }

      iy += 6;
      jA += 6;
    }
  }

  if ((*info == 0) && ((!(A[35].re != 0.0)) && (!(A[35].im != 0.0)))) {
    *info = 6;
  }
}

/* End of code generation (xgetrf.c) */
