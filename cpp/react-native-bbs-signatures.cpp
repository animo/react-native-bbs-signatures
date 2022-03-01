#include "react-native-bbs-signatures.h"

using namespace facebook;
using namespace react;

NativeBbsSignatures::NativeBbsSignatures(std::shared_ptr<CallInvoker> jsInvoker)
    : BbsSignaturesCxxSpecJSI(jsInvoker){};

jsi::Object NativeBbsSignatures::sign(jsi::Runtime &rt,
                                      const jsi::Object &options) {
  try {
    ByteArray publicKey = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "publicKey"));
    ByteArray secretKey = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "secretKey"));
    std::vector<ByteArray> messages =
        TurboModuleUtils::jsiToValue<std::vector<ByteArray>>(
            rt, options.getProperty(rt, "messages"));

    ExternError *err = new ExternError();
    ByteBuffer signature = Bbs::sign(publicKey, secretKey, messages, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(
        rt, "signature",
        TurboModuleUtils::byteBufferToArrayBuffer(rt, signature));
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object NativeBbsSignatures::blsSign(jsi::Runtime &rt,
                                         const jsi::Object &options) {
  try {
    jsi::Object object = jsi::Object(rt);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object NativeBbsSignatures::verify(jsi::Runtime &rt,
                                        const jsi::Object &options) {
  try {
    ByteArray publicKey = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "publicKey"));
    ByteArray signature = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "signature"));
    std::vector<ByteArray> messages =
        TurboModuleUtils::jsiToValue<std::vector<ByteArray>>(
            rt, options.getProperty(rt, "messages"));

    ExternError *err = new ExternError();
    bool verified = Bbs::verify(publicKey, signature, messages, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(rt, "verified", verified);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object NativeBbsSignatures::blsVerify(jsi::Runtime &rt,
                                           const jsi::Object &options) {
  try {
    jsi::Object object = jsi::Object(rt);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object NativeBbsSignatures::createProof(jsi::Runtime &rt,
                                             const jsi::Object &options) {
  try {
    jsi::Object object = jsi::Object(rt);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object NativeBbsSignatures::blsCreateProof(jsi::Runtime &rt,
                                                const jsi::Object &options) {
  try {
    jsi::Object object = jsi::Object(rt);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object NativeBbsSignatures::verifyProof(jsi::Runtime &rt,
                                             const jsi::Object &options) {
  try {
    jsi::Object object = jsi::Object(rt);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object NativeBbsSignatures::blsVerifyProof(jsi::Runtime &rt,
                                                const jsi::Object &options) {
  try {
    jsi::Object object = jsi::Object(rt);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object
NativeBbsSignatures::commitmentForBlindSignRequest(jsi::Runtime &rt,
                                                   const jsi::Object &options) {
  try {
    jsi::Object object = jsi::Object(rt);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object
NativeBbsSignatures::verifyBlindSignRequest(jsi::Runtime &rt,
                                            const jsi::Object &options) {
  try {
    jsi::Object object = jsi::Object(rt);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object NativeBbsSignatures::blindSign(jsi::Runtime &rt,
                                           const jsi::Object &options) {
  try {
    jsi::Object object = jsi::Object(rt);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object
NativeBbsSignatures::generateBls12381G1KeyPair(jsi::Runtime &rt,
                                               const jsi::Object &options) {
  try {
    ByteArray seed = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "seed"), true);

    ExternError *err = new ExternError();

    BlsKeyPair bpk = Bbs::generateBls12381G1KeyPair(seed, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(
        rt, "publicKey",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, bpk.publicKey));
    object.setProperty(
        rt, "secretKey",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, bpk.secretKey));
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object NativeBbsSignatures::generateBlindedBls12381G1KeyPair(
    jsi::Runtime &rt, const jsi::Object &options) {
  try {
    jsi::Object object = jsi::Object(rt);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object
NativeBbsSignatures::generateBls12381G2KeyPair(jsi::Runtime &rt,
                                               const jsi::Object &options) {
  try {
    ByteArray seed = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "seed"), true);

    ExternError *err = new ExternError();

    BlsKeyPair bpk = Bbs::generateBls12381G2KeyPair(seed, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(
        rt, "publicKey",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, bpk.publicKey));
    object.setProperty(
        rt, "secretKey",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, bpk.secretKey));
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object NativeBbsSignatures::generateBlindedBls12381G2KeyPair(
    jsi::Runtime &rt, const jsi::Object &options) {
  try {
    jsi::Object object = jsi::Object(rt);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object NativeBbsSignatures::bl12381toBbs(jsi::Runtime &rt,
                                              const jsi::Object &options) {
  try {
    jsi::Object object = jsi::Object(rt);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}
