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
    ByteArray signature = Bbs::sign(publicKey, secretKey, messages, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(
        rt, "signature",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, signature));
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

jsi::Object NativeBbsSignatures::createProof(jsi::Runtime &rt,
                                             const jsi::Object &options) {
  try {
    ByteArray nonce = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "nonce"));
    ByteArray publicKey = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "publicKey"));
    ByteArray signature = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "signature"));
    std::vector<ByteArray> messages =
        TurboModuleUtils::jsiToValue<std::vector<ByteArray>>(
            rt, options.getProperty(rt, "messages"));
    std::vector<int32_t> revealed =
        TurboModuleUtils::jsiToValue<std::vector<int32_t>>(
            rt, options.getProperty(rt, "revealed"));

    if (messages.size() != revealed.size()) {
      throw "Messages does not have the same size as revealed";
    }

    ExternError *err = new ExternError();
    ByteArray proof =
        Bbs::createProof(nonce, publicKey, signature, messages, revealed, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(rt, "proof",
                       TurboModuleUtils::byteArrayToArrayBuffer(rt, proof));
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object NativeBbsSignatures::verifyProof(jsi::Runtime &rt,
                                             const jsi::Object &options) {
  try {
    ByteArray nonce = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "nonce"));
    ByteArray proof = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "proof"));
    ByteArray publicKey = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "publicKey"));
    std::vector<ByteArray> messages =
        TurboModuleUtils::jsiToValue<std::vector<ByteArray>>(
            rt, options.getProperty(rt, "messages"));

    ExternError *err = new ExternError();
    bool verified = Bbs::verifyProof(nonce, publicKey, proof, messages, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(rt, "verified", verified);
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object
NativeBbsSignatures::commitmentForBlindSignRequest(jsi::Runtime &rt,
                                                   const jsi::Object &options) {
  try {
    ByteArray nonce = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "nonce"));
    ByteArray publicKey = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "publicKey"));
    std::vector<int32_t> hidden =
        TurboModuleUtils::jsiToValue<std::vector<int32_t>>(
            rt, options.getProperty(rt, "hidden"));
    std::vector<ByteArray> messages =
        TurboModuleUtils::jsiToValue<std::vector<ByteArray>>(
            rt, options.getProperty(rt, "messages"));

    ExternError *err = new ExternError();
    std::tuple<ByteArray, ByteArray, ByteArray> res =
        Bbs::commitmentForBlindSignRequest(nonce, publicKey, messages, hidden,
                                           err);

    jsi::Object object = jsi::Object(rt);
    // todo: it seems that outcontext is not supplied by the node wrapper and it
    // provides challangehash, proofofhiddenmessages
    object.setProperty(
        rt, "commitment",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, std::get<0>(res)));
    object.setProperty(
        rt, "outcontext",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, std::get<1>(res)));
    object.setProperty(
        rt, "blindingfactor",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, std::get<2>(res)));
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object
NativeBbsSignatures::verifyBlindSignRequest(jsi::Runtime &rt,
                                            const jsi::Object &options) {
  try {
    ByteArray nonce = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "nonce"));
    ByteArray publicKey = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "publickey"));
    ByteArray proofOfHiddenMessages = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "poofOfHiddenMessages"));
    ByteArray challangeHash = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "challangeHash"));
    ByteArray commitment = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "commitment"));
    std::vector<int32_t> blinded =
        TurboModuleUtils::jsiToValue<std::vector<int32_t>>(
            rt, options.getProperty(rt, "blinded"));

    ExternError *err = new ExternError();
    bool verified =
        Bbs::verifyBlindSignRequest(nonce, publicKey, proofOfHiddenMessages,
                                    challangeHash, commitment, blinded, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(rt, "verified", verified);
    return object;
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

jsi::Object NativeBbsSignatures::generateBlindedBls12381G1KeyPair(
    jsi::Runtime &rt, const jsi::Object &options) {
  try {
    ByteArray seed = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "seed"), true);

    ExternError *err = new ExternError();

    BlindedBlsKeyPair bbpk = Bbs::generateBlindedBls12381G1KeyPair(seed, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(
        rt, "publicKey",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, bbpk.publicKey));
    object.setProperty(
        rt, "secretKey",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, bbpk.secretKey));
    object.setProperty(
        rt, "blindingFactor",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, bbpk.blindingFactor));
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object NativeBbsSignatures::generateBlindedBls12381G2KeyPair(
    jsi::Runtime &rt, const jsi::Object &options) {
  try {
    ByteArray seed = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "seed"), true);

    ExternError *err = new ExternError();

    BlindedBlsKeyPair bbkp = Bbs::generateBlindedBls12381G2KeyPair(seed, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(
        rt, "publicKey",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, bbkp.publicKey));
    object.setProperty(
        rt, "secretKey",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, bbkp.secretKey));
    object.setProperty(
        rt, "blindingFactor",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, bbkp.blindingFactor));
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}

jsi::Object NativeBbsSignatures::bls12381toBbs(jsi::Runtime &rt,
                                               const jsi::Object &options) {
  try {
    uint32_t messageCount = TurboModuleUtils::jsiToValue<int32_t>(
        rt, options.getProperty(rt, "messageCount"));
    ByteArray publicKey = TurboModuleUtils::jsiToValue<ByteArray>(
        rt, options.getProperty(rt, "publicKey"));

    ExternError *err = new ExternError();
    BlsKeyPair blsKeyPair = BlsKeyPair{publicKey};
    BbsKey bbsKey = Bbs::bls12381toBbs(blsKeyPair, messageCount, err);

    jsi::Object object = jsi::Object(rt);
    object.setProperty(
        rt, "publicKey",
        TurboModuleUtils::byteArrayToArrayBuffer(rt, bbsKey.publicKey));
    return object;
  } catch (const char *e) {
    throw jsi::JSError(rt, e);
  }
}
