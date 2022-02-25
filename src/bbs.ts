import type { BbsKeyPair, BlindedBlsKeyPair, BlsKeyPair } from './types'

export type int32_t = number
export type uint64_t = number
export type uint32_t = number
export type FfiStr = string

export type ByteBuffer = {
  a: any
}

export type ByteArray = {
  a: any
}

// TODO: Camelcase
type bbs_string_free_options = { s: string }
type bbs_byte_buffer_free_options = { v: ByteBuffer }
type free_bbs_blind_commitment_options = { v: uint64_t }
type bbs_blind_commitment_context_init_options = {}
type bbs_blind_commitment_context_add_message_string_options = { index: uint32_t; message: FfiStr }
type bbs_blind_commitment_context_add_message_bytes_options = { index: uint32_t; message: ByteArray }
type bbs_blind_commitment_context_add_message_prehashed_options = { index: uint32_t; message: ByteArray }
type bbs_blind_commitment_context_set_public_key_options = { value: ByteArray }
type bbs_blind_commitment_context_set_nonce_string_options = { message: FfiStr }
type bbs_blind_commitment_context_set_nonce_bytes_options = { value: ByteArray }
type bbs_blind_commitment_context_set_nonce_prehashed_options = { value: ByteArray }
type bbs_blind_commitment_context_finish_options = {}
type free_bbs_blind_sign_options = {}
type bbs_blinding_factor_size_options = {}
type bbs_blind_sign_context_init_options = {}
type bbs_blind_sign_context_add_message_string_options = {}
type bbs_blind_sign_context_add_message_bytes_options = {}
type bbs_blind_sign_context_add_message_prehashed_options = {}
type bbs_blind_sign_context_set_public_key_options = {}
type bbs_blind_sign_context_set_secret_key_options = {}
type bbs_blind_sign_context_set_commitment_options = {}
type bbs_blind_sign_context_finish_options = {}
type bbs_unblind_signature_options = {}
type free_create_proof_options = {}
type bbs_create_proof_context_size_options = {}
type bbs_create_proof_context_init_options = {}
type bbs_create_proof_context_add_proof_message_string_options = {}
type bbs_create_proof_context_add_proof_message_bytes_options = {}
type bbs_create_proof_context_add_proof_message_prehashed_options = {}
type bbs_create_proof_context_set_signature_options = {}
type bbs_create_proof_context_set_public_key_options = {}
type bbs_create_proof_context_set_nonce_string_options = {}
type bbs_create_proof_context_set_nonce_bytes_options = {}
type bbs_create_proof_context_set_nonce_prehashed_options = {}
type bbs_create_proof_context_finish_options = {}
type free_bbs_sign_options = {}
type bbs_signature_size_options = {}
type bbs_sign_context_add_message_string_options = { handle: number; message: string }
type bbs_sign_context_add_message_bytes_options = { handle: number; message: ArrayBuffer }
type bbs_sign_context_add_message_prehashed_options = {}
type bbs_sign_context_set_secret_key_options = { handle: number; secretKey: ArrayBuffer }
type bbs_sign_context_set_public_key_options = { handle: number; publicKey: ArrayBuffer }
type bbs_sign_context_finish_options = { handle: number }
type bbs_verify_context_init_options = {}
type bbs_verify_context_add_message_string_options = {}
type bbs_verify_context_add_message_bytes_options = {}
type bbs_verify_context_add_message_prehashed_options = {}
type bbs_verify_context_set_public_key_options = {}
type bbs_verify_context_set_signature_options = {}
type bbs_verify_context_finish_options = {}
type free_verify_proof_options = {}
type bbs_get_total_messages_count_for_proof_options = {}
type bbs_verify_proof_context_init_options = {}
type bbs_verify_proof_context_add_message_string_options = {}
type bbs_verify_proof_context_add_message_bytes_options = {}
type bbs_verify_proof_context_add_message_prehashed_options = {}
type bbs_verify_proof_context_set_proof_options = {}
type bbs_verify_proof_context_set_public_key_options = {}
type bbs_verify_proof_context_set_nonce_string_options = {}
type bbs_verify_proof_context_set_nonce_bytes_options = {}
type bbs_verify_proof_context_set_nonce_prehashed_options = {}
type bbs_verify_proof_context_finish_options = {}
type free_verify_sign_proof_options = {}
type bbs_verify_blind_commitment_context_init_options = {}
type bbs_verify_blind_commitment_context_add_blinded_options = {}
type bbs_verify_blind_commitment_context_set_public_key_options = {}
type bbs_verify_blind_commitment_context_set_nonce_string_options = {}
type bbs_verify_blind_commitment_context_set_nonce_bytes_options = {}
type bbs_verify_blind_commitment_context_set_nonce_prehashed_options = {}
type bbs_verify_blind_commitment_context_set_proof_options = {}
type bbs_verify_blind_commitment_context_finish_options = {}
type bls_secret_key_size_options = {}
type bls_public_key_g2_size_options = {}
type blinding_factor_size_options = {}
type bls_public_key_g1_size_options = {}
type bls_generate_g2_key_options = {}
type bls_generate_g1_key_options = {}
type bls_generate_blinded_g2_key_options = {}
type bls_generate_blinded_g1_key_options = {}
type bls_get_public_key_options = {}
type bls_secret_key_to_bbs_key_options = {}
type bls_public_key_to_bbs_key_options = { publicKey: ArrayBuffer; messageCount: number }

