#include "blsKeyPair.h"

BlsKeyPair::BlsKeyPair(ByteArray pk, ByteArray sk) {
  publicKey = pk;
  secretKey = sk;
}

BlsKeyPair::BlsKeyPair(ByteArray pk) {
  publicKey = pk;
  // Indicates optional
  secretKey = ByteArray{0, 0};
}

BlsKeyPair BlsKeyPair::generateG1(ByteArray seed, ExternError *err) {
  ByteBuffer *pk = new ByteBuffer();
  ByteBuffer *sk = new ByteBuffer();

  ::bls_generate_g1_key(seed, pk, sk, err);
  handleExternError(err);

  ByteArray bapk = byteBufferToByteArray(*pk);
  ByteArray bask = byteBufferToByteArray(*sk);
  return BlsKeyPair{bapk, bask};
}

BlsKeyPair BlsKeyPair::generateG2(ByteArray seed, ExternError *err) {
  ByteBuffer *pk = new ByteBuffer();
  ByteBuffer *sk = new ByteBuffer();

  ::bls_generate_g2_key(seed, pk, sk, err);
  handleExternError(err);

  ByteArray bapk = byteBufferToByteArray(*pk);
  ByteArray bask = byteBufferToByteArray(*sk);
  return BlsKeyPair{bapk, bask};
}

BlsKeyPair BlsKeyPair::fromSecretKey(ByteArray sk, ExternError *err) {
  ByteBuffer *pk = new ByteBuffer();

  ::bls_get_public_key(sk, pk, err);
  handleExternError(err);

  ByteArray bapk = byteBufferToByteArray(*pk);
  return BlsKeyPair{bapk, sk};
}

uint32_t BlsKeyPair::publicG1KeySize() { return ::bls_public_key_g1_size(); }

uint32_t BlsKeyPair::publicG2KeySize() { return ::bls_public_key_g2_size(); }

uint32_t BlsKeyPair::secretKeySize() { return ::bls_secret_key_size(); }

bool BlsKeyPair::isG1() { return publicKey.length == this->publicG1KeySize(); }

bool BlsKeyPair::isG2() { return publicKey.length == this->publicG2KeySize(); }

BbsKey BlsKeyPair::getBbsKey(uint32_t messageCount, ExternError *err) {
  ByteBuffer *pk = new ByteBuffer();
  if (secretKey.length) {
    ::bls_secret_key_to_bbs_key(secretKey, messageCount, pk, err);
    handleExternError(err);
  } else if (this->isG2()) {
    ::bls_public_key_to_bbs_key(publicKey, messageCount, pk, err);
    handleExternError(err);
  } else {
    throw "Key has incorrect length. A bbs key can only be generated from a "
          "secret key or a G2 public key.";
  }
  return BbsKey{byteBufferToByteArray(*pk), messageCount};
}
