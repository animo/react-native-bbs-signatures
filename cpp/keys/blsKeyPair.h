#pragma once

#include "../include/bbs.h"
#include "bbsKey.h"
#include "util.h"

class BlsKeyPair {
public:
  BlsKeyPair(ByteArray pk, ByteArray sk);
  BlsKeyPair(ByteArray pk);
  ByteArray publicKey;
  ByteArray secretKey;
  static BlsKeyPair generateG1(ByteArray seed, ExternError *err);
  static BlsKeyPair generateG2(ByteArray seed, ExternError *err);
  static BlsKeyPair fromSecretKey(ByteArray secretKey, ExternError *err);
  static uint32_t publicG1KeySize();
  static uint32_t publicG2KeySize();
  static uint32_t secretKeySize();
  bool isG1();
  bool isG2();
  BbsKey getBbsKey(uint32_t messageCount, ExternError *err);
};
