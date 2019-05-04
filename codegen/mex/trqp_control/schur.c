/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * schur.c
 *
 * Code generation for function 'schur'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "schur.h"
#include "xdlanv2.h"
#include "warning.h"
#include "xhseqr.h"
#include "xgehrd.h"
#include "trqp_control_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo wb_emlrtRSI = { 39, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 72, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 73, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 74, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo me_emlrtRSI = { 15, /* lineNo */
  "rsf2csf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\rsf2csf.m"/* pathName */
};

/* Function Definitions */
void schur(const emlrtStack *sp, const real_T A[9], creal_T V[9], creal_T T[9])
{
  boolean_T p;
  int32_T k;
  real_T b_A[9];
  real_T tau[2];
  real_T Vr[9];
  ptrdiff_t info_t;
  int32_T info;
  boolean_T b_p;
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'o', 'r', 'g', 'h', 'r' };

  int32_T m;
  int32_T mm1;
  int32_T i0;
  real_T r;
  int32_T b_tmp_tmp;
  real_T b;
  real_T s;
  real_T t1_re;
  real_T t1_im;
  real_T rt1r;
  real_T rt1i;
  real_T rt2r;
  real_T mu1_im;
  real_T mu1_re;
  real_T sn;
  int32_T re_tmp;
  int32_T b_re_tmp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  p = true;
  for (k = 0; k < 9; k++) {
    if (p && ((!muDoubleScalarIsInf(A[k])) && (!muDoubleScalarIsNaN(A[k])))) {
      p = true;
    } else {
      p = false;
    }
  }

  if (!p) {
    for (k = 0; k < 9; k++) {
      V[k].re = rtNaN;
      V[k].im = 0.0;
    }

    st.site = &wb_emlrtRSI;
    b_st.site = &dc_emlrtRSI;
    V[2].re = 0.0;
    V[2].im = 0.0;
    for (k = 0; k < 9; k++) {
      T[k].re = rtNaN;
      T[k].im = 0.0;
    }
  } else {
    memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
    st.site = &xb_emlrtRSI;
    xgehrd(&st, b_A, tau);
    st.site = &yb_emlrtRSI;
    memcpy(&Vr[0], &b_A[0], 9U * sizeof(real_T));
    b_st.site = &hd_emlrtRSI;
    info_t = LAPACKE_dorghr(102, (ptrdiff_t)3, (ptrdiff_t)1, (ptrdiff_t)3, &Vr[0],
      (ptrdiff_t)3, &tau[0]);
    info = (int32_T)info_t;
    c_st.site = &md_emlrtRSI;
    if (info != 0) {
      p = true;
      b_p = false;
      if (info == -5) {
        b_p = true;
      } else {
        if (info == -7) {
          b_p = true;
        }
      }

      if (!b_p) {
        if (info == -1010) {
          emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI, "MATLAB:nomem",
            "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI,
            "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, info);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      for (k = 0; k < 9; k++) {
        Vr[k] = rtNaN;
      }
    }

    st.site = &ac_emlrtRSI;
    info = xhseqr(&st, b_A, Vr);
    st.site = &bc_emlrtRSI;
    b_st.site = &me_emlrtRSI;
    for (k = 0; k < 9; k++) {
      T[k].re = b_A[k];
      T[k].im = 0.0;
      V[k].re = Vr[k];
      V[k].im = 0.0;
    }

    for (m = 1; m >= 0; m--) {
      mm1 = m + 1;
      k = m + 3 * m;
      i0 = k + 1;
      if (b_A[i0] != 0.0) {
        r = b_A[k];
        b_tmp_tmp = 3 * (m + 1);
        k = m + b_tmp_tmp;
        b = b_A[k];
        s = b_A[i0];
        t1_re = b_A[k + 1];
        t1_im = t1_re;
        xdlanv2(&r, &b, &s, &t1_im, &rt1r, &rt1i, &rt2r, &mu1_im, &mu1_re, &sn);
        mu1_re = rt1r - t1_re;
        r = muDoubleScalarHypot(muDoubleScalarHypot(mu1_re, rt1i), b_A[i0]);
        if (rt1i == 0.0) {
          mu1_re /= r;
          mu1_im = 0.0;
        } else if (mu1_re == 0.0) {
          mu1_re = 0.0;
          mu1_im = rt1i / r;
        } else {
          mu1_re /= r;
          mu1_im = rt1i / r;
        }

        s = b_A[i0] / r;
        for (k = mm1; k < 4; k++) {
          re_tmp = m + 3 * (k - 1);
          t1_im = T[m + 3 * (k - 1)].im;
          t1_re = T[re_tmp].re;
          b_re_tmp = re_tmp + 1;
          rt1r = T[b_re_tmp].re;
          rt2r = T[(m + 3 * (k - 1)) + 1].im;
          r = T[re_tmp].re;
          T[re_tmp].re = (mu1_re * T[re_tmp].re + mu1_im * t1_im) + s *
            T[b_re_tmp].re;
          T[re_tmp].im = (mu1_re * t1_im - mu1_im * r) + s * rt2r;
          r = mu1_re * rt1r - mu1_im * rt2r;
          b = mu1_re * rt2r + mu1_im * rt1r;
          T[b_re_tmp].re = r - s * t1_re;
          T[b_re_tmp].im = b - s * t1_im;
        }

        for (k = 0; k <= m + 1; k++) {
          re_tmp = k + 3 * m;
          t1_im = T[k + 3 * m].im;
          t1_re = T[re_tmp].re;
          b_re_tmp = k + b_tmp_tmp;
          rt1r = T[b_re_tmp].re;
          rt2r = T[k + 3 * (m + 1)].im;
          r = mu1_re * T[re_tmp].re - mu1_im * t1_im;
          b = mu1_re * t1_im + mu1_im * T[re_tmp].re;
          T[re_tmp].re = r + s * T[b_re_tmp].re;
          T[re_tmp].im = b + s * rt2r;
          T[b_re_tmp].re = (mu1_re * rt1r + mu1_im * rt2r) - s * t1_re;
          T[b_re_tmp].im = (mu1_re * rt2r - mu1_im * rt1r) - s * t1_im;
        }

        t1_re = V[3 * m].re;
        t1_im = V[3 * m].im;
        rt1r = V[b_tmp_tmp].re;
        rt2r = V[3 * (m + 1)].im;
        r = mu1_re * t1_re - mu1_im * t1_im;
        b = mu1_re * t1_im + mu1_im * t1_re;
        V[3 * m].re = r + s * V[b_tmp_tmp].re;
        V[3 * m].im = b + s * rt2r;
        V[b_tmp_tmp].re = (mu1_re * rt1r + mu1_im * rt2r) - s * t1_re;
        V[b_tmp_tmp].im = (mu1_re * rt2r - mu1_im * rt1r) - s * t1_im;
        re_tmp = 1 + 3 * m;
        t1_im = V[1 + 3 * m].im;
        t1_re = V[re_tmp].re;
        b_re_tmp = 1 + b_tmp_tmp;
        rt1r = V[b_re_tmp].re;
        rt2r = V[1 + 3 * (m + 1)].im;
        r = mu1_re * V[re_tmp].re - mu1_im * t1_im;
        b = mu1_re * t1_im + mu1_im * V[re_tmp].re;
        V[re_tmp].re = r + s * V[b_re_tmp].re;
        V[re_tmp].im = b + s * rt2r;
        V[b_re_tmp].re = (mu1_re * rt1r + mu1_im * rt2r) - s * t1_re;
        V[b_re_tmp].im = (mu1_re * rt2r - mu1_im * rt1r) - s * t1_im;
        re_tmp = 2 + 3 * m;
        t1_im = V[2 + 3 * m].im;
        t1_re = V[re_tmp].re;
        b_re_tmp = 2 + b_tmp_tmp;
        rt1r = V[b_re_tmp].re;
        rt2r = V[2 + 3 * (m + 1)].im;
        r = mu1_re * V[re_tmp].re - mu1_im * t1_im;
        b = mu1_re * t1_im + mu1_im * V[re_tmp].re;
        V[re_tmp].re = r + s * V[b_re_tmp].re;
        V[re_tmp].im = b + s * rt2r;
        V[b_re_tmp].re = (mu1_re * rt1r + mu1_im * rt2r) - s * t1_re;
        V[b_re_tmp].im = (mu1_re * rt2r - mu1_im * rt1r) - s * t1_im;
        T[i0].re = 0.0;
        T[i0].im = 0.0;
      }
    }

    if (info != 0) {
      st.site = &cc_emlrtRSI;
      c_warning(&st);
    }
  }
}

/* End of code generation (schur.c) */
