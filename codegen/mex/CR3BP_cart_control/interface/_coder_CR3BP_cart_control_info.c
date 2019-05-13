/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_CR3BP_cart_control_info.c
 *
 * Code generation for function '_coder_CR3BP_cart_control_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CR3BP_cart_control.h"
#include "_coder_CR3BP_cart_control_info.h"

/* Function Definitions */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 5);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString(
    "CR3BP_cart_control"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(5.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "C:\\Users\\u99a\\Google Drive\\Grad School\\Master\'s Thesis Stuff\\Code\\DDP\\ddp_se_halo\\CR3BP_cart_control.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737558.0543402778));
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.6.0.1099231 (R2019a) Update 1"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[21] = {
    "789ced5dcb6f234919ef1966d0cc61a12fb0cb3b23d0f25894b663c71e8356f2fb918d1fb193b59d7d386dbbdaee4d3f9c7e38764ee182b820ed1fc01f809010"
    "7062051cb2b7155cf6002bc415a15da13dad044744fbd189bbc635ee992eb7d3769594542abf76fdaa3e7dfd7d555f3d4cddc9e5ef5014f505e3e7aef1f3d26f",
    "a8717a619251f434bf4b59138cdf99e6df80ca66ba4fddb37ccec47f31cd5bb2a48181362908bc040abad8048a519058115c57d396455e6225ed70d803940254"
    "59e883f618e178011cf222d897670a59de2888e919e8ba3082467f27baa0755ad1454ae9aa37cd15660bd48c7c3e9ce97f2412beeeffbd39f299c5cdfef208f9",
    "d010fe46eaadc48f982315282aa347222c9391e58e00b6920adf074c4661db5b955657960526cfaa1a50beab6e1d7681caab5b154de7382621b701934c969876"
    "bbd75041a3cb0a32932807e2a5468b55b4c648de8a2c6c8b50ffde9d69ff6cbb3e3fa77fb3f81de839b87f0fa7b9cff2df607492ef4ef3f0347f3ccd23d3fcc7",
    "51b37d2708fe79f27f96f6d15344ecc9e723b5738baf2deb4d01dcf0fdd2215f16c967c5dfc8edd7c62a5652e48ec28a5ba3774165f2b1c3fd589c29eff8fc86"
    "ce69867e35e50103448111f82623b29ac03619b9a73213396d8b8be464576fe0dc4c0fa907d3bf2efffaf38f3e8ab9c737499bc23740d46757efbe8ce0a321dc",
    "7f01bafec0795bf7a762b54aa6330cb5c57afaa61da5053c8bda4121ca6ed5efd5f7b78768975d7dbb0b95cd64da7ddaf2df1b7b6ff25f22eab72bb76f21f869"
    "086f197e51d9e68dc18622b1c236afc6755ed0729231dc000adf5a99ddffc0215f0bc967c59f496fd42eab80363396d9f4f72bd3cc9420034b703aa270d18efd",
    "99fa1ff10b5ef70be7c7f1a38b8b41375cece9a9d44ea2b55b661fc7895f58b55f3841b40bafbec5b18def1f4065eafab909c2ab4667157eb02a3bff5b877cfb"
    "483e2bee440f8060fcc198929a1874f7f421fafe0f32c49e7bdd9e175aa7d59c926e7169ad1668f90f76e3f57c3c43ecf946d8f3cb34367b7e1fc1474f9169b8",
    "c6b3f19a0c92cf8a3bd583a91ab8687748bc66997c4eedf897107c34840f7d11a99b4b9c17b34052a5d051a8799cc952c48eaffafd75375eb31d9de47e12afa1"
    "48bce669fd22f19ad5f291780d9efa9dced34b5099829e33714c7ee1112768e33f5dd5bb68298a4bef5e44f0d1100ef903b5c50aac92eaaccc0fdc5a3d19fd3c",
    "61fc4d71b9391fbcfaacfe1762ef6fabbdb73b0f8805254edef3f1155f3d542af9f73bb1dda040117bbf39efb1912ef3d145f30fbbf27a012a53d07326ceabd2"
    "649caa8d767cad2ecee3543f8a483e2bfe5ce3018e1f80764f36d483b1c8cbd5780ff5ebea57fe46ecfc92f8dc1ad76702a7c3ca598717128789d3f259bc7378",
    "7a944a123bbfa9761ec5876f3d96e38de94cd7ab767d0fc967c59ddbf5899ccc0dbbc4aeaf079f5be3f7fe1948f5fa2d35523b0fc87249adf803f5636a7decfa"
    "7b88cfdb95630d513f0de1b8edfa238e57548de3dd8ddbb0d8e2f8df44f0d1106e88a16174bfc1c98a20cbbd86dc070a27c8e78dd6e8fc85f3713d9c50ed3193",
    "c977f59c7c66fd275019e6337147fb71266af414f9b91acff9d3bfee9378ce6df50776c7f9ea6ba9412a797151da1bec04f33bbec441ccef4bad8f3ff804f179"
    "bb72fc29a27e1ac297fd5e3f7afa038d2e107a76ce2be1d5d70cb6f9c13da84c5d3f374146e3de51bee275065e6a83414ed2b0ed1b482f688789e398378ce60c",
    "2eeac77bfff907992f78dd3f54863d5edc3d2b57fd7cb31dcc1d1f94f2fefe1ac581c8fb6b4d567df3ad4d9c7f917f6975d9d1f65112e747e46622f12077f848"
    "9c1f4ffd64fc6f6d2f5e7dcdb9761f83d175911d78d71f2c757dc07a5e6b2c29f7d7072eefffe4ef241ee4757f5057d86ca5dfec37c365904c0dc5dd48b50e88",
    "3f20fe00d16feb7ab1bbfe8097883fb0e70f78c97d7f70f5c7171f127fe0757fd061ebe162a05a380b37635a62972d0641f0608dceef92f5e2f9b9992cfa77c2"
    "62b3efcf1aef77cae7f679de358e0b92b8fe12f9485c1f4ffd9eb5eb174091557d35f7b145df8e8ef3abb75cb3f39c2e8c8e8f78763fbf1be378b5c72a9c2e31",
    "2359ad20aef33b12e7f7bebdd7423b623959cd748f03f2455fcb8be9bc5f5b237beff43d2e41650a7acec43d7d4e97ba39a7fb33447d76e5f53d041f0de1d0fe"
    "19b6d71386715e62956165ecf3d2bad4d27859c2b5cefcc505ed32716ecadbe8b252db700826bfd3fb1cd805fc268e67dc8014e713f7799f20da8d51bf0eaaff",
    "26f11eaffb89744d8dd70e32af152a47c9ec7e4e5122d992b446f11ef27ecfef973d7d0c63f31fdf46f0d1100efb8fbeccb7638ac20ed302ab6940e2a5cef839"
    "af9e1b7873019f8963d2a739e273fb5e4feaf2bf4de227bcee272ef6b281c451af261e348bed588dcbe6076231bb3e7ee20af179bb723c46d44f4338aef9c424",
    "82d4e00499d51ae6659894cb7a187d93dc03e4906f69f3d05b73ae9cdc03b44c3e720f109efa9dae1f5411f5d3108ecbfe4bb256600b452567bcda1dc3f8bbab"
    "7f756ceb058bee79e655899528efae17e4907c561cc7bdfd86a456304fbc24ebc34be473cbbe9fc5f4a2181cd682beb2b2a327fc20d2170bd4fad877f21ecf6f",
    "bf55efbe83ed7e0872cf338acf8a937b9e1df38dd3a6f0917b9ef1d44fc6fbf37333a1c6fb9788faeccaed6b083e1ac2e7c679b63941962781ae55f905a77a73"
    "84e4b3e278e23daf4ce4c68ce536f6042ece0b7e45f61179df0f34bba1524d12b476451653ba940d3453f1bd355a1ffe10f179bb72bceddfeb8ed213bb7af939",
    "44ffccfda42f59fe0b7faf3bbeef6f5fb4af543d53b451eed5f3036e7c2f1c1046bb4a47927233fe1f7dffe865e207bcee07829914d7f58572ef1453819c563a"
    "90a47e22b946ebbfe4fdb526abbebd8c6dfcff75041f0de14fc48592b2c8f2524a5164cbb9dc9ec3f638dd3feaadf980458c6ecf07fef029d907e4793f20e4c5",
    "b678aa807c2f51d51ecb7a9babeb3c890b6de0fb3c4a216ce3fbc5df17303a15a502afae0317907c561cc7b9315356ee9e138e3e78f56d62dfbd6edfcfab3935"
    "2d9cbe9edee1948ad07fa7b8275d1c24887ddf4cfbfe2ad9ff3f4d64fffffcfed8d023b2ff7f897c64ff3f9efa49fcc79aacfab68d2dfef355041f0de1f3d77f",
    "cd28ffeaecbfd3f1c3e1023e13c7bbfe3bd199d97e9c20da8971dfffeffff93189fbdf56bb6f775fe8637dbfe27b3d508c29b9404aaaed954352394411bbbf69"
    "76ff5d447d76e5f47d041f0de1f3ee8fb01e85ce4925816d81e9f3b7651dc0e97ed1e6027e13c778ce7cae5857f03d93e41e8925f2b9353fd04b89c4209ca8f6",
    "0a87bb205ce806f2fbe1d3358a1b91f77b7ebfece9e30fc93a814d3eb24e809b6f9236858fac13e0a99fd8fbf9fddad478d1f3fa03122f9a9f9b89c48bdce123"
    "f12267f5ff1fb01f96a6", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 44848U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_CR3BP_cart_control_info.c) */
