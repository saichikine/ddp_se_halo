/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xhseqr.c
 *
 * Code generation for function 'xhseqr'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "xhseqr.h"
#include "xdhseqr.h"
#include "xzhseqr.h"

/* Variable Definitions */
static emlrtRSInfo fe_emlrtRSI = { 21, /* lineNo */
  "xhseqr",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xhseqr.m"/* pathName */
};

static emlrtRSInfo ge_emlrtRSI = { 11, /* lineNo */
  "xdhseqr",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

static emlrtRSInfo jg_emlrtRSI = { 23, /* lineNo */
  "xhseqr",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xhseqr.m"/* pathName */
};

static emlrtRSInfo kg_emlrtRSI = { 15, /* lineNo */
  "xzhseqr",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

/* Function Definitions */
int32_T b_xhseqr(const emlrtStack *sp, creal_T h[36], creal_T z[36])
{
  int32_T info;
  int32_T istart;
  int32_T j;
  int32_T i;
  int32_T i3;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &kg_emlrtRSI;
  info = eml_zlahqr(&b_st, h, z);
  istart = 4;
  for (j = 0; j < 3; j++) {
    for (i = istart; i < 7; i++) {
      i3 = (i + 6 * j) - 1;
      h[i3].re = 0.0;
      h[i3].im = 0.0;
    }

    istart++;
  }

  return info;
}

int32_T xhseqr(const emlrtStack *sp, real_T h[36], real_T z[36])
{
  int32_T info;
  int32_T istart;
  int32_T j;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fe_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &ge_emlrtRSI;
  info = eml_dlahqr(&b_st, h, z);
  istart = 4;
  for (j = 0; j < 3; j++) {
    if (istart <= 6) {
      memset(&h[(j * 6 + istart) + -1], 0, (uint32_T)((7 - istart) * (int32_T)
              sizeof(real_T)));
    }

    istart++;
  }

  return info;
}

/* End of code generation (xhseqr.c) */
