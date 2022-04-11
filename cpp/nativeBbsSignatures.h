#pragma once

#include <jsi/jsi.h>

#include "bbsSignatures.h"
#include "turboModuleUtility.h"

using namespace facebook;

namespace nativeBbsSignatures {

jsi::Value sign(jsi::Runtime &rt, jsi::Object options);
jsi::Value verify(jsi::Runtime &rt, jsi::Object options);
jsi::Value createProof(jsi::Runtime &rt, jsi::Object options);
jsi::Value verifyProof(jsi::Runtime &rt, jsi::Object options);
jsi::Value generateBls12381G1KeyPair(jsi::Runtime &rt, jsi::Object options);
jsi::Value generateBls12381G2KeyPair(jsi::Runtime &rt, jsi::Object options);
jsi::Value bls12381toBbs(jsi::Runtime &rt, jsi::Object options);

}; // namespace nativeBbsSignatures