export interface Bbs {
  bbs_string_free(options: bbs_string_free_options): void
  bbs_byte_buffer_free(options: bbs_byte_buffer_free_options): void
  free_bbs_blind_commitment(options: free_bbs_blind_commitment_options): void
  bbs_blind_signature_size(): int32_t
  bbs_blind_commitment_context_init(options: bbs_blind_commitment_context_init_options): uint64_t
  bbs_blind_commitment_context_add_message_string(
    options: bbs_blind_commitment_context_add_message_string_options
  ): int32_t
  bbs_blind_commitment_context_add_message_bytes(
    options: bbs_blind_commitment_context_add_message_bytes_options
  ): int32_t
  bbs_blind_commitment_context_add_message_prehashed(
    options: bbs_blind_commitment_context_add_message_prehashed_options
  ): int32_t
  bbs_blind_commitment_context_set_public_key(options: bbs_blind_commitment_context_set_public_key_options): int32_t
  bbs_blind_commitment_context_set_nonce_string(options: bbs_blind_commitment_context_set_nonce_string_options): int32_t
  bbs_blind_commitment_context_set_nonce_bytes(options: bbs_blind_commitment_context_set_nonce_bytes_options): int32_t
  bbs_blind_commitment_context_set_nonce_prehashed(
    options: bbs_blind_commitment_context_set_nonce_prehashed_options
  ): int32_t
  bbs_blind_commitment_context_finish(options: bbs_blind_commitment_context_finish_options): int32_t
  free_bbs_blind_sign(options: free_bbs_blind_sign_options): void
  bbs_blinding_factor_size(options: bbs_blinding_factor_size_options): int32_t
  bbs_blind_sign_context_init(options: bbs_blind_sign_context_init_options): uint64_t
  bbs_blind_sign_context_add_message_string(options: bbs_blind_sign_context_add_message_string_options): int32_t
  bbs_blind_sign_context_add_message_bytes(options: bbs_blind_sign_context_add_message_bytes_options): int32_t
  bbs_blind_sign_context_add_message_prehashed(options: bbs_blind_sign_context_add_message_prehashed_options): int32_t
  bbs_blind_sign_context_set_public_key(options: bbs_blind_sign_context_set_public_key_options): int32_t
  bbs_blind_sign_context_set_secret_key(options: bbs_blind_sign_context_set_secret_key_options): int32_t
  bbs_blind_sign_context_set_commitment(options: bbs_blind_sign_context_set_commitment_options): int32_t
  bbs_blind_sign_context_finish(options: bbs_blind_sign_context_finish_options): int32_t
  bbs_unblind_signature(options: bbs_unblind_signature_options): int32_t
  free_create_proof(options: free_create_proof_options): void
  bbs_create_proof_context_size(options: bbs_create_proof_context_size_options): int32_t
  bbs_create_proof_context_init(options: bbs_create_proof_context_init_options): uint64_t
  bbs_create_proof_context_add_proof_message_string(
    options: bbs_create_proof_context_add_proof_message_string_options
  ): int32_t
  bbs_create_proof_context_add_proof_message_bytes(
    options: bbs_create_proof_context_add_proof_message_bytes_options
  ): int32_t
  bbs_create_proof_context_add_proof_message_prehashed(
    options: bbs_create_proof_context_add_proof_message_prehashed_options
  ): int32_t
  bbs_create_proof_context_set_signature(options: bbs_create_proof_context_set_signature_options): int32_t
  bbs_create_proof_context_set_public_key(options: bbs_create_proof_context_set_public_key_options): int32_t
  bbs_create_proof_context_set_nonce_string(options: bbs_create_proof_context_set_nonce_string_options): int32_t
  bbs_create_proof_context_set_nonce_bytes(options: bbs_create_proof_context_set_nonce_bytes_options): int32_t
  bbs_create_proof_context_set_nonce_prehashed(options: bbs_create_proof_context_set_nonce_prehashed_options): int32_t
  bbs_create_proof_context_finish(options: bbs_create_proof_context_finish_options): int32_t
  free_bbs_sign(options: free_bbs_sign_options): void
  bbs_signature_size(options: bbs_signature_size_options): int32_t
  bbs_sign_context_init(): uint64_t
  bbs_sign_context_add_message_string(options: bbs_sign_context_add_message_string_options): int32_t
  bbs_sign_context_add_message_bytes(options: bbs_sign_context_add_message_bytes_options): int32_t
  bbs_sign_context_add_message_prehashed(options: bbs_sign_context_add_message_prehashed_options): int32_t
  bbs_sign_context_set_secret_key(options: bbs_sign_context_set_secret_key_options): int32_t
  bbs_sign_context_set_public_key(options: bbs_sign_context_set_public_key_options): int32_t
  bbs_sign_context_finish(options: bbs_sign_context_finish_options): { signature: Uint8Array }
  bbs_verify_context_init(options: bbs_verify_context_init_options): uint64_t
  bbs_verify_context_add_message_string(options: bbs_verify_context_add_message_string_options): int32_t
  bbs_verify_context_add_message_bytes(options: bbs_verify_context_add_message_bytes_options): int32_t
  bbs_verify_context_add_message_prehashed(options: bbs_verify_context_add_message_prehashed_options): int32_t
  bbs_verify_context_set_public_key(options: bbs_verify_context_set_public_key_options): int32_t
  bbs_verify_context_set_signature(options: bbs_verify_context_set_signature_options): int32_t
  bbs_verify_context_finish(options: bbs_verify_context_finish_options): int32_t
  free_verify_proof(options: free_verify_proof_options): void
  bbs_get_total_messages_count_for_proof(options: bbs_get_total_messages_count_for_proof_options): int32_t
  bbs_verify_proof_context_init(options: bbs_verify_proof_context_init_options): uint64_t
  bbs_verify_proof_context_add_message_string(options: bbs_verify_proof_context_add_message_string_options): int32_t
  bbs_verify_proof_context_add_message_bytes(options: bbs_verify_proof_context_add_message_bytes_options): int32_t
  bbs_verify_proof_context_add_message_prehashed(
    options: bbs_verify_proof_context_add_message_prehashed_options
  ): int32_t
  bbs_verify_proof_context_set_proof(options: bbs_verify_proof_context_set_proof_options): int32_t
  bbs_verify_proof_context_set_public_key(options: bbs_verify_proof_context_set_public_key_options): int32_t
  bbs_verify_proof_context_set_nonce_string(options: bbs_verify_proof_context_set_nonce_string_options): int32_t
  bbs_verify_proof_context_set_nonce_bytes(options: bbs_verify_proof_context_set_nonce_bytes_options): int32_t
  bbs_verify_proof_context_set_nonce_prehashed(options: bbs_verify_proof_context_set_nonce_prehashed_options): int32_t
  bbs_verify_proof_context_finish(options: bbs_verify_proof_context_finish_options): int32_t
  free_verify_sign_proof(options: free_verify_sign_proof_options): void
  bbs_verify_blind_commitment_context_init(options: bbs_verify_blind_commitment_context_init_options): uint64_t
  bbs_verify_blind_commitment_context_add_blinded(
    options: bbs_verify_blind_commitment_context_add_blinded_options
  ): int32_t
  bbs_verify_blind_commitment_context_set_public_key(
    options: bbs_verify_blind_commitment_context_set_public_key_options
  ): int32_t
  bbs_verify_blind_commitment_context_set_nonce_string(
    options: bbs_verify_blind_commitment_context_set_nonce_string_options
  ): int32_t
  bbs_verify_blind_commitment_context_set_nonce_bytes(
    options: bbs_verify_blind_commitment_context_set_nonce_bytes_options
  ): int32_t
  bbs_verify_blind_commitment_context_set_nonce_prehashed(
    options: bbs_verify_blind_commitment_context_set_nonce_prehashed_options
  ): int32_t
  bbs_verify_blind_commitment_context_set_proof(options: bbs_verify_blind_commitment_context_set_proof_options): int32_t
  bbs_verify_blind_commitment_context_finish(options: bbs_verify_blind_commitment_context_finish_options): int32_t
  bls_secret_key_size(options: bls_secret_key_size_options): int32_t
  bls_public_key_g2_size(options: bls_public_key_g2_size_options): int32_t
  blinding_factor_size(options: blinding_factor_size_options): int32_t
  bls_public_key_g1_size(options: bls_public_key_g1_size_options): int32_t
  bls_generate_g1_key(options: bls_generate_g1_key_options): Required<BlsKeyPair>
  bls_generate_g2_key(options: bls_generate_g2_key_options): Required<BlsKeyPair>
  bls_generate_blinded_g1_key(options: bls_generate_blinded_g1_key_options): Required<BlindedBlsKeyPair>
  bls_generate_blinded_g2_key(options: bls_generate_blinded_g2_key_options): Required<BlindedBlsKeyPair>
  bls_get_public_key(options: bls_get_public_key_options): int32_t
  bls_secret_key_to_bbs_key(options: bls_secret_key_to_bbs_key_options): int32_t
  bls_public_key_to_bbs_key(options: bls_public_key_to_bbs_key_options): Required<BbsKeyPair>
}
