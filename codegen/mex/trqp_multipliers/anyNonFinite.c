/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * anyNonFinite.c
 *
 * Code generation for function 'anyNonFinite'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "anyNonFinite.h"

/* Function Definitions */
boolean_T anyNonFinite(const creal_T x[36])
{
  boolean_T p;
  int32_T k;
  p = true;
  for (k = 0; k < 36; k++) {
    if (p && ((!muDoubleScalarIsInf(x[k].re)) && (!muDoubleScalarIsInf(x[k].im))
              && ((!muDoubleScalarIsNaN(x[k].re)) && (!muDoubleScalarIsNaN(x[k].
            im))))) {
      p = true;
    } else {
      p = false;
    }
  }

  return !p;
}

/* End of code generation (anyNonFinite.c) */
