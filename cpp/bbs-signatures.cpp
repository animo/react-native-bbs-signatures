#include "bbs-signatures.h"

// TODO: after every lib call we must handle the error
ByteBuffer Bbs::sign(ByteArray publicKey, ByteArray secretKey, std::vector<ByteArray> messages, ExternError *err) {
  uint64_t handle = ::bbs_sign_context_init(err);
  
  uint32_t length = (uint32_t)messages.size();
  for (int i = 0; i < length; i++) {
    ByteArray message = messages[i];
    ::bbs_sign_context_add_message_bytes(handle, message, err);
  }

  BlsKeyPair *bpk = new BlsKeyPair(publicKey, secretKey);
  BbsKey key = bpk->getBbsKey(length);

  ::bbs_sign_context_set_public_key(handle, key.publicKey, err);

  ::bbs_sign_context_set_secret_key(handle, secretKey, err);
  
  ByteBuffer *signature = new ByteBuffer();
  ::bbs_sign_context_finish(handle, signature, err);

  return *signature;
}

void Bbs::blsSign() {}

void Bbs::verify() {}

void Bbs::blsVerify() {}

void Bbs::createProof() {}

void Bbs::blsCreateProof() {}

void Bbs::verifyProof() {}

void Bbs::blsVerifyProof() {}

void Bbs::commitmentForBlindSignRequest() {}

void Bbs::verifyBlindSignRequest() {}

void Bbs::blindSign() {}

KeyPair Bbs::generateBls12381G1KeyPair(ByteArray seed, ExternError *err) {
  ByteBuffer *publicKey = new ByteBuffer();
  ByteBuffer *secretKey = new ByteBuffer();
    
  ::bls_generate_g1_key(seed, publicKey, secretKey, err);
  
  return KeyPair {*publicKey, *secretKey};
}

void Bbs::generateBls12381G2KeyPair() {}

void Bbs::generateBlindedBls12381G1KeyPair() {}

void Bbs::generateBlindedBls12381G2KeyPair() {}

void Bbs::bl12381toBbs() {}

