/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzhgeqz.c
 *
 * Code generation for function 'xzhgeqz'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "xzhgeqz.h"
#include "eml_int_forloop_overflow_check.h"
#include "xzlartg.h"
#include "sqrt.h"
#include "mod.h"
#include "xzlanhs.h"
#include "trqp_control_data.h"

/* Variable Definitions */
static emlrtRSInfo uf_emlrtRSI = { 37, /* lineNo */
  "xzhgeqz",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"/* pathName */
};

static emlrtRSInfo vf_emlrtRSI = { 51, /* lineNo */
  "xzhgeqz",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"/* pathName */
};

static emlrtRSInfo wf_emlrtRSI = { 111,/* lineNo */
  "xzhgeqz",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"/* pathName */
};

static emlrtRSInfo xf_emlrtRSI = { 391,/* lineNo */
  "xzhgeqz",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"/* pathName */
};

static emlrtRSInfo yf_emlrtRSI = { 398,/* lineNo */
  "xzhgeqz",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"/* pathName */
};

static emlrtRSInfo ag_emlrtRSI = { 401,/* lineNo */
  "xzhgeqz",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"/* pathName */
};

static emlrtRSInfo bg_emlrtRSI = { 410,/* lineNo */
  "xzhgeqz",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"/* pathName */
};

static emlrtRSInfo cg_emlrtRSI = { 412,/* lineNo */
  "xzhgeqz",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"/* pathName */
};

static emlrtRSInfo dg_emlrtRSI = { 424,/* lineNo */
  "xzhgeqz",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"/* pathName */
};

static emlrtRSInfo eg_emlrtRSI = { 436,/* lineNo */
  "xzhgeqz",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"/* pathName */
};

