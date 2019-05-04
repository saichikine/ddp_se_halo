/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trqp_control.c
 *
 * Code generation for function 'trqp_control'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "xpotrf.h"
#include "inv.h"
#include "eig.h"
#include "relop.h"
#include "mldivide.h"
#include "norm.h"
#include "sqrt.h"
#include "warning.h"
#include "trqp_control_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 15,    /* lineNo */
  "trqp_control",                      /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_control.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 16,  /* lineNo */
  "trqp_control",                      /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_control.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 36,  /* lineNo */
  "trqp_control",                      /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_control.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 56,  /* lineNo */
  "trqp_control",                      /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_control.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 57,  /* lineNo */
  "trqp_control",                      /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_control.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 65,  /* lineNo */
  "trqp_control",                      /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_control.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 70,  /* lineNo */
  "trqp_control",                      /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_control.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 87,  /* lineNo */
  "trqp_control",                      /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_control.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 94,  /* lineNo */
  "trqp_control",                      /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_control.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 95,  /* lineNo */
  "trqp_control",                      /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_control.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 99,  /* lineNo */
  "trqp_control",                      /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_control.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 100, /* lineNo */
  "trqp_control",                      /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\trqp_control.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 34,  /* lineNo */
  "chol",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\chol.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 74,  /* lineNo */
  "cholesky",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\chol.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 84,  /* lineNo */
  "cholesky",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\chol.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 85,  /* lineNo */
  "cholesky",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\chol.m"/* pathName */
};

static emlrtRSInfo ph_emlrtRSI = { 45, /* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\mpower.m"/* pathName */
};

