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
                (737549.05967592588));
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
    "789ced5dcb8fe34819f72c3368e6b0e00becf2ee1168792c6a279d743201ad94f7a3b7f3eede24bd8fb41397136ffb91f6239df4a9b9202e48fb07f007202404"
    "9c580187dedb0a2e7b8015e28a100871428223c249eceed893da78c615a79d54493395ea9f53bfaa4f9fbfafeaab47887b85e23d82203e43ccd2cbbf98e52f1a",
    "65d2c85f20acc98edf33f2afd8ca667a40dcb77ccfc47f62e45d4954c1489d15784e04254de800592f88b4006eaa6124811369513d1a0f00210345e287809922"
    "2cc783234e0087d25c21cfe905213b07dd1426d0e473aa0fba67754d20e4be72db5c7ebe40ccc9e7a3b9fec762d19bfedf5f209f79dcec2f07910f69c3dfccbc",
    "9dfa1e75ac0059a1b4588ca67292d4e3c14e5ae68680cac934b353eff62589a78ab4a202f99bcace511f289cb253573596a5521203a874ba4231cca0ad80769f"
    "e6252a550b252bed2e2dabed89bc6589df156cfd7b6faefdf3edfaf482fecde3f76ccfd9fbf7c8c80396bf86e3b37cdfc8a346fec4c86346fefdb8d9be5308ff",
    "22f93f4bfb48031106d2c544edbce26324adc3835bbe9fbae4cb43f9acf89b85c3e654c52ab2d493696167f22e2854317174984852b5bd4050d73955d7af8e34"
    "a280c0533cd7a1045ae5e90e250d146a26a75d61999c9cea8d3d37d323e2a1f1e9ea8f3ffef8e384777cb3b42d7c23487d4ef5eef3103ed286072f413f18ba60",
    "b46026d1ace77ae30823b4b2b7eda82ce159d60e0252f6aa7ebfbebf0348bb9ceadb0bb6b2994cbb4f5afe7a6bef4dfe2b48fd4ee5f635083f69c3bbba5f9477"
    "397db0218b34bfcb29498de3d582a80f3780cc75d766f73f74c9d785f259f167d21ba54fcb80a1a63233fe7fd5c84c095276091a230a0fedd8ef89ff61bfe077",
    "bf7071923cbebc1cf5a3e58196c9eca5bafb35fa4912fb8575fb855348bbd0ea5b12d9f8fea1ad4cdc3c37433845efaccc8dd665e77fe992ef10ca67c5dde801"
    "e0f50f9429a99941f74e1fe21f7c2787edb9dfed79a97bd628c8d92e9b559ba16eb0ba9f6c1593396ccfb7c29e5f6591d9f307103ed2408c708d6fe33539289f",
    "1577ab07861a78687770bc66957c6eedf8e7207ca40d1f076262bf90ba28e781a88891e348e7249727b01d5ff7fbeb6dbc66373ecb83385e63fc1dc76b16f70b"
    "c76bd6cb87e33568ea773b4fafd8ca84ed391347e4171eb3bc3afde8a9dec52b71547af712848fb4e1367fa074699e9633bdb5f9813bab27937f4f197f535c5e",
    "ce07afffddfa03b6f777d5de3b9d0724c2222b1d04b87aa015a9548287bdc47e9827b0bddf9ef7584f57c5f8b2f9875379bd682b13b6e74c9c53c4d938559dec"
    "f85a5f9cc7ad7e94a17c56fcb9c6032c3702cc40d2d583b2c8cbd3780ff1f3c617fe84edfc8af8bc1ad7e74267e3fa798fe35347a9b3da79b27774769c49633b",
    "bfad761ec6876e3d96e5f4e94cdfaf76fd00ca67c5dddbf5999ccc0dbbd8ae6f069f57e3f7e139c80c865d25d6bc08495245a90743ad136273ecfafb90ef3b95"
    "6313523f69c351dbf5c72c272b2acb791bb7a191c5f1bf0ae1236db82e86b6defd362bc9bc240ddad210c82c2f5db4bb93f317eec7f5f6046b8f994cbeebe7e4",
    "33eb3f5dc267e2aef6e3ccd4e813e4e7693ce7777f7b80e33977d51f381de72baf674699f4e565e560b4172eee0552d5443090d91c7ff00fc8f79dcaf18790fa"
    "491bbeeaf7faf1273fd0ee037ee0e4bc125a7dcd219b1fdcb795899be766c864dc3bc9d7bccec0890c18154415d9be81ec927698388a79c364cee0a17ebcff9f",
    "bfe0f982dffd437d3ce084fdf35a23c8759870e1a45a2906871b1407c2efaf3559f52db03171fe65fea5dba727db47719c1f929b09c783bce1c3717e34f5e3f1"
    "bfb5bd68f5b5e0d97d0c7ad7057ae45f7fb0d2f501eb79ada9a4bc5f1fb87af0833fe37890dffd414ba6f3f56167d889d6403a3316f6638d16c0fe00fb0348bf",
    "adebc5defa034ec4fec0993fe044effdc1f56f5f7a84fd81dffd418f6e45cba146e93cda49a8a97dba1c06e1ea069ddfc5ebc58b733359f4ef944666df9f35de"
    "ef96cfebf3bc1b1c17c471fd15f2e1b83e9afa7d6bd72f812c29da7aee638bbf139fe6d76f7b66e7598d9f1c1ff1ed7e7e2fc6f1ca8096594da426b25a435ce7",
    "5738ceef7f7baf46f6845aba91eb9f84a4cba15a14b2c5a0ba41f6deed7b5cb19509db7326eeeb73bac4ed39dd1f41ea732aaf6f41f8481b6edb3f430f06fc38"
    "c989b43cae4f7d5e5613bb2a2789a8d6993fbba45d26ce1abced3e2d32ba4330f9dddee7402fe1377134e306a8389fbacffb14d26e84fa556dfc13c77bfcee27",
    "b24d25d9ace65e2fd58fd3f9c3822cc7f2157183e23df8fd5edc2f67fa1845e63fbe0ee1236db8dd7f0c258e49c8323dcef2b4aa0291137bd3e7fc7a6ee0ad25"
    "7c268e489f1688cfeb7b3d89abff76b09ff0bb9fb83cc88752c783a650ed94994493cd17474239bf397ee21af27da7723c81d44fda7054f3895904a9cdf212ad",
    "b6cdcb30098ff530fe16be07c825dfcae6a177e65c39be0768957cf81e2034f5bb5d3f6840ea276d382afb2f4a6a892e95e582fe6af774e3efadfeb590ad172c"
    "bbe79953445a24fcbb5e5080f2597114f7f6eb925ac33cf10aaf0faf90cf2bfb7e9ed0ca4278dc0c076af29e960a82d85028119b63dff17bbcb8fd56bdfb06b2",
    "fb21f03dcf303e2b8eef7976cd374ddbc287ef7946533f1eef2fcecd041bef5f41ea732ab72f41f8481bbe30ceb3cbf292340b74adcb2fb8d59b63289f154713"
    "ef797526376a2ab7a927f0705ef033bc8fc8ff7ea0d38f549a22af327549c868623ed4c9240f36687df823c8f79dcaf1aeffae3b4c4f9ceae5a720fd33f793be",
    "6cf9abfd77ddd1fd7efbb27da5cab9ac4e72bf9e1ff0e277e1003fd9553a919497f1fff807c7af603fe0773f10ce65d87e205278b79c0915d44a551487a9f406"
    "adffe2f7d79aacfaf60ab2f1ff97217ca40d7f2a2e9496049a1333b22c59cee50e5cb6c7edfe517fcd072c62f47a3ef09b7fe17d40bef7037c51608433191407",
    "a986fa44d218b6a571382eb485eff32445908def97ff5ec0e4549402fcba0e5c82f2597114e7c64c59797b4e38fef0b577b07df7bb7dbf6814942c7ff646768f"
    "95ebfcf0ddf28178594d61fbbe9df6fd35bcffdf4878ffffe2fe38d023bcff7f857c78ff3f9afa71fcc79aacfab68b2cfef345081f69c317afff9a51fef5d97f",
    "b7e387a3257c268e76fd77a633f3fd3885b413e1beff5ffff5ef38ee7f57edbed37da14fb4c37ae08d503921174219b179508b88b50881edfeb6d9fdf720f539"
    "95d3b7217ca40d5f747f84f5287441acf0741718cfdf957500b7fb453b4bf84d1ce139f385625dc3ef4ce27b2456c8e7d5fc40aba452a368aa31281ded8368a9",
    "1f2a1e46cf36286e84dfefc5fd72a68fdfc5eb040ef9f03a016abe59da163ebc4e80a67e6cef17f76b5be345cfeb0f70bc68716e261c2ff2860fc78bdcd5ff7f"
    "41e593ec", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 44848U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_CR3BP_cart_control_info.c) */
