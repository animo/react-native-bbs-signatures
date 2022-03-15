import { bbsNativeBindings } from "./register";
import type { BlsKeyPair, BlindedBlsKeyPair } from "./types";

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
 * Generates a blinded BLS12-381 key pair where the public key is a commitment in G1 to the private key
 * along with a further commitment of a blinding factor to the blinding factor generator point in G1
 * @param seed [Optional] To derive the key pair from
 *
 * @returns A BlindedBlsKeyPair
 */
export const generateBlindedBls12381G1KeyPair = async (
  seed?: Uint8Array
): Promise<Required<BlindedBlsKeyPair>> => {
  const { publicKey, secretKey, blindingFactor } =
    bbsNativeBindings.generateBlindedBls12381G1KeyPair({
      seed: seed?.buffer,
    });
  return {
    secretKey: new Uint8Array(secretKey),
    publicKey: new Uint8Array(publicKey),
    blindingFactor: new Uint8Array(blindingFactor),
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

/**
 * Generates a blinded BLS12-381 key pair where the public key is a commitment in G2 to the private key
 * along with a further commitment of a blinding factor to the blinding factor generator point in G2
 * @param seed [Optional] To derive the key pair from
 *
 * @returns A BlindedBlsKeyPair
 */
export const generateBlindedBls12381G2KeyPair = async (
  seed?: Uint8Array
): Promise<Required<BlindedBlsKeyPair>> => {
  const { publicKey, secretKey, blindingFactor } =
    bbsNativeBindings.generateBlindedBls12381G2KeyPair({
      seed: seed?.buffer,
    });
  return {
    secretKey: new Uint8Array(secretKey),
    publicKey: new Uint8Array(publicKey),
    blindingFactor: new Uint8Array(blindingFactor),
  };
};
