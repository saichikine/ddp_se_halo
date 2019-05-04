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
#include "trqp_control.h"
#include "norm.h"

/* Function Definitions */
real_T b_norm(const real_T x[9])
{
  real_T y;
  int32_T j;
  boolean_T exitg1;
  real_T s;
  y = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 3)) {
    s = (muDoubleScalarAbs(x[3 * j]) + muDoubleScalarAbs(x[1 + 3 * j])) +
      muDoubleScalarAbs(x[2 + 3 * j]);
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

real_T c_norm(const creal_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 3.3121686421112381E-170;
  absxk = muDoubleScalarAbs(x[0].re);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = muDoubleScalarAbs(x[0].im);
  if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = muDoubleScalarAbs(x[1].re);
  if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = muDoubleScalarAbs(x[1].im);
  if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = muDoubleScalarAbs(x[2].re);
  if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = muDoubleScalarAbs(x[2].im);
  if (absxk > scale) {
    t = scale / absxk;
    y = 1.0 + y * t * t;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * muDoubleScalarSqrt(y);
}

/* End of code generation (norm.c) */
