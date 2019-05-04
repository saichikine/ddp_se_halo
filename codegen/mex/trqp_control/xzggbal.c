/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzggbal.c
 *
 * Code generation for function 'xzggbal'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "xzggbal.h"
#include "eml_int_forloop_overflow_check.h"
#include "trqp_control_data.h"

/* Variable Definitions */
static emlrtRSInfo bf_emlrtRSI = { 22, /* lineNo */
  "xzggbal",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 26, /* lineNo */
  "xzggbal",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 35, /* lineNo */
  "xzggbal",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo ef_emlrtRSI = { 39, /* lineNo */
  "xzggbal",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo ff_emlrtRSI = { 139,/* lineNo */
  "eml_zggbal_eigsearch_rows",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo gf_emlrtRSI = { 59, /* lineNo */
  "eml_zggbal_simtran",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo hf_emlrtRSI = { 76, /* lineNo */
  "eml_zggbal_simtran",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo if_emlrtRSI = { 101,/* lineNo */
  "eml_zggbal_eigsearch_cols",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo jf_emlrtRSI = { 105,/* lineNo */
  "eml_zggbal_eigsearch_cols",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

/* Function Definitions */
void xzggbal(const emlrtStack *sp, creal_T A[9], int32_T *ilo, int32_T *ihi,
             int32_T rscale[3])
{
  int32_T exitg2;
  int32_T i;
  int32_T j;
  boolean_T found;
  int32_T ii;
  boolean_T exitg3;
  int32_T nzcount;
  real_T atmp_re;
  real_T atmp_im;
  int32_T exitg1;
  int32_T jj;
  boolean_T exitg4;
  int32_T atmp_re_tmp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  rscale[0] = 1;
  rscale[1] = 1;
  rscale[2] = 1;
  *ilo = 1;
  *ihi = 3;
  do {
    exitg2 = 0;
    st.site = &bf_emlrtRSI;
    i = 0;
    j = 0;
    found = false;
    ii = *ihi;
    exitg3 = false;
    while ((!exitg3) && (ii > 0)) {
      nzcount = 0;
      i = ii;
      j = *ihi;
      b_st.site = &ff_emlrtRSI;
      if ((1 <= *ihi) && (*ihi > 2147483646)) {
        c_st.site = &bb_emlrtRSI;
        check_forloop_overflow_error(&c_st, true);
      }

      jj = 0;
      exitg4 = false;
      while ((!exitg4) && (jj <= *ihi - 1)) {
        if ((A[(ii + 3 * jj) - 1].re != 0.0) || (A[(ii + 3 * jj) - 1].im != 0.0)
            || (ii == jj + 1)) {
          if (nzcount == 0) {
            j = jj + 1;
            nzcount = 1;
            jj++;
          } else {
            nzcount = 2;
            exitg4 = true;
          }
        } else {
          jj++;
        }
      }

      if (nzcount < 2) {
        found = true;
        exitg3 = true;
      } else {
        ii--;
      }
    }

    if (!found) {
      exitg2 = 2;
    } else {
      st.site = &cf_emlrtRSI;
      if (i != *ihi) {
        b_st.site = &gf_emlrtRSI;
        atmp_re = A[i - 1].re;
        atmp_im = A[i - 1].im;
        A[i - 1] = A[*ihi - 1];
        A[*ihi - 1].re = atmp_re;
        A[*ihi - 1].im = atmp_im;
        atmp_re = A[i + 2].re;
        atmp_im = A[i + 2].im;
        A[i + 2] = A[*ihi + 2];
        A[*ihi + 2].re = atmp_re;
        A[*ihi + 2].im = atmp_im;
        atmp_re = A[i + 5].re;
        atmp_im = A[i + 5].im;
        A[i + 5] = A[*ihi + 5];
        A[*ihi + 5].re = atmp_re;
        A[*ihi + 5].im = atmp_im;
      }

      if (j != *ihi) {
        b_st.site = &hf_emlrtRSI;
        if ((1 <= *ihi) && (*ihi > 2147483646)) {
          c_st.site = &bb_emlrtRSI;
          check_forloop_overflow_error(&c_st, true);
        }

        for (ii = 0; ii < *ihi; ii++) {
          nzcount = ii + 3 * (j - 1);
          atmp_re = A[nzcount].re;
          atmp_im = A[ii + 3 * (j - 1)].im;
          jj = ii + 3 * (*ihi - 1);
          A[nzcount] = A[jj];
          A[jj].re = atmp_re;
          A[jj].im = atmp_im;
        }
      }

      rscale[*ihi - 1] = j;
      (*ihi)--;
      if (*ihi == 1) {
        rscale[0] = 1;
        exitg2 = 1;
      }
    }
  } while (exitg2 == 0);

  if (exitg2 == 1) {
  } else {
    do {
      exitg1 = 0;
      st.site = &df_emlrtRSI;
      i = 0;
      j = 0;
      found = false;
      b_st.site = &if_emlrtRSI;
      if ((*ilo <= *ihi) && (*ihi > 2147483646)) {
        c_st.site = &bb_emlrtRSI;
        check_forloop_overflow_error(&c_st, true);
      }

      jj = *ilo;
      exitg3 = false;
      while ((!exitg3) && (jj <= *ihi)) {
        nzcount = 0;
        i = *ihi;
        j = jj;
        b_st.site = &jf_emlrtRSI;
        if ((*ilo <= *ihi) && (*ihi > 2147483646)) {
          c_st.site = &bb_emlrtRSI;
          check_forloop_overflow_error(&c_st, true);
        }

        ii = *ilo;
        exitg4 = false;
        while ((!exitg4) && (ii <= *ihi)) {
          if ((A[(ii + 3 * (jj - 1)) - 1].re != 0.0) || (A[(ii + 3 * (jj - 1)) -
               1].im != 0.0) || (ii == jj)) {
            if (nzcount == 0) {
              i = ii;
              nzcount = 1;
              ii++;
            } else {
              nzcount = 2;
              exitg4 = true;
            }
          } else {
            ii++;
          }
        }

        if (nzcount < 2) {
          found = true;
          exitg3 = true;
        } else {
          jj++;
        }
      }

      if (!found) {
        exitg1 = 1;
      } else {
        st.site = &ef_emlrtRSI;
        if (i != *ilo) {
          b_st.site = &gf_emlrtRSI;
          for (ii = *ilo; ii < 4; ii++) {
            nzcount = 3 * (ii - 1);
            atmp_re_tmp = (i + nzcount) - 1;
            atmp_re = A[atmp_re_tmp].re;
            atmp_im = A[(i + 3 * (ii - 1)) - 1].im;
            jj = (*ilo + nzcount) - 1;
            A[atmp_re_tmp] = A[jj];
            A[jj].re = atmp_re;
            A[jj].im = atmp_im;
          }
        }

        if (j != *ilo) {
          b_st.site = &hf_emlrtRSI;
          if ((1 <= *ihi) && (*ihi > 2147483646)) {
            c_st.site = &bb_emlrtRSI;
            check_forloop_overflow_error(&c_st, true);
          }

          for (ii = 0; ii < *ihi; ii++) {
            nzcount = ii + 3 * (j - 1);
            atmp_re = A[nzcount].re;
            atmp_im = A[ii + 3 * (j - 1)].im;
            jj = ii + 3 * (*ilo - 1);
            A[nzcount] = A[jj];
            A[jj].re = atmp_re;
            A[jj].im = atmp_im;
          }
        }

        rscale[*ilo - 1] = j;
        (*ilo)++;
        if (*ilo == *ihi) {
          rscale[*ilo - 1] = *ilo;
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/* End of code generation (xzggbal.c) */