static emlrtRSInfo qh_emlrtRSI = { 55, /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
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
void trqp_control(const emlrtStack *sp, real_T H[9], real_T g[3], real_T delta,
                  const real_T M[9], creal_T s_out[3], creal_T H_out[9],
                  boolean_T *bool_TRQP_failure)
{
  int32_T counter;
  int32_T rtemp;
  real_T SinvT[9];
  int32_T r1;
  real_T ST[9];
  int32_T r2;
  real_T S[9];
  real_T im;
  real_T b_ST[3];
  real_T Ma;
  real_T c_ST[9];
  int32_T working;
  creal_T v[9];
  creal_T w[3];
  creal_T min_eig;
  creal_T max_eig;
  boolean_T b0;
  boolean_T b1;
  boolean_T p;
  real_T a21;
  real_T lambda_p_re;
  real_T lambda_p_im;
  real_T ma;
  creal_T H_tilde[9];
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  int32_T exitg1;
  creal_T L[9];
  creal_T b_L[9];
  creal_T s[3];
  real_T L_im;
  real_T re;
  int32_T jmax;
  real_T a_re;
  real_T a_im;
  real_T b_re;
  real_T b_im;
  real_T brm;
  real_T y_im;
  real_T b_re_tmp;
  real_T b_im_tmp;
  real_T alpha1_re;
  real_T alpha1_im;
  creal_T s2[3];
  int32_T exitg2;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
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
  counter = 0;
  for (rtemp = 0; rtemp < 9; rtemp++) {
    H_out[rtemp].re = H[rtemp] * 0.0;
    H_out[rtemp].im = 0.0;
  }

  s_out[0].re = g[0] * 0.0;
  s_out[0].im = 0.0;
  s_out[1].re = g[1] * 0.0;
  s_out[1].im = 0.0;
  s_out[2].re = g[2] * 0.0;
  s_out[2].im = 0.0;
  st.site = &emlrtRSI;
  b_st.site = &m_emlrtRSI;
  memcpy(&SinvT[0], &M[0], 9U * sizeof(real_T));
  c_st.site = &n_emlrtRSI;
  r1 = xpotrf(SinvT);
  if (r1 == 0) {
  } else {
    emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI, "Coder:MATLAB:posdef",
      "Coder:MATLAB:posdef", 0);
  }

  c_st.site = &o_emlrtRSI;
  for (r1 = 2; r1 < 4; r1++) {
    c_st.site = &p_emlrtRSI;
    for (r2 = 0; r2 <= r1 - 2; r2++) {
      SinvT[r2 + 3 * (r1 - 1)] = 0.0;
    }
  }

  st.site = &b_emlrtRSI;
  inv(&st, SinvT, ST);
  for (rtemp = 0; rtemp < 3; rtemp++) {
    S[3 * rtemp] = ST[rtemp];
    im = ST[rtemp + 3];
    S[1 + 3 * rtemp] = im;
    Ma = ST[rtemp] * g[0] + im * g[1];
    im = ST[rtemp + 6];
    S[2 + 3 * rtemp] = im;
    Ma += im * g[2];
    b_ST[rtemp] = Ma;
  }

  for (rtemp = 0; rtemp < 3; rtemp++) {
    g[rtemp] = b_ST[rtemp];
    for (r1 = 0; r1 < 3; r1++) {
      c_ST[rtemp + 3 * r1] = (ST[rtemp] * H[3 * r1] + ST[rtemp + 3] * H[1 + 3 *
        r1]) + ST[rtemp + 6] * H[2 + 3 * r1];
    }
  }

  for (rtemp = 0; rtemp < 3; rtemp++) {
    for (r1 = 0; r1 < 3; r1++) {
      H[rtemp + 3 * r1] = (c_ST[rtemp] * S[3 * r1] + c_ST[rtemp + 3] * S[1 + 3 *
                           r1]) + c_ST[rtemp + 6] * S[2 + 3 * r1];
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
  b0 = muDoubleScalarIsNaN(w[1].re);
  b1 = muDoubleScalarIsNaN(w[1].im);
  if (b0 || b1) {
    p = false;
  } else if (muDoubleScalarIsNaN(w[0].re) || muDoubleScalarIsNaN(w[0].im)) {
    p = true;
  } else {
    absRelopProxies(w[0], w[1], &Ma, &a21);
    p = (Ma > a21);
  }

  if (p) {
    min_eig = w[1];
  }

  if (b0 || b1) {
    p = false;
  } else if (muDoubleScalarIsNaN(w[0].re) || muDoubleScalarIsNaN(w[0].im)) {
    p = true;
  } else {
    absRelopProxies(w[0], w[1], &Ma, &a21);
    p = (Ma < a21);
  }

  if (p) {
    max_eig = w[1];
  }

  b0 = muDoubleScalarIsNaN(w[2].re);
  b1 = muDoubleScalarIsNaN(w[2].im);
  if (b0 || b1) {
    p = false;
  } else if (muDoubleScalarIsNaN(min_eig.re) || muDoubleScalarIsNaN(min_eig.im))
  {
    p = true;
  } else {
    absRelopProxies(min_eig, w[2], &Ma, &a21);
    p = (Ma > a21);
  }

  if (p) {
    min_eig = w[2];
  }

  if (b0 || b1) {
    p = false;
  } else if (muDoubleScalarIsNaN(max_eig.re) || muDoubleScalarIsNaN(max_eig.im))
  {
    p = true;
  } else {
    absRelopProxies(max_eig, w[2], &Ma, &a21);
    p = (Ma < a21);
  }

  if (p) {
    max_eig = w[2];
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
        a21 = 5.0E-16;
      } else {
        Ma = muDoubleScalarHypot(lambda_p_re, lambda_p_im);
        a21 = 1.0E-15;
      }

      if (Ma == a21) {
        im = muDoubleScalarAbs(lambda_p_im);
        if (ma > im) {
          Ma = ma;
          ma = im;
        } else {
          Ma = im;
        }

        if (Ma > 1.0E-15) {
          ma = Ma;
          a21 = 1.0E-15;
        } else if (Ma < 1.0E-15) {
          if (ma > 0.0) {
            a21 = 1.0E-15 - Ma;
            ma *= ma / 2.0 / (Ma / 2.0 + 5.0E-16);
          } else {
            ma = Ma;
            a21 = 1.0E-15;
          }
        } else {
          a21 = 0.0;
        }

        Ma = ma;
        if (ma == a21) {
          Ma = muDoubleScalarAtan2(lambda_p_im, lambda_p_re);
          a21 = 0.0;
          if (Ma == 0.0) {
            Ma = lambda_p_im;
            if (lambda_p_im == 0.0) {
              Ma = 0.0;
            }
          }
        }
      }

      if (Ma < a21) {
        lambda_p_re = 1.0E-15;
        lambda_p_im = 0.0;
      }
    }

    /*  zero eigenvalue */
    for (rtemp = 0; rtemp < 9; rtemp++) {
      H_tilde[rtemp].re = H[rtemp] + lambda_p_re * (real_T)b[rtemp];
      H_tilde[rtemp].im = lambda_p_im * (real_T)b[rtemp];
    }

    st.site = &d_emlrtRSI;
    b_st.site = &m_emlrtRSI;
    r1 = 0;
    do {
      exitg1 = 0;
      if (r1 < 3) {
        if (H_tilde[r1 + 3 * r1].im != 0.0) {
          emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
            "Coder:MATLAB:chol_matrixMustBePosDefWithRealDiag",
            "Coder:MATLAB:chol_matrixMustBePosDefWithRealDiag", 0);
        } else {
          r1++;
        }
      } else {
        memcpy(&L[0], &H_tilde[0], 9U * sizeof(creal_T));
        c_st.site = &n_emlrtRSI;
        r1 = b_xpotrf(L);
        if (r1 == 0) {
        } else {
          emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI, "Coder:MATLAB:posdef",
            "Coder:MATLAB:posdef", 0);
        }

        c_st.site = &o_emlrtRSI;
        for (r1 = 2; r1 < 4; r1++) {
          c_st.site = &p_emlrtRSI;
          for (r2 = 0; r2 <= r1 - 2; r2++) {
            rtemp = r2 + 3 * (r1 - 1);
            L[rtemp].re = 0.0;
            L[rtemp].im = 0.0;
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);

    for (rtemp = 0; rtemp < 3; rtemp++) {
      for (r1 = 0; r1 < 3; r1++) {
        ma = L[r1 + 3].re;
        L_im = -L[r1 + 3].im;
        re = (L[rtemp].re * L[r1].re - L[rtemp].im * -L[r1].im) + (L[rtemp + 3].
          re * ma - L[rtemp + 3].im * L_im);
        im = (L[rtemp].re * -L[r1].im + L[rtemp].im * L[r1].re) + (L[rtemp + 3].
          re * L_im + L[rtemp + 3].im * ma);
        ma = L[r1 + 6].re;
        L_im = -L[r1 + 6].im;
        re += L[rtemp + 6].re * ma - L[rtemp + 6].im * L_im;
        im += L[rtemp + 6].re * L_im + L[rtemp + 6].im * ma;
        r2 = rtemp + 3 * r1;
        b_L[r2].re = -re;
        b_L[r2].im = -im;
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
        r2 = 0;
        min_eig = w[0];
        if (muDoubleScalarIsNaN(w[1].re) || muDoubleScalarIsNaN(w[1].im)) {
          p = false;
        } else if (muDoubleScalarIsNaN(w[0].re) || muDoubleScalarIsNaN(w[0].im))
        {
          p = true;
        } else {
          absRelopProxies(w[0], w[1], &Ma, &a21);
          p = (Ma > a21);
        }

        if (p) {
          min_eig = w[1];
          r2 = 1;
        }

        if (muDoubleScalarIsNaN(w[2].re) || muDoubleScalarIsNaN(w[2].im)) {
          p = false;
        } else if (muDoubleScalarIsNaN(min_eig.re) || muDoubleScalarIsNaN
                   (min_eig.im)) {
          p = true;
        } else {
          absRelopProxies(min_eig, w[2], &Ma, &a21);
          p = (Ma > a21);
        }

        if (p) {
          r2 = 2;
        }

        re = v[3 * r2].re;
        im = v[3 * r2].im;
        a_re = re * re - -im * im;
        a_im = re * im + -im * re;
        a21 = 2.0 * s[0].re;
        Ma = 2.0 * -s[0].im;
        b_re = a21 * re - Ma * im;
        b_im = a21 * im + Ma * re;
        re = v[1 + 3 * r2].re;
        im = v[1 + 3 * r2].im;
        a_re += re * re - -im * im;
        a_im += re * im + -im * re;
        a21 = 2.0 * s[1].re;
        Ma = 2.0 * -s[1].im;
        b_re += a21 * re - Ma * im;
        b_im += a21 * im + Ma * re;
        re = v[2 + 3 * r2].re;
        im = v[2 + 3 * r2].im;
        a_re += re * re - -im * im;
        a_im += re * im + -im * re;
        a21 = 2.0 * s[2].re;
        Ma = 2.0 * -s[2].im;
        b_re += a21 * re - Ma * im;
        b_im += a21 * im + Ma * re;
        y_im = ((s[0].re * s[0].im + -s[0].im * s[0].re) + (s[1].re * s[1].im +
                 -s[1].im * s[1].re)) + (s[2].re * s[2].im + -s[2].im * s[2].re);
        st.site = &g_emlrtRSI;
        b_st.site = &ph_emlrtRSI;
        c_st.site = &qh_emlrtRSI;
        min_eig.re = (((s[0].re * s[0].re - -s[0].im * s[0].im) + (s[1].re * s[1]
          .re - -s[1].im * s[1].im)) + (s[2].re * s[2].re - -s[2].im * s[2].im))
          - delta * delta;
        b_re_tmp = b_re * b_re - b_im * b_im;
        b_im_tmp = b_re * b_im;
        b_im_tmp += b_im_tmp;
        re = 4.0 * a_re;
        im = 4.0 * a_im;
        max_eig.re = b_re_tmp - (re * min_eig.re - im * y_im);
        max_eig.im = b_im_tmp - (re * y_im + im * min_eig.re);
        c_sqrt(&max_eig);
        a21 = -b_re + max_eig.re;
        ma = -b_im + max_eig.im;
        Ma = 2.0 * a_re;
        L_im = 2.0 * a_im;
        if (L_im == 0.0) {
          if (ma == 0.0) {
            alpha1_re = a21 / Ma;
            alpha1_im = 0.0;
          } else if (a21 == 0.0) {
            alpha1_re = 0.0;
            alpha1_im = ma / Ma;
          } else {
            alpha1_re = a21 / Ma;
            alpha1_im = ma / Ma;
          }
        } else if (Ma == 0.0) {
          if (a21 == 0.0) {
            alpha1_re = ma / L_im;
            alpha1_im = 0.0;
          } else if (ma == 0.0) {
            alpha1_re = 0.0;
            alpha1_im = -(a21 / L_im);
          } else {
            alpha1_re = ma / L_im;
            alpha1_im = -(a21 / L_im);
          }
        } else {
          brm = muDoubleScalarAbs(Ma);
          re = muDoubleScalarAbs(L_im);
          if (brm > re) {
            re = L_im / Ma;
            Ma += re * L_im;
            alpha1_re = (a21 + re * ma) / Ma;
            alpha1_im = (ma - re * a21) / Ma;
          } else if (re == brm) {
            if (Ma > 0.0) {
              re = 0.5;
            } else {
              re = -0.5;
            }

            if (L_im > 0.0) {
              Ma = 0.5;
            } else {
              Ma = -0.5;
            }

            alpha1_re = (a21 * re + ma * Ma) / brm;
            alpha1_im = (ma * re - a21 * Ma) / brm;
          } else {
            re = Ma / L_im;
            Ma = L_im + re * Ma;
            alpha1_re = (re * a21 + ma) / Ma;
            alpha1_im = (re * ma - a21) / Ma;
          }
        }

        re = 4.0 * a_re;
        im = 4.0 * a_im;
        max_eig.re = b_re_tmp - (re * min_eig.re - im * y_im);
        max_eig.im = b_im_tmp - (re * y_im + im * min_eig.re);
        c_sqrt(&max_eig);
        a21 = -b_re - max_eig.re;
        ma = -b_im - max_eig.im;
        Ma = 2.0 * a_re;
        L_im = 2.0 * a_im;
        if (L_im == 0.0) {
          if (ma == 0.0) {
            min_eig.re = a21 / Ma;
            min_eig.im = 0.0;
          } else if (a21 == 0.0) {
            min_eig.re = 0.0;
            min_eig.im = ma / Ma;
          } else {
            min_eig.re = a21 / Ma;
            min_eig.im = ma / Ma;
          }
        } else if (Ma == 0.0) {
          if (a21 == 0.0) {
            min_eig.re = ma / L_im;
            min_eig.im = 0.0;
          } else if (ma == 0.0) {
            min_eig.re = 0.0;
            min_eig.im = -(a21 / L_im);
          } else {
            min_eig.re = ma / L_im;
            min_eig.im = -(a21 / L_im);
          }
        } else {
          brm = muDoubleScalarAbs(Ma);
          re = muDoubleScalarAbs(L_im);
          if (brm > re) {
            re = L_im / Ma;
            Ma += re * L_im;
            min_eig.re = (a21 + re * ma) / Ma;
            min_eig.im = (ma - re * a21) / Ma;
          } else if (re == brm) {
            if (Ma > 0.0) {
              re = 0.5;
            } else {
              re = -0.5;
            }

            if (L_im > 0.0) {
              Ma = 0.5;
            } else {
              Ma = -0.5;
            }

            min_eig.re = (a21 * re + ma * Ma) / brm;
            min_eig.im = (ma * re - a21 * Ma) / brm;
          } else {
            re = Ma / L_im;
            Ma = L_im + re * Ma;
            min_eig.re = (re * a21 + ma) / Ma;
            min_eig.im = (re * ma - a21) / Ma;
          }
        }

        re = v[3 * r2].re;
        im = v[3 * r2].im;
        w[0].re = s[0].re + (alpha1_re * re - alpha1_im * im);
        w[0].im = s[0].im + (alpha1_re * im + alpha1_im * re);
        s2[0].re = s[0].re + (min_eig.re * re - min_eig.im * im);
        s2[0].im = s[0].im + (min_eig.re * im + min_eig.im * re);
        re = v[1 + 3 * r2].re;
        im = v[1 + 3 * r2].im;
        w[1].re = s[1].re + (alpha1_re * re - alpha1_im * im);
        w[1].im = s[1].im + (alpha1_re * im + alpha1_im * re);
        s2[1].re = s[1].re + (min_eig.re * re - min_eig.im * im);
        s2[1].im = s[1].im + (min_eig.re * im + min_eig.im * re);
        re = v[2 + 3 * r2].re;
        im = v[2 + 3 * r2].im;
        w[2].re = s[2].re + (alpha1_re * re - alpha1_im * im);
        w[2].im = s[2].im + (alpha1_re * im + alpha1_im * re);
        s2[2].re = s[2].re + (min_eig.re * re - min_eig.im * im);
        s2[2].im = s[2].im + (min_eig.re * im + min_eig.im * re);
        for (rtemp = 0; rtemp < 9; rtemp++) {
          b_L[rtemp].re = H[rtemp];
          b_L[rtemp].im = 0.0;
        }

        Ma = 0.0;
        y_im = 0.0;
        for (r1 = 0; r1 < 3; r1++) {
          re = ((w[0].re * b_L[3 * r1].re - -w[0].im * b_L[3 * r1].im) + (w[1].
                 re * b_L[1 + 3 * r1].re - -w[1].im * b_L[1 + 3 * r1].im)) + (w
            [2].re * b_L[2 + 3 * r1].re - -w[2].im * b_L[2 + 3 * r1].im);
          im = ((w[0].re * b_L[3 * r1].im + -w[0].im * b_L[3 * r1].re) + (w[1].
                 re * b_L[1 + 3 * r1].im + -w[1].im * b_L[1 + 3 * r1].re)) + (w
            [2].re * b_L[2 + 3 * r1].im + -w[2].im * b_L[2 + 3 * r1].re);
          Ma += re * w[r1].re - im * w[r1].im;
          y_im += re * w[r1].im + im * w[r1].re;
        }

        for (rtemp = 0; rtemp < 9; rtemp++) {
          b_L[rtemp].re = H[rtemp];
          b_L[rtemp].im = 0.0;
        }

        max_eig.re = 0.0;
        max_eig.im = 0.0;
        ma = 0.0;
        for (r1 = 0; r1 < 3; r1++) {
          re = ((s2[0].re * b_L[3 * r1].re - -s2[0].im * b_L[3 * r1].im) + (s2[1]
                 .re * b_L[1 + 3 * r1].re - -s2[1].im * b_L[1 + 3 * r1].im)) +
            (s2[2].re * b_L[2 + 3 * r1].re - -s2[2].im * b_L[2 + 3 * r1].im);
          im = ((s2[0].re * b_L[3 * r1].im + -s2[0].im * b_L[3 * r1].re) + (s2[1]
                 .re * b_L[1 + 3 * r1].im + -s2[1].im * b_L[1 + 3 * r1].re)) +
            (s2[2].re * b_L[2 + 3 * r1].im + -s2[2].im * b_L[2 + 3 * r1].re);
          max_eig.re += re * s2[r1].re - im * s2[r1].im;
          max_eig.im += re * s2[r1].im + im * s2[r1].re;
          ma += g[r1] * w[r1].re - 0.0 * w[r1].im;
        }

        if (y_im == 0.0) {
          Ma /= 2.0;
        } else if (Ma == 0.0) {
          Ma = 0.0;
        } else {
          Ma /= 2.0;
        }

        if (max_eig.im == 0.0) {
          a21 = max_eig.re / 2.0;
        } else if (max_eig.re == 0.0) {
          a21 = 0.0;
        } else {
          a21 = max_eig.re / 2.0;
        }

        if (ma + Ma < (((g[0] * s2[0].re - 0.0 * s2[0].im) + (g[1] * s2[1].re -
               0.0 * s2[1].im)) + (g[2] * s2[2].re - 0.0 * s2[2].im)) + a21) {
          min_eig.re = alpha1_re;
          min_eig.im = alpha1_im;
        }

        s[0].re += v[3 * r2].re * min_eig.re - v[3 * r2].im * min_eig.im;
        s[0].im += v[3 * r2].re * min_eig.im + v[3 * r2].im * min_eig.re;
        s[1].re += v[1 + 3 * r2].re * min_eig.re - v[1 + 3 * r2].im * min_eig.im;
        s[1].im += v[1 + 3 * r2].re * min_eig.im + v[1 + 3 * r2].im * min_eig.re;
        s[2].re += v[2 + 3 * r2].re * min_eig.re - v[2 + 3 * r2].im * min_eig.im;
        s[2].im += v[2 + 3 * r2].re * min_eig.im + v[2 + 3 * r2].im * min_eig.re;
        working = 0;
      }
    }

    do {
      exitg1 = 0;
      st.site = &h_emlrtRSI;
      if ((working != 0) && (counter < 100)) {
        /*  Step 4 */
        im = c_norm(s) - delta;
        if (muDoubleScalarAbs(im) <= 1.0E-10 * delta) {
          exitg1 = 1;
        } else {
          /*  Step 5 */
          st.site = &i_emlrtRSI;
          b_st.site = &lg_emlrtRSI;
          c_st.site = &mg_emlrtRSI;
          d_st.site = &ng_emlrtRSI;
          r1 = 0;
          r2 = 1;
          jmax = 2;
          Ma = muDoubleScalarAbs(L[0].re) + muDoubleScalarAbs(L[0].im);
          a21 = muDoubleScalarAbs(L[1].re) + muDoubleScalarAbs(L[1].im);
          if (a21 > Ma) {
            Ma = a21;
            r1 = 1;
            r2 = 0;
          }

          if (muDoubleScalarAbs(L[2].re) + muDoubleScalarAbs(L[2].im) > Ma) {
            r1 = 2;
            r2 = 1;
            jmax = 0;
          }

          ma = L[r2].re;
          a21 = L[r1].re;
          if (L[r1].im == 0.0) {
            if (L[r2].im == 0.0) {
              L[r2].re /= L[r1].re;
              L[r2].im = 0.0;
            } else if (L[r2].re == 0.0) {
              L[r2].re = 0.0;
              L[r2].im /= a21;
            } else {
              L[r2].re /= L[r1].re;
              L[r2].im /= a21;
            }
          } else if (L[r1].re == 0.0) {
            if (L[r2].re == 0.0) {
              L[r2].re = L[r2].im / L[r1].im;
              L[r2].im = 0.0;
            } else if (L[r2].im == 0.0) {
              L[r2].re = 0.0;
              L[r2].im = -(ma / L[r1].im);
            } else {
              L[r2].re = L[r2].im / L[r1].im;
              L[r2].im = -(ma / L[r1].im);
            }
          } else {
            brm = muDoubleScalarAbs(L[r1].re);
            re = muDoubleScalarAbs(L[r1].im);
            if (brm > re) {
              re = L[r1].im / L[r1].re;
              Ma = L[r1].re + re * L[r1].im;
              L[r2].re = (L[r2].re + re * L[r2].im) / Ma;
              L[r2].im = (L[r2].im - re * ma) / Ma;
            } else if (re == brm) {
              if (L[r1].re > 0.0) {
                re = 0.5;
              } else {
                re = -0.5;
              }

              if (L[r1].im > 0.0) {
                Ma = 0.5;
              } else {
                Ma = -0.5;
              }

              L[r2].re = (L[r2].re * re + L[r2].im * Ma) / brm;
              L[r2].im = (L[r2].im * re - ma * Ma) / brm;
            } else {
              re = L[r1].re / L[r1].im;
              Ma = L[r1].im + re * L[r1].re;
              a21 = re * L[r2].im - L[r2].re;
              L[r2].re = (re * L[r2].re + L[r2].im) / Ma;
              L[r2].im = a21 / Ma;
            }
          }

          ma = L[jmax].re;
          a21 = L[r1].re;
          if (L[r1].im == 0.0) {
            if (L[jmax].im == 0.0) {
              L[jmax].re /= L[r1].re;
              L[jmax].im = 0.0;
            } else if (L[jmax].re == 0.0) {
              L[jmax].re = 0.0;
              L[jmax].im /= a21;
            } else {
              L[jmax].re /= L[r1].re;
              L[jmax].im /= a21;
            }
          } else if (L[r1].re == 0.0) {
            if (L[jmax].re == 0.0) {
              L[jmax].re = L[jmax].im / L[r1].im;
              L[jmax].im = 0.0;
            } else if (L[jmax].im == 0.0) {
              L[jmax].re = 0.0;
              L[jmax].im = -(ma / L[r1].im);
            } else {
              L[jmax].re = L[jmax].im / L[r1].im;
              L[jmax].im = -(ma / L[r1].im);
            }
          } else {
            brm = muDoubleScalarAbs(L[r1].re);
            re = muDoubleScalarAbs(L[r1].im);
            if (brm > re) {
              re = L[r1].im / L[r1].re;
              Ma = L[r1].re + re * L[r1].im;
              L[jmax].re = (L[jmax].re + re * L[jmax].im) / Ma;
              L[jmax].im = (L[jmax].im - re * ma) / Ma;
            } else if (re == brm) {
              if (L[r1].re > 0.0) {
                re = 0.5;
              } else {
                re = -0.5;
              }

              if (L[r1].im > 0.0) {
                Ma = 0.5;
              } else {
                Ma = -0.5;
              }

              L[jmax].re = (L[jmax].re * re + L[jmax].im * Ma) / brm;
              L[jmax].im = (L[jmax].im * re - ma * Ma) / brm;
            } else {
              re = L[r1].re / L[r1].im;
              Ma = L[r1].im + re * L[r1].re;
              a21 = re * L[jmax].im - L[jmax].re;
              L[jmax].re = (re * L[jmax].re + L[jmax].im) / Ma;
              L[jmax].im = a21 / Ma;
            }
          }

          L_im = L[r2].re * L[3 + r1].im + L[r2].im * L[3 + r1].re;
          L[3 + r2].re -= L[r2].re * L[3 + r1].re - L[r2].im * L[3 + r1].im;
          L[3 + r2].im -= L_im;
          L_im = L[jmax].re * L[3 + r1].im + L[jmax].im * L[3 + r1].re;
          L[3 + jmax].re -= L[jmax].re * L[3 + r1].re - L[jmax].im * L[3 + r1].
            im;
          L[3 + jmax].im -= L_im;
          L_im = L[r2].re * L[6 + r1].im + L[r2].im * L[6 + r1].re;
          L[6 + r2].re -= L[r2].re * L[6 + r1].re - L[r2].im * L[6 + r1].im;
          L[6 + r2].im -= L_im;
          L_im = L[jmax].re * L[6 + r1].im + L[jmax].im * L[6 + r1].re;
          L[6 + jmax].re -= L[jmax].re * L[6 + r1].re - L[jmax].im * L[6 + r1].
            im;
          L[6 + jmax].im -= L_im;
          if (muDoubleScalarAbs(L[3 + jmax].re) + muDoubleScalarAbs(L[3 + jmax].
               im) > muDoubleScalarAbs(L[3 + r2].re) + muDoubleScalarAbs(L[3 +
               r2].im)) {
            rtemp = r2;
            r2 = jmax;
            jmax = rtemp;
          }

          ma = L[3 + jmax].re;
          L_im = L[3 + jmax].im;
          a21 = L[3 + r2].re;
          Ma = L[3 + r2].im;
          if (Ma == 0.0) {
            if (L_im == 0.0) {
              L[3 + jmax].re = ma / a21;
              L[3 + jmax].im = 0.0;
            } else if (ma == 0.0) {
              L[3 + jmax].re = 0.0;
              L[3 + jmax].im = L_im / a21;
            } else {
              L[3 + jmax].re = ma / a21;
              L[3 + jmax].im = L_im / a21;
            }
          } else if (a21 == 0.0) {
            if (ma == 0.0) {
              L[3 + jmax].re = L_im / Ma;
              L[3 + jmax].im = 0.0;
            } else if (L_im == 0.0) {
              L[3 + jmax].re = 0.0;
              L[3 + jmax].im = -(ma / Ma);
            } else {
              L[3 + jmax].re = L_im / Ma;
              L[3 + jmax].im = -(ma / Ma);
            }
          } else {
            brm = muDoubleScalarAbs(a21);
            re = muDoubleScalarAbs(Ma);
            if (brm > re) {
              re = Ma / a21;
              Ma = a21 + re * Ma;
              L[3 + jmax].re = (ma + re * L_im) / Ma;
              L[3 + jmax].im = (L_im - re * ma) / Ma;
            } else if (re == brm) {
              if (a21 > 0.0) {
                re = 0.5;
              } else {
                re = -0.5;
              }

              if (Ma > 0.0) {
                Ma = 0.5;
              } else {
                Ma = -0.5;
              }

              L[3 + jmax].re = (ma * re + L_im * Ma) / brm;
              L[3 + jmax].im = (L_im * re - ma * Ma) / brm;
            } else {
              re = a21 / Ma;
              Ma += re * a21;
              L[3 + jmax].re = (re * ma + L_im) / Ma;
              L[3 + jmax].im = (re * L_im - ma) / Ma;
            }
          }

          L_im = L[3 + jmax].re * L[6 + r2].im + L[3 + jmax].im * L[6 + r2].re;
          L[6 + jmax].re -= L[3 + jmax].re * L[6 + r2].re - L[3 + jmax].im * L[6
            + r2].im;
          L[6 + jmax].im -= L_im;
          if (((L[r1].re == 0.0) && (L[r1].im == 0.0)) || ((L[3 + r2].re == 0.0)
               && (L[3 + r2].im == 0.0)) || ((L[6 + jmax].re == 0.0) && (L[6 +
                jmax].im == 0.0))) {
            e_st.site = &og_emlrtRSI;
            f_st.site = &pg_emlrtRSI;
            warning(&f_st);
          }

          w[1].re = s[r2].re - (s[r1].re * L[r2].re - s[r1].im * L[r2].im);
          w[1].im = s[r2].im - (s[r1].re * L[r2].im + s[r1].im * L[r2].re);
          w[2].re = (s[jmax].re - (s[r1].re * L[jmax].re - s[r1].im * L[jmax].im))
            - (w[1].re * L[3 + jmax].re - w[1].im * L[3 + jmax].im);
          w[2].im = (s[jmax].im - (s[r1].re * L[jmax].im + s[r1].im * L[jmax].re))
            - (w[1].re * L[3 + jmax].im + w[1].im * L[3 + jmax].re);
          a21 = w[2].re;
          Ma = L[6 + jmax].re;
          L_im = L[6 + jmax].im;
          if (L_im == 0.0) {
            if (w[2].im == 0.0) {
              w[2].re /= Ma;
              w[2].im = 0.0;
            } else if (w[2].re == 0.0) {
              w[2].re = 0.0;
              w[2].im /= Ma;
            } else {
              w[2].re /= Ma;
              w[2].im /= Ma;
            }
          } else if (Ma == 0.0) {
            if (w[2].re == 0.0) {
              w[2].re = w[2].im / L_im;
              w[2].im = 0.0;
            } else if (w[2].im == 0.0) {
              w[2].re = 0.0;
              w[2].im = -(a21 / L_im);
            } else {
              w[2].re = w[2].im / L_im;
              w[2].im = -(a21 / L_im);
            }
          } else {
            brm = muDoubleScalarAbs(Ma);
            re = muDoubleScalarAbs(L_im);
            if (brm > re) {
              re = L_im / Ma;
              Ma += re * L_im;
              w[2].re = (w[2].re + re * w[2].im) / Ma;
              w[2].im = (w[2].im - re * a21) / Ma;
            } else if (re == brm) {
              if (Ma > 0.0) {
                re = 0.5;
              } else {
                re = -0.5;
              }

              if (L_im > 0.0) {
                Ma = 0.5;
              } else {
                Ma = -0.5;
              }

              w[2].re = (w[2].re * re + w[2].im * Ma) / brm;
              w[2].im = (w[2].im * re - a21 * Ma) / brm;
            } else {
              re = Ma / L_im;
              Ma = L_im + re * Ma;
              a21 = re * w[2].im - w[2].re;
              w[2].re = (re * w[2].re + w[2].im) / Ma;
              w[2].im = a21 / Ma;
            }
          }

          w[0].re = s[r1].re - (w[2].re * L[6 + r1].re - w[2].im * L[6 + r1].im);
          w[0].im = s[r1].im - (w[2].re * L[6 + r1].im + w[2].im * L[6 + r1].re);
          w[1].re -= w[2].re * L[6 + r2].re - w[2].im * L[6 + r2].im;
          w[1].im -= w[2].re * L[6 + r2].im + w[2].im * L[6 + r2].re;
          a21 = w[1].re;
          Ma = L[3 + r2].re;
          L_im = L[3 + r2].im;
          if (L_im == 0.0) {
            if (w[1].im == 0.0) {
              w[1].re /= Ma;
              w[1].im = 0.0;
            } else if (w[1].re == 0.0) {
              w[1].re = 0.0;
              w[1].im /= Ma;
            } else {
              w[1].re /= Ma;
              w[1].im /= Ma;
            }
          } else if (Ma == 0.0) {
            if (w[1].re == 0.0) {
              w[1].re = w[1].im / L_im;
              w[1].im = 0.0;
            } else if (w[1].im == 0.0) {
              w[1].re = 0.0;
              w[1].im = -(a21 / L_im);
            } else {
              w[1].re = w[1].im / L_im;
              w[1].im = -(a21 / L_im);
            }
          } else {
            brm = muDoubleScalarAbs(Ma);
            re = muDoubleScalarAbs(L_im);
            if (brm > re) {
              re = L_im / Ma;
              Ma += re * L_im;
              w[1].re = (w[1].re + re * w[1].im) / Ma;
              w[1].im = (w[1].im - re * a21) / Ma;
            } else if (re == brm) {
              if (Ma > 0.0) {
                re = 0.5;
              } else {
                re = -0.5;
              }

              if (L_im > 0.0) {
                Ma = 0.5;
              } else {
                Ma = -0.5;
              }

              w[1].re = (w[1].re * re + w[1].im * Ma) / brm;
              w[1].im = (w[1].im * re - a21 * Ma) / brm;
            } else {
              re = Ma / L_im;
              Ma = L_im + re * Ma;
              a21 = re * w[1].im - w[1].re;
              w[1].re = (re * w[1].re + w[1].im) / Ma;
              w[1].im = a21 / Ma;
            }
          }

          w[0].re -= w[1].re * L[3 + r1].re - w[1].im * L[3 + r1].im;
          w[0].im -= w[1].re * L[3 + r1].im + w[1].im * L[3 + r1].re;
          a21 = w[0].re;
          if (L[r1].im == 0.0) {
            if (w[0].im == 0.0) {
              w[0].re /= L[r1].re;
              w[0].im = 0.0;
            } else if (w[0].re == 0.0) {
              w[0].re = 0.0;
              w[0].im /= L[r1].re;
            } else {
              w[0].re /= L[r1].re;
              w[0].im /= L[r1].re;
            }
          } else if (L[r1].re == 0.0) {
            if (w[0].re == 0.0) {
              w[0].re = w[0].im / L[r1].im;
              w[0].im = 0.0;
            } else if (w[0].im == 0.0) {
              w[0].re = 0.0;
              w[0].im = -(a21 / L[r1].im);
            } else {
              w[0].re = w[0].im / L[r1].im;
              w[0].im = -(a21 / L[r1].im);
            }
          } else {
            brm = muDoubleScalarAbs(L[r1].re);
            re = muDoubleScalarAbs(L[r1].im);
            if (brm > re) {
              re = L[r1].im / L[r1].re;
              Ma = L[r1].re + re * L[r1].im;
              w[0].re = (w[0].re + re * w[0].im) / Ma;
              w[0].im = (w[0].im - re * a21) / Ma;
            } else if (re == brm) {
              if (L[r1].re > 0.0) {
                re = 0.5;
              } else {
                re = -0.5;
              }

              if (L[r1].im > 0.0) {
                Ma = 0.5;
              } else {
                Ma = -0.5;
              }

              w[0].re = (w[0].re * re + w[0].im * Ma) / brm;
              w[0].im = (w[0].im * re - a21 * Ma) / brm;
            } else {
              re = L[r1].re / L[r1].im;
              Ma = L[r1].im + re * L[r1].re;
              a21 = re * w[0].im - w[0].re;
              w[0].re = (re * w[0].re + w[0].im) / Ma;
              w[0].im = a21 / Ma;
            }
          }

          st.site = &j_emlrtRSI;
          Ma = c_norm(s) / c_norm(w);
          b_st.site = &ph_emlrtRSI;
          c_st.site = &qh_emlrtRSI;
          lambda_p_re += im / delta * (Ma * Ma);

          /*  Step 6 */
          for (rtemp = 0; rtemp < 9; rtemp++) {
            H_tilde[rtemp].re = H[rtemp] + lambda_p_re * (real_T)b[rtemp];
            H_tilde[rtemp].im = lambda_p_im * (real_T)b[rtemp];
          }

          st.site = &k_emlrtRSI;
          b_st.site = &m_emlrtRSI;
          r1 = 0;
          do {
            exitg2 = 0;
            if (r1 < 3) {
              if (H_tilde[r1 + 3 * r1].im != 0.0) {
                emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
                  "Coder:MATLAB:chol_matrixMustBePosDefWithRealDiag",
                  "Coder:MATLAB:chol_matrixMustBePosDefWithRealDiag", 0);
              } else {
                r1++;
              }
            } else {
              memcpy(&L[0], &H_tilde[0], 9U * sizeof(creal_T));
              c_st.site = &n_emlrtRSI;
              r1 = b_xpotrf(L);
              if (r1 == 0) {
              } else {
                emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
                  "Coder:MATLAB:posdef", "Coder:MATLAB:posdef", 0);
              }

              c_st.site = &o_emlrtRSI;
              for (r1 = 2; r1 < 4; r1++) {
                c_st.site = &p_emlrtRSI;
                for (r2 = 0; r2 <= r1 - 2; r2++) {
                  rtemp = r2 + 3 * (r1 - 1);
                  L[rtemp].re = 0.0;
                  L[rtemp].im = 0.0;
                }
              }

              exitg2 = 1;
            }
          } while (exitg2 == 0);

          for (rtemp = 0; rtemp < 3; rtemp++) {
            for (r1 = 0; r1 < 3; r1++) {
              ma = L[r1 + 3].re;
              L_im = -L[r1 + 3].im;
              re = (L[rtemp].re * L[r1].re - L[rtemp].im * -L[r1].im) + (L[rtemp
                + 3].re * ma - L[rtemp + 3].im * L_im);
              im = (L[rtemp].re * -L[r1].im + L[rtemp].im * L[r1].re) + (L[rtemp
                + 3].re * L_im + L[rtemp + 3].im * ma);
              ma = L[r1 + 6].re;
              L_im = -L[r1 + 6].im;
              re += L[rtemp + 6].re * ma - L[rtemp + 6].im * L_im;
              im += L[rtemp + 6].re * L_im + L[rtemp + 6].im * ma;
              r2 = rtemp + 3 * r1;
              b_L[r2].re = -re;
              b_L[r2].im = -im;
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

    for (rtemp = 0; rtemp < 9; rtemp++) {
      b_L[rtemp].re = SinvT[rtemp];
      b_L[rtemp].im = 0.0;
    }

    for (rtemp = 0; rtemp < 3; rtemp++) {
      for (r1 = 0; r1 < 3; r1++) {
        r2 = rtemp + 3 * r1;
        v[r2].re = ((b_L[rtemp].re * H_tilde[3 * r1].re - b_L[rtemp].im *
                     H_tilde[3 * r1].im) + (b_L[rtemp + 3].re * H_tilde[1 + 3 *
          r1].re - b_L[rtemp + 3].im * H_tilde[1 + 3 * r1].im)) + (b_L[rtemp + 6]
          .re * H_tilde[2 + 3 * r1].re - b_L[rtemp + 6].im * H_tilde[2 + 3 * r1]
          .im);
        v[r2].im = ((b_L[rtemp].re * H_tilde[3 * r1].im + b_L[rtemp].im *
                     H_tilde[3 * r1].re) + (b_L[rtemp + 3].re * H_tilde[1 + 3 *
          r1].im + b_L[rtemp + 3].im * H_tilde[1 + 3 * r1].re)) + (b_L[rtemp + 6]
          .re * H_tilde[2 + 3 * r1].im + b_L[rtemp + 6].im * H_tilde[2 + 3 * r1]
          .re);
      }
    }

    for (rtemp = 0; rtemp < 3; rtemp++) {
      b_L[3 * rtemp].re = SinvT[rtemp];
      b_L[3 * rtemp].im = 0.0;
      r1 = 1 + 3 * rtemp;
      b_L[r1].re = SinvT[rtemp + 3];
      b_L[r1].im = 0.0;
      r1 = 2 + 3 * rtemp;
      b_L[r1].re = SinvT[rtemp + 6];
      b_L[r1].im = 0.0;
    }

    for (rtemp = 0; rtemp < 3; rtemp++) {
      for (r1 = 0; r1 < 3; r1++) {
        r2 = rtemp + 3 * r1;
        H_out[r2].re = ((v[rtemp].re * b_L[3 * r1].re - v[rtemp].im * b_L[3 * r1]
                         .im) + (v[rtemp + 3].re * b_L[1 + 3 * r1].re - v[rtemp
          + 3].im * b_L[1 + 3 * r1].im)) + (v[rtemp + 6].re * b_L[2 + 3 * r1].re
          - v[rtemp + 6].im * b_L[2 + 3 * r1].im);
        H_out[r2].im = ((v[rtemp].re * b_L[3 * r1].im + v[rtemp].im * b_L[3 * r1]
                         .re) + (v[rtemp + 3].re * b_L[1 + 3 * r1].im + v[rtemp
          + 3].im * b_L[1 + 3 * r1].re)) + (v[rtemp + 6].re * b_L[2 + 3 * r1].im
          + v[rtemp + 6].im * b_L[2 + 3 * r1].re);
      }
    }

    for (rtemp = 0; rtemp < 9; rtemp++) {
      b_L[rtemp].re = S[rtemp];
      b_L[rtemp].im = 0.0;
    }

    for (rtemp = 0; rtemp < 3; rtemp++) {
      s_out[rtemp].re = ((b_L[rtemp].re * s[0].re - b_L[rtemp].im * s[0].im) +
                         (b_L[rtemp + 3].re * s[1].re - b_L[rtemp + 3].im * s[1]
                          .im)) + (b_L[rtemp + 6].re * s[2].re - b_L[rtemp + 6].
        im * s[2].im);
      s_out[rtemp].im = ((b_L[rtemp].re * s[0].im + b_L[rtemp].im * s[0].re) +
                         (b_L[rtemp + 3].re * s[1].im + b_L[rtemp + 3].im * s[1]
                          .re)) + (b_L[rtemp + 6].re * s[2].im + b_L[rtemp + 6].
        im * s[2].re);
    }
  }
}

/* End of code generation (trqp_control.c) */
