// class "interface" of the generated code. This has to be copied over from
// `../lib/cpp-generated/NativeModules.h`

#include "../lib/cpp-generated/NativeModules.h"
#include "NativeModules.h"
#include "TurboModuleUtils.h"
#include "bbs.h"
#include <ReactCommon/TurboModule.h>
#include <jsi/jsi.h>
#include <jsi/jsilib.h>

namespace facebook {
namespace react {

class NativeBbsSignatures : public BbsSignaturesCxxSpecJSI {
public:
  NativeBbsSignatures(std::shared_ptr<CallInvoker> jsInvoker);
  void bbs_string_free(jsi::Runtime &rt, const jsi::Object &options);
  void bbs_byte_buffer_free(jsi::Runtime &rt, const jsi::Object &options);
  void free_bbs_blind_commitment(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blind_signature_size(jsi::Runtime &rt);
  double bbs_blind_commitment_context_init(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_blind_commitment_context_add_message_string(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_blind_commitment_context_add_message_bytes(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_blind_commitment_context_add_message_prehashed(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blind_commitment_context_set_public_key(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blind_commitment_context_set_nonce_string(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blind_commitment_context_set_nonce_bytes(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blind_commitment_context_set_nonce_prehashed(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blind_commitment_context_finish(jsi::Runtime &rt, const jsi::Object &options);
  void free_bbs_blind_sign(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blinding_factor_size(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blind_sign_context_init(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blind_sign_context_add_message_string(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blind_sign_context_add_message_bytes(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blind_sign_context_add_message_prehashed(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blind_sign_context_set_public_key(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blind_sign_context_set_secret_key(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blind_sign_context_set_commitment(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_blind_sign_context_finish(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_unblind_signature(jsi::Runtime &rt, const jsi::Object &options);
  void free_create_proof(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_create_proof_context_size(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_create_proof_context_init(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_create_proof_context_add_proof_message_string(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_create_proof_context_add_proof_message_bytes(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_create_proof_context_add_proof_message_prehashed(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_create_proof_context_set_signature(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_create_proof_context_set_public_key(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_create_proof_context_set_nonce_string(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_create_proof_context_set_nonce_bytes(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_create_proof_context_set_nonce_prehashed(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_create_proof_context_finish(jsi::Runtime &rt,const jsi::Object &options);
  void free_bbs_sign(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_signature_size(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_sign_context_init(jsi::Runtime &rt);
  double bbs_sign_context_add_message_string(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_sign_context_add_message_bytes(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_sign_context_add_message_prehashed(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_sign_context_set_secret_key(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_sign_context_set_public_key(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_sign_context_finish(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_verify_context_init(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_verify_context_add_message_string(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_context_add_message_bytes(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_context_add_message_prehashed(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_context_set_public_key(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_context_set_signature(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_context_finish(jsi::Runtime &rt,const jsi::Object &options);
  void free_verify_proof(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_get_total_messages_count_for_proof(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_proof_context_init(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_proof_context_add_message_string(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_proof_context_add_message_bytes(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_proof_context_add_message_prehashed(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_proof_context_set_proof(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_proof_context_set_public_key(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_proof_context_set_nonce_string(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_proof_context_set_nonce_bytes(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_verify_proof_context_set_nonce_prehashed(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_proof_context_finish(jsi::Runtime &rt,const jsi::Object &options);
  void free_verify_sign_proof(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_verify_blind_commitment_context_init(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_blind_commitment_context_add_blinded(jsi::Runtime &rt,const jsi::Object &options);
  double bbs_verify_blind_commitment_context_set_public_key(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_verify_blind_commitment_context_set_nonce_string(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_verify_blind_commitment_context_set_nonce_bytes(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_verify_blind_commitment_context_set_nonce_prehashed(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_verify_blind_commitment_context_set_proof(jsi::Runtime &rt, const jsi::Object &options);
  double bbs_verify_blind_commitment_context_finish(jsi::Runtime &rt, const jsi::Object &options);
  double bls_secret_key_size(jsi::Runtime &rt, const jsi::Object &options);
  double bls_public_key_g2_size(jsi::Runtime &rt, const jsi::Object &options);
  double blinding_factor_size(jsi::Runtime &rt, const jsi::Object &options);
  double bls_public_key_g1_size(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object bls_generate_g2_key(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object bls_generate_g1_key(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object bls_generate_blinded_g2_key(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object bls_generate_blinded_g1_key(jsi::Runtime &rt,const jsi::Object &options);
  double bls_get_public_key(jsi::Runtime &rt, const jsi::Object &options);
  double bls_secret_key_to_bbs_key(jsi::Runtime &rt, const jsi::Object &options);
  jsi::Object bls_public_key_to_bbs_key(jsi::Runtime &rt, const jsi::Object &options);
};
}
}
