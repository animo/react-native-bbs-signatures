#pragma once

// class "interface" of the generated code. This has to be copied over from
// `../lib/cpp-generated/NativeModules.h`

#include "generated/NativeModules.h"
#include "TurboModuleUtils.h"
#include "bbs-signatures.h"
#include <ReactCommon/TurboModule.h>

namespace facebook {
namespace react {

class NativeBbsSignatures : public BbsSignaturesCxxSpecJSI {
public:
  NativeBbsSignatures(std::shared_ptr<CallInvoker> jsInvoker);
  jsi::Object sign(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object verify(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object createProof(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object verifyProof(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object commitmentForBlindSignRequest(jsi::Runtime &rt,
                                            const jsi::Object &options);
  jsi::Object verifyBlindSignRequest(jsi::Runtime &rt,
                                     const jsi::Object &options);
  jsi::Object blindSign(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object generateBls12381G1KeyPair(jsi::Runtime &rt,
                                        const jsi::Object &options);
  jsi::Object generateBlindedBls12381G1KeyPair(jsi::Runtime &rt,
                                               const jsi::Object &options);
  jsi::Object generateBls12381G2KeyPair(jsi::Runtime &rt,
                                        const jsi::Object &options);
  jsi::Object generateBlindedBls12381G2KeyPair(jsi::Runtime &rt,
                                               const jsi::Object &options);
  jsi::Object bls12381toBbs(jsi::Runtime &rt, const jsi::Object &options);
};
} // namespace react
} // namespace facebook
