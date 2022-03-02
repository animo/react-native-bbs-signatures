import type { BlindedBlsKeyPair, BlsKeyPair } from './types'

type SignOptions = {
  publicKey: ArrayBuffer
  secretKey: ArrayBuffer
  messages: ArrayBuffer[]
}

type BlsSignOptions = {
  publickey: ArrayBuffer
  secretkey: ArrayBuffer
  messages: ArrayBuffer[]
}

type VerifyOptions = {
  publicKey: ArrayBuffer
  signature: ArrayBuffer
  messages: ArrayBuffer[]
}

type BlsVerifyOptions = {
  publickey: ArrayBuffer
  signature: ArrayBuffer
  messages: ArrayBuffer[]
}

type CreateProofOptions = {
  nonce: ArrayBuffer
  revealed: readonly number[]
  publicKey: ArrayBuffer
  signature: ArrayBuffer
  messages: ArrayBuffer[]
}

type BlsCreateProofOptions = {
  nonce: Uint8Array
  revealed: number[]
  publicKey: ArrayBuffer
  signature: ArrayBuffer
  messages: ArrayBuffer[]
}

type VerifyProofOptions = {
  nonce: ArrayBuffer
  publicKey: ArrayBuffer
  proof: ArrayBuffer
  messages: ArrayBuffer[]
}

type BlsVerifyProofOptions = {
  nonce: Uint8Array
  publicKey: ArrayBuffer
  proof: ArrayBuffer
  messages: ArrayBuffer[]
}

type CommitmentForBlindSignRequestOptions = {
  nonce: ArrayBuffer
  publicKey: ArrayBuffer
  messages: ArrayBuffer[]
  hidden: readonly number[]
}

type VerifyBlindSignRequestOptions = {
  nonce: ArrayBuffer
  commitment: ArrayBuffer
  proofOfHiddenMessages: ArrayBuffer
  challengeHash: ArrayBuffer
  publicKey: ArrayBuffer
  blinded: readonly number[]
}

type BlindSignOptions = {
  commitment: ArrayBuffer
  secretKey: ArrayBuffer
  messages: ArrayBuffer[]
}

// ---
type GenerateBls12381G1KeyPairOptions = {
  seed?: Uint8Array
}

type GenerateBlindedBls12381G1KeyPairOptions = {}

type GenerateBls12381G2KeyPairOptions = {
  seed?: Uint8Array
}

type GenerateBlindedBls12381G2KeyPairOptions = {}
// ---
type Bl12381toBbsOptions = {}

export interface Bbs {
  sign(options: SignOptions): { signature: Uint8Array }
  blsSign(options: BlsSignOptions): {}
  verify(options: VerifyOptions): { verified: boolean; error?: string }
  blsVerify(options: BlsVerifyOptions): {}
  createProof(options: CreateProofOptions): { proof: Uint8Array }
  blsCreateProof(options: BlsCreateProofOptions): {}
  verifyProof(options: VerifyProofOptions): { verified: boolean; error?: string }
  blsVerifyProof(options: BlsVerifyProofOptions): {}
  commitmentForBlindSignRequest(options: CommitmentForBlindSignRequestOptions): {}
  verifyBlindSignRequest(options: VerifyBlindSignRequestOptions): {}
  blindSign(options: BlindSignOptions): {}
  // ---
  generateBls12381G1KeyPair(options: GenerateBls12381G1KeyPairOptions): Required<BlsKeyPair>
  generateBlindedBls12381G1KeyPair(options: GenerateBlindedBls12381G1KeyPairOptions): Required<BlindedBlsKeyPair>
  generateBls12381G2KeyPair(options: GenerateBls12381G2KeyPairOptions): Required<BlsKeyPair>
  generateBlindedBls12381G2KeyPair(options: GenerateBlindedBls12381G2KeyPairOptions): Required<BlindedBlsKeyPair>
  // ---
  bls12381toBbs(options: Bl12381toBbsOptions): { publicKey: Uint8Array }
}
