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
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "eig.h"
#include "warning.h"
#include "schur.h"
#include "ishermitian.h"
#include "xgeev.h"
#include "anyNonFinite.h"
#include "trqp_multipliers_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo kc_emlrtRSI = { 118,/* lineNo */
  "eig",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 133,/* lineNo */
  "eig",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 163,/* lineNo */
  "eig",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 181,/* lineNo */
  "eig",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 20, /* lineNo */
  "ishermitian",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\ishermitian.m"/* pathName */
};

/* Function Definitions */
void b_eig(const emlrtStack *sp, const creal_T A[36], creal_T V[36], creal_T D[6])
{
  int32_T info;
  creal_T T[36];
  int32_T k;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  info = 0;
  if (anyNonFinite(A)) {
    for (info = 0; info < 36; info++) {
      V[info].re = rtNaN;
      V[info].im = 0.0;
    }

    for (info = 0; info < 6; info++) {
      D[info].re = rtNaN;
      D[info].im = 0.0;
    }
  } else {
    if (ishermitian(A)) {
      st.site = &lc_emlrtRSI;
      b_schur(&st, A, V, T);
      for (k = 0; k < 6; k++) {
        D[k] = T[k + 6 * k];
      }
    } else {
      st.site = &mc_emlrtRSI;
      xgeev(&st, A, &info, D, V);
    }

    if (info != 0) {
      st.site = &nc_emlrtRSI;
      d_warning(&st);
    }
  }
}

void eig(const emlrtStack *sp, const real_T A[36], creal_T V[36], creal_T D[6])
{
  int32_T info;
  boolean_T p;
  int32_T k;
  int32_T i;
  boolean_T exitg2;
  int32_T exitg1;
  creal_T b_A[36];
  ptrdiff_t info_t;
  creal_T vl;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  info = 0;
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

    for (i = 0; i < 6; i++) {
      D[i].re = rtNaN;
      D[i].im = 0.0;
    }
  } else {
    st.site = &kc_emlrtRSI;
    b_st.site = &oc_emlrtRSI;
    p = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 6)) {
      i = 0;
      do {
        exitg1 = 0;
        if (i <= k) {
          if (!(A[i + 6 * k] == A[k + 6 * i])) {
            p = false;
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          k++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (p) {
      st.site = &lc_emlrtRSI;
      schur(&st, A, V, b_A);
      for (k = 0; k < 6; k++) {
        D[k] = b_A[k + 6 * k];
      }
    } else {
      st.site = &mc_emlrtRSI;
      b_st.site = &hf_emlrtRSI;
      for (k = 0; k < 36; k++) {
        b_A[k].re = A[k];
        b_A[k].im = 0.0;
      }

      info_t = LAPACKE_zgeev(102, 'N', 'V', (ptrdiff_t)6, (lapack_complex_double
        *)&b_A[0], (ptrdiff_t)6, (lapack_complex_double *)&D[0],
        (lapack_complex_double *)&vl, (ptrdiff_t)1, (lapack_complex_double *)&V
        [0], (ptrdiff_t)6);
      info = (int32_T)info_t;
      c_st.site = &mf_emlrtRSI;
      if (info < 0) {
        if (info == -1010) {
          emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI, "MATLAB:nomem",
            "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
            "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 13, cv0, 12, info);
        }
      }
    }

    if (info != 0) {
      st.site = &nc_emlrtRSI;
      d_warning(&st);
    }
  }
}

/* End of code generation (eig.c) */
