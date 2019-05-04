/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzggev.c
 *
 * Code generation for function 'xzggev'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "xzggev.h"
#include "eml_int_forloop_overflow_check.h"
#include "xzlartg.h"
#include "xztgevc.h"
#include "xzhgeqz.h"
#include "xzggbal.h"
#include "trqp_control_data.h"

/* Variable Definitions */
static emlrtRSInfo ue_emlrtRSI = { 39, /* lineNo */
  "xzggev",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"/* pathName */
};

static emlrtRSInfo ve_emlrtRSI = { 84, /* lineNo */
  "xzggev",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"/* pathName */
};

static emlrtRSInfo we_emlrtRSI = { 100,/* lineNo */
  "xzggev",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"/* pathName */
};

static emlrtRSInfo xe_emlrtRSI = { 101,/* lineNo */
  "xzggev",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"/* pathName */
};

static emlrtRSInfo ye_emlrtRSI = { 106,/* lineNo */
  "xzggev",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"/* pathName */
};

static emlrtRSInfo af_emlrtRSI = { 108,/* lineNo */
  "xzggev",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"/* pathName */
};

static emlrtRSInfo kf_emlrtRSI = { 62, /* lineNo */
  "xzgghrd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"/* pathName */
};

static emlrtRSInfo lf_emlrtRSI = { 64, /* lineNo */
  "xzgghrd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"/* pathName */
};

static emlrtRSInfo mf_emlrtRSI = { 77, /* lineNo */
  "xzgghrd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"/* pathName */
};

static emlrtRSInfo nf_emlrtRSI = { 79, /* lineNo */
  "xzgghrd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"/* pathName */
};

static emlrtRSInfo ig_emlrtRSI = { 32, /* lineNo */
  "xzggbak",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbak.m"/* pathName */
};

