#include "nativeBbsSignatures.h"

namespace nativeBbsSignatures {

jsi::Value sign(jsi::Runtime &rt, jsi::Object options) {
  try {
    ByteArray publicKey = turboModuleUtility::jsiToValue<ByteArray>(rt, options.getProperty(rt, "publicKey"));
    ByteArray secretKey = turboModuleUtility::jsiToValue<ByteArray>(rt, options.getProperty(rt, "secretKey"));
    std::vector<ByteArray> messages = turboModuleUtility::jsiToValue<std::vector<ByteArray>>(rt, options.getProperty(rt, "messages"));

    ExternError *err = new ExternError();
    ByteArray signature = bbs::sign(publicKey, secretKey, messages, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(rt, "signature", turboModuleUtility::byteArrayToArrayBuffer(rt, signature));
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Value verify(jsi::Runtime &rt, jsi::Object options) {
  return jsi::Object(rt);
}

jsi::Value createProof(jsi::Runtime &rt, jsi::Object options) {
  return jsi::Object(rt);
}

jsi::Value verifyProof(jsi::Runtime &rt, jsi::Object options) {
  return jsi::Object(rt);
}

jsi::Value generateBls12381G1KeyPair(jsi::Runtime &rt, jsi::Object options) {
  return jsi::Object(rt);
}

jsi::Value generateBls12381G2KeyPair(jsi::Runtime &rt, jsi::Object options) {
    try {
    ByteArray seed = turboModuleUtility::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "seed"), true);

    ExternError *err = new ExternError();

    BlsKeyPair bpk = bbs::generateBls12381G2KeyPair(seed, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(
        rt, "publicKey",
        turboModuleUtility::byteArrayToArrayBuffer(rt, bpk.publicKey));
    object.setProperty(
        rt, "secretKey",
        turboModuleUtility::byteArrayToArrayBuffer(rt, bpk.secretKey));
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}
 
jsi::Value bls12381toBbs(jsi::Runtime &rt, jsi::Object options) {
  try {
    uint32_t messageCount = turboModuleUtility::jsiToValue<int32_t>(
        rt, options.getProperty(rt, "messageCount"));
    ByteArray publicKey = turboModuleUtility::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "publicKey"));

    ExternError *err = new ExternError();
    BlsKeyPair blsKeyPair = BlsKeyPair{publicKey};
    BbsKey bbsKey = bbs::bls12381toBbs(blsKeyPair, messageCount, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(
        rt, "publicKey",
        turboModuleUtility::byteArrayToArrayBuffer(rt, bbsKey.publicKey));
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

}
