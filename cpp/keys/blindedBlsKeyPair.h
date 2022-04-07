#pragma once

#include "bbsKey.h"
#include "../include/bbs.h"
#include "blsKeyPair.h"
#include "util.h"

class BlindedBlsKeyPair {
public:
  BlindedBlsKeyPair(ByteArray pk, ByteArray sk, ByteArray blindingFactor);
  ByteArray publicKey;
  ByteArray secretKey;
  ByteArray blindingFactor;
  static BlindedBlsKeyPair generateBlindedG1(ByteArray seed, ExternError *err);
  static BlindedBlsKeyPair generateBlindedG2(ByteArray seed, ExternError *err);
};
