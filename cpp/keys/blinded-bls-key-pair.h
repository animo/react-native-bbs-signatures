#pragma once

#include "bbs-key.h"
#include "bbs.h"
#include "bls-key-pair.h"
#include "util.h"

class BlindedBlsKeyPair {
public:
  BlindedBlsKeyPair(ByteArray pk, ByteArray sk, ByteArray blindingFactor);
  ByteArray publicKey;
  ByteArray secretKey;
  ByteArray blindingFactor;
  static BlindedBlsKeyPair generateBlindedG1(ByteArray seed, ExternError *err);
  static BlindedBlsKeyPair generateBlindedG2(ByteArray seed, ExternError *err);
  // TODO: what other methods do we have here?
};
