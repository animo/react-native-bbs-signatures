#pragma once

#include "bbs.h"
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
                               std::vector<int64_t> revealed, ExternError *err);
  static void blsCreateProof();
  static bool verifyProof(ByteArray nonce, ByteArray publicKey, ByteArray proof,
                          std::vector<ByteArray> messages, ExternError *err);
  static void blsVerifyProof();
  static void commitmentForBlindSignRequest();
  static void verifyBlindSignRequest();
  static void blindSign();
  static BlsKeyPair generateBls12381G1KeyPair(ByteArray seed, ExternError *err);
  static void generateBlindedBls12381G1KeyPair();
  static BlsKeyPair generateBls12381G2KeyPair(ByteArray seed, ExternError *err);
  static void generateBlindedBls12381G2KeyPair();
  static void bl12381toBbs();
};