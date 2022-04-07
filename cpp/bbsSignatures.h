#pragma once

#include "include/bbs.h"
#include "keys/bbsKey.h"
#include "keys/blindedBlsKeyPair.h"
#include "keys/blsKeyPair.h"
#include <vector>

namespace bbs {

ByteArray sign(ByteArray publicKey, ByteArray secretKey, std::vector<ByteArray> messages, ExternError *err);

bool verify(ByteArray publicKey, ByteArray signature, std::vector<ByteArray> messages, ExternError *err);

ByteArray createProof(ByteArray nonce, ByteArray publicKey,
                               ByteArray signature,
                               std::vector<ByteArray> messages,
                               std::vector<int32_t> revealed, ExternError *err);

bool verifyProof(ByteArray nonce, ByteArray publicKey, ByteArray proof,
                          std::vector<ByteArray> messages, ExternError *err);

BlsKeyPair generateBls12381G1KeyPair(ByteArray seed, ExternError *err);

BlsKeyPair generateBls12381G2KeyPair(ByteArray seed, ExternError *err);

BbsKey bls12381toBbs(BlsKeyPair kp, uint32_t messageCount, ExternError *err);

}
