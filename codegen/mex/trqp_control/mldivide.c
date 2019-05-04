/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "mldivide.h"
#include "warning.h"
#include "trqp_control_data.h"

/* Function Definitions */
void mldivide(const emlrtStack *sp, const creal_T A[9], const real_T B[3],
              creal_T Y[3])
{
  creal_T b_A[9];
  int32_T r1;
  int32_T r2;
  int32_T r3;
  real_T maxval;
  real_T a21;
  real_T brm;
  real_T bim;
  real_T A_re;
  real_T A_im;
  int32_T rtemp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &mg_emlrtRSI;
  c_st.site = &ng_emlrtRSI;
  memcpy(&b_A[0], &A[0], 9U * sizeof(creal_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = muDoubleScalarAbs(A[0].re) + muDoubleScalarAbs(A[0].im);
  a21 = muDoubleScalarAbs(A[1].re) + muDoubleScalarAbs(A[1].im);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (muDoubleScalarAbs(A[2].re) + muDoubleScalarAbs(A[2].im) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  if (A[r1].im == 0.0) {
    if (A[r2].im == 0.0) {
      b_A[r2].re = A[r2].re / A[r1].re;
      b_A[r2].im = 0.0;
    } else if (A[r2].re == 0.0) {
      b_A[r2].re = 0.0;
      b_A[r2].im = A[r2].im / A[r1].re;
    } else {
      b_A[r2].re = A[r2].re / A[r1].re;
      b_A[r2].im = A[r2].im / A[r1].re;
    }
  } else if (A[r1].re == 0.0) {
    if (A[r2].re == 0.0) {
      b_A[r2].re = A[r2].im / A[r1].im;
      b_A[r2].im = 0.0;
    } else if (A[r2].im == 0.0) {
      b_A[r2].re = 0.0;
      b_A[r2].im = -(A[r2].re / A[r1].im);
    } else {
      b_A[r2].re = A[r2].im / A[r1].im;
      b_A[r2].im = -(A[r2].re / A[r1].im);
    }
  } else {
    brm = muDoubleScalarAbs(A[r1].re);
    bim = muDoubleScalarAbs(A[r1].im);
    if (brm > bim) {
      bim = A[r1].im / A[r1].re;
      a21 = A[r1].re + bim * A[r1].im;
      b_A[r2].re = (A[r2].re + bim * A[r2].im) / a21;
      b_A[r2].im = (A[r2].im - bim * A[r2].re) / a21;
    } else if (bim == brm) {
      if (A[r1].re > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      if (A[r1].im > 0.0) {
        maxval = 0.5;
      } else {
        maxval = -0.5;
      }

      b_A[r2].re = (A[r2].re * bim + A[r2].im * maxval) / brm;
      b_A[r2].im = (A[r2].im * bim - A[r2].re * maxval) / brm;
    } else {
      bim = A[r1].re / A[r1].im;
      a21 = A[r1].im + bim * A[r1].re;
      b_A[r2].re = (bim * A[r2].re + A[r2].im) / a21;
      b_A[r2].im = (bim * A[r2].im - A[r2].re) / a21;
    }
  }

  A_re = b_A[r3].re;
  maxval = b_A[r1].re;
  if (b_A[r1].im == 0.0) {
    if (b_A[r3].im == 0.0) {
      b_A[r3].re /= b_A[r1].re;
      b_A[r3].im = 0.0;
    } else if (b_A[r3].re == 0.0) {
      b_A[r3].re = 0.0;
      b_A[r3].im /= maxval;
    } else {
      b_A[r3].re /= b_A[r1].re;
      b_A[r3].im /= maxval;
    }
  } else if (b_A[r1].re == 0.0) {
    if (b_A[r3].re == 0.0) {
      b_A[r3].re = b_A[r3].im / b_A[r1].im;
      b_A[r3].im = 0.0;
    } else if (b_A[r3].im == 0.0) {
      b_A[r3].re = 0.0;
      b_A[r3].im = -(A_re / b_A[r1].im);
    } else {
      b_A[r3].re = b_A[r3].im / b_A[r1].im;
      b_A[r3].im = -(A_re / b_A[r1].im);
    }
  } else {
    brm = muDoubleScalarAbs(b_A[r1].re);
    bim = muDoubleScalarAbs(b_A[r1].im);
    if (brm > bim) {
      bim = b_A[r1].im / b_A[r1].re;
      a21 = b_A[r1].re + bim * b_A[r1].im;
      b_A[r3].re = (b_A[r3].re + bim * b_A[r3].im) / a21;
      b_A[r3].im = (b_A[r3].im - bim * A_re) / a21;
    } else if (bim == brm) {
      if (b_A[r1].re > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      if (b_A[r1].im > 0.0) {
        maxval = 0.5;
      } else {
        maxval = -0.5;
      }

      b_A[r3].re = (b_A[r3].re * bim + b_A[r3].im * maxval) / brm;
      b_A[r3].im = (b_A[r3].im * bim - A_re * maxval) / brm;
    } else {
      bim = b_A[r1].re / b_A[r1].im;
      a21 = b_A[r1].im + bim * b_A[r1].re;
      maxval = bim * b_A[r3].im - b_A[r3].re;
      b_A[r3].re = (bim * b_A[r3].re + b_A[r3].im) / a21;
      b_A[r3].im = maxval / a21;
    }
  }

  A_im = b_A[r2].re * b_A[3 + r1].im + b_A[r2].im * b_A[3 + r1].re;
  b_A[3 + r2].re -= b_A[r2].re * b_A[3 + r1].re - b_A[r2].im * b_A[3 + r1].im;
  b_A[3 + r2].im -= A_im;
  A_im = b_A[r3].re * b_A[3 + r1].im + b_A[r3].im * b_A[3 + r1].re;
  b_A[3 + r3].re -= b_A[r3].re * b_A[3 + r1].re - b_A[r3].im * b_A[3 + r1].im;
  b_A[3 + r3].im -= A_im;
  A_im = b_A[r2].re * b_A[6 + r1].im + b_A[r2].im * b_A[6 + r1].re;
  b_A[6 + r2].re -= b_A[r2].re * b_A[6 + r1].re - b_A[r2].im * b_A[6 + r1].im;
  b_A[6 + r2].im -= A_im;
  A_im = b_A[r3].re * b_A[6 + r1].im + b_A[r3].im * b_A[6 + r1].re;
  b_A[6 + r3].re -= b_A[r3].re * b_A[6 + r1].re - b_A[r3].im * b_A[6 + r1].im;
  b_A[6 + r3].im -= A_im;
  if (muDoubleScalarAbs(b_A[3 + r3].re) + muDoubleScalarAbs(b_A[3 + r3].im) >
      muDoubleScalarAbs(b_A[3 + r2].re) + muDoubleScalarAbs(b_A[3 + r2].im)) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  A_re = b_A[3 + r3].re;
  A_im = b_A[3 + r3].im;
  maxval = b_A[3 + r2].re;
  a21 = b_A[3 + r2].im;
  if (a21 == 0.0) {
    if (A_im == 0.0) {
      b_A[3 + r3].re = A_re / maxval;
      b_A[3 + r3].im = 0.0;
    } else if (A_re == 0.0) {
      b_A[3 + r3].re = 0.0;
      b_A[3 + r3].im = A_im / maxval;
    } else {
      b_A[3 + r3].re = A_re / maxval;
      b_A[3 + r3].im = A_im / maxval;
    }
  } else if (maxval == 0.0) {
    if (A_re == 0.0) {
      b_A[3 + r3].re = A_im / a21;
      b_A[3 + r3].im = 0.0;
    } else if (A_im == 0.0) {
      b_A[3 + r3].re = 0.0;
      b_A[3 + r3].im = -(A_re / a21);
    } else {
      b_A[3 + r3].re = A_im / a21;
      b_A[3 + r3].im = -(A_re / a21);
    }
  } else {
    brm = muDoubleScalarAbs(maxval);
    bim = muDoubleScalarAbs(a21);
    if (brm > bim) {
      bim = a21 / maxval;
      a21 = maxval + bim * a21;
      b_A[3 + r3].re = (A_re + bim * A_im) / a21;
      b_A[3 + r3].im = (A_im - bim * A_re) / a21;
    } else if (bim == brm) {
      if (maxval > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      if (a21 > 0.0) {
        maxval = 0.5;
      } else {
        maxval = -0.5;
      }

      b_A[3 + r3].re = (A_re * bim + A_im * maxval) / brm;
      b_A[3 + r3].im = (A_im * bim - A_re * maxval) / brm;
    } else {
      bim = maxval / a21;
      a21 += bim * maxval;
      b_A[3 + r3].re = (bim * A_re + A_im) / a21;
      b_A[3 + r3].im = (bim * A_im - A_re) / a21;
    }
  }

  A_im = b_A[3 + r3].re * b_A[6 + r2].im + b_A[3 + r3].im * b_A[6 + r2].re;
  b_A[6 + r3].re -= b_A[3 + r3].re * b_A[6 + r2].re - b_A[3 + r3].im * b_A[6 +
    r2].im;
  b_A[6 + r3].im -= A_im;
  if (((b_A[r1].re == 0.0) && (b_A[r1].im == 0.0)) || ((b_A[3 + r2].re == 0.0) &&
       (b_A[3 + r2].im == 0.0)) || ((b_A[6 + r3].re == 0.0) && (b_A[6 + r3].im ==
        0.0))) {
    d_st.site = &og_emlrtRSI;
    e_st.site = &pg_emlrtRSI;
    warning(&e_st);
  }

  Y[1].re = B[r2] - (B[r1] * b_A[r2].re - 0.0 * b_A[r2].im);
  Y[1].im = 0.0 - (B[r1] * b_A[r2].im + 0.0 * b_A[r2].re);
  Y[2].re = (B[r3] - (B[r1] * b_A[r3].re - 0.0 * b_A[r3].im)) - (Y[1].re * b_A[3
    + r3].re - Y[1].im * b_A[3 + r3].im);
  Y[2].im = (0.0 - (B[r1] * b_A[r3].im + 0.0 * b_A[r3].re)) - (Y[1].re * b_A[3 +
    r3].im + Y[1].im * b_A[3 + r3].re);
  A_re = Y[2].re;
  maxval = b_A[6 + r3].re;
  a21 = b_A[6 + r3].im;
  if (a21 == 0.0) {
    if (Y[2].im == 0.0) {
      Y[2].re /= maxval;
      Y[2].im = 0.0;
    } else if (Y[2].re == 0.0) {
      Y[2].re = 0.0;
      Y[2].im /= maxval;
    } else {
      Y[2].re /= maxval;
      Y[2].im /= maxval;
    }
  } else if (maxval == 0.0) {
    if (Y[2].re == 0.0) {
      Y[2].re = Y[2].im / a21;
      Y[2].im = 0.0;
    } else if (Y[2].im == 0.0) {
      Y[2].re = 0.0;
      Y[2].im = -(A_re / a21);
    } else {
      Y[2].re = Y[2].im / a21;
      Y[2].im = -(A_re / a21);
    }
  } else {
    brm = muDoubleScalarAbs(maxval);
    bim = muDoubleScalarAbs(a21);
    if (brm > bim) {
      bim = a21 / maxval;
      a21 = maxval + bim * a21;
      Y[2].re = (Y[2].re + bim * Y[2].im) / a21;
      Y[2].im = (Y[2].im - bim * A_re) / a21;
    } else if (bim == brm) {
      if (maxval > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      if (a21 > 0.0) {
        maxval = 0.5;
      } else {
        maxval = -0.5;
      }

      Y[2].re = (Y[2].re * bim + Y[2].im * maxval) / brm;
      Y[2].im = (Y[2].im * bim - A_re * maxval) / brm;
    } else {
      bim = maxval / a21;
      a21 += bim * maxval;
      maxval = bim * Y[2].im - Y[2].re;
      Y[2].re = (bim * Y[2].re + Y[2].im) / a21;
      Y[2].im = maxval / a21;
    }
  }

  Y[0].re = B[r1] - (Y[2].re * b_A[6 + r1].re - Y[2].im * b_A[6 + r1].im);
  Y[0].im = 0.0 - (Y[2].re * b_A[6 + r1].im + Y[2].im * b_A[6 + r1].re);
  Y[1].re -= Y[2].re * b_A[6 + r2].re - Y[2].im * b_A[6 + r2].im;
  Y[1].im = (0.0 - (B[r1] * b_A[r2].im + 0.0 * b_A[r2].re)) - (Y[2].re * b_A[6 +
    r2].im + Y[2].im * b_A[6 + r2].re);
  A_re = Y[1].re;
  maxval = b_A[3 + r2].re;
  a21 = b_A[3 + r2].im;
  if (a21 == 0.0) {
    if (Y[1].im == 0.0) {
      Y[1].re /= maxval;
      Y[1].im = 0.0;
    } else if (Y[1].re == 0.0) {
      Y[1].re = 0.0;
      Y[1].im /= maxval;
    } else {
      Y[1].re /= maxval;
      Y[1].im /= maxval;
    }
  } else if (maxval == 0.0) {
    if (Y[1].re == 0.0) {
      Y[1].re = Y[1].im / a21;
      Y[1].im = 0.0;
    } else if (Y[1].im == 0.0) {
      Y[1].re = 0.0;
      Y[1].im = -(A_re / a21);
    } else {
      Y[1].re = Y[1].im / a21;
      Y[1].im = -(A_re / a21);
    }
  } else {
    brm = muDoubleScalarAbs(maxval);
    bim = muDoubleScalarAbs(a21);
    if (brm > bim) {
      bim = a21 / maxval;
      a21 = maxval + bim * a21;
      Y[1].re = (Y[1].re + bim * Y[1].im) / a21;
      Y[1].im = (Y[1].im - bim * A_re) / a21;
    } else if (bim == brm) {
      if (maxval > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      if (a21 > 0.0) {
        maxval = 0.5;
      } else {
        maxval = -0.5;
      }

      Y[1].re = (Y[1].re * bim + Y[1].im * maxval) / brm;
      Y[1].im = (Y[1].im * bim - A_re * maxval) / brm;
    } else {
      bim = maxval / a21;
      a21 += bim * maxval;
      maxval = bim * Y[1].im - Y[1].re;
      Y[1].re = (bim * Y[1].re + Y[1].im) / a21;
      Y[1].im = maxval / a21;
    }
  }

  Y[0].re -= Y[1].re * b_A[3 + r1].re - Y[1].im * b_A[3 + r1].im;
  Y[0].im -= Y[1].re * b_A[3 + r1].im + Y[1].im * b_A[3 + r1].re;
  A_re = Y[0].re;
  if (b_A[r1].im == 0.0) {
    if (Y[0].im == 0.0) {
      Y[0].re /= b_A[r1].re;
      Y[0].im = 0.0;
    } else if (Y[0].re == 0.0) {
      Y[0].re = 0.0;
      Y[0].im /= b_A[r1].re;
    } else {
      Y[0].re /= b_A[r1].re;
      Y[0].im /= b_A[r1].re;
    }
  } else if (b_A[r1].re == 0.0) {
    if (Y[0].re == 0.0) {
      Y[0].re = Y[0].im / b_A[r1].im;
      Y[0].im = 0.0;
    } else if (Y[0].im == 0.0) {
      Y[0].re = 0.0;
      Y[0].im = -(A_re / b_A[r1].im);
    } else {
      Y[0].re = Y[0].im / b_A[r1].im;
      Y[0].im = -(A_re / b_A[r1].im);
    }
  } else {
    brm = muDoubleScalarAbs(b_A[r1].re);
    bim = muDoubleScalarAbs(b_A[r1].im);
    if (brm > bim) {
      bim = b_A[r1].im / b_A[r1].re;
      a21 = b_A[r1].re + bim * b_A[r1].im;
      Y[0].re = (Y[0].re + bim * Y[0].im) / a21;
      Y[0].im = (Y[0].im - bim * A_re) / a21;
    } else if (bim == brm) {
      if (b_A[r1].re > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      if (b_A[r1].im > 0.0) {
        maxval = 0.5;
      } else {
        maxval = -0.5;
      }

      Y[0].re = (Y[0].re * bim + Y[0].im * maxval) / brm;
      Y[0].im = (Y[0].im * bim - A_re * maxval) / brm;
    } else {
      bim = b_A[r1].re / b_A[r1].im;
      a21 = b_A[r1].im + bim * b_A[r1].re;
      maxval = bim * Y[0].im - Y[0].re;
      Y[0].re = (bim * Y[0].re + Y[0].im) / a21;
      Y[0].im = maxval / a21;
    }
  }
}

/* End of code generation (mldivide.c) */
