/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trqp_control_data.c
 *
 * Code generation for function 'trqp_control_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "trqp_control.h"
#include "trqp_control_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131482U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "trqp_control",                      /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo q_emlrtRSI = { 16,         /* lineNo */
  "xpotrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xpotrf.m"/* pathName */
};

emlrtRSInfo r_emlrtRSI = { 42,         /* lineNo */
  "xzpotrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzpotrf.m"/* pathName */
};

emlrtRSInfo s_emlrtRSI = { 57,         /* lineNo */
  "xzpotrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzpotrf.m"/* pathName */
};

emlrtRSInfo t_emlrtRSI = { 61,         /* lineNo */
  "xzpotrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzpotrf.m"/* pathName */
};

emlrtRSInfo u_emlrtRSI = { 65,         /* lineNo */
  "xzpotrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzpotrf.m"/* pathName */
};

emlrtRSInfo v_emlrtRSI = { 69,         /* lineNo */
  "xzpotrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzpotrf.m"/* pathName */
};

emlrtRSInfo w_emlrtRSI = { 32,         /* lineNo */
  "xdotc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdotc.m"/* pathName */
};

emlrtRSInfo x_emlrtRSI = { 35,         /* lineNo */
  "xdot",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdot.m"/* pathName */
};

emlrtRSInfo y_emlrtRSI = { 15,         /* lineNo */
  "xdot",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdot.m"/* pathName */
};

emlrtRSInfo ab_emlrtRSI = { 42,        /* lineNo */
  "xdotx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdotx.m"/* pathName */
};

