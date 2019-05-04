/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * inv.c
 *
 * Code generation for function 'inv'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "inv.h"
#include "warning.h"
#include "norm.h"
#include "eml_int_forloop_overflow_check.h"
#include "trqp_multipliers_data.h"

/* Variable Definitions */
static emlrtRSInfo ob_emlrtRSI = { 21, /* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 22, /* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 173,/* lineNo */
  "invNxN",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 180,/* lineNo */
  "invNxN",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 183,/* lineNo */
  "invNxN",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 190,/* lineNo */
  "invNxN",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 45, /* lineNo */
  "xgeru",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 59, /* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 51, /* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 42, /* lineNo */
  "checkcond",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 46, /* lineNo */
  "checkcond",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtMCInfo c_emlrtMCI = { 53,  /* lineNo */
  19,                                  /* colNo */
  "flt2str",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"/* pName */
};

static emlrtRSInfo eh_emlrtRSI = { 53, /* lineNo */
  "flt2str",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"/* pathName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14]);
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_sprintf_, const char_T *identifier, char_T y[14]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14]);
static void invNxN(const emlrtStack *sp, const real_T x[36], real_T y[36]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14])
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m19;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m19, 2, pArrays, "sprintf", true,
    location);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_sprintf_, const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_sprintf_), &thisId, y);
  emlrtDestroyArray(&a__output_of_sprintf_);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 14);
  emlrtDestroyArray(&src);
}

static void invNxN(const emlrtStack *sp, const real_T x[36], real_T y[36])
{
  real_T b_x[36];
  int32_T jp1j;
  int32_T j;
  int8_T ipiv[6];
  int32_T b;
  int32_T jj;
  int32_T n;
  int32_T k;
  int8_T p[6];
  int32_T iy;
  int32_T jA;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T ijA;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  memset(&y[0], 0, 36U * sizeof(real_T));
  st.site = &qb_emlrtRSI;
  memcpy(&b_x[0], &x[0], 36U * sizeof(real_T));
  b_st.site = &ub_emlrtRSI;
  for (jp1j = 0; jp1j < 6; jp1j++) {
    ipiv[jp1j] = (int8_T)(1 + jp1j);
  }

  for (j = 0; j < 5; j++) {
    b = j * 7;
    jj = j * 7;
    jp1j = b + 2;
    n = 6 - j;
    c_st.site = &vb_emlrtRSI;
    d_st.site = &yb_emlrtRSI;
    iy = 0;
    ix = b;
    smax = muDoubleScalarAbs(b_x[b]);
    e_st.site = &ac_emlrtRSI;
    for (k = 2; k <= n; k++) {
      ix++;
      s = muDoubleScalarAbs(b_x[ix]);
      if (s > smax) {
        iy = k - 1;
        smax = s;
      }
    }

    if (b_x[jj + iy] != 0.0) {
      if (iy != 0) {
        iy += j;
        ipiv[j] = (int8_T)(iy + 1);
        ix = j;
        for (k = 0; k < 6; k++) {
          smax = b_x[ix];
          b_x[ix] = b_x[iy];
          b_x[iy] = smax;
          ix += 6;
          iy += 6;
        }
      }

      jA = (jj - j) + 6;
      c_st.site = &wb_emlrtRSI;
      for (n = jp1j; n <= jA; n++) {
        b_x[n - 1] /= b_x[jj];
      }
    }

    n = 4 - j;
    iy = b + 6;
    c_st.site = &xb_emlrtRSI;
    d_st.site = &bc_emlrtRSI;
    e_st.site = &cc_emlrtRSI;
    f_st.site = &dc_emlrtRSI;
    jA = jj + 8;
    g_st.site = &ec_emlrtRSI;
    for (jp1j = 0; jp1j <= n; jp1j++) {
      smax = b_x[iy];
      if (b_x[iy] != 0.0) {
        ix = jj + 1;
        b = (jA - j) + 4;
        g_st.site = &fc_emlrtRSI;
        if ((jA <= b) && (b > 2147483646)) {
          h_st.site = &bb_emlrtRSI;
          check_forloop_overflow_error(&h_st, true);
        }

        for (ijA = jA; ijA <= b; ijA++) {
          b_x[ijA - 1] += b_x[ix] * -smax;
          ix++;
        }
      }

      iy += 6;
      jA += 6;
    }
  }

  for (jp1j = 0; jp1j < 6; jp1j++) {
    p[jp1j] = (int8_T)(1 + jp1j);
  }

  for (k = 0; k < 5; k++) {
    if (ipiv[k] > 1 + k) {
      jA = ipiv[k] - 1;
      iy = p[jA];
      p[jA] = p[k];
      p[k] = (int8_T)iy;
    }
  }

  for (k = 0; k < 6; k++) {
    y[k + 6 * (p[k] - 1)] = 1.0;
    st.site = &rb_emlrtRSI;
    for (j = k + 1; j < 7; j++) {
      jp1j = 6 * (p[k] - 1);
      jA = (j + jp1j) - 1;
      if (y[jA] != 0.0) {
        iy = j + 1;
        st.site = &sb_emlrtRSI;
        for (n = iy; n < 7; n++) {
          ijA = (n + jp1j) - 1;
          y[ijA] -= y[jA] * b_x[(n + 6 * (j - 1)) - 1];
        }
      }
    }
  }

  st.site = &tb_emlrtRSI;
  b_st.site = &gc_emlrtRSI;
  for (j = 0; j < 6; j++) {
    jA = 6 * j;
    for (k = 5; k >= 0; k--) {
      iy = 6 * k;
      jp1j = k + jA;
      if (y[jp1j] != 0.0) {
        y[jp1j] /= b_x[k + iy];
        c_st.site = &hc_emlrtRSI;
        for (n = 0; n < k; n++) {
          ijA = n + jA;
          y[ijA] -= y[jp1j] * b_x[n + iy];
        }
      }
    }
  }
}

void inv(const emlrtStack *sp, const real_T x[36], real_T y[36])
{
  real_T n1x;
  real_T n1xinv;
  real_T rc;
  const mxArray *b_y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 6 };

  static const char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  const mxArray *c_y;
  const mxArray *m1;
  char_T cv1[14];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ob_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  invNxN(&st, x, y);
  st.site = &pb_emlrtRSI;
  n1x = b_norm(x);
  n1xinv = b_norm(y);
  rc = 1.0 / (n1x * n1xinv);
  if ((n1x == 0.0) || (n1xinv == 0.0) || (rc == 0.0)) {
    b_st.site = &ic_emlrtRSI;
    warning(&b_st);
  } else {
    if (muDoubleScalarIsNaN(rc) || (rc < 2.2204460492503131E-16)) {
      b_st.site = &jc_emlrtRSI;
      b_y = NULL;
      m0 = emlrtCreateCharArray(2, iv0);
      emlrtInitCharArrayR2013a(&b_st, 6, m0, &rfmt[0]);
      emlrtAssign(&b_y, m0);
      c_y = NULL;
      m1 = emlrtCreateDoubleScalar(rc);
      emlrtAssign(&c_y, m1);
      c_st.site = &eh_emlrtRSI;
      emlrt_marshallIn(&c_st, b_sprintf(&c_st, b_y, c_y, &c_emlrtMCI),
                       "<output of sprintf>", cv1);
      b_st.site = &jc_emlrtRSI;
      b_warning(&b_st, cv1);
    }
  }
}

/* End of code generation (inv.c) */
