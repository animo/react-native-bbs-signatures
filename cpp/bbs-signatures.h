#pragma once

#include "bbs-key.h"
#include "bbs.h"
#include "blinded-bls-key-pair.h"
#include "bls-key-pair.h"
#include <vector>

class Bbs {
public:
  static ByteBuffer sign(ByteArray publicKey, ByteArray secretKey,
                         std::vector<ByteArray> messages, ExternError *err);
  static void blsSign();
  static bool verify(ByteArray publicKey, ByteArray signature,
                     std::vector<ByteArray> messages, ExternError *err);
  static void blsVerify();
  static ByteArray createProof(ByteArray nonce, ByteArray publicKey,
                               ByteArray signature,
                               std::vector<ByteArray> messages,
                               std::vector<int32_t> revealed, ExternError *err);
  static void blsCreateProof();
  static bool verifyProof(ByteArray nonce, ByteArray publicKey, ByteArray proof,
                          std::vector<ByteArray> messages, ExternError *err);
  static void blsVerifyProof();
  static std::tuple<ByteArray, ByteArray, ByteArray>
  commitmentForBlindSignRequest(ByteArray nonce, ByteArray publicKey,
                                std::vector<ByteArray> messages,
                                std::vector<int32_t> hidden, ExternError *err);
  static bool verifyBlindSignRequest(ByteArray nonce, ByteArray publicKey,
                                     ByteArray proofOfHiddenMessages,
                                     ByteArray challangeHash,
                                     ByteArray commitment,
                                     std::vector<int32_t> blinded,
                                     ExternError *err);
  static void blindSign();
  static BlsKeyPair generateBls12381G1KeyPair(ByteArray seed, ExternError *err);
  static BlindedBlsKeyPair generateBlindedBls12381G1KeyPair(ByteArray seed, ExternError *err);
  static BlsKeyPair generateBls12381G2KeyPair(ByteArray seed, ExternError *err);
  static BlindedBlsKeyPair generateBlindedBls12381G2KeyPair(ByteArray seed, ExternError *err);
  static BbsKey bls12381toBbs(BlsKeyPair kp, uint32_t messageCount,
                             ExternError *err);
};