emlrtRSInfo bb_emlrtRSI = { 21,        /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo cb_emlrtRSI = { 57,        /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

emlrtRSInfo db_emlrtRSI = { 77,        /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

emlrtRSInfo eb_emlrtRSI = { 78,        /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

emlrtRSInfo hb_emlrtRSI = { 141,       /* lineNo */
  "ceval_xgemv",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

emlrtRSInfo ib_emlrtRSI = { 142,       /* lineNo */
  "ceval_xgemv",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

emlrtRSInfo jb_emlrtRSI = { 143,       /* lineNo */
  "ceval_xgemv",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

emlrtRSInfo kb_emlrtRSI = { 144,       /* lineNo */
  "ceval_xgemv",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

emlrtRSInfo lb_emlrtRSI = { 145,       /* lineNo */
  "ceval_xgemv",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

emlrtRSInfo mb_emlrtRSI = { 31,        /* lineNo */
  "xscal",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal.m"/* pathName */
};

emlrtRSInfo nb_emlrtRSI = { 18,        /* lineNo */
  "xscal",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xscal.m"/* pathName */
};

emlrtRSInfo vb_emlrtRSI = { 20,        /* lineNo */
  "ishermitian",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\ishermitian.m"/* pathName */
};

emlrtRSInfo xb_emlrtRSI = { 66,        /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

emlrtRSInfo cc_emlrtRSI = { 83,        /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

emlrtRSInfo dc_emlrtRSI = { 48,        /* lineNo */
  "triu",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\triu.m"/* pathName */
};

emlrtRSInfo ic_emlrtRSI = { 20,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo jc_emlrtRSI = { 41,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo kc_emlrtRSI = { 53,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo lc_emlrtRSI = { 68,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo mc_emlrtRSI = { 71,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo nc_emlrtRSI = { 81,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo uc_emlrtRSI = { 37,        /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

emlrtRSInfo vc_emlrtRSI = { 45,        /* lineNo */
  "xgerc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgerc.m"/* pathName */
};

emlrtRSInfo wc_emlrtRSI = { 45,        /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

emlrtRSInfo xc_emlrtRSI = { 15,        /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xger.m"/* pathName */
};

emlrtRSInfo yc_emlrtRSI = { 41,        /* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

emlrtRSInfo ad_emlrtRSI = { 54,        /* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

emlrtRSInfo hd_emlrtRSI = { 11,        /* lineNo */
  "xungorghr",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

emlrtRSInfo id_emlrtRSI = { 34,        /* lineNo */
  "ceval_xungorghr",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

emlrtRSInfo jd_emlrtRSI = { 35,        /* lineNo */
  "ceval_xungorghr",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

emlrtRSInfo kd_emlrtRSI = { 55,        /* lineNo */
  "ceval_xungorghr",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

emlrtRSInfo ld_emlrtRSI = { 60,        /* lineNo */
  "ceval_xungorghr",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

emlrtRSInfo md_emlrtRSI = { 68,        /* lineNo */
  "ceval_xungorghr",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

emlrtRSInfo nd_emlrtRSI = { 9,         /* lineNo */
  "int",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\int.m"/* pathName */
};

emlrtRSInfo od_emlrtRSI = { 8,         /* lineNo */
  "majority",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\majority.m"/* pathName */
};

emlrtRSInfo pd_emlrtRSI = { 31,        /* lineNo */
  "infocheck",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pathName */
};

emlrtRSInfo td_emlrtRSI = { 238,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo ud_emlrtRSI = { 257,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo wd_emlrtRSI = { 285,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo xd_emlrtRSI = { 293,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo yd_emlrtRSI = { 313,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo ae_emlrtRSI = { 320,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo be_emlrtRSI = { 354,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo de_emlrtRSI = { 365,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo ee_emlrtRSI = { 44,        /* lineNo */
  "xdlanv2",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

emlrtRSInfo fe_emlrtRSI = { 58,        /* lineNo */
  "xdlanv2",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

emlrtRSInfo ge_emlrtRSI = { 79,        /* lineNo */
  "xdlanv2",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

emlrtRSInfo he_emlrtRSI = { 80,        /* lineNo */
  "xdlanv2",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

emlrtRSInfo ie_emlrtRSI = { 82,        /* lineNo */
  "xdlanv2",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

emlrtRSInfo je_emlrtRSI = { 110,       /* lineNo */
  "xdlanv2",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

emlrtRSInfo ne_emlrtRSI = { 37,        /* lineNo */
  "eml_rsf2csf",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eml_rsf2csf.m"/* pathName */
};

emlrtRSInfo oe_emlrtRSI = { 47,        /* lineNo */
  "eml_rsf2csf",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eml_rsf2csf.m"/* pathName */
};

emlrtRSInfo pe_emlrtRSI = { 55,        /* lineNo */
  "eml_rsf2csf",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eml_rsf2csf.m"/* pathName */
};

emlrtRSInfo qe_emlrtRSI = { 15,        /* lineNo */
  "xdlanv2",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\xdlanv2.m"/* pathName */
};

emlrtRSInfo sf_emlrtRSI = { 10,        /* lineNo */
  "xzrot_rows",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzrot_rows.m"/* pathName */
};

emlrtRSInfo tf_emlrtRSI = { 10,        /* lineNo */
  "xzrot_cols",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzrot_cols.m"/* pathName */
};

emlrtRSInfo jg_emlrtRSI = { 40,        /* lineNo */
  "xdotc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdotc.m"/* pathName */
};

emlrtRSInfo kg_emlrtRSI = { 15,        /* lineNo */
  "xdotc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdotc.m"/* pathName */
};

emlrtRSInfo lg_emlrtRSI = { 20,        /* lineNo */
  "mldivide",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

emlrtRSInfo mg_emlrtRSI = { 42,        /* lineNo */
  "mldiv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

emlrtRSInfo ng_emlrtRSI = { 61,        /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

emlrtRSInfo og_emlrtRSI = { 292,       /* lineNo */
  "lusolve3x3",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

emlrtRSInfo pg_emlrtRSI = { 90,        /* lineNo */
  "warn_singular",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

emlrtRSInfo tg_emlrtRSI = { 26,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo ug_emlrtRSI = { 58,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo vg_emlrtRSI = { 24,        /* lineNo */
  "xdlapy3",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\xdlapy3.m"/* pathName */
};

emlrtRSInfo wg_emlrtRSI = { 52,        /* lineNo */
  "xgerc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgerc.m"/* pathName */
};

emlrtRSInfo xg_emlrtRSI = { 15,        /* lineNo */
  "xgerc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerc.m"/* pathName */
};

emlrtRSInfo eh_emlrtRSI = { 247,       /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRSInfo gh_emlrtRSI = { 274,       /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRSInfo hh_emlrtRSI = { 281,       /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRSInfo ih_emlrtRSI = { 306,       /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRSInfo mh_emlrtRSI = { 339,       /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRSInfo nh_emlrtRSI = { 345,       /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRSInfo oh_emlrtRSI = { 351,       /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRTEInfo d_emlrtRTEI = { 45,       /* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

emlrtRTEInfo e_emlrtRTEI = { 48,       /* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

emlrtRTEInfo f_emlrtRTEI = { 12,       /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

/* End of code generation (trqp_control_data.c) */
