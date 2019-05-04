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
#include "trqp_control.h"
#include "xgehrd.h"
#include "xzlarf.h"
#include "eml_int_forloop_overflow_check.h"
#include "xnrm2.h"
#include "xdlapy3.h"
#include "recip.h"
#include "trqp_control_data.h"

/* Variable Definitions */
static emlrtRSInfo fb_emlrtRSI = { 51, /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 58, /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 18, /* lineNo */
  "xgehrd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgehrd.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 31, /* lineNo */
  "xzgehrd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgehrd.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 35, /* lineNo */
  "xzgehrd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgehrd.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 43, /* lineNo */
  "xzgehrd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgehrd.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 53, /* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 84, /* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 91, /* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 121,/* lineNo */
  "ilazlr",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

/* Function Definitions */
void b_xgehrd(const emlrtStack *sp, creal_T a[9], creal_T tau[2])
{
  creal_T work[3];
  creal_T alpha1;
  real_T xnorm;
  real_T beta1;
  int32_T knt;
  real_T c_im;
  int32_T lastv;
  int32_T lastc;
  int32_T i;
  creal_T b_a;
  boolean_T exitg2;
  int32_T ix;
  int32_T b;
  int32_T ia;
  int32_T exitg1;
  int32_T b_b;
  real_T temp_im;
  int32_T ijA;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ec_emlrtRSI;
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
  work[0].re = 0.0;
  work[0].im = 0.0;
  work[1].re = 0.0;
  work[1].im = 0.0;
  work[2].re = 0.0;
  work[2].im = 0.0;
  alpha1 = a[1];
  b_st.site = &fc_emlrtRSI;
  tau[0].re = 0.0;
  tau[0].im = 0.0;
  c_st.site = &ic_emlrtRSI;
  xnorm = d_xnrm2(&c_st, 1, a, 3);
  if ((xnorm != 0.0) || (a[1].im != 0.0)) {
    c_st.site = &tg_emlrtRSI;
    beta1 = xdlapy3(a[1].re, a[1].im, xnorm);
    if (a[1].re >= 0.0) {
      beta1 = -beta1;
    }

    if (muDoubleScalarAbs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        c_st.site = &jc_emlrtRSI;
        d_st.site = &mb_emlrtRSI;
        e_st.site = &nb_emlrtRSI;
        for (i = 3; i < 4; i++) {
          xnorm = a[2].re;
          c_im = a[2].im;
          a[2].re = 9.9792015476736E+291 * xnorm - 0.0 * c_im;
          a[2].im = 9.9792015476736E+291 * c_im + 0.0 * xnorm;
        }

        beta1 *= 9.9792015476736E+291;
        alpha1.re *= 9.9792015476736E+291;
        alpha1.im *= 9.9792015476736E+291;
      } while (!(muDoubleScalarAbs(beta1) >= 1.0020841800044864E-292));

      c_st.site = &kc_emlrtRSI;
      xnorm = d_xnrm2(&c_st, 1, a, 3);
      c_st.site = &ug_emlrtRSI;
      beta1 = xdlapy3(alpha1.re, alpha1.im, xnorm);
      if (alpha1.re >= 0.0) {
        beta1 = -beta1;
      }

      xnorm = beta1 - alpha1.re;
      if (0.0 - alpha1.im == 0.0) {
        tau[0].re = xnorm / beta1;
        tau[0].im = 0.0;
      } else if (xnorm == 0.0) {
        tau[0].re = 0.0;
        tau[0].im = (0.0 - alpha1.im) / beta1;
      } else {
        tau[0].re = xnorm / beta1;
        tau[0].im = (0.0 - alpha1.im) / beta1;
      }

      b_a.re = alpha1.re - beta1;
      b_a.im = alpha1.im;
      alpha1 = recip(b_a);
      c_st.site = &lc_emlrtRSI;
      d_st.site = &mb_emlrtRSI;
      e_st.site = &nb_emlrtRSI;
      for (i = 3; i < 4; i++) {
        xnorm = a[2].re;
        c_im = a[2].im;
        a[2].re = alpha1.re * xnorm - alpha1.im * c_im;
        a[2].im = alpha1.re * c_im + alpha1.im * xnorm;
      }

      c_st.site = &mc_emlrtRSI;
      if ((1 <= knt) && (knt > 2147483646)) {
        d_st.site = &bb_emlrtRSI;
        check_forloop_overflow_error(&d_st, true);
      }

      for (i = 0; i < knt; i++) {
        beta1 *= 1.0020841800044864E-292;
      }

      alpha1.re = beta1;
      alpha1.im = 0.0;
    } else {
      xnorm = beta1 - a[1].re;
      c_im = 0.0 - a[1].im;
      if (c_im == 0.0) {
        tau[0].re = xnorm / beta1;
        tau[0].im = 0.0;
      } else if (xnorm == 0.0) {
        tau[0].re = 0.0;
        tau[0].im = c_im / beta1;
      } else {
        tau[0].re = xnorm / beta1;
        tau[0].im = c_im / beta1;
      }

      b_a.re = a[1].re - beta1;
      b_a.im = a[1].im;
      alpha1 = recip(b_a);
      c_st.site = &nc_emlrtRSI;
      d_st.site = &mb_emlrtRSI;
      e_st.site = &nb_emlrtRSI;
      for (i = 3; i < 4; i++) {
        xnorm = a[2].re;
        c_im = a[2].im;
        a[2].re = alpha1.re * xnorm - alpha1.im * c_im;
        a[2].im = alpha1.re * c_im + alpha1.im * xnorm;
      }

      alpha1.re = beta1;
      alpha1.im = 0.0;
    }
  }

  a[1].re = 1.0;
  a[1].im = 0.0;
  b_st.site = &gc_emlrtRSI;
  if ((tau[0].re != 0.0) || (tau[0].im != 0.0)) {
    lastv = 1;
    i = 2;
    while ((lastv + 1 > 0) && ((a[i].re == 0.0) && (a[i].im == 0.0))) {
      lastv--;
      i--;
    }

    c_st.site = &qc_emlrtRSI;
    lastc = 3;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      knt = 3 + lastc;
      d_st.site = &tc_emlrtRSI;
      ia = knt;
      do {
        exitg1 = 0;
        if (ia <= knt + lastv * 3) {
          if ((a[ia - 1].re != 0.0) || (a[ia - 1].im != 0.0)) {
            exitg1 = 1;
          } else {
            ia += 3;
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
    c_st.site = &rc_emlrtRSI;
    d_st.site = &cb_emlrtRSI;
    if (lastc != 0) {
      e_st.site = &uc_emlrtRSI;
      for (knt = 0; knt < lastc; knt++) {
        work[knt].re = 0.0;
        work[knt].im = 0.0;
      }

      ix = 1;
      b = 3 * lastv + 4;
      e_st.site = &fb_emlrtRSI;
      for (i = 4; i <= b; i += 3) {
        xnorm = a[ix].re - 0.0 * a[ix].im;
        c_im = a[ix].im + 0.0 * a[ix].re;
        knt = 0;
        b_b = (i + lastc) - 1;
        e_st.site = &gb_emlrtRSI;
        for (ia = i; ia <= b_b; ia++) {
          work[knt].re += a[ia - 1].re * xnorm - a[ia - 1].im * c_im;
          work[knt].im += a[ia - 1].re * c_im + a[ia - 1].im * xnorm;
          knt++;
        }

        ix++;
      }
    }

    c_st.site = &sc_emlrtRSI;
    xnorm = -tau[0].re;
    c_im = -tau[0].im;
    d_st.site = &wg_emlrtRSI;
    e_st.site = &xg_emlrtRSI;
    if ((!(-tau[0].re == 0.0)) || (!(-tau[0].im == 0.0))) {
      knt = 3;
      i = 1;
      f_st.site = &yc_emlrtRSI;
      for (b_b = 0; b_b <= lastv; b_b++) {
        if ((a[i].re != 0.0) || (a[i].im != 0.0)) {
          beta1 = a[i].re * xnorm + a[i].im * c_im;
          temp_im = a[i].re * c_im - a[i].im * xnorm;
          ix = 0;
          ia = knt + 1;
          b = lastc + knt;
          f_st.site = &ad_emlrtRSI;
          if ((knt + 1 <= b) && (b > 2147483646)) {
            g_st.site = &bb_emlrtRSI;
            check_forloop_overflow_error(&g_st, true);
          }

          for (ijA = ia; ijA <= b; ijA++) {
            a[ijA - 1].re += work[ix].re * beta1 - work[ix].im * temp_im;
            a[ijA - 1].im += work[ix].re * temp_im + work[ix].im * beta1;
            ix++;
          }
        }

        i++;
        knt += 3;
      }
    }
  }

  b_a.re = tau[0].re;
  b_a.im = -tau[0].im;
  b_st.site = &hc_emlrtRSI;
  b_xzlarf(&b_st, 2, 2, 2, b_a, a, 5, work);
  a[1] = alpha1;
  alpha1 = a[5];
  b_st.site = &fc_emlrtRSI;
  tau[1].re = 0.0;
  tau[1].im = 0.0;
  c_st.site = &ic_emlrtRSI;
  xnorm = d_xnrm2(&c_st, 0, a, 6);
  if ((xnorm != 0.0) || (a[5].im != 0.0)) {
    c_st.site = &tg_emlrtRSI;
    beta1 = xdlapy3(a[5].re, a[5].im, xnorm);
    if (a[5].re >= 0.0) {
      beta1 = -beta1;
    }

    if (muDoubleScalarAbs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        c_st.site = &jc_emlrtRSI;
        d_st.site = &mb_emlrtRSI;
        e_st.site = &nb_emlrtRSI;
        beta1 *= 9.9792015476736E+291;
        alpha1.re *= 9.9792015476736E+291;
        alpha1.im *= 9.9792015476736E+291;
      } while (!(muDoubleScalarAbs(beta1) >= 1.0020841800044864E-292));

      c_st.site = &kc_emlrtRSI;
      xnorm = d_xnrm2(&c_st, 0, a, 6);
      c_st.site = &ug_emlrtRSI;
      beta1 = xdlapy3(alpha1.re, alpha1.im, xnorm);
      if (alpha1.re >= 0.0) {
        beta1 = -beta1;
      }

      xnorm = beta1 - alpha1.re;
      if (0.0 - alpha1.im == 0.0) {
        tau[1].re = xnorm / beta1;
        tau[1].im = 0.0;
      } else if (xnorm == 0.0) {
        tau[1].re = 0.0;
        tau[1].im = (0.0 - alpha1.im) / beta1;
      } else {
        tau[1].re = xnorm / beta1;
        tau[1].im = (0.0 - alpha1.im) / beta1;
      }

      c_st.site = &lc_emlrtRSI;
      d_st.site = &mb_emlrtRSI;
      e_st.site = &nb_emlrtRSI;
      c_st.site = &mc_emlrtRSI;
      if ((1 <= knt) && (knt > 2147483646)) {
        d_st.site = &bb_emlrtRSI;
        check_forloop_overflow_error(&d_st, true);
      }

      for (i = 0; i < knt; i++) {
        beta1 *= 1.0020841800044864E-292;
      }

      alpha1.re = beta1;
      alpha1.im = 0.0;
    } else {
      xnorm = beta1 - a[5].re;
      c_im = 0.0 - a[5].im;
      if (c_im == 0.0) {
        tau[1].re = xnorm / beta1;
        tau[1].im = 0.0;
      } else if (xnorm == 0.0) {
        tau[1].re = 0.0;
        tau[1].im = c_im / beta1;
      } else {
        tau[1].re = xnorm / beta1;
        tau[1].im = c_im / beta1;
      }

      c_st.site = &nc_emlrtRSI;
      d_st.site = &mb_emlrtRSI;
      e_st.site = &nb_emlrtRSI;
      alpha1.re = beta1;
      alpha1.im = 0.0;
    }
  }

  a[5].re = 1.0;
  a[5].im = 0.0;
  b_st.site = &gc_emlrtRSI;
  if ((tau[1].re != 0.0) || (tau[1].im != 0.0)) {
    lastv = 0;
    i = 5;
    while ((lastv + 1 > 0) && ((a[i].re == 0.0) && (a[i].im == 0.0))) {
      lastv--;
      i--;
    }

    c_st.site = &qc_emlrtRSI;
    lastc = 3;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      knt = 6 + lastc;
      d_st.site = &tc_emlrtRSI;
      ia = knt;
      do {
        exitg1 = 0;
        if (ia <= knt + lastv * 3) {
          if ((a[ia - 1].re != 0.0) || (a[ia - 1].im != 0.0)) {
            exitg1 = 1;
          } else {
            ia += 3;
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
    c_st.site = &rc_emlrtRSI;
    d_st.site = &cb_emlrtRSI;
    if (lastc != 0) {
      e_st.site = &uc_emlrtRSI;
      for (knt = 0; knt < lastc; knt++) {
        work[knt].re = 0.0;
        work[knt].im = 0.0;
      }

      ix = 5;
      b = 3 * lastv + 7;
      e_st.site = &fb_emlrtRSI;
      for (i = 7; i <= b; i += 3) {
        xnorm = a[ix].re - 0.0 * a[ix].im;
        c_im = a[ix].im + 0.0 * a[ix].re;
        knt = 0;
        b_b = (i + lastc) - 1;
        e_st.site = &gb_emlrtRSI;
        for (ia = i; ia <= b_b; ia++) {
          work[knt].re += a[ia - 1].re * xnorm - a[ia - 1].im * c_im;
          work[knt].im += a[ia - 1].re * c_im + a[ia - 1].im * xnorm;
          knt++;
        }

        ix++;
      }
    }

    c_st.site = &sc_emlrtRSI;
    xnorm = -tau[1].re;
    c_im = -tau[1].im;
    d_st.site = &wg_emlrtRSI;
    e_st.site = &xg_emlrtRSI;
    if ((!(-tau[1].re == 0.0)) || (!(-tau[1].im == 0.0))) {
      knt = 6;
      i = 5;
      f_st.site = &yc_emlrtRSI;
      for (b_b = 0; b_b <= lastv; b_b++) {
        if ((a[i].re != 0.0) || (a[i].im != 0.0)) {
          beta1 = a[i].re * xnorm + a[i].im * c_im;
          temp_im = a[i].re * c_im - a[i].im * xnorm;
          ix = 0;
          ia = knt + 1;
          b = lastc + knt;
          f_st.site = &ad_emlrtRSI;
          if ((knt + 1 <= b) && (b > 2147483646)) {
            g_st.site = &bb_emlrtRSI;
            check_forloop_overflow_error(&g_st, true);
          }

          for (ijA = ia; ijA <= b; ijA++) {
            a[ijA - 1].re += work[ix].re * beta1 - work[ix].im * temp_im;
            a[ijA - 1].im += work[ix].re * temp_im + work[ix].im * beta1;
            ix++;
          }
        }

        i++;
        knt += 3;
      }
    }
  }

  b_a.re = tau[1].re;
  b_a.im = -tau[1].im;
  b_st.site = &hc_emlrtRSI;
  b_xzlarf(&b_st, 1, 1, 6, b_a, a, 9, work);
  a[5] = alpha1;
}

void xgehrd(const emlrtStack *sp, real_T a[9], real_T tau[2])
{
  real_T work[3];
  real_T alpha1;
  real_T xnorm;
  real_T beta1;
  int32_T knt;
  int32_T lastv;
  int32_T lastc;
  int32_T i;
  boolean_T exitg2;
  int32_T ix;
  int32_T b;
  int32_T ia;
  int32_T exitg1;
  int32_T b_b;
  int32_T ijA;
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
  st.site = &ec_emlrtRSI;
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
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  alpha1 = a[1];
  b_st.site = &fc_emlrtRSI;
  tau[0] = 0.0;
  c_st.site = &ic_emlrtRSI;
  xnorm = xnrm2(&c_st, 1, a, 3);
  if (xnorm != 0.0) {
    beta1 = muDoubleScalarHypot(a[1], xnorm);
    if (a[1] >= 0.0) {
      beta1 = -beta1;
    }

    if (muDoubleScalarAbs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        c_st.site = &jc_emlrtRSI;
        d_st.site = &mb_emlrtRSI;
        e_st.site = &nb_emlrtRSI;
        for (i = 3; i < 4; i++) {
          a[2] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        alpha1 *= 9.9792015476736E+291;
      } while (!(muDoubleScalarAbs(beta1) >= 1.0020841800044864E-292));

      c_st.site = &kc_emlrtRSI;
      xnorm = xnrm2(&c_st, 1, a, 3);
      beta1 = muDoubleScalarHypot(alpha1, xnorm);
      if (alpha1 >= 0.0) {
        beta1 = -beta1;
      }

      tau[0] = (beta1 - alpha1) / beta1;
      xnorm = 1.0 / (alpha1 - beta1);
      c_st.site = &lc_emlrtRSI;
      d_st.site = &mb_emlrtRSI;
      e_st.site = &nb_emlrtRSI;
      for (i = 3; i < 4; i++) {
        a[2] *= xnorm;
      }

      c_st.site = &mc_emlrtRSI;
      if ((1 <= knt) && (knt > 2147483646)) {
        d_st.site = &bb_emlrtRSI;
        check_forloop_overflow_error(&d_st, true);
      }

      for (i = 0; i < knt; i++) {
        beta1 *= 1.0020841800044864E-292;
      }

      alpha1 = beta1;
    } else {
      tau[0] = (beta1 - a[1]) / beta1;
      xnorm = 1.0 / (a[1] - beta1);
      c_st.site = &nc_emlrtRSI;
      d_st.site = &mb_emlrtRSI;
      e_st.site = &nb_emlrtRSI;
      for (i = 3; i < 4; i++) {
        a[2] *= xnorm;
      }

      alpha1 = beta1;
    }
  }

  a[1] = 1.0;
  b_st.site = &gc_emlrtRSI;
  if (tau[0] != 0.0) {
    lastv = 1;
    i = 2;
    while ((lastv + 1 > 0) && (a[i] == 0.0)) {
      lastv--;
      i--;
    }

    c_st.site = &qc_emlrtRSI;
    lastc = 3;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      knt = 3 + lastc;
      d_st.site = &tc_emlrtRSI;
      ia = knt;
      do {
        exitg1 = 0;
        if (ia <= knt + lastv * 3) {
          if (a[ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            ia += 3;
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
    c_st.site = &rc_emlrtRSI;
    d_st.site = &cb_emlrtRSI;
    if (lastc != 0) {
      e_st.site = &uc_emlrtRSI;
      memset(&work[0], 0, (uint32_T)(lastc * (int32_T)sizeof(real_T)));
      ix = 1;
      b = 3 * lastv + 4;
      e_st.site = &fb_emlrtRSI;
      for (knt = 4; knt <= b; knt += 3) {
        i = 0;
        b_b = (knt + lastc) - 1;
        e_st.site = &gb_emlrtRSI;
        for (ia = knt; ia <= b_b; ia++) {
          work[i] += a[ia - 1] * a[ix];
          i++;
        }

        ix++;
      }
    }

    c_st.site = &sc_emlrtRSI;
    d_st.site = &vc_emlrtRSI;
    e_st.site = &wc_emlrtRSI;
    f_st.site = &xc_emlrtRSI;
    if (!(-tau[0] == 0.0)) {
      knt = 3;
      i = 1;
      g_st.site = &yc_emlrtRSI;
      for (b_b = 0; b_b <= lastv; b_b++) {
        if (a[i] != 0.0) {
          xnorm = a[i] * -tau[0];
          ix = 0;
          ia = knt + 1;
          b = lastc + knt;
          g_st.site = &ad_emlrtRSI;
          if ((knt + 1 <= b) && (b > 2147483646)) {
            h_st.site = &bb_emlrtRSI;
            check_forloop_overflow_error(&h_st, true);
          }

          for (ijA = ia; ijA <= b; ijA++) {
            a[ijA - 1] += work[ix] * xnorm;
            ix++;
          }
        }

        i++;
        knt += 3;
      }
    }
  }

  b_st.site = &hc_emlrtRSI;
  xzlarf(&b_st, 2, 2, 2, tau[0], a, 5, work);
  a[1] = alpha1;
  alpha1 = a[5];
  b_st.site = &fc_emlrtRSI;
  tau[1] = 0.0;
  c_st.site = &ic_emlrtRSI;
  xnorm = xnrm2(&c_st, 0, a, 6);
  if (xnorm != 0.0) {
    beta1 = muDoubleScalarHypot(a[5], xnorm);
    if (a[5] >= 0.0) {
      beta1 = -beta1;
    }

    if (muDoubleScalarAbs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        c_st.site = &jc_emlrtRSI;
        d_st.site = &mb_emlrtRSI;
        e_st.site = &nb_emlrtRSI;
        beta1 *= 9.9792015476736E+291;
        alpha1 *= 9.9792015476736E+291;
      } while (!(muDoubleScalarAbs(beta1) >= 1.0020841800044864E-292));

      c_st.site = &kc_emlrtRSI;
      xnorm = xnrm2(&c_st, 0, a, 6);
      beta1 = muDoubleScalarHypot(alpha1, xnorm);
      if (alpha1 >= 0.0) {
        beta1 = -beta1;
      }

      tau[1] = (beta1 - alpha1) / beta1;
      c_st.site = &lc_emlrtRSI;
      d_st.site = &mb_emlrtRSI;
      e_st.site = &nb_emlrtRSI;
      c_st.site = &mc_emlrtRSI;
      if ((1 <= knt) && (knt > 2147483646)) {
        d_st.site = &bb_emlrtRSI;
        check_forloop_overflow_error(&d_st, true);
      }

      for (i = 0; i < knt; i++) {
        beta1 *= 1.0020841800044864E-292;
      }

      alpha1 = beta1;
    } else {
      tau[1] = (beta1 - a[5]) / beta1;
      c_st.site = &nc_emlrtRSI;
      d_st.site = &mb_emlrtRSI;
      e_st.site = &nb_emlrtRSI;
      alpha1 = beta1;
    }
  }

  a[5] = 1.0;
  b_st.site = &gc_emlrtRSI;
  if (tau[1] != 0.0) {
    lastv = 0;
    i = 5;
    while ((lastv + 1 > 0) && (a[i] == 0.0)) {
      lastv--;
      i--;
    }

    c_st.site = &qc_emlrtRSI;
    lastc = 3;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      knt = 6 + lastc;
      d_st.site = &tc_emlrtRSI;
      ia = knt;
      do {
        exitg1 = 0;
        if (ia <= knt + lastv * 3) {
          if (a[ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            ia += 3;
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
    c_st.site = &rc_emlrtRSI;
    d_st.site = &cb_emlrtRSI;
    if (lastc != 0) {
      e_st.site = &uc_emlrtRSI;
      memset(&work[0], 0, (uint32_T)(lastc * (int32_T)sizeof(real_T)));
      ix = 5;
      b = 3 * lastv + 7;
      e_st.site = &fb_emlrtRSI;
      for (knt = 7; knt <= b; knt += 3) {
        i = 0;
        b_b = (knt + lastc) - 1;
        e_st.site = &gb_emlrtRSI;
        for (ia = knt; ia <= b_b; ia++) {
          work[i] += a[ia - 1] * a[ix];
          i++;
        }

        ix++;
      }
    }

    c_st.site = &sc_emlrtRSI;
    d_st.site = &vc_emlrtRSI;
    e_st.site = &wc_emlrtRSI;
    f_st.site = &xc_emlrtRSI;
    if (!(-tau[1] == 0.0)) {
      knt = 6;
      i = 5;
      g_st.site = &yc_emlrtRSI;
      for (b_b = 0; b_b <= lastv; b_b++) {
        if (a[i] != 0.0) {
          xnorm = a[i] * -tau[1];
          ix = 0;
          ia = knt + 1;
          b = lastc + knt;
          g_st.site = &ad_emlrtRSI;
          if ((knt + 1 <= b) && (b > 2147483646)) {
            h_st.site = &bb_emlrtRSI;
            check_forloop_overflow_error(&h_st, true);
          }

          for (ijA = ia; ijA <= b; ijA++) {
            a[ijA - 1] += work[ix] * xnorm;
            ix++;
          }
        }

        i++;
        knt += 3;
      }
    }
  }

  b_st.site = &hc_emlrtRSI;
  xzlarf(&b_st, 1, 1, 6, tau[1], a, 9, work);
  a[5] = alpha1;
}

/* End of code generation (xgehrd.c) */
