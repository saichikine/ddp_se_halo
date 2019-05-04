/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trqp_multipliers.c
 *
 * Code generation for function 'trqp_multipliers'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "xpotrf.h"
#include "inv.h"
#include "eig.h"
#include "relop.h"
#include "mldivide.h"
#include "norm.h"
#include "sqrt.h"
#include "toLogicalCheck.h"
#include "trqp_multipliers_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 15,    /* lineNo */
  "trqp_multipliers",                  /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_multipliers.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 16,  /* lineNo */
  "trqp_multipliers",                  /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_multipliers.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 36,  /* lineNo */
  "trqp_multipliers",                  /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_multipliers.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 56,  /* lineNo */
  "trqp_multipliers",                  /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_multipliers.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 57,  /* lineNo */
  "trqp_multipliers",                  /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_multipliers.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 65,  /* lineNo */
  "trqp_multipliers",                  /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_multipliers.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 70,  /* lineNo */
  "trqp_multipliers",                  /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_multipliers.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 87,  /* lineNo */
  "trqp_multipliers",                  /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_multipliers.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 94,  /* lineNo */
  "trqp_multipliers",                  /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_multipliers.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 95,  /* lineNo */
  "trqp_multipliers",                  /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_multipliers.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 99,  /* lineNo */
  "trqp_multipliers",                  /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_multipliers.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 100, /* lineNo */
  "trqp_multipliers",                  /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_multipliers.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 34,  /* lineNo */
  "chol",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\chol.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 80,  /* lineNo */
  23,                                  /* colNo */
  "cholesky",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\chol.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 68,/* lineNo */
  13,                                  /* colNo */
  "cholesky",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\chol.m"/* pName */
};

