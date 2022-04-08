#include "bbsSignatures.h"

#include <algorithm>

namespace bbs {

ByteArray sign(ByteArray publicKey, ByteArray secretKey,
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

bool verify(ByteArray publicKey, ByteArray signature,
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

ByteArray createProof(ByteArray nonce, ByteArray publicKey, ByteArray signature,
                      std::vector<ByteArray> messages,
                      std::vector<int32_t> revealed, ExternError *err) {
  uint32_t messagesLength = (uint32_t)messages.size();
  uint32_t revealedLength = (uint32_t)revealed.size();

  if (revealedLength > messagesLength) {
    throw "Array of revealed messages is longer than the array of messages";
  }

  uint64_t handle = ::bbs_create_proof_context_init(err);
  handleExternError(err);

  std::vector<std::tuple<ByteArray, int32_t>> messagesWithType;
  for (int i = 0; i < messagesLength; i++) {
    bool shouldBeRevealed =
        std::find(revealed.begin(), revealed.end(), i) != revealed.end();
    int32_t type = shouldBeRevealed ? 1 : 2;

    ProofMessageType xtype = static_cast<ProofMessageType>(type);
    ByteArray message = messages[i];

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

bool verifyProof(ByteArray nonce, ByteArray publicKey, ByteArray proof,
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

BlsKeyPair generateBls12381G1KeyPair(ByteArray seed, ExternError *err) {
  return BlsKeyPair::generateG1(seed, err);
}

BlsKeyPair generateBls12381G2KeyPair(ByteArray seed, ExternError *err) {
  return BlsKeyPair::generateG2(seed, err);
}

BbsKey bls12381toBbs(BlsKeyPair kp, uint32_t messageCount, ExternError *err) {
  return kp.getBbsKey(messageCount, err);
}

} // namespace bbs
