/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fX.c
 *
 * Code generation for function 'fX'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "CR3BP_cart_control_STMSTT.h"
#include "fX.h"
#include "CR3BP_cart_control_STMSTT_data.h"

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI = { 49,  /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 50,  /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 51,  /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 55,  /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 60,  /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 61,  /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 62,  /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 66,  /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 71,  /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 72,  /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 73,  /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 77,  /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 89, /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 90, /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 91, /* lineNo */
  "fX",                                /* fcnName */
  "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\fX.m"/* pathName */
};

/* Function Definitions */
void fX(const emlrtStack *sp, const real_T X[1110], real_T c, real_T mu, real_T
        Tmax, real_T b_fX[100])
{
  real_T a_tmp;
  real_T b_a_tmp;
  real_T c_a_tmp;
  real_T a;
  real_T b_a;
  real_T c_a;
  real_T d_a;
  real_T fX_tmp;
  real_T b_fX_tmp;
  real_T c_fX_tmp;
  real_T d_fX_tmp;
  real_T e_fX_tmp;
  real_T f_fX_tmp;
  real_T g_fX_tmp;
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
  b_fX[0] = 0.0;
  b_fX[10] = 0.0;
  b_fX[20] = 0.0;
  b_fX[30] = 1.0;
  b_fX[40] = 0.0;
  b_fX[50] = 0.0;
  b_fX[60] = 0.0;
  b_fX[70] = 0.0;
  b_fX[80] = 0.0;
  b_fX[90] = 0.0;
  b_fX[1] = 0.0;
  b_fX[11] = 0.0;
  b_fX[21] = 0.0;
  b_fX[31] = 0.0;
  b_fX[41] = 1.0;
  b_fX[51] = 0.0;
  b_fX[61] = 0.0;
  b_fX[71] = 0.0;
  b_fX[81] = 0.0;
  b_fX[91] = 0.0;
  b_fX[2] = 0.0;
  b_fX[12] = 0.0;
  b_fX[22] = 0.0;
  b_fX[32] = 0.0;
  b_fX[42] = 0.0;
  b_fX[52] = 1.0;
  b_fX[62] = 0.0;
  b_fX[72] = 0.0;
  b_fX[82] = 0.0;
  b_fX[92] = 0.0;
  st.site = &n_emlrtRSI;
  a_tmp = mu + X[0];
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &n_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &n_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &n_emlrtRSI;
  b_a_tmp = X[1] * X[1];
  c_a_tmp = X[2] * X[2];
  a = (a_tmp * a_tmp + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &n_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &n_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &n_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &n_emlrtRSI;
  b_a = ((a_tmp - 1.0) * (a_tmp - 1.0) + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (b_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &n_emlrtRSI;
  c_a = (mu + X[0]) - 1.0;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &n_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &n_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &n_emlrtRSI;
  c_a = (c_a * c_a + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (c_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &n_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &n_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &n_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &n_emlrtRSI;
  d_a = (a_tmp * a_tmp + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (d_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  fX_tmp = 2.0 * mu + 2.0 * X[0];
  b_fX[3] = ((((mu - 1.0) / muDoubleScalarPower(a, 1.5) - mu /
               muDoubleScalarPower(b_a, 1.5)) + 3.0 * mu * (fX_tmp - 2.0) * ((mu
    + X[0]) - 1.0) / (2.0 * muDoubleScalarPower(c_a, 2.5))) - 3.0 * fX_tmp *
             a_tmp * (mu - 1.0) / (2.0 * muDoubleScalarPower(d_a, 2.5))) + 1.0;
  st.site = &o_emlrtRSI;
  a = (mu + X[0]) - 1.0;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &o_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &o_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &o_emlrtRSI;
  a = (a * a + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &o_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &o_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &o_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &o_emlrtRSI;
  b_a = (a_tmp * a_tmp + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (b_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_fX_tmp = 3.0 * mu * X[1];
  b_fX[13] = b_fX_tmp * ((mu + X[0]) - 1.0) / muDoubleScalarPower(a, 2.5) - 3.0 *
    X[1] * a_tmp * (mu - 1.0) / muDoubleScalarPower(b_a, 2.5);
  st.site = &p_emlrtRSI;
  a = (mu + X[0]) - 1.0;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &p_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &p_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &p_emlrtRSI;
  a = (a * a + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &p_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &p_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &p_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &p_emlrtRSI;
  b_a = (a_tmp * a_tmp + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (b_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  c_fX_tmp = 3.0 * mu * X[2];
  b_fX[23] = c_fX_tmp * ((mu + X[0]) - 1.0) / muDoubleScalarPower(a, 2.5) - 3.0 *
    X[2] * a_tmp * (mu - 1.0) / muDoubleScalarPower(b_a, 2.5);
  b_fX[33] = 0.0;
  b_fX[43] = 2.0;
  b_fX[53] = 0.0;
  st.site = &q_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  d_fX_tmp = X[6] * X[6];
  e_fX_tmp = -(Tmax * X[7]);
  b_fX[63] = e_fX_tmp / d_fX_tmp;
  f_fX_tmp = Tmax / X[6];
  b_fX[73] = f_fX_tmp;
  b_fX[83] = 0.0;
  b_fX[93] = 0.0;
  st.site = &r_emlrtRSI;
  a = (mu + X[0]) - 1.0;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &r_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &r_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &r_emlrtRSI;
  a = (a * a + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &r_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &r_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &r_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &r_emlrtRSI;
  b_a = (a_tmp * a_tmp + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (b_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_fX[4] = b_fX_tmp * ((2.0 * mu + 2.0 * X[0]) - 2.0) / (2.0 *
    muDoubleScalarPower(a, 2.5)) - 3.0 * X[1] * fX_tmp * (mu - 1.0) / (2.0 *
    muDoubleScalarPower(b_a, 2.5));
  st.site = &s_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &s_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &s_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &s_emlrtRSI;
  a = (a_tmp * a_tmp + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &s_emlrtRSI;
  b_a = (mu + X[0]) - 1.0;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &s_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &s_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &s_emlrtRSI;
  b_a = (b_a * b_a + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (b_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &s_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &s_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &s_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &s_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &s_emlrtRSI;
  c_a = (a_tmp * a_tmp + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (c_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &s_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &s_emlrtRSI;
  d_a = (mu + X[0]) - 1.0;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &s_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &s_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &s_emlrtRSI;
  d_a = (d_a * d_a + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (d_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_fX[14] = ((((mu - 1.0) / muDoubleScalarPower(a, 1.5) - mu /
                muDoubleScalarPower(b_a, 1.5)) - 3.0 * b_a_tmp * (mu - 1.0) /
               muDoubleScalarPower(c_a, 2.5)) + 3.0 * mu * b_a_tmp /
              muDoubleScalarPower(d_a, 2.5)) + 1.0;
  st.site = &t_emlrtRSI;
  a = (mu + X[0]) - 1.0;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &t_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &t_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &t_emlrtRSI;
  a = (a * a + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &t_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &t_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &t_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &t_emlrtRSI;
  b_a = (a_tmp * a_tmp + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (b_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_fX_tmp *= X[2];
  c_a = 3.0 * X[1] * X[2] * (mu - 1.0);
  b_fX[24] = b_fX_tmp / muDoubleScalarPower(a, 2.5) - c_a / muDoubleScalarPower
    (b_a, 2.5);
  b_fX[34] = -2.0;
  b_fX[44] = 0.0;
  b_fX[54] = 0.0;
  st.site = &u_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  g_fX_tmp = -(Tmax * X[8]);
  b_fX[64] = g_fX_tmp / d_fX_tmp;
  b_fX[74] = 0.0;
  b_fX[84] = f_fX_tmp;
  b_fX[94] = 0.0;
  st.site = &v_emlrtRSI;
  a = (mu + X[0]) - 1.0;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &v_emlrtRSI;
  a = (a * a + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &v_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &v_emlrtRSI;
  b_a = (a_tmp * a_tmp + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (b_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_fX[5] = c_fX_tmp * ((2.0 * mu + 2.0 * X[0]) - 2.0) / (2.0 *
    muDoubleScalarPower(a, 2.5)) - 3.0 * X[2] * fX_tmp * (mu - 1.0) / (2.0 *
    muDoubleScalarPower(b_a, 2.5));
  st.site = &w_emlrtRSI;
  a = (mu + X[0]) - 1.0;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &w_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &w_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &w_emlrtRSI;
  a = (a * a + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &w_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &w_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &w_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &w_emlrtRSI;
  b_a = (a_tmp * a_tmp + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (b_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_fX[15] = b_fX_tmp / muDoubleScalarPower(a, 2.5) - c_a / muDoubleScalarPower
    (b_a, 2.5);
  st.site = &x_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &x_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &x_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &x_emlrtRSI;
  a = (a_tmp * a_tmp + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &x_emlrtRSI;
  b_a = (mu + X[0]) - 1.0;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &x_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &x_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &x_emlrtRSI;
  b_a = (b_a * b_a + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (b_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &x_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &x_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &x_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &x_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &x_emlrtRSI;
  c_a = (a_tmp * a_tmp + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (c_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  st.site = &x_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &x_emlrtRSI;
  d_a = (mu + X[0]) - 1.0;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &x_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &x_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &x_emlrtRSI;
  d_a = (d_a * d_a + b_a_tmp) + c_a_tmp;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (d_a < 0.0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }

  b_fX[25] = (((mu - 1.0) / muDoubleScalarPower(a, 1.5) - mu /
               muDoubleScalarPower(b_a, 1.5)) - 3.0 * c_a_tmp * (mu - 1.0) /
              muDoubleScalarPower(c_a, 2.5)) + 3.0 * mu * c_a_tmp /
    muDoubleScalarPower(d_a, 2.5);
  b_fX[35] = 0.0;
  b_fX[45] = 0.0;
  b_fX[55] = 0.0;
  st.site = &y_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  fX_tmp = -(Tmax * X[9]);
  b_fX[65] = fX_tmp / d_fX_tmp;
  b_fX[75] = 0.0;
  b_fX[85] = 0.0;
  b_fX[95] = f_fX_tmp;
  b_fX[6] = 0.0;
  b_fX[16] = 0.0;
  b_fX[26] = 0.0;
  b_fX[36] = 0.0;
  b_fX[46] = 0.0;
  b_fX[56] = 0.0;
  b_fX[66] = 0.0;
  st.site = &ab_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &ab_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &ab_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &ab_emlrtRSI;
  a_tmp = ((X[7] * X[7] + X[8] * X[8]) + X[9] * X[9]) + 1.0E-8;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  d_st.site = &db_emlrtRSI;
  e_st.site = &eb_emlrtRSI;
  f_st.site = &fb_emlrtRSI;
  if (a_tmp < 0.0) {
    emlrtErrorWithMessageIdR2018a(&f_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  b_fX[76] = e_fX_tmp / (c * muDoubleScalarSqrt(a_tmp));
  st.site = &bb_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &bb_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &bb_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &bb_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  d_st.site = &db_emlrtRSI;
  e_st.site = &eb_emlrtRSI;
  f_st.site = &fb_emlrtRSI;
  if (a_tmp < 0.0) {
    emlrtErrorWithMessageIdR2018a(&f_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  b_fX[86] = g_fX_tmp / (c * muDoubleScalarSqrt(a_tmp));
  st.site = &cb_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &cb_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &cb_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  st.site = &cb_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  d_st.site = &db_emlrtRSI;
  e_st.site = &eb_emlrtRSI;
  f_st.site = &fb_emlrtRSI;
  if (a_tmp < 0.0) {
    emlrtErrorWithMessageIdR2018a(&f_st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  b_fX[96] = fX_tmp / (c * muDoubleScalarSqrt(a_tmp));
  b_fX[7] = 0.0;
  b_fX[17] = 0.0;
  b_fX[27] = 0.0;
  b_fX[37] = 0.0;
  b_fX[47] = 0.0;
  b_fX[57] = 0.0;
  b_fX[67] = 0.0;
  b_fX[77] = 0.0;
  b_fX[87] = 0.0;
  b_fX[97] = 0.0;
  b_fX[8] = 0.0;
  b_fX[18] = 0.0;
  b_fX[28] = 0.0;
  b_fX[38] = 0.0;
  b_fX[48] = 0.0;
  b_fX[58] = 0.0;
  b_fX[68] = 0.0;
  b_fX[78] = 0.0;
  b_fX[88] = 0.0;
  b_fX[98] = 0.0;
  b_fX[9] = 0.0;
  b_fX[19] = 0.0;
  b_fX[29] = 0.0;
  b_fX[39] = 0.0;
  b_fX[49] = 0.0;
  b_fX[59] = 0.0;
  b_fX[69] = 0.0;
  b_fX[79] = 0.0;
  b_fX[89] = 0.0;
  b_fX[99] = 0.0;
}

/* End of code generation (fX.c) */
