/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xtrsm.c
 *
 * Code generation for function 'xtrsm'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "xtrsm.h"

/* Function Definitions */
void b_xtrsm(const creal_T A[36], creal_T B[6])
{
  int32_T k;
  int32_T kAcol;
  real_T B_re;
  real_T B_im;
  real_T A_re;
  real_T A_im;
  real_T brm;
  real_T bim;
  real_T s;
  int32_T i;
  for (k = 5; k >= 0; k--) {
    kAcol = 6 * k;
    if ((B[k].re != 0.0) || (B[k].im != 0.0)) {
      B_re = B[k].re;
      B_im = B[k].im;
      A_re = A[k + kAcol].re;
      A_im = A[k + kAcol].im;
      if (A_im == 0.0) {
        if (B_im == 0.0) {
          B[k].re = B_re / A_re;
          B[k].im = 0.0;
        } else if (B_re == 0.0) {
          B[k].re = 0.0;
          B[k].im = B_im / A_re;
        } else {
          B[k].re = B_re / A_re;
          B[k].im = B_im / A_re;
        }
      } else if (A_re == 0.0) {
        if (B_re == 0.0) {
          B[k].re = B_im / A_im;
          B[k].im = 0.0;
        } else if (B_im == 0.0) {
          B[k].re = 0.0;
          B[k].im = -(B_re / A_im);
        } else {
          B[k].re = B_im / A_im;
          B[k].im = -(B_re / A_im);
        }
      } else {
        brm = muDoubleScalarAbs(A_re);
        bim = muDoubleScalarAbs(A_im);
        if (brm > bim) {
          s = A_im / A_re;
          bim = A_re + s * A_im;
          B[k].re = (B_re + s * B_im) / bim;
          B[k].im = (B_im - s * B_re) / bim;
        } else if (bim == brm) {
          if (A_re > 0.0) {
            s = 0.5;
          } else {
            s = -0.5;
          }

          if (A_im > 0.0) {
            bim = 0.5;
          } else {
            bim = -0.5;
          }

          B[k].re = (B_re * s + B_im * bim) / brm;
          B[k].im = (B_im * s - B_re * bim) / brm;
        } else {
          s = A_re / A_im;
          bim = A_im + s * A_re;
          B[k].re = (s * B_re + B_im) / bim;
          B[k].im = (s * B_im - B_re) / bim;
        }
      }

      for (i = 0; i < k; i++) {
        B_im = B[k].re * A[i + kAcol].im + B[k].im * A[i + kAcol].re;
        B[i].re -= B[k].re * A[i + kAcol].re - B[k].im * A[i + kAcol].im;
        B[i].im -= B_im;
      }
    }
  }
}

void xtrsm(const creal_T A[36], creal_T B[6])
{
  int32_T k;
  int32_T kAcol;
  int32_T i;
  real_T B_im;
  for (k = 0; k < 6; k++) {
    kAcol = 6 * k;
    if ((B[k].re != 0.0) || (B[k].im != 0.0)) {
      for (i = k + 2; i < 7; i++) {
        B_im = B[k].re * A[(i + kAcol) - 1].im + B[k].im * A[(i + kAcol) - 1].re;
        B[i - 1].re -= B[k].re * A[(i + kAcol) - 1].re - B[k].im * A[(i + kAcol)
          - 1].im;
        B[i - 1].im -= B_im;
      }
    }
  }
}

/* End of code generation (xtrsm.c) */
