#pragma once

#include "bbs-key.h"
#include "bbs.h"
#include "util.h"

typedef std::pair<ByteBuffer, ByteBuffer> KeyPair;

class BlsKeyPair {
public:
BlsKeyPair(ByteArray pk, ByteArray sk);
ByteArray publicKey;
ByteArray secretKey;
// "Constructors"
static BlsKeyPair generateG1(ByteArray seed);
static BlsKeyPair generateG2(ByteArray seed);
static BlsKeyPair fromSecretKey(ByteArray secretKey);
//
static uint32_t publicG1KeySize();
static uint32_t publicG2KeySize();
static uint32_t secretKeySize();
bool isG1();
bool isG2();
BbsKey getBbsKey(uint32_t messageCount);
};
