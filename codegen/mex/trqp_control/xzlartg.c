/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzlartg.c
 *
 * Code generation for function 'xzlartg'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "xzlartg.h"
#include "eml_int_forloop_overflow_check.h"
#include "trqp_control_data.h"

/* Variable Definitions */
static emlrtRSInfo of_emlrtRSI = { 67, /* lineNo */
  "xzlartg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlartg.m"/* pathName */
};

static emlrtRSInfo pf_emlrtRSI = { 93, /* lineNo */
  "xzlartg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlartg.m"/* pathName */
};

static emlrtRSInfo qf_emlrtRSI = { 102,/* lineNo */
  "xzlartg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlartg.m"/* pathName */
};

static emlrtRSInfo rf_emlrtRSI = { 106,/* lineNo */
  "xzlartg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlartg.m"/* pathName */
};

/* Function Definitions */
void b_xzlartg(const emlrtStack *sp, const creal_T f, const creal_T g, real_T
               *cs, creal_T *sn)
{
  real_T y_tmp;
  real_T scale;
  real_T b_y_tmp;
  real_T f2s;
  real_T f2;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  int32_T count;
  int32_T rescaledir;
  boolean_T guard1 = false;
  real_T g2s;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  y_tmp = muDoubleScalarAbs(f.re);
  scale = y_tmp;
  b_y_tmp = muDoubleScalarAbs(f.im);
  if (b_y_tmp > y_tmp) {
    scale = b_y_tmp;
  }

  f2s = muDoubleScalarAbs(g.re);
  f2 = muDoubleScalarAbs(g.im);
  if (f2 > f2s) {
    f2s = f2;
  }

  if (f2s > scale) {
    scale = f2s;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = 0;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));

    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    f2 = fs_re * fs_re + fs_im * fs_im;
    scale = gs_re * gs_re + gs_im * gs_im;
    f2s = scale;
    if (1.0 > scale) {
      f2s = 1.0;
    }

    if (f2 <= f2s * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        scale = muDoubleScalarHypot(gs_re, gs_im);
        sn->re = gs_re / scale;
        sn->im = -gs_im / scale;
      } else {
        st.site = &of_emlrtRSI;
        if (scale < 0.0) {
          emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
            "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
            3, 4, 4, "sqrt");
        }

        g2s = muDoubleScalarSqrt(scale);
        *cs = muDoubleScalarHypot(fs_re, fs_im) / g2s;
        if (b_y_tmp > y_tmp) {
          y_tmp = b_y_tmp;
        }

        if (y_tmp > 1.0) {
          scale = muDoubleScalarHypot(f.re, f.im);
          fs_re = f.re / scale;
          fs_im = f.im / scale;
        } else {
          f2s = 7.4428285367870146E+137 * f.re;
          f2 = 7.4428285367870146E+137 * f.im;
          scale = muDoubleScalarHypot(f2s, f2);
          fs_re = f2s / scale;
          fs_im = f2 / scale;
        }

        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
      }
    } else {
      st.site = &pf_emlrtRSI;
      f2s = 1.0 + scale / f2;
      if (f2s < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      f2s = muDoubleScalarSqrt(f2s);
      *cs = 1.0 / f2s;
      scale += f2;
      fs_re = f2s * fs_re / scale;
      fs_im = f2s * fs_im / scale;
      sn->re = fs_re * gs_re - fs_im * -gs_im;
      sn->im = fs_re * -gs_im + fs_im * gs_re;
      if (rescaledir > 0) {
        st.site = &qf_emlrtRSI;
        if ((1 <= count) && (count > 2147483646)) {
          b_st.site = &bb_emlrtRSI;
          check_forloop_overflow_error(&b_st, true);
        }
      } else {
        if (rescaledir < 0) {
          st.site = &rf_emlrtRSI;
          if ((1 <= count) && (count > 2147483646)) {
            b_st.site = &bb_emlrtRSI;
            check_forloop_overflow_error(&b_st, true);
          }
        }
      }
    }
  }
}

