/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzlarfg.c
 *
 * Code generation for function 'xzlarfg'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "xzlarfg.h"
#include "eml_int_forloop_overflow_check.h"
#include "xscal.h"
#include "xnrm2.h"
#include "xdlapy3.h"
#include "recip.h"
#include "trqp_multipliers_data.h"

/* Function Definitions */
creal_T b_xzlarfg(const emlrtStack *sp, creal_T *alpha1, creal_T *x)
{
  creal_T tau;
  real_T xnorm;
  real_T beta1;
  int32_T knt;
  real_T ai;
  creal_T b_alpha1;
  real_T x_re;
  real_T x_im;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  tau.re = 0.0;
  tau.im = 0.0;
  xnorm = muDoubleScalarHypot(x->re, x->im);
  if ((xnorm != 0.0) || (alpha1->im != 0.0)) {
    st.site = &eg_emlrtRSI;
    beta1 = xdlapy3(alpha1->re, alpha1->im, xnorm);
    if (alpha1->re >= 0.0) {
      beta1 = -beta1;
    }

    if (muDoubleScalarAbs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        x->re *= 9.9792015476736E+291;
        x->im *= 9.9792015476736E+291;
        beta1 *= 9.9792015476736E+291;
        alpha1->re *= 9.9792015476736E+291;
        alpha1->im *= 9.9792015476736E+291;
      } while (!(muDoubleScalarAbs(beta1) >= 1.0020841800044864E-292));

      st.site = &fg_emlrtRSI;
      beta1 = xdlapy3(alpha1->re, alpha1->im, muDoubleScalarHypot(x->re, x->im));
      if (alpha1->re >= 0.0) {
        beta1 = -beta1;
      }

      xnorm = beta1 - alpha1->re;
      ai = 0.0 - alpha1->im;
      if (ai == 0.0) {
        tau.re = xnorm / beta1;
        tau.im = 0.0;
      } else if (xnorm == 0.0) {
        tau.re = 0.0;
        tau.im = ai / beta1;
      } else {
        tau.re = xnorm / beta1;
        tau.im = ai / beta1;
      }

      b_alpha1.re = alpha1->re - beta1;
      b_alpha1.im = alpha1->im;
      *alpha1 = recip(b_alpha1);
      xnorm = alpha1->re;
      ai = alpha1->im;
      x_re = x->re;
      x_im = x->im;
      x->re = xnorm * x_re - ai * x_im;
      x->im = xnorm * x_im + ai * x_re;
      st.site = &fd_emlrtRSI;
      if ((1 <= knt) && (knt > 2147483646)) {
        b_st.site = &bb_emlrtRSI;
        check_forloop_overflow_error(&b_st, true);
      }

      for (k = 0; k < knt; k++) {
        beta1 *= 1.0020841800044864E-292;
      }

      alpha1->re = beta1;
      alpha1->im = 0.0;
    } else {
      xnorm = beta1 - alpha1->re;
      ai = 0.0 - alpha1->im;
      if (ai == 0.0) {
        tau.re = xnorm / beta1;
        tau.im = 0.0;
      } else if (xnorm == 0.0) {
        tau.re = 0.0;
        tau.im = ai / beta1;
      } else {
        tau.re = xnorm / beta1;
        tau.im = ai / beta1;
      }

      b_alpha1.re = alpha1->re - beta1;
      b_alpha1.im = alpha1->im;
      *alpha1 = recip(b_alpha1);
      xnorm = alpha1->re;
      ai = alpha1->im;
      x_re = x->re;
      x_im = x->im;
      x->re = xnorm * x_re - ai * x_im;
      x->im = xnorm * x_im + ai * x_re;
      alpha1->re = beta1;
      alpha1->im = 0.0;
    }
  }

  return tau;
}

real_T xzlarfg(const emlrtStack *sp, int32_T n, real_T *alpha1, real_T x[3])
{
  real_T tau;
  real_T xnorm;
  int32_T knt;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  tau = 0.0;
  if (n > 0) {
    st.site = &bd_emlrtRSI;
    xnorm = b_xnrm2(&st, n - 1, x);
    if (xnorm != 0.0) {
      xnorm = muDoubleScalarHypot(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          st.site = &cd_emlrtRSI;
          xscal(&st, n - 1, 9.9792015476736E+291, x);
          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(muDoubleScalarAbs(xnorm) >= 1.0020841800044864E-292));

        st.site = &dd_emlrtRSI;
        xnorm = b_xnrm2(&st, n - 1, x);
        xnorm = muDoubleScalarHypot(*alpha1, xnorm);
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }

        tau = (xnorm - *alpha1) / xnorm;
        st.site = &ed_emlrtRSI;
        xscal(&st, n - 1, 1.0 / (*alpha1 - xnorm), x);
        st.site = &fd_emlrtRSI;
        if ((1 <= knt) && (knt > 2147483646)) {
          b_st.site = &bb_emlrtRSI;
          check_forloop_overflow_error(&b_st, true);
        }

        for (k = 0; k < knt; k++) {
          xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        st.site = &gd_emlrtRSI;
        xscal(&st, n - 1, 1.0 / (*alpha1 - xnorm), x);
        *alpha1 = xnorm;
      }
    }
  }

  return tau;
}

/* End of code generation (xzlarfg.c) */
