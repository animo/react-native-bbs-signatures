import { bbsNativeBindings } from "./register";
import type { BlsKeyPair } from "./types";

/**
 * Generates a BLS12-381 key pair where the public key is a commitment in G1
 * @param seed [Optional] To derive the key pair from
 *
 * @returns A BlsKeyPair
 */
export const generateBls12381G1KeyPair = async (
  seed?: Uint8Array
): Promise<Required<BlsKeyPair>> => {
  const { publicKey, secretKey } = bbsNativeBindings.generateBls12381G1KeyPair({
    seed: seed?.buffer,
  });
  return {
    secretKey: new Uint8Array(secretKey),
    publicKey: new Uint8Array(publicKey),
  };
};

/**
 * Generates a BLS12-381 key pair where the public key is a commitment in G2
 * @param seed [Optional] To derive the key pair from
 *
 * @returns A BlsKeyPair
 */
export const generateBls12381G2KeyPair = async (
  seed?: Uint8Array
): Promise<Required<BlsKeyPair>> => {
  const { publicKey, secretKey } = bbsNativeBindings.generateBls12381G2KeyPair({
    seed: seed?.buffer,
  });
  return {
    secretKey: new Uint8Array(secretKey),
    publicKey: new Uint8Array(publicKey),
  };
};
