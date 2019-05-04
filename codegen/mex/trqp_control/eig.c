/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eig.c
 *
 * Code generation for function 'eig'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "eig.h"
#include "warning.h"
#include "schur.h"
#include "xnrm2.h"
#include "xzggev.h"
#include "xhseqr.h"
#include "xgehrd.h"
#include "anyNonFinite.h"
#include "trqp_control_data.h"
#include "lapacke.h"

/* Type Definitions */

/* Variable Definitions */
static emlrtRSInfo rb_emlrtRSI = { 118,/* lineNo */
  "eig",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 133,/* lineNo */
  "eig",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 175,/* lineNo */
  "eig",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 181,/* lineNo */
  "eig",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo re_emlrtRSI = { 14, /* lineNo */
  "xzgeev",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgeev.m"/* pathName */
};

static emlrtRSInfo se_emlrtRSI = { 22, /* lineNo */
  "xzgeev",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgeev.m"/* pathName */
};

static emlrtRSInfo te_emlrtRSI = { 23, /* lineNo */
  "xzgeev",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgeev.m"/* pathName */
};

static emlrtRSInfo qg_emlrtRSI = { 43, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo rg_emlrtRSI = { 77, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo sg_emlrtRSI = { 78, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

/* Function Definitions */
void b_eig(const emlrtStack *sp, const creal_T A[9], creal_T V[9], creal_T D[3])
{
  int32_T info;
  int32_T i;
  boolean_T p;
  int32_T j;
  boolean_T exitg2;
  int32_T exitg1;
  creal_T At[9];
  creal_T beta1[3];
  creal_T tau[2];
  real_T colnorm;
  real_T D_re;
  int32_T b;
  real_T V_im;
  real_T V_re;
  ptrdiff_t info_t;
  boolean_T b_p;
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'z',
    'u', 'n', 'g', 'h', 'r' };

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
  info = 0;
  if (anyNonFinite(A)) {
    for (i = 0; i < 9; i++) {
      V[i].re = rtNaN;
      V[i].im = 0.0;
    }

    D[0].re = rtNaN;
    D[0].im = 0.0;
    D[1].re = rtNaN;
    D[1].im = 0.0;
    D[2].re = rtNaN;
    D[2].im = 0.0;
  } else {
    st.site = &rb_emlrtRSI;
    p = true;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j < 3)) {
      i = 0;
      do {
        exitg1 = 0;
        if (i <= j) {
          if ((!(A[i + 3 * j].re == A[j + 3 * i].re)) || (!(A[i + 3 * j].im ==
                -A[j + 3 * i].im))) {
            p = false;
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          j++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (p) {
      st.site = &sb_emlrtRSI;
      if (anyNonFinite(A)) {
        b_st.site = &qg_emlrtRSI;
        for (i = 0; i < 9; i++) {
          V[i].re = rtNaN;
          V[i].im = 0.0;
        }

        c_st.site = &dc_emlrtRSI;
        for (i = 2; i < 4; i++) {
          V[i - 1].re = 0.0;
          V[i - 1].im = 0.0;
        }

        c_st.site = &dc_emlrtRSI;
        for (i = 3; i < 4; i++) {
          V[5].re = 0.0;
          V[5].im = 0.0;
        }

        for (i = 0; i < 9; i++) {
          At[i].re = rtNaN;
          At[i].im = 0.0;
        }
      } else {
        memcpy(&At[0], &A[0], 9U * sizeof(creal_T));
        b_st.site = &xb_emlrtRSI;
        b_xgehrd(&b_st, At, tau);
        b_st.site = &rg_emlrtRSI;
        memcpy(&V[0], &At[0], 9U * sizeof(creal_T));
        c_st.site = &hd_emlrtRSI;
        info_t = LAPACKE_zunghr(102, (ptrdiff_t)3, (ptrdiff_t)1, (ptrdiff_t)3,
          (lapack_complex_double *)&V[0], (ptrdiff_t)3, (lapack_complex_double *)
          &tau[0]);
        i = (int32_T)info_t;
        d_st.site = &md_emlrtRSI;
        if (i != 0) {
          p = true;
          b_p = false;
          if (i == -5) {
            b_p = true;
          } else {
            if (i == -7) {
              b_p = true;
            }
          }

          if (!b_p) {
            if (i == -1010) {
              emlrtErrorWithMessageIdR2018a(&d_st, &d_emlrtRTEI, "MATLAB:nomem",
                "MATLAB:nomem", 0);
            } else {
              emlrtErrorWithMessageIdR2018a(&d_st, &e_emlrtRTEI,
                "Coder:toolbox:LAPACKCallErrorInfo",
                "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, i);
            }
          }
        } else {
          p = false;
        }

        if (p) {
          for (i = 0; i < 9; i++) {
            V[i].re = rtNaN;
            V[i].im = 0.0;
          }
        }

        b_st.site = &sg_emlrtRSI;
        i = b_xhseqr(&b_st, At, V);
        if (i != 0) {
          b_st.site = &cc_emlrtRSI;
          c_warning(&b_st);
        }
      }

      D[0] = At[0];
      D[1] = At[4];
      D[2] = At[8];
    } else {
      st.site = &tb_emlrtRSI;
      memcpy(&At[0], &A[0], 9U * sizeof(creal_T));
      b_st.site = &re_emlrtRSI;
      xzggev(&b_st, At, &info, D, beta1, V);
      for (i = 0; i <= 6; i += 3) {
        b_st.site = &se_emlrtRSI;
        colnorm = c_xnrm2(&b_st, V, i + 1);
        b = i + 3;
        b_st.site = &te_emlrtRSI;
        for (j = i + 1; j <= b; j++) {
          V_re = V[j - 1].re;
          V_im = V[j - 1].im;
          if (V_im == 0.0) {
            V[j - 1].re = V_re / colnorm;
            V[j - 1].im = 0.0;
          } else if (V_re == 0.0) {
            V[j - 1].re = 0.0;
            V[j - 1].im = V_im / colnorm;
          } else {
            V[j - 1].re = V_re / colnorm;
            V[j - 1].im = V_im / colnorm;
          }
        }
      }

      D_re = D[0].re;
      if (beta1[0].im == 0.0) {
        if (D[0].im == 0.0) {
          D[0].re /= beta1[0].re;
          D[0].im = 0.0;
        } else if (D[0].re == 0.0) {
          D[0].re = 0.0;
          D[0].im /= beta1[0].re;
        } else {
          D[0].re /= beta1[0].re;
          D[0].im /= beta1[0].re;
        }
      } else if (beta1[0].re == 0.0) {
        if (D[0].re == 0.0) {
          D[0].re = D[0].im / beta1[0].im;
          D[0].im = 0.0;
        } else if (D[0].im == 0.0) {
          D[0].re = 0.0;
          D[0].im = -(D_re / beta1[0].im);
        } else {
          D[0].re = D[0].im / beta1[0].im;
          D[0].im = -(D_re / beta1[0].im);
        }
      } else {
        V_im = muDoubleScalarAbs(beta1[0].re);
        colnorm = muDoubleScalarAbs(beta1[0].im);
        if (V_im > colnorm) {
          V_re = beta1[0].im / beta1[0].re;
          V_im = beta1[0].re + V_re * beta1[0].im;
          D[0].re = (D[0].re + V_re * D[0].im) / V_im;
          D[0].im = (D[0].im - V_re * D_re) / V_im;
        } else if (colnorm == V_im) {
          if (beta1[0].re > 0.0) {
            colnorm = 0.5;
          } else {
            colnorm = -0.5;
          }

          if (beta1[0].im > 0.0) {
            V_re = 0.5;
          } else {
            V_re = -0.5;
          }

          D[0].re = (D[0].re * colnorm + D[0].im * V_re) / V_im;
          D[0].im = (D[0].im * colnorm - D_re * V_re) / V_im;
        } else {
          V_re = beta1[0].re / beta1[0].im;
          V_im = beta1[0].im + V_re * beta1[0].re;
          colnorm = V_re * D[0].im - D[0].re;
          D[0].re = (V_re * D[0].re + D[0].im) / V_im;
          D[0].im = colnorm / V_im;
        }
      }

      D_re = D[1].re;
      if (beta1[1].im == 0.0) {
        if (D[1].im == 0.0) {
          D[1].re /= beta1[1].re;
          D[1].im = 0.0;
        } else if (D[1].re == 0.0) {
          D[1].re = 0.0;
          D[1].im /= beta1[1].re;
        } else {
          D[1].re /= beta1[1].re;
          D[1].im /= beta1[1].re;
        }
      } else if (beta1[1].re == 0.0) {
        if (D[1].re == 0.0) {
          D[1].re = D[1].im / beta1[1].im;
          D[1].im = 0.0;
        } else if (D[1].im == 0.0) {
          D[1].re = 0.0;
          D[1].im = -(D_re / beta1[1].im);
        } else {
          D[1].re = D[1].im / beta1[1].im;
          D[1].im = -(D_re / beta1[1].im);
        }
      } else {
        V_im = muDoubleScalarAbs(beta1[1].re);
        colnorm = muDoubleScalarAbs(beta1[1].im);
        if (V_im > colnorm) {
          V_re = beta1[1].im / beta1[1].re;
          V_im = beta1[1].re + V_re * beta1[1].im;
          D[1].re = (D[1].re + V_re * D[1].im) / V_im;
          D[1].im = (D[1].im - V_re * D_re) / V_im;
        } else if (colnorm == V_im) {
          if (beta1[1].re > 0.0) {
            colnorm = 0.5;
          } else {
            colnorm = -0.5;
          }

          if (beta1[1].im > 0.0) {
            V_re = 0.5;
          } else {
            V_re = -0.5;
          }

          D[1].re = (D[1].re * colnorm + D[1].im * V_re) / V_im;
          D[1].im = (D[1].im * colnorm - D_re * V_re) / V_im;
        } else {
          V_re = beta1[1].re / beta1[1].im;
          V_im = beta1[1].im + V_re * beta1[1].re;
          colnorm = V_re * D[1].im - D[1].re;
          D[1].re = (V_re * D[1].re + D[1].im) / V_im;
          D[1].im = colnorm / V_im;
        }
      }

      D_re = D[2].re;
      if (beta1[2].im == 0.0) {
        if (D[2].im == 0.0) {
          D[2].re /= beta1[2].re;
          D[2].im = 0.0;
        } else if (D[2].re == 0.0) {
          D[2].re = 0.0;
          D[2].im /= beta1[2].re;
        } else {
          D[2].re /= beta1[2].re;
          D[2].im /= beta1[2].re;
        }
      } else if (beta1[2].re == 0.0) {
        if (D[2].re == 0.0) {
          D[2].re = D[2].im / beta1[2].im;
          D[2].im = 0.0;
        } else if (D[2].im == 0.0) {
          D[2].re = 0.0;
          D[2].im = -(D_re / beta1[2].im);
        } else {
          D[2].re = D[2].im / beta1[2].im;
          D[2].im = -(D_re / beta1[2].im);
        }
      } else {
        V_im = muDoubleScalarAbs(beta1[2].re);
        colnorm = muDoubleScalarAbs(beta1[2].im);
        if (V_im > colnorm) {
          V_re = beta1[2].im / beta1[2].re;
          V_im = beta1[2].re + V_re * beta1[2].im;
          D[2].re = (D[2].re + V_re * D[2].im) / V_im;
          D[2].im = (D[2].im - V_re * D_re) / V_im;
        } else if (colnorm == V_im) {
          if (beta1[2].re > 0.0) {
            colnorm = 0.5;
          } else {
            colnorm = -0.5;
          }

          if (beta1[2].im > 0.0) {
            V_re = 0.5;
          } else {
            V_re = -0.5;
          }

          D[2].re = (D[2].re * colnorm + D[2].im * V_re) / V_im;
          D[2].im = (D[2].im * colnorm - D_re * V_re) / V_im;
        } else {
          V_re = beta1[2].re / beta1[2].im;
          V_im = beta1[2].im + V_re * beta1[2].re;
          colnorm = V_re * D[2].im - D[2].re;
          D[2].re = (V_re * D[2].re + D[2].im) / V_im;
          D[2].im = colnorm / V_im;
        }
      }
    }

    if (info != 0) {
      st.site = &ub_emlrtRSI;
      d_warning(&st);
    }
  }
}

void eig(const emlrtStack *sp, const real_T A[9], creal_T V[9], creal_T D[3])
{
  int32_T info;
  boolean_T p;
  int32_T k;
  int32_T j;
  boolean_T exitg2;
  int32_T exitg1;
  creal_T At[9];
  creal_T beta1[3];
  real_T colnorm;
  real_T D_re;
  int32_T b;
  real_T V_im;
  real_T V_re;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  info = 0;
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

    D[0].re = rtNaN;
    D[0].im = 0.0;
    D[1].re = rtNaN;
    D[1].im = 0.0;
    D[2].re = rtNaN;
    D[2].im = 0.0;
  } else {
    st.site = &rb_emlrtRSI;
    p = true;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j < 3)) {
      k = 0;
      do {
        exitg1 = 0;
        if (k <= j) {
          if (!(A[k + 3 * j] == A[j + 3 * k])) {
            p = false;
            exitg1 = 1;
          } else {
            k++;
          }
        } else {
          j++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (p) {
      st.site = &sb_emlrtRSI;
      schur(&st, A, V, At);
      D[0] = At[0];
      D[1] = At[4];
      D[2] = At[8];
    } else {
      st.site = &tb_emlrtRSI;
      for (k = 0; k < 9; k++) {
        At[k].re = A[k];
        At[k].im = 0.0;
      }

      b_st.site = &re_emlrtRSI;
      xzggev(&b_st, At, &info, D, beta1, V);
      for (k = 0; k <= 6; k += 3) {
        b_st.site = &se_emlrtRSI;
        colnorm = c_xnrm2(&b_st, V, k + 1);
        b = k + 3;
        for (j = k + 1; j <= b; j++) {
          V_re = V[j - 1].re;
          V_im = V[j - 1].im;
          if (V_im == 0.0) {
            V[j - 1].re = V_re / colnorm;
            V[j - 1].im = 0.0;
          } else if (V_re == 0.0) {
            V[j - 1].re = 0.0;
            V[j - 1].im = V_im / colnorm;
          } else {
            V[j - 1].re = V_re / colnorm;
            V[j - 1].im = V_im / colnorm;
          }
        }
      }

      D_re = D[0].re;
      if (beta1[0].im == 0.0) {
        if (D[0].im == 0.0) {
          D[0].re /= beta1[0].re;
          D[0].im = 0.0;
        } else if (D[0].re == 0.0) {
          D[0].re = 0.0;
          D[0].im /= beta1[0].re;
        } else {
          D[0].re /= beta1[0].re;
          D[0].im /= beta1[0].re;
        }
      } else if (beta1[0].re == 0.0) {
        if (D[0].re == 0.0) {
          D[0].re = D[0].im / beta1[0].im;
          D[0].im = 0.0;
        } else if (D[0].im == 0.0) {
          D[0].re = 0.0;
          D[0].im = -(D_re / beta1[0].im);
        } else {
          D[0].re = D[0].im / beta1[0].im;
          D[0].im = -(D_re / beta1[0].im);
        }
      } else {
        V_im = muDoubleScalarAbs(beta1[0].re);
        colnorm = muDoubleScalarAbs(beta1[0].im);
        if (V_im > colnorm) {
          V_re = beta1[0].im / beta1[0].re;
          V_im = beta1[0].re + V_re * beta1[0].im;
          D[0].re = (D[0].re + V_re * D[0].im) / V_im;
          D[0].im = (D[0].im - V_re * D_re) / V_im;
        } else if (colnorm == V_im) {
          if (beta1[0].re > 0.0) {
            colnorm = 0.5;
          } else {
            colnorm = -0.5;
          }

          if (beta1[0].im > 0.0) {
            V_re = 0.5;
          } else {
            V_re = -0.5;
          }

          D[0].re = (D[0].re * colnorm + D[0].im * V_re) / V_im;
          D[0].im = (D[0].im * colnorm - D_re * V_re) / V_im;
        } else {
          V_re = beta1[0].re / beta1[0].im;
          V_im = beta1[0].im + V_re * beta1[0].re;
          colnorm = V_re * D[0].im - D[0].re;
          D[0].re = (V_re * D[0].re + D[0].im) / V_im;
          D[0].im = colnorm / V_im;
        }
      }

      D_re = D[1].re;
      if (beta1[1].im == 0.0) {
        if (D[1].im == 0.0) {
          D[1].re /= beta1[1].re;
          D[1].im = 0.0;
        } else if (D[1].re == 0.0) {
          D[1].re = 0.0;
          D[1].im /= beta1[1].re;
        } else {
          D[1].re /= beta1[1].re;
          D[1].im /= beta1[1].re;
        }
      } else if (beta1[1].re == 0.0) {
        if (D[1].re == 0.0) {
          D[1].re = D[1].im / beta1[1].im;
          D[1].im = 0.0;
        } else if (D[1].im == 0.0) {
          D[1].re = 0.0;
          D[1].im = -(D_re / beta1[1].im);
        } else {
          D[1].re = D[1].im / beta1[1].im;
          D[1].im = -(D_re / beta1[1].im);
        }
      } else {
        V_im = muDoubleScalarAbs(beta1[1].re);
        colnorm = muDoubleScalarAbs(beta1[1].im);
        if (V_im > colnorm) {
          V_re = beta1[1].im / beta1[1].re;
          V_im = beta1[1].re + V_re * beta1[1].im;
          D[1].re = (D[1].re + V_re * D[1].im) / V_im;
          D[1].im = (D[1].im - V_re * D_re) / V_im;
        } else if (colnorm == V_im) {
          if (beta1[1].re > 0.0) {
            colnorm = 0.5;
          } else {
            colnorm = -0.5;
          }

          if (beta1[1].im > 0.0) {
            V_re = 0.5;
          } else {
            V_re = -0.5;
          }

          D[1].re = (D[1].re * colnorm + D[1].im * V_re) / V_im;
          D[1].im = (D[1].im * colnorm - D_re * V_re) / V_im;
        } else {
          V_re = beta1[1].re / beta1[1].im;
          V_im = beta1[1].im + V_re * beta1[1].re;
          colnorm = V_re * D[1].im - D[1].re;
          D[1].re = (V_re * D[1].re + D[1].im) / V_im;
          D[1].im = colnorm / V_im;
        }
      }

      D_re = D[2].re;
      if (beta1[2].im == 0.0) {
        if (D[2].im == 0.0) {
          D[2].re /= beta1[2].re;
          D[2].im = 0.0;
        } else if (D[2].re == 0.0) {
          D[2].re = 0.0;
          D[2].im /= beta1[2].re;
        } else {
          D[2].re /= beta1[2].re;
          D[2].im /= beta1[2].re;
        }
      } else if (beta1[2].re == 0.0) {
        if (D[2].re == 0.0) {
          D[2].re = D[2].im / beta1[2].im;
          D[2].im = 0.0;
        } else if (D[2].im == 0.0) {
          D[2].re = 0.0;
          D[2].im = -(D_re / beta1[2].im);
        } else {
          D[2].re = D[2].im / beta1[2].im;
          D[2].im = -(D_re / beta1[2].im);
        }
      } else {
        V_im = muDoubleScalarAbs(beta1[2].re);
        colnorm = muDoubleScalarAbs(beta1[2].im);
        if (V_im > colnorm) {
          V_re = beta1[2].im / beta1[2].re;
          V_im = beta1[2].re + V_re * beta1[2].im;
          D[2].re = (D[2].re + V_re * D[2].im) / V_im;
          D[2].im = (D[2].im - V_re * D_re) / V_im;
        } else if (colnorm == V_im) {
          if (beta1[2].re > 0.0) {
            colnorm = 0.5;
          } else {
            colnorm = -0.5;
          }

          if (beta1[2].im > 0.0) {
            V_re = 0.5;
          } else {
            V_re = -0.5;
          }

          D[2].re = (D[2].re * colnorm + D[2].im * V_re) / V_im;
          D[2].im = (D[2].im * colnorm - D_re * V_re) / V_im;
        } else {
          V_re = beta1[2].re / beta1[2].im;
          V_im = beta1[2].im + V_re * beta1[2].re;
          colnorm = V_re * D[2].im - D[2].re;
          D[2].re = (V_re * D[2].re + D[2].im) / V_im;
          D[2].im = colnorm / V_im;
        }
      }
    }

    if (info != 0) {
      st.site = &ub_emlrtRSI;
      d_warning(&st);
    }
  }
}

/* End of code generation (eig.c) */
