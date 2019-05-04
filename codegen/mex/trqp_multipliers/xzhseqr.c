/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzhseqr.c
 *
 * Code generation for function 'xzhseqr'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "xzhseqr.h"
#include "xscal.h"
#include "xzlarfg.h"
#include "sqrt.h"

/* Variable Definitions */
static emlrtRSInfo mg_emlrtRSI = { 73, /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

static emlrtRSInfo ng_emlrtRSI = { 78, /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

static emlrtRSInfo og_emlrtRSI = { 84, /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

static emlrtRSInfo qg_emlrtRSI = { 265,/* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

static emlrtRSInfo ug_emlrtRSI = { 310,/* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

static emlrtRSInfo vg_emlrtRSI = { 316,/* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

static emlrtRSInfo wg_emlrtRSI = { 322,/* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

/* Function Definitions */
int32_T eml_zlahqr(const emlrtStack *sp, creal_T h[36], creal_T z[36])
{
  int32_T info;
  int32_T i;
  int32_T c;
  boolean_T exitg1;
  real_T htmp2;
  real_T tst;
  int32_T L;
  real_T t_re;
  boolean_T goto140;
  int32_T its;
  creal_T sc;
  boolean_T exitg2;
  real_T aa;
  int32_T k;
  real_T ba;
  boolean_T exitg3;
  int32_T tst_tmp;
  real_T bb;
  real_T t_im;
  boolean_T goto70;
  creal_T x2;
  int32_T m;
  real_T u_re;
  real_T u_im;
  real_T s;
  int32_T b_k;
  creal_T v[2];
  int32_T i4;
  int32_T sc_re_tmp;
  int32_T i5;
  int32_T b;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  info = 0;
  h[2].re = 0.0;
  h[2].im = 0.0;
  h[3].re = 0.0;
  h[3].im = 0.0;
  h[9].re = 0.0;
  h[9].im = 0.0;
  h[10].re = 0.0;
  h[10].im = 0.0;
  h[16].re = 0.0;
  h[16].im = 0.0;
  h[17].re = 0.0;
  h[17].im = 0.0;
  h[23].re = 0.0;
  h[23].im = 0.0;
  for (i = 0; i < 5; i++) {
    c = (i + 6 * i) + 1;
    if (h[c].im != 0.0) {
      htmp2 = h[(i + 6 * i) + 1].re;
      tst = h[(i + 6 * i) + 1].im;
      t_re = muDoubleScalarAbs(h[(i + 6 * i) + 1].re) + muDoubleScalarAbs(h[(i +
        6 * i) + 1].im);
      if (tst == 0.0) {
        sc.re = htmp2 / t_re;
        sc.im = 0.0;
      } else if (htmp2 == 0.0) {
        sc.re = 0.0;
        sc.im = tst / t_re;
      } else {
        sc.re = htmp2 / t_re;
        sc.im = tst / t_re;
      }

      aa = sc.re;
      ba = -sc.im;
      tst = sc.re;
      htmp2 = sc.im;
      t_re = muDoubleScalarHypot(tst, htmp2);
      if (ba == 0.0) {
        sc.re = aa / t_re;
        sc.im = 0.0;
      } else if (aa == 0.0) {
        sc.re = 0.0;
        sc.im = ba / t_re;
      } else {
        sc.re = aa / t_re;
        sc.im = ba / t_re;
      }

      h[c].re = muDoubleScalarHypot(h[c].re, h[(i + 6 * i) + 1].im);
      h[c].im = 0.0;
      st.site = &mg_emlrtRSI;
      c_xscal(&st, 5 - i, sc, h, (i + (i + 1) * 6) + 2);
      c = i + 3;
      x2.re = sc.re;
      x2.im = -sc.im;
      st.site = &ng_emlrtRSI;
      b_xscal(&st, muIntScalarMin_sint32(6, c), x2, h, 1 + (i + 1) * 6);
      x2.re = sc.re;
      x2.im = -sc.im;
      st.site = &og_emlrtRSI;
      d_xscal(&st, x2, z, 1 + (i + 1) * 6);
    }
  }

  i = 5;
  exitg1 = false;
  while ((!exitg1) && (i + 1 >= 1)) {
    L = -1;
    goto140 = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      k = i;
      exitg3 = false;
      while ((!exitg3) && (k + 1 > L + 2)) {
        c = k + 6 * (k - 1);
        htmp2 = muDoubleScalarAbs(h[c].re);
        ba = htmp2 + muDoubleScalarAbs(h[k + 6 * (k - 1)].im);
        if (ba <= 6.0125050800269183E-292) {
          exitg3 = true;
        } else {
          tst_tmp = k + 6 * k;
          bb = muDoubleScalarAbs(h[tst_tmp].re) + muDoubleScalarAbs(h[k + 6 * k]
            .im);
          tst = (muDoubleScalarAbs(h[c - 1].re) + muDoubleScalarAbs(h[(k + 6 *
                   (k - 1)) - 1].im)) + bb;
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = muDoubleScalarAbs(h[(k + 6 * (k - 2)) - 1].re);
            }

            if (k + 2 <= 6) {
              tst += muDoubleScalarAbs(h[tst_tmp + 1].re);
            }
          }

          if (htmp2 <= 2.2204460492503131E-16 * tst) {
            htmp2 = muDoubleScalarAbs(h[tst_tmp - 1].re) + muDoubleScalarAbs(h
              [(k + 6 * k) - 1].im);
            if (ba > htmp2) {
              tst = ba;
              ba = htmp2;
            } else {
              tst = htmp2;
            }

            htmp2 = muDoubleScalarAbs(h[(k + 6 * (k - 1)) - 1].re - h[k + 6 * k]
              .re) + muDoubleScalarAbs(h[(k + 6 * (k - 1)) - 1].im - h[k + 6 * k]
              .im);
            if (bb > htmp2) {
              aa = bb;
              bb = htmp2;
            } else {
              aa = htmp2;
            }

            s = aa + tst;
            if (ba * (tst / s) <= muDoubleScalarMax(6.0125050800269183E-292,
                 2.2204460492503131E-16 * (bb * (aa / s)))) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }
      }

      L = k - 1;
      if (k + 1 > 1) {
        h[k + 6 * (k - 1)].re = 0.0;
        h[k + 6 * (k - 1)].im = 0.0;
      }

      if (k + 1 >= i + 1) {
        goto140 = true;
        exitg2 = true;
      } else {
        if (its == 10) {
          t_re = 0.75 * muDoubleScalarAbs(h[(k + 6 * k) + 1].re) + h[k + 6 * k].
            re;
          t_im = h[k + 6 * k].im;
        } else if (its == 20) {
          t_re = 0.75 * muDoubleScalarAbs(h[i + 6 * (i - 1)].re) + h[i + 6 * i].
            re;
          t_im = h[i + 6 * i].im;
        } else {
          c = i + 6 * i;
          t_re = h[c].re;
          t_im = h[i + 6 * i].im;
          x2 = h[c - 1];
          c_sqrt(&x2);
          sc = h[i + 6 * (i - 1)];
          c_sqrt(&sc);
          u_re = x2.re * sc.re - x2.im * sc.im;
          u_im = x2.re * sc.im + x2.im * sc.re;
          s = muDoubleScalarAbs(u_re) + muDoubleScalarAbs(u_im);
          if (s != 0.0) {
            t_re = 0.5 * (h[(i + 6 * (i - 1)) - 1].re - h[c].re);
            t_im = 0.5 * (h[(i + 6 * (i - 1)) - 1].im - h[i + 6 * i].im);
            bb = muDoubleScalarAbs(t_re) + muDoubleScalarAbs(t_im);
            s = muDoubleScalarMax(s, bb);
            if (t_im == 0.0) {
              x2.re = t_re / s;
              x2.im = 0.0;
            } else if (t_re == 0.0) {
              x2.re = 0.0;
              x2.im = t_im / s;
            } else {
              x2.re = t_re / s;
              x2.im = t_im / s;
            }

            tst = x2.re;
            htmp2 = x2.im;
            aa = x2.re;
            ba = x2.im;
            x2.re = tst * aa - htmp2 * ba;
            x2.im = tst * ba + htmp2 * aa;
            if (u_im == 0.0) {
              sc.re = u_re / s;
              sc.im = 0.0;
            } else if (u_re == 0.0) {
              sc.re = 0.0;
              sc.im = u_im / s;
            } else {
              sc.re = u_re / s;
              sc.im = u_im / s;
            }

            aa = sc.re;
            ba = sc.im;
            tst = sc.re;
            htmp2 = sc.im;
            x2.re += aa * tst - ba * htmp2;
            x2.im += aa * htmp2 + ba * tst;
            c_sqrt(&x2);
            sc.re = s * x2.re;
            sc.im = s * x2.im;
            if (bb > 0.0) {
              if (t_im == 0.0) {
                x2.re = t_re / bb;
                x2.im = 0.0;
              } else if (t_re == 0.0) {
                x2.re = 0.0;
                x2.im = t_im / bb;
              } else {
                x2.re = t_re / bb;
                x2.im = t_im / bb;
              }

              if (x2.re * sc.re + x2.im * sc.im < 0.0) {
                sc.re = -sc.re;
                sc.im = -sc.im;
              }
            }

            t_re += sc.re;
            aa = t_im + sc.im;
            if (aa == 0.0) {
              if (u_im == 0.0) {
                bb = u_re / t_re;
                tst = 0.0;
              } else if (u_re == 0.0) {
                bb = 0.0;
                tst = u_im / t_re;
              } else {
                bb = u_re / t_re;
                tst = u_im / t_re;
              }
            } else if (t_re == 0.0) {
              if (u_re == 0.0) {
                bb = u_im / aa;
                tst = 0.0;
              } else if (u_im == 0.0) {
                bb = 0.0;
                tst = -(u_re / aa);
              } else {
                bb = u_im / aa;
                tst = -(u_re / aa);
              }
            } else {
              ba = muDoubleScalarAbs(t_re);
              tst = muDoubleScalarAbs(aa);
              if (ba > tst) {
                s = aa / t_re;
                tst = t_re + s * aa;
                bb = (u_re + s * u_im) / tst;
                tst = (u_im - s * u_re) / tst;
              } else if (tst == ba) {
                if (t_re > 0.0) {
                  htmp2 = 0.5;
                } else {
                  htmp2 = -0.5;
                }

                if (aa > 0.0) {
                  tst = 0.5;
                } else {
                  tst = -0.5;
                }

                bb = (u_re * htmp2 + u_im * tst) / ba;
                tst = (u_im * htmp2 - u_re * tst) / ba;
              } else {
                s = t_re / aa;
                tst = aa + s * t_re;
                bb = (s * u_re + u_im) / tst;
                tst = (s * u_im - u_re) / tst;
              }
            }

            t_re = h[i + 6 * i].re - (u_re * bb - u_im * tst);
            t_im = h[i + 6 * i].im - (u_re * tst + u_im * bb);
          }
        }

        goto70 = false;
        m = i;
        exitg3 = false;
        while ((!exitg3) && (m > k + 1)) {
          c = m + 6 * (m - 1);
          tst_tmp = c - 1;
          sc.re = h[tst_tmp].re - t_re;
          sc.im = h[(m + 6 * (m - 1)) - 1].im - t_im;
          tst = h[c].re;
          s = (muDoubleScalarAbs(sc.re) + muDoubleScalarAbs(sc.im)) +
            muDoubleScalarAbs(tst);
          aa = sc.re;
          ba = sc.im;
          if (ba == 0.0) {
            sc.re = aa / s;
            sc.im = 0.0;
          } else if (aa == 0.0) {
            sc.re = 0.0;
            sc.im = ba / s;
          } else {
            sc.re = aa / s;
            sc.im = ba / s;
          }

          tst /= s;
          v[0] = sc;
          v[1].re = tst;
          v[1].im = 0.0;
          if (muDoubleScalarAbs(h[(m + 6 * (m - 2)) - 1].re) * muDoubleScalarAbs
              (tst) <= 2.2204460492503131E-16 * ((muDoubleScalarAbs(sc.re) +
                muDoubleScalarAbs(sc.im)) * ((muDoubleScalarAbs(h[tst_tmp].re) +
                 muDoubleScalarAbs(h[(m + 6 * (m - 1)) - 1].im)) +
                (muDoubleScalarAbs(h[m + 6 * m].re) + muDoubleScalarAbs(h[m + 6 *
                  m].im))))) {
            goto70 = true;
            exitg3 = true;
          } else {
            m--;
          }
        }

        if (!goto70) {
          sc.re = h[k + 6 * k].re - t_re;
          sc.im = h[k + 6 * k].im - t_im;
          tst = h[(k + 6 * k) + 1].re;
          s = (muDoubleScalarAbs(sc.re) + muDoubleScalarAbs(sc.im)) +
            muDoubleScalarAbs(tst);
          if (sc.im == 0.0) {
            v[0].re = sc.re / s;
            v[0].im = 0.0;
          } else if (sc.re == 0.0) {
            v[0].re = 0.0;
            v[0].im = sc.im / s;
          } else {
            v[0].re = sc.re / s;
            v[0].im = sc.im / s;
          }

          tst /= s;
          v[1].re = tst;
          v[1].im = 0.0;
        }

        for (b_k = m; b_k <= i; b_k++) {
          if (b_k > m) {
            c = b_k + 6 * (b_k - 2);
            v[0] = h[c - 1];
            v[1] = h[c];
          }

          st.site = &qg_emlrtRSI;
          sc = b_xzlarfg(&st, &v[0], &v[1]);
          if (b_k > m) {
            h[(b_k + 6 * (b_k - 2)) - 1] = v[0];
            h[b_k + 6 * (b_k - 2)].re = 0.0;
            h[b_k + 6 * (b_k - 2)].im = 0.0;
          }

          t_re = v[1].re;
          t_im = v[1].im;
          aa = sc.re * v[1].re - sc.im * v[1].im;
          for (tst_tmp = b_k; tst_tmp < 7; tst_tmp++) {
            sc_re_tmp = b_k + 6 * (tst_tmp - 1);
            c = sc_re_tmp - 1;
            x2.re = (sc.re * h[c].re - -sc.im * h[(b_k + 6 * (tst_tmp - 1)) - 1]
                     .im) + aa * h[sc_re_tmp].re;
            x2.im = (sc.re * h[(b_k + 6 * (tst_tmp - 1)) - 1].im + -sc.im * h
                     [(b_k + 6 * (tst_tmp - 1)) - 1].re) + aa * h[b_k + 6 *
              (tst_tmp - 1)].im;
            h[c].re = h[(b_k + 6 * (tst_tmp - 1)) - 1].re - x2.re;
            h[c].im = h[(b_k + 6 * (tst_tmp - 1)) - 1].im - x2.im;
            h[sc_re_tmp].re = h[b_k + 6 * (tst_tmp - 1)].re - (x2.re * t_re -
              x2.im * t_im);
            h[sc_re_tmp].im = h[b_k + 6 * (tst_tmp - 1)].im - (x2.re * t_im +
              x2.im * t_re);
          }

          i4 = b_k + 2;
          i5 = i + 1;
          b = muIntScalarMin_sint32(i4, i5);
          for (tst_tmp = 0; tst_tmp < b; tst_tmp++) {
            sc_re_tmp = tst_tmp + 6 * (b_k - 1);
            c = tst_tmp + 6 * b_k;
            x2.re = (sc.re * h[sc_re_tmp].re - sc.im * h[tst_tmp + 6 * (b_k - 1)]
                     .im) + aa * h[c].re;
            x2.im = (sc.re * h[tst_tmp + 6 * (b_k - 1)].im + sc.im * h[tst_tmp +
                     6 * (b_k - 1)].re) + aa * h[tst_tmp + 6 * b_k].im;
            h[sc_re_tmp].re = h[tst_tmp + 6 * (b_k - 1)].re - x2.re;
            h[sc_re_tmp].im = h[tst_tmp + 6 * (b_k - 1)].im - x2.im;
            h[c].re = h[tst_tmp + 6 * b_k].re - (x2.re * t_re - x2.im * -t_im);
            h[c].im = h[tst_tmp + 6 * b_k].im - (x2.re * -t_im + x2.im * t_re);
          }

          for (tst_tmp = 0; tst_tmp < 6; tst_tmp++) {
            sc_re_tmp = tst_tmp + 6 * (b_k - 1);
            c = tst_tmp + 6 * b_k;
            x2.re = (sc.re * z[sc_re_tmp].re - sc.im * z[tst_tmp + 6 * (b_k - 1)]
                     .im) + aa * z[c].re;
            x2.im = (sc.re * z[tst_tmp + 6 * (b_k - 1)].im + sc.im * z[tst_tmp +
                     6 * (b_k - 1)].re) + aa * z[tst_tmp + 6 * b_k].im;
            z[sc_re_tmp].re = z[tst_tmp + 6 * (b_k - 1)].re - x2.re;
            z[sc_re_tmp].im = z[tst_tmp + 6 * (b_k - 1)].im - x2.im;
            z[c].re = z[tst_tmp + 6 * b_k].re - (x2.re * t_re - x2.im * -t_im);
            z[c].im = z[tst_tmp + 6 * b_k].im - (x2.re * -t_im + x2.im * t_re);
          }

          if ((b_k == m) && (m > k + 1)) {
            sc.re = 1.0 - sc.re;
            sc.im = 0.0 - sc.im;
            aa = sc.re;
            ba = sc.im;
            tst = sc.re;
            htmp2 = sc.im;
            t_re = muDoubleScalarHypot(tst, htmp2);
            if (ba == 0.0) {
              sc.re = aa / t_re;
              sc.im = 0.0;
            } else if (aa == 0.0) {
              sc.re = 0.0;
              sc.im = ba / t_re;
            } else {
              sc.re = aa / t_re;
              sc.im = ba / t_re;
            }

            htmp2 = h[m + 6 * (m - 1)].re;
            tst = h[m + 6 * (m - 1)].im;
            h[m + 6 * (m - 1)].re = htmp2 * sc.re - tst * -sc.im;
            h[m + 6 * (m - 1)].im = htmp2 * -sc.im + tst * sc.re;
            if (m + 2 <= i + 1) {
              c = (m + 6 * m) + 1;
              htmp2 = h[c].re;
              tst = h[(m + 6 * m) + 1].im;
              h[c].re = htmp2 * sc.re - tst * sc.im;
              h[c].im = htmp2 * sc.im + tst * sc.re;
            }

            for (tst_tmp = m; tst_tmp <= i + 1; tst_tmp++) {
              if (tst_tmp != m + 1) {
                if (6 > tst_tmp) {
                  st.site = &ug_emlrtRSI;
                  c_xscal(&st, 6 - tst_tmp, sc, h, tst_tmp + tst_tmp * 6);
                }

                x2.re = sc.re;
                x2.im = -sc.im;
                st.site = &vg_emlrtRSI;
                b_xscal(&st, tst_tmp - 1, x2, h, 1 + (tst_tmp - 1) * 6);
                x2.re = sc.re;
                x2.im = -sc.im;
                st.site = &wg_emlrtRSI;
                d_xscal(&st, x2, z, 1 + (tst_tmp - 1) * 6);
              }
            }
          }
        }

        x2 = h[i + 6 * (i - 1)];
        if (h[i + 6 * (i - 1)].im != 0.0) {
          htmp2 = muDoubleScalarHypot(h[i + 6 * (i - 1)].re, h[i + 6 * (i - 1)].
            im);
          h[i + 6 * (i - 1)].re = htmp2;
          h[i + 6 * (i - 1)].im = 0.0;
          if (x2.im == 0.0) {
            sc.re = x2.re / htmp2;
            sc.im = 0.0;
          } else if (x2.re == 0.0) {
            sc.re = 0.0;
            sc.im = x2.im / htmp2;
          } else {
            sc.re = x2.re / htmp2;
            sc.im = x2.im / htmp2;
          }

          if (6 > i + 1) {
            c = (i + (i + 1) * 6) + 1;
            t_re = sc.re;
            t_im = -sc.im;
            b = c + 6 * (4 - i);
            for (k = c; k <= b; k += 6) {
              htmp2 = h[k - 1].re;
              tst = h[k - 1].im;
              h[k - 1].re = t_re * htmp2 - t_im * tst;
              h[k - 1].im = t_re * tst + t_im * htmp2;
            }
          }

          c = i * 6 + 1;
          b = i * 6 + i;
          for (k = c; k <= b; k++) {
            htmp2 = h[k - 1].re;
            tst = h[k - 1].im;
            h[k - 1].re = sc.re * htmp2 - sc.im * tst;
            h[k - 1].im = sc.re * tst + sc.im * htmp2;
          }

          b = i * 6 + 6;
          for (k = c; k <= b; k++) {
            htmp2 = z[k - 1].re;
            tst = z[k - 1].im;
            z[k - 1].re = sc.re * htmp2 - sc.im * tst;
            z[k - 1].im = sc.re * tst + sc.im * htmp2;
          }
        }

        its++;
      }
    }

    if (!goto140) {
      info = i + 1;
      exitg1 = true;
    } else {
      i = L;
    }
  }

  return info;
}

/* End of code generation (xzhseqr.c) */
