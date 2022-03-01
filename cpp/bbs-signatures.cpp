#include "bbs-signatures.h"

ByteBuffer Bbs::sign(ByteArray publicKey, ByteArray secretKey,
                     std::vector<ByteArray> messages, ExternError *err) {
  uint32_t length = (uint32_t)messages.size();
  BlsKeyPair *bpk = new BlsKeyPair(publicKey, secretKey);
  BbsKey key = bpk->getBbsKey(length, err);
  handleExternError(err);

  uint64_t handle = ::bbs_sign_context_init(err);
  handleExternError(err);

  ::bbs_sign_context_set_public_key(handle, key.publicKey, err);
  handleExternError(err);

  ::bbs_sign_context_set_secret_key(handle, secretKey, err);
  handleExternError(err);

  for (int i = 0; i < length; i++) {
    ByteArray message = messages[i];
    ::bbs_sign_context_add_message_bytes(handle, message, err);
    handleExternError(err);
  }

  ByteBuffer *signature = new ByteBuffer();
  ::bbs_sign_context_finish(handle, signature, err);
  handleExternError(err);

  return *signature;
}

void Bbs::blsSign() {}

bool Bbs::verify(ByteArray publicKey, ByteArray signature,
                 std::vector<ByteArray> messages, ExternError *err) {

  uint32_t length = (uint32_t)messages.size();
  BlsKeyPair *bpk = new BlsKeyPair(publicKey);
  BbsKey key = bpk->getBbsKey(length, err);
  handleExternError(err);

  uint64_t handle = ::bbs_verify_context_init(err);
  handleExternError(err);

  ::bbs_verify_context_set_public_key(handle, key.publicKey, err);
  handleExternError(err);

  ::bbs_verify_context_set_signature(handle, signature, err);
  handleExternError(err);

  for (int i = 0; i < length; i++) {
    ByteArray message = messages[i];
    ::bbs_verify_context_add_message_bytes(handle, message, err);
    handleExternError(err);
  }

  int32_t res = ::bbs_verify_context_finish(handle, err);
  handleExternError(err);

  return res == 0;
}

void Bbs::blsVerify() {}

ByteArray Bbs::createProof(ByteArray nonce, ByteArray publicKey,
                           ByteArray signature, std::vector<ByteArray> messages,
                           std::vector<int64_t> revealed, ExternError *err) {
  uint32_t length = (uint32_t)messages.size();
  BlsKeyPair *bpk = new BlsKeyPair(publicKey);
  BbsKey key = bpk->getBbsKey(length, err);
  handleExternError(err);

  uint64_t handle = ::bbs_create_proof_context_init(err);
  handleExternError(err);

  for (int i = 0; i < length; i++) {
    // TODO: message length MUST equal revealed length?
    ByteArray message = messages[i];
    ProofMessageType xtype = static_cast<ProofMessageType>(revealed[i]);
    // TODO: how do we get the blinding factor?
    ByteArray blindingFactor = ByteArray{0, 0};
    ::bbs_create_proof_context_add_proof_message_bytes(handle, message, xtype,
                                                       blindingFactor, err);
    handleExternError(err);
  }

  ::bbs_create_proof_context_set_nonce_bytes(handle, nonce, err);
  handleExternError(err);

  ::bbs_create_proof_context_set_public_key(handle, key.publicKey, err);
  handleExternError(err);

  ::bbs_create_proof_context_set_signature(handle, signature, err);
  handleExternError(err);

  ByteBuffer *proof = new ByteBuffer();
  ::bbs_create_proof_context_finish(handle, proof, err);
  handleExternError(err);

  return byteBufferToByteArray(*proof);
}

void Bbs::blsCreateProof() {}

bool Bbs::verifyProof(ByteArray nonce, ByteArray publicKey, ByteArray proof,
                      std::vector<ByteArray> messages, ExternError *err) {
  uint32_t length = (uint32_t)messages.size();
  BlsKeyPair *bpk = new BlsKeyPair(publicKey);
  BbsKey key = bpk->getBbsKey(length, err);
  handleExternError(err);

  uint64_t handle = ::bbs_verify_proof_context_init(err);
  handleExternError(err);

  ::bbs_verify_proof_context_set_public_key(handle, key.publicKey, err);
  handleExternError(err);

  ::bbs_verify_proof_context_set_nonce_bytes(handle, nonce, err);
  handleExternError(err);

  ::bbs_verify_proof_context_set_proof(handle, proof, err);
  handleExternError(err);

  for (int i = 0; i < length; i++) {
    ByteArray message = messages[i];
    ::bbs_verify_proof_context_add_message_bytes(handle, message, err);
    handleExternError(err);
  }

  int32_t res = ::bbs_verify_proof_context_finish(handle, err);
  handleExternError(err);

  return res == 0;
}

void Bbs::blsVerifyProof() {}

void Bbs::commitmentForBlindSignRequest() {}

void Bbs::verifyBlindSignRequest() {}

void Bbs::blindSign() {}

BlsKeyPair Bbs::generateBls12381G1KeyPair(ByteArray seed, ExternError *err) {
  return BlsKeyPair::generateG1(seed, err);
}

BlsKeyPair Bbs::generateBls12381G2KeyPair(ByteArray seed, ExternError *err) {
  return BlsKeyPair::generateG2(seed, err);
}

void Bbs::generateBlindedBls12381G1KeyPair() {}

void Bbs::generateBlindedBls12381G2KeyPair() {}

void Bbs::bl12381toBbs() {}