void xzlartg(const emlrtStack *sp, const creal_T f, const creal_T g, real_T *cs,
             creal_T *sn, creal_T *r)
{
  real_T y_tmp;
  real_T scale;
  real_T b_y_tmp;
  real_T f2s;
  real_T f2;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  int32_T count;
  int32_T rescaledir;
  boolean_T guard1 = false;
  real_T g2s;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  y_tmp = muDoubleScalarAbs(f.re);
  scale = y_tmp;
  b_y_tmp = muDoubleScalarAbs(f.im);
  if (b_y_tmp > y_tmp) {
    scale = b_y_tmp;
  }

  f2s = muDoubleScalarAbs(g.re);
  f2 = muDoubleScalarAbs(g.im);
  if (f2 > f2s) {
    f2s = f2;
  }

  if (f2s > scale) {
    scale = f2s;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = 0;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));

    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
      *r = f;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    f2 = fs_re * fs_re + fs_im * fs_im;
    scale = gs_re * gs_re + gs_im * gs_im;
    f2s = scale;
    if (1.0 > scale) {
      f2s = 1.0;
    }

    if (f2 <= f2s * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        r->re = muDoubleScalarHypot(g.re, g.im);
        r->im = 0.0;
        scale = muDoubleScalarHypot(gs_re, gs_im);
        sn->re = gs_re / scale;
        sn->im = -gs_im / scale;
      } else {
        st.site = &of_emlrtRSI;
        if (scale < 0.0) {
          emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
            "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
            3, 4, 4, "sqrt");
        }

        g2s = muDoubleScalarSqrt(scale);
        *cs = muDoubleScalarHypot(fs_re, fs_im) / g2s;
        if (b_y_tmp > y_tmp) {
          y_tmp = b_y_tmp;
        }

        if (y_tmp > 1.0) {
          scale = muDoubleScalarHypot(f.re, f.im);
          fs_re = f.re / scale;
          fs_im = f.im / scale;
        } else {
          f2 = 7.4428285367870146E+137 * f.re;
          f2s = 7.4428285367870146E+137 * f.im;
          scale = muDoubleScalarHypot(f2, f2s);
          fs_re = f2 / scale;
          fs_im = f2s / scale;
        }

        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
        r->re = *cs * f.re + (sn->re * g.re - sn->im * g.im);
        r->im = *cs * f.im + (sn->re * g.im + sn->im * g.re);
      }
    } else {
      st.site = &pf_emlrtRSI;
      f2s = 1.0 + scale / f2;
      if (f2s < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      f2s = muDoubleScalarSqrt(f2s);
      r->re = f2s * fs_re;
      r->im = f2s * fs_im;
      *cs = 1.0 / f2s;
      scale += f2;
      f2 = r->re / scale;
      f2s = r->im / scale;
      sn->re = f2 * gs_re - f2s * -gs_im;
      sn->im = f2 * -gs_im + f2s * gs_re;
      if (rescaledir > 0) {
        st.site = &qf_emlrtRSI;
        if ((1 <= count) && (count > 2147483646)) {
          b_st.site = &bb_emlrtRSI;
          check_forloop_overflow_error(&b_st, true);
        }

        for (rescaledir = 0; rescaledir < count; rescaledir++) {
          r->re *= 7.4428285367870146E+137;
          r->im *= 7.4428285367870146E+137;
        }
      } else {
        if (rescaledir < 0) {
          st.site = &rf_emlrtRSI;
          if ((1 <= count) && (count > 2147483646)) {
            b_st.site = &bb_emlrtRSI;
            check_forloop_overflow_error(&b_st, true);
          }

          for (rescaledir = 0; rescaledir < count; rescaledir++) {
            r->re *= 1.3435752215134178E-138;
            r->im *= 1.3435752215134178E-138;
          }
        }
      }
    }
  }
}

/* End of code generation (xzlartg.c) */
