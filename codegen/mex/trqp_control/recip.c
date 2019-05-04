/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * recip.c
 *
 * Code generation for function 'recip'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "recip.h"

/* Function Definitions */
creal_T recip(const creal_T y)
{
  creal_T z;
  real_T brm;
  real_T bim;
  real_T d;
  brm = muDoubleScalarAbs(y.re);
  bim = muDoubleScalarAbs(y.im);
  if (y.im == 0.0) {
    z.re = 1.0 / y.re;
    z.im = 0.0;
  } else if (y.re == 0.0) {
    z.re = 0.0;
    z.im = -1.0 / y.im;
  } else if (brm > bim) {
    bim = y.im / y.re;
    d = y.re + bim * y.im;
    z.re = 1.0 / d;
    z.im = -bim / d;
  } else if (brm == bim) {
    bim = 0.5;
    if (y.re < 0.0) {
      bim = -0.5;
    }

    d = 0.5;
    if (y.im < 0.0) {
      d = -0.5;
    }

    z.re = bim / brm;
    z.im = -d / brm;
  } else {
    bim = y.re / y.im;
    d = y.im + bim * y.re;
    z.re = bim / d;
    z.im = -1.0 / d;
  }

  return z;
}

/* End of code generation (recip.c) */
