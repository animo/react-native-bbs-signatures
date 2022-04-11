#include "../../include/bbs.h"
#include "bbsSignatures.h"
#include "util.h"
#include <cassert>
#include <vector>

void testPublicG1KeySize() { assert(BlsKeyPair::publicG1KeySize() == 48); }

void testPublicG2KeySize() { assert(BlsKeyPair::publicG2KeySize() == 96); }

void testSecretKeySize() { assert(BlsKeyPair::secretKeySize() == 32); }

void testGenerateBls12381G2KeyPair() {
  ByteArray seed = ByteArray{0, 0};
  ExternError *err = new ExternError();
  BlsKeyPair blsKeyPair = bbs::generateBls12381G2KeyPair(seed, err);
  assert(blsKeyPair.isG2() == 1);
  assert(blsKeyPair.isG1() == 0);
}

void testGenerateBls12381G1KeyPair() {
  ByteArray seed = ByteArray{0, 0};
  ExternError *err = new ExternError();
  BlsKeyPair blsKeyPair = bbs::generateBls12381G1KeyPair(seed, err);
  assert(blsKeyPair.isG1() == 1);
  assert(blsKeyPair.isG2() == 0);
}

void testGenerateBlindedG1() {
  ByteArray seed = ByteArray{0, 0};
  ExternError *err = new ExternError();
  BlindedBlsKeyPair blindedBlsKeyPair =
      BlindedBlsKeyPair::generateBlindedG1(seed, err);
  assert(blindedBlsKeyPair.publicKey.length == BlsKeyPair::publicG1KeySize());
  assert(blindedBlsKeyPair.secretKey.length == BlsKeyPair::secretKeySize());
}

void testGenerateBlindedG2() {
  ByteArray seed = ByteArray{0, 0};
  ExternError *err = new ExternError();
  BlindedBlsKeyPair blindedBlsKeyPair =
      BlindedBlsKeyPair::generateBlindedG2(seed, err);
  assert(blindedBlsKeyPair.publicKey.length == BlsKeyPair::publicG2KeySize());
  assert(blindedBlsKeyPair.secretKey.length == BlsKeyPair::secretKeySize());
}

void testByteArrayToByteBuffer() {
  uint8_t data = 'a';
  ByteArray byteArray = ByteArray{10, &data};
  ByteBuffer byteBuffer = byteArrayToByteBuffer(byteArray);
  assert(byteBuffer.len == 10);
  assert(*byteBuffer.data == 'a');
}

void testByteBufferToByteArray() {
  uint8_t data = 'q';
  ByteBuffer byteBuffer = ByteBuffer{20, &data};
  ByteArray byteArray = byteBufferToByteArray(byteBuffer);
  assert(byteArray.length == 20);
  assert(*byteArray.data == 'q');
}

void testBls12381toBbs() {
  uint32_t messageCount = 1;
  ByteArray seed = ByteArray{0, 0};
  ExternError *err = new ExternError();
  BlsKeyPair blsKeyPair = bbs::generateBls12381G2KeyPair(seed, err);

  BbsKey bbsKey = bbs::bls12381toBbs(blsKeyPair, messageCount, err);

  assert(bbsKey.publicKey.length == 196);
  assert(bbsKey.messageCount == 1);
}

ByteArray testSign(ByteArray publicKey, ByteArray secretKey,
                   std::vector<ByteArray> messages, ExternError *err) {
  ByteArray signature = bbs::sign(publicKey, secretKey, messages, err);

  assert(signature.length == 112);

  return signature;
}

void testVerify(ByteArray publicKey, ByteArray signature,
                std::vector<ByteArray> messages, ExternError *err) {
  bool isVerified = bbs::verify(publicKey, signature, messages, err);

  assert(isVerified == true);
}

ByteArray testCreateProof(ByteArray nonce, ByteArray publicKey,
                          ByteArray signature, std::vector<ByteArray> messages,
                          std::vector<int32_t> revealed, ExternError *err) {
  ByteArray proof =
      bbs::createProof(nonce, publicKey, signature, messages, revealed, err);
  return proof;
}

void testVerifyProof(ByteArray nonce, ByteArray publicKey, ByteArray proof,
                     std::vector<ByteArray> messages, ExternError *err) {
  bool isVerified = bbs::verifyProof(nonce, publicKey, proof, messages, err);
  assert(isVerified == 1);
}

int main() {
  // --- standalone ---
  testPublicG1KeySize();
  testPublicG2KeySize();
  testSecretKeySize();

  testGenerateBls12381G1KeyPair();
  testGenerateBls12381G2KeyPair();

  testGenerateBlindedG1();
  testGenerateBlindedG2();

  testBls12381toBbs();

  testByteArrayToByteBuffer();
  testByteBufferToByteArray();

  // --- Whole flow ---
  try {
    // Mock data
    uint8_t data = 'q';
    ByteArray message = ByteArray{1, &data};
    std::vector<ByteArray> messages = {message, message, message};
    uint32_t messageCount = (uint32_t)messages.size();
    ByteArray seed = ByteArray{0, 0};
    ExternError *err = new ExternError();
    ByteArray nonce = ByteArray{1, &data};
    std::vector<int32_t> revealed = {0};

    // Generate a G2 bls keypair
    BlsKeyPair blsKeyPair = bbs::generateBls12381G2KeyPair(seed, err);
    BbsKey bbsKey = blsKeyPair.getBbsKey(messageCount, err);

    // Create a signature for the messages
    ByteArray signature =
        testSign(bbsKey.publicKey, blsKeyPair.secretKey, messages, err);
    assert(err->code == 0);

    // Verify the signature
    testVerify(bbsKey.publicKey, signature, messages, err);
    assert(err->code == 0);

    // Create a proof with the signature
    ByteArray proof = testCreateProof(nonce, bbsKey.publicKey, signature,
                                      messages, revealed, err);
    assert(err->code == 0);

    // Verify the proof with the messages
    testVerifyProof(nonce, bbsKey.publicKey, proof, {message}, err);
    assert(err->code == 0);
  } catch (const char *e) {
    printf("ERROR: %s\n", e);
    return 1;
  }

  return 0;
}
