/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CR3BP_fast.c
 *
 * Code generation for function 'CR3BP_fast'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "CR3BP_fast.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 17,    /* lineNo */
  "CR3BP_fast",                        /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\halo_orbits\\CR3BP_fast.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 18,  /* lineNo */
  "CR3BP_fast",                        /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\halo_orbits\\CR3BP_fast.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 12,  /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

/* Function Definitions */
void CR3BP_fast(const emlrtStack *sp, real_T t, const real_T X[6], real_T mu,
                real_T X_dot[6])
{
  real_T a_tmp;
  real_T r2;
  real_T r1_tmp;
  real_T r1;
  real_T b_a_tmp;
  emlrtStack st;
  (void)t;
  st.prev = sp;
  st.tls = sp->tls;

  /*  Reshape to column vector */
  /*  Positions */
  /*  Velocities */
  /*  Distances to primaries */
  a_tmp = X[0] + mu;
  st.site = &emlrtRSI;
  r2 = X[1] * X[1];
  r1_tmp = X[2] * X[2];
  r1 = (a_tmp * a_tmp + r2) + r1_tmp;
  if (r1 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  r1 = muDoubleScalarSqrt(r1);
  b_a_tmp = (X[0] - 1.0) + mu;
  st.site = &b_emlrtRSI;
  r2 = (b_a_tmp * b_a_tmp + r2) + r1_tmp;
  if (r2 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  r2 = muDoubleScalarSqrt(r2);

  /*  Accelerations  */
  X_dot[0] = X[3];
  X_dot[1] = X[4];
  X_dot[2] = X[5];
  r1_tmp = muDoubleScalarPower(r1, 3.0);
  r2 = muDoubleScalarPower(r2, 3.0);
  X_dot[3] = ((2.0 * X[4] + X[0]) - (1.0 - mu) * (a_tmp / r1_tmp)) - mu *
    b_a_tmp / r2;
  X_dot[4] = ((-2.0 * X[3] + X[1]) - (1.0 - mu) * (X[1] / r1_tmp)) - mu * X[1] /
    r2;
  X_dot[5] = -(1.0 - mu) * X[2] / r1_tmp - mu * X[2] / r2;
}

/* End of code generation (CR3BP_fast.c) */