/* Function Definitions */
void xzggev(const emlrtStack *sp, creal_T A[9], int32_T *info, creal_T alpha1[3],
            creal_T beta1[3], creal_T V[9])
{
  real_T anrm;
  int32_T k;
  boolean_T exitg1;
  real_T absxk;
  boolean_T ilascl;
  real_T anrmto;
  int32_T ilo;
  int32_T ihi;
  int32_T rscale[3];
  real_T ctoc;
  boolean_T notdone;
  int32_T tmp_re_tmp;
  int8_T b_I[9];
  real_T cfrom1;
  real_T stemp_re;
  real_T stemp_im;
  int32_T jcol;
  int32_T jcolp1;
  int32_T jrow;
  int32_T i;
  creal_T tmp;
  int32_T stemp_re_tmp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  *info = 0;
  st.site = &ue_emlrtRSI;
  anrm = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    absxk = muDoubleScalarHypot(A[k].re, A[k].im);
    if (muDoubleScalarIsNaN(absxk)) {
      anrm = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }

      k++;
    }
  }

  if (muDoubleScalarIsInf(anrm) || muDoubleScalarIsNaN(anrm)) {
    alpha1[0].re = rtNaN;
    alpha1[0].im = 0.0;
    beta1[0].re = rtNaN;
    beta1[0].im = 0.0;
    alpha1[1].re = rtNaN;
    alpha1[1].im = 0.0;
    beta1[1].re = rtNaN;
    beta1[1].im = 0.0;
    alpha1[2].re = rtNaN;
    alpha1[2].im = 0.0;
    beta1[2].re = rtNaN;
    beta1[2].im = 0.0;
    for (tmp_re_tmp = 0; tmp_re_tmp < 9; tmp_re_tmp++) {
      V[tmp_re_tmp].re = rtNaN;
      V[tmp_re_tmp].im = 0.0;
    }
  } else {
    ilascl = false;
    anrmto = anrm;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      anrmto = 6.7178761075670888E-139;
      ilascl = true;
    } else {
      if (anrm > 1.4885657073574029E+138) {
        anrmto = 1.4885657073574029E+138;
        ilascl = true;
      }
    }

    if (ilascl) {
      absxk = anrm;
      ctoc = anrmto;
      notdone = true;
      while (notdone) {
        cfrom1 = absxk * 2.0041683600089728E-292;
        stemp_re = ctoc / 4.9896007738368E+291;
        if ((cfrom1 > ctoc) && (ctoc != 0.0)) {
          stemp_im = 2.0041683600089728E-292;
          absxk = cfrom1;
        } else if (stemp_re > absxk) {
          stemp_im = 4.9896007738368E+291;
          ctoc = stemp_re;
        } else {
          stemp_im = ctoc / absxk;
          notdone = false;
        }

        for (tmp_re_tmp = 0; tmp_re_tmp < 9; tmp_re_tmp++) {
          A[tmp_re_tmp].re *= stemp_im;
          A[tmp_re_tmp].im *= stemp_im;
        }
      }
    }

    st.site = &ve_emlrtRSI;
    xzggbal(&st, A, &ilo, &ihi, rscale);
    st.site = &we_emlrtRSI;
    for (tmp_re_tmp = 0; tmp_re_tmp < 9; tmp_re_tmp++) {
      b_I[tmp_re_tmp] = 0;
    }

    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    for (tmp_re_tmp = 0; tmp_re_tmp < 9; tmp_re_tmp++) {
      V[tmp_re_tmp].re = b_I[tmp_re_tmp];
      V[tmp_re_tmp].im = 0.0;
    }

    if (ihi >= ilo + 2) {
      for (jcol = ilo - 1; jcol + 1 < ihi - 1; jcol++) {
        jcolp1 = jcol + 2;
        for (jrow = ihi - 1; jrow + 1 > jcol + 2; jrow--) {
          k = jrow + 3 * jcol;
          b_st.site = &kf_emlrtRSI;
          xzlartg(&b_st, A[k - 1], A[k], &cfrom1, &tmp, &A[(jrow + 3 * jcol) - 1]);
          A[k].re = 0.0;
          A[k].im = 0.0;
          b_st.site = &lf_emlrtRSI;
          c_st.site = &sf_emlrtRSI;
          for (k = jcolp1; k < 4; k++) {
            tmp_re_tmp = jrow + 3 * (k - 1);
            stemp_re_tmp = tmp_re_tmp - 1;
            stemp_re = cfrom1 * A[stemp_re_tmp].re + (tmp.re * A[tmp_re_tmp].re
              - tmp.im * A[jrow + 3 * (k - 1)].im);
            stemp_im = cfrom1 * A[(jrow + 3 * (k - 1)) - 1].im + (tmp.re *
              A[jrow + 3 * (k - 1)].im + tmp.im * A[jrow + 3 * (k - 1)].re);
            absxk = A[(jrow + 3 * (k - 1)) - 1].im;
            ctoc = A[(jrow + 3 * (k - 1)) - 1].re;
            A[tmp_re_tmp].re = cfrom1 * A[jrow + 3 * (k - 1)].re - (tmp.re * A
              [(jrow + 3 * (k - 1)) - 1].re + tmp.im * A[(jrow + 3 * (k - 1)) -
              1].im);
            A[tmp_re_tmp].im = cfrom1 * A[jrow + 3 * (k - 1)].im - (tmp.re *
              absxk - tmp.im * ctoc);
            A[stemp_re_tmp].re = stemp_re;
            A[stemp_re_tmp].im = stemp_im;
          }

          tmp.re = -tmp.re;
          tmp.im = -tmp.im;
          b_st.site = &mf_emlrtRSI;
          c_st.site = &tf_emlrtRSI;
          if ((1 <= ihi) && (ihi > 2147483646)) {
            d_st.site = &bb_emlrtRSI;
            check_forloop_overflow_error(&d_st, true);
          }

          for (i = 1; i <= ihi; i++) {
            tmp_re_tmp = (i + 3 * (jrow - 1)) - 1;
            stemp_re_tmp = (i + 3 * jrow) - 1;
            stemp_re = cfrom1 * A[stemp_re_tmp].re + (tmp.re * A[tmp_re_tmp].re
              - tmp.im * A[(i + 3 * (jrow - 1)) - 1].im);
            stemp_im = cfrom1 * A[(i + 3 * jrow) - 1].im + (tmp.re * A[(i + 3 *
              (jrow - 1)) - 1].im + tmp.im * A[(i + 3 * (jrow - 1)) - 1].re);
            absxk = A[(i + 3 * jrow) - 1].im;
            ctoc = A[(i + 3 * jrow) - 1].re;
            A[tmp_re_tmp].re = cfrom1 * A[(i + 3 * (jrow - 1)) - 1].re - (tmp.re
              * A[(i + 3 * jrow) - 1].re + tmp.im * A[(i + 3 * jrow) - 1].im);
            A[tmp_re_tmp].im = cfrom1 * A[(i + 3 * (jrow - 1)) - 1].im - (tmp.re
              * absxk - tmp.im * ctoc);
            A[stemp_re_tmp].re = stemp_re;
            A[stemp_re_tmp].im = stemp_im;
          }

          b_st.site = &nf_emlrtRSI;
          c_st.site = &tf_emlrtRSI;
          stemp_re = cfrom1 * V[3 * jrow].re + (tmp.re * V[3 * (jrow - 1)].re -
            tmp.im * V[3 * (jrow - 1)].im);
          stemp_im = cfrom1 * V[3 * jrow].im + (tmp.re * V[3 * (jrow - 1)].im +
            tmp.im * V[3 * (jrow - 1)].re);
          absxk = V[3 * jrow].re;
          V[3 * (jrow - 1)].re = cfrom1 * V[3 * (jrow - 1)].re - (tmp.re * V[3 *
            jrow].re + tmp.im * V[3 * jrow].im);
          V[3 * (jrow - 1)].im = cfrom1 * V[3 * (jrow - 1)].im - (tmp.re * V[3 *
            jrow].im - tmp.im * absxk);
          V[3 * jrow].re = stemp_re;
          V[3 * jrow].im = stemp_im;
          tmp_re_tmp = 1 + 3 * (jrow - 1);
          stemp_re_tmp = 1 + 3 * jrow;
          stemp_re = cfrom1 * V[stemp_re_tmp].re + (tmp.re * V[tmp_re_tmp].re -
            tmp.im * V[1 + 3 * (jrow - 1)].im);
          stemp_im = cfrom1 * V[1 + 3 * jrow].im + (tmp.re * V[1 + 3 * (jrow - 1)]
            .im + tmp.im * V[1 + 3 * (jrow - 1)].re);
          absxk = V[1 + 3 * jrow].re;
          V[tmp_re_tmp].re = cfrom1 * V[1 + 3 * (jrow - 1)].re - (tmp.re * V[1 +
            3 * jrow].re + tmp.im * V[1 + 3 * jrow].im);
          V[tmp_re_tmp].im = cfrom1 * V[tmp_re_tmp].im - (tmp.re * V[1 + 3 *
            jrow].im - tmp.im * absxk);
          V[stemp_re_tmp].re = stemp_re;
          V[stemp_re_tmp].im = stemp_im;
          tmp_re_tmp = 2 + 3 * (jrow - 1);
          stemp_re_tmp = 2 + 3 * jrow;
          stemp_re = cfrom1 * V[stemp_re_tmp].re + (tmp.re * V[tmp_re_tmp].re -
            tmp.im * V[2 + 3 * (jrow - 1)].im);
          stemp_im = cfrom1 * V[2 + 3 * jrow].im + (tmp.re * V[2 + 3 * (jrow - 1)]
            .im + tmp.im * V[2 + 3 * (jrow - 1)].re);
          absxk = V[2 + 3 * jrow].re;
          V[tmp_re_tmp].re = cfrom1 * V[2 + 3 * (jrow - 1)].re - (tmp.re * V[2 +
            3 * jrow].re + tmp.im * V[2 + 3 * jrow].im);
          V[tmp_re_tmp].im = cfrom1 * V[tmp_re_tmp].im - (tmp.re * V[2 + 3 *
            jrow].im - tmp.im * absxk);
          V[stemp_re_tmp].re = stemp_re;
          V[stemp_re_tmp].im = stemp_im;
        }
      }
    }

    st.site = &xe_emlrtRSI;
    xzhgeqz(&st, A, ilo, ihi, V, info, alpha1, beta1);
    if (*info == 0) {
      st.site = &ye_emlrtRSI;
      xztgevc(&st, A, V);
      st.site = &af_emlrtRSI;
      if (ilo > 1) {
        for (i = ilo - 2; i + 1 >= 1; i--) {
          k = rscale[i] - 1;
          if (rscale[i] != i + 1) {
            tmp = V[i];
            V[i] = V[k];
            V[k] = tmp;
            tmp = V[i + 3];
            V[i + 3] = V[k + 3];
            V[k + 3] = tmp;
            tmp = V[i + 6];
            V[i + 6] = V[k + 6];
            V[k + 6] = tmp;
          }
        }
      }

      if (ihi < 3) {
        tmp_re_tmp = ihi + 1;
        b_st.site = &ig_emlrtRSI;
        for (i = tmp_re_tmp; i < 4; i++) {
          k = rscale[i - 1];
          if (k != i) {
            tmp = V[i - 1];
            V[i - 1] = V[k - 1];
            V[k - 1] = tmp;
            tmp = V[i + 2];
            V[i + 2] = V[k + 2];
            V[k + 2] = tmp;
            tmp = V[i + 5];
            V[i + 5] = V[k + 5];
            V[k + 5] = tmp;
          }
        }
      }

      for (k = 0; k < 3; k++) {
        absxk = muDoubleScalarAbs(V[3 * k].re) + muDoubleScalarAbs(V[3 * k].im);
        tmp_re_tmp = 3 * k + 1;
        ctoc = muDoubleScalarAbs(V[tmp_re_tmp].re) + muDoubleScalarAbs
          (V[tmp_re_tmp].im);
        if (ctoc > absxk) {
          absxk = ctoc;
        }

        stemp_re_tmp = 3 * k + 2;
        ctoc = muDoubleScalarAbs(V[stemp_re_tmp].re) + muDoubleScalarAbs
          (V[stemp_re_tmp].im);
        if (ctoc > absxk) {
          absxk = ctoc;
        }

        if (absxk >= 6.7178761075670888E-139) {
          absxk = 1.0 / absxk;
          V[3 * k].re *= absxk;
          V[3 * k].im *= absxk;
          V[tmp_re_tmp].re *= absxk;
          V[tmp_re_tmp].im *= absxk;
          V[stemp_re_tmp].re *= absxk;
          V[stemp_re_tmp].im *= absxk;
        }
      }

      if (ilascl) {
        notdone = true;
        while (notdone) {
          cfrom1 = anrmto * 2.0041683600089728E-292;
          stemp_re = anrm / 4.9896007738368E+291;
          if ((cfrom1 > anrm) && (anrm != 0.0)) {
            stemp_im = 2.0041683600089728E-292;
            anrmto = cfrom1;
          } else if (stemp_re > anrmto) {
            stemp_im = 4.9896007738368E+291;
            anrm = stemp_re;
          } else {
            stemp_im = anrm / anrmto;
            notdone = false;
          }

          alpha1[0].re *= stemp_im;
          alpha1[0].im *= stemp_im;
          alpha1[1].re *= stemp_im;
          alpha1[1].im *= stemp_im;
          alpha1[2].re *= stemp_im;
          alpha1[2].im *= stemp_im;
        }
      }
    }
  }
}

/* End of code generation (xzggev.c) */
