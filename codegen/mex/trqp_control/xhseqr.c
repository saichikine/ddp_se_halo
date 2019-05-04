/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xhseqr.c
 *
 * Code generation for function 'xhseqr'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "xhseqr.h"
#include "xdlanv2.h"
#include "xrot.h"
#include "xzlarfg.h"
#include "sqrt.h"
#include "xscal.h"

/* Variable Definitions */
static emlrtRSInfo qd_emlrtRSI = { 21, /* lineNo */
  "xhseqr",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xhseqr.m"/* pathName */
};

static emlrtRSInfo rd_emlrtRSI = { 11, /* lineNo */
  "xdhseqr",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

static emlrtRSInfo sd_emlrtRSI = { 187,/* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 263,/* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

static emlrtRSInfo ce_emlrtRSI = { 359,/* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

static emlrtRSInfo yg_emlrtRSI = { 23, /* lineNo */
  "xhseqr",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xhseqr.m"/* pathName */
};

static emlrtRSInfo ah_emlrtRSI = { 15, /* lineNo */
  "xzhseqr",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

static emlrtRSInfo bh_emlrtRSI = { 73, /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

static emlrtRSInfo ch_emlrtRSI = { 78, /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

static emlrtRSInfo dh_emlrtRSI = { 84, /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

static emlrtRSInfo fh_emlrtRSI = { 265,/* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

static emlrtRSInfo jh_emlrtRSI = { 310,/* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

static emlrtRSInfo kh_emlrtRSI = { 316,/* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

static emlrtRSInfo lh_emlrtRSI = { 322,/* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

/* Function Definitions */
int32_T b_xhseqr(const emlrtStack *sp, creal_T h[9], creal_T z[9])
{
  int32_T info;
  real_T htmp2;
  real_T tst;
  real_T t_re;
  int32_T i;
  boolean_T exitg1;
  creal_T sc;
  int32_T L;
  real_T aa;
  boolean_T goto140;
  real_T ba;
  int32_T its;
  boolean_T exitg2;
  int32_T k;
  boolean_T exitg3;
  int32_T m;
  creal_T x2;
  int32_T tst_tmp;
  real_T bb;
  real_T t_im;
  boolean_T goto70;
  real_T u_re;
  real_T u_im;
  real_T s;
  creal_T v[2];
  int32_T j;
  int32_T sc_re_tmp;
  int32_T b_sc_re_tmp;
  int32_T x2_tmp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &ah_emlrtRSI;
  info = 0;
  h[2].re = 0.0;
  h[2].im = 0.0;
  if (h[1].im != 0.0) {
    htmp2 = h[1].re;
    tst = h[1].im;
    t_re = muDoubleScalarAbs(h[1].re) + muDoubleScalarAbs(h[1].im);
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
    htmp2 = muDoubleScalarHypot(tst, htmp2);
    if (ba == 0.0) {
      sc.re = aa / htmp2;
      sc.im = 0.0;
    } else if (aa == 0.0) {
      sc.re = 0.0;
      sc.im = ba / htmp2;
    } else {
      sc.re = aa / htmp2;
      sc.im = ba / htmp2;
    }

    h[1].re = muDoubleScalarHypot(h[1].re, h[1].im);
    h[1].im = 0.0;
    c_st.site = &bh_emlrtRSI;
    c_xscal(&c_st, 2, sc, h, 5);
    x2.re = sc.re;
    x2.im = -sc.im;
    c_st.site = &ch_emlrtRSI;
    b_xscal(&c_st, 3, x2, h, 4);
    x2.re = sc.re;
    x2.im = -sc.im;
    c_st.site = &dh_emlrtRSI;
    d_xscal(&c_st, x2, z, 4);
  }

  if (h[5].im != 0.0) {
    htmp2 = h[5].re;
    tst = h[5].im;
    t_re = muDoubleScalarAbs(h[5].re) + muDoubleScalarAbs(h[5].im);
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

    h[5].re = muDoubleScalarHypot(h[5].re, h[5].im);
    h[5].im = 0.0;
    c_st.site = &bh_emlrtRSI;
    c_xscal(&c_st, 1, sc, h, 9);
    x2.re = sc.re;
    x2.im = -sc.im;
    c_st.site = &ch_emlrtRSI;
    b_xscal(&c_st, 3, x2, h, 7);
    x2.re = sc.re;
    x2.im = -sc.im;
    c_st.site = &dh_emlrtRSI;
    d_xscal(&c_st, x2, z, 7);
  }

  i = 2;
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
        m = k + 3 * (k - 1);
        htmp2 = muDoubleScalarAbs(h[m].re);
        ba = htmp2 + muDoubleScalarAbs(h[k + 3 * (k - 1)].im);
        if (ba <= 3.0062525400134592E-292) {
          exitg3 = true;
        } else {
          tst_tmp = k + 3 * k;
          bb = muDoubleScalarAbs(h[tst_tmp].re) + muDoubleScalarAbs(h[k + 3 * k]
            .im);
          tst = (muDoubleScalarAbs(h[m - 1].re) + muDoubleScalarAbs(h[(k + 3 *
                   (k - 1)) - 1].im)) + bb;
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = muDoubleScalarAbs(h[(k + 3 * (k - 2)) - 1].re);
            }

            if (k + 2 <= 3) {
              tst += muDoubleScalarAbs(h[tst_tmp + 1].re);
            }
          }

          if (htmp2 <= 2.2204460492503131E-16 * tst) {
            htmp2 = muDoubleScalarAbs(h[tst_tmp - 1].re) + muDoubleScalarAbs(h
              [(k + 3 * k) - 1].im);
            if (ba > htmp2) {
              tst = ba;
              ba = htmp2;
            } else {
              tst = htmp2;
            }

            htmp2 = muDoubleScalarAbs(h[(k + 3 * (k - 1)) - 1].re - h[k + 3 * k]
              .re) + muDoubleScalarAbs(h[(k + 3 * (k - 1)) - 1].im - h[k + 3 * k]
              .im);
            if (bb > htmp2) {
              aa = bb;
              bb = htmp2;
            } else {
              aa = htmp2;
            }

            s = aa + tst;
            if (ba * (tst / s) <= muDoubleScalarMax(3.0062525400134592E-292,
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
        h[k + 3 * (k - 1)].re = 0.0;
        h[k + 3 * (k - 1)].im = 0.0;
      }

      if (k + 1 >= i + 1) {
        goto140 = true;
        exitg2 = true;
      } else {
        if (its == 10) {
          t_re = 0.75 * muDoubleScalarAbs(h[(k + 3 * k) + 1].re) + h[k + 3 * k].
            re;
          t_im = h[k + 3 * k].im;
        } else if (its == 20) {
          t_re = 0.75 * muDoubleScalarAbs(h[i + 3 * (i - 1)].re) + h[i + 3 * i].
            re;
          t_im = h[i + 3 * i].im;
        } else {
          m = i + 3 * i;
          t_re = h[m].re;
          t_im = h[i + 3 * i].im;
          x2 = h[m - 1];
          c_sqrt(&x2);
          sc = h[i + 3 * (i - 1)];
          c_sqrt(&sc);
          u_re = x2.re * sc.re - x2.im * sc.im;
          u_im = x2.re * sc.im + x2.im * sc.re;
          s = muDoubleScalarAbs(u_re) + muDoubleScalarAbs(u_im);
          if (s != 0.0) {
            t_re = 0.5 * (h[(i + 3 * (i - 1)) - 1].re - h[m].re);
            t_im = 0.5 * (h[(i + 3 * (i - 1)) - 1].im - h[i + 3 * i].im);
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

            t_re = h[i + 3 * i].re - (u_re * bb - u_im * tst);
            t_im = h[i + 3 * i].im - (u_re * tst + u_im * bb);
          }
        }

        goto70 = false;
        m = i;
        exitg3 = false;
        while ((!exitg3) && (m > k + 1)) {
          sc.re = h[4].re - t_re;
          sc.im = h[4].im - t_im;
          tst = h[5].re;
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
          if (muDoubleScalarAbs(h[1].re) * muDoubleScalarAbs(tst) <=
              2.2204460492503131E-16 * ((muDoubleScalarAbs(sc.re) +
                muDoubleScalarAbs(sc.im)) * ((muDoubleScalarAbs(h[4].re) +
                 muDoubleScalarAbs(h[4].im)) + (muDoubleScalarAbs(h[8].re) +
                 muDoubleScalarAbs(h[8].im))))) {
            goto70 = true;
            exitg3 = true;
          } else {
            m = 1;
          }
        }

        if (!goto70) {
          sc.re = h[k + 3 * k].re - t_re;
          sc.im = h[k + 3 * k].im - t_im;
          tst = h[(k + 3 * k) + 1].re;
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

        for (tst_tmp = m; tst_tmp <= i; tst_tmp++) {
          if (tst_tmp > m) {
            v[0] = h[1];
            v[1] = h[2];
          }

          c_st.site = &fh_emlrtRSI;
          sc = b_xzlarfg(&c_st, &v[0], &v[1]);
          if (tst_tmp > m) {
            h[1] = v[0];
            h[2].re = 0.0;
            h[2].im = 0.0;
          }

          t_re = v[1].re;
          t_im = v[1].im;
          aa = sc.re * v[1].re - sc.im * v[1].im;
          for (j = tst_tmp; j < 4; j++) {
            sc_re_tmp = tst_tmp + 3 * (j - 1);
            b_sc_re_tmp = sc_re_tmp - 1;
            x2.re = (sc.re * h[b_sc_re_tmp].re - -sc.im * h[(tst_tmp + 3 * (j -
                       1)) - 1].im) + aa * h[sc_re_tmp].re;
            x2.im = (sc.re * h[(tst_tmp + 3 * (j - 1)) - 1].im + -sc.im * h
                     [(tst_tmp + 3 * (j - 1)) - 1].re) + aa * h[tst_tmp + 3 * (j
              - 1)].im;
            h[b_sc_re_tmp].re = h[(tst_tmp + 3 * (j - 1)) - 1].re - x2.re;
            h[b_sc_re_tmp].im = h[(tst_tmp + 3 * (j - 1)) - 1].im - x2.im;
            h[sc_re_tmp].re = h[tst_tmp + 3 * (j - 1)].re - (x2.re * t_re -
              x2.im * t_im);
            h[sc_re_tmp].im = h[tst_tmp + 3 * (j - 1)].im - (x2.re * t_im +
              x2.im * t_re);
          }

          for (j = 0; j <= i; j++) {
            sc_re_tmp = j + 3 * (tst_tmp - 1);
            x2_tmp = j + 3 * tst_tmp;
            x2.re = (sc.re * h[sc_re_tmp].re - sc.im * h[j + 3 * (tst_tmp - 1)].
                     im) + aa * h[x2_tmp].re;
            x2.im = (sc.re * h[j + 3 * (tst_tmp - 1)].im + sc.im * h[j + 3 *
                     (tst_tmp - 1)].re) + aa * h[j + 3 * tst_tmp].im;
            h[sc_re_tmp].re = h[j + 3 * (tst_tmp - 1)].re - x2.re;
            h[sc_re_tmp].im = h[j + 3 * (tst_tmp - 1)].im - x2.im;
            h[x2_tmp].re = h[j + 3 * tst_tmp].re - (x2.re * t_re - x2.im * -t_im);
            h[x2_tmp].im = h[j + 3 * tst_tmp].im - (x2.re * -t_im + x2.im * t_re);
          }

          sc_re_tmp = 3 * (tst_tmp - 1);
          x2.re = (sc.re * z[sc_re_tmp].re - sc.im * z[3 * (tst_tmp - 1)].im) +
            aa * z[3 * tst_tmp].re;
          x2.im = (sc.re * z[3 * (tst_tmp - 1)].im + sc.im * z[3 * (tst_tmp - 1)]
                   .re) + aa * z[3 * tst_tmp].im;
          z[sc_re_tmp].re = z[3 * (tst_tmp - 1)].re - x2.re;
          z[sc_re_tmp].im = z[3 * (tst_tmp - 1)].im - x2.im;
          z[3 * tst_tmp].re -= x2.re * v[1].re - x2.im * -v[1].im;
          z[3 * tst_tmp].im -= x2.re * -v[1].im + x2.im * v[1].re;
          b_sc_re_tmp = 1 + sc_re_tmp;
          x2_tmp = 1 + 3 * tst_tmp;
          x2.re = (sc.re * z[b_sc_re_tmp].re - sc.im * z[1 + 3 * (tst_tmp - 1)].
                   im) + aa * z[x2_tmp].re;
          x2.im = (sc.re * z[1 + 3 * (tst_tmp - 1)].im + sc.im * z[1 + 3 *
                   (tst_tmp - 1)].re) + aa * z[1 + 3 * tst_tmp].im;
          z[b_sc_re_tmp].re = z[1 + 3 * (tst_tmp - 1)].re - x2.re;
          z[b_sc_re_tmp].im = z[1 + 3 * (tst_tmp - 1)].im - x2.im;
          z[x2_tmp].re = z[1 + 3 * tst_tmp].re - (x2.re * v[1].re - x2.im * -v[1]
            .im);
          z[x2_tmp].im = z[1 + 3 * tst_tmp].im - (x2.re * -v[1].im + x2.im * v[1]
            .re);
          sc_re_tmp += 2;
          x2_tmp = 2 + 3 * tst_tmp;
          x2.re = (sc.re * z[sc_re_tmp].re - sc.im * z[2 + 3 * (tst_tmp - 1)].im)
            + aa * z[x2_tmp].re;
          x2.im = (sc.re * z[2 + 3 * (tst_tmp - 1)].im + sc.im * z[2 + 3 *
                   (tst_tmp - 1)].re) + aa * z[2 + 3 * tst_tmp].im;
          z[sc_re_tmp].re = z[2 + 3 * (tst_tmp - 1)].re - x2.re;
          z[sc_re_tmp].im = z[2 + 3 * (tst_tmp - 1)].im - x2.im;
          z[x2_tmp].re = z[2 + 3 * tst_tmp].re - (x2.re * v[1].re - x2.im * -v[1]
            .im);
          z[x2_tmp].im = z[2 + 3 * tst_tmp].im - (x2.re * -v[1].im + x2.im * v[1]
            .re);
          if ((tst_tmp == m) && (m > k + 1)) {
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

            htmp2 = h[5].re;
            tst = h[5].im;
            h[5].re = htmp2 * sc.re - tst * -sc.im;
            h[5].im = htmp2 * -sc.im + tst * sc.re;
            for (j = 2; j <= i + 1; j++) {
              if (j != 3) {
                c_st.site = &jh_emlrtRSI;
                c_xscal(&c_st, 1, sc, h, 8);
                x2.re = sc.re;
                x2.im = -sc.im;
                c_st.site = &kh_emlrtRSI;
                b_xscal(&c_st, 1, x2, h, 4);
                x2.re = sc.re;
                x2.im = -sc.im;
                c_st.site = &lh_emlrtRSI;
                d_xscal(&c_st, x2, z, 4);
              }
            }
          }
        }

        x2 = h[i + 3 * (i - 1)];
        if (h[i + 3 * (i - 1)].im != 0.0) {
          htmp2 = muDoubleScalarHypot(h[i + 3 * (i - 1)].re, h[i + 3 * (i - 1)].
            im);
          h[i + 3 * (i - 1)].re = htmp2;
          h[i + 3 * (i - 1)].im = 0.0;
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

          if (3 > i + 1) {
            htmp2 = h[7].re;
            tst = h[7].im;
            h[7].re = sc.re * htmp2 - -sc.im * tst;
            h[7].im = sc.re * tst + -sc.im * htmp2;
          }

          m = i * 3 + 1;
          tst_tmp = i * 3 + i;
          for (k = m; k <= tst_tmp; k++) {
            htmp2 = h[k - 1].re;
            tst = h[k - 1].im;
            h[k - 1].re = sc.re * htmp2 - sc.im * tst;
            h[k - 1].im = sc.re * tst + sc.im * htmp2;
          }

          tst_tmp = i * 3 + 3;
          for (k = m; k <= tst_tmp; k++) {
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

int32_T xhseqr(const emlrtStack *sp, real_T h[9], real_T z[9])
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
  real_T h22;
  real_T rt1r;
  int32_T m;
  int32_T j;
  int32_T i1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &rd_emlrtRSI;
  info = 0;
  v[0] = 0.0;
  v[1] = 0.0;
  v[2] = 0.0;
  h[2] = 0.0;
  i = 2;
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
        sum1_tmp = k + 3 * (k - 1);
        d1 = muDoubleScalarAbs(h[sum1_tmp]);
        if (d1 <= 3.0062525400134592E-292) {
          exitg3 = true;
        } else {
          nr = k + 3 * k;
          tst_tmp = sum1_tmp - 1;
          tst = muDoubleScalarAbs(h[tst_tmp]) + muDoubleScalarAbs(h[nr]);
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = muDoubleScalarAbs(h[(k + 3 * (k - 2)) - 1]);
            }

            if (k + 2 <= 3) {
              tst += muDoubleScalarAbs(h[nr + 1]);
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

            htmp1 = muDoubleScalarAbs(h[nr]);
            tst = muDoubleScalarAbs(h[tst_tmp] - h[k + 3 * k]);
            if (htmp1 > tst) {
              aa = htmp1;
              htmp1 = tst;
            } else {
              aa = tst;
            }

            s = aa + ab;
            if (ba * (ab / s) <= muDoubleScalarMax(3.0062525400134592E-292,
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
        h[k + 3 * (k - 1)] = 0.0;
      }

      if (k + 1 >= i) {
        goto150 = true;
        exitg2 = true;
      } else {
        if (its == 10) {
          s = muDoubleScalarAbs(h[1]) + muDoubleScalarAbs(h[5]);
          tst = 0.75 * s + h[0];
          ab = -0.4375 * s;
          htmp1 = s;
          h22 = tst;
        } else if (its == 20) {
          s = muDoubleScalarAbs(h[i + 3 * (i - 1)]) + muDoubleScalarAbs(h[(i + 3
            * (i - 2)) - 1]);
          tst = 0.75 * s + h[i + 3 * i];
          ab = -0.4375 * s;
          htmp1 = s;
          h22 = tst;
        } else {
          tst = h[(i + 3 * (i - 1)) - 1];
          htmp1 = h[i + 3 * (i - 1)];
          ab = h[(i + 3 * i) - 1];
          h22 = h[i + 3 * i];
        }

        s = ((muDoubleScalarAbs(tst) + muDoubleScalarAbs(ab)) +
             muDoubleScalarAbs(htmp1)) + muDoubleScalarAbs(h22);
        if (s == 0.0) {
          rt1r = 0.0;
          tst = 0.0;
          aa = 0.0;
          htmp1 = 0.0;
        } else {
          tst /= s;
          htmp1 /= s;
          ab /= s;
          h22 /= s;
          ba = (tst + h22) / 2.0;
          tst = (tst - ba) * (h22 - ba) - ab * htmp1;
          htmp1 = muDoubleScalarAbs(tst);
          c_st.site = &sd_emlrtRSI;
          b_sqrt(&c_st, &htmp1);
          if (tst >= 0.0) {
            rt1r = ba * s;
            aa = rt1r;
            tst = htmp1 * s;
            htmp1 = -tst;
          } else {
            rt1r = ba + htmp1;
            aa = ba - htmp1;
            if (muDoubleScalarAbs(rt1r - h22) <= muDoubleScalarAbs(aa - h22)) {
              rt1r *= s;
              aa = rt1r;
            } else {
              aa *= s;
              rt1r = aa;
            }

            tst = 0.0;
            htmp1 = 0.0;
          }
        }

        m = i - 1;
        if (i - 1 >= 1) {
          ab = h[0] - aa;
          s = (muDoubleScalarAbs(ab) + muDoubleScalarAbs(htmp1)) +
            muDoubleScalarAbs(h[1]);
          ba = h[1] / s;
          v[0] = (ba * h[3] + (h[0] - rt1r) * (ab / s)) - tst * (htmp1 / s);
          v[1] = ba * (((h[0] + h[4]) - rt1r) - aa);
          v[2] = ba * h[5];
          s = (muDoubleScalarAbs(v[0]) + muDoubleScalarAbs(v[1])) +
            muDoubleScalarAbs(v[2]);
          v[0] /= s;
          v[1] /= s;
          v[2] /= s;
        }

        for (k = m; k <= i; k++) {
          nr = (i - k) + 2;
          nr = muIntScalarMin_sint32(3, nr);
          if (k > i - 1) {
            tst_tmp = (k + 3 * (k - 2)) - 1;
            for (j = 0; j < nr; j++) {
              v[j] = h[j + tst_tmp];
            }
          }

          tst = v[0];
          c_st.site = &vd_emlrtRSI;
          aa = xzlarfg(&c_st, nr, &tst, v);
          v[0] = tst;
          if (k > i - 1) {
            h[(k + 3 * (k - 2)) - 1] = tst;
            h[k + 3 * (k - 2)] = 0.0;
            if (k < i) {
              h[(k + 3 * (k - 2)) + 1] = 0.0;
            }
          }

          d1 = v[1];
          tst = aa * v[1];
          if (nr == 3) {
            s = v[2];
            ba = aa * v[2];
            for (j = k; j < 4; j++) {
              ix = k + 3 * (j - 1);
              sum1_tmp = ix - 1;
              tst_tmp = ix + 1;
              ab = (h[sum1_tmp] + d1 * h[ix]) + s * h[tst_tmp];
              h[sum1_tmp] -= ab * aa;
              h[ix] -= ab * tst;
              h[tst_tmp] -= ab * ba;
            }

            nr = k + 3;
            i1 = i + 1;
            nr = muIntScalarMin_sint32(nr, i1);
            for (j = 0; j < nr; j++) {
              tst_tmp = j + 3 * (k - 1);
              htmp1 = h[tst_tmp];
              ix = j + 3 * k;
              sum1_tmp = j + 3 * (k + 1);
              ab = (htmp1 + d1 * h[ix]) + s * h[sum1_tmp];
              h[tst_tmp] = htmp1 - ab * aa;
              h[ix] -= ab * tst;
              h[sum1_tmp] -= ab * ba;
            }

            for (j = 0; j < 3; j++) {
              tst_tmp = j + 3 * (k - 1);
              htmp1 = z[tst_tmp];
              ix = j + 3 * k;
              sum1_tmp = j + 3 * (k + 1);
              ab = (htmp1 + d1 * z[ix]) + s * z[sum1_tmp];
              z[tst_tmp] = htmp1 - ab * aa;
              z[ix] -= ab * tst;
              z[sum1_tmp] -= ab * ba;
            }
          } else {
            if (nr == 2) {
              for (j = k; j < 4; j++) {
                ix = k + 3 * (j - 1);
                tst_tmp = ix - 1;
                htmp1 = h[tst_tmp];
                ab = htmp1 + d1 * h[ix];
                h[tst_tmp] = htmp1 - ab * aa;
                h[ix] -= ab * tst;
              }

              for (j = 0; j <= i; j++) {
                ix = j + 3 * (k - 1);
                sum1_tmp = j + 3 * k;
                ab = h[ix] + d1 * h[sum1_tmp];
                h[ix] -= ab * aa;
                h[sum1_tmp] -= ab * tst;
              }

              for (j = 0; j < 3; j++) {
                tst_tmp = j + 3 * (k - 1);
                htmp1 = z[tst_tmp];
                ix = j + 3 * k;
                ab = htmp1 + d1 * z[ix];
                z[tst_tmp] = htmp1 - ab * aa;
                z[ix] -= ab * tst;
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
        sum1_tmp = i + 3 * i;
        nr = sum1_tmp - 1;
        d1 = h[nr];
        ix = 3 * (i - 1);
        tst_tmp = i + ix;
        s = h[tst_tmp];
        tst = h[sum1_tmp];
        xdlanv2(&h[(i + 3 * (i - 1)) - 1], &d1, &s, &tst, &htmp1, &ab, &ba, &aa,
                &h22, &rt1r);
        h[nr] = d1;
        h[tst_tmp] = s;
        h[sum1_tmp] = tst;
        if (3 > i + 1) {
          c_st.site = &ce_emlrtRSI;
          xrot(&c_st, 2 - i, h, i + (i + 1) * 3, (i + (i + 1) * 3) + 1, h22,
               rt1r);
        }

        if (i - 1 >= 1) {
          nr = i * 3;
          for (k = 0; k <= i - 2; k++) {
            tst = h22 * h[ix] + rt1r * h[nr];
            h[nr] = h22 * h[nr] - rt1r * h[ix];
            h[ix] = tst;
            nr++;
            ix++;
          }
        }

        b_xrot(z, 1 + (i - 1) * 3, 1 + i * 3, h22, rt1r);
      }

      i = L - 2;
    }
  }

  return info;
}

/* End of code generation (xhseqr.c) */
