/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzlanhs.c
 *
 * Code generation for function 'xzlanhs'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "xzlanhs.h"
#include "eml_int_forloop_overflow_check.h"
#include "trqp_control_data.h"

/* Variable Definitions */
static emlrtRSInfo fg_emlrtRSI = { 20, /* lineNo */
  "xzlanhs",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlanhs.m"/* pathName */
};

static emlrtRSInfo gg_emlrtRSI = { 21, /* lineNo */
  "xzlanhs",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlanhs.m"/* pathName */
};

static emlrtRSInfo hg_emlrtRSI = { 57, /* lineNo */
  "xzlanhs",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlanhs.m"/* pathName */
};

/* Function Definitions */
real_T xzlanhs(const emlrtStack *sp, const creal_T A[9], int32_T ilo, int32_T
               ihi)
{
  real_T f;
  real_T scale;
  real_T sumsq;
  boolean_T firstNonZero;
  int32_T j;
  int32_T b;
  int32_T i;
  real_T re;
  real_T im;
  real_T temp1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  f = 0.0;
  if (ilo <= ihi) {
    scale = 0.0;
    sumsq = 0.0;
    firstNonZero = true;
    st.site = &fg_emlrtRSI;
    if ((ilo <= ihi) && (ihi > 2147483646)) {
      b_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    for (j = ilo; j <= ihi; j++) {
      b = j + 1;
      if (ihi < j + 1) {
        b = ihi;
      }

      st.site = &gg_emlrtRSI;
      if ((ilo <= b) && (b > 2147483646)) {
        b_st.site = &bb_emlrtRSI;
        check_forloop_overflow_error(&b_st, true);
      }

      for (i = ilo; i <= b; i++) {
        re = A[(i + 3 * (j - 1)) - 1].re;
        im = A[(i + 3 * (j - 1)) - 1].im;
        if (re != 0.0) {
          temp1 = muDoubleScalarAbs(re);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = temp1;
            firstNonZero = false;
          } else if (scale < temp1) {
            re = scale / temp1;
            sumsq = 1.0 + sumsq * re * re;
            scale = temp1;
          } else {
            re = temp1 / scale;
            sumsq += re * re;
          }
        }

        if (im != 0.0) {
          temp1 = muDoubleScalarAbs(im);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = temp1;
            firstNonZero = false;
          } else if (scale < temp1) {
            re = scale / temp1;
            sumsq = 1.0 + sumsq * re * re;
            scale = temp1;
          } else {
            re = temp1 / scale;
            sumsq += re * re;
          }
        }
      }
    }

    st.site = &hg_emlrtRSI;
    f = scale * muDoubleScalarSqrt(sumsq);
  }

  return f;
}

/* End of code generation (xzlanhs.c) */
