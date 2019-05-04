/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xpotrf.c
 *
 * Code generation for function 'xpotrf'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "xpotrf.h"
#include "blas.h"

/* Function Definitions */
int32_T b_xpotrf(creal_T A[9])
{
  int32_T info;
  int32_T j;
  boolean_T exitg1;
  int32_T jm1;
  int32_T jj;
  real_T ajj;
  int32_T ix;
  int32_T iy;
  int32_T k;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  real_T A_re;
  real_T A_im;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  static const creal_T alpha1 = { -1.0,/* re */
    0.0                                /* im */
  };

  static const creal_T beta1 = { 1.0,  /* re */
    0.0                                /* im */
  };

  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 3)) {
    jm1 = j - 1;
    jj = j + j * 3;
    ajj = 0.0;
    if (j >= 1) {
      ix = j;
      iy = j;
      for (k = 0; k <= jm1; k++) {
        ajj += A[ix].re * A[iy].re + A[ix].im * A[iy].im;
        ix += 3;
        iy += 3;
      }
    }

    ajj = A[jj].re - ajj;
    if ((A[jj].im == 0.0) && (ajj > 0.0)) {
      ajj = muDoubleScalarSqrt(ajj);
      A[jj].re = ajj;
      A[jj].im = 0.0;
      if (j + 1 < 3) {
        iy = jj + 2;
        for (k = 0; k <= jm1; k++) {
          A[j + 3 * k].im = -A[j + 3 * k].im;
        }

        if (j >= 1) {
          TRANSA = 'N';
          m_t = (ptrdiff_t)(2 - j);
          n_t = (ptrdiff_t)j;
          lda_t = (ptrdiff_t)3;
          incx_t = (ptrdiff_t)3;
          incy_t = (ptrdiff_t)1;
          zgemv(&TRANSA, &m_t, &n_t, (real_T *)&alpha1, (real_T *)&A[j + 1],
                &lda_t, (real_T *)&A[j], &incx_t, (real_T *)&beta1, (real_T *)
                &A[jj + 1], &incy_t);
        }

        for (k = 0; k <= jm1; k++) {
          A[j + 3 * k].im = -A[j + 3 * k].im;
        }

        ajj = 1.0 / ajj;
        ix = (jj - j) + 3;
        for (k = iy; k <= ix; k++) {
          A_re = A[k - 1].re;
          A_im = A[k - 1].im;
          A[k - 1].re = ajj * A_re - 0.0 * A_im;
          A[k - 1].im = ajj * A_im + 0.0 * A_re;
        }
      }

      j++;
    } else {
      A[jj].re = ajj;
      A[jj].im = 0.0;
      info = j + 1;
      exitg1 = true;
    }
  }

  return info;
}

int32_T xpotrf(real_T A[9])
{
  int32_T info;
  int32_T j;
  boolean_T exitg1;
  int32_T jj;
  real_T ajj;
  int32_T ix;
  int32_T iy;
  int32_T k;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 3)) {
    jj = j + j * 3;
    ajj = 0.0;
    if (j >= 1) {
      ix = j;
      iy = j;
      for (k = 0; k < j; k++) {
        ajj += A[ix] * A[iy];
        ix += 3;
        iy += 3;
      }
    }

    ajj = A[jj] - ajj;
    if (ajj > 0.0) {
      ajj = muDoubleScalarSqrt(ajj);
      A[jj] = ajj;
      if (j + 1 < 3) {
        iy = jj + 2;
        if (j >= 1) {
          alpha1 = -1.0;
          beta1 = 1.0;
          TRANSA = 'N';
          m_t = (ptrdiff_t)(2 - j);
          n_t = (ptrdiff_t)j;
          lda_t = (ptrdiff_t)3;
          incx_t = (ptrdiff_t)3;
          incy_t = (ptrdiff_t)1;
          dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A[j + 1], &lda_t, &A[j], &incx_t,
                &beta1, &A[jj + 1], &incy_t);
        }

        ajj = 1.0 / ajj;
        ix = (jj - j) + 3;
        for (k = iy; k <= ix; k++) {
          A[k - 1] *= ajj;
        }
      }

      j++;
    } else {
      A[jj] = ajj;
      info = j + 1;
      exitg1 = true;
    }
  }

  return info;
}

/* End of code generation (xpotrf.c) */
