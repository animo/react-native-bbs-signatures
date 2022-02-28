// class "interface" of the generated code. This has to be copied over from
// `../lib/cpp-generated/NativeModules.h`

#include "../lib/cpp-generated/NativeModules.h"
#include "NativeModules.h"
#include "TurboModuleUtils.h"
#include "bbs.h"
#include <ReactCommon/TurboModule.h>
#include <jsi/jsi.h>
#include <jsi/jsilib.h>

namespace facebook {
namespace react {

class NativeBbsSignatures : public BbsSignaturesCxxSpecJSI {
public:
  NativeBbsSignatures(std::shared_ptr<CallInvoker> jsInvoker);
  jsi::Object sign(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object blsSign(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object verify(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object blsVerify(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object createProof(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object blsCreateProof(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object verifyProof(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object blsVerifyProof(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object commitmentForBlindSignRequest(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object verifyBlindSignRequest(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object blindSign(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object generateBls12381G1KeyPair(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object generateBlindedBls12381G1KeyPair(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object generateBls12381G2KeyPair(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object generateBlindedBls12381G2KeyPair(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object bl12381toBbs(jsi::Runtime &rt, const jsi::Object &options);
};
} // namespace react
} // namespace facebook
