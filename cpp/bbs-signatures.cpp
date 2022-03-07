#include "bbs-signatures.h"

ByteArray Bbs::sign(ByteArray publicKey, ByteArray secretKey,
                     std::vector<ByteArray> messages, ExternError *err) {
  uint32_t length = (uint32_t)messages.size();

  uint64_t handle = ::bbs_sign_context_init(err);
  handleExternError(err);

  ::bbs_sign_context_set_public_key(handle, publicKey, err);
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

  return byteBufferToByteArray(*signature);
}

bool Bbs::verify(ByteArray publicKey, ByteArray signature,
                 std::vector<ByteArray> messages, ExternError *err) {

  uint32_t length = (uint32_t)messages.size();

  uint64_t handle = ::bbs_verify_context_init(err);
  handleExternError(err);

  ::bbs_verify_context_set_public_key(handle, publicKey, err);
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

ByteArray Bbs::createProof(ByteArray nonce, ByteArray publicKey,
                           ByteArray signature, std::vector<ByteArray> messages,
                           std::vector<int32_t> revealed, ExternError *err) {
  uint32_t length = (uint32_t)messages.size();

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

  ::bbs_create_proof_context_set_public_key(handle, publicKey, err);
  handleExternError(err);

  ::bbs_create_proof_context_set_signature(handle, signature, err);
  handleExternError(err);

  ByteBuffer *proof = new ByteBuffer();
  ::bbs_create_proof_context_finish(handle, proof, err);
  handleExternError(err);

  return byteBufferToByteArray(*proof);
}

bool Bbs::verifyProof(ByteArray nonce, ByteArray publicKey, ByteArray proof,
                      std::vector<ByteArray> messages, ExternError *err) {
  uint32_t length = (uint32_t)messages.size();

  uint64_t handle = ::bbs_verify_proof_context_init(err);
  handleExternError(err);

  ::bbs_verify_proof_context_set_public_key(handle, publicKey, err);
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

std::tuple<ByteArray, ByteArray, ByteArray> Bbs::commitmentForBlindSignRequest(
    ByteArray nonce, ByteArray publicKey, std::vector<ByteArray> messages,
    std::vector<int32_t> hidden, ExternError *err) {
  uint32_t length = (uint32_t)messages.size();

  uint64_t handle = ::bbs_blind_commitment_context_init(err);
  handleExternError(err);

  for (int i = 0; i < length; i++) {
    ByteArray message = messages[i];
    uint32_t index = hidden[i];
    ::bbs_blind_commitment_context_add_message_bytes(handle, index, message,
                                                     err);
    handleExternError(err);
  }

  ::bbs_blind_commitment_context_set_nonce_bytes(handle, nonce, err);
  handleExternError(err);

  ::bbs_blind_commitment_context_set_public_key(handle, publicKey, err);
  handleExternError(err);

  ByteBuffer *commitment = new ByteBuffer();
  ByteBuffer *out_context = new ByteBuffer();
  ByteBuffer *blinding_factor = new ByteBuffer();
  ::bbs_blind_commitment_context_finish(handle, commitment, out_context,
                                        blinding_factor, err);
  handleExternError(err);

  return std::make_tuple(byteBufferToByteArray(*commitment),
                         byteBufferToByteArray(*out_context),
                         byteBufferToByteArray(*blinding_factor));
}

bool Bbs::verifyBlindSignRequest(ByteArray nonce, ByteArray publicKey,
                                 ByteArray proofOfHiddenMessages,
                                 ByteArray challangeHash, ByteArray commitment,
                                 std::vector<int32_t> blinded,
                                 ExternError *err) {
  uint64_t handle = ::bbs_verify_blind_commitment_context_init(err);
  handleExternError(err);

  ::bbs_verify_blind_commitment_context_set_nonce_bytes(handle, nonce, err);
  handleExternError(err);

  ::bbs_verify_blind_commitment_context_set_proof(handle, proofOfHiddenMessages,
                                                  err);
  handleExternError(err);

  ::bbs_verify_blind_commitment_context_set_public_key(handle, publicKey, err);
  handleExternError(err);

  uint32_t length = (uint32_t)blinded.size();
  for (int i = 0; i < length; i++) {
    // TODO: do we just need to give the `i` or `blinded[i]`?
    int32_t index = blinded[i];
    ::bbs_verify_blind_commitment_context_add_blinded(handle, index, err);
    handleExternError(err);
  }

  int32_t res = ::bbs_verify_blind_commitment_context_finish(handle, err);
  handleExternError(err);

  return res == 0;
}

BlsKeyPair Bbs::generateBls12381G1KeyPair(ByteArray seed, ExternError *err) {
  return BlsKeyPair::generateG1(seed, err);
}

BlsKeyPair Bbs::generateBls12381G2KeyPair(ByteArray seed, ExternError *err) {
  return BlsKeyPair::generateG2(seed, err);
}

BlindedBlsKeyPair Bbs::generateBlindedBls12381G1KeyPair(ByteArray seed,
                                                        ExternError *err) {
  return BlindedBlsKeyPair::generateBlindedG1(seed, err);
}

BlindedBlsKeyPair Bbs::generateBlindedBls12381G2KeyPair(ByteArray seed,
                                                        ExternError *err) {
  return BlindedBlsKeyPair::generateBlindedG2(seed, err);
}

BbsKey Bbs::bls12381toBbs(BlsKeyPair kp, uint32_t messageCount,
                          ExternError *err) {
  return kp.getBbsKey(messageCount, err);
}
