/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgehrd.c
 *
 * Code generation for function 'xgehrd'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "xgehrd.h"
#include "xzlarf.h"
#include "eml_int_forloop_overflow_check.h"
#include "xnrm2.h"
#include "xdlapy3.h"
#include "recip.h"
#include "trqp_multipliers_data.h"

/* Variable Definitions */
static emlrtRSInfo fb_emlrtRSI = { 51, /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 58, /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 18, /* lineNo */
  "xgehrd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgehrd.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 31, /* lineNo */
  "xzgehrd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgehrd.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 35, /* lineNo */
  "xzgehrd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgehrd.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 43, /* lineNo */
  "xzgehrd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgehrd.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 53, /* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 84, /* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 91, /* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 121,/* lineNo */
  "ilazlr",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

/* Function Definitions */
void b_xgehrd(const emlrtStack *sp, creal_T a[36], creal_T tau[5])
{
  int32_T i;
  creal_T work[6];
  int32_T im1n;
  int32_T in;
  int32_T alpha1_tmp;
  creal_T alpha1;
  int32_T knt;
  int32_T ix0;
  real_T xnorm;
  real_T beta1;
  int32_T jy;
  int32_T ic0;
  real_T c_im;
  int32_T b_tmp;
  int32_T lastv;
  int32_T lastc;
  creal_T b_a;
  int32_T k;
  boolean_T exitg2;
  int32_T b;
  int32_T ix;
  int32_T exitg1;
  real_T temp_im;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  for (i = 0; i < 6; i++) {
    work[i].re = 0.0;
    work[i].im = 0.0;
  }

  for (i = 0; i < 5; i++) {
    im1n = i * 6 + 2;
    in = (i + 1) * 6;
    alpha1_tmp = (i + 6 * i) + 1;
    alpha1 = a[alpha1_tmp];
    knt = i + 3;
    ix0 = muIntScalarMin_sint32(knt, 6) + i * 6;
    b_st.site = &xc_emlrtRSI;
    tau[i].re = 0.0;
    tau[i].im = 0.0;
    c_st.site = &bd_emlrtRSI;
    xnorm = c_xnrm2(&c_st, 4 - i, a, ix0);
    if ((xnorm != 0.0) || (a[(i + 6 * i) + 1].im != 0.0)) {
      c_st.site = &eg_emlrtRSI;
      beta1 = xdlapy3(a[(i + 6 * i) + 1].re, a[(i + 6 * i) + 1].im, xnorm);
      if (a[(i + 6 * i) + 1].re >= 0.0) {
        beta1 = -beta1;
      }

      if (muDoubleScalarAbs(beta1) < 1.0020841800044864E-292) {
        knt = 0;
        b_tmp = (ix0 - i) + 3;
        do {
          knt++;
          c_st.site = &cd_emlrtRSI;
          d_st.site = &mb_emlrtRSI;
          e_st.site = &nb_emlrtRSI;
          for (k = ix0; k <= b_tmp; k++) {
            xnorm = a[k - 1].re;
            c_im = a[k - 1].im;
            a[k - 1].re = 9.9792015476736E+291 * xnorm - 0.0 * c_im;
            a[k - 1].im = 9.9792015476736E+291 * c_im + 0.0 * xnorm;
          }

          beta1 *= 9.9792015476736E+291;
          alpha1.re *= 9.9792015476736E+291;
          alpha1.im *= 9.9792015476736E+291;
        } while (!(muDoubleScalarAbs(beta1) >= 1.0020841800044864E-292));

        c_st.site = &dd_emlrtRSI;
        xnorm = c_xnrm2(&c_st, 4 - i, a, ix0);
        c_st.site = &fg_emlrtRSI;
        beta1 = xdlapy3(alpha1.re, alpha1.im, xnorm);
        if (alpha1.re >= 0.0) {
          beta1 = -beta1;
        }

        xnorm = beta1 - alpha1.re;
        if (0.0 - alpha1.im == 0.0) {
          tau[i].re = xnorm / beta1;
          tau[i].im = 0.0;
        } else if (xnorm == 0.0) {
          tau[i].re = 0.0;
          tau[i].im = (0.0 - alpha1.im) / beta1;
        } else {
          tau[i].re = xnorm / beta1;
          tau[i].im = (0.0 - alpha1.im) / beta1;
        }

        b_a.re = alpha1.re - beta1;
        b_a.im = alpha1.im;
        alpha1 = recip(b_a);
        c_st.site = &ed_emlrtRSI;
        d_st.site = &mb_emlrtRSI;
        e_st.site = &nb_emlrtRSI;
        for (k = ix0; k <= b_tmp; k++) {
          xnorm = a[k - 1].re;
          c_im = a[k - 1].im;
          a[k - 1].re = alpha1.re * xnorm - alpha1.im * c_im;
          a[k - 1].im = alpha1.re * c_im + alpha1.im * xnorm;
        }

        c_st.site = &fd_emlrtRSI;
        if ((1 <= knt) && (knt > 2147483646)) {
          d_st.site = &bb_emlrtRSI;
          check_forloop_overflow_error(&d_st, true);
        }

        for (k = 0; k < knt; k++) {
          beta1 *= 1.0020841800044864E-292;
        }

        alpha1.re = beta1;
        alpha1.im = 0.0;
      } else {
        xnorm = beta1 - a[(i + 6 * i) + 1].re;
        c_im = 0.0 - a[(i + 6 * i) + 1].im;
        if (c_im == 0.0) {
          tau[i].re = xnorm / beta1;
          tau[i].im = 0.0;
        } else if (xnorm == 0.0) {
          tau[i].re = 0.0;
          tau[i].im = c_im / beta1;
        } else {
          tau[i].re = xnorm / beta1;
          tau[i].im = c_im / beta1;
        }

        b_a.re = a[(i + 6 * i) + 1].re - beta1;
        b_a.im = a[(i + 6 * i) + 1].im;
        alpha1 = recip(b_a);
        c_st.site = &gd_emlrtRSI;
        d_st.site = &mb_emlrtRSI;
        b = (ix0 - i) + 3;
        e_st.site = &nb_emlrtRSI;
        for (k = ix0; k <= b; k++) {
          xnorm = a[k - 1].re;
          c_im = a[k - 1].im;
          a[k - 1].re = alpha1.re * xnorm - alpha1.im * c_im;
          a[k - 1].im = alpha1.re * c_im + alpha1.im * xnorm;
        }

        alpha1.re = beta1;
        alpha1.im = 0.0;
      }
    }

    a[alpha1_tmp].re = 1.0;
    a[alpha1_tmp].im = 0.0;
    jy = (i + im1n) - 1;
    ic0 = in + 1;
    b_st.site = &yc_emlrtRSI;
    if ((tau[i].re != 0.0) || (tau[i].im != 0.0)) {
      lastv = 4 - i;
      knt = (jy - i) + 4;
      while ((lastv + 1 > 0) && ((a[knt].re == 0.0) && (a[knt].im == 0.0))) {
        lastv--;
        knt--;
      }

      c_st.site = &jd_emlrtRSI;
      lastc = 6;
      exitg2 = false;
      while ((!exitg2) && (lastc > 0)) {
        knt = in + lastc;
        d_st.site = &md_emlrtRSI;
        k = knt;
        do {
          exitg1 = 0;
          if (k <= knt + lastv * 6) {
            if ((a[k - 1].re != 0.0) || (a[k - 1].im != 0.0)) {
              exitg1 = 1;
            } else {
              k += 6;
            }
          } else {
            lastc--;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    } else {
      lastv = -1;
      lastc = 0;
    }

    if (lastv + 1 > 0) {
      c_st.site = &kd_emlrtRSI;
      d_st.site = &cb_emlrtRSI;
      if (lastc != 0) {
        e_st.site = &nd_emlrtRSI;
        for (knt = 0; knt < lastc; knt++) {
          work[knt].re = 0.0;
          work[knt].im = 0.0;
        }

        ix = jy;
        b = (in + 6 * lastv) + 1;
        e_st.site = &fb_emlrtRSI;
        for (b_tmp = ic0; b_tmp <= b; b_tmp += 6) {
          xnorm = a[ix].re - 0.0 * a[ix].im;
          c_im = a[ix].im + 0.0 * a[ix].re;
          knt = 0;
          ix0 = (b_tmp + lastc) - 1;
          e_st.site = &gb_emlrtRSI;
          for (k = b_tmp; k <= ix0; k++) {
            work[knt].re += a[k - 1].re * xnorm - a[k - 1].im * c_im;
            work[knt].im += a[k - 1].re * c_im + a[k - 1].im * xnorm;
            knt++;
          }

          ix++;
        }
      }

      c_st.site = &ld_emlrtRSI;
      xnorm = -tau[i].re;
      c_im = -tau[i].im;
      d_st.site = &hg_emlrtRSI;
      e_st.site = &ig_emlrtRSI;
      if ((!(-tau[i].re == 0.0)) || (!(-tau[i].im == 0.0))) {
        knt = in;
        f_st.site = &ec_emlrtRSI;
        for (b_tmp = 0; b_tmp <= lastv; b_tmp++) {
          if ((a[jy].re != 0.0) || (a[jy].im != 0.0)) {
            beta1 = a[jy].re * xnorm + a[jy].im * c_im;
            temp_im = a[jy].re * c_im - a[jy].im * xnorm;
            ix = 0;
            ix0 = knt + 1;
            b = lastc + knt;
            f_st.site = &fc_emlrtRSI;
            if ((knt + 1 <= b) && (b > 2147483646)) {
              g_st.site = &bb_emlrtRSI;
              check_forloop_overflow_error(&g_st, true);
            }

            for (k = ix0; k <= b; k++) {
              a[k - 1].re += work[ix].re * beta1 - work[ix].im * temp_im;
              a[k - 1].im += work[ix].re * temp_im + work[ix].im * beta1;
              ix++;
            }
          }

          jy++;
          knt += 6;
        }
      }
    }

    b_a.re = tau[i].re;
    b_a.im = -tau[i].im;
    b_st.site = &ad_emlrtRSI;
    b_xzlarf(&b_st, 5 - i, 5 - i, i + im1n, b_a, a, (i + in) + 2, work);
    a[alpha1_tmp] = alpha1;
  }
}

void xgehrd(const emlrtStack *sp, real_T a[36], real_T tau[5])
{
  int32_T i;
  real_T work[6];
  int32_T im1n;
  int32_T in;
  int32_T alpha1_tmp_tmp;
  real_T alpha1_tmp;
  int32_T knt;
  int32_T ix0;
  real_T xnorm;
  real_T beta1;
  int32_T jy;
  int32_T ic0;
  int32_T b_tmp;
  int32_T lastv;
  int32_T lastc;
  int32_T b;
  int32_T k;
  boolean_T exitg2;
  int32_T ix;
  int32_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  for (i = 0; i < 6; i++) {
    work[i] = 0.0;
  }

  for (i = 0; i < 5; i++) {
    im1n = i * 6 + 2;
    in = (i + 1) * 6;
    alpha1_tmp_tmp = (i + 6 * i) + 1;
    alpha1_tmp = a[alpha1_tmp_tmp];
    knt = i + 3;
    ix0 = muIntScalarMin_sint32(knt, 6) + i * 6;
    b_st.site = &xc_emlrtRSI;
    tau[i] = 0.0;
    c_st.site = &bd_emlrtRSI;
    xnorm = xnrm2(&c_st, 4 - i, a, ix0);
    if (xnorm != 0.0) {
      beta1 = muDoubleScalarHypot(alpha1_tmp, xnorm);
      if (alpha1_tmp >= 0.0) {
        beta1 = -beta1;
      }

      if (muDoubleScalarAbs(beta1) < 1.0020841800044864E-292) {
        knt = 0;
        b_tmp = (ix0 - i) + 3;
        do {
          knt++;
          c_st.site = &cd_emlrtRSI;
          d_st.site = &mb_emlrtRSI;
          e_st.site = &nb_emlrtRSI;
          for (k = ix0; k <= b_tmp; k++) {
            a[k - 1] *= 9.9792015476736E+291;
          }

          beta1 *= 9.9792015476736E+291;
          alpha1_tmp *= 9.9792015476736E+291;
        } while (!(muDoubleScalarAbs(beta1) >= 1.0020841800044864E-292));

        c_st.site = &dd_emlrtRSI;
        xnorm = xnrm2(&c_st, 4 - i, a, ix0);
        beta1 = muDoubleScalarHypot(alpha1_tmp, xnorm);
        if (alpha1_tmp >= 0.0) {
          beta1 = -beta1;
        }

        tau[i] = (beta1 - alpha1_tmp) / beta1;
        xnorm = 1.0 / (alpha1_tmp - beta1);
        c_st.site = &ed_emlrtRSI;
        d_st.site = &mb_emlrtRSI;
        e_st.site = &nb_emlrtRSI;
        for (k = ix0; k <= b_tmp; k++) {
          a[k - 1] *= xnorm;
        }

        c_st.site = &fd_emlrtRSI;
        if ((1 <= knt) && (knt > 2147483646)) {
          d_st.site = &bb_emlrtRSI;
          check_forloop_overflow_error(&d_st, true);
        }

        for (k = 0; k < knt; k++) {
          beta1 *= 1.0020841800044864E-292;
        }

        alpha1_tmp = beta1;
      } else {
        tau[i] = (beta1 - a[alpha1_tmp_tmp]) / beta1;
        xnorm = 1.0 / (a[(i + 6 * i) + 1] - beta1);
        c_st.site = &gd_emlrtRSI;
        d_st.site = &mb_emlrtRSI;
        b = (ix0 - i) + 3;
        e_st.site = &nb_emlrtRSI;
        for (k = ix0; k <= b; k++) {
          a[k - 1] *= xnorm;
        }

        alpha1_tmp = beta1;
      }
    }

    a[alpha1_tmp_tmp] = 1.0;
    jy = (i + im1n) - 1;
    ic0 = in + 1;
    b_st.site = &yc_emlrtRSI;
    if (tau[i] != 0.0) {
      lastv = 4 - i;
      knt = (jy - i) + 4;
      while ((lastv + 1 > 0) && (a[knt] == 0.0)) {
        lastv--;
        knt--;
      }

      c_st.site = &jd_emlrtRSI;
      lastc = 6;
      exitg2 = false;
      while ((!exitg2) && (lastc > 0)) {
        knt = in + lastc;
        d_st.site = &md_emlrtRSI;
        k = knt;
        do {
          exitg1 = 0;
          if (k <= knt + lastv * 6) {
            if (a[k - 1] != 0.0) {
              exitg1 = 1;
            } else {
              k += 6;
            }
          } else {
            lastc--;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    } else {
      lastv = -1;
      lastc = 0;
    }

    if (lastv + 1 > 0) {
      c_st.site = &kd_emlrtRSI;
      d_st.site = &cb_emlrtRSI;
      if (lastc != 0) {
        e_st.site = &nd_emlrtRSI;
        memset(&work[0], 0, (uint32_T)(lastc * (int32_T)sizeof(real_T)));
        ix = jy;
        b = (in + 6 * lastv) + 1;
        e_st.site = &fb_emlrtRSI;
        for (knt = ic0; knt <= b; knt += 6) {
          b_tmp = 0;
          ix0 = (knt + lastc) - 1;
          e_st.site = &gb_emlrtRSI;
          for (k = knt; k <= ix0; k++) {
            work[b_tmp] += a[k - 1] * a[ix];
            b_tmp++;
          }

          ix++;
        }
      }

      c_st.site = &ld_emlrtRSI;
      d_st.site = &od_emlrtRSI;
      e_st.site = &cc_emlrtRSI;
      f_st.site = &dc_emlrtRSI;
      if (!(-tau[i] == 0.0)) {
        knt = in;
        g_st.site = &ec_emlrtRSI;
        for (b_tmp = 0; b_tmp <= lastv; b_tmp++) {
          if (a[jy] != 0.0) {
            xnorm = a[jy] * -tau[i];
            ix = 0;
            ix0 = knt + 1;
            b = lastc + knt;
            g_st.site = &fc_emlrtRSI;
            if ((knt + 1 <= b) && (b > 2147483646)) {
              h_st.site = &bb_emlrtRSI;
              check_forloop_overflow_error(&h_st, true);
            }

            for (k = ix0; k <= b; k++) {
              a[k - 1] += work[ix] * xnorm;
              ix++;
            }
          }

          jy++;
          knt += 6;
        }
      }
    }

    b_st.site = &ad_emlrtRSI;
    xzlarf(&b_st, 5 - i, 5 - i, i + im1n, tau[i], a, (i + in) + 2, work);
    a[alpha1_tmp_tmp] = alpha1_tmp;
  }
}

/* End of code generation (xgehrd.c) */
