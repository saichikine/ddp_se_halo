/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "sqrt.h"
#include "trqp_control_data.h"

/* Function Definitions */
void b_sqrt(const emlrtStack *sp, real_T *x)
{
  if (*x < 0.0) {
    emlrtErrorWithMessageIdR2018a(sp, &f_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  *x = muDoubleScalarSqrt(*x);
}

void c_sqrt(creal_T *x)
{
  real_T xr;
  real_T xi;
  real_T yr;
  real_T absxr;
  xr = x->re;
  xi = x->im;
  if (xi == 0.0) {
    if (xr < 0.0) {
      yr = 0.0;
      xr = muDoubleScalarSqrt(-xr);
    } else {
      yr = muDoubleScalarSqrt(xr);
      xr = 0.0;
    }
  } else if (xr == 0.0) {
    if (xi < 0.0) {
      yr = muDoubleScalarSqrt(-xi / 2.0);
      xr = -yr;
    } else {
      yr = muDoubleScalarSqrt(xi / 2.0);
      xr = yr;
    }
  } else if (muDoubleScalarIsNaN(xr)) {
    yr = xr;
  } else if (muDoubleScalarIsNaN(xi)) {
    yr = xi;
    xr = xi;
  } else if (muDoubleScalarIsInf(xi)) {
    yr = muDoubleScalarAbs(xi);
    xr = xi;
  } else if (muDoubleScalarIsInf(xr)) {
    if (xr < 0.0) {
      yr = 0.0;
      xr = xi * -xr;
    } else {
      yr = xr;
      xr = 0.0;
    }
  } else {
    absxr = muDoubleScalarAbs(xr);
    yr = muDoubleScalarAbs(xi);
    if ((absxr > 4.4942328371557893E+307) || (yr > 4.4942328371557893E+307)) {
      absxr *= 0.5;
      yr = muDoubleScalarHypot(absxr, yr * 0.5);
      if (yr > absxr) {
        yr = muDoubleScalarSqrt(yr) * muDoubleScalarSqrt(1.0 + absxr / yr);
      } else {
        yr = muDoubleScalarSqrt(yr) * 1.4142135623730951;
      }
    } else {
      yr = muDoubleScalarSqrt((muDoubleScalarHypot(absxr, yr) + absxr) * 0.5);
    }

    if (xr > 0.0) {
      xr = 0.5 * (xi / yr);
    } else {
      if (xi < 0.0) {
        xr = -yr;
      } else {
        xr = yr;
      }

      yr = 0.5 * (xi / xr);
    }
  }

  x->re = yr;
  x->im = xr;
}

/* End of code generation (sqrt.c) */
