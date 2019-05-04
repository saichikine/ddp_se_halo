/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * norm.c
 *
 * Code generation for function 'norm'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "norm.h"

/* Function Definitions */
real_T b_norm(const real_T x[36])
{
  real_T y;
  int32_T j;
  boolean_T exitg1;
  real_T s;
  int32_T i;
  y = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 6)) {
    s = 0.0;
    for (i = 0; i < 6; i++) {
      s += muDoubleScalarAbs(x[i + 6 * j]);
    }

    if (muDoubleScalarIsNaN(s)) {
      y = rtNaN;
      exitg1 = true;
    } else {
      if (s > y) {
        y = s;
      }

      j++;
    }
  }

  return y;
}

real_T c_norm(const creal_T x[6])
{
  real_T y;
  real_T scale;
  int32_T k;
  real_T absxk;
  real_T t;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 6; k++) {
    absxk = muDoubleScalarAbs(x[k].re);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }

    absxk = muDoubleScalarAbs(x[k].im);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * muDoubleScalarSqrt(y);
}

/* End of code generation (norm.c) */
