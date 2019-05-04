/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdlanv2.c
 *
 * Code generation for function 'xdlanv2'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "xdlanv2.h"

/* Function Definitions */
void xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T *rt1r, real_T
             *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn)
{
  real_T d2;
  real_T p;
  real_T z;
  real_T bcmis;
  real_T scale;
  real_T bcmax;
  int32_T b_b;
  int32_T b_c;
  int32_T b_bcmis;
  real_T b_p;
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    *cs = 0.0;
    *sn = 1.0;
    z = *d;
    *d = *a;
    *a = z;
    *b = -*c;
    *c = 0.0;
  } else {
    d2 = *a - *d;
    if ((d2 == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
      *cs = 1.0;
      *sn = 0.0;
    } else {
      p = 0.5 * d2;
      bcmis = muDoubleScalarAbs(*b);
      scale = muDoubleScalarAbs(*c);
      bcmax = muDoubleScalarMax(bcmis, scale);
      if (!(*b < 0.0)) {
        b_b = 1;
      } else {
        b_b = -1;
      }

      if (!(*c < 0.0)) {
        b_c = 1;
      } else {
        b_c = -1;
      }

      bcmis = muDoubleScalarMin(bcmis, scale) * (real_T)b_b * (real_T)b_c;
      scale = muDoubleScalarMax(muDoubleScalarAbs(p), bcmax);
      z = p / scale * p + bcmax / scale * bcmis;
      if (z >= 8.8817841970012523E-16) {
        *a = muDoubleScalarSqrt(scale) * muDoubleScalarSqrt(z);
        if (!(p < 0.0)) {
          b_p = *a;
        } else {
          b_p = -*a;
        }

        z = p + b_p;
        *a = *d + z;
        *d -= bcmax / z * bcmis;
        bcmax = muDoubleScalarHypot(*c, z);
        *cs = z / bcmax;
        *sn = *c / bcmax;
        *b -= *c;
        *c = 0.0;
      } else {
        bcmis = *b + *c;
        bcmax = muDoubleScalarHypot(bcmis, d2);
        *cs = muDoubleScalarSqrt(0.5 * (1.0 + muDoubleScalarAbs(bcmis) / bcmax));
        if (!(bcmis < 0.0)) {
          b_bcmis = 1;
        } else {
          b_bcmis = -1;
        }

        *sn = -(p / (bcmax * *cs)) * (real_T)b_bcmis;
        bcmax = *a * *cs + *b * *sn;
        scale = -*a * *sn + *b * *cs;
        z = *c * *cs + *d * *sn;
        bcmis = -*c * *sn + *d * *cs;
        *b = scale * *cs + bcmis * *sn;
        *c = -bcmax * *sn + z * *cs;
        z = 0.5 * ((bcmax * *cs + z * *sn) + (-scale * *sn + bcmis * *cs));
        *a = z;
        *d = z;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              d2 = muDoubleScalarSqrt(muDoubleScalarAbs(*b));
              bcmis = muDoubleScalarSqrt(muDoubleScalarAbs(*c));
              *a = d2 * bcmis;
              if (!(*c < 0.0)) {
                p = *a;
              } else {
                p = -*a;
              }

              bcmax = 1.0 / muDoubleScalarSqrt(muDoubleScalarAbs(*b + *c));
              *a = z + p;
              *d = z - p;
              *b -= *c;
              *c = 0.0;
              scale = d2 * bcmax;
              bcmis *= bcmax;
              z = *cs * scale - *sn * bcmis;
              *sn = *cs * bcmis + *sn * scale;
              *cs = z;
            }
          } else {
            *b = -*c;
            *c = 0.0;
            z = *cs;
            *cs = -*sn;
            *sn = z;
          }
        }
      }
    }
  }

  *rt1r = *a;
  *rt2r = *d;
  if (*c == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    *rt1i = muDoubleScalarSqrt(muDoubleScalarAbs(*b)) * muDoubleScalarSqrt
      (muDoubleScalarAbs(*c));
    *rt2i = -*rt1i;
  }
}

/* End of code generation (xdlanv2.c) */
