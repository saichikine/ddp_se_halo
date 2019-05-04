/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdhseqr.c
 *
 * Code generation for function 'xdhseqr'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "xdhseqr.h"
#include "xdlanv2.h"
#include "xrot.h"
#include "xzlarfg.h"
#include "sqrt.h"

/* Variable Definitions */
static emlrtRSInfo ie_emlrtRSI = { 187,/* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 263,/* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

static emlrtRSInfo re_emlrtRSI = { 359,/* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

/* Function Definitions */
int32_T eml_dlahqr(const emlrtStack *sp, real_T h[36], real_T z[36])
{
  int32_T info;
  real_T v[3];
  int32_T i;
  boolean_T exitg1;
  int32_T L;
  boolean_T goto150;
  int32_T its;
  boolean_T exitg2;
  int32_T k;
  boolean_T exitg3;
  int32_T sum1_tmp;
  int32_T nr;
  real_T d1;
  int32_T ix;
  int32_T tst_tmp;
  real_T s;
  real_T tst;
  real_T htmp1;
  real_T ab;
  real_T ba;
  real_T aa;
  real_T rt2r;
  real_T rt1r;
  int32_T m;
  int32_T b_k;
  int32_T j;
  int32_T i2;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  info = 0;
  v[0] = 0.0;
  h[2] = 0.0;
  h[3] = 0.0;
  v[1] = 0.0;
  h[9] = 0.0;
  h[10] = 0.0;
  v[2] = 0.0;
  h[16] = 0.0;
  h[17] = 0.0;
  h[23] = 0.0;
  i = 5;
  exitg1 = false;
  while ((!exitg1) && (i + 1 >= 1)) {
    L = 1;
    goto150 = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      k = i;
      exitg3 = false;
      while ((!exitg3) && (k + 1 > L)) {
        sum1_tmp = k + 6 * (k - 1);
        d1 = muDoubleScalarAbs(h[sum1_tmp]);
        if (d1 <= 6.0125050800269183E-292) {
          exitg3 = true;
        } else {
          nr = k + 6 * k;
          tst_tmp = sum1_tmp - 1;
          tst = muDoubleScalarAbs(h[tst_tmp]) + muDoubleScalarAbs(h[nr]);
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = muDoubleScalarAbs(h[(k + 6 * (k - 2)) - 1]);
            }

            if (k + 2 <= 6) {
              tst += muDoubleScalarAbs(h[(k + 6 * k) + 1]);
            }
          }

          if (d1 <= 2.2204460492503131E-16 * tst) {
            htmp1 = muDoubleScalarAbs(h[sum1_tmp]);
            tst = muDoubleScalarAbs(h[nr - 1]);
            if (htmp1 > tst) {
              ab = htmp1;
              ba = tst;
            } else {
              ab = tst;
              ba = htmp1;
            }

            htmp1 = muDoubleScalarAbs(h[k + 6 * k]);
            tst = muDoubleScalarAbs(h[tst_tmp] - h[k + 6 * k]);
            if (htmp1 > tst) {
              aa = htmp1;
              htmp1 = tst;
            } else {
              aa = tst;
            }

            s = aa + ab;
            if (ba * (ab / s) <= muDoubleScalarMax(6.0125050800269183E-292,
                 2.2204460492503131E-16 * (htmp1 * (aa / s)))) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }
      }

      L = k + 1;
      if (k + 1 > 1) {
        h[k + 6 * (k - 1)] = 0.0;
      }

      if (k + 1 >= i) {
        goto150 = true;
        exitg2 = true;
      } else {
        if (its == 10) {
          s = muDoubleScalarAbs(h[(k + 6 * k) + 1]) + muDoubleScalarAbs(h[(k + 6
            * (k + 1)) + 2]);
          tst = 0.75 * s + h[k + 6 * k];
          ab = -0.4375 * s;
          htmp1 = s;
          aa = tst;
        } else if (its == 20) {
          s = muDoubleScalarAbs(h[i + 6 * (i - 1)]) + muDoubleScalarAbs(h[(i + 6
            * (i - 2)) - 1]);
          tst = 0.75 * s + h[i + 6 * i];
          ab = -0.4375 * s;
          htmp1 = s;
          aa = tst;
        } else {
          tst = h[(i + 6 * (i - 1)) - 1];
          htmp1 = h[i + 6 * (i - 1)];
          ab = h[(i + 6 * i) - 1];
          aa = h[i + 6 * i];
        }

        s = ((muDoubleScalarAbs(tst) + muDoubleScalarAbs(ab)) +
             muDoubleScalarAbs(htmp1)) + muDoubleScalarAbs(aa);
        if (s == 0.0) {
          rt1r = 0.0;
          tst = 0.0;
          rt2r = 0.0;
          htmp1 = 0.0;
        } else {
          tst /= s;
          htmp1 /= s;
          ab /= s;
          aa /= s;
          ba = (tst + aa) / 2.0;
          tst = (tst - ba) * (aa - ba) - ab * htmp1;
          htmp1 = muDoubleScalarAbs(tst);
          st.site = &ie_emlrtRSI;
          b_sqrt(&st, &htmp1);
          if (tst >= 0.0) {
            rt1r = ba * s;
            rt2r = rt1r;
            tst = htmp1 * s;
            htmp1 = -tst;
          } else {
            rt1r = ba + htmp1;
            rt2r = ba - htmp1;
            if (muDoubleScalarAbs(rt1r - aa) <= muDoubleScalarAbs(rt2r - aa)) {
              rt1r *= s;
              rt2r = rt1r;
            } else {
              rt2r *= s;
              rt1r = rt2r;
            }

            tst = 0.0;
            htmp1 = 0.0;
          }
        }

        m = i - 1;
        exitg3 = false;
        while ((!exitg3) && (m >= k + 1)) {
          nr = m + 6 * (m - 1);
          ab = h[nr - 1];
          ba = ab - rt2r;
          s = (muDoubleScalarAbs(ba) + muDoubleScalarAbs(htmp1)) +
            muDoubleScalarAbs(h[nr]);
          aa = h[m + 6 * (m - 1)] / s;
          nr = m + 6 * m;
          v[0] = (aa * h[nr - 1] + (ab - rt1r) * (ba / s)) - tst * (htmp1 / s);
          v[1] = aa * (((ab + h[nr]) - rt1r) - rt2r);
          v[2] = aa * h[nr + 1];
          s = (muDoubleScalarAbs(v[0]) + muDoubleScalarAbs(v[1])) +
            muDoubleScalarAbs(v[2]);
          v[0] /= s;
          v[1] /= s;
          v[2] /= s;
          if (m == k + 1) {
            exitg3 = true;
          } else {
            sum1_tmp = m + 6 * (m - 2);
            if (muDoubleScalarAbs(h[sum1_tmp - 1]) * (muDoubleScalarAbs(v[1]) +
                 muDoubleScalarAbs(v[2])) <= 2.2204460492503131E-16 *
                muDoubleScalarAbs(v[0]) * ((muDoubleScalarAbs(h[sum1_tmp - 2]) +
                  muDoubleScalarAbs(ab)) + muDoubleScalarAbs(h[m + 6 * m]))) {
              exitg3 = true;
            } else {
              m--;
            }
          }
        }

        for (b_k = m; b_k <= i; b_k++) {
          nr = (i - b_k) + 2;
          nr = muIntScalarMin_sint32(3, nr);
          if (b_k > m) {
            tst_tmp = (b_k + 6 * (b_k - 2)) - 1;
            for (j = 0; j < nr; j++) {
              v[j] = h[j + tst_tmp];
            }
          }

          tst = v[0];
          st.site = &le_emlrtRSI;
          aa = xzlarfg(&st, nr, &tst, v);
          v[0] = tst;
          if (b_k > m) {
            h[(b_k + 6 * (b_k - 2)) - 1] = tst;
            h[b_k + 6 * (b_k - 2)] = 0.0;
            if (b_k < i) {
              h[(b_k + 6 * (b_k - 2)) + 1] = 0.0;
            }
          } else {
            if (m > k + 1) {
              h[(b_k + 6 * (b_k - 2)) - 1] *= 1.0 - aa;
            }
          }

          d1 = v[1];
          tst = aa * v[1];
          if (nr == 3) {
            s = v[2];
            ba = aa * v[2];
            for (j = b_k; j < 7; j++) {
              nr = b_k + 6 * (j - 1);
              sum1_tmp = nr - 1;
              tst_tmp = nr + 1;
              ab = (h[sum1_tmp] + d1 * h[nr]) + s * h[tst_tmp];
              h[sum1_tmp] -= ab * aa;
              h[nr] -= ab * tst;
              h[tst_tmp] -= ab * ba;
            }

            nr = b_k + 3;
            i2 = i + 1;
            ix = muIntScalarMin_sint32(nr, i2);
            for (j = 0; j < ix; j++) {
              tst_tmp = j + 6 * (b_k - 1);
              htmp1 = h[tst_tmp];
              nr = j + 6 * b_k;
              sum1_tmp = j + 6 * (b_k + 1);
              ab = (htmp1 + d1 * h[nr]) + s * h[sum1_tmp];
              h[tst_tmp] = htmp1 - ab * aa;
              h[nr] -= ab * tst;
              h[sum1_tmp] -= ab * ba;
            }

            for (j = 0; j < 6; j++) {
              tst_tmp = j + 6 * (b_k - 1);
              htmp1 = z[tst_tmp];
              nr = j + 6 * b_k;
              sum1_tmp = j + 6 * (b_k + 1);
              ab = (htmp1 + d1 * z[nr]) + s * z[sum1_tmp];
              z[tst_tmp] = htmp1 - ab * aa;
              z[nr] -= ab * tst;
              z[sum1_tmp] -= ab * ba;
            }
          } else {
            if (nr == 2) {
              for (j = b_k; j < 7; j++) {
                nr = b_k + 6 * (j - 1);
                tst_tmp = nr - 1;
                htmp1 = h[tst_tmp];
                ab = htmp1 + d1 * h[nr];
                h[tst_tmp] = htmp1 - ab * aa;
                h[nr] -= ab * tst;
              }

              for (j = 0; j <= i; j++) {
                nr = j + 6 * (b_k - 1);
                sum1_tmp = j + 6 * b_k;
                ab = h[nr] + d1 * h[sum1_tmp];
                h[nr] -= ab * aa;
                h[sum1_tmp] -= ab * tst;
              }

              for (j = 0; j < 6; j++) {
                tst_tmp = j + 6 * (b_k - 1);
                htmp1 = z[tst_tmp];
                nr = j + 6 * b_k;
                ab = htmp1 + d1 * z[nr];
                z[tst_tmp] = htmp1 - ab * aa;
                z[nr] -= ab * tst;
              }
            }
          }
        }

        its++;
      }
    }

    if (!goto150) {
      info = i + 1;
      exitg1 = true;
    } else {
      if ((L != i + 1) && (L == i)) {
        sum1_tmp = i + 6 * i;
        nr = sum1_tmp - 1;
        d1 = h[nr];
        ix = 6 * (i - 1);
        tst_tmp = i + ix;
        s = h[tst_tmp];
        tst = h[sum1_tmp];
        xdlanv2(&h[(i + 6 * (i - 1)) - 1], &d1, &s, &tst, &htmp1, &ab, &ba, &aa,
                &rt2r, &rt1r);
        h[nr] = d1;
        h[tst_tmp] = s;
        h[sum1_tmp] = tst;
        if (6 > i + 1) {
          st.site = &re_emlrtRSI;
          xrot(&st, 5 - i, h, i + (i + 1) * 6, (i + (i + 1) * 6) + 1, rt2r, rt1r);
        }

        if (i - 1 >= 1) {
          nr = i * 6;
          for (k = 0; k <= i - 2; k++) {
            tst = rt2r * h[ix] + rt1r * h[nr];
            h[nr] = rt2r * h[nr] - rt1r * h[ix];
            h[ix] = tst;
            nr++;
            ix++;
          }
        }

        b_xrot(z, 1 + (i - 1) * 6, 1 + i * 6, rt2r, rt1r);
      }

      i = L - 2;
    }
  }

  return info;
}

/* End of code generation (xdhseqr.c) */