/* Function Definitions */
void trqp_multipliers(const emlrtStack *sp, real_T H[36], real_T g[6], real_T
                      delta, const real_T M[36], creal_T s_out[6], creal_T
                      H_out[36], boolean_T *bool_TRQP_failure)
{
  int32_T counter;
  int32_T i0;
  int32_T i;
  real_T SinvT[36];
  int32_T j;
  real_T ST[36];
  real_T y;
  real_T b_ST[6];
  real_T Ma;
  real_T S[36];
  int32_T working;
  real_T c_ST[36];
  creal_T v[36];
  creal_T w[6];
  creal_T min_eig;
  creal_T max_eig;
  real_T lambda_p_re;
  creal_T b_w;
  real_T lambda_p_im;
  boolean_T b0;
  boolean_T b1;
  boolean_T p;
  real_T ma;
  creal_T H_tilde[36];
  static const int8_T b[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  int32_T exitg1;
  creal_T L[36];
  creal_T b_L[36];
  creal_T s[6];
  real_T re;
  real_T im;
  real_T a_re;
  real_T a_im;
  real_T b_re;
  real_T b_im;
  real_T y_re;
  real_T y_im;
  real_T b_re_tmp;
  real_T b_im_tmp;
  int32_T exitg2;
  real_T ai;
  real_T alpha1_re;
  real_T alpha1_im;
  creal_T s2[6];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  counter = 0;
  for (i0 = 0; i0 < 36; i0++) {
    H_out[i0].re = H[i0] * 0.0;
    H_out[i0].im = 0.0;
  }

  for (i = 0; i < 6; i++) {
    s_out[i].re = g[i] * 0.0;
    s_out[i].im = 0.0;
  }

  st.site = &emlrtRSI;
  b_st.site = &m_emlrtRSI;
  memcpy(&SinvT[0], &M[0], 36U * sizeof(real_T));
  i = xpotrf(SinvT);
  if (i == 0) {
  } else {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI, "Coder:MATLAB:posdef",
      "Coder:MATLAB:posdef", 0);
  }

  for (j = 2; j < 7; j++) {
    for (i = 0; i <= j - 2; i++) {
      SinvT[i + 6 * (j - 1)] = 0.0;
    }
  }

  st.site = &b_emlrtRSI;
  inv(&st, SinvT, ST);
  for (i0 = 0; i0 < 6; i0++) {
    y = 0.0;
    for (i = 0; i < 6; i++) {
      Ma = ST[i0 + 6 * i];
      S[i + 6 * i0] = Ma;
      y += Ma * g[i];
    }

    b_ST[i0] = y;
  }

  for (i0 = 0; i0 < 6; i0++) {
    g[i0] = b_ST[i0];
    for (i = 0; i < 6; i++) {
      y = 0.0;
      for (j = 0; j < 6; j++) {
        y += ST[i0 + 6 * j] * H[j + 6 * i];
      }

      c_ST[i0 + 6 * i] = y;
    }
  }

  for (i0 = 0; i0 < 6; i0++) {
    for (i = 0; i < 6; i++) {
      y = 0.0;
      for (j = 0; j < 6; j++) {
        y += c_ST[i0 + 6 * j] * S[j + 6 * i];
      }

      H[i0 + 6 * i] = y;
    }
  }

  *bool_TRQP_failure = false;

  /*  TRQP algorithm 7.3.6 */
  /*  find model minimizer when eigensolution is cheap */
  working = 1;

  /*  Check for blowup */
  /*      try */
  /*          [v,l] = eig(H,'vector'); */
  /*      catch */
  /*          H_out = eye(size(H_in))*1e16; */
  /*          s_out = zeros(size(g)); */
  /*          warning('H blew up in TRQP'); */
  /*          return */
  /*      end */
  st.site = &c_emlrtRSI;
  eig(&st, H, v, w);
  min_eig = w[0];
  max_eig = w[0];
  for (j = 0; j < 5; j++) {
    b_w = w[j + 1];
    b0 = muDoubleScalarIsNaN(b_w.re);
    b1 = muDoubleScalarIsNaN(w[j + 1].im);
    if (b0 || b1) {
      p = false;
    } else if (muDoubleScalarIsNaN(min_eig.re) || muDoubleScalarIsNaN(min_eig.im))
    {
      p = true;
    } else {
      absRelopProxies(min_eig, b_w, &Ma, &y);
      p = (Ma > y);
    }

    if (p) {
      min_eig = b_w;
    }

    if (b0 || b1) {
      p = false;
    } else if (muDoubleScalarIsNaN(max_eig.re) || muDoubleScalarIsNaN(max_eig.im))
    {
      p = true;
    } else {
      absRelopProxies(max_eig, b_w, &Ma, &y);
      p = (Ma < y);
    }

    if (p) {
      max_eig = b_w;
    }
  }

  lambda_p_re = 0.0;
  lambda_p_im = 0.0;
  if (muDoubleScalarHypot(max_eig.re, max_eig.im) > 1.0E+10) {
    *bool_TRQP_failure = true;

    /*              H_out = 1e16*eye(size(H_in)); */
    /*              s_out = zeros(size(g)); */
  } else {
    if (min_eig.re < 1.0E-15) {
      /*  n.d */
      lambda_p_re = 1.01 * -min_eig.re;
      lambda_p_im = 1.01 * -min_eig.im;
      ma = muDoubleScalarAbs(lambda_p_re);
      if ((ma > 8.9884656743115785E+307) || (muDoubleScalarAbs(lambda_p_im) >
           8.9884656743115785E+307)) {
        Ma = muDoubleScalarHypot(lambda_p_re / 2.0, lambda_p_im / 2.0);
        y = 5.0E-16;
      } else {
        Ma = muDoubleScalarHypot(lambda_p_re, lambda_p_im);
        y = 1.0E-15;
      }

      if (Ma == y) {
        y = muDoubleScalarAbs(lambda_p_im);
        if (ma > y) {
          Ma = ma;
          ma = y;
        } else {
          Ma = y;
        }

        if (Ma > 1.0E-15) {
          ma = Ma;
          y = 1.0E-15;
        } else if (Ma < 1.0E-15) {
          if (ma > 0.0) {
            y = 1.0E-15 - Ma;
            ma *= ma / 2.0 / (Ma / 2.0 + 5.0E-16);
          } else {
            ma = Ma;
            y = 1.0E-15;
          }
        } else {
          y = 0.0;
        }

        Ma = ma;
        if (ma == y) {
          Ma = muDoubleScalarAtan2(lambda_p_im, lambda_p_re);
          y = 0.0;
          if (Ma == 0.0) {
            Ma = lambda_p_im;
            if (lambda_p_im == 0.0) {
              Ma = 0.0;
            }
          }
        }
      }

      if (Ma < y) {
        lambda_p_re = 1.0E-15;
        lambda_p_im = 0.0;
      }
    }

    /*  zero eigenvalue */
    for (i0 = 0; i0 < 36; i0++) {
      H_tilde[i0].re = H[i0] + lambda_p_re * (real_T)b[i0];
      H_tilde[i0].im = lambda_p_im * (real_T)b[i0];
    }

    st.site = &d_emlrtRSI;
    b_st.site = &m_emlrtRSI;
    j = 0;
    do {
      exitg1 = 0;
      if (j < 6) {
        if (H_tilde[j + 6 * j].im != 0.0) {
          emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
            "Coder:MATLAB:chol_matrixMustBePosDefWithRealDiag",
            "Coder:MATLAB:chol_matrixMustBePosDefWithRealDiag", 0);
        } else {
          j++;
        }
      } else {
        memcpy(&L[0], &H_tilde[0], 36U * sizeof(creal_T));
        i = b_xpotrf(L);
        if (i == 0) {
        } else {
          emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI, "Coder:MATLAB:posdef",
            "Coder:MATLAB:posdef", 0);
        }

        for (j = 2; j < 7; j++) {
          for (i = 0; i <= j - 2; i++) {
            i0 = i + 6 * (j - 1);
            L[i0].re = 0.0;
            L[i0].im = 0.0;
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);

    for (i0 = 0; i0 < 6; i0++) {
      for (i = 0; i < 6; i++) {
        re = 0.0;
        im = 0.0;
        for (j = 0; j < 6; j++) {
          y = L[i + 6 * j].re;
          Ma = -L[i + 6 * j].im;
          re += L[i0 + 6 * j].re * y - L[i0 + 6 * j].im * Ma;
          im += L[i0 + 6 * j].re * Ma + L[i0 + 6 * j].im * y;
        }

        j = i0 + 6 * i;
        b_L[j].re = -re;
        b_L[j].im = -im;
      }
    }

    st.site = &e_emlrtRSI;
    mldivide(&st, b_L, g, s);

    /*  Step 3 */
    if (c_norm(s) <= delta) {
      /*              if lambda_p == 0 || norm(s) == delta */
      if (((lambda_p_re == 0.0) && (lambda_p_im == 0.0)) || (c_norm(s) - delta <
           1.0E-10 * delta)) {
        working = 0;
      } else {
        st.site = &f_emlrtRSI;
        b_eig(&st, H_tilde, v, w);
        i = 0;
        min_eig = w[0];
        for (j = 0; j < 5; j++) {
          b_w = w[j + 1];
          if (muDoubleScalarIsNaN(b_w.re) || muDoubleScalarIsNaN(w[j + 1].im)) {
            p = false;
          } else if (muDoubleScalarIsNaN(min_eig.re) || muDoubleScalarIsNaN
                     (min_eig.im)) {
            p = true;
          } else {
            absRelopProxies(min_eig, b_w, &Ma, &y);
            p = (Ma > y);
          }

          if (p) {
            min_eig = b_w;
            i = j + 1;
          }
        }

        a_re = 0.0;
        a_im = 0.0;
        b_re = 0.0;
        b_im = 0.0;
        y_re = 0.0;
        y_im = 0.0;
        for (j = 0; j < 6; j++) {
          re = v[j + 6 * i].re;
          im = v[j + 6 * i].im;
          a_re += re * re - -im * im;
          a_im += re * im + -im * re;
          y = 2.0 * s[j].re;
          Ma = 2.0 * -s[j].im;
          b_re += y * re - Ma * im;
          b_im += y * im + Ma * re;
          y_re += s[j].re * s[j].re - -s[j].im * s[j].im;
          y_im += s[j].re * s[j].im + -s[j].im * s[j].re;
        }

        st.site = &g_emlrtRSI;
        min_eig.re = y_re - delta * delta;
        b_re_tmp = b_re * b_re - b_im * b_im;
        b_im_tmp = b_re * b_im;
        b_im_tmp += b_im_tmp;
        re = 4.0 * a_re;
        im = 4.0 * a_im;
        max_eig.re = b_re_tmp - (re * min_eig.re - im * y_im);
        max_eig.im = b_im_tmp - (re * y_im + im * min_eig.re);
        c_sqrt(&max_eig);
        im = -b_re + max_eig.re;
        ai = -b_im + max_eig.im;
        ma = 2.0 * a_re;
        y_re = 2.0 * a_im;
        if (y_re == 0.0) {
          if (ai == 0.0) {
            alpha1_re = im / ma;
            alpha1_im = 0.0;
          } else if (im == 0.0) {
            alpha1_re = 0.0;
            alpha1_im = ai / ma;
          } else {
            alpha1_re = im / ma;
            alpha1_im = ai / ma;
          }
        } else if (ma == 0.0) {
          if (im == 0.0) {
            alpha1_re = ai / y_re;
            alpha1_im = 0.0;
          } else if (ai == 0.0) {
            alpha1_re = 0.0;
            alpha1_im = -(im / y_re);
          } else {
            alpha1_re = ai / y_re;
            alpha1_im = -(im / y_re);
          }
        } else {
          re = muDoubleScalarAbs(ma);
          y = muDoubleScalarAbs(y_re);
          if (re > y) {
            Ma = y_re / ma;
            y = ma + Ma * y_re;
            alpha1_re = (im + Ma * ai) / y;
            alpha1_im = (ai - Ma * im) / y;
          } else if (y == re) {
            if (ma > 0.0) {
              Ma = 0.5;
            } else {
              Ma = -0.5;
            }

            if (y_re > 0.0) {
              y = 0.5;
            } else {
              y = -0.5;
            }

            alpha1_re = (im * Ma + ai * y) / re;
            alpha1_im = (ai * Ma - im * y) / re;
          } else {
            Ma = ma / y_re;
            y = y_re + Ma * ma;
            alpha1_re = (Ma * im + ai) / y;
            alpha1_im = (Ma * ai - im) / y;
          }
        }

        re = 4.0 * a_re;
        im = 4.0 * a_im;
        max_eig.re = b_re_tmp - (re * min_eig.re - im * y_im);
        max_eig.im = b_im_tmp - (re * y_im + im * min_eig.re);
        c_sqrt(&max_eig);
        im = -b_re - max_eig.re;
        ai = -b_im - max_eig.im;
        ma = 2.0 * a_re;
        y_re = 2.0 * a_im;
        if (y_re == 0.0) {
          if (ai == 0.0) {
            min_eig.re = im / ma;
            min_eig.im = 0.0;
          } else if (im == 0.0) {
            min_eig.re = 0.0;
            min_eig.im = ai / ma;
          } else {
            min_eig.re = im / ma;
            min_eig.im = ai / ma;
          }
        } else if (ma == 0.0) {
          if (im == 0.0) {
            min_eig.re = ai / y_re;
            min_eig.im = 0.0;
          } else if (ai == 0.0) {
            min_eig.re = 0.0;
            min_eig.im = -(im / y_re);
          } else {
            min_eig.re = ai / y_re;
            min_eig.im = -(im / y_re);
          }
        } else {
          re = muDoubleScalarAbs(ma);
          y = muDoubleScalarAbs(y_re);
          if (re > y) {
            Ma = y_re / ma;
            y = ma + Ma * y_re;
            min_eig.re = (im + Ma * ai) / y;
            min_eig.im = (ai - Ma * im) / y;
          } else if (y == re) {
            if (ma > 0.0) {
              Ma = 0.5;
            } else {
              Ma = -0.5;
            }

            if (y_re > 0.0) {
              y = 0.5;
            } else {
              y = -0.5;
            }

            min_eig.re = (im * Ma + ai * y) / re;
            min_eig.im = (ai * Ma - im * y) / re;
          } else {
            Ma = ma / y_re;
            y = y_re + Ma * ma;
            min_eig.re = (Ma * im + ai) / y;
            min_eig.im = (Ma * ai - im) / y;
          }
        }

        for (i0 = 0; i0 < 6; i0++) {
          re = v[i0 + 6 * i].re;
          im = v[i0 + 6 * i].im;
          w[i0].re = s[i0].re + (alpha1_re * re - alpha1_im * im);
          w[i0].im = s[i0].im + (alpha1_re * im + alpha1_im * re);
          s2[i0].re = s[i0].re + (min_eig.re * re - min_eig.im * im);
          s2[i0].im = s[i0].im + (min_eig.re * im + min_eig.im * re);
        }

        for (i0 = 0; i0 < 36; i0++) {
          b_L[i0].re = H[i0];
          b_L[i0].im = 0.0;
        }

        y_re = 0.0;
        y_im = 0.0;
        for (j = 0; j < 6; j++) {
          re = 0.0;
          im = 0.0;
          for (i0 = 0; i0 < 6; i0++) {
            re += w[i0].re * b_L[i0 + 6 * j].re - -w[i0].im * b_L[i0 + 6 * j].im;
            im += w[i0].re * b_L[i0 + 6 * j].im + -w[i0].im * b_L[i0 + 6 * j].re;
          }

          y_re += re * w[j].re - im * w[j].im;
          y_im += re * w[j].im + im * w[j].re;
        }

        for (i0 = 0; i0 < 36; i0++) {
          b_L[i0].re = H[i0];
          b_L[i0].im = 0.0;
        }

        max_eig.re = 0.0;
        max_eig.im = 0.0;
        ma = 0.0;
        for (j = 0; j < 6; j++) {
          re = 0.0;
          im = 0.0;
          for (i0 = 0; i0 < 6; i0++) {
            re += s2[i0].re * b_L[i0 + 6 * j].re - -s2[i0].im * b_L[i0 + 6 * j].
              im;
            im += s2[i0].re * b_L[i0 + 6 * j].im + -s2[i0].im * b_L[i0 + 6 * j].
              re;
          }

          max_eig.re += re * s2[j].re - im * s2[j].im;
          max_eig.im += re * s2[j].im + im * s2[j].re;
          ma += g[j] * w[j].re - 0.0 * w[j].im;
        }

        Ma = 0.0;
        for (i0 = 0; i0 < 6; i0++) {
          Ma += g[i0] * s2[i0].re - 0.0 * s2[i0].im;
        }

        if (y_im == 0.0) {
          y_re /= 2.0;
        } else if (y_re == 0.0) {
          y_re = 0.0;
        } else {
          y_re /= 2.0;
        }

        if (max_eig.im == 0.0) {
          y = max_eig.re / 2.0;
        } else if (max_eig.re == 0.0) {
          y = 0.0;
        } else {
          y = max_eig.re / 2.0;
        }

        if (ma + y_re < Ma + y) {
          min_eig.re = alpha1_re;
          min_eig.im = alpha1_im;
        }

        for (i0 = 0; i0 < 6; i0++) {
          s[i0].re += v[i0 + 6 * i].re * min_eig.re - v[i0 + 6 * i].im *
            min_eig.im;
          s[i0].im += v[i0 + 6 * i].re * min_eig.im + v[i0 + 6 * i].im *
            min_eig.re;
        }

        working = 0;
      }
    }

    do {
      exitg1 = 0;
      st.site = &h_emlrtRSI;
      toLogicalCheck(&st, working);
      if ((working != 0) && (counter < 100)) {
        /*  Step 4 */
        y = c_norm(s) - delta;
        if (muDoubleScalarAbs(y) <= 1.0E-10 * delta) {
          exitg1 = 1;
        } else {
          /*  Step 5 */
          memcpy(&w[0], &s[0], 6U * sizeof(creal_T));
          st.site = &i_emlrtRSI;
          b_mldivide(&st, L, w);
          st.site = &j_emlrtRSI;
          Ma = c_norm(s) / c_norm(w);
          lambda_p_re += y / delta * (Ma * Ma);

          /*  Step 6 */
          for (i0 = 0; i0 < 36; i0++) {
            H_tilde[i0].re = H[i0] + lambda_p_re * (real_T)b[i0];
            H_tilde[i0].im = lambda_p_im * (real_T)b[i0];
          }

          st.site = &k_emlrtRSI;
          b_st.site = &m_emlrtRSI;
          j = 0;
          do {
            exitg2 = 0;
            if (j < 6) {
              if (H_tilde[j + 6 * j].im != 0.0) {
                emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
                  "Coder:MATLAB:chol_matrixMustBePosDefWithRealDiag",
                  "Coder:MATLAB:chol_matrixMustBePosDefWithRealDiag", 0);
              } else {
                j++;
              }
            } else {
              memcpy(&L[0], &H_tilde[0], 36U * sizeof(creal_T));
              i = b_xpotrf(L);
              if (i == 0) {
              } else {
                emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
                  "Coder:MATLAB:posdef", "Coder:MATLAB:posdef", 0);
              }

              for (j = 2; j < 7; j++) {
                for (i = 0; i <= j - 2; i++) {
                  i0 = i + 6 * (j - 1);
                  L[i0].re = 0.0;
                  L[i0].im = 0.0;
                }
              }

              exitg2 = 1;
            }
          } while (exitg2 == 0);

          for (i0 = 0; i0 < 6; i0++) {
            for (i = 0; i < 6; i++) {
              re = 0.0;
              im = 0.0;
              for (j = 0; j < 6; j++) {
                y = L[i + 6 * j].re;
                Ma = -L[i + 6 * j].im;
                re += L[i0 + 6 * j].re * y - L[i0 + 6 * j].im * Ma;
                im += L[i0 + 6 * j].re * Ma + L[i0 + 6 * j].im * y;
              }

              j = i0 + 6 * i;
              b_L[j].re = -re;
              b_L[j].im = -im;
            }
          }

          st.site = &l_emlrtRSI;
          mldivide(&st, b_L, g, s);
          counter++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if ((counter >= 100) && (!(muDoubleScalarAbs(c_norm(s) - delta) <= 1.0E-9 *
          delta))) {
      *bool_TRQP_failure = true;

      /* warning("TRQP iteration limit exceeded; model minimzer not satisfactory."); */
    }

    for (i0 = 0; i0 < 36; i0++) {
      b_L[i0].re = SinvT[i0];
      b_L[i0].im = 0.0;
    }

    for (i0 = 0; i0 < 6; i0++) {
      for (i = 0; i < 6; i++) {
        re = 0.0;
        im = 0.0;
        for (j = 0; j < 6; j++) {
          re += b_L[i0 + 6 * j].re * H_tilde[j + 6 * i].re - b_L[i0 + 6 * j].im *
            H_tilde[j + 6 * i].im;
          im += b_L[i0 + 6 * j].re * H_tilde[j + 6 * i].im + b_L[i0 + 6 * j].im *
            H_tilde[j + 6 * i].re;
        }

        j = i0 + 6 * i;
        v[j].re = re;
        v[j].im = im;
      }
    }

    for (i0 = 0; i0 < 6; i0++) {
      for (i = 0; i < 6; i++) {
        j = i + 6 * i0;
        b_L[j].re = SinvT[i0 + 6 * i];
        b_L[j].im = 0.0;
      }
    }

    for (i0 = 0; i0 < 6; i0++) {
      for (i = 0; i < 6; i++) {
        re = 0.0;
        im = 0.0;
        for (j = 0; j < 6; j++) {
          re += v[i0 + 6 * j].re * b_L[j + 6 * i].re - v[i0 + 6 * j].im * b_L[j
            + 6 * i].im;
          im += v[i0 + 6 * j].re * b_L[j + 6 * i].im + v[i0 + 6 * j].im * b_L[j
            + 6 * i].re;
        }

        j = i0 + 6 * i;
        H_out[j].re = re;
        H_out[j].im = im;
      }
    }

    for (i0 = 0; i0 < 36; i0++) {
      b_L[i0].re = S[i0];
      b_L[i0].im = 0.0;
    }

    for (i0 = 0; i0 < 6; i0++) {
      re = 0.0;
      im = 0.0;
      for (i = 0; i < 6; i++) {
        re += b_L[i0 + 6 * i].re * s[i].re - b_L[i0 + 6 * i].im * s[i].im;
        im += b_L[i0 + 6 * i].re * s[i].im + b_L[i0 + 6 * i].im * s[i].re;
      }

      s_out[i0].re = re;
      s_out[i0].im = im;
    }
  }
}

/* End of code generation (trqp_multipliers.c) */
