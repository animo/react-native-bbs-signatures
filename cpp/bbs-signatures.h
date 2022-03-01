#pragma once

#include "bbs.h"
#include <vector>
#include "bls-key-pair.h"

class Bbs {
public:
  static ByteBuffer sign(ByteArray publicKey, ByteArray secretKey, std::vector<ByteArray> messages, ExternError *err);
  static void blsSign();
  static void verify();
  static void blsVerify();
  static void createProof();
  static void blsCreateProof();
  static void verifyProof();
  static void blsVerifyProof();
  static void commitmentForBlindSignRequest();
  static void verifyBlindSignRequest();
  static void blindSign();
  static KeyPair generateBls12381G1KeyPair(ByteArray seed, ExternError *err);
  static void generateBlindedBls12381G1KeyPair();
  static void generateBls12381G2KeyPair();
  static void generateBlindedBls12381G2KeyPair();
  static void bl12381toBbs();
};
