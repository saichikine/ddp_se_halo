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
#include "trqp_multipliers.h"
#include "schur.h"
#include "xdlanv2.h"
#include "warning.h"
#include "xhseqr.h"
#include "xgehrd.h"
#include "anyNonFinite.h"
#include "trqp_multipliers_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo pc_emlrtRSI = { 39, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 66, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 72, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 73, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 74, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 83, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 48, /* lineNo */
  "triu",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\triu.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 11, /* lineNo */
  "xungorghr",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

static emlrtRSInfo be_emlrtRSI = { 68, /* lineNo */
  "ceval_xungorghr",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 15, /* lineNo */
  "rsf2csf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\rsf2csf.m"/* pathName */
};

static emlrtRSInfo bg_emlrtRSI = { 43, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo cg_emlrtRSI = { 77, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo dg_emlrtRSI = { 78, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

/* Function Definitions */
void b_schur(const emlrtStack *sp, const creal_T A[36], creal_T V[36], creal_T
             T[36])
{
  int32_T info;
  creal_T tau[5];
  int32_T istart;
  int32_T j;
  int32_T i;
  ptrdiff_t info_t;
  boolean_T p;
  boolean_T b_p;
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'z',
    'u', 'n', 'g', 'h', 'r' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (anyNonFinite(A)) {
    for (info = 0; info < 36; info++) {
      V[info].re = rtNaN;
      V[info].im = 0.0;
    }

    st.site = &bg_emlrtRSI;
    istart = 2;
    for (j = 0; j < 5; j++) {
      b_st.site = &vc_emlrtRSI;
      for (i = istart; i < 7; i++) {
        info = (i + 6 * j) - 1;
        V[info].re = 0.0;
        V[info].im = 0.0;
      }

      istart++;
    }

    for (info = 0; info < 36; info++) {
      T[info].re = rtNaN;
      T[info].im = 0.0;
    }
  } else {
    memcpy(&T[0], &A[0], 36U * sizeof(creal_T));
    st.site = &qc_emlrtRSI;
    b_xgehrd(&st, T, tau);
    st.site = &cg_emlrtRSI;
    memcpy(&V[0], &T[0], 36U * sizeof(creal_T));
    b_st.site = &vd_emlrtRSI;
    info_t = LAPACKE_zunghr(102, (ptrdiff_t)6, (ptrdiff_t)1, (ptrdiff_t)6,
      (lapack_complex_double *)&V[0], (ptrdiff_t)6, (lapack_complex_double *)
      &tau[0]);
    info = (int32_T)info_t;
    c_st.site = &be_emlrtRSI;
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
          emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI, "MATLAB:nomem",
            "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
            "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, info);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      for (info = 0; info < 36; info++) {
        V[info].re = rtNaN;
        V[info].im = 0.0;
      }
    }

    st.site = &dg_emlrtRSI;
    info = b_xhseqr(&st, T, V);
    if (info != 0) {
      st.site = &uc_emlrtRSI;
      c_warning(&st);
    }
  }
}

void schur(const emlrtStack *sp, const real_T A[36], creal_T V[36], creal_T T[36])
{
  boolean_T p;
  int32_T k;
  real_T b_A[36];
  real_T tau[5];
  real_T Vr[36];
  ptrdiff_t info_t;
  int32_T info;
  boolean_T b_p;
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'o', 'r', 'g', 'h', 'r' };

  int32_T m;
  int32_T mm1;
  int32_T i1;
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
  for (k = 0; k < 36; k++) {
    if (p && ((!muDoubleScalarIsInf(A[k])) && (!muDoubleScalarIsNaN(A[k])))) {
      p = true;
    } else {
      p = false;
    }
  }

  if (!p) {
    for (k = 0; k < 36; k++) {
      V[k].re = rtNaN;
      V[k].im = 0.0;
    }

    st.site = &pc_emlrtRSI;
    b_st.site = &vc_emlrtRSI;
    for (k = 3; k < 7; k++) {
      V[k - 1].re = 0.0;
      V[k - 1].im = 0.0;
    }

    b_st.site = &vc_emlrtRSI;
    for (k = 4; k < 7; k++) {
      V[k + 5].re = 0.0;
      V[k + 5].im = 0.0;
    }

    b_st.site = &vc_emlrtRSI;
    for (k = 5; k < 7; k++) {
      V[k + 11].re = 0.0;
      V[k + 11].im = 0.0;
    }

    b_st.site = &vc_emlrtRSI;
    for (k = 6; k < 7; k++) {
      V[23].re = 0.0;
      V[23].im = 0.0;
    }

    for (k = 0; k < 36; k++) {
      T[k].re = rtNaN;
      T[k].im = 0.0;
    }
  } else {
    memcpy(&b_A[0], &A[0], 36U * sizeof(real_T));
    st.site = &qc_emlrtRSI;
    xgehrd(&st, b_A, tau);
    st.site = &rc_emlrtRSI;
    memcpy(&Vr[0], &b_A[0], 36U * sizeof(real_T));
    b_st.site = &vd_emlrtRSI;
    info_t = LAPACKE_dorghr(102, (ptrdiff_t)6, (ptrdiff_t)1, (ptrdiff_t)6, &Vr[0],
      (ptrdiff_t)6, &tau[0]);
    info = (int32_T)info_t;
    c_st.site = &be_emlrtRSI;
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
          emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI, "MATLAB:nomem",
            "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
            "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, info);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      for (k = 0; k < 36; k++) {
        Vr[k] = rtNaN;
      }
    }

    st.site = &sc_emlrtRSI;
    info = xhseqr(&st, b_A, Vr);
    st.site = &tc_emlrtRSI;
    b_st.site = &cf_emlrtRSI;
    for (k = 0; k < 36; k++) {
      T[k].re = b_A[k];
      T[k].im = 0.0;
      V[k].re = Vr[k];
      V[k].im = 0.0;
    }

    for (m = 4; m >= 0; m--) {
      mm1 = m + 1;
      k = m + 6 * m;
      i1 = k + 1;
      if (b_A[i1] != 0.0) {
        r = b_A[k];
        b_tmp_tmp = 6 * (m + 1);
        k = m + b_tmp_tmp;
        b = b_A[k];
        s = b_A[i1];
        t1_re = b_A[k + 1];
        t1_im = t1_re;
        xdlanv2(&r, &b, &s, &t1_im, &rt1r, &rt1i, &rt2r, &mu1_im, &mu1_re, &sn);
        mu1_re = rt1r - t1_re;
        r = muDoubleScalarHypot(muDoubleScalarHypot(mu1_re, rt1i), b_A[i1]);
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

        s = b_A[i1] / r;
        for (k = mm1; k < 7; k++) {
          re_tmp = m + 6 * (k - 1);
          t1_im = T[m + 6 * (k - 1)].im;
          t1_re = T[re_tmp].re;
          b_re_tmp = re_tmp + 1;
          rt1r = T[b_re_tmp].re;
          rt2r = T[(m + 6 * (k - 1)) + 1].im;
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
          re_tmp = k + 6 * m;
          t1_im = T[k + 6 * m].im;
          t1_re = T[re_tmp].re;
          b_re_tmp = k + b_tmp_tmp;
          rt1r = T[b_re_tmp].re;
          rt2r = T[k + 6 * (m + 1)].im;
          r = mu1_re * T[re_tmp].re - mu1_im * t1_im;
          b = mu1_re * t1_im + mu1_im * T[re_tmp].re;
          T[re_tmp].re = r + s * T[b_re_tmp].re;
          T[re_tmp].im = b + s * rt2r;
          T[b_re_tmp].re = (mu1_re * rt1r + mu1_im * rt2r) - s * t1_re;
          T[b_re_tmp].im = (mu1_re * rt2r - mu1_im * rt1r) - s * t1_im;
        }

        for (k = 0; k < 6; k++) {
          re_tmp = k + 6 * m;
          t1_im = V[k + 6 * m].im;
          t1_re = V[re_tmp].re;
          b_re_tmp = k + b_tmp_tmp;
          rt1r = V[b_re_tmp].re;
          rt2r = V[k + 6 * (m + 1)].im;
          r = mu1_re * V[re_tmp].re - mu1_im * t1_im;
          b = mu1_re * t1_im + mu1_im * V[re_tmp].re;
          V[re_tmp].re = r + s * V[b_re_tmp].re;
          V[re_tmp].im = b + s * rt2r;
          V[b_re_tmp].re = (mu1_re * rt1r + mu1_im * rt2r) - s * t1_re;
          V[b_re_tmp].im = (mu1_re * rt2r - mu1_im * rt1r) - s * t1_im;
        }

        T[i1].re = 0.0;
        T[i1].im = 0.0;
      }
    }

    if (info != 0) {
      st.site = &uc_emlrtRSI;
      c_warning(&st);
    }
  }
}

/* End of code generation (schur.c) */
