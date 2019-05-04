/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trqp_multipliers_data.c
 *
 * Code generation for function 'trqp_multipliers_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "trqp_multipliers.h"
#include "trqp_multipliers_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131482U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "trqp_multipliers",                  /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo n_emlrtRSI = { 74,         /* lineNo */
  "cholesky",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\chol.m"/* pathName */
};

emlrtRSInfo o_emlrtRSI = { 84,         /* lineNo */
  "cholesky",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\chol.m"/* pathName */
};

emlrtRSInfo p_emlrtRSI = { 85,         /* lineNo */
  "cholesky",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\chol.m"/* pathName */
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

emlrtRSInfo ub_emlrtRSI = { 30,        /* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

emlrtRSInfo vb_emlrtRSI = { 36,        /* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

emlrtRSInfo wb_emlrtRSI = { 50,        /* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

emlrtRSInfo xb_emlrtRSI = { 58,        /* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

emlrtRSInfo yb_emlrtRSI = { 23,        /* lineNo */
  "ixamax",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\ixamax.m"/* pathName */
};

emlrtRSInfo ac_emlrtRSI = { 24,        /* lineNo */
  "ixamax",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\ixamax.m"/* pathName */
};

emlrtRSInfo cc_emlrtRSI = { 45,        /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

emlrtRSInfo dc_emlrtRSI = { 15,        /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xger.m"/* pathName */
};

emlrtRSInfo ec_emlrtRSI = { 41,        /* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

emlrtRSInfo fc_emlrtRSI = { 54,        /* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

emlrtRSInfo bd_emlrtRSI = { 20,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo cd_emlrtRSI = { 41,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo dd_emlrtRSI = { 53,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo ed_emlrtRSI = { 68,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo fd_emlrtRSI = { 71,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo gd_emlrtRSI = { 81,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo nd_emlrtRSI = { 37,        /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

emlrtRSInfo od_emlrtRSI = { 45,        /* lineNo */
  "xgerc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgerc.m"/* pathName */
};

emlrtRSInfo wd_emlrtRSI = { 34,        /* lineNo */
  "ceval_xungorghr",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

emlrtRSInfo xd_emlrtRSI = { 35,        /* lineNo */
  "ceval_xungorghr",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

emlrtRSInfo yd_emlrtRSI = { 55,        /* lineNo */
  "ceval_xungorghr",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

emlrtRSInfo ae_emlrtRSI = { 60,        /* lineNo */
  "ceval_xungorghr",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

emlrtRSInfo ce_emlrtRSI = { 9,         /* lineNo */
  "int",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\int.m"/* pathName */
};

emlrtRSInfo de_emlrtRSI = { 8,         /* lineNo */
  "majority",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\majority.m"/* pathName */
};

emlrtRSInfo ee_emlrtRSI = { 31,        /* lineNo */
  "infocheck",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pathName */
};

emlrtRSInfo he_emlrtRSI = { 15,        /* lineNo */
  "xdhseqr",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo je_emlrtRSI = { 238,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo ke_emlrtRSI = { 257,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo me_emlrtRSI = { 285,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo ne_emlrtRSI = { 293,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo oe_emlrtRSI = { 313,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo pe_emlrtRSI = { 320,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo qe_emlrtRSI = { 354,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo se_emlrtRSI = { 365,       /* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

emlrtRSInfo te_emlrtRSI = { 44,        /* lineNo */
  "xdlanv2",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

emlrtRSInfo ue_emlrtRSI = { 58,        /* lineNo */
  "xdlanv2",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

emlrtRSInfo ve_emlrtRSI = { 79,        /* lineNo */
  "xdlanv2",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

emlrtRSInfo we_emlrtRSI = { 80,        /* lineNo */
  "xdlanv2",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

emlrtRSInfo xe_emlrtRSI = { 82,        /* lineNo */
  "xdlanv2",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

emlrtRSInfo ye_emlrtRSI = { 110,       /* lineNo */
  "xdlanv2",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdlanv2.m"/* pathName */
};

emlrtRSInfo df_emlrtRSI = { 37,        /* lineNo */
  "eml_rsf2csf",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eml_rsf2csf.m"/* pathName */
};

emlrtRSInfo ef_emlrtRSI = { 47,        /* lineNo */
  "eml_rsf2csf",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eml_rsf2csf.m"/* pathName */
};

emlrtRSInfo ff_emlrtRSI = { 55,        /* lineNo */
  "eml_rsf2csf",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eml_rsf2csf.m"/* pathName */
};

emlrtRSInfo gf_emlrtRSI = { 15,        /* lineNo */
  "xdlanv2",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\xdlanv2.m"/* pathName */
};

emlrtRSInfo hf_emlrtRSI = { 31,        /* lineNo */
  "xgeev",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeev.m"/* pathName */
};

emlrtRSInfo if_emlrtRSI = { 43,        /* lineNo */
  "ceval_xgeev",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeev.m"/* pathName */
};

emlrtRSInfo jf_emlrtRSI = { 50,        /* lineNo */
  "ceval_xgeev",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeev.m"/* pathName */
};

emlrtRSInfo kf_emlrtRSI = { 84,        /* lineNo */
  "ceval_xgeev",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeev.m"/* pathName */
};

emlrtRSInfo lf_emlrtRSI = { 91,        /* lineNo */
  "ceval_xgeev",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeev.m"/* pathName */
};

emlrtRSInfo mf_emlrtRSI = { 101,       /* lineNo */
  "ceval_xgeev",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeev.m"/* pathName */
};

emlrtRSInfo nf_emlrtRSI = { 40,        /* lineNo */
  "xdotc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdotc.m"/* pathName */
};

emlrtRSInfo of_emlrtRSI = { 15,        /* lineNo */
  "xdotc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdotc.m"/* pathName */
};

emlrtRSInfo ag_emlrtRSI = { 71,        /* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xtrsm.m"/* pathName */
};

emlrtRSInfo eg_emlrtRSI = { 26,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo fg_emlrtRSI = { 58,        /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

emlrtRSInfo gg_emlrtRSI = { 24,        /* lineNo */
  "xdlapy3",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\xdlapy3.m"/* pathName */
};

emlrtRSInfo hg_emlrtRSI = { 52,        /* lineNo */
  "xgerc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgerc.m"/* pathName */
};

emlrtRSInfo ig_emlrtRSI = { 15,        /* lineNo */
  "xgerc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerc.m"/* pathName */
};

emlrtRSInfo lg_emlrtRSI = { 19,        /* lineNo */
  "xzhseqr",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRSInfo pg_emlrtRSI = { 247,       /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRSInfo rg_emlrtRSI = { 274,       /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRSInfo sg_emlrtRSI = { 281,       /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRSInfo tg_emlrtRSI = { 306,       /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRSInfo xg_emlrtRSI = { 339,       /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRSInfo yg_emlrtRSI = { 345,       /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRSInfo ah_emlrtRSI = { 351,       /* lineNo */
  "eml_zlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhseqr.m"/* pathName */
};

emlrtRSInfo bh_emlrtRSI = { 45,        /* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\mpower.m"/* pathName */
};

emlrtRSInfo ch_emlrtRSI = { 55,        /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

emlrtRTEInfo d_emlrtRTEI = { 48,       /* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

emlrtRTEInfo e_emlrtRTEI = { 45,       /* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

const char_T cv0[13] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'z', 'g', 'e',
  'e', 'v' };

/* End of code generation (trqp_multipliers_data.c) */
