#include "nativeBbsSignatures.h"

namespace nativeBbsSignatures {

jsi::Value sign(jsi::Runtime &rt, jsi::Object options) {
  try {
    ByteArray publicKey = turboModuleUtility::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "publicKey"));
    ByteArray secretKey = turboModuleUtility::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "secretKey"));
    std::vector<ByteArray> messages =
        turboModuleUtility::jsiToValue<std::vector<ByteArray>>(
            rt, options.getProperty(rt, "messages"));

    ExternError *err = new ExternError();
    ByteArray signature = bbs::sign(publicKey, secretKey, messages, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(
        rt, "signature",
        turboModuleUtility::byteArrayToArrayBuffer(rt, signature));
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Value verify(jsi::Runtime &rt, jsi::Object options) {
  try {
    ByteArray publicKey = turboModuleUtility::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "publicKey"));
    ByteArray signature = turboModuleUtility::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "signature"));
    std::vector<ByteArray> messages =
        turboModuleUtility::jsiToValue<std::vector<ByteArray>>(
            rt, options.getProperty(rt, "messages"));

    ExternError *err = new ExternError();
    bool verified = bbs::verify(publicKey, signature, messages, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(rt, "verified", verified);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Value createProof(jsi::Runtime &rt, jsi::Object options) {
  try {
    ByteArray nonce = turboModuleUtility::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "nonce"));
    ByteArray publicKey = turboModuleUtility::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "publicKey"));
    ByteArray signature = turboModuleUtility::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "signature"));
    std::vector<ByteArray> messages =
        turboModuleUtility::jsiToValue<std::vector<ByteArray>>(
            rt, options.getProperty(rt, "messages"));
    std::vector<int32_t> revealed =
        turboModuleUtility::jsiToValue<std::vector<int32_t>>(
            rt, options.getProperty(rt, "revealed"));

    if (messages.size() != revealed.size()) {
      throw "Messages does not have the same size as revealed";
    }

    ExternError *err = new ExternError();
    ByteArray proof =
        bbs::createProof(nonce, publicKey, signature, messages, revealed, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(rt, "proof",
                       turboModuleUtility::byteArrayToArrayBuffer(rt, proof));
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Value verifyProof(jsi::Runtime &rt, jsi::Object options) {
  try {
    ByteArray nonce = turboModuleUtility::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "nonce"));
    ByteArray proof = turboModuleUtility::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "proof"));
    ByteArray publicKey = turboModuleUtility::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "publicKey"));
    std::vector<ByteArray> messages =
        turboModuleUtility::jsiToValue<std::vector<ByteArray>>(
            rt, options.getProperty(rt, "messages"));

    ExternError *err = new ExternError();
    bool verified = bbs::verifyProof(nonce, publicKey, proof, messages, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(rt, "verified", verified);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Value generateBls12381G1KeyPair(jsi::Runtime &rt, jsi::Object options) {
  try {
    ByteArray seed = turboModuleUtility::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "seed"), true);

    ExternError *err = new ExternError();

    BlsKeyPair bpk = bbs::generateBls12381G1KeyPair(seed, err);

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

} // namespace nativeBbsSignatures