/* Function Definitions */
void xzhgeqz(const emlrtStack *sp, creal_T A[9], int32_T ilo, int32_T ihi,
             creal_T Z[9], int32_T *info, creal_T alpha1[3], creal_T beta1[3])
{
  real_T eshift_re;
  real_T eshift_im;
  creal_T ctemp;
  real_T anorm;
  real_T temp;
  real_T b_atol;
  real_T ascale;
  boolean_T failed;
  int32_T jp1;
  int32_T j;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int32_T ifirst;
  int32_T istart;
  int32_T ilast;
  int32_T ilastm1;
  int32_T iiter;
  int32_T maxit;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  int32_T jiter;
  int32_T exitg1;
  boolean_T b_guard1 = false;
  boolean_T guard3 = false;
  boolean_T exitg2;
  creal_T b_ascale;
  real_T tempr;
  creal_T shift;
  real_T ascale_re;
  real_T ascale_im;
  int32_T A_tmp;
  real_T stemp_re;
  real_T stemp_im;
  real_T t1_re;
  real_T t1_im;
  int32_T shift_re_tmp;
  real_T t1_im_tmp;
  int32_T stemp_re_tmp;
  real_T b_ascale_re;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  *info = 0;
  alpha1[0].re = 0.0;
  alpha1[0].im = 0.0;
  beta1[0].re = 1.0;
  beta1[0].im = 0.0;
  alpha1[1].re = 0.0;
  alpha1[1].im = 0.0;
  beta1[1].re = 1.0;
  beta1[1].im = 0.0;
  alpha1[2].re = 0.0;
  alpha1[2].im = 0.0;
  beta1[2].re = 1.0;
  beta1[2].im = 0.0;
  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp.re = 0.0;
  ctemp.im = 0.0;
  st.site = &uf_emlrtRSI;
  anorm = xzlanhs(&st, A, ilo, ihi);
  temp = 2.2204460492503131E-16 * anorm;
  b_atol = 2.2250738585072014E-308;
  if (temp > 2.2250738585072014E-308) {
    b_atol = temp;
  }

  temp = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    temp = anorm;
  }

  ascale = 1.0 / temp;
  failed = true;
  jp1 = ihi + 1;
  st.site = &vf_emlrtRSI;
  for (j = jp1; j < 4; j++) {
    alpha1[j - 1] = A[(j + 3 * (j - 1)) - 1];
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    ifirst = ilo;
    istart = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    iiter = 0;
    maxit = 30 * ((ihi - ilo) + 1);
    goto60 = false;
    goto70 = false;
    goto90 = false;
    st.site = &wf_emlrtRSI;
    if ((1 <= maxit) && (maxit > 2147483646)) {
      b_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    jiter = 0;
    do {
      exitg1 = 0;
      if (jiter <= maxit - 1) {
        b_guard1 = false;
        if (ilast + 1 == ilo) {
          goto60 = true;
          b_guard1 = true;
        } else {
          jp1 = ilast + 3 * ilastm1;
          if (muDoubleScalarAbs(A[jp1].re) + muDoubleScalarAbs(A[ilast + 3 *
               ilastm1].im) <= b_atol) {
            A[jp1].re = 0.0;
            A[jp1].im = 0.0;
            goto60 = true;
            b_guard1 = true;
          } else {
            j = ilastm1;
            guard3 = false;
            exitg2 = false;
            while ((!exitg2) && (j + 1 >= ilo)) {
              if (j + 1 == ilo) {
                guard3 = true;
                exitg2 = true;
              } else {
                jp1 = j + 3 * (j - 1);
                if (muDoubleScalarAbs(A[jp1].re) + muDoubleScalarAbs(A[j + 3 *
                     (j - 1)].im) <= b_atol) {
                  A[jp1].re = 0.0;
                  A[jp1].im = 0.0;
                  guard3 = true;
                  exitg2 = true;
                } else {
                  j--;
                  guard3 = false;
                }
              }
            }

            if (guard3) {
              ifirst = j + 1;
              goto70 = true;
            }

            if (goto70) {
              b_guard1 = true;
            } else {
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
              for (jp1 = 0; jp1 < 9; jp1++) {
                Z[jp1].re = rtNaN;
                Z[jp1].im = 0.0;
              }

              *info = 1;
              exitg1 = 1;
            }
          }
        }

        if (b_guard1) {
          if (goto60) {
            goto60 = false;
            alpha1[ilast] = A[ilast + 3 * ilast];
            ilast = ilastm1;
            ilastm1--;
            if (ilast + 1 < ilo) {
              failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              iiter = 0;
              eshift_re = 0.0;
              eshift_im = 0.0;
              jiter++;
            }
          } else {
            if (goto70) {
              goto70 = false;
              iiter++;
              if (b_mod(iiter) != 0) {
                anorm = ascale * A[ilastm1 + 3 * ilastm1].re;
                temp = ascale * A[ilastm1 + 3 * ilastm1].im;
                if (temp == 0.0) {
                  shift.re = anorm / 0.57735026918962584;
                  shift.im = 0.0;
                } else if (anorm == 0.0) {
                  shift.re = 0.0;
                  shift.im = temp / 0.57735026918962584;
                } else {
                  shift.re = anorm / 0.57735026918962584;
                  shift.im = temp / 0.57735026918962584;
                }

                anorm = ascale * A[ilast + 3 * ilast].re;
                temp = ascale * A[ilast + 3 * ilast].im;
                if (temp == 0.0) {
                  stemp_re = anorm / 0.57735026918962584;
                  stemp_im = 0.0;
                } else if (anorm == 0.0) {
                  stemp_re = 0.0;
                  stemp_im = temp / 0.57735026918962584;
                } else {
                  stemp_re = anorm / 0.57735026918962584;
                  stemp_im = temp / 0.57735026918962584;
                }

                t1_re = 0.5 * (shift.re + stemp_re);
                t1_im = 0.5 * (shift.im + stemp_im);
                t1_im_tmp = t1_re * t1_im;
                anorm = ascale * A[ilastm1 + 3 * ilast].re;
                temp = ascale * A[ilastm1 + 3 * ilast].im;
                if (temp == 0.0) {
                  ascale_re = anorm / 0.57735026918962584;
                  ascale_im = 0.0;
                } else if (anorm == 0.0) {
                  ascale_re = 0.0;
                  ascale_im = temp / 0.57735026918962584;
                } else {
                  ascale_re = anorm / 0.57735026918962584;
                  ascale_im = temp / 0.57735026918962584;
                }

                anorm = ascale * A[ilast + 3 * ilastm1].re;
                temp = ascale * A[ilast + 3 * ilastm1].im;
                if (temp == 0.0) {
                  b_ascale_re = anorm / 0.57735026918962584;
                  anorm = 0.0;
                } else if (anorm == 0.0) {
                  b_ascale_re = 0.0;
                  anorm = temp / 0.57735026918962584;
                } else {
                  b_ascale_re = anorm / 0.57735026918962584;
                  anorm = temp / 0.57735026918962584;
                }

                temp = shift.re * stemp_re - shift.im * stemp_im;
                tempr = shift.re * stemp_im + shift.im * stemp_re;
                shift.re = ((t1_re * t1_re - t1_im * t1_im) + (ascale_re *
                  b_ascale_re - ascale_im * anorm)) - temp;
                shift.im = ((t1_im_tmp + t1_im_tmp) + (ascale_re * anorm +
                  ascale_im * b_ascale_re)) - tempr;
                c_sqrt(&shift);
                if ((t1_re - stemp_re) * shift.re + (t1_im - stemp_im) *
                    shift.im <= 0.0) {
                  shift.re += t1_re;
                  shift.im += t1_im;
                } else {
                  shift.re = t1_re - shift.re;
                  shift.im = t1_im - shift.im;
                }
              } else {
                temp = ascale * A[ilast + 3 * ilastm1].re;
                anorm = ascale * A[ilast + 3 * ilastm1].im;
                if (anorm == 0.0) {
                  ascale_re = temp / 0.57735026918962584;
                  ascale_im = 0.0;
                } else if (temp == 0.0) {
                  ascale_re = 0.0;
                  ascale_im = anorm / 0.57735026918962584;
                } else {
                  ascale_re = temp / 0.57735026918962584;
                  ascale_im = anorm / 0.57735026918962584;
                }

                eshift_re += ascale_re;
                eshift_im += ascale_im;
                shift.re = eshift_re;
                shift.im = eshift_im;
              }

              j = ilastm1;
              jp1 = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && (j + 1 > ifirst)) {
                istart = j + 1;
                ctemp.re = ascale * A[j + 3 * j].re - shift.re *
                  0.57735026918962584;
                ctemp.im = ascale * A[j + 3 * j].im - shift.im *
                  0.57735026918962584;
                temp = muDoubleScalarAbs(ctemp.re) + muDoubleScalarAbs(ctemp.im);
                anorm = ascale * (muDoubleScalarAbs(A[jp1 + 3 * j].re) +
                                  muDoubleScalarAbs(A[jp1 + 3 * j].im));
                tempr = temp;
                if (anorm > temp) {
                  tempr = anorm;
                }

                if ((tempr < 1.0) && (tempr != 0.0)) {
                  temp /= tempr;
                  anorm /= tempr;
                }

                if ((muDoubleScalarAbs(A[j + 3 * (j - 1)].re) +
                     muDoubleScalarAbs(A[j + 3 * (j - 1)].im)) * anorm <= temp *
                    b_atol) {
                  goto90 = true;
                  exitg2 = true;
                } else {
                  jp1 = j;
                  j--;
                }
              }

              if (!goto90) {
                istart = ifirst;
                ctemp.re = ascale * A[(ifirst + 3 * (ifirst - 1)) - 1].re -
                  shift.re * 0.57735026918962584;
                ctemp.im = ascale * A[(ifirst + 3 * (ifirst - 1)) - 1].im -
                  shift.im * 0.57735026918962584;
                goto90 = true;
              }
            }

            if (goto90) {
              goto90 = false;
              b_ascale.re = ascale * A[istart + 3 * (istart - 1)].re;
              b_ascale.im = ascale * A[istart + 3 * (istart - 1)].im;
              st.site = &xf_emlrtRSI;
              b_xzlartg(&st, ctemp, b_ascale, &tempr, &shift);
              j = istart;
              jp1 = istart - 2;
              while (j < ilast + 1) {
                if (j > istart) {
                  A_tmp = j + 3 * jp1;
                  st.site = &yf_emlrtRSI;
                  xzlartg(&st, A[A_tmp - 1], A[A_tmp], &tempr, &shift, &A[(j + 3
                           * jp1) - 1]);
                  A[A_tmp].re = 0.0;
                  A[A_tmp].im = 0.0;
                }

                st.site = &ag_emlrtRSI;
                b_st.site = &sf_emlrtRSI;
                for (jp1 = j; jp1 < 4; jp1++) {
                  shift_re_tmp = j + 3 * (jp1 - 1);
                  stemp_re_tmp = shift_re_tmp - 1;
                  stemp_re = tempr * A[stemp_re_tmp].re + (shift.re *
                    A[shift_re_tmp].re - shift.im * A[j + 3 * (jp1 - 1)].im);
                  stemp_im = tempr * A[(j + 3 * (jp1 - 1)) - 1].im + (shift.re *
                    A[j + 3 * (jp1 - 1)].im + shift.im * A[j + 3 * (jp1 - 1)].re);
                  anorm = A[(j + 3 * (jp1 - 1)) - 1].im;
                  temp = A[(j + 3 * (jp1 - 1)) - 1].re;
                  A[shift_re_tmp].re = tempr * A[j + 3 * (jp1 - 1)].re -
                    (shift.re * A[(j + 3 * (jp1 - 1)) - 1].re + shift.im * A[(j
                      + 3 * (jp1 - 1)) - 1].im);
                  A[shift_re_tmp].im = tempr * A[j + 3 * (jp1 - 1)].im -
                    (shift.re * anorm - shift.im * temp);
                  A[stemp_re_tmp].re = stemp_re;
                  A[stemp_re_tmp].im = stemp_im;
                }

                shift.re = -shift.re;
                shift.im = -shift.im;
                jp1 = j + 2;
                if (ilast + 1 < j + 2) {
                  jp1 = ilast + 1;
                }

                st.site = &bg_emlrtRSI;
                b_st.site = &tf_emlrtRSI;
                if ((1 <= jp1) && (jp1 > 2147483646)) {
                  c_st.site = &bb_emlrtRSI;
                  check_forloop_overflow_error(&c_st, true);
                }

                for (A_tmp = 1; A_tmp <= jp1; A_tmp++) {
                  shift_re_tmp = (A_tmp + 3 * (j - 1)) - 1;
                  stemp_re_tmp = (A_tmp + 3 * j) - 1;
                  stemp_re = tempr * A[stemp_re_tmp].re + (shift.re *
                    A[shift_re_tmp].re - shift.im * A[(A_tmp + 3 * (j - 1)) - 1]
                    .im);
                  stemp_im = tempr * A[(A_tmp + 3 * j) - 1].im + (shift.re * A
                    [(A_tmp + 3 * (j - 1)) - 1].im + shift.im * A[(A_tmp + 3 *
                    (j - 1)) - 1].re);
                  anorm = A[(A_tmp + 3 * j) - 1].im;
                  temp = A[(A_tmp + 3 * j) - 1].re;
                  A[shift_re_tmp].re = tempr * A[(A_tmp + 3 * (j - 1)) - 1].re -
                    (shift.re * A[(A_tmp + 3 * j) - 1].re + shift.im * A[(A_tmp
                      + 3 * j) - 1].im);
                  A[shift_re_tmp].im = tempr * A[(A_tmp + 3 * (j - 1)) - 1].im -
                    (shift.re * anorm - shift.im * temp);
                  A[stemp_re_tmp].re = stemp_re;
                  A[stemp_re_tmp].im = stemp_im;
                }

                st.site = &cg_emlrtRSI;
                b_st.site = &tf_emlrtRSI;
                stemp_re = tempr * Z[3 * j].re + (shift.re * Z[3 * (j - 1)].re -
                  shift.im * Z[3 * (j - 1)].im);
                stemp_im = tempr * Z[3 * j].im + (shift.re * Z[3 * (j - 1)].im +
                  shift.im * Z[3 * (j - 1)].re);
                anorm = Z[3 * j].im;
                temp = Z[3 * j].re;
                Z[3 * (j - 1)].re = tempr * Z[3 * (j - 1)].re - (shift.re * Z[3 *
                  j].re + shift.im * Z[3 * j].im);
                Z[3 * (j - 1)].im = tempr * Z[3 * (j - 1)].im - (shift.re *
                  anorm - shift.im * temp);
                Z[3 * j].re = stemp_re;
                Z[3 * j].im = stemp_im;
                shift_re_tmp = 1 + 3 * (j - 1);
                stemp_re_tmp = 1 + 3 * j;
                stemp_re = tempr * Z[stemp_re_tmp].re + (shift.re *
                  Z[shift_re_tmp].re - shift.im * Z[1 + 3 * (j - 1)].im);
                stemp_im = tempr * Z[1 + 3 * j].im + (shift.re * Z[1 + 3 * (j -
                  1)].im + shift.im * Z[1 + 3 * (j - 1)].re);
                anorm = Z[1 + 3 * j].im;
                temp = Z[1 + 3 * j].re;
                Z[shift_re_tmp].re = tempr * Z[1 + 3 * (j - 1)].re - (shift.re *
                  Z[1 + 3 * j].re + shift.im * Z[1 + 3 * j].im);
                Z[shift_re_tmp].im = tempr * Z[1 + 3 * (j - 1)].im - (shift.re *
                  anorm - shift.im * temp);
                Z[stemp_re_tmp].re = stemp_re;
                Z[stemp_re_tmp].im = stemp_im;
                shift_re_tmp = 2 + 3 * (j - 1);
                stemp_re_tmp = 2 + 3 * j;
                stemp_re = tempr * Z[stemp_re_tmp].re + (shift.re *
                  Z[shift_re_tmp].re - shift.im * Z[2 + 3 * (j - 1)].im);
                stemp_im = tempr * Z[2 + 3 * j].im + (shift.re * Z[2 + 3 * (j -
                  1)].im + shift.im * Z[2 + 3 * (j - 1)].re);
                anorm = Z[2 + 3 * j].im;
                temp = Z[2 + 3 * j].re;
                Z[shift_re_tmp].re = tempr * Z[2 + 3 * (j - 1)].re - (shift.re *
                  Z[2 + 3 * j].re + shift.im * Z[2 + 3 * j].im);
                Z[shift_re_tmp].im = tempr * Z[2 + 3 * (j - 1)].im - (shift.re *
                  anorm - shift.im * temp);
                Z[stemp_re_tmp].re = stemp_re;
                Z[stemp_re_tmp].im = stemp_im;
                jp1 = j - 1;
                j++;
              }
            }

            jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      st.site = &dg_emlrtRSI;
      if ((1 <= ilast + 1) && (ilast + 1 > 2147483646)) {
        b_st.site = &bb_emlrtRSI;
        check_forloop_overflow_error(&b_st, true);
      }

      for (jp1 = 0; jp1 <= ilast; jp1++) {
        alpha1[jp1].re = rtNaN;
        alpha1[jp1].im = 0.0;
        beta1[jp1].re = rtNaN;
        beta1[jp1].im = 0.0;
      }

      for (jp1 = 0; jp1 < 9; jp1++) {
        Z[jp1].re = rtNaN;
        Z[jp1].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    st.site = &eg_emlrtRSI;
    if ((1 <= ilo - 1) && (ilo - 1 > 2147483646)) {
      b_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    for (j = 0; j <= ilo - 2; j++) {
      alpha1[j] = A[j + 3 * j];
    }
  }
}

/* End of code generation (xzhgeqz.c) */
