/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CR3BP_cart_control_STMSTT.c
 *
 * Code generation for function 'CR3BP_cart_control_STMSTT'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "CR3BP_cart_control_STMSTT.h"
#include "fXX.h"
#include "fX.h"
#include "sqrt.h"
#include "CR3BP_cart_control_STMSTT_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 21,    /* lineNo */
  "CR3BP_cart_control_STMSTT",         /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\CR3BP_cart_control_STMSTT.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 22,  /* lineNo */
  "CR3BP_cart_control_STMSTT",         /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\CR3BP_cart_control_STMSTT.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 28,  /* lineNo */
  "CR3BP_cart_control_STMSTT",         /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\CR3BP_cart_control_STMSTT.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 32,  /* lineNo */
  "CR3BP_cart_control_STMSTT",         /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\CR3BP_cart_control_STMSTT.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 37,  /* lineNo */
  "CR3BP_cart_control_STMSTT",         /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\CR3BP_cart_control_STMSTT.m"/* pathName */
};

/* Function Definitions */
void CR3BP_cart_control_STMSTT(const emlrtStack *sp, real_T t, const real_T X
  [1110], real_T mu, real_T c, real_T Tmax, real_T Xdot[1110])
{
  real_T STM[100];
  real_T a_tmp;
  real_T alpha1;
  real_T beta1;
  real_T r1;
  real_T b_a_tmp;
  real_T r2;
  real_T d0;
  real_T fXmat[100];
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  char_T TRANSA;
  char_T TRANSB;
  real_T STMdot[100];
  real_T fXXten[1000];
  real_T b_alpha1;
  real_T b_beta1;
  ptrdiff_t b_m_t;
  ptrdiff_t b_n_t;
  ptrdiff_t b_k_t;
  ptrdiff_t b_lda_t;
  ptrdiff_t b_ldb_t;
  ptrdiff_t b_ldc_t;
  char_T b_TRANSA;
  char_T b_TRANSB;
  int32_T i;
  int32_T i0;
  int32_T i1;
  real_T b_X[100];
  real_T b[100];
  real_T a[100];
  real_T c_X[1000];
  int32_T fXXten_tmp;
  real_T temp[1000];
  int32_T b_fXXten_tmp;
  emlrtStack st;
  (void)t;
  st.prev = sp;
  st.tls = sp->tls;

  /*     %% Unpack */
  memcpy(&STM[0], &X[10], 100U * sizeof(real_T));

  /*     %% Dynamics */
  a_tmp = X[0] + mu;
  alpha1 = X[1] * X[1];
  beta1 = X[2] * X[2];
  r1 = (a_tmp * a_tmp + alpha1) + beta1;
  st.site = &emlrtRSI;
  b_sqrt(&st, &r1);
  b_a_tmp = (X[0] - 1.0) + mu;
  r2 = (b_a_tmp * b_a_tmp + alpha1) + beta1;
  st.site = &b_emlrtRSI;
  b_sqrt(&st, &r2);
  d0 = ((X[7] * X[7] + X[8] * X[8]) + X[9] * X[9]) + 1.0E-8;
  st.site = &f_emlrtRSI;
  b_sqrt(&st, &d0);

  /*     %% STM Dynamics */
  st.site = &g_emlrtRSI;
  fX(&st, X, c, mu, Tmax, fXmat);
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)10;
  n_t = (ptrdiff_t)10;
  k_t = (ptrdiff_t)10;
  lda_t = (ptrdiff_t)10;
  ldb_t = (ptrdiff_t)10;
  ldc_t = (ptrdiff_t)10;
  TRANSA = 'N';
  TRANSB = 'N';
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &fXmat[0], &lda_t, &STM[0],
        &ldb_t, &beta1, &STMdot[0], &ldc_t);

  /*     %% STT Dynamics */
  st.site = &i_emlrtRSI;
  fXX(&st, X, c, mu, Tmax, fXXten);
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)10;
  n_t = (ptrdiff_t)10;
  k_t = (ptrdiff_t)10;
  lda_t = (ptrdiff_t)10;
  ldb_t = (ptrdiff_t)10;
  ldc_t = (ptrdiff_t)10;
  TRANSA = 'N';
  TRANSB = 'N';
  b_alpha1 = 1.0;
  b_beta1 = 0.0;
  b_m_t = (ptrdiff_t)10;
  b_n_t = (ptrdiff_t)10;
  b_k_t = (ptrdiff_t)10;
  b_lda_t = (ptrdiff_t)10;
  b_ldb_t = (ptrdiff_t)10;
  b_ldc_t = (ptrdiff_t)10;
  b_TRANSA = 'N';
  b_TRANSB = 'N';
  for (i = 0; i < 10; i++) {
    for (i0 = 0; i0 < 10; i0++) {
      for (i1 = 0; i1 < 10; i1++) {
        b[i1 + 10 * i0] = fXXten[(i + 10 * i1) + 100 * i0];
      }
    }

    memcpy(&b_X[0], &X[10], 100U * sizeof(real_T));
    for (i0 = 0; i0 < 10; i0++) {
      for (i1 = 0; i1 < 10; i1++) {
        a[i1 + 10 * i0] = b_X[i0 + 10 * i1];
      }
    }

    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &b[0],
          &ldb_t, &beta1, &b_X[0], &ldc_t);
    dgemm(&b_TRANSA, &b_TRANSB, &b_m_t, &b_n_t, &b_k_t, &b_alpha1, &b_X[0],
          &b_lda_t, &STM[0], &b_ldb_t, &b_beta1, &a[0], &b_ldc_t);
    for (i0 = 0; i0 < 10; i0++) {
      for (i1 = 0; i1 < 10; i1++) {
        temp[(i + 10 * i1) + 100 * i0] = a[i1 + 10 * i0];
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)10;
  n_t = (ptrdiff_t)10;
  k_t = (ptrdiff_t)10;
  lda_t = (ptrdiff_t)10;
  ldb_t = (ptrdiff_t)10;
  ldc_t = (ptrdiff_t)10;
  TRANSA = 'N';
  TRANSB = 'N';
  for (i = 0; i < 10; i++) {
    memcpy(&c_X[0], &X[110], 1000U * sizeof(real_T));
    for (i0 = 0; i0 < 10; i0++) {
      memcpy(&b[i0 * 10], &c_X[i * 100 + i0 * 10], 10U * sizeof(real_T));
    }

    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &fXmat[0], &lda_t, &b[0],
          &ldb_t, &beta1, &a[0], &ldc_t);
    for (i0 = 0; i0 < 10; i0++) {
      for (i1 = 0; i1 < 10; i1++) {
        fXXten_tmp = i1 + 10 * i0;
        b_fXXten_tmp = fXXten_tmp + 100 * i;
        fXXten[b_fXXten_tmp] = a[fXXten_tmp] + temp[b_fXXten_tmp];
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  Naive STTdot calculation */
  /*      for i = 1:10 */
  /*          for j = 1:10 */
  /*              for k = 1:10 */
  /*                  comp1 = 0; */
  /*                  comp2 = 0; */
  /*                  for gam1 = 1:10 */
  /*                      comp1 = comp1 + fXmat(i,gam1)*STT(gam1,j,k); % matrix part */
  /*                      for gam2 = 1:10 */
  /*                          comp2 = comp2 + fXXten(i,gam1,gam2)*STM(gam1,j)*STM(gam2,k); % tensor part */
  /*                      end */
  /*                  end */
  /*                  STTdot(i,j,k) = comp1 + comp2; */
  /*              end */
  /*          end */
  /*      end */
  /*     %% Repack */
  Xdot[0] = X[3];
  Xdot[1] = X[4];
  Xdot[2] = X[5];
  beta1 = muDoubleScalarPower(r1, 3.0);
  alpha1 = muDoubleScalarPower(r2, 3.0);
  Xdot[3] = (((2.0 * X[4] + X[0]) - (1.0 - mu) * (a_tmp / beta1)) - mu * b_a_tmp
             / alpha1) + Tmax * (X[7] / X[6]);
  Xdot[4] = (((-2.0 * X[3] + X[1]) - (1.0 - mu) * (X[1] / beta1)) - mu * X[1] /
             alpha1) + Tmax * (X[8] / X[6]);
  Xdot[5] = (-(1.0 - mu) * (X[2] / beta1) - mu * X[2] / alpha1) + Tmax * (X[9] /
    X[6]);
  Xdot[6] = -Tmax * d0 / c;
  Xdot[7] = 0.0;
  Xdot[8] = 0.0;
  Xdot[9] = 0.0;
  memcpy(&Xdot[10], &STMdot[0], 100U * sizeof(real_T));
  memcpy(&Xdot[110], &fXXten[0], 1000U * sizeof(real_T));
}

/* End of code generation (CR3BP_cart_control_STMSTT.c) */
