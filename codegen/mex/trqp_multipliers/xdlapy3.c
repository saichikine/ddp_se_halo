/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdlapy3.c
 *
 * Code generation for function 'xdlapy3'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "xdlapy3.h"

/* Function Definitions */
real_T xdlapy3(real_T x1, real_T x2, real_T x3)
{
  real_T y;
  real_T a;
  real_T b;
  real_T c;
  a = muDoubleScalarAbs(x1);
  b = muDoubleScalarAbs(x2);
  c = muDoubleScalarAbs(x3);
  y = muDoubleScalarMax(a, b);
  if (c > y) {
    y = c;
  }

  if ((y > 0.0) && (!muDoubleScalarIsInf(y))) {
    a /= y;
    b /= y;
    c /= y;
    y *= muDoubleScalarSqrt((a * a + c * c) + b * b);
  } else {
    y = (a + b) + c;
  }

  return y;
}

/* End of code generation (xdlapy3.c) */
