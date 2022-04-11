import type { BlsKeyPair } from "./types";

type SignOptions = {
  publicKey: ArrayBuffer;
  secretKey: ArrayBuffer;
  messages: readonly ArrayBuffer[];
};

type BlsSignOptions = {
  publickey: ArrayBuffer;
  secretkey: ArrayBuffer;
  messages: ArrayBuffer[];
};

type VerifyOptions = {
  publicKey: ArrayBuffer;
  signature: ArrayBuffer;
  messages: ArrayBuffer[];
};

type BlsVerifyOptions = {
  publickey: ArrayBuffer;
  signature: ArrayBuffer;
  messages: ArrayBuffer[];
};

type CreateProofOptions = {
  nonce: ArrayBuffer;
  revealed: readonly number[];
  publicKey: ArrayBuffer;
  signature: ArrayBuffer;
  messages: ArrayBuffer[];
};

type BlsCreateProofOptions = {
  nonce: ArrayBuffer;
  revealed: number[];
  publicKey: ArrayBuffer;
  signature: ArrayBuffer;
  messages: ArrayBuffer[];
};

type VerifyProofOptions = {
  nonce: ArrayBuffer;
  publicKey: ArrayBuffer;
  proof: ArrayBuffer;
  messages: ArrayBuffer[];
};

type BlsVerifyProofOptions = {
  nonce: ArrayBuffer;
  publicKey: ArrayBuffer;
  proof: ArrayBuffer;
  messages: ArrayBuffer[];
};

type GenerateBls12381G1KeyPairOptions = {
  seed?: ArrayBuffer;
};

type GenerateBls12381G2KeyPairOptions = {
  seed?: ArrayBuffer;
};

type Bl12381toBbsOptions = {
  publicKey: ArrayBuffer;
  messageCount: number;
};

export interface Bbs {
  sign(options: SignOptions): { signature: ArrayBuffer };
  blsSign(options: BlsSignOptions): {};
  verify(options: VerifyOptions): { verified: boolean; error?: string };
  blsVerify(options: BlsVerifyOptions): {};
  createProof(options: CreateProofOptions): { proof: ArrayBuffer };
  blsCreateProof(options: BlsCreateProofOptions): {};
  verifyProof(options: VerifyProofOptions): {
    verified: boolean;
    error?: string;
  };
  blsVerifyProof(options: BlsVerifyProofOptions): {};
  generateBls12381G1KeyPair(
    options: GenerateBls12381G1KeyPairOptions
  ): Required<BlsKeyPair>;
  generateBls12381G2KeyPair(options: GenerateBls12381G2KeyPairOptions): {
    publicKey: ArrayBuffer;
    secretKey: ArrayBuffer;
  };
  bls12381toBbs(options: Bl12381toBbsOptions): { publicKey: ArrayBuffer };
}
