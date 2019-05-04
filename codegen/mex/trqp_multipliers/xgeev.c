/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgeev.c
 *
 * Code generation for function 'xgeev'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "xgeev.h"
#include "trqp_multipliers_data.h"
#include "lapacke.h"

/* Function Definitions */
void xgeev(const emlrtStack *sp, const creal_T A[36], int32_T *info, creal_T W[6],
           creal_T V[36])
{
  creal_T b_A[36];
  ptrdiff_t info_t;
  creal_T vl;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  memcpy(&b_A[0], &A[0], 36U * sizeof(creal_T));
  info_t = LAPACKE_zgeev(102, 'N', 'V', (ptrdiff_t)6, (lapack_complex_double *)
    &b_A[0], (ptrdiff_t)6, (lapack_complex_double *)&W[0],
    (lapack_complex_double *)&vl, (ptrdiff_t)1, (lapack_complex_double *)&V[0],
    (ptrdiff_t)6);
  *info = (int32_T)info_t;
  b_st.site = &mf_emlrtRSI;
  if (*info < 0) {
    if (*info == -1010) {
      emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI, "MATLAB:nomem",
        "MATLAB:nomem", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI,
        "Coder:toolbox:LAPACKCallErrorInfo", "Coder:toolbox:LAPACKCallErrorInfo",
        5, 4, 13, cv0, 12, *info);
    }
  }
}

/* End of code generation (xgeev.c) */
