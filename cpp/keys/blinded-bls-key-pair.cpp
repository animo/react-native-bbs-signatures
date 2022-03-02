#include "blinded-bls-key-pair.h"

BlindedBlsKeyPair::BlindedBlsKeyPair(ByteArray pk, ByteArray sk, ByteArray bf) {
  publicKey = pk;
  secretKey = sk;
  blindingFactor = bf;
}

BlindedBlsKeyPair BlindedBlsKeyPair::generateBlindedG1(ByteArray seed, ExternError *err) {
  ByteBuffer *pk = new ByteBuffer();
  ByteBuffer *sk = new ByteBuffer();
  ByteBuffer *bf = new ByteBuffer();

  ::bls_generate_blinded_g1_key(seed, pk, sk, bf, err);
  handleExternError(err);

  ByteArray bapk = byteBufferToByteArray(*pk);
  ByteArray bask = byteBufferToByteArray(*sk);
  ByteArray babf = byteBufferToByteArray(*bf);
  return BlindedBlsKeyPair{bapk, bask, babf};
}

BlindedBlsKeyPair BlindedBlsKeyPair::generateBlindedG2(ByteArray seed, ExternError *err) {
  ByteBuffer *pk = new ByteBuffer();
  ByteBuffer *sk = new ByteBuffer();
  ByteBuffer *bf = new ByteBuffer();

  ::bls_generate_blinded_g2_key(seed, pk, sk, bf, err);
  handleExternError(err);

  ByteArray bapk = byteBufferToByteArray(*pk);
  ByteArray bask = byteBufferToByteArray(*sk);
  ByteArray babf = byteBufferToByteArray(*bf);
  return BlindedBlsKeyPair{bapk, bask, babf};
}
