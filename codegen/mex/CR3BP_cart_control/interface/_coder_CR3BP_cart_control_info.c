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
    "789ced5dcd6f234915ef2c3368e6b0900becf29d1168815d94b663c71e8356f2f74736fe889dacedec87d3b6abeddef487d3dd76ec9cc2057141da3f803f0021"
    "21e0c40a38646f2bb8ec815d21ae08811027243822badd7e93d8e31a7bd2e576daae2765ca55cfae5fd59bd7ef55bdfa68662393dd6018e673c69f99befc4b66",
    "482f5a09b3394a5f60c66992bf314abf369107bacfdc1bfb1df07f3a4a1b8aaca3be6e65444146b9ae5447aa919139093da9a6a94882ccc9fae1a0831815698a"
    "d843cd21871744742848685fb991490b46464ade603dc9982cf373ac8d1aa7a5aec4a86dedbab9e2cd0c73433e1fdfe87f28147cd2ff7b53e473930ffd1530f2",
    "d91c9501ffadc43bb1efb3471a5235b61b0a716c4a515a22da8aab420fb129956b6e951a6d4511d92ca7e948fdb6b675d8469aa06d95f42ecfb331a589d878bc"
    "c0369b9d9a866a6d4e54d858d1172dd41a9caad74c79ab8ab82d4df4effd1beddf60aeff7f3f3ba57f37f91b13df9becdfc351ea192bf587ad7477940647e9e3",
    "511a1aa53f0843fb4e30f8d3e4ff3ceddb34386699d451ce4db5730aafa974eb22bac6fb994dbc3416cf2a03fe5b99fdca50c50aaad2523969cb7c1634361b39"
    "dc8f44d9e28ec76be89c6ee8575de9b348125951a8b312a78b5c9d553a1a6bc9695b9a25a779f56632057ac83c187dbafcd34f3efd34e21c9e45eb82d7c7d437",
    "afde7d1183077a077cef056a7b7de7cdae3711a99452ad41a0295593d7ed28ccc099d50e069377aa7eb73ebf1d4cbbe6d5b71726f24060f737c74aafed3de05f"
    "62ea9f576edfc0e083dc80df30fca2ba2d18830d55e6c46d418b760551cfc8c67003a942636976ff239b788d19fd07fe73e98dd6e654d46487321bfdfbda2801",
    "09b293121c8d281cb4637f60fe47fd82dbfdc2f971f4e8e2a2df0ee63bdd446227d6d82d728fa3d42f2cdb2f9c60da4556dfa2c4c6f70f26f2409b06c72c1334"
    "a3b3aad05f969dff954dbc7d2c9e55067c3b7a8044e3030b92b20cba73fa10fef0d514b5e76eb7e7b9c66939a3261b7c52aff81ade83dd68351b4d517bbe16f6",
    "fc3249cc9edfc7e06d1a1cb36c14ae716dbc2685c5b3ca806f570f466ae0a0dda1f19a45e2d9b5e35fc0e081de017fe009c9ed4cec3c9f46b226078e02f5e354"
    "9aa1767cd9cfafb3f19aedb0957a69bc66f41d1aafb9b51da3f19a05e2d1780d99faedced30b1379209023f009f98547bca80f3f3aaa77e1429894debd84c103",
    "79017fc21f680d4ee4d4446b697ee0ceea89f9f794f1077139391fbcfa77f58fd4dedf557b3fef3c20e2977965cf23943cd540a1e0dd6f4576fd2243edfdfa3c"
    "c7065d66c3b3e61ff3caeb450c1ec80bf882265be354dddcf1b5bc388f5dfdc8cfe82ff06f351ee0853e6a7614433dd83179391aef617e51fed227d4ce2f08cf",
    "a9717dca773a289db5043176183b2d9e455b87a7478938b5f3eb6ae77178e4d66379c198ceb4dd6ad7f7b0785619f0eddb754b4eb06197daf5d5c0736afcde3b"
    "43894eafa1852ae73e45296825afaf7accac8e5dff00f3fb79e558c1d40f72043e69bbfe8817544de70567e3361cb138fed731782037e01b62a819ddaff18a2a",
    "2a4aa7a6f490ca8bca79ad619ebfb03fae9f245c7b8000efea967850d7c9447e120ff8b6f6e3586af40cf9391acff9fddfeed378ce5df507f38ef3b53712fd44"
    "fce2a2b0d7dff167773cb18388d793581d7ff00fccefe795e38f30f5831c81bfe8e7fad1b3bf506b23b133cf7925b2fa9a22363fb8379107da3438669939ee35",
    "f34b5e6710e426ea67649dd8be81e48c76009fc4bcc19c3338a81f1ffce72f74bee076ff501a740469f7ac58f60af5a63f737c50c87a7b2b1407a2cfef388deb"
    "9b6765e2fcb3fc4ba3cd99db47699c1f9302d178d06ad9f7558ff3d3f1ff22f535e3d87d0c46d725aeef5e7fb0d0f581f1f35a434939bf3e7079ff877fa6f120",
    "b7fb83aacaa54bbd7aaf1e2ca2786220ed86ca5544fd01f507987e8faf173beb0f0499fa83f9fc81203bef0fae7ef7d243ea0fdcee0f5a5c3598f7957367c17a"
    "448fed72793ff21facd0f95dba5e3c3d051ad3bf138e987d7fde78bf5d3ca7cff3ae705c90c6f5178847e3fa64ea77ad5dbf40aaa27597731f5bf8ddf030bd7a",
    "c7313bcf7745f3f8886bf7f33b318ed73a9cca7765d694d512e23abfa6717ef7db7b3db02315e3e554fbd8a75cf4f4ac94cc7af515b2f7769fe3c2441e08e408"
    "7c579fd365aecfe9fe1853dfbcf2fa0e060fe405fc89fd335ca7230ea282cca983d2d0e725bb7243171499d43af3e767b40bf8fc08b7d6e6e4a6e11000dfee7d",
    "0edc0c7ce093193760c5f9d47dde27987613d4af83f23f69bcc7ed7e2259d1a29583d41bb9d2513cbd9f51d550ba20af50bc873edf76f43148cc7f7c13830772"
    "04fea4ffe8294233a2aadc202972ba8e64416e0dbfe7d673036fcfc0033e217d9a223ea7eff5642eff5ba77ec2ed7ee2622fed8b1d752ad2413ddf8c54f874b6",
    "2fe5d3abe327ae30bf9f578ec798fa418ec027359fb02248355e5438bd069761320eeb61f86d7a0f904dbc85cd43efccb9727a0fd022f1e83d4064eab7bb7e50"
    "c6d40f72043e29fb2f2b7a8ecbe5d58cf168b70ce3efacfe5589ad17ccbae759d0644e66dcbb5e90c1e25965c027716fbf21a925cc132fe9faf002f19cb2ef67",
    "916e5ef20f2a7e4f51dde9c6bc28d49372ccead877fa1c4f6fffb8de7d8bd8fd10f49ee767f79fdef34c0c6f48eb8247ef7926533f1def4f4f8170e3fd4b4c7d"
    "f3caed2b183c901bf0a7c679b6795151ac40d7b2fc825dbd399ad17fe09389f7bc66c98d1dca6de8091c9c17fc9cee2372bf1fa8b703858a2ceacd922225ba72",
    "da574f44f756687df863ccefe795e35d7faf3b4e4fe6d5cbcf60fa07fb495f1e2b9d7caf3bb9f7b7cfda57aa9da9ba9977ebf90127de0b87447357a9292927e3"
    "ffe10f8f5ea17ec0ed7ec09f4af06d4f20f35e3ee1cbe8850359eec5e22bb4fe4b9fdf711ad7b757888dffbf8ac1033901ffa9b8505c9138414ea8aa32762eb7",
    "63b33d76f78fba6b3e302646a7e703bffd17dd07e47a3f2066a5a674aaa26c2756d61f2bdd265fed0a342eb486cfb3490162e3fbd9ef0b304f4569c8adebc039"
    "2c9e55067c12e7c64056ce9e130e3f78fd5d6adfdd6edfcfcb192d299ebe99dce1d592d87b2fbf275f1cc4a87d5f4ffbfe3addff3f22baffffd67a44f7ff2f10",
    "8feeff27533f8dff8cd3b8be6d138bff7c1983077202fef4f55f88f22fcffedb1d3f1ccec0033ed9f55f4b676ef6e304d34e82fbfe7ff3d7bfd3b8ff5db5fbf3"
    "ee0b7ddcdd2f79def4e5236ac697902b7bc5805c0c30d4eeaf9bdd7f1f53dfbc72fa2e060fe404fc69f7478c1f85cec805916ba0d1f7efca3a80ddfda2f519f8",
    "c02778ce7caa5897f09e497a8fc402f19c9a1f740bb1583f182b777287bb28986bfbb2fbc1d3158a1bd1e7db8e3e7e8fae13cc8947d70948e359b42e78749d80"
    "4cfdd4dedbd1c7d58b17ddd61fd078d1f41488c68bdce117d63d5ef47f97819890", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 44848U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_CR3BP_cart_control_info.c) */
