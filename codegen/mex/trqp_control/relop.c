/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * relop.c
 *
 * Code generation for function 'relop'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "relop.h"

/* Function Definitions */
void absRelopProxies(const creal_T a, const creal_T b, real_T *x, real_T *y)
{
  real_T ma;
  boolean_T SCALEA;
  real_T mb;
  boolean_T SCALEB;
  real_T Mb;
  real_T d0;
  real_T Ma;
  ma = muDoubleScalarAbs(a.re);
  if ((ma > 8.9884656743115785E+307) || (muDoubleScalarAbs(a.im) >
       8.9884656743115785E+307)) {
    SCALEA = true;
  } else {
    SCALEA = false;
  }

  mb = muDoubleScalarAbs(b.re);
  if ((mb > 8.9884656743115785E+307) || (muDoubleScalarAbs(b.im) >
       8.9884656743115785E+307)) {
    SCALEB = true;
  } else {
    SCALEB = false;
  }

  if (SCALEA || SCALEB) {
    *x = muDoubleScalarHypot(a.re / 2.0, a.im / 2.0);
    *y = muDoubleScalarHypot(b.re / 2.0, b.im / 2.0);
  } else {
    *x = muDoubleScalarHypot(a.re, a.im);
    *y = muDoubleScalarHypot(b.re, b.im);
  }

  if (*x == *y) {
    Mb = muDoubleScalarAbs(a.im);
    d0 = muDoubleScalarAbs(b.im);
    if (ma > Mb) {
      Ma = ma;
      ma = Mb;
    } else {
      Ma = Mb;
    }

    if (mb > d0) {
      Mb = mb;
      mb = d0;
    } else {
      Mb = d0;
    }

    if (Ma > Mb) {
      if (ma < mb) {
        *x = Ma - Mb;
        *y = (ma / 2.0 + mb / 2.0) / (Ma / 2.0 + Mb / 2.0) * (mb - ma);
      } else {
        *x = Ma;
        *y = Mb;
      }
    } else if (Ma < Mb) {
      if (ma > mb) {
        *y = Mb - Ma;
        *x = (ma / 2.0 + mb / 2.0) / (Ma / 2.0 + Mb / 2.0) * (ma - mb);
      } else {
        *x = Ma;
        *y = Mb;
      }
    } else {
      *x = ma;
      *y = mb;
    }

    if (*x == *y) {
      *x = muDoubleScalarAtan2(a.im, a.re);
      *y = muDoubleScalarAtan2(b.im, b.re);
      if (*x == *y) {
        if (*x > 0.78539816339744828) {
          if (*x > 2.3561944901923448) {
            *x = -a.im;
            *y = -b.im;
          } else {
            *x = -a.re;
            *y = -b.re;
          }
        } else if (*x > -0.78539816339744828) {
          *x = a.im;
          *y = b.im;
        } else if (*x > -2.3561944901923448) {
          *x = a.re;
          *y = b.re;
        } else {
          *x = -a.im;
          *y = -b.im;
        }

        if (*x == *y) {
          *x = 0.0;
          *y = 0.0;
        }
      }
    }
  }
}

/* End of code generation (relop.c) */
