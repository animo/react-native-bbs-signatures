import { bls12381toBbs } from "./bls12381toBbs";
import { bbsNativeBindings } from "./register";
import type {
  BbsBlindSignContext,
  BbsBlindSignContextRequest,
  BbsBlindSignRequest,
  BbsCreateProofRequest,
  BbsSignRequest,
  BbsVerifyBlindSignContextRequest,
  BbsVerifyProofRequest,
  BbsVerifyRequest,
  BbsVerifyResult,
  BlsBbsSignRequest,
  BlsBbsVerifyRequest,
} from "./types";

/**
 * Signs a set of messages with a BBS key pair and produces a BBS signature
 * @param request Request for the sign operation
 *
 * @returns The raw signature value
 */
export const sign = async ({
  messages,
  keyPair,
}: BbsSignRequest): Promise<Uint8Array> => {
  try {
    const messageBuffers = messages.map((m) => m.buffer);
    const { signature } = bbsNativeBindings.sign({
      publicKey: keyPair.publicKey.buffer,
      secretKey: keyPair.secretKey!.buffer,
      messages: messageBuffers,
    });

    return new Uint8Array(signature);
  } catch {
    throw new Error("Failed to sign");
  }
};

/**
 * Signs a set of messages with a BLS 12-381 key pair and produces a BBS signature
 * @param request Request for the sign operation
 *
 * @returns The raw signature value
 */
export const blsSign = async ({
  messages,
  keyPair,
}: BlsBbsSignRequest): Promise<Uint8Array> => {
  const bbsKeyPair = await bls12381toBbs({
    keyPair,
    messageCount: messages.length,
  });
  return sign({ keyPair: bbsKeyPair, messages });
};

/**
 * Verifies a BBS+ signature for a set of messages with a BBS public key
 * @param request Request for the signature verification operation
 *
 * @returns A result indicating if the signature was verified
 */
export const verify = async ({
  publicKey,
  signature,
  messages,
}: BbsVerifyRequest): Promise<BbsVerifyResult> => {
  try {
    const messageBuffers = messages.map((m) => m.buffer);
    const { verified } = bbsNativeBindings.verify({
      publicKey: publicKey.buffer,
      signature: signature.buffer,
      messages: messageBuffers,
    });

    return {
      verified,
    };
  } catch (error) {
    if (typeof error === "string") {
      return { verified: false, error };
    } else {
      return { verified: false };
    }
  }
};

/**
 * Verifies a BBS+ signature for a set of messages with a with a BLS 12-381 public key
 * @param request Request for the signature verification operation
 *
 * @returns A result indicating if the signature was verified
 */
export const blsVerify = async ({
  messages,
  publicKey,
  signature,
}: BlsBbsVerifyRequest): Promise<BbsVerifyResult> => {
  const bbsKeyPair = await bls12381toBbs({
    keyPair: { publicKey },
    messageCount: messages.length,
  });
  return verify({ messages, signature, publicKey: bbsKeyPair.publicKey });
};

/**
 * Creates a BBS+ proof for a set of messages from a BBS public key and a BBS signature
 * @param request Request for the create proof operation
 *
 * @returns The raw proof value
 */
export const createProof = async ({
  publicKey,
  messages,
  signature,
  nonce,
  revealed,
}: BbsCreateProofRequest): Promise<Uint8Array> => {
  try {
    const messageBuffers = messages.map((m) => m.buffer);
    const { proof } = bbsNativeBindings.createProof({
      publicKey: publicKey.buffer,
      messages: messageBuffers,
      signature: signature.buffer,
      nonce: nonce.buffer,
      revealed,
    });

    return new Uint8Array(proof);
  } catch {
    throw new Error("Failed to create proof");
  }
};

/**
 * Creates a BBS+ proof for a set of messages from a BLS12-381 public key and a BBS signature
 * @param request Request for the create proof operation
 *
 * @returns The raw proof value
 */
export const blsCreateProof = async ({
  signature,
  publicKey,
  messages,
  nonce,
  revealed,
}: BbsCreateProofRequest): Promise<Uint8Array> => {
  const bbsKeyPair = await bls12381toBbs({
    keyPair: { publicKey },
    messageCount: messages.length,
  });
  return createProof({
    publicKey: bbsKeyPair.publicKey,
    signature,
    messages,
    nonce,
    revealed,
  });
};

/**
 * Verifies a BBS+ proof with a BBS public key
 * @param request Request for the verify proof operation
 *
 * @returns A result indicating if the proof was verified
 */
export const verifyProof = async ({
  nonce,
  proof,
  messages,
  publicKey,
}: BbsVerifyProofRequest): Promise<BbsVerifyResult> => {
  try {
    const messageBuffers = messages.map((m) => m.buffer);
    const { verified } = bbsNativeBindings.verifyProof({
      publicKey: publicKey.buffer,
      messages: messageBuffers,
      proof: proof.buffer,
      nonce: nonce.buffer,
    });

    return {
      verified,
    };
  } catch (error) {
    if (typeof error === "string") {
      return { verified: false, error };
    } else {
      return { verified: false };
    }
  }
};

/**
 * Verifies a BBS+ proof with a BLS12-381 public key
 * @param request Request for the verify proof operation
 *
 * @returns A result indicating if the proof was verified
 */
export const blsVerifyProof = async ({
  nonce,
  proof,
  messages,
  publicKey,
}: BbsVerifyProofRequest): Promise<BbsVerifyResult> => {
  const bbsKeyPair = await bls12381toBbs({
    keyPair: { publicKey },
    messageCount: messages.length,
  });
  return verifyProof({
    publicKey: bbsKeyPair.publicKey,
    nonce,
    messages,
    proof,
  });
};

export const commitmentForBlindSignRequest =
  async ({}: BbsBlindSignContextRequest): Promise<BbsBlindSignContext> => {
    throw new Error("NOT YET IMPLEMENTED");
  };

export const verifyBlindSignContext =
  async ({}: BbsVerifyBlindSignContextRequest): Promise<boolean> => {
    throw new Error("NOT YET IMPLEMENTED");
  };

export const blindSign =
  async ({}: BbsBlindSignRequest): Promise<Uint8Array> => {
    throw new Error("NOT YET IMPLEMENTED");
  };
