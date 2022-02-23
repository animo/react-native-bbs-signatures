import type { TurboModule } from 'react-native-tscodegen-types'
import { TurboModuleRegistry } from 'react-native-tscodegen-types'
import type { int32_t, uint64_t } from './bbs'

// General interface for the package. Our generated cpp wrapper will be based on this
export interface BbsNativeBindings extends TurboModule {
  bbs_string_free(options: {}): void
  bbs_byte_buffer_free(options: {}): void
  free_bbs_blind_commitment(options: {}): void
  bbs_blind_signature_size(options: {}): int32_t
  bbs_blind_commitment_context_init(options: {}): uint64_t
  bbs_blind_commitment_context_add_message_string(options: {}): int32_t
  bbs_blind_commitment_context_add_message_bytes(options: {}): int32_t
  bbs_blind_commitment_context_add_message_prehashed(options: {}): int32_t
  bbs_blind_commitment_context_set_public_key(options: {}): int32_t
  bbs_blind_commitment_context_set_nonce_string(options: {}): int32_t
  bbs_blind_commitment_context_set_nonce_bytes(options: {}): int32_t
  bbs_blind_commitment_context_set_nonce_prehashed(options: {}): int32_t
  bbs_blind_commitment_context_finish(options: {}): int32_t
  free_bbs_blind_sign(options: {}): void
  bbs_blinding_factor_size(options: {}): int32_t
  bbs_blind_sign_context_init(options: {}): uint64_t
  bbs_blind_sign_context_add_message_string(options: {}): int32_t
  bbs_blind_sign_context_add_message_bytes(options: {}): int32_t
  bbs_blind_sign_context_add_message_prehashed(options: {}): int32_t
  bbs_blind_sign_context_set_public_key(options: {}): int32_t
  bbs_blind_sign_context_set_secret_key(options: {}): int32_t
  bbs_blind_sign_context_set_commitment(options: {}): int32_t
  bbs_blind_sign_context_finish(options: {}): int32_t
  bbs_unblind_signature(options: {}): int32_t
  free_create_proof(options: {}): void
  bbs_create_proof_context_size(options: {}): int32_t
  bbs_create_proof_context_init(options: {}): uint64_t
  bbs_create_proof_context_add_proof_message_string(options: {}): int32_t
  bbs_create_proof_context_add_proof_message_bytes(options: {}): int32_t
  bbs_create_proof_context_add_proof_message_prehashed(options: {}): int32_t
  bbs_create_proof_context_set_signature(options: {}): int32_t
  bbs_create_proof_context_set_public_key(options: {}): int32_t
  bbs_create_proof_context_set_nonce_string(options: {}): int32_t
  bbs_create_proof_context_set_nonce_bytes(options: {}): int32_t
  bbs_create_proof_context_set_nonce_prehashed(options: {}): int32_t
  bbs_create_proof_context_finish(options: {}): int32_t
  free_bbs_sign(options: {}): void
  bbs_signature_size(options: {}): int32_t
  bbs_sign_context_init(options: {}): uint64_t
  bbs_sign_context_add_message_string(options: {}): int32_t
  bbs_sign_context_add_message_bytes(options: {}): int32_t
  bbs_sign_context_add_message_prehashed(options: {}): int32_t
  bbs_sign_context_set_secret_key(options: {}): int32_t
  bbs_sign_context_set_public_key(options: {}): int32_t
  bbs_sign_context_finish(options: {}): int32_t
  bbs_verify_context_init(options: {}): uint64_t
  bbs_verify_context_add_message_string(options: {}): int32_t
  bbs_verify_context_add_message_bytes(options: {}): int32_t
  bbs_verify_context_add_message_prehashed(options: {}): int32_t
  bbs_verify_context_set_public_key(options: {}): int32_t
  bbs_verify_context_set_signature(options: {}): int32_t
  bbs_verify_context_finish(options: {}): int32_t
  free_verify_proof(options: {}): void
  bbs_get_total_messages_count_for_proof(options: {}): int32_t
  bbs_verify_proof_context_init(options: {}): uint64_t
  bbs_verify_proof_context_add_message_string(options: {}): int32_t
  bbs_verify_proof_context_add_message_bytes(options: {}): int32_t
  bbs_verify_proof_context_add_message_prehashed(options: {}): int32_t
  bbs_verify_proof_context_set_proof(options: {}): int32_t
  bbs_verify_proof_context_set_public_key(options: {}): int32_t
  bbs_verify_proof_context_set_nonce_string(options: {}): int32_t
  bbs_verify_proof_context_set_nonce_bytes(options: {}): int32_t
  bbs_verify_proof_context_set_nonce_prehashed(options: {}): int32_t
  bbs_verify_proof_context_finish(options: {}): int32_t
  free_verify_sign_proof(options: {}): void
  bbs_verify_blind_commitment_context_init(options: {}): uint64_t
  bbs_verify_blind_commitment_context_add_blinded(options: {}): int32_t
  bbs_verify_blind_commitment_context_set_public_key(options: {}): int32_t
  bbs_verify_blind_commitment_context_set_nonce_string(options: {}): int32_t
  bbs_verify_blind_commitment_context_set_nonce_bytes(options: {}): int32_t
  bbs_verify_blind_commitment_context_set_nonce_prehashed(options: {}): int32_t
  bbs_verify_blind_commitment_context_set_proof(options: {}): int32_t
  bbs_verify_blind_commitment_context_finish(options: {}): int32_t
  bls_secret_key_size(options: {}): int32_t
  bls_public_key_g2_size(options: {}): int32_t
  blinding_factor_size(options: {}): int32_t
  bls_public_key_g1_size(options: {}): int32_t
  bls_generate_g2_key(options: {}): int32_t
  bls_generate_g1_key(options: {}): int32_t
  bls_generate_blinded_g2_key(options: {}): int32_t
  bls_generate_blinded_g1_key(options: {}): int32_t
  bls_get_public_key(options: {}): int32_t
  bls_secret_key_to_bbs_key(options: {}): int32_t
  bls_public_key_to_bbs_key(options: {}): int32_t
}

// We MUST export this according to tscodegen. We are ignoring it however.
export default TurboModuleRegistry.getEnforcing<BbsNativeBindings>('BbsSignatures')
